#include <iostream>

#include "price.h"
#include "discount.h"
#include "tax.h"



Price::Price(char input_type, int input_price){
    type = input_type;
    price = input_price;
}

Price::~Price(){
}

void Price::priceSum(){
    int result = 0;
    
    Discount discount_one(price);
    Tax tax_one(type, price);
    
    result = discount_one.priceNew() + tax_one.taxNew() - price;
    std::cout << "The price you need: " << std::endl << result << std::endl;
    
}
