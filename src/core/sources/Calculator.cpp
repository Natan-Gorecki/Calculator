#include <memory>
#include "Calculator.h"
#include "tokenizer/Tokenizer.h"
#include "shunting_yard_interpreter/ShuntingYardInterpreter.h"

extern ErrorCallback error_callback;

using namespace std;

double CC Calculator::Calculate(const char* expression)
{
    try
    {
        auto tokenizer = make_unique<Tokenizer>();
        tokenizer->tokenize(expression);

        if (mUseShuntingYardInterpreter)
        {
            auto interpreter = make_unique<ShuntingYardInterpreter>();
            return interpreter->interpret(tokenizer.get());
        }

        return 0;
    }
    catch (const char* exception)
    {
        if (error_callback)
        {
            error_callback(exception);
        }

        throw;
    }
}
