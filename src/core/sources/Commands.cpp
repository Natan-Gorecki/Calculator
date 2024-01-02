#include "Commands.h"

//-----------------------------------------------------------------
//	Command representing single number
//-----------------------------------------------------------------
NumberCommand::NumberCommand(double number)
{
	this->_number = number;
}

double NumberCommand::Execute()
{
	return this->_number;
}



//-----------------------------------------------------------------
//	Command representing addition
//-----------------------------------------------------------------
AddCommand::AddCommand(Command* left, Command* right)
{
	this->_left = left;
	this->_right = right;
}

AddCommand::~AddCommand()
{
	delete _left,
	delete _right;
}

double AddCommand::Execute()
{
	return _left->Execute() + _right->Execute();
}



//-----------------------------------------------------------------
//	Command representing subtraction
//-----------------------------------------------------------------
SubtractCommand::SubtractCommand(Command* left, Command* right)
{
	this->_left = left;
	this->_right = right;
}

SubtractCommand::~SubtractCommand()
{
	delete _left;
	delete _right;
}

double SubtractCommand::Execute()
{
	return _left->Execute() - _right->Execute();
}



//-----------------------------------------------------------------
//	Command representing multiplication
//-----------------------------------------------------------------
MultiplyCommand::MultiplyCommand(Command* left, Command* right)
{
	this->_left = left;
	this->_right = right;
}

MultiplyCommand::~MultiplyCommand()
{
	delete _left;
	delete _right;
}

double MultiplyCommand::Execute()
{
	return _left->Execute() * _right->Execute();
}



//-----------------------------------------------------------------
//	Command representing division
//-----------------------------------------------------------------
DivideCommand::DivideCommand(Command* left, Command* right)
{
	this->_left = left;
	this->_right = right;
}

DivideCommand::~DivideCommand()
{
	delete _left;
    delete _right;
}

double DivideCommand::Execute()
{
	double divisor = _right->Execute();
	
	if (divisor == 0)
		throw "Division by 0!";
	
	return _left->Execute() / divisor;
}