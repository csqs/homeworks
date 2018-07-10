#include <iostream>
#include <math.h>
#include <stdlib.h>

#include "sale.h"

#include "sale_a.h"
#include "sale_b.h"
#include "new.h"

Sale::Sale(){
    leaderSalary = 5000;
    bonus = rand() % 2 * 50000;
}

Sale::~Sale(){
}

int Sale::salarySum(){
    Sale_a sale_a_one;
    Sale_b sale_b_one;
    char sale_a = '0', sale_b = '0';
    uint32_t a_number = 0, b_number = 0;
    
    std::cout << "Please input the new saleman(TYPE A) number :" << std::endl;
    std::cin >> sale_a;
    std::cout << "Please input the new saleman(TYPE B) number :" << std::endl;
    std::cin >> sale_b;
    a_number = sale_a - '0';
    b_number = sale_b - '0';
    
    New new_one(a_number, b_number);
    uint32_t all_sum = leaderSalary + bonus+ sale_a_one.salarySum() + sale_b_one.salarySum() + new_one.salarySum();
    return all_sum;
    
}
