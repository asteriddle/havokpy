//
// Created by exozg on 13/07/2025.
//

#ifndef CLASSES_H
#define CLASSES_H

#define hkShapeVariant std::variant<std::monostate, hkSphereShapeClass*, hkMoppBvTreeShapeClass *, hkSimpleMeshShapeClass*>

enum class hkClassType: uint32_t {
    hkClass = 0xa52796eb,
    hkClassMember = 0x2e50284b,
    hkClassEnum = 0x9617a10c,
    hkClassEnumItem = 0xce6f8a6c,
    hkWorldCinfo = 0x804c9b06,
    hkAabb = 0x4a948b16,
    hkCdBody = 0xe94d2688,
    hkSweptTransform = 0x0b4e5770,
    hkConstraintData = 0xf28ab3b7,
    hkPhantom = 0x9d6e0200,
    hkEntityDeactivator = 0xda8c7d7d,
    hkPhysicsData = 0xc2a461e4,
    hkPhysicsSystem = 0x3ace2c22,
    hkMotion = 0x179f1a0b,
    hkAction = 0x95f58619,
    hkShapeCollection = 0xd5f6b4ef,
    hkSimpleMeshShape = 0x33711d3b,
    hkMoppBvTreeShape = 0x83eb786f,
    hkRigidBody = 0xea24a665,
    hkBvTreeShape = 0xe7260682,
    hkMoppCodeCodeInfo = 0xd8fdbb08,
    hkConstraintAtom = 0x6dac429e,
    hkReferencedObject = 0x3b1c1113,
    hkWorldMemoryWatchDog = 0x3456cb8a,
    // hkShapeContainer = 0xe0708a00,
    hkCollidable = 0x3606426d,
    hkBroadPhaseHandle = 0xfa5860da,
    hkEntity = 0x32c2e1ad,
    hkSimpleMeshShapeTriangle = 0xe3d19f47,
    hkCollisionFilter = 0xb6fa76f0,
    hkMaterial = 0x0485a264,
    hkKeyframedRigidMotion = 0x27f50bfa,
    hkMoppCode = 0xbd097996,
    hkBaseObject = 0xe0708a00,
    hkMaxSizeMotion = 0xd9314173,
    hkPropertyValue = 0xc75925aa,
    hkShape = 0x9ab27645,
    hkTypedBroadPhaseHandle = 0x386f6de0,
    hkModifierConstraintAtom = 0xc85d520f,
    hkSingleShapeContainer = 0x73aa1d38,
    hkMultiThreadLock = 0x7497262b,
    hkWorldObject = 0x7107de4e,
    hkConstraintInstance = 0x2d0d9c11,
    hkProperty = 0x9ce308e9,
    hkMotionState = 0x332f16fa,
    hkLinkedCollidable = 0x3e51c7fc,
    hkSphereShape = 0xab396039
};

#endif //CLASSES_H
