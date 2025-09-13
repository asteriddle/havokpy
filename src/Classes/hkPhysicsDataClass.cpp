//
// Created by exozg on 12/07/2025.
//

#include "hkPhysicsDataClass.h"
#include "hkPhysicsSystemClass.h"

hkPhysicsDataClass::hkPhysicsDataClass(const uintptr_t offset_fs)
    : DataClass(offset_fs) {

    for (int i = 0; i < header->systems.count; i++) {
        systems.emplace_back(new hkPhysicsSystemClass(header->systems[i].fs_offset()));
    }
}
