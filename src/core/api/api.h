#pragma once

//Calling Convenion
//__cdecl v __stdcall
#define CC __cdecl


// pragma comment and dllimport/dllexport
#ifdef CALCULATOR
	#define DSPEC dllexport
#elif CALCULATOR_STATIC
	#define DSPEC
#else
	#if USE_DLL
		#define DSPEC dllimport
		#ifdef _MSC_VER
			#pragma comment(lib, "Calculator")
		#else
			#pragma comment(lib, "Calculator_BCC")
		#endif
	#elif USE_STATIC_LIB
		#define DSPEC
		#ifdef _MSC_VER
			#pragma comment(lib, "StaticLibrary")
		#else
			#pragma	comment(lib, "StaticLibrary_BCC")
		#endif
	#endif 
#endif


// extern "C" __declspec()
#if defined(CALCULATOR) || defined(USE_DLL)
	#define EXPORT extern "C" __declspec(DSPEC)
#else
	#define EXPORT extern "C"
#endif


#include "I_Calculator.h"


//-----------------------------------------------------------------------------------------------------
//	Export functions
//
EXPORT I_Calculator* CC CreateCalculator();
EXPORT void CC DeleteCalculator(I_Calculator* calculator);
//
//-----------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------
//	Typedefs
//
typedef I_Calculator* (CC* create_calculator)();
typedef void (CC* delete_calculator)(I_Calculator*);
//
//-----------------------------------------------------------------------------------------------------