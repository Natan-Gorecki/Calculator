#include <Windows.h>
#include "api.h"

using namespace System;

namespace CalculatorCLI
{
    ref class Calculator
    {
    public:
        Calculator();
        ~Calculator();
        double Calculate(String^ expression);

    private:
        HMODULE mlibraryHandle = nullptr;
        CalculatorCore::ICalculator* mCalculator = nullptr;
    };
}
