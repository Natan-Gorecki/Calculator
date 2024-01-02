#include "Calculator.h"


extern ErrorCallback error_callback;


//------------------------------------------------------------------------------
//
//	Constructor
//
//------------------------------------------------------------------------------
Calculator::Calculator()
{
	this->parser = new Parser();
}



//------------------------------------------------------------------------------
//
//	Virtual destructor
//
//------------------------------------------------------------------------------
Calculator::~Calculator()
{
	delete parser;
	if (command) delete command;
}



//------------------------------------------------------------------------------
//
// Public method return result using command object
//
//------------------------------------------------------------------------------
double CC Calculator::Calculate(const char* expression)
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