//-----------------------------------------------------------------------------------------------------
//
//  USE STATIC LIBRARY "CalculatorStatic.lib"
//  #define USE_STATIC 1
//
//-----------------------------------------------------------------------------------------------------
//
//  USE DLL "CalculatorDynamic.dll" WITH LINKING LIBRARY "CalculatorDynamic.lib"
//  #define USE_DYNAMIC 1
//
//-----------------------------------------------------------------------------------------------------
//
//  ifndef USE_DYNAMIC || USE_STATIC    =>    DYNAMIC LINK LIBRARY "CalculatorDynamic.dll"
//
//-----------------------------------------------------------------------------------------------------

#include <array>
#include <iostream>
#include <string>
#include <Windows.h>

#include "api.h"

using namespace std;
using namespace CalculatorCore;

int main()
{
    array<string, 7> screenLines = 
    {
        "Welcome in calculator console application.",
        "Enter \"exit\" to close program.",
        "",
        "",
        "",
        "",
        "Please enter your equation:"
    };

    //-----------------------------------------------------------------------------------------------------
    //  Get export functions from dll without using linking library
    //
    #if !(USE_DYNAMIC || USE_STATIC)
        auto hModule = LoadLibrary(L"CalculatorDynamic");

        if (!hModule)
        {
            cout << "Error loading DLL!!!" << endl;
            cin.get();
            return EXIT_FAILURE;
        }

        auto Calculator_Create = (TCalculator_Create)GetProcAddress(hModule, "Calculator_Create");
        auto Calculator_Delete = (TCalculator_Delete)GetProcAddress(hModule, "Calculator_Delete");
    #endif
    //-----------------------------------------------------------------------------------------------------


    //******************************************************************************************************
    ICalculator* calculator = Calculator_Create();
    //******************************************************************************************************


    while (true)
    {
        for (const auto& screenLine : screenLines)
        {
            cout << screenLine << endl;
        }

        string input;
        getline(cin, input);

        // Word "Exit" closes the program
        if (input == "exit")
        {
            break;
        }

        //-----------------------------------------------------------------
        try 
        {
            auto result = calculator->calculate(input.c_str());
            screenLines[3] = "";
            screenLines[4] = "";
            screenLines[5] = "Result: " + to_string(result);
        }
        catch (const ExpressionException& ex)
        {
            screenLines[3] = "Expression: '" + string(ex.getExpression()) + "'";
            screenLines[4] = "Exception: '" + string(ex.what()) + "'";
            screenLines[5] = "Position: " + to_string(ex.getPosition()) + " ('" + input.at(ex.getPosition()) + "')";
        }
        //-----------------------------------------------------------------

        system("cls");
    }


    //******************************************************************************************************
    Calculator_Delete(calculator);
    //******************************************************************************************************


    //-----------------------------------------------------------------------------------------------------
    //  Free library from the address space of calling process
    //
    #if !(USE_DYNAMIC || USE_STATIC)
        if (hModule)
        {
            FreeLibrary(hModule);
        }
    #endif
    //-----------------------------------------------------------------------------------------------------


    return EXIT_SUCCESS;
}
