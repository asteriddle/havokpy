//
// Created by exozg on 13/07/2025.
//

#ifndef HKCOMMON_H
#define HKCOMMON_H
#include <cstdint>

#include "hkPointer.h"

struct hkBaseObject {
    hkPointer<void> vtable;
};

struct hkReferencedObject : hkBaseObject {
    uint16_t memSizeAndFlags;
    uint16_t referenceCount;
};

struct hkMatrix3 {
    float m[12];
};

struct hkVector4 {
    float x;
    float y;
    float z;
    float w;
};

#endif //HKCOMMON_H
