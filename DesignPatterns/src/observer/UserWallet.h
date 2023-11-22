#pragma once

#include "observer.h"
#include <vector>

class UserWallet{
public:
    void attachObserver(Observer * observer);

    void deposit(float p);

    void consume(float p);

    float getBalance();

    void notify();

    float balance = 0.0;
    std::vector<Observer*> observerVec;
};