#pragma once

#include "api.h"
#include "Commands.h"
#include "C_Parser.h"


class C_Calculator :
	public I_Calculator
{
	// Calculate Method
public:
	virtual double CC Calculate(const char* expression);


	// Constructor / Destructor
public:
	C_Calculator();
	virtual ~C_Calculator();


	// Attributes
private:
	C_Command* command = NULL;
	C_Parser* parser = NULL;
};
