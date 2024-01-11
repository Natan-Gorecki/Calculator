#include <algorithm>
#include <array>
#include <stdexcept>
#include "ExpressionException.h"
#include "Tokenizer.h"

using namespace std;
using namespace CalculatorCore;

void Tokenizer::tokenize(const char* expression)
{
    mExpression = expression;
    mTokens.clear();
    mPosition = 0;

    while (mPosition < mExpression.length())
    {
        if (mExpression[mPosition] == ' ')
        {
            mPosition++;
            continue;
        }

        if (tryTokenizeNumber())
        {
            continue;
        }

        if (tryTokenizeSeparator())
        {
            continue;
        }

        if (tryTokenizeOperator())
        {
            continue;
        }

        throw ExpressionException("Failed to tokenize expression.", mPosition, mExpression.c_str());
    }
}

const char* Tokenizer::getExpression() const
{
    return mExpression.c_str();
}

int Tokenizer::getTokenCount() const
{
    return (int)mTokens.size();
}

Token Tokenizer::getTokenAt(int position)
{
    return mTokens.at(position);
}

void Tokenizer::insertAt(int index, const Token& token)
{
    mTokens.insert(mTokens.begin() + index, token);
}

void Tokenizer::removeAt(int index)
{
    mTokens.erase(mTokens.begin() + index);
}

bool Tokenizer::tryTokenizeNumber()
{
    int separatorCount = 0;
    string tokenString = "";

    if (!isDigitOrSeparator(mExpression[mPosition]))
    {
        return false;
    }

    while (mPosition < mExpression.length() && isDigitOrSeparator(mExpression[mPosition]))
    {
        if (mExpression[mPosition] == ',' || mExpression[mPosition] == '.')
        {
            separatorCount++;
            if (separatorCount > 1)
            {
                throw ExpressionException("Duplicated separators.", mPosition, mExpression.c_str());
            }
        }

        tokenString += mExpression[mPosition];
        mPosition++;
    }

    string withoutComma = tokenString;
    replace(withoutComma.begin(), withoutComma.end(), ',', '.');

    if (withoutComma == ".")
    {
        throw ExpressionException("Invalid number syntax", mPosition - 1, mExpression.c_str());
    }

    Token token = { ETokenType::NUMBER };
    token.stringValue = tokenString;
    token.numberValue = stod(withoutComma);
    token.absolutePosition = mPosition - (int)tokenString.length();

    mTokens.push_back(token);
    return true;
}

bool Tokenizer::tryTokenizeSeparator()
{
    if (mExpression[mPosition] != '(' && mExpression[mPosition] != ')')
    {
        return false;
    }

    Token token = { ETokenType::SEPARATOR };
    token.stringValue += mExpression[mPosition];
    token.charValue += mExpression[mPosition];
    token.absolutePosition = mPosition;

    mTokens.push_back(token);
    mPosition++;
    return true;
}

bool Tokenizer::tryTokenizeOperator()
{
    static const array<char, 5> validChars = { '+', '-', '*', '/', '^' };

    if (find(validChars.begin(), validChars.end(), mExpression[mPosition]) == validChars.end())
    {
        return false;
    }

    Token token = { ETokenType::OPERATOR };
    token.stringValue += mExpression[mPosition];
    token.charValue += mExpression[mPosition];
    token.absolutePosition = mPosition;

    mTokens.push_back(token);
    mPosition++;
    return true;
}

bool Tokenizer::isDigitOrSeparator(char c) const
{
    return isdigit(c) || c == ',' || c == '.';
}
