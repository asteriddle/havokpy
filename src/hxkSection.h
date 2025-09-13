//
// Created by exozg on 11/07/2025.
//

#ifndef HXKSECTION_H
#define HXKSECTION_H

#include <vector>
#include <span>
#include <string>
#include <variant>

class hkPhysicsDataClass;

struct hxkLocalFixup {
    uint32_t from;
    uint32_t to;
};

struct hxkGlobalFixup {
    uint32_t from;
    uint32_t section;
    uint32_t to;
};

struct hxkVirtualFixup {
    uint32_t from;
    uint32_t section;
    uint32_t classnameOffset;
};

struct hxkClassname {
    uint32_t signature;
    uint8_t nine;
    char name[128];
};

struct hxkSectionHeader {
    char sectionTag[19];
    uint8_t pad1;
    uint32_t absoluteDataStart;
    uint32_t localFixupsOffset;
    uint32_t globalFixupsOffset;
    uint32_t virtualFixupsOffset;
    uint32_t exportsOffset;
    uint32_t importsOffset;
    uint32_t bufferSize;
};

class hxkSection {
    uintptr_t offset;
    uint32_t index;
    std::span<uint8_t> buffer;

    hxkSectionHeader* header = reinterpret_cast<hxkSectionHeader*>(buffer.data() + offset);

public:
    explicit hxkSection(uintptr_t offset, uint32_t index); // buffer is hxkfile

    [[nodiscard]] bool isClassnameSection();
    [[nodiscard]] bool isDataSection();
    [[nodiscard]] hxkClassname* getVirtualClassname(uintptr_t offset_ds) const;
    [[nodiscard]] uintptr_t lookupFixup(uintptr_t offset_ds) const;

    std::variant<hkPhysicsDataClass*> root;
    std::vector<hxkClassname*> classnames;

    uintptr_t numLocalFixups;
    uintptr_t numGlobalFixups;
    uintptr_t numVirtualFixups;
    uintptr_t virtualEOF;

    hxkLocalFixup* localFixups;
    hxkGlobalFixup* globalFixups;
    hxkVirtualFixup* virtualFixups;

    uint32_t absoluteDataStart = header->absoluteDataStart;
};


#endif //HXKSECTION_H
