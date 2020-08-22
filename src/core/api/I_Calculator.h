#pragma once

class I_Calculator 
{
public:
	virtual double CC Calculate(const char* expression) = 0;
	virtual ~I_Calculator() {};
};