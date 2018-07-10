#include "system.h"
#include "car.h"


System::System() {
    for(uint32_t i = 1; i <= 5; i++){
        std::pair<uint32_t, uint32_t> temp(0, 0);
        need_list.push_back(temp);
    }
    vip = 0;
}

System::~System() {
}

void System::checkUser(std::string userID){
    if(userID == "vip")
        this->vip = 1;

}

void System::carDisplay(){
    std::cout << "Show the car feature." << std::endl;
    std::cout << "Audi -- Hard Shell" << std::endl;
    std::cout << "BMW -- Streamlined Design" << std::endl;
    std::cout << "Benz -- Fast Speed" << std::endl;
    std::cout << "Toyota -- Low Price" << std::endl;
    std::cout << "Hyundai -- Quick Begin" << std::endl;
}


void System::needGet(){
    uint32_t make_in_number = 0, make_out_number = 0;
    char input = '0';
    
    std::cout << "Please type in the number fllowing the order: Audi BMW Benz Toyota Hyundai." << std::endl;
    
    for(uint32_t i = 0; i < 5; i++){
        std::cout << "Make In Number :" << std::endl;
        std::cin >> input;
        make_in_number = input - '0';
        std::cout << "Make Out Number :" << std::endl;
        std::cin >> input;
        make_in_number = input - '0';
        need_list[i].first = make_in_number;
        need_list[i].second = make_out_number;
    }
}

void System::carMake(){
    for(uint32_t i = 0; i < 5; i++){
        //std::cout << "Make In Number First In:"<< need_list[i].first << std::endl;
        Car temp_in((i + 1), 1, need_list[i].first, vip);
        //std::cout << "Make In Number First Out:"<< temp_in.num << std::endl;
        temp_in.notify();
        Car temp_out((i + 1), 0, need_list[i].second, vip);
        temp_out.notify();
    }
}