//
//  main.cpp
//  car_maker
//
//  Created by macx  on 16-10-19.
//  Copyright (c) 2016年 macx . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <time.h>

#include "system.h"

using namespace std;

int main (int argc, char ** argv) {
    System system;
    
    std::cout << "Welcome to car-maker. " << endl;
    
    char input = '1';
    while(input != '0'){
        if(input != '0'){
            std::string userID;
            std::cout << "Type in the user ID: " << endl;
            std::cin >> userID;
            
            system.checkUser(userID);
            system.carDisplay();
            system.needGet();
            system.carMake();
            
           	std::cout << "Type in '0' to quit, '1' to go on." << endl;
           	std::cin >> input;
        }
    }
    std::cout << "System ends." << endl;
    
    return 0;
}


