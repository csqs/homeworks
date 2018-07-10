#include <iostream>

#include "registercourse.h"


RegisterCourse::RegisterCourse(int input_class, int input_time){
    class_number = input_class;
    time = input_time;
}

RegisterCourse::~RegisterCourse(){
}

bool RegisterCourse::registerNotify(){
    if(time % 3){
        std::cout << "Class full!" << std::endl;
        return false;
    }
    else{
        std::cout << "Class is not full. You should pay $100 to get in. " << std::endl;
        return true;
    }
    
}
