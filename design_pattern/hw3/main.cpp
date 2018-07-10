//
//  main.cpp
//  DbSearch
//
//  Created by macx  on 16-10-17.
//  Copyright (c) 2016年 macx . All rights reserved.
//

//
//  main.cpp
//  car_system 学号 地理
//
//  Created by macx  on 16-10-5.
//  Copyright (c) 2016年 macx . All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <time.h>

#include "client.h"

using namespace std;


int main (int argc, char ** argv) {
    
    Client client;
    
    std::cout << "Welcome to database. " << endl;
    
    char input = '1';
    while(input != '0'){
        if(input != '0'){
            client.search();
            std::cout << "You can type in '1' to go on. " << endl;
            std::cout << "You can type in '0' to quit. " << endl;
            std::cin >> input;
        }
    }
    std::cout << "System ends." << endl;
    
    
    return 0;
}


