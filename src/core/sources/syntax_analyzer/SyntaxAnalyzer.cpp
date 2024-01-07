#include "../ExpressionException.h"
#include "SyntaxAnalyzer.h"

using namespace std;

void SyntaxAnalyzer::analyze(Tokenizer* tokenizer)
{
    mTokenizer = tokenizer;

    handleSignOfNumber();
    handleEmptyBrackets();
    handleHiddenMultiplication();
    throwForEmptyExpression();
    throwForDuplicatedOperators();
    throwForMisplacedOperators();
    throwForNotClosedBrackets();
}

void SyntaxAnalyzer::handleSignOfNumber()
{
    if (mTokenizer->getTokenCount() < 2)
    {
        return;
    }

    for (int i = 0; i < mTokenizer->getTokenCount() - 1; i++)
    {
        if (!(i == 0 || mTokenizer->getTokenAt(i - 1).charValue == '('))
        {
            continue;
        }

        const auto& token = mTokenizer->getTokenAt(i);
        auto nextToken = mTokenizer->getTokenAt(i + 1);

        if (token.charValue != '+' && token.charValue != '-')
        {
            continue;
        }

        if (nextToken.type != ETokenType::NUMBER)
        {
            continue;
        }

        mTokenizer->removeAt(i + 1);
        mTokenizer->removeAt(i);
        nextToken.numberValue = token.charValue == '-' ? -nextToken.numberValue : nextToken.numberValue;
        mTokenizer->insertAt(i, nextToken);
    }
}

void SyntaxAnalyzer::handleHiddenMultiplication()
{
    if (mTokenizer->getTokenCount() < 2)
    {
        return;
    }

    for (int i = 0; i < mTokenizer->getTokenCount() - 1; i++)
    {
        const auto& token = mTokenizer->getTokenAt(i);
        const auto& nextToken = mTokenizer->getTokenAt(i + 1);

        if ((token.charValue == ')' && nextToken.type == ETokenType::NUMBER) ||
            (token.charValue == ')' && nextToken.charValue == '(') ||
            (token.type == ETokenType::NUMBER && nextToken.charValue == '('))
        {
            Token op = { ETokenType::OPERATOR };
            op.stringValue += '*';
            op.charValue = '*';

            mTokenizer->insertAt(i + 1, op);
        }
    }
}

void SyntaxAnalyzer::handleEmptyBrackets()
{
    for (int i = 0; i < mTokenizer->getTokenCount(); i++)
    {
        const auto& token = mTokenizer->getTokenAt(i);
        
        if (token.charValue != '(')
        {
            continue;
        }

        int position = i + 1;
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
            i--;
        }
    }
}

void SyntaxAnalyzer::throwForDuplicatedOperators()
{
    if (mTokenizer->getTokenCount() < 2)
    {
        return;
    }

    for (int i = 0; i < mTokenizer->getTokenCount() - 1; i++)
    {
        const auto& token = mTokenizer->getTokenAt(i);
        const auto& nextToken = mTokenizer->getTokenAt(i + 1);

        if (token.type == ETokenType::OPERATOR && nextToken.type == ETokenType::OPERATOR)
        {
            throw ExpressionException("Duplicated operators.", i, nullptr);
        }
    }
}

void SyntaxAnalyzer::throwForMisplacedOperators()
{
    for (int i = 0; i < mTokenizer->getTokenCount(); i++)
    {
        Token prevToken = i > 0 ? mTokenizer->getTokenAt(i - 1) : Token{};
        const auto& token = mTokenizer->getTokenAt(i);
        Token nextToken = i < mTokenizer->getTokenCount() - 1 ? mTokenizer->getTokenAt(i + 1) : Token{};

        if (token.type != ETokenType::OPERATOR)
        {
            continue;
        }

        if (prevToken.type == ETokenType::UNDEFINED || prevToken.charValue == '(' ||
            nextToken.type == ETokenType::UNDEFINED || nextToken.charValue == ')')
        {
            throw ExpressionException("Misplaced operator.", i, nullptr);
        }
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
