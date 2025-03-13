#pragma once
#include "CalculationResult.h"

namespace CalculatorCore
{
    class ICalculator
    {
    public:
        virtual CalculationResult CC calculate(const char* expression) = 0;
        virtual ~ICalculator() {};
    };
}
