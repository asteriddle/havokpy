//
// Created by exozg on 14/07/2025.
//

#ifndef HKSHAPECLASS_H
#define HKSHAPECLASS_H
#include "src/hkCommon.h"
#include "src/Classes/DataClass.h"

struct hkShape: hkReferencedObject {
    uint32_t userData;
};

class hkShapeClass: public DataClass {
    hkShape* header = reinterpret_cast<hkShape *>(buffer.data() + offset);

public:
    explicit hkShapeClass(const uintptr_t offset)
        : DataClass(offset) {
    }

    [[nodiscard]] hkClassType getType() const override {
        return hkClassType::hkShape;
    };
};



#endif //HKSHAPECLASS_H
