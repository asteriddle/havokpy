//
// Created by exozg on 12/07/2025.
//

#include "hkEntityClass.h"

#include "src/hkClassFactory.h"

hkEntityClass::hkEntityClass(const uintptr_t offset): DataClass(offset) {
    shape = hkClassFactory::Make(header->collidable.shape);
}
