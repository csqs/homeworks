#include "proxy.h"
#include "realsearcher.h"


Proxy::Proxy() {
}

Proxy::~Proxy() {
}

bool Proxy::checkAccess(std::string userID){
    AccessValidator accessValidator;
    return accessValidator.validateUser(userID);
}

void Proxy::logUsage(std::string userID){
    UsageLogger logger(userID);
    logger.save();
}

int Proxy::doSearch(std::string userID, std::string keyValue){
    if(checkAccess(userID)){
        logUsage(userID);
        RealSearcher searcher;
        return searcher.doSearch(keyValue);
    }
    else{
        return NULL;
    }
        
}