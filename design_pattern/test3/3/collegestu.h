#ifndef COLLEGESTU_H
#define COLLEGESTU_H

#include <string>
#include "company.h"

class CollegeStu{
    public:
        CollegeStu(std::string stu_name_input, int salary_accept_input);
        ~CollegeStu();

        //void notify(Company company_input);
    
        std::string stu_name;
        int salary_accept;
    
};


#endif
