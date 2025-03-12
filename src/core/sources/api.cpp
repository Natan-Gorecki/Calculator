#include "api.h"
#include "Calculator.h"

using namespace CalculatorCore;

EXPORT ICalculator* CC Calculator_Create()
{
    return (ICalculator*) new Calculator(EInterpreterType::SHUNTING_YARD);
}

EXPORT void CC Calculator_Delete(ICalculator* calculator)
{
    delete calculator;
    return;
}
