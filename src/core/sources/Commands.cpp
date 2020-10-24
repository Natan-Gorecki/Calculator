#include "Commands.h"

//-----------------------------------------------------------------
//	Command representing single number
//-----------------------------------------------------------------
C_NumberCommand::C_NumberCommand(double number)
{
	this->_number = number;
}

double C_NumberCommand::Execute()
{
	return this->_number;
}



//-----------------------------------------------------------------
//	Command representing addition
//-----------------------------------------------------------------
C_AddCommand::C_AddCommand(C_Command* left, C_Command* right)
{
	this->_left = left;
	this->_right = right;
}

C_AddCommand::~C_AddCommand()
{
	delete _left,
	delete _right;
}

double C_AddCommand::Execute()
{
	return _left->Execute() + _right->Execute();
}



//-----------------------------------------------------------------
//	Command representing subtraction
//-----------------------------------------------------------------
C_SubtractCommand::C_SubtractCommand(C_Command* left, C_Command* right)
{
	this->_left = left;
	this->_right = right;
}

C_SubtractCommand::~C_SubtractCommand()
{
	delete _left;
	delete _right;
}

double C_SubtractCommand::Execute()
{
	return _left->Execute() - _right->Execute();
}



//-----------------------------------------------------------------
//	Command representing multiplication
//-----------------------------------------------------------------
C_MultiplyCommand::C_MultiplyCommand(C_Command* left, C_Command* right)
{
	this->_left = left;
	this->_right = right;
}

C_MultiplyCommand::~C_MultiplyCommand()
{
	delete _left;
	delete _right;
}

double C_MultiplyCommand::Execute()
{
	return _left->Execute() * _right->Execute();
}



//-----------------------------------------------------------------
//	Command representing division
//-----------------------------------------------------------------
C_DivideCommand::C_DivideCommand(C_Command* left, C_Command* right)
{
	this->_left = left;
	this->_right = right;
}

C_DivideCommand::~C_DivideCommand()
{
	delete _left;
    delete _right;
}

double C_DivideCommand::Execute()
{
	double divisor = _right->Execute();
	
	if (divisor == 0)
		throw "Division by 0!";
	
	return _left->Execute() / divisor;
}