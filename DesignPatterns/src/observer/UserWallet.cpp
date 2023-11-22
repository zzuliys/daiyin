
#include "UserWallet.h"

void UserWallet::attachObserver(Observer * _observer){
    observerVec.push_back(_observer);
}

void UserWallet::deposit(float p){
    balance += p;
}

void UserWallet::consume(float p){
    balance -= p;
    notify();
}

float UserWallet::getBalance(){
    return balance;
}

void UserWallet::notify(){
    for(int i=0; i<observerVec.size(); i++){
        observerVec[i]->update();
    }
}

