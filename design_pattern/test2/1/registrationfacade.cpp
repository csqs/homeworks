#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "registrationfacade.h"
#include "registercourse.h"
#include "paymentgateway.h"
#include "notifyuser.h"


RegistrationFacade::RegistrationFacade(int client){
    client_id = client;
}

RegistrationFacade::~RegistrationFacade(){
}

void RegistrationFacade::interface(){
    char register_continue = '1';
    
    while(register_continue == '1'){
        std::cout << "Weclome to register the classes. We have the classes below:" << std::endl;
        std::cout << "1 -- English-zh" << std::endl << "2 -- English-li" << std::endl;
        std::cout << "Please enter the class number to choose:" << std::endl;
        
        int class_number = 0;
        std::cin >> class_number;
        int time = rand() % 1000;
        
        RegisterCourse course(class_number, time);
        
        if(course.registerNotify()){
            std::cout << "Please enter the correct paynumber:" << std::endl;
            int payNumber = 0;
            std::cin >> payNumber;
            PaymentGateway paygate(payNumber);
            if(paygate.payNotify()){
                NotifyUser notifyClient(this->client_id, class_number);
                notifyClient.notify();
            }
        }
        std::cout << "Continue to enter '1', or '0'." << std::endl;
        std::cin >> register_continue;
    }
}
