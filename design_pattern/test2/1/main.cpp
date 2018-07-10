#include <iostream>
#include <algorithm>
#include <time.h>

#include "client.h"

using namespace std;

int main (int argc, char ** argv) {
    
    std::cout << "Welcome to class-register. " << endl;
    
    char input = '1';
    while(input != '0'){
        if(input != '0'){
            char userID;
            std::cout << "Type in the user ID: " << endl;
            std::cin >> userID;
            
            int client_id = userID - '0';
            
            Client client_one(client_id);
            client_one.begin();
            
           	std::cout << "Type in '0' to quit, '1' to go on." << endl;
           	std::cin >> input;
        }
    }
    std::cout << "System ends." << endl;
    
    return 0;
}


