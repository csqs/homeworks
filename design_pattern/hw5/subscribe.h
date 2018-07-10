#ifndef SUBSCRIBE_H
#define SUBSCRIBE_H

#include "client.h"
#include <vector>


class Subscribe{
    public:
        Subscribe();
        ~Subscribe();

        void notify();
        void getState();
        void attach(Client client_one);
        void detach(Client client_one);
    
        int subscribe_state;
        std::vector<Client> client_list;
};


#endif
