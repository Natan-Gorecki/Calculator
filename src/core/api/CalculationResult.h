#pragma once

namespace CalculatorCore
{
    struct CalculationResult
    {
        bool isSuccess;
        double numericResult;

        const char* errorMessage;
        int errorPosition;
        const char* errorExpression;
    };
}
