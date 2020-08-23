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
//
//	Funtion checking if the equation is correct
//
//-----------------------------------------------------------------
void check_if_equation_is_correct(const char* text, int start, int end)
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
bool correct_parentheses(const char* text, int start, int end)
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
bool correct_characters(const char* text, int start, int end)
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
bool empty_parentheses(const char* text, int start, int end)
{
	for (int i = start; i <= end; i++)
		if (text[i] == '(')
			if (i < end)
				if (next_char(text, i + 1, end) != -1)
					if (text[next_char(text, i + 1, end)] == ')')
						return true;
	return false;

}