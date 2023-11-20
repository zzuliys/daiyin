#include "DBConfig.h"

#include <fstream>
#include <iostream>
#include <mutex>

DBConfig *DBConfig::config = nullptr;
static std::mutex mutex;
DBConfig *DBConfig::getInstance()
{
    std::lock_guard<std::mutex> lock(mutex);
    if (config == nullptr)
    {
        config = new DBConfig();
    }
    return config;
}

DBConfig::DBConfig()
{
    std::fstream fs("../../dbconfig.txt");
    char tempStr[1024];
    int index = 0;
    while (fs.getline(tempStr, 1024))
    {
        if (index == 0)
        {
            m_conn = tempStr;
        }
        if (index == 1)
        {
            m_username = tempStr;
        }
        if (index == 2)
        {
            m_password = tempStr;
        }
        index++;
    }
    std::cout << "read DB config from file" << std::endl;
}

std::string DBConfig::getConn()
{
    return m_conn;
}

std::string DBConfig::getUsername()
{
    return m_username;
}

std::string DBConfig::getPassword()
{
    return m_password;
}