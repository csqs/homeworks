#include <iostream>

#include "notifyuser.h"


NotifyUser::NotifyUser(int input_client, int input_class){
    class_number = input_class;
    client_id = input_client;
}

NotifyUser::~NotifyUser(){
}

void NotifyUser::notify(){
    std::cout << "You have registered a class."<< std::endl;
    std::cout << "Client ID: "<< client_id << std::endl;
    std::cout << "Class ID"<< class_number << std::endl;
}
