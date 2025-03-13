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
        mCacheErrorMessage = nullptr;
        mCacheErrorExpression = nullptr;

        return
        {
            true,
            numericResult,
            mCacheErrorMessage.get(),
            0,
            mCacheErrorExpression.get()
        };
    }
    catch (const CalculatorCore::ExpressionException& ex)
    {
        mCacheErrorMessage = makeCString(ex.what());
        mCacheErrorExpression = makeCString(ex.getExpression());

        return
        {
            false,
            0,
            mCacheErrorMessage.get(),
            ex.getPosition(),
            mCacheErrorExpression.get()
        };
    }
}

std::unique_ptr<char[]> Calculator::makeCString(const char* str)
{
    if (str == nullptr)
    {
        return nullptr;
    }

    size_t length = std::strlen(str);
    std::unique_ptr<char[]> buffer = std::make_unique<char[]>(length + 1);

    std::memcpy(buffer.get(), str, length);
    buffer[length] = '\0';

    return buffer;
}
