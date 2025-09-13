//
// Created by exozg on 14/07/2025.
//


#include "hkMoppBvTreeShapeClass.h"

#include "src/hkClassFactory.h"

hkMoppBvTreeShapeClass::hkMoppBvTreeShapeClass(const uintptr_t offset): hkShapeClass(offset) {
    child = hkClassFactory::Make(header->child.childShape);
    if (!header->code->data.is_nullptr()) {
        data.assign(header->code->data.begin(), header->code->data.end());
    }
}
