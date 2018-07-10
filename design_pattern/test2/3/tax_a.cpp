#include <iostream>

#include "tax_a.h"


Tax_a::Tax_a(float input_tax_rate, int input_price){
    tax_rate = input_tax_rate;
    price = input_price;
}

Tax_a::~Tax_a(){
}

int Tax_a::taxMethod(){
    return price * (1 + tax_rate);
}
