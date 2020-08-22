#include "api.h"
#include "C_Calculator.h"


//-----------------------------------------------------------------------------------------------------
//
//	CreateCalculator()
//
//-----------------------------------------------------------------------------------------------------
EXPORT I_Calculator* CC CreateCalculator()
{
	return (I_Calculator*) new C_Calculator();
}


//-----------------------------------------------------------------------------------------------------
//
//	DeleteCalculator( I_Calculator* calculator)
//
//-----------------------------------------------------------------------------------------------------
EXPORT void CC DeleteCalculator(I_Calculator* calculator)
{
	delete calculator;
	return;
}