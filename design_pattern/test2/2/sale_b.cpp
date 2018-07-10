#include <math.h>
#include <stdlib.h>

#include "sale_b.h"

Sale_b::Sale_b(){
    leaderSalary = 3000;
    bonus = rand() % 2 * 4000;
}

Sale_b::~Sale_b(){
}

uint32_t Sale_b::salarySum(){
    uint32_t all_sum = leaderSalary + bonus;
    return all_sum;
    
}
