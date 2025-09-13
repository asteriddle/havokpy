//
// Created by exozg on 14/07/2025.
//

#ifndef HKCLASSFACTORY_H
#define HKCLASSFACTORY_H

#include "hkPointer.h"
#include "Classes/Classes.h"
#include "Classes/Shapes/hkMoppBvTreeShapeClass.h"
#include "Classes/Shapes/hkSimpleMeshShapeClass.h"

namespace hkClassFactory {
    template <typename K>
    hkShapeVariant Make(const hkPointer<K>& ptr) {
        if (const auto classname = ptr.getVirtualClassname(); classname != nullptr) {
            switch (static_cast<hkClassType>(classname->signature)) {
                case hkClassType::hkClass:
                case hkClassType::hkClassMember:
                case hkClassType::hkClassEnum:
                case hkClassType::hkClassEnumItem:
                case hkClassType::hkWorldCinfo:
                case hkClassType::hkAabb:
                case hkClassType::hkCdBody:
                case hkClassType::hkSweptTransform:
                case hkClassType::hkConstraintData:
                case hkClassType::hkPhantom:
                case hkClassType::hkEntityDeactivator:
                case hkClassType::hkPhysicsData:
                case hkClassType::hkPhysicsSystem:
                case hkClassType::hkMotion:
                case hkClassType::hkAction:
                case hkClassType::hkShapeCollection:
                case hkClassType::hkRigidBody:
                case hkClassType::hkBvTreeShape:
                case hkClassType::hkMoppCodeCodeInfo:
                case hkClassType::hkConstraintAtom:
                case hkClassType::hkReferencedObject:
                case hkClassType::hkWorldMemoryWatchDog:
                case hkClassType::hkCollidable:
                case hkClassType::hkBroadPhaseHandle:
                case hkClassType::hkEntity:
                case hkClassType::hkSimpleMeshShapeTriangle:
                case hkClassType::hkCollisionFilter:
                case hkClassType::hkMaterial:
                case hkClassType::hkKeyframedRigidMotion:
                case hkClassType::hkMoppCode:
                case hkClassType::hkBaseObject:
                case hkClassType::hkMaxSizeMotion:
                case hkClassType::hkPropertyValue:
                case hkClassType::hkShape:
                case hkClassType::hkTypedBroadPhaseHandle:
                case hkClassType::hkModifierConstraintAtom:
                case hkClassType::hkSingleShapeContainer:
                case hkClassType::hkMultiThreadLock:
                case hkClassType::hkWorldObject:
                case hkClassType::hkConstraintInstance:
                case hkClassType::hkProperty:
                case hkClassType::hkMotionState:
                case hkClassType::hkLinkedCollidable: {
                    break;
                }
                case hkClassType::hkSimpleMeshShape:
                    return new hkSimpleMeshShapeClass(ptr.fs_offset());
                case hkClassType::hkMoppBvTreeShape:
                    return new hkMoppBvTreeShapeClass(ptr.fs_offset());
                case hkClassType::hkSphereShape:
                    return new hkSphereShapeClass(ptr.fs_offset());
            }
        }

        return std::monostate{};
    }
}

#endif //HKCLASSFACTORY_H
