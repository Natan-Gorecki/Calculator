#pragma once
#include <vector>
#include "../tokenizer/Tokenizer.h"

class ShuntingYardInterpreter
{
public:
    double interpret(Tokenizer* tokenizer);

private:
    double calculate();
    double calculate(double left, double right, char op) const;
    void handleOperator(const Token& op1);
    void handleRightParenthesis();
    int getPrecedence(const Token& op) const;
    bool isLeftAssociative(const Token& op) const;

    std::vector<double> mNumberStack;
    std::vector<Token> mOutputStack;
    std::vector<Token> mOperatorStack;
};