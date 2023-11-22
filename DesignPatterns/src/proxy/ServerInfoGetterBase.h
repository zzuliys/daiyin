#pragma once

#include "ServerInfo.h"

class ServerInfoGetterBase
{
public:
	virtual ServerInfo getinfo() = 0;
};