#include <iostream>

#include "paymentgateway.h"


PaymentGateway::PaymentGateway(int input_paynumber){
    paynumber = input_paynumber;
}

PaymentGateway::~PaymentGateway(){
}

bool PaymentGateway::payNotify(){
    if(paynumber == 100){
        std::cout << "Successful Paying!" << std::endl;
        return true;
    }
    else{
        std::cout << "Pay the wrong number." << std::endl;
        return false;

    }
}
