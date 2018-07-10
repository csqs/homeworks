#ifndef CHANGE_H
#define CHANGE_H

#include <string>
#include <vector>

class Change{
    public:
        Change(std::vector<std::string> input_vector);
        ~Change();
    
        void dbChange();
    
        std::vector<std::string> information;
    
};

#endif
