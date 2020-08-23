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
#include <libloaderapi.h>



int main()
{
	//-----------------------------------------------------------------------------------------------------
	//	Get export functions from dll without using linking library
	//
	#if !(USE_DLL || USE_STATIC_LIB)
		HMODULE h_dll = LoadLibrary(L"Calculator");

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
	I_Calculator* calculator = CreateCalculator();
	//******************************************************************************************************



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