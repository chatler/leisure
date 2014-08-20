
cmake_minimum_required(VERSION 2.8)

project(leisure)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

set(BUILD_SHARED_LIBS ON)
set(CMAKE_USE_RELATIVE_PATHS ON)

set(CXX_FLAGS
 -g
# -DVALGRIND
 -DMUDUO_STD_STRING
 -D_FILE_OFFSET_BITS=64
# -DCMAKE_BUILD_BITS=32
 -Wall
# -Wextra
 -Werror
# -Wconversion
 -Wno-unused-parameter
 -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
# -Wshadow
 -Wwrite-strings
 -march=native
 # -MMD
 # -std=c++0x
 -rdynamic
 )
message(STATUS "CXX_FLAGS = " ${CXX_FLAGS})
message(STATUS "CMAKE_BUILD_BITS = " ${CMAKE_BUILD_BITS})
if(CMAKE_BUILD_BITS EQUAL 32)
	list(APPEND CXX_FLAGS "-m32")
else()
	list(APPEND CXX_FLAGS "-m64")
endif()
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

find_package(Boost REQUIRED)
find_package(Protobuf REQUIRED)
find_library(BOOSTTEST_LIBRARY NAMES boost_unit_test_framework)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_BINARY_DIR})

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

#executables
add_subdirectory(sort)

