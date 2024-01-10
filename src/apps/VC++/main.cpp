//-----------------------------------------------------------------------------------------------------
//
//  USE STATIC LIBRARY "CalculatorStatic.lib"
//  #define USE_STATIC_LIB 1
//
//-----------------------------------------------------------------------------------------------------
//
//  USE DLL "CalculatorDynamic.dll" WITH LINKING LIBRARY "CalculatorDynamic.lib"
//  #define USE_DLL 1
//
//-----------------------------------------------------------------------------------------------------
//
//  ifndef USE_DLL || USE_STATIC    =>    DYNAMIC LINK LIBRARY "CalculatorDynamic.dll"
//
//-----------------------------------------------------------------------------------------------------

#include <array>
#include <iostream>
#include <string>
#include <Windows.h>

#include "api.h"

using namespace std;

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
    #if !(USE_DLL || USE_STATIC_LIB)
        auto hModule = LoadLibrary(L"CalculatorDynamic");

        if (!hModule)
        {
            cout << "Error loading DLL!!!" << endl;
            cin.get();
            return EXIT_FAILURE;
        }

        auto CreateCalculator = (create_calculator)GetProcAddress(hModule, "CreateCalculator");
        auto DeleteCalculator = (delete_calculator)GetProcAddress(hModule, "DeleteCalculator");
    #endif
    //-----------------------------------------------------------------------------------------------------


    //******************************************************************************************************
    ICalculator* calculator = CreateCalculator();
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
    DeleteCalculator(calculator);
    //******************************************************************************************************


    //-----------------------------------------------------------------------------------------------------
    //  Free library from the address space of calling process
    //
    #if !(USE_DLL || USE_STATIC_LIB)
        if (hModule)
        {
            FreeLibrary(hModule);
        }
    #endif
    //-----------------------------------------------------------------------------------------------------


    return EXIT_SUCCESS;
}
