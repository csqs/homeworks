#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

class Strategy{
    public:
        Strategy(float price, uint32_t maintain);
        ~Strategy();
    
        float price;
        uint32_t maintain;
};

class Patron : public Strategy {
    public:
        Patron(float price, uint32_t maintain);
        ~Patron();
    
        void PatronPrice();
    
        float price;
        uint32_t maintain;
};

class Holiday : public Strategy {
    public:
        Holiday(float price, uint32_t maintain);
        ~Holiday();
    
        void HolidayPrice();
    
        float price;
        uint32_t maintain;
};


#endif
