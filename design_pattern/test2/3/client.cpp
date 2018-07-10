#include <iostream>

#include "client.h"
#include "price.h"


Client::Client(){
}

Client::~Client(){
}

void Client::begin(){
    char type = 'A';
    int price = 0;
    
    std::cout << "Please input the object type: " << std::endl;
    std::cin >> type;
    
    std::cout << "Please input the object price: " << std::endl;
    std::cin >> price;
    
    Price price_demo(type, price);
    price_demo.priceSum();
    
}
