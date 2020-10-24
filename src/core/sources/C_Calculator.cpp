#include "C_Calculator.h"


extern ErrorCallback error_callback;


//------------------------------------------------------------------------------
//
//	Constructor
//
//------------------------------------------------------------------------------
C_Calculator::C_Calculator()
{
	this->parser = new C_Parser();
}



//------------------------------------------------------------------------------
//
//	Virtual destructor
//
//------------------------------------------------------------------------------
C_Calculator::~C_Calculator()
{
	delete parser;
	if (command) delete command;
}



//------------------------------------------------------------------------------
//
// Public method return result using command object
//
//------------------------------------------------------------------------------
double CC C_Calculator::Calculate(const char* expression)
{
	try
	{
		if (command)
		{
			delete command;
			command = NULL;
		}
		this->command = parser->Parse(expression);
		return this->command->Execute();
	}


	// Invoke error callback and rethrow exception
	catch (const char* exception)
	{
		if (error_callback)
		{
			error_callback(exception);
		}

		throw;
	}
}