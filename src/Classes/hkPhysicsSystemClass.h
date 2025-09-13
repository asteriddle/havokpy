//
// Created by exozg on 12/07/2025.
//

#ifndef HKPHYSICSSYSTEMCLASS_H
#define HKPHYSICSSYSTEMCLASS_H
#include "DataClass.h"
#include <vector>

#include "hkEntityClass.h"
#include "src/hkCommon.h"

struct hkPhysicsSystem: hkReferencedObject {
    hkArray<hkPointer<hkEntity>> rigidBodies;
    hkArray<uint32_t> constraints;
    hkArray<uint32_t> actions;
    hkArray<uint32_t> phantoms;
    hkPointer<char> name;
    hkPointer<void> userData;
    bool active;
    uint8_t pad[3];
};

class hkPhysicsSystemClass final: public DataClass {
    hkPhysicsSystem* header = reinterpret_cast<hkPhysicsSystem *>(buffer.data() + offset);

public:
    explicit hkPhysicsSystemClass(uintptr_t offset);

    [[nodiscard]] hkClassType getType() const override {
        return hkClassType::hkPhysicsSystem;
    };

    std::vector<hkEntityClass*> rigidBodies;
};



#endif //HKPHYSICSSYSTEMCLASS_H
