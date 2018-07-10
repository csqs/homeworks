#include <iostream>
#include <algorithm>
#include <time.h>

#include "client.h"

using namespace std;

int main (int argc, char ** argv) {
    
    std::cout << "Welcome to house-seller. " << endl;
    
    char input = '1';
    while(input != '0'){
        if(input != '0'){
            std::cout << "You can type in a number to choose the house's size. " << endl;
            std::cout << "1 - 40" << endl;
            std::cout << "2 - 80" << endl;
            std::cout << "3 - 100" << endl;
            std::cin >> input;
            int size_temp = input - '0';
            
            std::cout << "You can type in a number to choose the level of the house's decoration. " << endl;
            std::cout << "1 - high" << endl;
            std::cout << "2 - middle" << endl;
            std::cout << "3 - low" << endl;
            std::cin >> input;
            int decr_temp = input - '0';
            
            int style_temp = 0;
            if(decr_temp == 1){
				std::cout << "You can type in a number to choose the style of the house's decoration. " << endl;
            	std::cout << "1 - European" << endl;
            	std::cout << "2 - American" << endl;
            	std::cout << "3 - Japan" << endl;
            	std::cout << "4 - China" << endl;
            	
            	std::cin >> input;
            	style_temp = input - '0';
			}
			Client one_client(size_temp, decr_temp, style_temp);
            std::cout << "The house price: "<< one_client.getPrice() << endl;
           	std::cout << "Type in '0' to quit, '1' to go on." << endl;
           	std::cin >> input;
        }
    }
    std::cout << "System ends." << endl;
    
    
    return 0;
}


