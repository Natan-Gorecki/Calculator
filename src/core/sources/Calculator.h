#pragma once

#include <memory>
#include "api.h"
#include "interpreter/EInterpreterType.h"

namespace CalculatorCore
{
    class Calculator : public ICalculator
    {
    public:
        explicit Calculator(EInterpreterType interpreterType);
        CalculationResult CC calculate(const char* expression) override;

    private:
        std::unique_ptr<char[]> makeCString(const char* str);

        EInterpreterType mInterpreterType = EInterpreterType::UNDEFINED;
        // Prevent memory leaks
        std::unique_ptr<char[]> mCacheErrorMessage = nullptr;
        std::unique_ptr<char[]> mCacheErrorExpression = nullptr;
    };
}
