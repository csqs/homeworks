#ifndef CAR_H
#define CAR_H

#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

class Car{
    public:
        Car(uint32_t type, uint32_t makeIn, uint32_t num, uint32_t vip);
        ~Car();

        void notify();

        uint32_t makeIn;
        uint32_t type;
        uint32_t num;
        uint32_t vip;
};

class Toyota : public Car {
    public:
        Toyota(uint32_t type, uint32_t makeIn, uint32_t num, uint32_t vip);
        ~ Toyota();
};

class Hyundai : public Car {
public:
    Hyundai(uint32_t type, uint32_t makeIn, uint32_t num, uint32_t vip);
    ~ Hyundai();
};

class Benz : public Car {
public:
    Benz(uint32_t type, uint32_t makeIn, uint32_t num, uint32_t vip);
    ~ Benz();
};

class Audi : public Car {
public:
    Audi(uint32_t type, uint32_t makeIn, uint32_t num, uint32_t vip);
    ~ Audi();
};

class BMW : public Car {
public:
    BMW(uint32_t type, uint32_t makeIn, uint32_t num, uint32_t vip);
    ~ BMW();
};

#endif
