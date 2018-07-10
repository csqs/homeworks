#include <iostream>

#include "salary.h"

#include "tech.h"
#include "sale.h"
//#include "product.h"


Salary::Salary(){
    leaderSalary = 50000;
}

Salary::~Salary(){
}

int Salary::salarySum(){
    Tech tech_one;
    Sale sale_one;
    //Product product;
    
    //uint32_t all_sum = leaderSalary + tech_one.salarySum() + sale_one.salarySum() + product_one.salarySum();
    int all_sum = leaderSalary + tech_one.salarySum() + sale_one.salarySum();
    std::cout << "Salary Sum: " << std::endl;
    return all_sum;
    
}
