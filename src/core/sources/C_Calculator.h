#pragma once
#include "api.h"


class C_Calculator :
	public I_Calculator
{
public:
	virtual double CC Calculate(const char* expression);


private:
	// main function after check if the equation is correct
	double calculate(const char* text, int start, int end);


	//-----------------------------------------------------------------
	//	Funtions checking if the equation is correct
	//-----------------------------------------------------------------
	void check_if_equation_is_correct(const char* text, int start, int end);
	bool correct_parentheses(const char* text, int start, int end);
	bool correct_characters(const char* text, int start, int end);
	bool empty_parentheses(const char* text, int start, int end);
};

