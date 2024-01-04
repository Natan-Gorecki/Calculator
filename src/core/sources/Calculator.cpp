#include <memory>
#include "Calculator.h"
#include "interpreter/RecursiveInterpreter.h"
#include "interpreter/ShuntingYardInterpreter.h"
#include "tokenizer/Tokenizer.h"

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
        if (mUseRecursiveInterpreter)
        {
            auto interpreter = make_unique<RecursiveInterpreter>();
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
