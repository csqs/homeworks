#include <math.h>
#include <stdlib.h>

#include "sale_a.h"

Sale_a::Sale_a(){
    leaderSalary = 3500;
    bonus = rand() % 2 * 4000;
}

Sale_a::~Sale_a(){
}

uint32_t Sale_a::salarySum(){
    uint32_t all_sum = leaderSalary + bonus;
    return all_sum;
    
}
