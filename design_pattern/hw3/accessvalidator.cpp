#include "accessvalidator.h"

AccessValidator::AccessValidator() {
}

AccessValidator::~AccessValidator() {
}

bool AccessValidator::validateUser(std::string userID){
    if(userID == "admin") return true;
    else return false;
}

