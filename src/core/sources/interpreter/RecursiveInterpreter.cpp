#include "InterpreterException.h"
#include "RecursiveInterpreter.h"

double RecursiveInterpreter::interpret(Tokenizer* tokenizer)
{
    mTokenizer = tokenizer;
    auto result = interpretImpl(0, tokenizer->getTokenCount() - 1);
    mTokenizer = nullptr;

    return result;
}

double RecursiveInterpreter::interpretImpl(int start, int end)
{
    if (isWrapperWithBrackets(start, end))
    {
        return interpretImpl(start + 1, end - 1);
    }

    int position;
    if (findLeastPrecedenceOperator(start, end, position))
    {
        auto left = interpretImpl(start, position - 1);
        auto right = interpretImpl(position + 1, end);
        return calculate(left, right, mTokenizer->getTokenAt(position).charValue);
    }

    if (start < end)
    {
        throw InterpreterException("Empty expression.");
    }

    const auto& token = mTokenizer->getTokenAt(start);

    if (token.type != ETokenType::NUMBER)
    {
        throw InterpreterException("Invalid expression.");
    }

    return token.numberValue;
}

bool RecursiveInterpreter::findLeastPrecedenceOperator(int start, int end, int& position)
{
    int level = 0;
    int precedence = 10;
    position = -1;

    for (int i = end; i >= start; i--)
    {
        const auto& token = mTokenizer->getTokenAt(i);
        
        if (token.charValue == ')')
        {
            level++;
        }

        if (token.charValue == '(')
        {
            level--;
        }

        if (level > 0 || token.type != ETokenType::OPERATOR)
        {
            continue;
        }

        if (getPrecedence(token) < precedence)
        {
            position = i;
            precedence = getPrecedence(token);
            continue;
        }

        if (getPrecedence(token) == precedence && !isLeftAssociative(token))
        {
            position = i;
            precedence = getPrecedence(token);
        }
    }

    return position != -1;
}

bool RecursiveInterpreter::isWrapperWithBrackets(int start, int end)
{
    const auto& first = mTokenizer->getTokenAt(start);

    if (first.charValue != '(')
    {
        return false;
    }

    int level = 0;
    for (int i = start; i <= end; i++)
    {
        const auto& token = mTokenizer->getTokenAt(i);

        if (token.charValue == '(')
        {
            level++;
        }

        if (token.charValue == ')')
        {
            level--;
        }

        if (level == 0)
        {
            return i == end;
        }
    }

    return false;
}
