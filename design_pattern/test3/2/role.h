#ifndef ROLE_H
#define ROLE_H

#include "memento.h"

class Role{
    public:
        Role();
        ~Role();

        Memento saveState();
        void recoverState(Memento memento_temp);
        void show();
        void fight();
    
        int vitality;
};


#endif
