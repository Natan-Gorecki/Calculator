using namespace System;

namespace CalculatorCLI
{
    ref class ExpressionException : public Exception
    {
    public:
        ExpressionException(String^ message, int position, String^ expression)
            : Exception(message)
        {
            mMessage = message;
            mPosition = position;
            mExpression = expression;
        }

        property String^ Expression
        {
            String^ get()
            {
                return mExpression;
            }
        }

        property int Position
        {
            int get()
            {
                return mPosition;
            }
        }

    private:
        String^ mMessage;
        int mPosition;
        String^ mExpression;
    };
}
