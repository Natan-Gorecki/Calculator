//-----------------------------------------------------------------------------------------------------
//
//  USE STATIC LIBRARY "StaticLibrary.lib"
//  #define USE_STATIC_LIB 1
//
//-----------------------------------------------------------------------------------------------------
//
//  USE DLL "Calculator.dll" WITH LINKING LIBRARY "Calculator.lib"
//  #define USE_DLL 1
//
//-----------------------------------------------------------------------------------------------------
//
//  ifndef USE_DLL || USE_STATIC    =>    DYNAMIC LINK LIBRARY "Calculator.dll"
//

#include <iostream>
#include <Windows.h>
#include <string>

#include "api.h"

using namespace std;

int main()
{
    //-----------------------------------------------------------------------------------------------------
    //  Get export functions from dll without using linking library
    //
    #if !(USE_DLL || USE_STATIC_LIB)
        HMODULE hModule = LoadLibrary(L"CalculatorDynamic");

        if (hModule == 0)
        {
            cout << "Error loading DLL!!!" << endl;
            cin.get();
            return EXIT_FAILURE;
        }

        create_calculator CreateCalculator = (create_calculator)GetProcAddress(hModule, "CreateCalculator");
        delete_calculator DeleteCalculator = (delete_calculator)GetProcAddress(hModule, "DeleteCalculator");
    #endif
    //-----------------------------------------------------------------------------------------------------
    


    //******************************************************************************************************
    ICalculator* calculator = CreateCalculator();
    //******************************************************************************************************



    string inputLine, text = "";
    while (true) 
    {
        cout << "Welcome in our simple caluclator :)" << endl;
        cout << "Enter \"exit\" to close program." << endl << endl << endl;
        cout << "Give your equation to solve:" << endl;

        getline(cin, inputLine);

        text = (text == "\n") ? text = inputLine : text += inputLine;


        // Word "Exit" closes the program
        if (text == "exit") break;


        //-----------------------------------------------------------------
        try 
        {
            cout << "Result:   " << calculator->calculate(text.c_str()) << endl;
        }
        catch (const ExpressionException& ex)
        {
            cout << "Expression: '" << ex.getExpression() << "'" << endl;
            cout << "Exception: '" << ex.what() << "'" << endl;
            cout << "Position: " << ex.getPosition() << " ('" << text.at(ex.getPosition()) << "')" << endl;
        }
        //-----------------------------------------------------------------


        text = getchar();
        system("cls");
    }



    //******************************************************************************************************
    DeleteCalculator(calculator);
    //******************************************************************************************************
    


    //-----------------------------------------------------------------------------------------------------
    //  Free library from the address space of calling process
    //
    #if !(USE_DLL || USE_STATIC_LIB)
        if (hModule != 0)
        {
            FreeLibrary(hModule);
        }
    #endif
    //-----------------------------------------------------------------------------------------------------


    return EXIT_SUCCESS;
}
