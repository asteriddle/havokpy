//
// Created by exozg on 11/07/2025.
//

#include "hxkFile.h"

#include "ScopedFileContext.h"

hxkFile::hxkFile(const std::span<uint8_t> buffer): buffer(buffer) {
    const auto context = std::make_shared<FileContext>(this, buffer);
    ScopedFileContext ctx(context);

    uintptr_t offset = sizeof(hxkHeader);
    for (int i =0; i < header->numSections; i++) {
        hxkSection section(offset, i);
        sections.push_back(section);

        offset += sizeof(hxkSectionHeader);
    }
}

hxkSection * hxkFile::getDataSection() {
    return &sections[header->contentsSectionIndex];
}

hxkSection * hxkFile::getClassnameSection() {
    return &sections[header->contentsClassNameSectionIndex];
}

hxkClassname* hxkFile::getClassname(const uintptr_t offset) {
    const auto classname_section = sectionHeaders[header->contentsClassNameSectionIndex];
    return reinterpret_cast<hxkClassname*>(buffer.data() + classname_section.absoluteDataStart + offset - 5);
}
