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
		Label_Expression->Caption += " ÷";
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
		if(PreviousCharIsSign() == true)
			Label_Expression->Caption += " ";
		Label_Expression->Caption += tag;
	}
}

//------------------------------------------------------------------------------

void __fastcall TForm1::Button_EqualClick(TObject *Sender)
{
	// Only if calculator is correctly initalized
	if(this->calculator)
	{
		AnsiString ansi = Label_Expression->Caption;


		// Changing characters 'x' to '*' and '÷' to '/'
		// Function Calculate from Calculator library requires the second
		for(int i=1; i<= ansi.Length(); i++)
		{
			if(ansi[i] == 'x') ansi[i] = '*';
			if(ansi[i] == '÷') ansi[i] = '/';
		}


		Label_PreviousExpression->Caption = Label_Expression->Caption + " =   ";


		try
		{
			result = this->calculator->Calculate(ansi.c_str());
			Label_Expression->Caption = result;
		}
		catch(...)
		{
			result = 0;
			Label_Expression->Caption = "Invalid format!";
		}
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

			if(c == '+' || c == '-' || c == 'x' || c == '÷')
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

void __fastcall TForm1::Memory_Click(TObject *Sender)
{
	Button_MC->Enabled = true;
	Button_MR->Enabled = true;

	int tag = dynamic_cast<TcxButton*>(Sender)->Tag;

	switch(tag)
	{

	case 1: // MC Button
	{
		memory = 0;

		Button_MC->Enabled = false;
		Button_MR->Enabled = false;

		break;
	}


	case 2: // MR Button
		this->Button_MRClick();
		break;


	case 3: // M+ Button
		memory += result;
		break;


	case 4: // M- Button
		memory -= result;
		break;


	case 5: // MS Button
		memory = result;
		break;
	}


	if(memory == 0)
	{
		BarStatic_Memory->Caption = "";
		BarStatic_MemoryLabel->Enabled = false;
	}
	else
	{
		BarStatic_Memory->Caption = memory;
		BarStatic_MemoryLabel->Enabled = true;
	}
}

//------------------------------------------------------------------------------

void __fastcall TForm1::Button_MRClick()
{
	Label_PreviousExpression->Caption = "";


	//--------------------------------------------------------
	//  Insert number from memory to expression after last sign
	//
	if(PreviousCharIsSign() == true)
	{
		result = 0;
		Label_Expression->Caption = Label_Expression->Caption + " " + memory;
	}
	//--------------------------------------------------------


	//--------------------------------------------------------
	//  If last in expression isn't sign character
	//  	- clear expression and insert number from memory
	//
	else
	{
		result = memory;
		Label_Expression->Caption = memory;


		Button_MPlus->Enabled = true;
		Button_MMinus->Enabled = true;
		Button_MS->Enabled = true;
	}
	//--------------------------------------------------------
}

//------------------------------------------------------------------------------
//  TRUE - if previous character in Expression is '+' or '-' or 'x' or '÷'
//
//  FALSE -  if previous character in Expression is number or bracket
//
bool TForm1::PreviousCharIsSign()
{
	if(Label_Expression->Caption.Length() > 1)
	{
		for (int i = Label_Expression->Caption.Length(); i >= 1; i--)
		{
			char c = Label_Expression->Caption[i];

			if(c == '+' || c == '-' || c == 'x' || c == '÷')
				return true;

			if(c != ' ')
				return false;
		}
	}


  return false;
}
