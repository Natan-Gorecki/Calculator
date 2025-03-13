#include "Calculator.h"
#include "ExpressionException.h"

using namespace System::Runtime::InteropServices;

CalculatorCLI::Calculator::Calculator()
{
#if !(USE_DYNAMIC || USE_STATIC)
    mlibraryHandle = LoadLibrary(L"CalculatorDynamic");

    if (!mlibraryHandle)
    {
        throw gcnew DllNotFoundException(L"Couldn't find CalculatorDynamic.dll");
    }

    auto Calculator_Create = (TCalculator_Create)GetProcAddress(mlibraryHandle, "Calculator_Create");

    if (!Calculator_Create)
    {
        throw gcnew MissingMethodException(L"Couldn't find Calculator_Create method");
    }
#endif

    mCalculator = Calculator_Create();
}

CalculatorCLI::Calculator::~Calculator()
{
#if !(USE_DYNAMIC || USE_STATIC)
    auto Calculator_Delete = (TCalculator_Delete)GetProcAddress(mlibraryHandle, "Calculator_Delete");

    if (!Calculator_Delete)
    {
        throw gcnew MissingMethodException(L"Couldn't find Calculator_Delete method");
    }
#endif

    Calculator_Delete(mCalculator);

    if (mlibraryHandle)
    {
        FreeLibrary(mlibraryHandle);
    }
}

double CalculatorCLI::Calculator::Calculate(String^ expression)
{
    char* expressionPtr = (char*)(void*)Marshal::StringToHGlobalAnsi(expression);
    CalculatorCore::CalculationResult calculationResult = mCalculator->calculate(expressionPtr);
    Marshal::FreeHGlobal((IntPtr)expressionPtr);

    if (!calculationResult.isSuccess)
    {
        throw gcnew ExpressionException(
            gcnew String(calculationResult.errorMessage),
            calculationResult.errorPosition,
            gcnew String(calculationResult.errorExpression)
        );
    }

    return calculationResult.numericResult;
}
