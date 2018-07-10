#ifndef CLIENT_H
#define CLIENT_H

#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

class Client{
    public:
        Client(uint32_t client_id);
        ~Client();

        void begin();
    
        uint32_t client_id;
};


#endif
