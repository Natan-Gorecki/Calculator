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

