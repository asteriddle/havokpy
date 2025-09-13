//
// Created by exozg on 12/07/2025.
//

#ifndef HKPHYSICSDATA_H
#define HKPHYSICSDATA_H
#include "DataClass.h"
#include "src/hxk.h"
#include <vector>

#include "hkPhysicsSystemClass.h"

struct hkPhysicsData : hkReferencedObject {
    hkPointer<void> worldCinfo;
    hkArray<hkPointer<hkPhysicsSystem>> systems;
};

class hkPhysicsDataClass final : public DataClass {
    hkPhysicsData* header = reinterpret_cast<hkPhysicsData *>(buffer.data() + offset);

public:
    explicit hkPhysicsDataClass(uintptr_t offset_fs);

    [[nodiscard]] hkClassType getType() const override {
        return hkClassType::hkPhysicsData;
    };

    std::vector<hkPhysicsSystemClass*> systems;
};



#endif //HKPHYSICSDATA_H
