
#include "UserMessageObserver.h"

#include <stdio.h>

UserMessageObserver::UserMessageObserver(UserWallet * _wallet){
    wallet = _wallet;
    wallet->attachObserver(this);
}

void UserMessageObserver::update(){
    if(wallet->getBalance() < 5 ){
        printf("wallet balance < 5\n");
    }
}