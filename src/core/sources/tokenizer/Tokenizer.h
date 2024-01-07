#pragma once
#include <vector>
#include "Token.h"

class Tokenizer
{
public:
    void tokenize(const char* expression);
    int getTokenCount() const;
    Token getTokenAt(int index);
    void insertAt(int index, const Token& token);
    void removeAt(int index);

private:
    bool tryTokenizeNumber();
    bool tryTokenizeSeparator();
    bool tryTokenizeOperator();
    bool isDigitOrSeparator(char c) const;

    std::string mExpression;
    std::vector<Token> mTokens;
    int mPosition = 0;
};
