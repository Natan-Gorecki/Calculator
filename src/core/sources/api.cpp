#include "api.h"
#include "C_Calculator.h"


//	Error Callback
ErrorCallback error_callback = NULL;


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