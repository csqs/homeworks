#ifndef CAR_H
#define CAR_H

#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

class Car{
    public:
        Car(uint32_t car_name, uint32_t price);
        ~Car();

        void sell(uint32_t sell_num, double time);
        void buy(uint32_t buy_num, double time);
        void print();

        uint32_t name;
        uint32_t price;
        uint32_t num;
    
        std::vector<std::pair<uint32_t, double> > sell_history;
        std::vector<std::pair<uint32_t, double> > buy_history;
};

class Toyota : public Car {
    public:
        Toyota(uint32_t car_name, uint32_t price);
        ~ Toyota();
};

class Ford : public Car {
public:
    Ford(uint32_t car_name, uint32_t price);
    ~ Ford();
};

class Benz : public Car {
public:
    Benz(uint32_t car_name, uint32_t price);
    ~ Benz();
};

class Audi : public Car {
public:
    Audi(uint32_t car_name, uint32_t price);
    ~ Audi();
};

class BMW : public Car {
public:
    BMW(uint32_t car_name, uint32_t price);
    ~ BMW();
};

#endif
