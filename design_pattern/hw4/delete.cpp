#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#include "delete.h"

Delete::Delete(std::string input_id) {
    student_id = input_id;
}

Delete::~Delete() {
}

void Delete::dbDelete(){
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
            if(buffer.find(student_id) == std::string::npos){
                db_temp << buffer << std::endl;
                std::cout << buffer << std::endl;
            }
        }
        
        db.close();
        db_temp.close();
        //remove("/Users/macx/Desktop/database/database.txt.txt");
        rename("/Users/macx/Desktop/database/database_temp.txt", "/Users/macx/Desktop/database/database.txt");
    }
    
}

