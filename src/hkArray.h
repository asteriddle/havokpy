//
// Created by exozg on 13/07/2025.
//

#ifndef HKARRAY_H
#define HKARRAY_H
#include "hkPointer.h"

template<typename T>
struct hkArray {
    hkPointer<T> first;
    uint32_t count;
    uint16_t capacity;
    uint16_t flags;

    T& operator[](const size_t i) {
        return *reinterpret_cast<T*>(first.absolute_offset() + i * sizeof(T));
    }

    T& operator[](const size_t i) const {
        return *reinterpret_cast<T*>(first.absolute_offset() + i * sizeof(T));
    }

    [[nodiscard]] bool is_nullptr() const {
        return first.is_nullptr();
    }

    T* begin() {
        return reinterpret_cast<T*>(first.absolute_offset());
    }

    T* end() {
        return begin() + count;
    }

    const T* begin() const {
        return reinterpret_cast<T*>(first.absolute_offset());
    }

    const T* end() const {
        return begin() + count;
    }
};

#endif //HKARRAY_H
