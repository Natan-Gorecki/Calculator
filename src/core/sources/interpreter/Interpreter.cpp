#include "Interpreter.h"

double Interpreter::calculate(double left, double right, char op) const
{
    switch (op)
    {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    case '^':
        return pow(left, right);
    default:
        return 0;
    }
}

int Interpreter::getPrecedence(const Token& op) const
{
    switch (op.charValue)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    default:
        return 0;
    }
}

bool Interpreter::isLeftAssociative(const Token& op) const
{
    return op.type == ETokenType::OPERATOR && op.charValue != '^';
}