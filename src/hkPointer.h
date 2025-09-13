//
// Created by exozg on 13/07/2025.
//

#ifndef HKPOINTER_H
#define HKPOINTER_H
#include <cstdint>

#include "FileContext.h"
#include "hxkSection.h"

template<typename T>
struct hkPointer {
    uint32_t value;

    // absolute memory address
    [[nodiscard]] uintptr_t absolute_offset() const {
        const uintptr_t value_offset_fs = reinterpret_cast<uintptr_t>(&value) - reinterpret_cast<uintptr_t>(FileContext::get()->buffer.data());
        const uintptr_t value_offset_ds = value_offset_fs - FileContext::get()->section->absoluteDataStart;
        const uintptr_t out_value_fs = FileContext::get()->section->lookupFixup(value_offset_ds);

        return reinterpret_cast<uintptr_t>(FileContext::get()->buffer.data()) + out_value_fs;
    }

    // relative to file start
    [[nodiscard]] uintptr_t fs_offset() const {
        const uintptr_t value_offset_fs = reinterpret_cast<uintptr_t>(&value) - reinterpret_cast<uintptr_t>(FileContext::get()->buffer.data());
        const uintptr_t value_offset_ds = value_offset_fs - FileContext::get()->section->absoluteDataStart;
        return FileContext::get()->section->lookupFixup(value_offset_ds);
    }

    [[nodiscard]] bool is_nullptr() const {
        return fs_offset() == 0;
    }

    [[nodiscard]] hxkClassname* getVirtualClassname() const {
        const uintptr_t value_offset_fs = fs_offset();
        const uintptr_t value_offset_ds = value_offset_fs - FileContext::get()->section->absoluteDataStart;
        return FileContext::get()->section->getVirtualClassname(value_offset_ds);
    }

    T* operator*() {
        return reinterpret_cast<T*>(absolute_offset());
    }

    T* operator->() {
        return reinterpret_cast<T*>(absolute_offset());
    }

    const T* operator->() const {
        return reinterpret_cast<T*>(absolute_offset());
    }

    hkPointer(const hkPointer&) = delete;
    hkPointer& operator=(const hkPointer&) = delete;
};

#endif //HKPOINTER_H
