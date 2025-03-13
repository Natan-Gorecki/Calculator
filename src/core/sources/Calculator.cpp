#include <memory>
#include "interpreter/RecursiveInterpreter.h"
#include "interpreter/ShuntingYardInterpreter.h"
#include "syntax_analyzer/SyntaxAnalyzer.h"
#include "tokenizer/Tokenizer.h"
#include "Calculator.h"

using namespace std;
using namespace CalculatorCore;

Calculator::Calculator(EInterpreterType interpreterType)
    : mInterpreterType(interpreterType)
{
}

CalculationResult CC Calculator::calculate(const char* expression)
{
    try
    {
        auto tokenizer = make_unique<Tokenizer>();
        tokenizer->tokenize(expression);

        auto analyzer = make_unique<SyntaxAnalyzer>();
        analyzer->analyze(tokenizer.get());

        std::unique_ptr<Interpreter> interpreter = nullptr;
        switch (mInterpreterType)
        {
        case EInterpreterType::RECURSIVE:
            interpreter = make_unique<RecursiveInterpreter>();
            break;
        default:
            interpreter = make_unique<ShuntingYardInterpreter>();
            break;
        }

        return
        {
            true,
            interpreter->interpret(tokenizer.get())
        };
    }
    catch (const CalculatorCore::ExpressionException& ex)
    {
        return
        {
            false,
            0,
            ex.what(),
            ex.getPosition(),
            ex.getExpression()
        };
    }
}
