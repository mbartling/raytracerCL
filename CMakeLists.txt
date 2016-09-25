cmake_minimum_required(VERSION 3.1.3)

project(raytraceCL)

set(CMAKE_CXX_FLAGS "--std=c++11")
#set(CMAKE_BUILD_TYPE Release)

find_package(PNG REQUIRED)
find_package(ZLIB REQUIRED)
include_directories(${PNG_INCLUDE_DIR})
include_directories(${ZLIB_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/fileio)
include_directories(${PROJECT_SOURCE_DIR}/src/imageProcessing)
include_directories(${PROJECT_SOURCE_DIR}/src/parser)
include_directories(${PROJECT_SOURCE_DIR}/src/scene)
include_directories(${PROJECT_SOURCE_DIR}/src/SceneObjects)
include_directories(${PROJECT_SOURCE_DIR}/src/ui)
include_directories(${PROJECT_SOURCE_DIR}/src/vecmath)

set(SOURCES 
    ${PROJECT_SOURCE_DIR}/src/fileio/bitmap.cpp
    ${PROJECT_SOURCE_DIR}/src/fileio/buffer.cpp
    ${PROJECT_SOURCE_DIR}/src/fileio/pngimage.cpp
    ${PROJECT_SOURCE_DIR}/src/getopt.cpp
    ${PROJECT_SOURCE_DIR}/src/imageProcessing/filters.cpp
    ${PROJECT_SOURCE_DIR}/src/imageProcessing/kernels.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/parser/Parser.cpp
    ${PROJECT_SOURCE_DIR}/src/parser/ParserException.cpp
    ${PROJECT_SOURCE_DIR}/src/parser/Token.cpp
    ${PROJECT_SOURCE_DIR}/src/parser/Tokenizer.cpp
    ${PROJECT_SOURCE_DIR}/src/RayTracer.cpp
    ${PROJECT_SOURCE_DIR}/src/scene/camera.cpp
    #    ${PROJECT_SOURCE_DIR}/src/scene/kdtree.cpp
    ${PROJECT_SOURCE_DIR}/src/scene/light.cpp
    ${PROJECT_SOURCE_DIR}/src/scene/material.cpp
    ${PROJECT_SOURCE_DIR}/src/scene/ray.cpp
    ${PROJECT_SOURCE_DIR}/src/scene/scene.cpp
    ${PROJECT_SOURCE_DIR}/src/SceneObjects/Box.cpp
    ${PROJECT_SOURCE_DIR}/src/SceneObjects/Cone.cpp
    ${PROJECT_SOURCE_DIR}/src/SceneObjects/Cylinder.cpp
    ${PROJECT_SOURCE_DIR}/src/SceneObjects/Sphere.cpp
    ${PROJECT_SOURCE_DIR}/src/SceneObjects/Square.cpp
    ${PROJECT_SOURCE_DIR}/src/SceneObjects/trimesh.cpp
    ${PROJECT_SOURCE_DIR}/src/ui/CommandLineUI.cpp
#    ${PROJECT_SOURCE_DIR}/src/ui/debuggingView.cpp
#    ${PROJECT_SOURCE_DIR}/src/ui/glObjects.cpp
#    ${PROJECT_SOURCE_DIR}/src/ui/GraphicalUI.cpp
#    ${PROJECT_SOURCE_DIR}/src/ui/ModelerCamera.cpp
    ${PROJECT_SOURCE_DIR}/src/ui/pixelblock.cpp
#    ${PROJECT_SOURCE_DIR}/src/ui/TraceGLWindow.cpp
    )

#find_package(FLTK REQUIRED)
#find_package(OpenGL REQUIRED)

add_executable(ray ${SOURCES})
target_link_libraries(ray ${PNG_LIBRARY})
target_link_libraries(ray ${ZLIB_LIBRARIES})
