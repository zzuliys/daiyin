#include "ServerInfoGetterproxy.h"
#include <iostream>
#include <chrono>

// 静态变量cache需要在实现中定义，以确保内存空间被分配
ServerInfo ServerInfoGetterProxy::cache;
ServerInfoGetterProxy::ServerInfoGetterProxy(ServerInfoGetterBase * _getterbase){
    getterbase = _getterbase;
}

ServerInfo ServerInfoGetterProxy::getinfo(){
    if(cache.valid == false){
        cache = getterbase->getinfo();
        std::cout << "cache false" << std::endl;
        return cache;
    }

    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	long long currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();

    if((currentTime-cache.createTime) <= 2000){
        std::cout << "time <= 2000ms" << std::endl;
        return cache;
    }else{
        std::cout << "time >= 2000ms" << std::endl;
        cache = getterbase->getinfo();
        return cache;
    }

    return getterbase->getinfo();
}