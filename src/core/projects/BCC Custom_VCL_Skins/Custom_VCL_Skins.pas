unit Custom_VCL_Skins;

//{$I cxVer.inc}

interface

uses
  Classes, dxCore, dxCoreGraphics, dxGDIPlusApi, cxLookAndFeelPainters, dxSkinsCore, dxSkinsLookAndFeelPainter;

type

  { TdxSkinDefaultPainter }

  TdxSkinDefaultPainter = class(TdxSkinLookAndFeelPainter)
  public
    function LookAndFeelName: string; override;
  end;

  { TdxSkinBlue_ButtonPainter }

  TdxSkinBlue_ButtonPainter = class(TdxSkinLookAndFeelPainter)
  public
    function LookAndFeelName: string; override;
  end;

  { TdxSkinNumber_ButtonPainter }

  TdxSkinNumber_ButtonPainter = class(TdxSkinLookAndFeelPainter)
  public
    function LookAndFeelName: string; override;
  end;

implementation

{$R Custom_VCL_Skins.res}

const
  SkinsCount = 3;
  SkinNames: array[0..SkinsCount - 1] of string = (
    'Default',
    'Blue_Button',
    'Number_Button'
  );
  SkinPainters: array[0..SkinsCount - 1] of TdxSkinLookAndFeelPainterClass = (
    TdxSkinDefaultPainter,
    TdxSkinBlue_ButtonPainter,
    TdxSkinNumber_ButtonPainter
  );


{ TdxSkinDefaultPainter }

function TdxSkinDefaultPainter.LookAndFeelName: string;
begin
  Result := 'Default';
end;

{ TdxSkinBlue_ButtonPainter }

function TdxSkinBlue_ButtonPainter.LookAndFeelName: string;
begin
  Result := 'Blue_Button';
end;

{ TdxSkinNumber_ButtonPainter }

function TdxSkinNumber_ButtonPainter.LookAndFeelName: string;
begin
  Result := 'Number_Button';
end;

//

procedure RegisterPainters;
var
  I: Integer;
begin
  if CheckGdiPlus then
  begin
    for I := 0 to SkinsCount - 1 do
      cxLookAndFeelPaintersManager.Register(SkinPainters[I].Create(SkinNames[I], HInstance));
  end;
end;

procedure UnregisterPainters;
var
  I: Integer;
begin
  if cxLookAndFeelPaintersManager <> nil then
  begin
    for I := 0 to SkinsCount - 1 do
      cxLookAndFeelPaintersManager.Unregister(SkinNames[I]);
  end;
end;

{$IFNDEF DXSKINDYNAMICLOADING}
initialization
  dxUnitsLoader.AddUnit(@RegisterPainters, @UnregisterPainters);
finalization
  dxUnitsLoader.RemoveUnit(@UnregisterPainters);
{$ENDIF}
end.
