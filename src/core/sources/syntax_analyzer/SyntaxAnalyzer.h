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

    Token tryGetPreviousToken();
    Token tryGetNextToken();

    Tokenizer* mTokenizer = nullptr;
    int mPosition = 0;
};
