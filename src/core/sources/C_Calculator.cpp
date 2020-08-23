#include "C_Calculator.h"
#include <string.h>
#include <string>


//------------------------------------------------------------------------------
//
//	Public function return result after checking if the equation is correct
//
//------------------------------------------------------------------------------
double CC C_Calculator::Calculate(const char* expression)
{
	check_if_equation_is_correct(expression, 0, (int)strlen(expression) - 1);
	return calculate(expression, 0, (int)strlen(expression) - 1);
}



//------------------------------------------------------------------------------
//
//	Function calculating the result
//
//------------------------------------------------------------------------------
double C_Calculator::calculate(const char* text, int start, int end)
{
	int char_place;

	// If there is operation oustide patentheses => char_place = the place of LAST operation to do
	if (operation_outside_parentheses(text, start, end) == true) 
	{
		char_place = finding_last_operation(text, start, end);

		//	e.g. +2 v *4
		if (char_place == start)
			goto first_in_equation;



		//-----------------------------------------------------------
		//	Conditon functions:
		//		* throw exception for expression like "**" or "+/" 
		//		* throw exception for expression like "*2" or "/4"
		//		* +(part_of_equation) => return  1 * part_of_equation
		//		* -(part_of_equation) => return -1 * part_of_equation
		//-----------------------------------------------------------
		if (char_place > start) 
		{

			// We're checking multiplied operation char
			// e.g ++, *+
			if (previous_char(text, start, char_place - 1) != -1)
			{
				char temp_ch = text[previous_char(text, start, char_place - 1)];
				if (temp_ch == '+' || temp_ch == '-' || temp_ch == '*' || temp_ch == '/')
					throw "Too many operation chars ('+', '-', '*', '/')";
			}


			// First char in equation is operation char
			// previous_char(text, start, char_place - 1) == -1
			// e.g. "  + 2"
			else 
			{

				//	char_place == start
				//	e.g. "+ 2"
			first_in_equation:

				switch (text[char_place]) 
				{

				case '+':	return 1 * calculate(text, char_place + 1, end);

				case '-':	return -1 * calculate(text, char_place + 1, end);

					//	Invalid equation
					//	e.g. *2 v /4
				case '*':
				case '/':
					throw "Character '*'  or '/' at the beginning";
				}
			}
		}



		//-----------------------------------------------------------
		//	Conditions functions:
		//		* throw exception for expression like "2*"
		//		* throw exception for expression like "2 *   "
		//-----------------------------------------------------------
		if (char_place == end)
			throw "Operation char at the end";
		if (char_place < end)
			if (next_char(text, char_place + 1, end) == -1)
				throw "Operation char at the end";



		//---------------------------------------------------------------------------------------
		//	Switch statement function:
		//		* we have place of LAST operation to do in variable char_place
		//		* we do this operation on two parts of the eqation separated by char_place
		//---------------------------------------------------------------------------------------
		switch (text[char_place])
		{

		case '+':	return calculate(text, start, char_place - 1) + calculate(text, char_place + 1, end);

		case '-':	return calculate(text, start, char_place - 1) - calculate(text, char_place + 1, end);

		case '*':	return calculate(text, start, char_place - 1) * calculate(text, char_place + 1, end);

		case '/':

			//Throw exception - Division by 0!
			if (calculate(text, char_place + 1, end) == 0)
			{
				throw "Division by 0!";
			}

			return calculate(text, start, char_place - 1) / calculate(text, char_place + 1, end);

		case '(':	return calculate(text, start, char_place - 1) * calculate(text, char_place, end);

		case ')':	return calculate(text, start, char_place) * calculate(text, char_place + 1, end);
		}
	}



	//-----------------------------------------------------------
	//
	//	We have only number or part of the equation in parentheses
	//
	//	If there is outside parentheses
	//	(part_of_equation) => return part_of_eqation
	//
	//-----------------------------------------------------------
	int left, rigth;
	if (are_parentheses(text, start, end, left, rigth) == true) 
		return calculate(text, left + 1, rigth - 1);



	//-----------------------------------------------------------
	//	We have only number
	//-----------------------------------------------------------
	std::string result;
	int count_of_dot = 0;

	//-----------------------------------------------------------
	//	Convert part of equation from char[] to double 
	//-----------------------------------------------------------
	for (int i = start; i <= end; i++) {
		if ('0' <= text[i] && text[i] <= '9')
			result += text[i];
		if (text[i] == '.' || text[i] == ',') {
			result += '.';
			count_of_dot++;
		}
	}



	//-----------------------------------------------------------
	// Check if the number was correct
	// If not, throw exception 
	// e.g. "2.." v ".2." v "." v ","
	//-----------------------------------------------------------
	if (count_of_dot > 1 || result == "." || result == ",") // in case of 2.. v .2. v . v ,
		throw "Invalid number of dots or commas";



	//-----------------------------------------------------------
	// Check if the eqation isn't empty
	//-----------------------------------------------------------
	if (result == "")
		throw "Empty equation";



	//------------------------------------------------------------
	// 
	//	RETURN VALUE OF THIS PART OF THE EQUATION 
	//
	//------------------------------------------------------------
	return stod(result);
}



