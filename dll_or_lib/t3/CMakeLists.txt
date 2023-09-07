set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_library(t3 STATIC test3.cpp )
target_include_directories(t3 PRIVATE ${CMAKE_SOURCE_DIR}/include)