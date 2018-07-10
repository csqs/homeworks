#include <iostream>

#include "discount.h"
#include "discount_a.h"
#include "discount_b.h"


Discount::Discount(int input_price){
    price = input_price;
}

Discount::~Discount(){
}

int Discount::priceNew(){
    if(price > 10){
        Discount_a discount_a_one(price);
        return discount_a_one.priceNew();
    }
    else if(price > 50){
        Discount_b discount_b_one(price);
        return discount_b_one.priceNew();
    }
    else
        return price * 0.9;
}
