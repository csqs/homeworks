#include <math.h>
#include <stdlib.h>

#include "new.h"
#include "sale_a.h"
#include "sale_b.h"

New::New(uint32_t a_number, uint32_t b_number){
    sale_a = a_number;
    sale_b = b_number;
}

New::~New(){
}

uint32_t New::salarySum(){
    uint32_t all_sum = 0;
    
    for(int i = 0; i < sale_a; i++){
        Sale_a one;
        all_sum += one.salarySum();
    }
    
    for(int i = 0; i < sale_b; i++){
        Sale_b one;
        all_sum += one.salarySum();
    }
    
    return all_sum;
    
}
