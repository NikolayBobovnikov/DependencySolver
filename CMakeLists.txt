cmake_minimum_required(VERSION 3.2)
project(TestingAssignment VERSION 0.1.0 LANGUAGES CXX)

# Require C++11 and disable extensions for all targets
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#include(CTest)
#enable_testing()

# create build directory if not exists
#add_custom_target(build-time-make-directory ALL COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_SOURCE_DIR}/build)

#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)


#TODO: replace with explicit listing of source files
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
message(STATUS "Building from the following scr files:\n" ${SRC_FILES})
add_executable(depsolver ${SRC_FILES} "src/builder.cpp" "src/target.cpp" "src/buildgraph.cpp" "include/utility.h" "src/utility.cpp")
#add_executable(depsolver src/main.cpp)

set_target_properties(depsolver PROPERTIES OUTPUT_NAME depsolver)
target_include_directories(depsolver PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(depsolver PRIVATE  cxx_std_20)

