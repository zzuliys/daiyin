#include <iostream>
#include "test1.h"
#include "test2.h"
#include "test3.h"

__declspec(dllimport) void sayTest2();

void sayTest1()
{
    std::cout << "这里是t1" << std::endl;
}

int main()
{
    sayTest1();
    sayTest2();
    sayTest3();
    return 0;
}