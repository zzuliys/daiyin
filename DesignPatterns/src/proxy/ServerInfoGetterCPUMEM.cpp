#include "ServerInfoGetterCPUMEM.h"

ServerInfo ServerInfoGetterCPUMEM::getinfo(){

    ServerInfo info;
    info.cpu = 0.6;
    info.mem = 0.4;
    info.valid = true;
    
    return info;
}