#include "ServerInfo.h"

#include<chrono>
#include<thread>

ServerInfo::ServerInfo(){
    std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
	createTime = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch()).count();
}