#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#include "change.h"

Change::Change(std::vector<std::string> input_vector) {
    information = input_vector;
}

Change::~Change() {
}

void Change::dbChange(){
    std::ifstream db;
    std::ofstream db_temp;
    db.open("/Users/macx/Desktop/database/database.txt", std::ios::out | std::ios::in);
    db_temp.open("/Users/macx/Desktop/database/database_temp.txt", std::ios::out);
    if(!db.is_open() || !db_temp.is_open()){
        db.close();
        std::cout <<"open fail"<< std::endl;
    }
    else{
        std::string buffer;
        while(getline(db, buffer)){
            if(buffer.find(information[0]) != std::string::npos){
                buffer = information[0] + "   " + information[1] + "   " + information[2];
                db_temp << buffer << std::endl;
            }
            else{
                db_temp << buffer << std::endl;
            }
            std::cout << buffer << std::endl;
        }
        
        db.close();
        db_temp.close();
        //remove("/Users/macx/Desktop/database/database.txt");
        rename("/Users/macx/Desktop/database/database_temp.txt", "/Users/macx/Desktop/database/database.txt");
    }
    
}

