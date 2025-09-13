//
// Created by exozg on 12/07/2025.
//

#ifndef DATACLASS_H
#define DATACLASS_H
#include <cstdint>
#include <span>

#include "Classes.h"
#include "src/FileContext.h"

class DataClass {
protected:
    std::span<uint8_t> buffer;

    uintptr_t offset;
public:
    virtual ~DataClass() = default;

    explicit DataClass(const uintptr_t offset)
        : buffer(FileContext::get()->buffer), offset(offset) {
    }

    virtual hkClassType getType() const = 0;
};



#endif //DATACLASS_H
