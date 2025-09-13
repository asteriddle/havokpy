//
// Created by exozg on 14/07/2025.
//

#ifndef HKMOPPBVTREESHAPECLASS_H
#define HKMOPPBVTREESHAPECLASS_H

#include "hkShapeClass.h"
#include "hkSphereShapeClass.h"
#include "src/hkArray.h"
#include <variant>

#include "hkSimpleMeshShapeClass.h"

struct hkShapeContainer {
    hkPointer<void> vtable;
};

struct hkSingleShapeContainer: hkShapeContainer {
    hkPointer<hkShape> childShape;
};

struct hkBvTreeShape: hkShape {
    hkSingleShapeContainer child;
};

struct hkMoppCodeCodeInfo {
    hkVector4 offset;
};

struct hkMoppCode: hkReferencedObject {
    hkMoppCodeCodeInfo info;
    hkArray<uint8_t> data;
};

struct hkMoppBvTreeShape: hkBvTreeShape {
    hkPointer<hkMoppCode> code;
};

class hkMoppBvTreeShapeClass final : public hkShapeClass {
    hkMoppBvTreeShape* header = reinterpret_cast<hkMoppBvTreeShape *>(buffer.data() + offset);

public:
    explicit hkMoppBvTreeShapeClass(uintptr_t offset);

    [[nodiscard]] hkClassType getType() const override {
        return hkClassType::hkMoppBvTreeShape;
    };

    hkShapeVariant child;
    std::vector<uint8_t> data;
};

#endif  //HKMOPPBVTREESHAPECLASS_H