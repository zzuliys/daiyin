cmake_minimum_required()
project(encryption)

# 设置C++标准为C++ 11
set(CMAKE_CXX_STANDARD 11)

add_executable(encryption encryption.cpp AES256.cpp)
add_executable(decrypt decrypt.cpp AES256.cpp)