#include <iostream>

#include "collegestu.h"


CollegeStu::CollegeStu(std::string stu_name_input, int salary_accept_input){
    stu_name = stu_name_input;
    salary_accept = salary_accept_input;
}

CollegeStu::~CollegeStu(){
}

//void CollegeStu::notify(Company company_input){
//    std::cout << "There is a company you may be interested. " << std::endl;
//    std::cout << "Company name : "<< company_input.company_name << std::endl;
//    std::cout << "Salary give : "<< company_input.salary_give << std::endl;
//    
//}
