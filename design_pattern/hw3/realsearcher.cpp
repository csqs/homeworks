#include "realsearcher.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

RealSearcher::RealSearcher() {
}

RealSearcher::~RealSearcher() {
}

int RealSearcher::doSearch(std::string keyValue){
    std::ifstream db;
    db.open("/Users/macx/Desktop/DbSearch/DbSearch/database.txt", std::ios::in);
    if(!db.is_open()){
        db.close();
        std::cout <<"open fail"<< std::endl;
        return 0;
    }
    else{
        std::string buffer;
        int keyPos = -1;
        
        getline(db, buffer);
        //std::cout << keyValue << std::endl;
        //std::cout << buffer << std::endl;
        keyPos = buffer.find(keyValue, 0);
        if(keyPos < buffer.size()){
            int item_num = 0;
            while(getline(db, buffer)){
                item_num ++;
            }
            return item_num;
        }
        else return 0;
        
    }
    
}

