#include <iostream>

#include "tax_b.h"


Tax_b::Tax_b(float input_tax_rate, int input_price){
    tax_rate = input_tax_rate;
    price = input_price;
}

Tax_b::~Tax_b(){
}

int Tax_b::taxMethod(){
    return price * (1 + tax_rate);
}
