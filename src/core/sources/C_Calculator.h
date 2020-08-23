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
	//	Functions check next/previous non-whitespace character 
	//
	//	Return - the place of following char
	//	Return -	-1	in case when there are only whitespace char in searched range
	//
	//-----------------------------------------------------------------
	int next_char(const char* text, int start, int end);
	int previous_char(const char* text, int start, int end);



	//-----------------------------------------------------------------
	//	Funtions checking if the equation is correct
	//-----------------------------------------------------------------
	void check_if_equation_is_correct(const char* text, int start, int end);
	bool correct_parentheses(const char* text, int start, int end);
	bool correct_characters(const char* text, int start, int end);
	bool empty_parentheses(const char* text, int start, int end);
};

