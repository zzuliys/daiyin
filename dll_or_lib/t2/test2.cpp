#include <iostream>
#include "test2.h"
using namespace std;

// int main()
// {
//     cout << "1111111" << endl;
//     return 0;
// }

__declspec(dllexport) void sayTest2()
{
    cout << "这里是t2" << endl;
}