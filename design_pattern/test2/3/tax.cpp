#include <iostream>

#include "tax.h"
#include "tax_a.h"
#include "tax_b.h"


Tax::Tax(char input_type, int input_price){
    type = input_type;
    price = input_price;
}

Tax::~Tax(){
}

int Tax::taxNew(){
    float tax_rate = 1;
    
    if(type == 'A'){
        std::cout << "Please input the tax rate:" << std::endl;
        std::cin >> tax_rate;
        Tax_a tax_a_one(tax_rate, price);
        return tax_a_one.taxMethod();
    }
    else if(type == 'B'){
        std::cout << "Please input the tax rate:" << std::endl;
        std::cin >> tax_rate;
        Tax_b tax_b_one(tax_rate, price);
        return tax_b_one.taxMethod();
    }
    else
        return price;
}
