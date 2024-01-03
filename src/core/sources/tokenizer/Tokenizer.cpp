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
    mToken = {};
    mPosition = 0;

    while (mPosition < mExpression.length())
    {
        if (mExpression[mPosition] == ' ')
        {
            mPosition++;
            continue;
        }

        if (tryTokenizeString())
        {
            mTokens.push_back(mToken);
            mToken = {};
            continue;
        }

        if (tryTokenizeNumber())
        {
            mTokens.push_back(mToken);
            mToken = {};
            continue;
        }

        if (tryTokenizeCharacter())
        {
            mTokens.push_back(mToken);
            mToken = {};
            continue;
        }

        throw TokenizerException("Failed to tokenize expression.", mPosition, mExpression.c_str());
    }

    mToken = {};
    mPosition = 0;
}

int Tokenizer::getTokenCount() const
{
    return (int)mTokens.size();
}

Token Tokenizer::getTokenAt(int position)
{
    return mTokens.at(position);
}

bool Tokenizer::tryTokenizeString()
{
    if (!isalpha(mExpression[mPosition]))
    {
        return false;
    }

    while (mPosition < mExpression.length() && (isalpha(mExpression[mPosition]) || isdigit(mExpression[mPosition])))
    {
        mToken.stringValue += mExpression[mPosition];
        mPosition++;
    }

    mToken.tokenType = ETokenType::STRING;
    return true;
}

bool Tokenizer::tryTokenizeNumber()
{
    if (!isdigit(mExpression[mPosition]))
    {
        return false;
    }

    int separatorCount = 0;

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

        mToken.stringValue += mExpression[mPosition];
        mPosition++;
    }

    string withoutComma = mToken.stringValue;
    replace(withoutComma.begin(), withoutComma.end(), ',', '.');
    mToken.numberValue = stod(withoutComma);
    mToken.tokenType = ETokenType::NUMBER;
    return true;
}

bool Tokenizer::tryTokenizeCharacter()
{
    static const array<char, 6> validChars = { '+', '-', '*', '/', '(', ')' };

    if (find(validChars.begin(), validChars.end(), mExpression[mPosition]) == validChars.end())
    {
        return false;
    }

    mToken.tokenType = ETokenType::CHAR;
    mToken.stringValue += mExpression[mPosition];
    mToken.characterValue = mExpression[mPosition];
    mPosition++;
    return true;
}
