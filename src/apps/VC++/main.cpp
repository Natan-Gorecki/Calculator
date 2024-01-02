//-----------------------------------------------------------------------------------------------------
//
//	USE STATIC LIBRARY "StaticLibrary.lib"
//	#define USE_STATIC_LIB 1
//
//-----------------------------------------------------------------------------------------------------
//
//	USE DLL "Calculator.dll" WITH LINKING LIBRARY "Calculator.lib"
//	#define USE_DLL 1
//
//-----------------------------------------------------------------------------------------------------
//
//	ifndef USE_DLL || USE_STATIC	=>	DYNAMIC LINK LIBRARY "Calculator.dll"
//



#include "api.h"

#include <iostream>
#include <Windows.h>
#include <string>



int main()
{
	//-----------------------------------------------------------------------------------------------------
	//	Get export functions from dll without using linking library
	//
	#if !(USE_DLL || USE_STATIC_LIB)
		HMODULE h_dll = LoadLibrary(L"CalculatorShared");

		if (h_dll == 0) 
		{
			std::cout << "Error loading DLL !!!\n";
			std::cin.get();
			return 1;
		}

		create_calculator  CreateCalculator = (create_calculator)GetProcAddress(h_dll, "CreateCalculator");
		delete_calculator  DeleteCalculator = (delete_calculator)GetProcAddress(h_dll, "DeleteCalculator");
	#endif
	//-----------------------------------------------------------------------------------------------------
	


	//******************************************************************************************************
	ICalculator* calculator = CreateCalculator();
	//******************************************************************************************************



	std::string from_getline, text = "";
	while (true) 
	{
		std::cout << "Welcome in our simple caluclator :)\n";
		std::cout << "Enter \"exit\" to close program.\n\n" << std::endl;
		std::cout << "Give your equation to solve: \n";

		getline(std::cin, from_getline);

		text = (text == "\n") ? text = from_getline : text += from_getline;


		// Word "Exit" closes the program
		if (text == "exit")	break;


		//-----------------------------------------------------------------
		try 
		{
			std::cout << "Result:   " << calculator->Calculate(text.c_str()) << std::endl;
		}
		catch (const char* exception)
		{
			std::cout << "Exception - " << exception << std::endl;
		}
		//-----------------------------------------------------------------


		text = getchar();
		system("cls");
	}



	//******************************************************************************************************
	DeleteCalculator(calculator);
	//******************************************************************************************************
	


	//-----------------------------------------------------------------------------------------------------
	//	Free library from the adress space of calling process
	//
	#if !(USE_DLL || USE_STATIC_LIB)
		if (h_dll != 0)
			FreeLibrary(h_dll);
	#endif
	//-----------------------------------------------------------------------------------------------------


	return 0;
}