//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Window.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutControlAdapters"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinProject1"
#pragma link "dxSkins"
#pragma link "dxSkinsCore"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxBar"
#pragma link "dxBarExtItems"
#pragma link "cxContainer"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "cxImageList"
#pragma link "dxSkinsForm"
#pragma link "dxSkinsCore"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkins"
#pragma link "dxLayoutLookAndFeels"
#pragma link "Custom_VCL_Skins"
#pragma resource "*.dfm"
TForm1 *Form1;

//------------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
#if !(defined(USE_DLL) || defined(USE_STATIC_LIB))
// Use LoadLibraryA function to load "Calculator.dll"

	HMODULE h_dll = LoadLibraryA("Calculator");

	if (h_dll == NULL)
		Label_Expression->Caption = "Error loading Calculator.DLL !!!";
	else
	{
		create_calculator CreateCalculator = (create_calculator)GetProcAddress(h_dll, "CreateCalculator");

		if(CreateCalculator)
		{
#endif

			//*********************************************
			this->calculator = CreateCalculator();
			//*********************************************

#if !(defined(USE_DLL) || defined(USE_STATIC_LIB))
		}
		else
		{
			Label_Expression->Caption = "Address to CreateCalculator() function is not valid !!!";
		}
	}
#endif
}

//------------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
#if !(defined(USE_DLL) || defined(USE_STATIC_LIB))
	HMODULE h_dll = LoadLibraryA("Calculator");

	if (h_dll)
	{
		delete_calculator DeleteCalculator = (delete_calculator)GetProcAddress(h_dll, "DeleteCalculator");

		if(DeleteCalculator)
		{
#endif

			//*********************************************
			DeleteCalculator(this->calculator);
			this->calculator = NULL;
			//*********************************************

#if !(defined(USE_DLL) || defined(USE_STATIC_LIB))
		}

		FreeLibrary(h_dll);
	}
#endif
}

//------------------------------------------------------------------------------

void __fastcall TForm1::Button_Click(TObject *Sender)
{
	int tag = dynamic_cast<TcxButton*>(Sender)->Tag;

	switch(tag) {
	case 10: // Clear Button
	{
		// Remove digit/sign and whitespace character (2 characters)
		if(Label_Expression->Caption.Length()>1 && Label_Expression->Caption[Label_Expression->Caption.Length()-1] == ' ')
			Label_Expression->Caption = Label_Expression->Caption.SubString(0, Label_Expression->Caption.Length()-2);

		// Remove digit/sign (1 character)
		else
			Label_Expression->Caption = Label_Expression->Caption.SubString(0, Label_Expression->Caption.Length()-1);

		break;
	}


	case 11: // Comma Button
		Label_Expression->Caption += ",";
		break;


	case 12: // Plus Button
		Label_Expression->Caption += " +";
		break;


	case 13: // Minus Button
		Label_Expression->Caption += " -";
		break;


	case 14: // Multiply Button
		Label_Expression->Caption += " x";
		break;


	case 15: // Divide Button
		Label_Expression->Caption += " �";
		break;


	case 16: // Right Bracket Button
		Label_Expression->Caption += ")";
		break;


	case 17: // Left Bracket Button
		Label_Expression->Caption += " (";
		break;


	case 18: // Button "C"
		Label_Expression->Caption = "";
		break;


	case 19: // Button "CE"
		this->Button_CEClick();
		break;


	//  DEFAULT NUMBER 0-9
	default:
		Label_Expression->Caption += tag;
	}
}

//------------------------------------------------------------------------------

void __fastcall TForm1::Button_CEClick()
{
	if(Label_Expression->Caption.Length() <= 1)
	{
		Label_Expression->Caption = "";
	}
	else
	{
		int char_place = Label_Expression->Caption.Length();


		for(int i = Label_Expression->Caption.Length(); i>=1; i--)
		{
			char c = Label_Expression->Caption[i];
			char_place = i;

			if(c == '+' || c == '-' || c == 'x' || c == '�')
			{
				//--------------------------------------------
				// IF LAST IN EXPRESSION IS OPERATION CHAR - CLEAR THIS CHAR
				if(char_place == Label_Expression->Caption.Length())
					char_place = char_place - 2;
				//--------------------------------------------

				break;
			}

		}


		//---------------------------------
		//  IF IN EXPRESSION IS ONLY NUMBER
		if(char_place == 1)
			Label_Expression->Caption = "";
		//---------------------------------

		else
			Label_Expression->Caption = Label_Expression->Caption.SubString(0, char_place);
    }
}

//------------------------------------------------------------------------------
