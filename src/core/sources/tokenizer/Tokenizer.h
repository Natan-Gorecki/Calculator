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
    bool tryTokenizeString();
    bool tryTokenizeNumber();
    bool tryTokenizeCharacter();

    std::string mExpression;
    std::vector<Token> mTokens;

    Token mToken = {};
    int mPosition = 0;
};
