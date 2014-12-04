project(cpp)

cmake_minimum_required(VERSION 2.8.0)

# Check the compiler.
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  # Require at least GCC 4.9
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
    message(FATAL_ERROR "GCC version must be at least 4.9!")
  endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  # Require at least Clang 3.5
  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.5)
    message(FATAL_ERROR "Clang version must be at least 3.5!")
  endif()
else()
  message(WARNING "Compilation has only been tested with Clang and GCC.")
endif()

# Compiler flags.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Werror")

# And compile all the *.cpp files.
file(GLOB files "*.cpp")
foreach(file ${files})
  get_filename_component(name ${file} NAME_WE)
  add_executable(${name} ${name}.cpp)
endforeach()

