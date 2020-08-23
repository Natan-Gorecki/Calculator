#include "C_Calculator.h"
#include <string.h>


//------------------------------------------------------------------------------
//
//	Public function return result after checking if the equation is correct
//
//------------------------------------------------------------------------------
double CC C_Calculator::Calculate(const char* expression)
{
	check_if_equation_is_correct(expression, 0, strlen(expression) - 1);
	return calculate(expression, 0, strlen(expression) - 1);
}



//------------------------------------------------------------------------------
//
//	Function calculating the result
//
//------------------------------------------------------------------------------
double calculate(const char* text, int start, int end)
{
	// TODO
	return -1;
}



//-----------------------------------------------------------------
//	Function check next non-whitespace character 
//
//	Return - the place of following char
//	Return -	-1	in case when there are only whitespace char in searched range
//-----------------------------------------------------------------
int C_Calculator::next_char(const char* text, int start, int end) {
	for (int i = start; i <= end; i++)
		if (text[i] != ' ')
			return i;

	return -1;
}



//-----------------------------------------------------------------
//	Functions check previous non-whitespace character 
//
//	Return - the place of previous char
//	Return -	-1	in case when there are only whitespace char in searched range
//-----------------------------------------------------------------
int C_Calculator::previous_char(const char* text, int start, int end) {
	for (int i = end; i >= start; i--)
		if (text[i] != ' ')
			return i;

	return -1;
}



//-----------------------------------------------------------------
//
//	Funtion checking if the equation is correct
//
//-----------------------------------------------------------------
void C_Calculator::check_if_equation_is_correct(const char* text, int start, int end)
{
	if (correct_parentheses(text, start, end) == false)
		throw "Invalid parentheses";

	if (empty_parentheses(text, start, end) == true)
		throw "Empty parentheses";

	if (correct_characters(text, start, end) == false)
		throw "Invalid character";

	if (start > end)
		throw "Empty equation";
}



//-----------------------------------------------------------------
//
//	Funtion checking if the number and position of parentheses is correct
//
//-----------------------------------------------------------------
bool C_Calculator::correct_parentheses(const char* text, int start, int end)
{
	int counter = 0;

	for (int i = start; i <= end; i++) {
		if (text[i] == '(')
			counter++;
		if (text[i] == ')')
			counter--;


		//	Wrong arrangement of parentheses 
		// e.g '( ))'
		if (counter < 0)
			return false;
	}


	// Equal number of left and rigth bracket - return true 
	if (counter == 0)
		return true;


	// Uneven number of left and rigth bracket - retrun false
	//e.g. '( ()'
	return false;

}



//-----------------------------------------------------------------
//
//	Funtion checking if the characters are correct
//	Correct characters are (, ), *, +, -, ., /, 0-9 and ','
//
//-----------------------------------------------------------------
bool C_Calculator::correct_characters(const char* text, int start, int end)
{
	for (int i = start; i <= end; i++)
		if (!(('(' <= text[i] && text[i] <= '9') || text[i] == ' '))
			return false;

	return true;
}



//-----------------------------------------------------------------
//
//	Funtion checking if there are empty parentheses
//	e.g. '( )'
//
//-----------------------------------------------------------------
bool C_Calculator::empty_parentheses(const char* text, int start, int end)
{
	for (int i = start; i <= end; i++)
		if (text[i] == '(')
			if (i < end)
				if (next_char(text, i + 1, end) != -1)
					if (text[next_char(text, i + 1, end)] == ')')
						return true;
	return false;

}