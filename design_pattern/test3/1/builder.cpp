#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "builder.h"

Builder::Builder(){
}

Builder::~Builder(){
}

void Builder::getFood(char input){
    if(input == 'a') std::cout << "You get a ham." << std::endl;
    else if(input == 'b') std::cout << "You get a chickenwings." << std::endl;
    else if(input == 'c') std::cout << "You get a chickenlegs." << std::endl;
}

void Builder::getDrink(char input){
    if(input == 'a') std::cout << "You get a milk." << std::endl;
    else if(input == 'b') std::cout << "You get a coffee." << std::endl;
    else if(input == 'c') std::cout << "You get a water." << std::endl;
}

void Builder::getMeal(char input){
    getFood(input);
    getDrink(input);
}
