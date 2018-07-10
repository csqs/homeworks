#include <iostream>
#include "client.h"
#include "subscribe.h"


Client::Client(int client_id_input){
    client_id = client_id_input;
}

Client::~Client(){
}

void Client::updateState(){
    //Subscribe subscribe_one;
    char input = '0';
    std::cout << "Hello, client :"<< this->client_id << std::endl << "Do you want to subscribe the message? Yes -- 1, No -- 0" << std::endl;
    std::cin >> input;
    
    if(input == '1'){
        this->client_state = 1;
        //subscribe_one.attach(this->client_id);
    }
    else{
        this->client_state = 0;
        //subscribe_one.detach(this->client_id);
    }
    
}
