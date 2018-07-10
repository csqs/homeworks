//
//  main.cpp
//  car_system
//
//  Created by macx  on 16-10-5.
//  Copyright (c) 2016年 macx . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <time.h>

#include "system.h"

using namespace std;


int main (int argc, char ** argv) {
    
    System car_center;
    
    std::cout << "Welcome to the car-seller information center. " << endl;
    std::cout << "You can type in a number(0-2) to the corresponding function. " << endl;
    std::cout << "1 - Find the buy-in or sell-out information of some car." << endl;
    std::cout << "2 - Want to buy a car today." << endl;
    std::cout << "0 - Quit." << endl;
    
    char input = '1';
    while(input != '0'){
        std::cin >> input;
        if(input == '1')
            car_center.InOutSearch();
        else if(input == '2')
            car_center.PriceSearch();
        else if(input != '0')
            std::cout << "Input again." << endl;
        
        std::cout << "You can type in a number(0-2) to the corresponding function. " << endl;
        std::cout << "1 - Find the buy-in or sell-out information of some car." << endl;
        std::cout << "2 - Want to buy a car today." << endl;
        std::cout << "0 - Quit." << endl;

        
    }
    std::cout << "System ends." << endl;
    
    
    return 0;
}

