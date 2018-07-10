#include "expression.h"


Expression::Expression() {
}

Expression::~Expression() {
}

int Expression::interpret(Context input) {
    return 0;
}

Variable::Variable(char input_var){
    var = input_var;
}

Variable::Variable(){
}

int Variable::interpret(Context input) {
    return input.lookupValue(var);
}

Variable::~Variable() {
}

Add::Add(Variable left_input, Variable right_input){
    left = left_input;
    right = right_input;
}

Add::Add() {
}

Add::~Add() {
}

int Add::interpret(Context input){
    return left.interpret(input) + right.interpret(input);
}

Sub::Sub(Variable left_input, Div right_input){
    left = left_input;
    right = right_input;
}

Sub::Sub() {
}

Sub::~Sub() {
}

int Sub::interpret(Context input){
    return left.interpret(input) - right.interpret(input);
}

Mul::Mul(Add left_input, Sub right_input){
    left = left_input;
    right = right_input;
}

Mul::Mul(){
}

Mul::~Mul() {
}

int Mul::interpret(Context input){
    return left.interpret(input) * right.interpret(input);
}

Div::Div(Variable left_input, Variable right_input){
    left = left_input;
    right = right_input;
}

Div::Div() {
}


Div::~Div() {
}

int Div::interpret(Context input){
    return left.interpret(input) / right.interpret(input);
}

Del::Del(Mul left_input, Variable right_input){
    left = left_input;
    right = right_input;
}

Del::~Del() {
}

int Del::interpret(Context input){
    return left.interpret(input) % right.interpret(input);
}
