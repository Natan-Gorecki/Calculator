# Calculator

Simple project using C++ technology consists of:
* Calculator DLL and Static Library built with MSVC++ compiler
* Console Application that uses project classes to demonstrate their means
* GUI application created in Embarcadero C++ Builder (CLANG complier). Default skin is based on Windows calculator. 

## Description

This project was my first more complex project. Its structure and operation is intended to illustrate a few things: 
* use of interfaces in C++ 
* creating code for interoperating between different compilers (MSVC++ and Boreland Clang)
* creating a GUI using C++ Builder and DevExpress Components
* creating Dynamic-Link and Static Libraries
* unit tests using MS CppUnitTestFramework

## Api.h

The file includes export functions and necessary definitions

``` C++
EXPORT I_Calculator* CC CreateCalculator();
EXPORT void CC DeleteCalculator(I_Calculator* calculator);
```

## I_Calculator.h

Calculator interface has one method Calculate that returns a result for an expression passed in text
form (const char\*) or throws an const char\* exception with an explanatory message. An example of use is ConsoleApplication project (or BCC GUI application).

``` C++
class I_Calculator 
{
public:
	virtual double CC Calculate(const char* expression) = 0;
	virtual ~I_Calculator() {};
};
```

## Structure

``` 
+-- out
|   +-- bin
|       +-- x86
|           +-- Debug
|           +-- Release
|       +-- x64
|           +-- Debug
|           +-- Release
|   +-- lib
|       +-- x86
|           +-- Debug
|           +-- Release
|       +-- x64
|           +-- Debug
|           +-- Release
+-- src
|   +-- apps
|       +-- BCC (GUI application)
|       +-- VC++ (Console Application with VS solution file)
|   +-- core
|       +-- api
|       +-- projects
|           +-- BCC Custom_VCL_Skins
|           +-- BCC StaticLib
|           +-- Calculator.Tests
|           +-- VS DLL
|           +-- VS StaticLib
|       +-- sources
|       +-- tests
```
