# Copyright (c) Facebook, Inc. and its affiliates. All Rights Reserved
cmake_minimum_required(VERSION 3.9.0)

project(ReplicaSDK)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/../cmake")

set(PTEX_SHADER_DIR "${CMAKE_CURRENT_LIST_DIR}/shaders" CACHE PATH "Where the shaders live")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -msse2 -msse3 -Wall -std=c++11 -fopenmp -DSHADER_DIR=${PTEX_SHADER_DIR}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DSHADER_DIR=${PTEX_SHADER_DIR}")

#include_directories(${Pangolin_INCLUDE_DIRS})
#include_directories(${EIGEN3_INCLUDE_DIR})
include_directories("./include")

#######   ReplicaRenderer   #######
file(GLOB srcs_ptex ptex/*.cpp)
file(GLOB hdrs include/*.h)

add_library(ptex STATIC 
            ${srcs_ptex}
            ${hdrs}
)

target_link_libraries(ptex PUBLIC
                      ${GLEW_LIBRARIES}              
                      ${Pangolin_LIBRARIES}
                      ${SortLinux_LIBRARIES}
                      GLEW::glew
)

target_include_directories(ptex PUBLIC
            ${GLEW_INCLUDE_DIRS}
            ${EIGEN3_INCLUDE_DIR}
            ${PNG_PNG_INCLUDE_DIR}
            ${ZLIB_INCLUDE_DIR}
            ${Pangolin_INCLUDE_DIRS}
            ${SortLinux_INCLUDE_DIR}
            ${CMAKE_CURRENT_LIST_DIR}
            GL
)

#######   ReplicaRenderer   #######
add_executable(ReplicaViewer src/viewer.cpp src/MirrorSurface.cpp)

target_link_libraries(ReplicaViewer PUBLIC
                      ${Pangolin_LIBRARIES}
                      ptex
)

#######   ReplicaRenderer   #######
add_executable(ReplicaRenderer src/render.cpp src/MirrorSurface.cpp)

target_link_libraries(ReplicaRenderer PUBLIC
                      ${Pangolin_LIBRARIES}
                      ptex
)

