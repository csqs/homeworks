#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#include "add.h"

Add::Add(std::vector<std::string> input_vector) {
    information = input_vector;
}

Add::~Add() {
}

void Add::dbAdd(){
    std::ofstream db;
    db.open("/Users/macx/Desktop/database/database.txt", std::ios::app);
    if(!db.is_open()){
        db.close();
        std::cout <<"open fail"<< std::endl;
    }
    else{
        
        std::string buffer = information[0] + "   " + information[1] + "   " + information[2];
        db << std::endl << buffer;
        db.close();
        
        std::ifstream db;
        db.open("/Users/macx/Desktop/database/database.txt", std::ios::out | std::ios::in);
        while(getline(db, buffer)){
            std::cout << buffer << std::endl;
        }
        
        db.close();
    }
    
}

