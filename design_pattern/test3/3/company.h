#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include "collegestu.h"

class Company{
    public:
        Company(std::string company_name_input, int salary_give_input);
        ~Company();

        //void receive(CollegeStu collegestu_input);
    
        std::string company_name;
        int salary_give;
};


#endif
