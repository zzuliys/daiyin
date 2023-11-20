#include <iostream>
#include "Message.h"
#include "XiaojiuziMessage.h"

int main()
{
    Message *message = new XiaojiuziMessage("001", "123456");
    message->sendMessage("1", "send message");
    std::cout << "11111111";
    return 0;
}