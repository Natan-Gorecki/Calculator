object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 770
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object dxLayoutControl_Main: TdxLayoutControl
    Left = 0
    Top = 0
    Width = 635
    Height = 770
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 336
    ExplicitTop = 152
    ExplicitWidth = 300
    ExplicitHeight = 250
    object Button_RightBracket: TcxButton
      Left = 321
      Top = 154
      Width = 143
      Height = 90
      Caption = ')'
      TabOrder = 8
    end
    object Button_C: TcxButton
      Left = 22
      Top = 154
      Width = 143
      Height = 90
      Caption = 'C'
      TabOrder = 6
    end
    object Button_Divide: TcxButton
      Left = 470
      Top = 154
      Width = 143
      Height = 90
      Caption = #247
      TabOrder = 9
    end
    object Button_LeftBracket: TcxButton
      Left = 171
      Top = 154
      Width = 144
      Height = 90
      Caption = '('
      TabOrder = 7
    end
    object Button_Minus: TcxButton
      Left = 470
      Top = 406
      Width = 143
      Height = 90
      Caption = '-'
      TabOrder = 17
    end
    object Button_5: TcxButton
      Left = 171
      Top = 406
      Width = 144
      Height = 90
      Caption = '5'
      TabOrder = 15
    end
    object Button_6: TcxButton
      Left = 321
      Top = 406
      Width = 143
      Height = 90
      Caption = '6'
      TabOrder = 16
    end
    object Button_4: TcxButton
      Left = 22
      Top = 406
      Width = 143
      Height = 90
      Caption = '4'
      TabOrder = 14
    end
    object Button_2: TcxButton
      Left = 171
      Top = 532
      Width = 144
      Height = 90
      Caption = '2'
      TabOrder = 19
    end
    object Button_3: TcxButton
      Left = 321
      Top = 532
      Width = 143
      Height = 90
      Caption = '3'
      TabOrder = 20
    end
    object Button_1: TcxButton
      Left = 22
      Top = 532
      Width = 143
      Height = 90
      Caption = '1'
      TabOrder = 18
    end
    object Button_Plus: TcxButton
      Left = 470
      Top = 532
      Width = 143
      Height = 90
      Caption = '+'
      TabOrder = 21
    end
    object Button_Clear: TcxButton
      Left = 22
      Top = 658
      Width = 143
      Height = 90
      TabOrder = 22
    end
    object Button_0: TcxButton
      Left = 171
      Top = 658
      Width = 144
      Height = 90
      Caption = '0'
      TabOrder = 23
    end
    object Button_Comma: TcxButton
      Left = 321
      Top = 658
      Width = 143
      Height = 90
      Caption = ','
      TabOrder = 24
    end
    object Button_Equal: TcxButton
      Left = 470
      Top = 658
      Width = 143
      Height = 90
      Caption = '='
      TabOrder = 25
    end
    object Button_7: TcxButton
      Left = 22
      Top = 280
      Width = 143
      Height = 90
      Caption = '7'
      TabOrder = 10
    end
    object Button_8: TcxButton
      Left = 171
      Top = 280
      Width = 144
      Height = 90
      Caption = '8'
      TabOrder = 11
    end
    object Button_Multiply: TcxButton
      Left = 470
      Top = 280
      Width = 143
      Height = 90
      Caption = 'x'
      TabOrder = 13
    end
    object Button_9: TcxButton
      Left = 321
      Top = 280
      Width = 143
      Height = 90
      Caption = '9'
      TabOrder = 12
    end
    object Button_MC: TcxButton
      Left = 122
      Top = 28
      Width = 93
      Height = 90
      Caption = 'MC'
      TabOrder = 1
    end
    object Button_MPlus: TcxButton
      Left = 321
      Top = 28
      Width = 93
      Height = 90
      Caption = 'M+'
      TabOrder = 3
    end
    object Button_CE: TcxButton
      Left = 22
      Top = 28
      Width = 94
      Height = 90
      Caption = 'CE'
      TabOrder = 0
    end
    object Button_MS: TcxButton
      Left = 520
      Top = 28
      Width = 93
      Height = 90
      Caption = 'MS'
      TabOrder = 5
    end
    object Button_MMinus: TcxButton
      Left = 420
      Top = 28
      Width = 94
      Height = 90
      Caption = 'M-'
      TabOrder = 4
    end
    object Button_MR: TcxButton
      Left = 221
      Top = 28
      Width = 94
      Height = 90
      Caption = 'MR'
      TabOrder = 2
    end
    object dxRootGroup: TdxLayoutGroup
      AlignHorz = ahClient
      AlignVert = avClient
      ButtonOptions.Buttons = <>
      Hidden = True
      ItemIndex = 2
      ShowBorder = False
      Index = -1
    end
    object Item_RightBracket: TdxLayoutItem
      Parent = dxLayoutGroup2
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'cxButton1'
      CaptionOptions.Visible = False
      Control = Button_RightBracket
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object Item_C: TdxLayoutItem
      Parent = dxLayoutGroup2
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'cxButton2'
      CaptionOptions.Visible = False
      Control = Button_C
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object Item_Divide: TdxLayoutItem
      Parent = dxLayoutGroup2
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_Divide
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object Item_5: TdxLayoutItem
      Parent = dxLayoutGroup4
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_5
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object Item_Minus: TdxLayoutItem
      Parent = dxLayoutGroup4
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'cxButton5'
      CaptionOptions.Visible = False
      Control = Button_Minus
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object Item_LeftBracket: TdxLayoutItem
      Parent = dxLayoutGroup2
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'cxButton4'
      CaptionOptions.Visible = False
      Control = Button_LeftBracket
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object Item_6: TdxLayoutItem
      Parent = dxLayoutGroup4
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_6
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object Item_4: TdxLayoutItem
      Parent = dxLayoutGroup4
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_4
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object Item_2: TdxLayoutItem
      Parent = dxLayoutGroup5
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_2
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object Item_3: TdxLayoutItem
      Parent = dxLayoutGroup5
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_3
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object Item_1: TdxLayoutItem
      Parent = dxLayoutGroup5
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_1
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object Item_Plus: TdxLayoutItem
      Parent = dxLayoutGroup5
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_Plus
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object Item_Clear: TdxLayoutItem
      Parent = dxLayoutGroup6
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_Clear
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object Item_0: TdxLayoutItem
      Parent = dxLayoutGroup6
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_0
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object Item_Comma: TdxLayoutItem
      Parent = dxLayoutGroup6
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_Comma
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object Item_Equal: TdxLayoutItem
      Parent = dxLayoutGroup6
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_Equal
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object Item_7: TdxLayoutItem
      Parent = dxLayoutGroup3
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_7
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object Item_8: TdxLayoutItem
      Parent = dxLayoutGroup3
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_8
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object Item_Multiply: TdxLayoutItem
      Parent = dxLayoutGroup3
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_Multiply
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object Item_9: TdxLayoutItem
      Parent = dxLayoutGroup3
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_9
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object Item_MC: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_MC
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object Item_MPlus: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_MPlus
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object Item_CE: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_CE
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object Item_MS: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_MS
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 5
    end
    object Item_MMinus: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_MMinus
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 4
    end
    object Item_MR: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Visible = False
      Control = Button_MR
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object dxLayoutGroup2: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      AlignVert = avClient
      ButtonOptions.Buttons = <>
      ItemIndex = 3
      LayoutDirection = ldHorizontal
      Index = 1
    end
    object dxLayoutGroup4: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      AlignVert = avClient
      ButtonOptions.Buttons = <>
      ItemIndex = 3
      LayoutDirection = ldHorizontal
      Index = 3
    end
    object dxLayoutGroup5: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      AlignVert = avClient
      ButtonOptions.Buttons = <>
      ItemIndex = 3
      LayoutDirection = ldHorizontal
      Index = 4
    end
    object dxLayoutGroup6: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      AlignVert = avClient
      ButtonOptions.Buttons = <>
      ItemIndex = 3
      LayoutDirection = ldHorizontal
      Index = 5
    end
    object dxLayoutGroup3: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      AlignVert = avClient
      ButtonOptions.Buttons = <>
      ItemIndex = 3
      LayoutDirection = ldHorizontal
      Index = 2
    end
    object dxLayoutGroup1: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      AlignVert = avClient
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      Index = 0
    end
  end
end
