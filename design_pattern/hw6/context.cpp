#include "context.h"

Context::Context() {
}

Context::~Context() {
}

void Context::addValue(char var, int number){
    var_map.insert(std::map<char, int>::value_type(var, number));
}

int Context::lookupValue(char var){
    return var_map[var];
}

