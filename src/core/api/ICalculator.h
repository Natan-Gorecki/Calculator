#pragma once

class ICalculator
{
public:
	virtual double CC Calculate(const char* expression) = 0;
	virtual ~ICalculator() {};
};