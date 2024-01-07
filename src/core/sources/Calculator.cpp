#include <memory>
#include "interpreter/RecursiveInterpreter.h"
#include "interpreter/ShuntingYardInterpreter.h"
#include "tokenizer/Tokenizer.h"
#include "Calculator.h"

extern ErrorCallback error_callback;

using namespace std;

Calculator::Calculator(EInterpreterType interpreterType)
    : mInterpreterType(interpreterType)
{
}

double CC Calculator::calculate(const char* expression)
{
    try
    {
        auto tokenizer = make_unique<Tokenizer>();
        tokenizer->tokenize(expression);

        switch (mInterpreterType)
        {
        case EInterpreterType::RECURSIVE:
            {
                auto interpreter = make_unique<RecursiveInterpreter>();
                return interpreter->interpret(tokenizer.get());
            }
        case EInterpreterType::SHUNTING_YARD:
        default:
            {
                auto interpreter = make_unique<ShuntingYardInterpreter>();
                return interpreter->interpret(tokenizer.get());
            }
        }
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
