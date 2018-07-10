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

class System{
    public:
        System();
        ~System();
    
        void checkUser(std::string userID);
        void carDisplay();
        void needGet();
        void carMake();
    
        std::vector<std::pair<uint32_t, uint32_t>> need_list;
        uint32_t vip;

};

#endif
