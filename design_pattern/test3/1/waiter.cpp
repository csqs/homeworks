#include <iostream>

#include "waiter.h"
#include "builder.h"


Waiter::Waiter(){
}

Waiter::~Waiter(){
}

void Waiter::construct(){
    std::cout << "You have 3 meals to choose. Type in your choice."<< std::endl;
    std::cout << "a: 1 ham, 1 milk."<<  std::endl;
    std::cout << "b: 1 chickenwings, 1 coffee."<< std::endl;
    std::cout << "c: 1 chickenlegs, 1 water."<< std::endl;
    
    char input = 'a';
    std::cin >> input;
    
    if(input >= 'a' && input <= 'c'){
        Builder mealBuilder;
        mealBuilder.getMeal(input);
    }
    else
        std::cout << "Wrong input, system quit."<< std::endl;
}
