#ifndef ADD_H
#define ADD_H

#include <string>
#include <vector>

class Add{
    public:
        Add(std::vector<std::string> input_vector);
        ~Add();
    
        void dbAdd();
    
        std::vector<std::string> information;
    
};

#endif
