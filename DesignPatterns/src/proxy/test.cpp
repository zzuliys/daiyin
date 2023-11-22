#include <iostream>

#include"ServerInfoGetterproxy.h"
#include"ServerInfoGetterCPUMEM.h"

#include<chrono>
#include<thread>

int main(){

    while (1)
    {
        ServerInfoGetterCPUMEM win;

        ServerInfoGetterProxy getter(&win);
        ServerInfo info = getter.getinfo();

        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    
    return 0;
}