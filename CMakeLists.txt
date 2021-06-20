cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project (optimizer_nl)

# Find Dependencies
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# Directories
set (INC_DIR optimizer)
include_directories("${INC_DIR}")
#FILE (GLOB INC_FILES "optimizer/*.h" "optimizer/*.hpp")

# Examples
FILE (GLOB EG_FILES "examples/*.cpp")
foreach(file ${EG_FILES})
    get_filename_component(name ${file} NAME_WLE)
    message(${name})
    add_executable(${name} ${INC_FILES} examples/${name}.cpp)
    target_include_directories (${name} PRIVATE)
    target_link_libraries (${name} stdc++fs Eigen3::Eigen)
endforeach()
