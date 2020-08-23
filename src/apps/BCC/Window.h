//---------------------------------------------------------------------------

#ifndef WindowH
#define WindowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxButtons.hpp"
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "dxLayoutContainer.hpp"
#include "dxLayoutControl.hpp"
#include "dxLayoutControlAdapters.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinProject1.hpp"
#include "dxSkins.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include <Vcl.Menus.hpp>
#include "dxBar.hpp"
#include "dxBarExtItems.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TdxLayoutGroup *dxRootGroup;
	TdxLayoutControl *dxLayoutControl_Main;
	TcxButton *Button_RightBracket;
	TdxLayoutItem *Item_RightBracket;
	TcxButton *Button_C;
	TdxLayoutItem *Item_C;
	TdxLayoutItem *Item_Divide;
	TcxButton *Button_Divide;
	TcxButton *Button_LeftBracket;
	TcxButton *Button_Minus;
	TdxLayoutItem *Item_5;
	TcxButton *Button_5;
	TdxLayoutItem *Item_Minus;
	TdxLayoutItem *Item_LeftBracket;
	TdxLayoutItem *Item_6;
	TcxButton *Button_6;
	TdxLayoutItem *Item_4;
	TcxButton *Button_4;
	TdxLayoutItem *Item_2;
	TcxButton *Button_2;
	TdxLayoutItem *Item_3;
	TcxButton *Button_3;
	TdxLayoutItem *Item_1;
	TcxButton *Button_1;
	TdxLayoutItem *Item_Plus;
	TcxButton *Button_Plus;
	TdxLayoutItem *Item_Clear;
	TcxButton *Button_Clear;
	TdxLayoutItem *Item_0;
	TcxButton *Button_0;
	TdxLayoutItem *Item_Comma;
	TcxButton *Button_Comma;
	TdxLayoutItem *Item_Equal;
	TcxButton *Button_Equal;
	TdxLayoutItem *Item_7;
	TcxButton *Button_7;
	TdxLayoutItem *Item_8;
	TcxButton *Button_8;
	TdxLayoutItem *Item_Multiply;
	TcxButton *Button_Multiply;
	TdxLayoutItem *Item_9;
	TcxButton *Button_9;
	TdxLayoutItem *Item_MC;
	TcxButton *Button_MC;
	TdxLayoutItem *Item_MPlus;
	TcxButton *Button_MPlus;
	TdxLayoutItem *Item_CE;
	TcxButton *Button_CE;
	TdxLayoutItem *Item_MS;
	TcxButton *Button_MS;
	TdxLayoutItem *Item_MMinus;
	TcxButton *Button_MMinus;
	TdxLayoutItem *Item_MR;
	TcxButton *Button_MR;
	TdxLayoutGroup *dxLayoutGroup2;
	TdxLayoutGroup *dxLayoutGroup4;
	TdxLayoutGroup *dxLayoutGroup5;
	TdxLayoutGroup *dxLayoutGroup6;
	TdxLayoutGroup *dxLayoutGroup3;
	TdxLayoutGroup *dxLayoutGroup1;
	TdxBarManager *dxBarManager1;
	TdxBar *BarManager_MainMenu;
	TdxBar *BarManager_Memory;
	TdxBarSubItem *BarSubItem_Skins;
	TdxBarButton *BarButton_Exit;
	TdxBarButton *BarButton_DefaultSkin;
	TdxBarSeparator *BarSeparator_Skins;
	TdxBarButton *BarButton_Blueprint;
	TdxBarButton *BarButton_DevExpressDarkStyle;
	TdxBarButton *BarButton_DevExpressStyle;
	TdxBarButton *BarButton_HighContrast;
	TdxBarButton *BarButton_Office2016Dark;
	TdxBarButton *BarButton_Pumpkin;
	TdxBarButton *BarButton_Xmas2008Blue;
	TdxBarStatic *BarStatic_MemoryLabel;
	TdxBarStatic *BarStatic_Memory;
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
