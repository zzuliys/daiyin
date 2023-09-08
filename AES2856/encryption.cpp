#include <iostream>
#include <fstream>
#include <string>
#include "AES256.h"
int main()
{
    // 定义密钥
    ByteArray key = {'o', 'r', 'b', 'b', 'e', 'c', '_', 's', 'd', 'k', '_', '2', '8', '5', '3', '4', '8'};

    // 确定加密文件路径
    std::cout << "请输入加密文件路径：";
    std::string input_file_path;
    std::cin >> input_file_path;

    // 确认输出文件路径
    size_t lastSlashPos = input_file_path.find_last_of("/\\");               // 找到最后一个路径分隔符的位置
    std::string out_file_path = input_file_path.substr(0, lastSlashPos + 1); // 从路径字符串中提取目录部分
    std::string inputFileName = input_file_path.substr(lastSlashPos + 1);    // 从路径字符串中提取文件名
    std::string outputFileName = "encryption_" + inputFileName;

    // 打开明文文件和输出文件
    std::ifstream inputFile(input_file_path, std::ios::binary);
    std::ofstream outputFile(out_file_path + outputFileName, std::ios::binary);

    if (!inputFile)
    {
        std::cout << "无法打开输入文件." << std::endl;
        return 0;
    }

    if (!outputFile)
    {
        std::cout << "无法打开输出文件." << std::endl;
        return 0;
    }

    // 初始化AES加密器
    Aes256 aes(key);

    // 定义缓冲区和加密后的数据
    ByteArray inputBuffer;
    ByteArray encryptedBuffer;

    // 读取整个文件到 inputBuffer
    inputFile.seekg(0, std::ios::end);     // 将文件指针移动到文件末尾
    inputBuffer.resize(inputFile.tellg()); // 调整 inputBuffer 大小以容纳整个文件
    inputFile.seekg(0, std::ios::beg);     // 将文件指针移动回文件开头

    inputFile.read(reinterpret_cast<char *>(inputBuffer.data()), inputBuffer.size());

    // 使用您的加密函数将数据块加密
    aes.encrypt(key, inputBuffer, encryptedBuffer);
    // 将加密后的数据写入输出文件
    outputFile.write(reinterpret_cast<const char *>(encryptedBuffer.data()), encryptedBuffer.size());

    // 关闭文件
    inputFile.close();
    outputFile.close();

    std::cout << "文件加密完成" << std::endl;
    std::cout << "文件保存路径: " + out_file_path + outputFileName << std::endl;

    return 0;
}