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
    
    void throwForDuplicatedOperators();
    void throwForMisplacedOperators();
    void throwForEmptyExpression();
    void throwForNotClosedBrackets();

    Tokenizer* mTokenizer = nullptr;
};
