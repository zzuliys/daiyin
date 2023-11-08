#include "SqlQuery.h"
#include <iostream>
#include <string>

SqlQuery::SqlQuery(std::string conn, std::string username, std::string password)
{
    this->m_conn = conn;
    this->m_username = username;
    this->m_password = password;
}

int SqlQuery::query(std::string conn, std::string username, std::string password)
{
    std::cout << conn << username << password << std::endl;

    std::cout << "query something ! \n"
              << std::endl;
    return 1;
}
