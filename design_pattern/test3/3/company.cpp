#include <iostream>

#include "company.h"


Company::Company(std::string company_name_input, int salary_give_input){
    company_name = company_name_input;
    salary_give = salary_give_input;
}

Company::~Company(){
}

void receive(CollegeStu collegestu_input){
    std::cout << "There is a student you may be interested. " << std::endl;
    std::cout << "Student name : "<< collegestu_input.stu_name << std::endl;
    std::cout << "Salary hope : "<< collegestu_input.salary_accept << std::endl;
}
