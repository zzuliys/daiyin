#pragma once

#include "ServerInfoGetterBase.h"

class ServerInfoGetterCPUMEM : public ServerInfoGetterBase{
public:
    virtual ServerInfo getinfo() override;
};

