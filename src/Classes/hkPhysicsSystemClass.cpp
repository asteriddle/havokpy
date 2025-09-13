//
// Created by exozg on 12/07/2025.
//

#include "hkPhysicsSystemClass.h"
#include "src/hxkSection.h"
hkPhysicsSystemClass::hkPhysicsSystemClass(const uintptr_t offset)
    : DataClass(offset) {


    for (int i = 0; i < header->rigidBodies.count; i++) {
        rigidBodies.emplace_back(new hkEntityClass(header->rigidBodies[i].fs_offset()));
    }
}