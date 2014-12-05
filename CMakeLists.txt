project(programs)

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
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -std=c11 -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Werror")


# This macro will add an executable for each match of the given wildcard.
function(compile wildcard)
  file(GLOB_RECURSE files ${wildcard})
  foreach(file ${files})
    get_filename_component(name ${file} NAME_WE)
    add_executable(${name} ${file})
  endforeach()
endfunction(compile)

# And finally let's list the directories to compile.
add_subdirectory(algorithms)
add_subdirectory(lang)
add_subdirectory(net)
add_subdirectory(os)

