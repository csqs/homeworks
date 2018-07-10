#ifndef CONTEXT_H
#define CONTEXT_H


#include <map>
#include <iostream>

class Context{
    public:
        Context();
        ~Context();

        void addValue(char var, int number);
        int lookupValue(char var);

        std::map<char, int> var_map;
};

#endif
