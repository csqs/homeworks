#include "client.h"

#include <string>
#include <iostream>

//#include <assert.h>


Client::Client() {
}

Client::~Client() {
}

void Client::search() {
    Proxy searcher;
    std::string userId = "Admin";
    std::string searchType = "Item_num";
    std::cout << "Please enter the UserID: " << std::endl;
    std::cin >> userId;
    std::cout << "Please enter the Item Name: " << std::endl;
    std::cin >> searchType;
    
    int result = searcher.doSearch(userId, searchType);
    std::cout << "Item num: " << result << std::endl;
}

