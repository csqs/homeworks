#include "usagelogger.h"

#include <time.h>

UsageLogger::UsageLogger(std::string userId) {
    userID = userId;
}

UsageLogger::~UsageLogger() {
}


void UsageLogger::save(){
    time_t current_time = -1;
    time(&current_time);
    
    std::pair<std::string, double> temp(this->userID, current_time);
    history.push_back(temp);
}

