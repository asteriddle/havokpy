//
// Created by exozg on 14/07/2025.
//

#include "hkSimpleMeshShapeClass.h"

hkSimpleMeshShapeClass::hkSimpleMeshShapeClass(const uintptr_t offset): hkShapeClass(offset) {
    vertices.assign(header->vertices.begin(), header->vertices.end());
    triangles.assign(header->triangles.begin(), header->triangles.end());
    materialIndices.assign(header->materialIndices.begin(), header->materialIndices.end());
}
