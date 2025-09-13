//
// Created by exozg on 10/07/2025.
//

#include "HavokFile.h"

HavokFile::HavokFile(const std::span<uint8_t> &buffer)
    : buffer(buffer) {
    uintptr_t offset = 12;
    while (offset < buffer.size()) {
        const uint32_t size = *reinterpret_cast<uint32_t *>(buffer.data() + offset);
        std::span<uint8_t> entry = buffer.subspan(offset + 4, size);
        entries.emplace_back(entry);
        offset += size + 8;
    }
}
