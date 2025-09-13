//
// Created by exozg on 14/07/2025.
//

#ifndef HKSIMPLEMESHSHAPECLASS_H
#define HKSIMPLEMESHSHAPECLASS_H
#include "hkShapeClass.h"
#include "src/hkArray.h"

struct hkShapeCollection: hkShape {
    hkPointer<void> vtable;

    bool disableWelding;
    uint8_t pad[3];
};

struct hkSimpleMeshShapeTriangle {
    uint32_t a;
    uint32_t b;
    uint32_t c;
};

struct hkSimpleMeshShape : hkShapeCollection {
    hkArray<hkVector4> vertices;
    hkArray<hkSimpleMeshShapeTriangle> triangles;
    hkArray<uint8_t> materialIndices;
    float radius;
};

class hkSimpleMeshShapeClass final : public hkShapeClass {
    hkSimpleMeshShape* header = reinterpret_cast<hkSimpleMeshShape *>(buffer.data() + offset);

public:
    explicit hkSimpleMeshShapeClass(uintptr_t offset);

    std::vector<hkVector4> vertices;
    std::vector<hkSimpleMeshShapeTriangle> triangles;
    std::vector<uint8_t> materialIndices;
};

#endif //HKSIMPLEMESHSHAPECLASS_H
