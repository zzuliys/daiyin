set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(t1 test1.cpp)

# 引用头文件目录
target_include_directories(t1 PRIVATE ${CMAKE_SOURCE_DIR}/include)
# 添加链接静态库的路径
target_link_libraries(t1 PRIVATE ${CMAKE_SOURCE_DIR}/lib/Debug/t3.lib)

target_link_libraries(t1 PRIVATE ${CMAKE_BINARY_DIR}/bin/Debug/t2.lib)
