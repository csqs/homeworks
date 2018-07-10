#ifndef SEARCH_H
#define SEARCH_H

#include <string>
#include <vector>

class Search{
    public:
        Search(std::string input_id);
        ~Search();
    
        void dbSearch();
    
        std::string student_id;
    
};

#endif
