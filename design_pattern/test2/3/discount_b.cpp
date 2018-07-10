#include <iostream>

#include "discount_b.h"


Discount_b::Discount_b(int input_price){
    price = input_price;
}

Discount_b::~Discount_b(){
}

int Discount_b::priceNew(){
    return price * 0.92;
}
