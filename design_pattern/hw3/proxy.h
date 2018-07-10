#ifndef PROXY_H
#define PROXY_H

#include <string>

#include "UsageLogger.h"
#include "RealSearcher.h"
#include "AccessValidator.h"

class Proxy{
    public:
        Proxy();
        ~Proxy();
    
        int doSearch(std::string userID, std::string keyValue);
        bool checkAccess(std::string userID);
        void logUsage(std::string userID);
};

#endif
