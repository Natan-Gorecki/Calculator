#pragma once
#include <memory>
#include "../tokenizer/Tokenizer.h"

class RecursiveInterpreter
{
public:
    double interpret(Tokenizer* tokenizer);

private:
    double interpretImpl(int start, int end);
    bool findLeastPrecedenceOperator(int start, int end, int& position);
    bool isWrapperWithBrackets(int start, int end);

    double calculate(double left, double right, char op) const;
    int getPrecedence(const Token& op) const;
    bool isLeftAssociative(const Token& op) const;

    Tokenizer* mTokenizer = nullptr;
};
