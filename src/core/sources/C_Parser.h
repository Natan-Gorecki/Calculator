#pragma once

#include "Commands.h"

#include <string.h>
#include <string>


class C_Parser
{
public:
	C_Command* Parse(const char* expression);


private:
	// main function after check if the equation is correct
	C_Command* Parse(std::string expression);



	//-----------------------------------------------------------------
	//	First function check if there is operation outside parentheses to do  
	//	e.g. 2(4*2) - multiply
	//		 2+4	- addition
	//
	//
	//	Return the place, where find  LAST  operation to do or -1
	//-----------------------------------------------------------------
	int OperationOutsideParentheses(std::string text);



	//-----------------------------------------------------------------
	//	Functions check next/previous non-whitespace character 
	//
	//	Return - the place of following char
	//	Return -	-1	in case when there are only whitespace char in searched range
	//
	//-----------------------------------------------------------------
	int next_char(std::string text, int start, int end);
	int previous_char(std::string text, int start, int end);



	//-----------------------------------------------------------------
	//	Return TRUE - '0'-'9' v '.' v ','
	//
	//	Return FALSE - other characters
	//-----------------------------------------------------------------
	bool is_number(char c);



	//-----------------------------------------------------------------
	//	Method check if there are outside parentheses
	//	e.g (2+2)	v	(4*2)
	//
	// Return empty string or expression inside parentheses 
	//-----------------------------------------------------------------
	std::string inside_parentheses(std::string text);



	//-----------------------------------------------------------------
	//	Funtions checking if the equation is correct
	//-----------------------------------------------------------------
	void check_if_equation_is_correct(std::string text);
	bool correct_parentheses(std::string text);
	bool correct_characters(std::string text);
	bool empty_parentheses(std::string text);
};