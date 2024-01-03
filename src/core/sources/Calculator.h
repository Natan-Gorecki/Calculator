#pragma once

#include "api.h"
#include "commands/Command.h"
#include "Parser.h"


class Calculator :
	public ICalculator
{
	// Calculate Method
public:
	virtual double CC Calculate(const char* expression);


	// Constructor / Destructor
public:
	Calculator();
	virtual ~Calculator();


	// Attributes
private:
	Command* command = NULL;
	Parser* parser = NULL;
};
