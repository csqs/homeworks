#ifndef DELETE_H
#define DELETE_H

#include <string>
#include <vector>

class Delete{
    public:
        Delete(std::string input_id);
        ~Delete();
    
        void dbDelete();
    
        std::string student_id;
    
};

#endif
