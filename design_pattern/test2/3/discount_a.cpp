#include <iostream>

#include "discount_a.h"


Discount_a::Discount_a(int input_price){
    price = input_price;
}

Discount_a::~Discount_a(){
}

int Discount_a::priceNew(){
    return price * 0.95;
}
