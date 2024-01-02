#pragma once

#ifndef NULL
	#define NULL 0
#endif


#ifndef  CC
	#define CC __cdecl
#endif



//-----------------------------------------------------------------
// Abstract base class with virtual Execute method
//-----------------------------------------------------------------
class Command
{
public:
	virtual double CC Execute() = 0;
	virtual ~Command() {};
};



//-----------------------------------------------------------------
//	Command representing single number
//-----------------------------------------------------------------
class NumberCommand : public Command
{
public:
	virtual double CC Execute();

public:
	NumberCommand(double number);
	virtual ~NumberCommand() {};

private:
	double _number;
};



//-----------------------------------------------------------------
//	Command representing addition
//-----------------------------------------------------------------
class AddCommand : public Command
{
public:
	virtual double CC Execute();

public:
	AddCommand(Command* left, Command* right);
	virtual ~AddCommand();

private:
	Command* _left;
	Command* _right;
};



//-----------------------------------------------------------------
//	Command representing subtraction
//-----------------------------------------------------------------
class SubtractCommand : public Command
{
public:
	virtual double CC Execute();

public:
	SubtractCommand(Command* left, Command* right);
	virtual ~SubtractCommand();

private:
	Command* _left;
	Command* _right;
};



//-----------------------------------------------------------------
//	Command representing multiplication
//-----------------------------------------------------------------
class MultiplyCommand : public Command
{
public:
	virtual double CC Execute();

public:
	MultiplyCommand(Command* left, Command* right);
	virtual ~MultiplyCommand();

private:
	Command* _left;
	Command* _right;
};



//-----------------------------------------------------------------
//	Command representing division
//-----------------------------------------------------------------
class DivideCommand : public Command
{
public:
	virtual double CC Execute();

public:
	DivideCommand(Command* left, Command* right);
	virtual ~DivideCommand();

private:
	Command* _left;
	Command* _right;
};
