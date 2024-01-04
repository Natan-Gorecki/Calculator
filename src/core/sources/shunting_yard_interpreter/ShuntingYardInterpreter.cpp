#include "../InterpreterException.h"
#include "ShuntingYardInterpreter.h"

using namespace std;

double ShuntingYardInterpreter::interpret(Tokenizer* tokenizer)
{
    mNumberStack.clear();
    mOutputStack.clear();
    mOperatorStack.clear();

    int position = 0;
    while (position < tokenizer->getTokenCount()) 
    {
        const auto& token = tokenizer->getTokenAt(position++);
        if (token.tokenType == ETokenType::NUMBER)
        {
            mOutputStack.push_back(token);
            continue;
        }
        if (token.tokenType == ETokenType::OPERATOR)
        {
            handleOperator(token);
        }
        if (token.separatorValue == '(')
        {
            mOperatorStack.push_back(token);
            continue;
        }
        if (token.separatorValue == ')')
        {
            handleRightParenthesis();
            continue;
        }
    }

    while (!mOperatorStack.empty())
    {
        const auto& token = mOperatorStack.back();
        mOperatorStack.pop_back();

        if (token.separatorValue == '(')
        {
            throw InterpreterException("Mismatched parentheses.");
        }

        mOutputStack.push_back(token);
    }

    return calculate();
}

double ShuntingYardInterpreter::calculate()
{
    for (int i = 0; i < mOutputStack.size(); i++)
    {
        const auto& token = mOutputStack.at(i);

        if (token.tokenType == ETokenType::NUMBER)
        {
            mNumberStack.push_back(token.numberValue);
            continue;
        }

        if (mNumberStack.size() < 2)
        {
            throw InterpreterException("Invalid expression.");
        }

        auto right = mNumberStack.back();
        mNumberStack.pop_back();
        auto left = mNumberStack.back();
        mNumberStack.pop_back();

        auto result = calculate(left, right, token.operatorType);
        mNumberStack.push_back(result);
    }

    if (mNumberStack.size() != 1)
    {
        throw InterpreterException("Invalid expression.");
    }

    return mNumberStack.back();
}

double ShuntingYardInterpreter::calculate(double left, double right, EOperatorType op) const
{
    switch (op)
    {
    case EOperatorType::ADDITION:
        return left + right;
    case EOperatorType::SUBSTRACTION:
        return left - right;
    case EOperatorType::MULTIPLICATION:
        return left * right;
    case EOperatorType::DIVISION:
        return left / right;
    case EOperatorType::POWER:
        return pow(left, right);
    default:
        throw InterpreterException("Undefined operator type.");
    }
}

void ShuntingYardInterpreter::handleOperator(const Token& op1)
{
    while (!mOperatorStack.empty())
    {
        const auto& op2 = mOperatorStack.back();
        
        if (op2.tokenType != ETokenType::OPERATOR)
        {
            break;
        }

        if (op2.operatorPriority > op1.operatorPriority || (op1.operatorPriority == op2.operatorPriority && isLeftAssociative(op1)))
        {
            mOperatorStack.pop_back();
            mOutputStack.push_back(op2);
            continue;
        }
    }
}

void ShuntingYardInterpreter::handleRightParenthesis()
{
    while (true)
    {
        if (mOperatorStack.empty())
        {
            throw InterpreterException("Mismatched parentheses.");
        }
        const auto& token = mOperatorStack.back();

        if (token.separatorValue != '(')
        {
            mOperatorStack.pop_back();
            mOutputStack.push_back(token);
            continue;
        }

        mOperatorStack.pop_back();
        break;
    }
}

bool ShuntingYardInterpreter::isLeftAssociative(const Token& op1) const
{
    return op1.operatorType != EOperatorType::POWER;
}
