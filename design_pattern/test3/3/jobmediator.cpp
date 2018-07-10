#include <iostream>

#include "jobmediator.h"


JobMediator::JobMediator(){
}

JobMediator::~JobMediator(){
}

void JobMediator::addObserver(CollegeStu stu_in){
    int find = 0;
    std::string stu_name_in = stu_in.stu_name;
    for(int i = 0; i < stu_list.size(); i++){
        if(stu_list[i].stu_name == stu_name_in){
            find = 1;
            break;
        }
    }
    if(find == 0)
        stu_list.push_back(stu_in);
}

void JobMediator::addRegister(Company company_in){
    for(int i = 0; i < company_list.size(); i++){
        if(company_list[i].company_name == company_in.company_name){
            company_list.erase(company_list.begin() + i);
            break;
        }
    }
    company_list.push_back(company_in);
    
    for(int i = 0; i < stu_list.size(); i++){
        if(stu_list[i].salary_accept <= company_in.salary_give){
            std::cout << "Hello, " <<stu_list[i].stu_name << ". There is a company you may be interested." << std::endl << "Company: " << company_in.company_name << "Salary: " << company_in.salary_give << std::endl;
            std::cout << "Hello, " <<company_in.company_name << ". There is a student you may be interested." << std::endl << "Student: " << stu_list[i].stu_name << "Salary: " << stu_list[i].salary_accept << std::endl;
            //stu_list[i].notify(company_in);
            //company_in.receive(stu_list[i]);
            
        }
    }

}