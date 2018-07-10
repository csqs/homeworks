#include <iostream>

#include "jobmediator.h"
#include "company.h"
#include "collegestu.h"

using namespace std;

int main (int argc, char ** argv) {
    
    JobMediator jobCenter;
    
    CollegeStu stu1("Lily", 1500);
    jobCenter.addObserver(stu1);
    
    CollegeStu stu2("Tom", 2000);
    jobCenter.addObserver(stu2);
    
    Company com1("Apple", 1500);
    jobCenter.addRegister(com1);
    
    Company com2("Pineapple", 3000);
    jobCenter.addRegister(com2);
    
    return 0;
}


