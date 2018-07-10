#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

class Customer{
    public:
        Customer(uint32_t id, double time, uint32_t maintain, bool history);
        ~Customer();

        uint32_t id;
        double time;
        uint32_t maintain;
        bool history;
    
};

#endif
