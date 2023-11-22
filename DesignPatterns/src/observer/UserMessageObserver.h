#pragma once

#include "observer.h"
#include "UserWallet.h"

class UserMessageObserver : public Observer{
public:
    UserMessageObserver(UserWallet * _wallet);

    virtual void update() override;

    UserWallet * wallet = nullptr;
};