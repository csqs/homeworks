#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <string>

#include "car.h"

#define Toyota 1
#define Ford 2
#define Benz 3
#define Audi 4
#define BMW 5

#define Toyota_price 10
#define Ford_price 20
#define Benz_price 30
#define Audi_price 40
#define BMW_price 50



uint32_t find_car_price(uint32_t car_type);
std::string find_car_name(uint32_t car_type);

class System{
    public:
        System();
        ~System();
    
        void InOutSearch();
        void PriceSearch();
    
        std::vector<Car> car_list;

};

#endif
