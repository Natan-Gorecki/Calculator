#pragma once

//Calling Convenion
//__cdecl v __stdcall
#ifndef CC
    #define CC __cdecl
#endif

// pragma comment and dllimport/dllexport
#ifdef CALCULATOR_DYNAMIC
    #define DSPEC dllexport
#elif CALCULATOR_STATIC
    #define DSPEC
#else
    #if USE_DYNAMIC
        #define DSPEC dllimport
        #pragma comment(lib, "CalculatorDynamic")
    #elif USE_STATIC
        #define DSPEC
        #pragma comment(lib, "CalculatorStatic")
    #endif 
#endif

// extern "C" __declspec()
#if defined(CALCULATOR_DYNAMIC) || defined(USE_DYNAMIC)
    #define EXPORT extern "C" __declspec(DSPEC)
#else
    #define EXPORT extern "C"
#endif


#include "ICalculator.h"
#include "ExpressionException.h"


//-----------------------------------------------------------------------------------------------------
//  Export functions
//
EXPORT CalculatorCore::ICalculator* CC Calculator_Create();
EXPORT void CC Calculator_Delete(CalculatorCore::ICalculator* calculator);
//
//-----------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------
//  Typedefs
//
using TCalculator_Create = CalculatorCore::ICalculator* (CC*)();
using TCalculator_Delete = void (CC*)(CalculatorCore::ICalculator*);
//
//-----------------------------------------------------------------------------------------------------
