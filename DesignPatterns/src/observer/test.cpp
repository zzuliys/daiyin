#include "UserWallet.h"
#include "UserMessageObserver.h"

#include <stdio.h>

int main(){

    UserWallet wallet;
    
    UserMessageObserver observer(&wallet);

    wallet.deposit(100);

    for(int i= 1; i<=100; i++){
        wallet.consume(1.0);
        printf("%f\n", wallet.getBalance());
    }

    return 0;
}