#pragma once

using namespace System;

namespace CalculatorCLI
{
    public interface class ICalculator : IDisposable
    {
    public:
        double Calculate(String^ expression);
    };
}
