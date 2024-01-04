#include <algorithm>
#include <array>
#include <stdexcept>
#include "Tokenizer.h"
#include "TokenizerException.h"

using namespace std;

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

        throw TokenizerException("Failed to tokenize expression.", mPosition, mExpression.c_str());
    }
}

int Tokenizer::getTokenCount() const
{
    return (int)mTokens.size();
}

Token Tokenizer::getTokenAt(int position)
{
    return mTokens.at(position);
}

bool Tokenizer::tryTokenizeNumber()
{
    if (!isdigit(mExpression[mPosition]))
    {
        return false;
    }

    int separatorCount = 0;
    string tokenString = "";

    while (mPosition < mExpression.length() && (isdigit(mExpression[mPosition]) || mExpression[mPosition] == ',' || mExpression[mPosition] == '.'))
    {
        if (mExpression[mPosition] == ',' || mExpression[mPosition] == '.')
        {
            if (++separatorCount > 1)
            {
                throw TokenizerException("Duplicated separators.", mPosition, mExpression.c_str());
            }

            if (mExpression[mPosition] == mExpression.length() - 1 || !isdigit(mExpression[mPosition + 1]))
            {
                throw TokenizerException("Missing decimal part.", mPosition, mExpression.c_str());
            }
        }

        tokenString += mExpression[mPosition];
        mPosition++;
    }

    replace(tokenString.begin(), tokenString.end(), ',', '.');
    mTokens.push_back({ ETokenType::NUMBER, stod(tokenString) });
    return true;
}

bool Tokenizer::tryTokenizeSeparator()
{
    if (mExpression[mPosition] == '(' || mExpression[mPosition] == ')')
    {
        mTokens.push_back({ ETokenType::SEPARATOR, 0, mExpression[mPosition] });
        mPosition++;
        return true;
    }

    return false;
}

bool Tokenizer::tryTokenizeOperator()
{
    Token token = {};
    bool operatorFound = false;

    if (mExpression[mPosition] == '+')
    {
        token.operatorType = EOperatorType::ADDITION;
        token.operatorPriority = 2;
        operatorFound = true;
    }
    else if (mExpression[mPosition] == '-')
    {
        token.operatorType = EOperatorType::SUBSTRACTION;
        token.operatorPriority = 2;
        operatorFound = true;
    }
    else if (mExpression[mPosition] == '*')
    {
        token.operatorType = EOperatorType::MULTIPLICATION;
        token.operatorPriority = 3;
        operatorFound = true;
    }
    else if (mExpression[mPosition] == '/')
    {
        token.operatorType = EOperatorType::DIVISION;
        token.operatorPriority = 3;
        operatorFound = true;
    }
    else if (mExpression[mPosition] == '^')
    {
        token.operatorType = EOperatorType::POWER;
        token.operatorPriority = 4;
        operatorFound = true;
    }

    if (operatorFound)
    {
        mTokens.push_back(token);
        mPosition++;
    }

    return operatorFound;
}
