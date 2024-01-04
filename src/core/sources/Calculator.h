#pragma once

#include "api.h"
#include "interpreter/EInterpreterType.h"

class Calculator : public ICalculator
{
public:
    explicit Calculator(EInterpreterType interpreterType);
    double CC calculate(const char* expression) override;

private:
    EInterpreterType mInterpreterType = EInterpreterType::UNDEFINED;
};
