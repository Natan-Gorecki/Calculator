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

        double numericResult = interpreter->interpret(tokenizer.get());
        mCacheErrorMessage = "";
        mCacheErrorExpression = "";

        return
        {
            true,
            numericResult,
            mCacheErrorMessage.c_str(),
            0,
            mCacheErrorExpression.c_str()
        };
    }
    catch (const CalculatorCore::ExpressionException& ex)
    {
        mCacheErrorMessage = std::string(ex.what());
        mCacheErrorExpression = std::string(ex.getExpression());

        return
        {
            false,
            0,
            mCacheErrorMessage.c_str(),
            ex.getPosition(),
            mCacheErrorExpression.c_str()
        };
    }
}
