// //
// // Created by exozg on 10/07/2025.
// //
//
// #ifndef HXK_H
// #define HXK_H
//
// #include <cstdint>
//
//
// #pragma pack(push, 1)
//
// struct hkBaseObject {
//     hkPointer<void> vtable;
// };
//
// struct hkReferencedObject : hkBaseObject {
//     uint16_t memSizeAndFlags;
//     uint16_t referenceCount;
// };
//
//
//
// // maybe is a 4x4?

//
// struct hkShape: hkReferencedObject {
//     uint32_t userData;
// };
//
// struct hkSphereShape: hkShape {
//     float radius;
// };
//
// struct hkShapeContainer {
//     void* vtable;
// };
//
// struct hkSingleShapeContainer: hkShapeContainer {
//     hkPointer<hkShape> childShape;
// };
//
// struct hkBvTreeShape: hkShape {
//     hkSingleShapeContainer child;
// };
//
// struct hkMoppCodeCodeInfo {
//     hkVector4 offset;
// };
//
// struct hkMoppCode: hkReferencedObject {
//     hkMoppCodeCodeInfo info;
//     hkArray<uint8_t> data;
// };
//
// struct hkMoppBvTreeShape: hkBvTreeShape {
//     hkPointer<hkMoppCode> code;
// };
//
// struct hkCdBody {
//     hkPointer<hkShape> shape;
//     uint32_t shapeKey;
//     hkPointer<void> motion;
//     hkPointer<void> parent;
// };
//
// struct hkBroadPhaseHandle {
//     uint32_t id;
// };
//
// struct hkTypedBroadPhaseHandle: hkBroadPhaseHandle {
//     uint8_t type;
//     uint8_t ownerOffset;
//     uint16_t objectQualityType;
//     uint32_t collisionFilterInfo;
// };
//
// struct hkCollidable: hkCdBody {
//     uint32_t ownerOffset;
//     hkTypedBroadPhaseHandle broadPhaseHandle;
//     float allowedPenetrationDepth;
// };
//
// struct hkLinkedCollidable : hkCollidable {
//     hkArray<uint32_t> collisionEntries;
// };
//
// struct hkMultiThread {
//     uint32_t threadId;
//     uint16_t lockCount;
//     uint16_t lockBitStack;
// };
//
// struct hkProperty {
//     uint32_t key;
//     uint8_t pad[4];
//     uint64_t value;
// };
//
// struct hkWorldObject: hkReferencedObject {
//     hkPointer<void> world;
//     uint32_t userData;
//     hkPointer<char> name;
//     hkMultiThread multithreadLock;
//     hkLinkedCollidable collidable;
//     hkArray<hkProperty> properties;
// };
//
// struct hkMaterial {
//     uint8_t responseType;
//     uint8_t pad[3];
//     float friction;
//     float restitution;
// };
//
// struct hkTransform {
//     hkMatrix3 rotation;
//     hkVector4 translation;
// };
//
// struct hkMotionState {
//     hkTransform transform;
//     uint8_t sweptTransform[80];
//     hkVector4 deltaAngle;
//     float objectRadius;
//     float maxLinearVelocity;
//     float maxAngularVelocity;
//     float linearDamping;
//     float angularDamping;
//     uint16_t deactivationClass;
//     uint16_t deactivationCounter;
//     uint8_t pad[10];
// };
//
// struct hkMotion: hkReferencedObject {
//     uint8_t type;
//     uint8_t pad[7];
//     hkMotionState motionState;
//     hkVector4 inertiaAndMassInv;
//     hkVector4 linearVelocity;
//     hkVector4 angularVelocity;
//     uint8_t pad2[16];
// };
//
// struct hkEntity: hkWorldObject {
//     hkPointer<void> simulationIsland;
//     hkMaterial material;
//     hkPointer<void> deactivator;
//     hkArray<uint32_t> constraintsMaster;
//     hkArray<uint32_t> constraintsSlave;
//     hkArray<uint32_t> constraintRuntime;
//     uint16_t storageIndex;
//     uint16_t processContactCallbackDelay;
//     uint8_t autoRemoveLevel;
//     uint8_t pad[11];
//     hkMotion motion;
//     uint32_t solverData;
//     hkArray<uint32_t> collisionListeners;
//     hkArray<uint32_t> activationListeners;
//     hkArray<uint32_t> entityListeners;
//     hkArray<uint32_t> actions;
//     uint32_t uid;
// };
//
// struct hkPhysicsSystem: hkReferencedObject {
//     hkArray<hkPointer<hkEntity>> rigidBodies;
//     hkArray<uint32_t> constraints;
//     hkArray<uint32_t> actions;
//     hkArray<uint32_t> phantoms;
//     hkPointer<char> name;
//     hkPointer<void> userData;
//     bool active;
//     uint8_t pad[3];
// };
//
// struct hkPhysicsData : hkReferencedObject {
//     hkPointer<void> worldCinfo;
//     hkArray<hkPhysicsSystem*> systems;
// };
//
//
//
//
//
// #pragma pack(pop)
//
// #endif //HXK_H
