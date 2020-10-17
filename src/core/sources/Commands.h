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
class C_Command
{
public:
	virtual double CC Execute() = 0;
	virtual ~C_Command() {};
};



//-----------------------------------------------------------------
//	Command representing single number
//-----------------------------------------------------------------
class C_NumberCommand : C_Command
{
public:
	virtual double CC Execute();

public:
	C_NumberCommand(double number);
	virtual ~C_NumberCommand() {};

private:
	double _number;
};



//-----------------------------------------------------------------
//	Command representing addition
//-----------------------------------------------------------------
class C_AddCommand : C_Command
{
public:
	virtual double CC Execute();

public:
	C_AddCommand(C_Command* left, C_Command* right);
	virtual ~C_AddCommand();

private:
	C_Command* _left;
	C_Command* _right;
};



//-----------------------------------------------------------------
//	Command representing subtraction
//-----------------------------------------------------------------
class C_SubtractCommand : C_Command
{
public:
	virtual double CC Execute();

public:
	C_SubtractCommand(C_Command* left, C_Command* right);
	virtual ~C_SubtractCommand();

private:
	C_Command* _left;
	C_Command* _right;
};



//-----------------------------------------------------------------
//	Command representing multiplication
//-----------------------------------------------------------------
class C_MultiplyCommand : C_Command
{
public:
	virtual double CC Execute();

public:
	C_MultiplyCommand(C_Command* left, C_Command* right);
	virtual ~C_MultiplyCommand();

private:
	C_Command* _left;
	C_Command* _right;
};



//-----------------------------------------------------------------
//	Command representing division
//-----------------------------------------------------------------
class C_DivideCommand : C_Command
{
public:
	virtual double CC Execute();

public:
	C_DivideCommand(C_Command* left, C_Command* right);
	virtual ~C_DivideCommand();

private:
	C_Command* _left;
	C_Command* _right;
};
