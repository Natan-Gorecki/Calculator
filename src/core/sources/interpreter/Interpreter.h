#pragma once
#include "../tokenizer/Tokenizer.h"

class Interpreter
{
public:
    virtual ~Interpreter() = default;
    virtual double interpret(Tokenizer* tokenizer) = 0;

protected:
    double calculate(double left, double right, char op) const;
    int getPrecedence(const Token& op) const;
    bool isLeftAssociative(const Token& op) const;
};