# Copyright (c) Facebook, Inc. and its affiliates. All Rights Reserved
cmake_minimum_required(VERSION 3.9.0)

project(Replica)

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/")

# set(THIRD_PARTY "${CMAKE_CURRENT_LIST_DIR}/3rdparty/")

# find_package(Eigen3 NO_MODULE)
# if(NOT ${Eigen3_FOUND})
#     message(STATUS "Using 3rd party Eigen3")
#     set(Eigen_INCLUDE_DIRS "${THIRD_PARTY}/eigen")
# endif()

# # use system Pangolin if available
# find_package(Pangolin)
# if(NOT ${Pangolin_FOUND})
#     message(STATUS "Using 3rd party Pangolin")
#     set(Pangolin_INCLUDE_DIRS "${THIRD_PARTY}/Pangolin/build/src/include")
#     list(APPEND Pangolin_INCLUDE_DIRS "${THIRD_PARTY}/Pangolin/include")
#     set(Pangolin_LIBRARIES "${THIRD_PARTY}/Pangolin/build/src/libpangolin.so")
# endif()

# find_package(dl REQUIRED)

set (CMAKE_CXX_STANDARD 17)
add_definitions(-DEIGEN_NO_DEBUG)

set(CMAKE_DEBUG_POSTFIX "d" CACHE STRING "Set debug library postfix")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")

# include 3rd libraries path
#############################
# DEPENDENCIES DIR
#############################
set(Eigen3_DIR "D:/libraries_windows/eigen/eigen-3.3.9-bin/share/eigen3/cmake")
set(gflags_DIR "D:/libraries_windows/glog/glog_with_gflags-0.4.0-msvc14.0-x64-dll/gflags-2.2.2-bin/lib/cmake/gflags/")
set(glog_DIR "D:/libraries_windows/glog/glog_with_gflags-0.4.0-msvc14.0-x64-dll/glog-0.4.0-bin/lib/cmake/glog/")
set(GLEW_DIR "D:/libraries_windows/glew/glew-2.1.0-bin/lib/cmake/glew")
set(Pangolin_DIR "D:/libraries_windows/Pangolin/Pangolin-bin/lib/cmake/Pangolin")

#############################
# SET RUN-TIME ENV
#############################
unset(RUNTIMT_ENV_PATH_LIST)
unset(RUNTIMT_ENV_PATH_STR)
unset(RUNTIMT_ENV_PATH)
SET(RUNTIMT_ENV_PATH_LIST "PATH=%PATH%")
LIST(APPEND RUNTIMT_ENV_PATH_LIST "D:/libraries_windows/glog/glog_with_gflags-0.4.0-msvc14.0-x64-dll/gflags-2.2.2-bin/bin/")
LIST(APPEND RUNTIMT_ENV_PATH_LIST "D:/libraries_windows/glog/glog_with_gflags-0.4.0-msvc14.0-x64-dll/glog-0.4.0-bin/bin/")
LIST(APPEND RUNTIMT_ENV_PATH_LIST "D:/libraries_windows/glew/glew-2.1.0-bin/bin/")
LIST(APPEND RUNTIMT_ENV_PATH_LIST "D:/libraries_windows/Pangolin/Pangolin-bin/bin")
LIST(APPEND RUNTIMT_ENV_PATH_LIST "D:/workspace_windows/replica/Replica-Dataset_360/3rdparty/linux_sort_dll/")
string(JOIN ";" RUNTIMT_ENV_PATH_STR ${RUNTIMT_ENV_PATH_LIST})
#string(CONCAT ";" RUNTIMT_ENV_PATH_STR ${RUNTIMT_ENV_PATH_LIST})
set(RUNTIMT_ENV_PATH ${RUNTIMT_ENV_PATH_STR} CACHE STRING "vs runtime env" FORCE)
MESSAGE(STATUS "DEBUG: RUNTIMT_ENV_PATH_STR=${RUNTIMT_ENV_PATH}")

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/cmake/")
# set(THIRD_PARTY "${CMAKE_CURRENT_LIST_DIR}/3rdparty/")
# set(Eigen_INCLUDE_DIRS "${THIRD_PARTY}/eigen") 
# set(Pangolin_INCLUDE_DIRS "${THIRD_PARTY}/Pangolin/build/src/include")
# list(APPEND Pangolin_INCLUDE_DIRS "${THIRD_PARTY}/Pangolin/include") 
# set(Pangolin_LIBRARIES "${THIRD_PARTY}/Pangolin/build/src/libpangolin.so") 

# find_package(dl REQUIRED)

find_package(Eigen3 REQUIRED)
find_package(glew REQUIRED)
find_package(Pangolin REQUIRED)
find_package(gflags REQUIRED)
find_package(glog REQUIRED)

# Pangolin's dependencies
set(ZLIB_INCLUDE_DIR "D:/libraries_windows/Pangolin/Pangolin-bin/include")
set(ZLIB_LIBRARY_DEBUG  "D:/libraries_windows/Pangolin/Pangolin-bin/lib/zlibstaticd.lib")
set(ZLIB_LIBRARY_RELEASE   "D:/libraries_windows/Pangolin/Pangolin-bin/lib/zlibstatic.lib")
set(PNG_PNG_INCLUDE_DIR  "D:/libraries_windows/Pangolin/Pangolin-bin/include/libpng16")
set(PNG_LIBRARY_DEBUG  "D:/libraries_windows/Pangolin/Pangolin-bin/lib/libpng16_staticd.lib")
set(PNG_LIBRARY_RELEASE  "D:/libraries_windows/Pangolin/Pangolin-bin/lib/libpng16_static.lib")
set(JPEG_LIBRARY  "D:/libraries_windows/Pangolin/Pangolin-bin/lib/jpeg.lib")

set(Pangolin_INCLUDE_DIRS "D:/libraries_windows/Pangolin/Pangolin-bin/include")
set(Pangolin_LIBRARIES "D:/libraries_windows/Pangolin/Pangolin-bin/lib/pangolin.lib")

set(SortLinux_INCLUDE_DIR "D:/workspace_windows/replica/Replica-Dataset_360/3rdparty/linux_sort_dll/")
set(SortLinux_LIBRARIES "D:/workspace_windows/replica/Replica-Dataset_360/3rdparty/linux_sort_dll/sort_linux.lib")

add_subdirectory("./ReplicaSDK")

