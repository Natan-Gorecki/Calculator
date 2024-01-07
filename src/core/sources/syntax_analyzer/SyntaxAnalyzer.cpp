#include "../ExpressionException.h"
#include "SyntaxAnalyzer.h"

using namespace std;

void SyntaxAnalyzer::analyze(Tokenizer* tokenizer)
{
    mTokenizer = tokenizer;
    mPosition = 0;

    while (mPosition < mTokenizer->getTokenCount())
    {
        handleSignOfNumber();
        handleEmptyBrackets();
        handleHiddenMultiplication();

        throwForDuplicatedOperators();
        throwForMisplacedOperators();

        mPosition++;
    }

    throwForEmptyExpression();
    throwForNotClosedBrackets();
}

void SyntaxAnalyzer::handleSignOfNumber()
{
    if (mPosition == mTokenizer->getTokenCount() - 1)
    {
        return;
    }

    if (!(mPosition == 0 || mTokenizer->getTokenAt(mPosition - 1).charValue == '('))
    {
        return;
    }

    auto token = mTokenizer->getTokenAt(mPosition);
    auto nextToken = mTokenizer->getTokenAt(mPosition + 1);

    if (token.charValue != '+' && token.charValue != '-')
    {
        return;
    }

    if (nextToken.type != ETokenType::NUMBER)
    {
        return;
    }

    mTokenizer->removeAt(mPosition + 1);
    mTokenizer->removeAt(mPosition);
    nextToken.numberValue = token.charValue == '-' ? -nextToken.numberValue : nextToken.numberValue;
    mTokenizer->insertAt(mPosition, nextToken);
}

void SyntaxAnalyzer::handleHiddenMultiplication()
{
    if (mPosition == mTokenizer->getTokenCount() - 1)
    {
        return;
    }

    auto token = mTokenizer->getTokenAt(mPosition);
    auto nextToken = mTokenizer->getTokenAt(mPosition + 1);

    if ((token.charValue == ')' && nextToken.type == ETokenType::NUMBER) ||
        (token.charValue == ')' && nextToken.charValue == '(') ||
        (token.type == ETokenType::NUMBER && nextToken.charValue == '('))
    {
        Token op = { ETokenType::OPERATOR };
        op.stringValue += '*';
        op.charValue = '*';

        mTokenizer->insertAt(mPosition + 1, op);
    }
}

void SyntaxAnalyzer::handleEmptyBrackets()
{
    auto token = mTokenizer->getTokenAt(mPosition);
    if (token.charValue != '(')
    {
        return;
    }

    int position = mPosition + 1;
    int quantity = 1;
    
    while (mTokenizer->getTokenAt(position).charValue == '(')
    {
        quantity++;
        position++;
    }

    while (quantity > 0)
    {
        if (mTokenizer->getTokenAt(position).charValue != ')')
        {
            return;
        }

        quantity--;
        position--;
        mTokenizer->removeAt(position + 1);
        mTokenizer->removeAt(position);
    }

    if (quantity == 0)
    {
        mPosition--;
    }
}

void SyntaxAnalyzer::throwForDuplicatedOperators()
{
    auto prevToken = tryGetPreviousToken();
    const auto& token = mTokenizer->getTokenAt(mPosition);
    auto nextToken = tryGetNextToken();

    if (prevToken.type == ETokenType::OPERATOR && token.type == ETokenType::OPERATOR)
    {
        throw ExpressionException("Duplicated operators.", mPosition - 1, nullptr);
    }
    if (token.type == ETokenType::OPERATOR && nextToken.type == ETokenType::OPERATOR)
    {
        throw ExpressionException("Duplicated operators.", mPosition, nullptr);
    }
}

void SyntaxAnalyzer::throwForMisplacedOperators()
{
    auto prevToken = tryGetPreviousToken();
    const auto& token = mTokenizer->getTokenAt(mPosition);
    auto nextToken = tryGetNextToken();

    if (token.type != ETokenType::OPERATOR)
    {
        return;
    }

    if (prevToken.type == ETokenType::UNDEFINED || prevToken.charValue == '(' ||
        nextToken.type == ETokenType::UNDEFINED || nextToken.charValue == ')')
    {
        throw ExpressionException("Misplaced operator.", mPosition, nullptr);
    }
}

void SyntaxAnalyzer::throwForEmptyExpression()
{
    if (mTokenizer->getTokenCount() == 0)
    {
        throw ExpressionException("Empty expression.", 0, nullptr);
    }
}

void SyntaxAnalyzer::throwForNotClosedBrackets()
{
    vector<int> leftIndexes;

    for (int i = 0; i < mTokenizer->getTokenCount(); i++)
    {
        if (mTokenizer->getTokenAt(i).charValue == '(')
        {
            leftIndexes.push_back(i);
            continue;
        }

        if (mTokenizer->getTokenAt(i).charValue != ')')
        {
            continue;
        }

        if (leftIndexes.empty())
        {
            throw ExpressionException("Brackets mismatch.", i, nullptr);
        }

        leftIndexes.pop_back();
    }

    if (!leftIndexes.empty())
    {
        throw ExpressionException("Brackets mismatch.", leftIndexes.at(0), nullptr);
    }
}

Token SyntaxAnalyzer::tryGetPreviousToken()
{
    if (mPosition > 0)
    {
        return mTokenizer->getTokenAt(mPosition - 1);
    }

    return {};
}

Token SyntaxAnalyzer::tryGetNextToken()
{
    if (mPosition < mTokenizer->getTokenCount() - 1)
    {
        return mTokenizer->getTokenAt(mPosition + 1);
    }

    return {};
}
