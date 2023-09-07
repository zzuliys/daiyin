#include <iostream>
#include "test2.h"
using namespace std;

__declspec(dllexport) void sayTest2()
{
    cout << "这里是t2" << endl;
}