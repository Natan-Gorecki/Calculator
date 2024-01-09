#pragma once
#include "../tokenizer/Tokenizer.h"

class SyntaxAnalyzer
{
public:
    void analyze(Tokenizer* tokenizer);

private:
    void handleSignOfNumber();
    void handleHiddenMultiplication();
    void handleEmptyBrackets();
    
    void throwForDuplicatedOperators() const;
    void throwForMisplacedOperators() const;
    void throwForEmptyExpression() const;
    void throwForNotClosedBrackets() const;

    Tokenizer* mTokenizer = nullptr;
};
