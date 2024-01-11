#include "ShuntingYardInterpreter.h"

using namespace std;
using namespace CalculatorCore;

double ShuntingYardInterpreter::interpret(Tokenizer* tokenizer)
{
    mNumberStack.clear();
    mOutputStack.clear();
    mOperatorStack.clear();

    int position = 0;
    while (position < tokenizer->getTokenCount()) 
    {
        const auto& token = tokenizer->getTokenAt(position);
        position++;

        if (token.type == ETokenType::NUMBER)
        {
            mOutputStack.push_back(token);
            continue;
        }
        if (token.type == ETokenType::OPERATOR)
        {
            handleOperator(token);
            continue;
        }
        if (token.charValue == '(')
        {
            mOperatorStack.push_back(token);
            continue;
        }
        if (token.charValue == ')')
        {
            handleRightParenthesis();
            continue;
        }
    }

    while (!mOperatorStack.empty())
    {
        const auto& token = mOperatorStack.back();
        mOperatorStack.pop_back();
        mOutputStack.push_back(token);
    }

    return calculate();
}

double ShuntingYardInterpreter::calculate()
{
    for (const auto& token : mOutputStack)
    {
        if (token.type == ETokenType::NUMBER)
        {
            mNumberStack.push_back(token.numberValue);
            continue;
        }

        auto right = mNumberStack.back();
        mNumberStack.pop_back();
        auto left = mNumberStack.back();
        mNumberStack.pop_back();

        auto result = Interpreter::calculate(left, right, token.charValue);
        mNumberStack.push_back(result);
    }

    return mNumberStack.back();
}

void ShuntingYardInterpreter::handleOperator(const Token& op1)
{
    while (!mOperatorStack.empty())
    {
        Token op2 = mOperatorStack.back();
        
        if (op2.type != ETokenType::OPERATOR)
        {
            break;
        }

        if (getPrecedence(op2)> getPrecedence(op1) || (getPrecedence(op1) == getPrecedence(op2) && isLeftAssociative(op1)))
        {
            mOperatorStack.pop_back();
            mOutputStack.push_back(op2);
            continue;
        }

        break;
    }

    mOperatorStack.push_back(op1);
}

void ShuntingYardInterpreter::handleRightParenthesis()
{
    while (true)
    {
        Token token = mOperatorStack.back();

        if (token.charValue != '(')
        {
            mOperatorStack.pop_back();
            mOutputStack.push_back(token);
            continue;
        }

        mOperatorStack.pop_back();
        break;
    }
}