#include "Parser.h"



double Parser::Parse(const char* expression)
{
	std::string exp = std::string(expression);
	CheckIfExpressionIsCorrect(exp);
	return this->Parse(exp);
}



//------------------------------------------------------------------------------
//
//	Function calculating the result
//
//------------------------------------------------------------------------------
double Parser::Parse(std::string text)
{
	int char_place = OperationOutsideParentheses(text);

	// If there is operation oustide patentheses => char_place = the place of LAST operation to do
	if (char_place != -1)
	{

		//	e.g. +2 v *4
		if (char_place == 0)
			goto first_in_equation;



		//-----------------------------------------------------------
		//	Conditon functions:
		//		* throw exception for text like "**" or "+/" 
		//		* throw exception for text like "*2" or "/4"
		//		* +(part_of_equation) => return  1 * part_of_equation
		//		* -(part_of_equation) => return -1 * part_of_equation
		//-----------------------------------------------------------
		if (char_place > 0)
		{

			// We're checking multiplied operation char
			// e.g ++, *+
			if (PreviousChar(text, 0, char_place - 1) != -1)
			{
				char temp_ch = text[PreviousChar(text, 0, char_place - 1)];
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

				case '+':
					return Parse(text.substr(char_place + 1, text.length() - char_place));

				case '-':
					return -1 * Parse(text.substr(char_place + 1, text.length() - char_place));

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
		//		* throw exception for text like "2*"
		//		* throw exception for text like "2 *   "
		//-----------------------------------------------------------
		if (char_place == (int)text.length()-1)
			throw "Operation char at the end";
		if (char_place < (int)text.length() - 1)
			if (NextChar(text, char_place + 1, text.length() - 1) == -1)
				throw "Operation char at the end";



		//---------------------------------------------------------------------------------------
		//	Switch statement function:
		//		* we have place of LAST operation to do in variable char_place
		//		* we do this operation on two parts of the eqation separated by char_place
		//---------------------------------------------------------------------------------------
		std::string left = text.substr(0, char_place);
		std::string right = text.substr(char_place + 1, text.length() - (char_place+1));
		switch (text[char_place])
		{
		case '+':	
			return Parse(left) + Parse(right);

		case '-':
			return Parse(left) - Parse(right);

		case '*':	
			return Parse(left) * Parse(right);

		case '/':
			return Parse(left) / Parse(right);

		case '(':
			return Parse(left) * Parse(text.substr(char_place, text.length() - char_place));

		case ')':
			return Parse(text.substr(0, char_place+1)) * Parse(right);
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
	std::string inner_expression = InsideParentheses(text);
	if (inner_expression != "")
		return Parse(inner_expression);



	//-----------------------------------------------------------
	//	We have only number
	//-----------------------------------------------------------
	std::string result;
	int count_of_dot = 0;


	//-----------------------------------------------------------
	//	Convert part of equation from char[] to double 
	//-----------------------------------------------------------
	for (int i = 0; i <= (int)text.length() - 1; i++)
	{
		if ('0' <= text[i] && text[i] <= '9')
			result += text[i];
		if (text[i] == '.' || text[i] == ',')
		{
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
//	Function find	LAST	operation to do
//
//	Return the place, where find this operation
//------------------------------------------------------------------------------
int Parser::OperationOutsideParentheses(std::string text)
{
	// We're looking for operation ONLY OUTSIDE parentheses
	// Level must have value 0
	int level = 0;


	//------------------------------------------
	//	Loop that checks if there is addition or  subtraction
	//	If there is return the place of last '+' v '-'
	//------------------------------------------
	for (int i = text.length() - 1; i >= 0; i--)
	{
		if (text[i] == '+' || text[i] == '-')
			if (level == 0)
				return i;

		//	Opening the bracket increases level
		if (text[i] == ')')
			level++;

		//	Closing the bracket decreases level
		if (text[i] == '(')
			level--;
	}


	//------------------------------------------
	//	Loop that checks if there is multiplication or division
	//	Return the place of LAST operation to do
	//------------------------------------------
	for (int i = text.length() - 1; i >= 0; i--)
	{

		// If there is '*' or '/' return the place of this char
		if (text[i] == '*' || text[i] == '/')
			if (level == 0)
				return i;


		//	Opening the bracket increases level
		if (text[i] == ')')
		{
			level++;

			//	Return the place of ')' when multiplication like ") 2" was found
			if (i < (int)text.length() - 1 && level == 1)
				if (NextChar(text, i + 1, text.length() - 1) != -1)
					if (IsNumber(text[PreviousChar(text, i + 1, text.length() - 1)]))
						return i;
		}


		//	Closing the bracket decreases level
		if (text[i] == '(')
		{
			level--;

			//	Return the place of '(' when multiplication like "2 (" or ") (" was found
			if (i > 0 && level == 0)
				if (PreviousChar(text, 0, i - 1) != -1)
					if (IsNumber(text[PreviousChar(text, 0, i - 1)]) || text[PreviousChar(text, 0, i - 1)] == ')')
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
int Parser::NextChar(std::string text, int start, int end)
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
int Parser::PreviousChar(std::string text, int start, int end)
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
bool Parser::IsNumber(char c)
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
std::string Parser::InsideParentheses(std::string text)
{
	int left = -1, right = -1;
	for (int i = 0; i <= (int)text.length() - 1; i++)
	{
		if (text[i] == ' ') continue;


		//We find '(' - now we're looking ')' from the other side
		if (text[i] == '(')
		{
			left = i;
			for (int j = text.length() - 1; j > i; j--)
			{
				if (text[j] == ' ') continue;


				//We find ')' - return true
				if (text[j] == ')')
				{
					right = j;
					return text.substr(left + 1, right - left - 1);
				}


				// Last non-whitespace character isn't rigth bracket - return false
				return "";
			}
		}


		// First non-whitespace character isn't left bracket - return false
		return "";
	}


	//	There are no parentheses - return false;
	return "";
}



//-----------------------------------------------------------------
//
//	Funtion checking if the equation is correct
//
//-----------------------------------------------------------------
void Parser::CheckIfExpressionIsCorrect(std::string text)
{
	if (CorrectParentheses(text) == false)
		throw "Invalid parentheses";

	if (EmptyParentheses(text) == true)
		throw "Empty parentheses";

	if (CorrectCharacters(text) == false)
		throw "Invalid character";

	if (text.empty())
		throw "Empty equation";
}



//-----------------------------------------------------------------
//
//	Funtion checking if the number and position of parentheses is correct
//
//-----------------------------------------------------------------
bool Parser::CorrectParentheses(std::string text)
{
	int counter = 0;

	for (int i = 0; i <= (int)text.length() - 1; i++)
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
bool Parser::CorrectCharacters(std::string text)
{
	for (int i = 0; i <= (int)text.length() - 1; i++)
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
bool Parser::EmptyParentheses(std::string text)
{
	for (int i = 0; i <= (int)text.length()-1; i++)
	{
		if (text[i] == '(')
		{
			if (NextChar(text, i + 1, text.length() - 1) != -1)
			{
				if (text[NextChar(text, i + 1, text.length() - 1)] == ')')
					return true;
			}
		}
	}
		

	return false;
}