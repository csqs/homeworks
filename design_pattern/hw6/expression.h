#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <math.h>

#include "context.h"

class Expression{
    public:
        Expression();
        ~Expression();
    
        virtual int interpret(Context input);
};

class Variable : public Expression{
    public:
        Variable(char input_var);
        Variable();
        ~Variable();
    
        int interpret(Context input);
    
        char var;
};

class Add : public Expression{
    public:
        Add(Variable left_input, Variable right_input);
        Add();
        ~Add();
    
        int interpret(Context input);
        
        Variable left;
        Variable right;
};

class Div : public Expression{
public:
    Div(Variable left_input, Variable right_input);
    Div();
    ~Div();
    
    int interpret(Context input);
    
    Variable left;
    Variable right;
};


class Sub : public Expression{
    public:
        Sub(Variable left_input, Div right_input);
        Sub();
        ~Sub();
    
        int interpret(Context input);
        
        Variable left;
        Div right;
};

class Mul : public Expression{
    public:
        Mul(Add left_input, Sub right_input);
        Mul();
        ~Mul();
    
        int interpret(Context input);
        
        Add left;
        Sub right;
};

class Del : public Expression{
    public:
        Del(Mul left_input, Variable right_input);
        ~Del();
        
        int interpret(Context input);
        
        Mul left;
        Variable right;
};


#endif
