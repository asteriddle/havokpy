//
// Created by exozg on 14/07/2025.
//

#ifndef HKSPHERESHAPECLASS_H
#define HKSPHERESHAPECLASS_H
#include "hkShapeClass.h"

struct hkSphereShape: hkShape {
    float radius;
};

class hkSphereShapeClass final : hkShapeClass {
    hkSphereShape* header = reinterpret_cast<hkSphereShape *>(buffer.data() + offset);

public:
    explicit hkSphereShapeClass(const uintptr_t offset)
        : hkShapeClass(offset) {
    }

    [[nodiscard]] hkClassType getType() const override {
        return hkClassType::hkSphereShape;
    };

    float radius = header->radius;
};



#endif //HKSPHERESHAPECLASS_H
