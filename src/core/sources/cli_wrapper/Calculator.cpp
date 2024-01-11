#include "Calculator.h"
#include "ExpressionException.h"

using namespace System::Runtime::InteropServices;

CalculatorCLI::Calculator::Calculator()
{
#if !(USE_DYNAMIC || USE_STATIC)
    mlibraryHandle = LoadLibrary(L"CalculatorDynamic");

    if (!mlibraryHandle)
    {
        throw gcnew DllNotFoundException(L"Coudn't find CalculatorDynamic.dll");
    }

    auto Calculator_Create = (TCalculator_Create)GetProcAddress(mlibraryHandle, "Calculator_Create");
#endif

    mCalculator = Calculator_Create();
}

CalculatorCLI::Calculator::~Calculator()
{
#if !(USE_DYNAMIC || USE_STATIC)
    auto Calculator_Delete = (TCalculator_Delete)GetProcAddress(mlibraryHandle, "Calculator_Delete");
#endif

    Calculator_Delete(mCalculator);

    if (mlibraryHandle)
    {
        FreeLibrary(mlibraryHandle);
    }
}

double CalculatorCLI::Calculator::Calculate(String^ expression)
{
    try
    {
        auto expressionPtr = (char*)(void*)Marshal::StringToHGlobalAnsi(expression);
        auto result = mCalculator->calculate(expressionPtr);
        Marshal::FreeHGlobal((IntPtr)expressionPtr);
        return result;
    }
    catch (const CalculatorCore::ExpressionException& ex)
    {
        throw gcnew ExpressionException(gcnew String(ex.what()), ex.getPosition(), gcnew String(ex.getExpression()));
    }
}
