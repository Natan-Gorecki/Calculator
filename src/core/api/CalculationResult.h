#pragma once

namespace CalculatorCore
{
    struct CalculationResult
    {
        bool isSuccess;
        double numericResult;

        const char* message;
        int position;
        const char* expression;
    };
}
