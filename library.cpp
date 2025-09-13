#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "src/HavokFile.h"
#include "src/Classes/hkPhysicsDataClass.h"
#include "src/hxkFile.h"
#include "src/hxkSection.h"

namespace py = pybind11;

PYBIND11_MODULE(havokpy, m) {
    py::class_<HavokFile>(m, "HavokFile")
            .def_readonly("version", &HavokFile::version)
            .def_readonly("entries", &HavokFile::entries);

    py::class_<hxkFile>(m, "hxkFile")
            .def_readonly("version", &hxkFile::version)
            .def_readonly("contents_version", &hxkFile::contentsVersion)
            .def_readonly("sections", &hxkFile::sections);

    py::class_<hxkClassname>(m, "hxkClassname")
            .def_readonly("name", &hxkClassname::name)
            .def_readonly("signature", &hxkClassname::signature);

    py::class_<hkPhysicsDataClass>(m, "hkPhysicsDataClass")
            .def_readonly("systems", &hkPhysicsDataClass::systems);

    py::class_<hkPhysicsSystemClass>(m, "hkPhysicsSystemClass")
            .def_readonly("rigid_bodies", &hkPhysicsSystemClass::rigidBodies);

    py::class_<hkMaterial>(m, "hkMaterial")
            .def_readonly("response_type", &hkMaterial::responseType)
            .def_readonly("friction", &hkMaterial::friction)
            .def_readonly("restitution", &hkMaterial::restitution);

    py::class_<hkSphereShapeClass>(m, "hkSphereShapeClass")
            .def_readonly("radius", &hkSphereShapeClass::radius);

    py::class_<hkMoppBvTreeShapeClass>(m, "hkMoppBvTreeShapeClass")
            .def_readonly("child", &hkMoppBvTreeShapeClass::child);

    py::class_<hkVector4>(m, "hkVector4")
            .def_readwrite("x", &hkVector4::x)
            .def_readwrite("y", &hkVector4::y)
            .def_readwrite("z", &hkVector4::z)
            .def_readwrite("w", &hkVector4::w);

    py::class_<hkSimpleMeshShapeTriangle>(m, "hkSimpleMeshShapeTriangle")
            .def_readwrite("a", &hkSimpleMeshShapeTriangle::a)
            .def_readwrite("b", &hkSimpleMeshShapeTriangle::b)
            .def_readwrite("c", &hkSimpleMeshShapeTriangle::c);

    py::class_<hkSimpleMeshShapeClass>(m, "hkSimpleMeshShapeClass")
            .def_readonly("vertices", &hkSimpleMeshShapeClass::vertices)
            .def_readonly("triangles", &hkSimpleMeshShapeClass::triangles)
            .def_readonly("material_indices", &hkSimpleMeshShapeClass::materialIndices);

    py::class_<hkMatrix3>(m, "hkMatrix3")
            .def_property("m",
                          [](hkMatrix3 &self) {
                              return py::list(py::make_iterator(self.m, self.m + 12));
                          },
                          [](hkMatrix3 &self, const py::iterable &values) {
                              size_t i = 0;
                              for (auto item: values) {
                                  if (i >= 12)
                                      throw std::runtime_error("Too many elements for hkMatrix3");
                                  self.m[i++] = py::cast<float>(item);
                              }
                              if (i != 12)
                                  throw std::runtime_error("Expected exactly 12 elements for hkMatrix3");
                          }
            );

    py::class_<hkTransform>(m, "hkTransform")
            .def_readwrite("rotation", &hkTransform::rotation)
            .def_readwrite("translation", &hkTransform::translation);

    py::class_<hkEntityClass>(m, "hkEntityClass")
            .def_readonly("material", &hkEntityClass::material)
            .def_readonly("shape", &hkEntityClass::shape)
            .def_readonly("transform", &hkEntityClass::transform);

    py::class_<hxkSection>(m, "hxkSection")
            // .def_readonly("is_classname_section", &hxkSection::isClassnameSection)
            // .def_readonly("is_data_section", &hxkSection::isDataSection)
            .def_readonly("classnames", &hxkSection::classnames)
            .def_readonly("root", &hxkSection::root);

    m.def("read_file", [](const py::buffer &b) {
        const py::buffer_info info = b.request();
        const std::span view(static_cast<uint8_t *>(info.ptr), info.size);
        HavokFile file(view);
        return file;
    });
}
