#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <numeric>
#include "AES256.h"

// 生成指定长度的随机字符序列
std::string generateRandomString(int length)
{
    // 定义字符集，你可以根据需要扩展或修改字符集
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    // 创建随机数生成器
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, charset.size() - 1);

    // 生成随机字符序列
    std::string randomString;
    for (int i = 0; i < length; ++i)
    {
        randomString += charset[distribution(generator)];
    }

    return randomString;
}

int main(int argc, char *argv[])
{
    // 定义密钥
    ByteArray key;

    // 获取option ，option = 0 加密 option = 1 解密
    std::string option = argv[1];
    if (option != "0" && option != "1")
    {
        std::cout << "请正确输入option" << std::endl;
        std::cout << "option = 0 ->加密" << std::endl;
        std::cout << "option = 1 ->解密" << std::endl;
        return 0;
    }

    // 获取输入输出路径
    std::string inputFilePath = argv[2];
    std::string outputFilePath = argv[3];

    // 加密时未输入key，则自动生成key
    if (option == "0" && argv[4] == NULL)
    {
        int length = 20; // 指定生成的随机字符序列的长度
        std::string randomString = generateRandomString(length);

        for (std::string::iterator it = randomString.begin(); it != randomString.end(); it++)
        {
            key.push_back(*it);
        }
    }
    else if (argv[4] != NULL)
    {
        for (char c : static_cast<std::string>(argv[4]))
        {
            key.push_back(static_cast<unsigned char>(c));
        }
    }
    else if (option == "1" && argv[4] == NULL)
    {
        std::cout << "解密必须输入key!" << std::endl;
        return 0;
    }

    // 输出key至数据归档文件
    if (option == "0")
    {

        size_t lastSlashPos = outputFilePath.find_last_of("/\\");                                                                    // 找到最后一个路径分隔符的位置
        std::string outDataFilePath = outputFilePath.substr(0, lastSlashPos + 1);                                                    // 从路径字符串中提取目录部分
        std::string outputFileName = outputFilePath.substr(lastSlashPos + 1, outputFilePath.find_last_of(".") - (lastSlashPos + 1)); // 从路径字符串中提取文件名

        // 打开归档文件
        std::ofstream outputDataFile(outDataFilePath + outputFileName + ".txt", std::ios::binary);
        if (!outputDataFile)
        {
            std::cout << "无法打开归档数据文件." << std::endl;
            return 0;
        }

        std::string key_string;
        for (std::vector<unsigned char>::iterator it = key.begin(); it != key.end(); ++it)
        {
            key_string += *it;
        }

        outputDataFile.write(("key = " + key_string).c_str(), key_string.size());
        std::cout << "key = " + key_string << std::endl;
        std::cout << "key save in -> " + outDataFilePath + outputFileName + ".txt" << std::endl;
    }

    // 打开明文文件
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    if (!inputFile)
    {
        std::cout << "无法打开输入文件." << std::endl;
        return 0;
    }

    // 打开输出文件
    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!outputFile)
    {
        std::cout << "无法打开输出文件." << std::endl;
        return 0;
    }

    // 初始化AES加密器  TODO
    Aes256 aes(key);

    // 定义缓冲区和加密后的数据
    ByteArray inputBuffer;
    ByteArray encryptedBuffer;

    // 读取整个文件到 inputBuffer
    inputFile.seekg(0, std::ios::end);     // 将文件指针移动到文件末尾
    inputBuffer.resize(inputFile.tellg()); // 调整 inputBuffer 大小以容纳整个文件
    inputFile.seekg(0, std::ios::beg);     // 将文件指针移动回文件开头

    inputFile.read(reinterpret_cast<char *>(inputBuffer.data()), inputBuffer.size());

    if (option == "0")
    {
        // 使用您的加密函数将数据块加密
        aes.encrypt(key, inputBuffer, encryptedBuffer);
    }
    else
    {
        // 使用您的解密函数将数据块解密
        aes.decrypt(key, inputBuffer, encryptedBuffer);
    }

    // 将加密后的数据写入输出文件
    outputFile.write(reinterpret_cast<const char *>(encryptedBuffer.data()), encryptedBuffer.size());

    // 关闭文件
    inputFile.close();
    outputFile.close();

    if (option == "0")
    {
        std::cout << "文件加密完成" << std::endl;
    }
    else if (option == "1")
    {
        std::cout << "文件解密完成" << std::endl;
    }

    return 0;
}