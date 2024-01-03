#pragma once
#include <stdexcept>

class CalculatorException : public std::exception
{
public:
    CalculatorException(const char* message, int position, const char* expression)
        : std::exception(message), mPosition(position), mExpression(expression) {}

    int getPosition() const { return mPosition; }
    const char* getExpression() const { return mExpression; }

private:
    int mPosition;
    const char* mExpression;
};
