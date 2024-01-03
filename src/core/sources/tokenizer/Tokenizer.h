#pragma once
#include <vector>
#include "Token.h"

class Tokenizer
{
public:
    explicit Tokenizer(const char* expression);

    int getTokenCount() const;
    Token getTokenAt(int position);

private:
    void tokenize(const char* expression);
    bool tryTokenizeString(const std::string& exp, Token& token, int& pos) const;
    bool tryTokenizeNumber(const std::string& exp, Token& token, int& pos) const;
    bool tryTokenizeCharacter(const std::string& exp, Token& token, int& pos) const;

    const char* mExpression;
    std::vector<Token> mTokens;
};
