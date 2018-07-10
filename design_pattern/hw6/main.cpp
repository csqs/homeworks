#include <iostream>
#include <algorithm>
#include <time.h>

#include "context.h"
#include "expression.h"

using namespace std;


int main (int argc, char ** argv) {
    
    Context context_temp;
    int number;
    
    std::cout << "The expression is (a + b) * (c - d / e) % a. " << std::endl;
    
    std::cout << "Please input a's number: " << endl;
    std::cin >> number;
    context_temp.addValue('a', number);
    
    std::cout << "Please input b's number: " << endl;
    std::cin >> number;
    context_temp.addValue('b', number);
    
    std::cout << "Please input c's number: " << endl;
    std::cin >> number;
    context_temp.addValue('c', number);
    
    std::cout << "Please input d's number: " << endl;
    std::cin >> number;
    context_temp.addValue('d', number);
    
    std::cout << "Please input e's number: " << endl;
    std::cin >> number;
    context_temp.addValue('e', number);
    
    Variable v_a('a');
    Variable v_b('b');
    Variable v_c('c');
    Variable v_d('d');
    Variable v_e('e');
    
    Add add_temp(v_a, v_b);
    Div div_temp(v_d, v_e);
    Sub sub_temp(v_c, div_temp);
    Mul mul_temp(add_temp, sub_temp);
    Del del_temp(mul_temp, v_a);
    
    std::cout << "The resule is: " << del_temp.interpret(context_temp) << endl;
    
    return 0;
}

