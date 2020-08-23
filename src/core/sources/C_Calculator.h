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
	//	First function check if there is operation outside parentheses to do  
	//	e.g. 2(4*2) - multiply
	//		 2+4	- addition
	//
	//	Second function find	LAST	operation to do
	//
	//	Return the place, where find this operation
	//
	//-----------------------------------------------------------------
	bool operation_outside_parentheses(const char* tekst, int start, int end);
	int finding_last_operation(const char* tekst, int start, int end);



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
	//	Return TRUE - '0'-'9' v '.' v ','
	//
	//	Return FALSE - other characters
	//-----------------------------------------------------------------
	bool is_number(char c);



	//-----------------------------------------------------------------
	//	First function check if there are outside parentheses
	//	e.g (2+2)	v	(4*2)
	//
	//	Second function find them and give their location left and rigth variable
	//-----------------------------------------------------------------
	bool are_parentheses(const char* text, int start, int end);
	void finding_parentheses(const char* text, int start, int end, int& left, int& rigth);



	//-----------------------------------------------------------------
	//	Funtions checking if the equation is correct
	//-----------------------------------------------------------------
	void check_if_equation_is_correct(const char* text, int start, int end);
	bool correct_parentheses(const char* text, int start, int end);
	bool correct_characters(const char* text, int start, int end);
	bool empty_parentheses(const char* text, int start, int end);
};

