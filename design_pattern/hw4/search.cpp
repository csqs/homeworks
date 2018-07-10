#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

#include "search.h"

Search::Search(std::string input_id) {
    student_id = input_id;
}

Search::~Search() {
}

void Search::dbSearch(){
    std::ifstream db;
    db.open("/Users/macx/Desktop/database/database.txt", std::ios::out | std::ios::in);
    if(!db.is_open()){
        db.close();
        std::cout <<"open fail"<< std::endl;
    }
    else{
        std::string buffer;
        while(getline(db, buffer)){
            if(buffer.find(student_id) != std::string::npos){
                std::cout << buffer << std::endl;
                break;
            }
        }
        
        db.close();
    }
    
}

