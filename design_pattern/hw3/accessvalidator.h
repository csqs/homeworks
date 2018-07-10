#ifndef ACCESSVALIDATOR_H
#define ACCESSVALIDATOR_H

#include <string>

class AccessValidator{
    public:
        AccessValidator();
        ~AccessValidator();
    
        bool validateUser(std::string userID);
    
};

#endif
