#pragma once
#include <stdexcept>

class ExpressionException : public std::exception
{
public:
    ExpressionException(const char* message, int position, const char* expression)
        : std::exception(message), mPosition(position), mExpression(expression) {}

    int getPosition() const { return mPosition; }
    const char* getExpression() const { return mExpression; }

private:
    int mPosition;
    const char* mExpression;
};
