#include "client.h"
#include "database.h"


Client::Client(){
}

Client::~Client(){
}

void Client::begin(){
    Database db_one;
    db_one.interface();
    
}
