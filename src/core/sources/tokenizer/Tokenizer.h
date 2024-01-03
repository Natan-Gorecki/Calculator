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
    bool tryTokenizeString(Token& token, int& pos) const;
    bool tryTokenizeNumber(Token& token, int& pos) const;
    bool tryTokenizeCharacter(Token& token, int& pos) const;

    std::string mExpression;
    std::vector<Token> mTokens;
};
