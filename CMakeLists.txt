cmake_minimum_required(VERSION 3.31)
project(havokpy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(HAVOK_SOURCES
        src/hxk.h
        src/HavokFile.cpp
        src/HavokFile.h
        src/hxkFile.cpp
        src/hxkFile.h
        src/hxkSection.cpp
        src/hxkSection.h
        src/Classes/hkPhysicsDataClass.cpp
        src/Classes/hkPhysicsDataClass.h
        src/Classes/DataClass.h
        src/Classes/hkPhysicsSystemClass.cpp
        src/Classes/hkPhysicsSystemClass.h
        src/Classes/hkEntityClass.cpp
        src/Classes/hkEntityClass.h
        src/FileContext.h
        src/ScopedFileContext.h
        src/Classes/Classes.h
        src/hkPointer.h
        src/hkCommon.h
        src/hkArray.h
        src/Classes/Shapes/hkShapeClass.h
        src/Classes/Shapes/hkSphereShapeClass.h
        src/Classes/Shapes/hkMoppBvTreeShapeClass.h
        src/hkClassFactory.h
        src/Classes/Shapes/hkMoppBvTreeShapeClass.cpp
        src/Classes/Shapes/hkSimpleMeshShapeClass.h
        src/Classes/Shapes/hkSimpleMeshShapeClass.cpp
)

set(Python_EXECUTABLE "C:/Users/exozg/.pyenv/pyenv-win/versions/3.11.9/python.exe")

find_package(Python REQUIRED COMPONENTS Interpreter Development)

add_library(havok_core STATIC ${HAVOK_SOURCES})
target_include_directories(havok_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(libs/pybind11)

pybind11_add_module(havokpy MODULE library.cpp)
target_link_libraries(havokpy PRIVATE havok_core)
target_compile_definitions(havokpy PRIVATE PYBIND11_DETAILED_ERROR_MESSAGES)

add_executable(havok_test test.cpp)
target_link_libraries(havok_test PRIVATE havok_core)
