//
// Created by exozg on 11/07/2025.
//

#ifndef HXKFILE_H
#define HXKFILE_H

#include <span>

#include "hxkSection.h"

struct hxkHeaderlayout {
    uint8_t bytesInhkPointer;
    bool littleEndian;
    bool reusePaddingOptimization;
    bool emptyBaseClassOptimization;
};

struct hxkHeader {
    uint32_t magic1;
    uint32_t magic2;
    uint32_t userTag;
    uint32_t version;
    hxkHeaderlayout layout;
    uint32_t numSections;
    uint32_t contentsSectionIndex;
    uint32_t contentsSectionOffset;
    uint32_t contentsClassNameSectionIndex;
    uint32_t contentsClassNameSectionOffset;
    char contentsVersion[15];
    uint8_t pad;
    uint32_t flags;
    uint32_t pad2;
};

class hxkFile {
    std::span<uint8_t> buffer;

    hxkHeader* header = reinterpret_cast<hxkHeader *>(buffer.data());

public:
    explicit hxkFile(std::span<uint8_t> buffer); // buffer is hxkfile

    hxkSectionHeader* sectionHeaders = reinterpret_cast<hxkSectionHeader *>(buffer.data() + sizeof(hxkHeader));
    std::vector<hxkSection> sections;
    uint32_t version = header->version;
    std::string contentsVersion = header->contentsVersion;

    hxkSection* getDataSection();
    hxkSection* getClassnameSection();
    hxkClassname* getClassname(uintptr_t offset);

    uint32_t contentsClassNameSectionOffset = header->contentsClassNameSectionOffset;
    uint32_t contentsSectionOffset = header->contentsSectionOffset;
    uint32_t contentsClassNameSectionIndex = header->contentsClassNameSectionIndex;
    uint32_t contentsSectionIndex = header->contentsSectionIndex;
};



#endif //HXKFILE_H
