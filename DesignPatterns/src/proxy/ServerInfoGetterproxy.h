#pragma once 

#include "ServerInfoGetterBase.h"
#include "ServerInfoGetterCPUMEM.h"

class ServerInfoGetterProxy : public ServerInfoGetterBase{
public:
    ServerInfoGetterProxy(ServerInfoGetterBase * getterBase);

    virtual ServerInfo getinfo() override;
private:
    // 静态变量cache需要在实现中定义，以确保内存空间被分配
    static ServerInfo cache;
    ServerInfoGetterBase * getterbase = nullptr;
};