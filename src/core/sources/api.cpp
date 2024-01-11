#include "api.h"
#include "Calculator.h"

using namespace CalculatorCore;

//	Error Callback
ErrorCallback error_callback = NULL;


//-----------------------------------------------------------------------------------------------------
//
//	CreateCalculator()
//
//-----------------------------------------------------------------------------------------------------
EXPORT ICalculator* CC CreateCalculator()
{
	return (ICalculator*) new Calculator(EInterpreterType::SHUNTING_YARD);
}


//-----------------------------------------------------------------------------------------------------
//
//	DeleteCalculator( I_Calculator* calculator)
//
//-----------------------------------------------------------------------------------------------------
EXPORT void CC DeleteCalculator(ICalculator* calculator)
{
	delete calculator;
	return;
}


//-----------------------------------------------------------------------------------------------------
//
//	SetErrorCallback( ErrorCallback callback )
//
//-----------------------------------------------------------------------------------------------------
EXPORT void CC SetErrorCallback(ErrorCallback callback)
{
	if (callback)
	{
		error_callback = callback;
	}
}