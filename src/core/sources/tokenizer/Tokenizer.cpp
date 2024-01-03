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

    Token token = {};
    int position = 0;

    while (position < mExpression.length())
    {
        if (mExpression[position] == ' ')
        {
            position++;
            continue;
        }

        if (tryTokenizeString(token, position))
        {
            mTokens.push_back(token);
            token = {};
            continue;
        }

        if (tryTokenizeNumber(token, position))
        {
            mTokens.push_back(token);
            token = {};
            continue;
        }

        if (tryTokenizeCharacter(token, position))
        {
            mTokens.push_back(token);
            token = {};
            continue;
        }

        throw TokenizerException("Failed to tokenize expression.", position, mExpression.c_str());
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

bool Tokenizer::tryTokenizeString(Token& token, int& pos) const
{
    if (!isalpha(mExpression[pos]))
    {
        return false;
    }

    while (pos < mExpression.length() && (isalpha(mExpression[pos]) || isdigit(mExpression[pos])))
    {
        token.stringValue += mExpression[pos];
        pos++;
    }

    token.tokenType = ETokenType::STRING;
    return true;
}

bool Tokenizer::tryTokenizeNumber(Token& token, int& pos) const
{
    if (!isdigit(mExpression[pos]))
    {
        return false;
    }

    int separatorCount = 0;

    while (pos < mExpression.length() && (isdigit(mExpression[pos]) || mExpression[pos] == ',' || mExpression[pos] == '.'))
    {
        if (mExpression[pos] == ',' || mExpression[pos] == '.')
        {
            if (++separatorCount > 1)
            {
                throw TokenizerException("Duplicated separators.", pos, mExpression.c_str());
            }

            if (mExpression[pos] == mExpression.length() - 1 || !isdigit(mExpression[pos + 1]))
            {
                throw TokenizerException("Missing decimal part.", pos, mExpression.c_str());
            }
        }

        token.stringValue += mExpression[pos];
        pos++;
    }

    string withoutComma = token.stringValue;
    replace(withoutComma.begin(), withoutComma.end(), ',', '.');
    token.numberValue = stod(withoutComma);
    token.tokenType = ETokenType::NUMBER;
    return true;
}

bool Tokenizer::tryTokenizeCharacter(Token& token, int& pos) const
{
    static const array<char, 6> validChars = { '+', '-', '*', '/', '(', ')' };

    if (find(validChars.begin(), validChars.end(), mExpression[pos]) == validChars.end())
    {
        return false;
    }

    token.tokenType = ETokenType::CHAR;
    token.stringValue += mExpression[pos];
    token.characterValue = mExpression[pos];
    pos++;
    return true;
}
