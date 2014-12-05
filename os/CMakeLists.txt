
compile("*.c")

# The mmap.c file needs itself to be in the build directory :)
file(COPY ${CMAKE_SOURCE_DIR}/os/mmap.c DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

