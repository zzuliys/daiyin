#pragma once
class ServerInfo
{
public:
    ServerInfo();
    
    float cpu;
    float mem;

    long long createTime;

    bool valid = false;
};
