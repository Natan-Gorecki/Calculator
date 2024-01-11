#pragma once
#include <stdexcept>

namespace CalculatorCore
{
    class ExpressionException : public std::exception
    {
    public:
        ExpressionException(const char* message, int position, const char* expression)
            : std::exception(message), mPosition(position), mExpression(expression)
        {
        }

        int getPosition() const { return mPosition; }
        const char* getExpression() const { return mExpression.c_str(); }

    private:
        int mPosition;
        std::string mExpression;
    };
}
