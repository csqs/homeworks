#include "system.h"
#include "customer.h"
#include "strategy.h"

#include <sstream>

uint32_t find_car_price(uint32_t car_type){
    if(car_type == Toyota) return Toyota_price;
    else if(car_type == Ford) return Ford_price;
    else if(car_type == Benz) return Benz_price;
    else if(car_type == Audi) return Audi_price;
    else if(car_type == BMW) return BMW_price;
    else return 0;
}

std::string find_car_name(uint32_t car_type){
    if(car_type == Toyota) return "Toyota";
    else if(car_type == Ford) return "Ford";
    else if(car_type == Benz) return "Benz";
    else if(car_type == Audi) return "Audi";
    else if(car_type == BMW) return "BMW";
    else return 0;
}


System::System() {
    for(uint32_t i = 1; i <= 5; i++){
        uint32_t car_price = find_car_price(i);
        Car temp(i, car_price);
        car_list.push_back(temp);
    }
}

System::~System() {
}

void System::InOutSearch(){
    
    time_t start_time = -1, current_time = -1;
    double run_time = 1, duration = 0;
    
    time(&start_time);
    std::cout << "Start the car-seller simulation..." << std::endl;
    while(duration < run_time){
        uint32_t car_type = rand() % 5 + 1;
        uint32_t sell_or_buy = rand() % 2;
        uint32_t car_num = rand() % 10 + 1;
        
        if(!sell_or_buy){
            time(&current_time);
            car_list[car_type].sell(car_num, current_time);
        }
        else{
            time(&current_time);
            car_list[car_type].buy(car_num, current_time);
        }
        time(&current_time);
        duration = difftime(current_time, start_time);
    }
    std::cout << "The simulation ends. Duration: " << duration << std::endl;
    
    std::cout << "You can type in a number(1-5) to find information of the corresponding car. " << std::endl;
    std::cout << "1 - Toyota" << std::endl;
    std::cout << "2 - Ford" << std::endl;
    std::cout << "3 - Benz" << std::endl;
    std::cout << "4 - Audi" << std::endl;
    std::cout << "5 - BMW" << std::endl;
    std::cout << "You can type in a '0' to quit. " << std::endl;
    
    char input = '1';
    while(input != '0'){
        std::cin >> input;
        int car_type = input - '1';
        if(car_type >= 0 && car_type <= 4)
            car_list[car_type].print();
        else
            std::cout << "Input again." << std::endl;
    }
    std::cout << "Function ends." << std::endl;

}

void System::PriceSearch(){
    std::string input;
    int input_id;
    uint32_t time_second;
    uint32_t maintain;
    bool history;
    
    std::stringstream transfer;
    time_t start_time = -1, current_time = -1;
    time(&start_time);
    
    std::cout << "Before show the cars' information, please input your ID." << std::endl;
    std::cout << "Input '0' to quit." << std::endl;
    std::cin >> input;
    transfer << input;
    transfer >> input_id;
    transfer.clear();
    //std::cout << std::endl;
    //std::cout << "Input: " << input_id << std::endl;
    
    while(input_id != 0){
        time(&current_time);
        time_second = difftime(current_time, start_time);
        maintain = rand() % 5;
        history = rand() % 2;
        
        Customer car_buyer(input_id, time_second, maintain, history);
        std::cout << "User Information:" << std::endl;
        std::cout << "User ID: " << input_id << std::endl;
        std::cout << "Check in time: " << time_second << std::endl;
        std::cout << "Maintain times: " << maintain << std::endl;
        std::cout << "Patron: " << history << std::endl << std::endl;
        
        std::cout << "Car Information for You:" << std::endl;
        for(uint32_t i = 1; i <= 5; i++){
            float car_price = float(find_car_price(i));
            uint32_t maintain_gift = 0;
            if(time_second % 3){
                Patron price_patron(car_price, maintain_gift);
                price_patron.PatronPrice();
                car_price = price_patron.price;
            }
            if(history){
                Holiday price_holiday(car_price, maintain_gift);
                price_holiday.HolidayPrice();
                car_price = price_holiday.price;
                maintain_gift = price_holiday.maintain;
            }
            std::cout << find_car_name(i) <<"   price: " << car_price << "   maintain gift: "<< maintain_gift << std::endl;
        }
        
        std::cout << "Before show the cars' information, please input your ID." <<std:: endl;
        std::cout << "Input '0' to quit." << std::endl;
        std::cin >> input;
        transfer << input;
        transfer >> input_id;
        transfer.clear();
        std::cout << std::endl;
    }
    
    std::cout << "Function ends." << std::endl;
    
}