#pragma once
#include <vector>
#include "Token.h"

class Tokenizer
{
public:
    Tokenizer(const char* expression);

    int getTokenCount();
    Token getTokenAt(int position);

private:
    void tokenize(const char* expression);
    bool tryTokenizeString(const std::string& exp, Token& token, int& pos);
    bool tryTokenizeNumber(const std::string& exp, Token& token, int& pos);
    bool tryTokenizeCharacter(const std::string& exp, Token& token, int& pos);

    const char* mExpression;
    std::vector<Token> mTokens;
};
