#include <iostream>

#include "role.h"


Role::Role(){
    vitality = 100;
}

Role::~Role(){
}

void Role::show(){
    std::cout << "Now, the role's vitality is : " << vitality << std::endl;
}

void Role::fight(){
    std::cout << "Battle begin... " << std::endl;
    vitality = 0;
    show();
}

void Role::recoverState(Memento memento_temp){
    this->vitality = memento_temp.vitality;
}

Memento Role::saveState(){
    Memento memento_role(vitality);
    return memento_role;
}

