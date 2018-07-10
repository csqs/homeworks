#include "client.h"
#include "registrationfacade.h"


Client::Client(uint32_t input_id){
    client_id = input_id;
}

Client::~Client(){
}

void Client::begin(){
    RegistrationFacade facade_demo(this->client_id);
    facade_demo.interface();
    
}
