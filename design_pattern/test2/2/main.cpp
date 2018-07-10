#include <iostream>
#include <algorithm>

#include "salary.h"

using namespace std;

int main (int argc, char ** argv) {
    
    std::cout << "Welcome to Salary." << std::endl;
    
    char input = '1';
    while(input != '0'){
        if(input != '0'){
            std::cout << "System begin." << std::endl;
            
            Salary one;
            
            std::cout << one.salarySum()<< std::endl;
            
           	std::cout << "Type in '0' to quit, '1' to go on." << std::endl;
           	std::cin >> input;
        }
    }
    std::cout << "System ends." << std::endl;
    
    return 0;
}


