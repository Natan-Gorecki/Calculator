#pragma once

//Calling Convenion
//__cdecl v __stdcall
#ifndef CC
    #define CC __cdecl
#endif

// pragma comment and dllimport/dllexport
#ifdef CALCULATOR
    #define DSPEC dllexport
#elif CALCULATOR_STATIC
    #define DSPEC
#else
    #if USE_DLL
        #define DSPEC dllimport
        #ifdef _MSC_VER
            #pragma comment(lib, "CalculatorDynamic")
        #else
            #pragma comment(lib, "CalculatorDynamic_BCC")
        #endif
    #elif USE_STATIC_LIB
        #define DSPEC
        #ifdef _MSC_VER
            #pragma comment(lib, "CalculatorStatic")
        #else
            #pragma comment(lib, "CalculatorStatic_BCC")
        #endif
    #endif 
#endif

// extern "C" __declspec()
#if defined(CALCULATOR) || defined(USE_DLL)
    #define EXPORT extern "C" __declspec(DSPEC)
#else
    #define EXPORT extern "C"
#endif


#include "ICalculator.h"
#include "ExpressionException.h"


//-----------------------------------------------------------------------------------------------------
//  Export functions
//
EXPORT CalculatorCore::ICalculator* CC CreateCalculator();
EXPORT void CC DeleteCalculator(CalculatorCore::ICalculator* calculator);
//
//-----------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------
//  Typedefs
//
using create_calculator = CalculatorCore::ICalculator* (CC*)();
using delete_calculator = void (CC*)(CalculatorCore::ICalculator*);
//
//-----------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------
//  Error Callback
//
typedef void (CC* ErrorCallback)(const char* message);

EXPORT void CC SetErrorCallback(ErrorCallback callback);
typedef void (CC* set_error_callback)(ErrorCallback);
//
//-----------------------------------------------------------------------------------------------------
