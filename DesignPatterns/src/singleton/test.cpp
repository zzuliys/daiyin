#include <iostream>
#include "SqlQuery.h"
#include "DBConfig.h"
int main()
{
    for (int i = 0; i < 10; i++)
    {
        DBConfig *config = DBConfig::getInstance();

        SqlQuery query("1", "2", "3");
        std::cout << "query" << std::endl;
    }
    return 0;
}