cmake_minimum_required()
project(AES256)

# 设置C++标准为C++ 11
set(CMAKE_CXX_STANDARD 11)

# add_executable(encryption encryption.cpp AES256.cpp)
# add_executable(decryption decryption.cpp AES256.cpp)
add_executable(AES256_tool AES256_tool.cpp AES256.cpp)