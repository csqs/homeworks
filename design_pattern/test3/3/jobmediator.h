#ifndef JOBMEDIATOR_H
#define JOBMEDIATOR_H

#include <vector>
#include "collegestu.h"
#include "company.h"

class JobMediator{
    public:
        JobMediator();
        ~JobMediator();

        void addObserver(CollegeStu stu_in);
        void addRegister(Company company_in);
    
        std::vector<CollegeStu> stu_list;
        std::vector<Company> company_list;
};


#endif
