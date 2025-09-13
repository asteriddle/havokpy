//
// Created by exozg on 11/07/2025.
//

#include "hxkSection.h"

#include "hxkFile.h"
#include "Classes/hkPhysicsDataClass.h"

// void hxkSection::ApplyFixups() {
//     for (int i = 0; i < numGlobalFixups; i++) {
//         auto [from, section, to] = globalFixups[i];
//         const auto& sectionHeader = dynamic_cast<hxkFile *>(parent)->sectionHeaders[section];
//
//         auto absoluteOffset = reinterpret_cast<uintptr_t>(buffer.data() + sectionHeader.absoluteDataStart + to);
//         if (to == -1U || from == -1U) {continue;}
//
//         std::memcpy(&buffer[from + header->absoluteDataStart], &absoluteOffset, sizeof(absoluteOffset));
//     }
//
//     for (int i = 0; i < numLocalFixups; i++) {
//         auto [from, to] = localFixups[i];
//         auto absoluteOffset = reinterpret_cast<uintptr_t>(buffer.data() + header->absoluteDataStart + to);
//
//         if (to == -1U || from == -1U) {continue;}
//
//         std::memcpy(&buffer[from + header->absoluteDataStart], &absoluteOffset, sizeof(absoluteOffset));
//     }
// }

hxkSection::hxkSection(const uintptr_t offset, const uint32_t index)
    : offset(offset), index(index), buffer(FileContext::get()->buffer) {
    FileContext::get()->section = this;

    virtualEOF = header->exportsOffset == -1U ? header->importsOffset : header->exportsOffset;
    numLocalFixups = (header->globalFixupsOffset - header->localFixupsOffset) / sizeof(hxkLocalFixup);
    numGlobalFixups = (header->virtualFixupsOffset - header->globalFixupsOffset) / sizeof(hxkGlobalFixup);
    numVirtualFixups = (virtualEOF - header->virtualFixupsOffset) / sizeof(hxkVirtualFixup);

    localFixups = reinterpret_cast<hxkLocalFixup *>(
        buffer.data() + header->absoluteDataStart + header->localFixupsOffset);
    globalFixups = reinterpret_cast<hxkGlobalFixup *>(
        buffer.data() + header->absoluteDataStart + header->globalFixupsOffset);
    virtualFixups = reinterpret_cast<hxkVirtualFixup *>(
        buffer.data() + header->absoluteDataStart + header->virtualFixupsOffset);

    if (isDataSection()) {
        if (static_cast<hkClassType>(FileContext::get()->file->getClassname(
                FileContext::get()->file->contentsClassNameSectionOffset)->signature) ==
            hkClassType::hkPhysicsData) {
            root = new hkPhysicsDataClass(
                header->absoluteDataStart + FileContext::get()->file->contentsSectionOffset);
        }
    }

    if (isClassnameSection()) {
        uintptr_t local_offset = header->absoluteDataStart;
        while (local_offset < header->absoluteDataStart + virtualEOF) {
            auto *classname = reinterpret_cast<hxkClassname *>(buffer.data() + local_offset);
            local_offset += 5 + strlen(classname->name) + 1;

            if (classname->signature != 0xFFFF) {
                classnames.emplace_back(classname);
            }
        }
    }
}

bool hxkSection::isClassnameSection() {
    return index == FileContext::get()->file->contentsClassNameSectionIndex;
}

bool hxkSection::isDataSection() {
    return index == FileContext::get()->file->contentsSectionIndex;
}

hxkClassname *hxkSection::getVirtualClassname(const uintptr_t offset_ds) const {
    for (int i = 0; i < numVirtualFixups; i++) {
        if (const auto fixup = virtualFixups[i]; fixup.from == offset_ds) {
            return FileContext::get()->file->getClassname(fixup.classnameOffset);
        }
    }

    return nullptr;
}

uintptr_t hxkSection::lookupFixup(const uintptr_t offset_ds) const {
    for (int i = 0; i < numGlobalFixups; i++) {
        if (const auto [from, section, to] = globalFixups[i]; from == offset_ds) {
            const auto out_offset_fs = FileContext::get()->file->sectionHeaders[section].absoluteDataStart + to;
            const auto out_offset_ds = to;
            for (int j = 0; j < numLocalFixups; j++) {
                if (const auto [from, to] = localFixups[j]; from == out_offset_ds) {
                    return header->absoluteDataStart + to;
                }
            }
            return out_offset_fs;
        }
    }

    for (int i = 0; i < numLocalFixups; i++) {
        if (const auto [from, to] = localFixups[i]; from == offset_ds) {
            return header->absoluteDataStart + to;
        }
    }

    return 0;
}
