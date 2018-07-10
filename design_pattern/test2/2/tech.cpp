#include "tech.h"

#include "tech_a.h"
#include "tech_b.h"

Tech::Tech(){
    leaderSalary = 25000;
}

Tech::~Tech(){
}

int Tech::salarySum(){
    Tech_a tech_a_one;
    Tech_b tech_b_one;
    
    int all_sum = leaderSalary + tech_b_one.salarySum() + tech_a_one.salarySum();
    return all_sum;
    
}
