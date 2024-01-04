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

        if (tryTokenizeNumber() ||
            tryTokenizeSeparator() ||
            tryTokenizeOperator())
        {
            handleHiddenMultiplication();
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
    int separatorCount = 0;
    string tokenString = "";

    if (shouldHandleSignForNumber())
    {
        tokenString += mExpression[mPosition];
        mPosition++;
    }

    if (!isNumberOrSeparator(mExpression[mPosition]))
    {
        return false;
    }

    while (mPosition < mExpression.length() && isNumberOrSeparator(mExpression[mPosition]))
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

    string withoutComma = tokenString;
    replace(withoutComma.begin(), withoutComma.end(), ',', '.');

    Token token = { ETokenType::NUMBER };
    token.stringValue = tokenString;
    token.numberValue = stod(withoutComma);

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

    mTokens.push_back(token);
    mPosition++;
    return true;
}

void Tokenizer::handleHiddenMultiplication()
{
    if (mTokens.size() < 2)
    {
        return;
    }

    Token left = mTokens[mTokens.size() - 2];
    Token right = mTokens[mTokens.size() - 1];

    if ((left.charValue == ')' && right.type == ETokenType::NUMBER) ||
        (left.type == ETokenType::NUMBER && right.charValue == '(') ||
        (left.charValue == ')' && right.charValue == '('))
    {
        Token op = { ETokenType::OPERATOR };
        op.stringValue += '*';
        op.charValue = '*';

        mTokens.pop_back();
        mTokens.push_back(op);
        mTokens.push_back(right);
    }
}

bool Tokenizer::isNumberOrSeparator(char c) const
{
    return isdigit(c) || c == ',' || c == '.';
}

bool Tokenizer::shouldHandleSignForNumber() const
{
    if (mExpression[mPosition] != '+' && mExpression[mPosition] != '-')
    {
        return false;
    }

    if (mPosition == mExpression.length() - 1 || !isdigit(mExpression[mPosition + 1]))
    {
        return false;
    }

    if (mTokens.empty())
    {
        return true;
    }

    const auto& previousToken = mTokens.back();

    if (previousToken.charValue == '(')
    {
        return true;
    }

    return false;
}