//------------------------------------------------------------------------------
//	Function check if there is operation outside parentheses to do  
//	e.g. 2(4*2) - multiply
//		 2+4	- addition
//
//------------------------------------------------------------------------------
bool C_Calculator::operation_outside_parentheses(const char* tekst, int start, int end) 
{

	// We're looking for operation ONLY OUTSIDE parentheses
	// Level must have value 0
	int level = 0;


	//------------------------------------------
	//	Loop that checks if there is addition or  subtraction
	//	Return TRUE -	'+' v '-'
	//------------------------------------------
	for (int i = end; i >= start; i--) 
	{
		if (tekst[i] == '+' || tekst[i] == '-')
			if (level == 0)
				return true;

		//	Opening the bracket increases level
		if (tekst[i] == ')')
			level++;

		//	Closing the bracket decreases level
		if (tekst[i] == '(')
			level--;
	}


	//------------------------------------------
	//	Loop that checks if there is multiplication or division
	//	Return TRUE -	'*' v '/'
	//	Return TRUE -	")2" v ")(" v "2("
	//------------------------------------------
	for (int i = end; i >= start; i--) 
	{
		if (tekst[i] == '*' || tekst[i] == '/')
			if (level == 0)
				return true;

		//	Opening the bracket increases level
		if (tekst[i] == ')')
		{
			level++;

			//	Return TRUE, when next char is number <==> ") 2"
			if (i < end && level == 1)
				if (next_char(tekst, i + 1, end) != -1)
					if (is_number(tekst[next_char(tekst, i + 1, end)]))
						return true;
		}


		//	Closing the bracket decreases level
		if (tekst[i] == '(') 
		{
			level--;

			//	Return TRUE, when previous char is number or the opposite bracket
			//	<==> ") (" v "2 ("
			if (i > start && level == 0)
				if (previous_char(tekst, start, i - 1) != -1)
					if (is_number(tekst[previous_char(tekst, start, i - 1)]) || tekst[previous_char(tekst, start, i - 1)] == ')')
						return true;
		}
	}


	//	Return false, when no matching operation was found 
	//	Ramaining number or operations in parentheses
	return false;
}



//------------------------------------------------------------------------------
//	Function find	LAST	operation to do
//
//	Return the place, where find this operation
//------------------------------------------------------------------------------
int C_Calculator::finding_last_operation(const char* tekst, int start, int end) 
{

	// We're looking for operation ONLY OUTSIDE parentheses
	// Level must have value 0
	int level = 0;


	//------------------------------------------
	//	Loop that checks if there is addition or  subtraction
	//	If there is return the place of last '+' v '-'
	//------------------------------------------
	for (int i = end; i >= start; i--)
	{
		if (tekst[i] == '+' || tekst[i] == '-')
			if (level == 0)
				return i;

		//	Opening the bracket increases level
		if (tekst[i] == ')')
			level++;

		//	Closing the bracket decreases level
		if (tekst[i] == '(')
			level--;
	}


	//------------------------------------------
	//	Loop that checks if there is multiplication or division
	//	Return the place of LAST operation to do
	//------------------------------------------
	for (int i = end; i >= start; i--)
	{

		// If there is '*' or '/' return the place of this char
		if (tekst[i] == '*' || tekst[i] == '/')
			if (level == 0)
				return i;


		//	Opening the bracket increases level
		if (tekst[i] == ')')
		{
			level++;

			//	Return the place of ')' when multiplication like ") 2" was found
			if (i < end && level == 1)
				if (next_char(tekst, i + 1, end) != -1)
					if (is_number(tekst[previous_char(tekst, i + 1, end)]))
						return i;
		}


		//	Closing the bracket decreases level
		if (tekst[i] == '(') 
		{
			level--;

			//	Return the place of '(' when multiplication like "2 (" or ") (" was found
			if (i > start && level == 0)
				if (previous_char(tekst, start, i - 1) != -1)
					if (is_number(tekst[previous_char(tekst, start, i - 1)]) || tekst[previous_char(tekst, start, i - 1)] == ')')
						return i;
		}
	}


	return -1;
}



//-----------------------------------------------------------------
//	Function check next non-whitespace character 
//
//	Return - the place of following char
//	Return -	-1	in case when there are only whitespace char in searched range
//-----------------------------------------------------------------
int C_Calculator::next_char(const char* text, int start, int end) 
{
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
int C_Calculator::previous_char(const char* text, int start, int end) 
{
	for (int i = end; i >= start; i--)
		if (text[i] != ' ')
			return i;

	return -1;
}



//-----------------------------------------------------------------
//	Return TRUE - '0'-'9' v '.' v ','
//
//	Return FALSE - other characters
//-----------------------------------------------------------------
bool C_Calculator::is_number(char c) 
{
	if (('0' <= c && c <= '9') || c == '.' || c == ',')
		return true;

	return false;
}



//-----------------------------------------------------------------
//
//	Funtion check if there are outside parentheses
//	e.g (2+2)	v	(4*2)
//	
//-----------------------------------------------------------------
bool C_Calculator::are_parentheses(const char* text, int start, int end, int& left, int& right)
{
	left = -1; right = -1;
	for (int i = start; i <= end; i++) 
	{
		if (text[i] == ' ') continue;


		//We find '(' - now we're looking ')' from the other side
		if (text[i] == '(') 
		{
			left = i;
			for (int j = end; j > i; j--)
			{
				if (text[j] == ' ') continue;


				//We find ')' - return true
				if (text[j] == ')')
				{
					right = j;
					return true;
				}


				// Last non-whitespace character isn't rigth bracket - return false
				return false;
			}
		}


		// First non-whitespace character isn't left bracket - return false
		return false;
	}


	//	There are no parentheses - return false;
	return false;
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

	for (int i = start; i <= end; i++) 
	{
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