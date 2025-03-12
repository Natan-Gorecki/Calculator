#pragma once

#include <Windows.h>
#include "api.h"
#include "ICalculator.h"

using namespace System;

namespace CalculatorCLI
{
    public ref class Calculator : ICalculator
    {
    public:
        Calculator();
        ~Calculator();
        virtual double Calculate(String^ expression);

    private:
        HMODULE mlibraryHandle = nullptr;
        CalculatorCore::ICalculator* mCalculator = nullptr;
    };
}
