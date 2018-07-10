#include "car.h"

//#include <assert.h>


Car::Car(uint32_t car_name, uint32_t price) {
    name = car_name;
    price = price;
    num = 0;
}

Car::~Car() {
}

void Car::sell(uint32_t sell_num, double time) {
    if(sell_num > num)
        std::cout << "Limited Supply!" << endl << "supply num: " << num << endl;
    else{
        pair<uint32_t, double> temp(sell_num, time);
        sell_history.push_back(temp);
        num -= sell_num;
    }
}

void Car::buy(uint32_t buy_num, double time) {
    pair<uint32_t, double> temp(buy_num, time);
    buy_history.push_back(temp);
    num += buy_num;
}

void Car::print(){
    uint32_t sell_total_num = 0, buy_total_num = 0';
    
    std::cout<< "Sell Histoy (num time)" << endl;
    for(uint32_t i = 0; i < sell_history.size(); i++){
        std::cout << sell_history[i].first << "  " << sell_history[i].second << endl;
        sell_total_num += sell_history[i].first;
    }
    std::cout << "Car Price "<< price << " Total Sell Num" << sell_total_num << "The Sum " << (sell_total_num * price) << endl;
    
    std::cout<< "Buy Histoy (num time)" << endl;
    for(uint32_t i = 0; i < buy_history.size(); i++){
        std::cout << buy_history[i].first << "  " << buy_history[i].second << endl;
        buy_total_num += buy_history[i].first;
    }
    std::cout << "Car Price "<< price << " Total Sell Num" << buy_total_num << "The Sum " << (buy_total_num * price) << endl;
    
    
}
