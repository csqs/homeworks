#include "car.h"

//#include <assert.h>


Car::Car(uint32_t type_temp, uint32_t makeIn_temp, uint32_t num_temp, uint32_t vip_temp) {
    makeIn = makeIn_temp;
    type = type_temp;
    num = num_temp;
    vip = vip_temp;
}

Car::~Car() {
}

void Car::notify() {
    uint32_t month = 1, time = 0;
    int last_month_num = 0, car_num = num;
    uint32_t make_in_time = 5, make_out_time = 7;
    
    //std::cout << "car number before: " << num << std::endl;
    while(car_num > 0){
        if(makeIn) time += rand() % make_in_time + 1;
        else time += rand() % make_out_time + 1;
        
        car_num--;
        if(type == 1) std::cout << "Audi Made Time : " << time << std::endl;
        else if(type == 2) std::cout << "BMW Made Time : " << time << std::endl;
        else if(type == 3) std::cout << "Benz Made Time : " << time << std::endl;
        else if(type == 4) std::cout << "Toyota Made Time : " << time << std::endl;
        else if(type == 5) std::cout << "Hyundai Made Time : " << time << std::endl;
        
        if(vip){
            if(time > (month * 30)){
                std::cout << "Above Type Month Made Number : " << (num - last_month_num) << std::endl;
                last_month_num = num;
                month++;
            }
        }
        //std::cout << "car number : " << car_num << std::endl;
    }
}
