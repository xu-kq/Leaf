cmake_minimum_required (VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (Leaf)

if (PROJECT_BINARY_DIR STREQUAL PROJECT_SOURCE_DIR)
    message(WARNING "The binary directory of CMake cannot be the same as source direcory!")
endif()

if (WIN32)
    add_definitions(-DNOMINMAX -D_USE_MATH_DEFINES)
endif()

if (CMAKE_SIZEOF_VOID_P STREQUAL 8) 
	set(CURRENT_ARCHITECUTURE x64)
else ()
	set(CURRENT_ARCHITECUTURE x86)
endif()

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

add_subdirectory ("Leaf")

add_subdirectory("Sandbox")

add_subdirectory("Leaf/vendor/GLFW")