#include <iostream>
#include "test1.h"
#include "test2.h"
#include "test3.h"
using namespace std;

void sayTest1()
{
    cout << "这里是t1" << endl;
}

int main()
{
    sayTest1();
    sayTest2();
    sayTest3();
    return 0;
}