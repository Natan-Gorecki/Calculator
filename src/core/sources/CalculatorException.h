#pragma once
#include <stdexcept>

class CalculatorException : public std::exception
{
public:
    CalculatorException(const char* message, int position, std::string expression)
        : std::exception(message), mExpression(expression), mPosition(position) {}

    int getPosition() const { return mPosition; }
    const char* getExpression() const { return mExpression.c_str(); }

private:
    int mPosition;
    std::string mExpression;
};
