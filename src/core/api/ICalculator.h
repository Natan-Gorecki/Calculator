#pragma once

namespace CalculatorCore
{
    class ICalculator
    {
    public:
        virtual double CC calculate(const char* expression) = 0;
        virtual ~ICalculator() {};
    };
}
