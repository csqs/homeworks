#ifndef USAGELOGGER_H
#define USAGELOGGER_H

#include <vector>
#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <string>

class UsageLogger{
    public:
        UsageLogger(std::string userID);
        ~UsageLogger();
    
        void save();
    
        std::vector<std::pair<std::string, double> > history;
        std::string userID;
};


#endif