#pragma once
#include "api.h"


class C_Calculator :
	public I_Calculator
{
public:
	virtual double CC Calculate(const char* expression);
};

