#include "client.h"
#include "waiter.h"


Client::Client(){
}

Client::~Client(){
}

void Client::order(){
    Waiter KFCWaiter;
    KFCWaiter.construct();
}
