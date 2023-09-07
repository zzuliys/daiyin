# 设置cmake项目
cmake_minimum_required(VERSION 3.12)
project(myproject)

# 设置C++标准为C++11
set(CMAKE_CXX_STANDARD 11)

# 添加子项目
add_subdirectory(t1) 
add_subdirectory(t2) 
add_subdirectory(t3)

# 设置依赖
add_dependencies(t1 t2)
add_dependencies(t1 t3)