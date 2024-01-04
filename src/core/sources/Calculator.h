#pragma once

#include "api.h"

class Calculator : public ICalculator
{
public:
    double CC Calculate(const char* expression) override;

private:
    bool mUseShuntingYardInterpreter = false;
    bool mUseRecursiveInterpreter = true;
};
