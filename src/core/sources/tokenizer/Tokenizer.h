#pragma once
#include <vector>
#include "Token.h"

class Tokenizer
{
public:
    void tokenize(const char* expression);
    int getTokenCount() const;
    Token getTokenAt(int position);

private:
    bool tryTokenizeNumber();
    bool tryTokenizeSeparator();
    bool tryTokenizeOperator();

    std::string mExpression;
    std::vector<Token> mTokens;
    int mPosition = 0;
};
