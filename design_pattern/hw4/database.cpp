#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>

#include "database.h"
#include "add.h"
#include "delete.h"
#include "change.h"
#include "search.h"


Database::Database(){
}

Database::~Database(){
}

void Database::interface(){
    char process_continue = '1';
    
    while(process_continue == '1'){
        std::cout << "Weclome to the database. Type the number below to get the corresponding function." << std::endl;
        std::cout << "1 -- Add" << std::endl << "2 -- Delete" << std::endl << "3 -- Change" << std::endl << "4 -- Search" << std::endl;
        std::cout << "Enter the number:" << std::endl;
        
        char input_number = '0';
        std::cin >> input_number;
        
        if(input_number == '1'){
            std::string input_string;
            std::vector<std::string> input_information;
            std::cout << "Begin to enter the new information." << std::endl;
            std::cout << "Enter the student ID:" << std::endl;
            std::cin >> input_string;
            input_information.push_back(input_string);
            input_string.clear();
            
            std::cout << "Enter the student name:" << std::endl;
            std::cin >> input_string;
            input_information.push_back(input_string);
            input_string.clear();
            
            std::cout << "Enter the student gender:" << std::endl;
            std::cin >> input_string;
            input_information.push_back(input_string);
            input_string.clear();
            
            Add add_one(input_information);
            add_one.dbAdd();
        }
        else if(input_number == '3'){
            std::string input_string;
            std::vector<std::string> input_information;
            std::cout << "Begin to change the student information." << std::endl;
            std::cout << "Enter the student ID:" << std::endl;
            std::cin >> input_string;
            input_information.push_back(input_string);
            input_string.clear();
            
            std::cout << "Enter the student name:" << std::endl;
            std::cin >> input_string;
            input_information.push_back(input_string);
            input_string.clear();
            
            std::cout << "Enter the student gender:" << std::endl;
            std::cin >> input_string;
            input_information.push_back(input_string);
            input_string.clear();
            
            Change change_one(input_information);
            change_one.dbChange();
        }
        else if(input_number == '4'){
            std::string input_string;
            
            std::cout << "Begin to search the student." << std::endl;
            std::cout << "Enter the student ID:" << std::endl;
            std::cin >> input_string;
            
            Search search_one(input_string);
            search_one.dbSearch();
        }
        else if(input_number == '2'){
            std::string input_string;
            
            std::cout << "Begin to delete the student information." << std::endl;
            std::cout << "Enter the student ID:" << std::endl;
            std::cin >> input_string;
            
            Delete delete_one(input_string);
            delete_one.dbDelete();
        }
        else
            std::cout << "Enter the wrong number." << std::endl;
        
        std::cout << "Continue to enter '1', or '0'." << std::endl;
        std::cin >> process_continue;
    }
}
