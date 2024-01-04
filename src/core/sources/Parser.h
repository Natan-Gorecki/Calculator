#pragma once

#include "commands/Command.h"

#include <string.h>
#include <string>


class Parser
{
public:
	Command* Parse(const char* expression);


private:
	// main function after check if the equation is correct
	Command* Parse(std::string expression);



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
	int NextChar(std::string text, int start, int end);
	int PreviousChar(std::string text, int start, int end);



	//-----------------------------------------------------------------
	//	Return TRUE - '0'-'9' v '.' v ','
	//
	//	Return FALSE - other characters
	//-----------------------------------------------------------------
	bool IsNumber(char c);



	//-----------------------------------------------------------------
	//	Method check if there are outside parentheses
	//	e.g (2+2)	v	(4*2)
	//
	// Return empty string or expression inside parentheses 
	//-----------------------------------------------------------------
	std::string InsideParentheses(std::string text);



	//-----------------------------------------------------------------
	//	Funtions checking if the equation is correct
	//-----------------------------------------------------------------
	void CheckIfExpressionIsCorrect(std::string text);
	bool CorrectParentheses(std::string text);
	bool CorrectCharacters(std::string text);
	bool EmptyParentheses(std::string text);
};