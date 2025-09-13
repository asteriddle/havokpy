//
// Created by exozg on 10/07/2025.
//

#ifndef HAVOKFILE_H
#define HAVOKFILE_H

#include <vector>
#include <span>
#include "hxkFile.h"

struct HavokHeader {
    char magic[4];
    uint32_t version;
};

class HavokFile {
    std::span<uint8_t> buffer;

    HavokHeader* header = reinterpret_cast<HavokHeader *>(buffer.data());

public:
    explicit HavokFile(const std::span<uint8_t> &buffer); // buffer is entire file

    std::vector<hxkFile> entries;
    uint32_t version = header->version;
};

#endif //HAVOKFILE_H
