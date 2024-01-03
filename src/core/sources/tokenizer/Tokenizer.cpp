#include "Tokenizer.h"
#include <algorithm>
#include <array>
#include <stdexcept>

using namespace std;

Tokenizer::Tokenizer(const char* expression)
{
    mExpression = expression;
    tokenize(expression);
}

int Tokenizer::getTokenCount()
{
    return mTokens.size();
}

Token Tokenizer::getTokenAt(int position)
{
    return mTokens.at(position);
}

void Tokenizer::tokenize(const char* expression)
{
    string expressionString = expression;
    Token token = {};
    int position = 0;

    while (position < expressionString.length())
    {
        if (expressionString[position] == ' ')
        {
            position++;
            continue;
        }

        if (tryTokenizeString(expressionString, token, position))
        {
            mTokens.push_back(token);
            token = {};
            continue;
        }

        if (tryTokenizeNumber(expressionString, token, position))
        {
            mTokens.push_back(token);
            token = {};
            continue;
        }

        if (tryTokenizeCharacter(expressionString, token, position))
        {
            mTokens.push_back(token);
            token = {};
            continue;
        }

        throw runtime_error("Failed to tokenize expression!");
    }
}

bool Tokenizer::tryTokenizeString(const std::string& exp, Token& token, int& pos)
{
    if (!isalpha(exp[pos]))
    {
        return false;
    }

    while (pos < exp.length() && (isalpha(exp[pos]) || isdigit(exp[pos])))
    {
        token.stringValue += exp[pos];
        pos++;
    }

    token.tokenType = ETokenType::STRING;
    return true;
}

bool Tokenizer::tryTokenizeNumber(const std::string& exp, Token& token, int& pos)
{
    if (!isdigit(exp[pos]))
    {
        return false;
    }

    int separatorCount = 0;

    while (pos < exp.length() && (isdigit(exp[pos]) || exp[pos] == ',' || exp[pos] == '.'))
    {
        if (exp[pos] == ',' || exp[pos] == '.')
        {
            if (++separatorCount > 1)
            {
                throw runtime_error("To many separators!");
            }

            if (exp[pos] == exp.length() - 1 || !isdigit(exp[pos + 1]))
            {
                throw runtime_error("Missing decimal part!");
            }
        }

        token.stringValue += exp[pos];
        pos++;
    }

    string withoutComma = token.stringValue;
    replace(withoutComma.begin(), withoutComma.end(), ',', '.');
    token.numberValue = stod(withoutComma);
    token.tokenType = ETokenType::NUMBER;
    return true;
}

bool Tokenizer::tryTokenizeCharacter(const std::string& exp, Token& token, int& pos)
{
    static const array<char, 6> validChars = { '+', '-', '*', '/', '(', ')' };

    char c = exp[pos];
    if (find(validChars.begin(), validChars.end(), c) == validChars.end())
    {
        return false;
    }

    token.tokenType = ETokenType::CHAR;
    token.stringValue += c;
    token.characterValue = c;
    pos++;
    return true;
}
