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

double CC Calculator::calculate(const char* expression)
{
    auto tokenizer = make_unique<Tokenizer>();
    tokenizer->tokenize(expression);

    auto analyzer = make_unique<SyntaxAnalyzer>();
    analyzer->analyze(tokenizer.get());

    switch (mInterpreterType)
    {
    case EInterpreterType::RECURSIVE:
        {
            auto interpreter = make_unique<RecursiveInterpreter>();
            return interpreter->interpret(tokenizer.get());
        }
    default:
        {
            auto interpreter = make_unique<ShuntingYardInterpreter>();
            return interpreter->interpret(tokenizer.get());
        }
    }
}
