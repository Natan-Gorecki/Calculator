object Form1: TForm1
  Left = 0
  Top = 0
  Margins.Left = 0
  Margins.Top = 0
  Margins.Right = 0
  Margins.Bottom = 0
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = 'Calculator'
  ClientHeight = 543
  ClientWidth = 515
  Color = 15132390
  Constraints.MinHeight = 500
  Constraints.MinWidth = 360
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object dxLayoutControl_Main: TdxLayoutControl
    Left = 0
    Top = 24
    Width = 515
    Height = 519
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentBackground = True
    ParentFont = False
    TabOrder = 0
    Transparent = True
    LayoutLookAndFeel = dxLayoutSkinLookAndFeel1
    object Button_RightBracket: TcxButton
      Tag = 16
      Left = 258
      Top = 182
      Width = 126
      Height = 67
      Caption = ')'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 10
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_C: TcxButton
      Tag = 18
      Left = 2
      Top = 182
      Width = 127
      Height = 67
      Caption = 'C'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 8
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_Divide: TcxButton
      Tag = 15
      Left = 385
      Top = 182
      Width = 128
      Height = 67
      Caption = #247
      LookAndFeel.SkinName = 'Blue_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 11
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_LeftBracket: TcxButton
      Tag = 17
      Left = 130
      Top = 182
      Width = 127
      Height = 67
      Caption = '('
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 9
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_Minus: TcxButton
      Tag = 13
      Left = 385
      Top = 317
      Width = 128
      Height = 66
      Caption = '-'
      LookAndFeel.SkinName = 'Blue_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 19
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_5: TcxButton
      Tag = 5
      Left = 130
      Top = 317
      Width = 127
      Height = 66
      Caption = '5'
      LookAndFeel.SkinName = 'Number_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 17
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_6: TcxButton
      Tag = 6
      Left = 258
      Top = 317
      Width = 126
      Height = 66
      Caption = '6'
      LookAndFeel.SkinName = 'Number_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 18
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_4: TcxButton
      Tag = 4
      Left = 2
      Top = 317
      Width = 127
      Height = 66
      Caption = '4'
      LookAndFeel.SkinName = 'Number_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 16
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_2: TcxButton
      Tag = 2
      Left = 130
      Top = 384
      Width = 127
      Height = 66
      Caption = '2'
      LookAndFeel.SkinName = 'Number_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_3: TcxButton
      Tag = 3
      Left = 258
      Top = 384
      Width = 126
      Height = 66
      Caption = '3'
      LookAndFeel.SkinName = 'Number_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 22
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_1: TcxButton
      Tag = 1
      Left = 2
      Top = 384
      Width = 127
      Height = 66
      Caption = '1'
      LookAndFeel.SkinName = 'Number_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 20
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_Plus: TcxButton
      Tag = 12
      Left = 385
      Top = 384
      Width = 128
      Height = 66
      Caption = '+'
      LookAndFeel.SkinName = 'Blue_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 23
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_Clear: TcxButton
      Tag = 10
      Left = 2
      Top = 451
      Width = 127
      Height = 66
      OptionsImage.ImageIndex = 0
      OptionsImage.Images = cxImageList1
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 24
      OnClick = Button_Click
    end
    object Button_0: TcxButton
      Left = 130
      Top = 451
      Width = 127
      Height = 66
      Caption = '0'
      LookAndFeel.SkinName = 'Number_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_Comma: TcxButton
      Tag = 11
      Left = 258
      Top = 451
      Width = 126
      Height = 66
      Caption = ','
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 26
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_Equal: TcxButton
      Left = 385
      Top = 451
      Width = 128
      Height = 66
      Caption = '='
      LookAndFeel.SkinName = 'Blue_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Button_7: TcxButton
      Tag = 7
      Left = 2
      Top = 250
      Width = 127
      Height = 66
      Caption = '7'
      LookAndFeel.SkinName = 'Number_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 12
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_8: TcxButton
      Tag = 8
      Left = 130
      Top = 250
      Width = 127
      Height = 66
      Caption = '8'
      LookAndFeel.SkinName = 'Number_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 13
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_Multiply: TcxButton
      Tag = 14
      Left = 385
      Top = 250
      Width = 128
      Height = 66
      Caption = 'x'
      LookAndFeel.SkinName = 'Blue_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 15
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_9: TcxButton
      Tag = 9
      Left = 258
      Top = 250
      Width = 126
      Height = 66
      Caption = '9'
      LookAndFeel.SkinName = 'Number_Button'
      SpeedButtonOptions.CanBeFocused = False
      TabOrder = 14
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_MC: TcxButton
      Left = 76
      Top = 156
      Width = 75
      Height = 25
      Caption = 'MC'
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Transparent = True
      TabOrder = 3
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button_MPlus: TcxButton
      Left = 226
      Top = 156
      Width = 75
      Height = 25
      Caption = 'M+'
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Transparent = True
      TabOrder = 5
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button_CE: TcxButton
      Tag = 19
      Left = 1
      Top = 156
      Width = 75
      Height = 25
      Caption = 'CE'
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Transparent = True
      TabOrder = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      OnClick = Button_Click
    end
    object Button_MS: TcxButton
      Left = 376
      Top = 156
      Width = 75
      Height = 25
      Caption = 'MS'
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Transparent = True
      TabOrder = 7
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button_MMinus: TcxButton
      Left = 301
      Top = 156
      Width = 75
      Height = 25
      Caption = 'M-'
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Transparent = True
      TabOrder = 6
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button_MR: TcxButton
      Left = 151
      Top = 156
      Width = 75
      Height = 25
      Caption = 'MR'
      SpeedButtonOptions.CanBeFocused = False
      SpeedButtonOptions.Transparent = True
      TabOrder = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label_Expression: TcxLabel
      Left = 168
      Top = 56
      Caption = 'Expression'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -37
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.HotTrack = False
      Style.IsFontAssigned = True
      Transparent = True
    end
    object Label_PreviousExpression: TcxLabel
      Left = 333
      Top = 27
      Caption = 'PreviousExpression'
      ParentFont = False
      Style.Font.Charset = DEFAULT_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -21
      Style.Font.Name = 'Tahoma'
      Style.Font.Style = []
      Style.HotTrack = False
      Style.IsFontAssigned = True
      Transparent = True
    end
    object dxRootGroup: TdxLayoutGroup
      AlignHorz = ahClient
      AlignVert = avClient
      ButtonOptions.Buttons = <>
      Hidden = True
      ItemIndex = 4
      Padding.Bottom = -9
      Padding.Left = -9
      Padding.Right = -9
      Padding.Top = -9
      Padding.AssignedValues = [lpavBottom, lpavLeft, lpavRight, lpavTop]
      ShowBorder = False
      UseIndent = False
      Index = -1
    end
    object Item_RightBracket: TdxLayoutItem
      Parent = dxLayoutGroup2
      AlignHorz = ahClient
      AlignVert = avClient
      CaptionOptions.Text = 'cxButton1'
      CaptionOptions.Visible = False
      Offsets.Left = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
      Offsets.Right = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
      Offsets.Right = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
      Offsets.Right = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
      Offsets.Right = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
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
      Offsets.Left = 1
      Offsets.Right = 1
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
      Offsets.Left = 1
      Control = Button_9
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object Item_MC: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avCenter
      CaptionOptions.Visible = False
      SizeOptions.MaxWidth = 75
      Control = Button_MC
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object Item_MPlus: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avCenter
      CaptionOptions.Visible = False
      SizeOptions.MaxWidth = 75
      Control = Button_MPlus
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object Item_CE: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avCenter
      CaptionOptions.Visible = False
      SizeOptions.MaxWidth = 75
      Control = Button_CE
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 0
    end
    object Item_MS: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avCenter
      CaptionOptions.Visible = False
      SizeOptions.MaxWidth = 75
      Control = Button_MS
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 5
    end
    object Item_MMinus: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avCenter
      CaptionOptions.Visible = False
      SizeOptions.MaxWidth = 75
      Control = Button_MMinus
      ControlOptions.OriginalHeight = 25
      ControlOptions.OriginalWidth = 75
      ControlOptions.ShowBorder = False
      Index = 4
    end
    object Item_MR: TdxLayoutItem
      Parent = dxLayoutGroup1
      AlignHorz = ahClient
      AlignVert = avCenter
      CaptionOptions.Visible = False
      SizeOptions.MaxWidth = 75
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
      Offsets.Bottom = 1
      ButtonOptions.Buttons = <>
      ItemIndex = 3
      LayoutDirection = ldHorizontal
      ShowBorder = False
      UseIndent = False
      Index = 6
    end
    object dxLayoutGroup4: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      AlignVert = avClient
      Offsets.Bottom = 1
      ButtonOptions.Buttons = <>
      ItemIndex = 3
      LayoutDirection = ldHorizontal
      ShowBorder = False
      UseIndent = False
      Index = 8
    end
    object dxLayoutGroup5: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      AlignVert = avClient
      Offsets.Bottom = 1
      ButtonOptions.Buttons = <>
      ItemIndex = 3
      LayoutDirection = ldHorizontal
      ShowBorder = False
      UseIndent = False
      Index = 9
    end
    object dxLayoutGroup6: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      AlignVert = avClient
      Offsets.Bottom = 1
      ButtonOptions.Buttons = <>
      ItemIndex = 3
      LayoutDirection = ldHorizontal
      ShowBorder = False
      UseIndent = False
      Index = 10
    end
    object dxLayoutGroup3: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      AlignVert = avClient
      Offsets.Bottom = 1
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      ShowBorder = False
      UseIndent = False
      Index = 7
    end
    object dxLayoutGroup1: TdxLayoutGroup
      Parent = dxRootGroup
      AlignHorz = ahClient
      Offsets.Bottom = 1
      ButtonOptions.Buttons = <>
      LayoutDirection = ldHorizontal
      ShowBorder = False
      UseIndent = False
      Index = 5
    end
    object Item_Expression: TdxLayoutItem
      Parent = dxRootGroup
      AlignHorz = ahCenter
      CaptionOptions.Text = 'cxLabel1'
      CaptionOptions.Visible = False
      Control = Label_Expression
      ControlOptions.OriginalHeight = 49
      ControlOptions.OriginalWidth = 178
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object Item_PreviousExpression: TdxLayoutItem
      Parent = dxRootGroup
      AlignHorz = ahRight
      CaptionOptions.Text = 'cxLabel2'
      CaptionOptions.Visible = False
      Control = Label_PreviousExpression
      ControlOptions.OriginalHeight = 29
      ControlOptions.OriginalWidth = 181
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object Item_EmptySpace1: TdxLayoutEmptySpaceItem
      Parent = dxRootGroup
      AlignVert = avClient
      CaptionOptions.Text = 'Empty Space Item'
      SizeOptions.Height = 10
      SizeOptions.Width = 10
      Index = 0
    end
    object Item_EmptySpace2: TdxLayoutEmptySpaceItem
      Parent = dxRootGroup
      AlignVert = avClient
      CaptionOptions.Text = 'Empty Space Item'
      SizeOptions.Height = 10
      SizeOptions.Width = 10
      Index = 3
    end
    object Item_EmptySpace3: TdxLayoutEmptySpaceItem
      Parent = dxRootGroup
      AlignVert = avClient
      CaptionOptions.Text = 'Empty Space Item'
      SizeOptions.Height = 10
      SizeOptions.Width = 10
      Index = 4
    end
  end
  object dxBarManager1: TdxBarManager
    AllowReset = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    CanCustomize = False
    Categories.Strings = (
      'Default')
    Categories.ItemsVisibles = (
      2)
    Categories.Visibles = (
      True)
    PopupMenuLinks = <>
    UseSystemFont = True
    Left = 8
    Top = 40
    PixelsPerInch = 96
    DockControlHeights = (
      0
      0
      24
      0)
    object BarManager_MainMenu: TdxBar
      AllowClose = False
      AllowCustomizing = False
      AllowQuickCustomizing = False
      AllowReset = False
      Caption = 'MainMenu'
      CaptionButtons = <>
      DockedDockingStyle = dsTop
      DockedLeft = 0
      DockedTop = 0
      DockingStyle = dsTop
      FloatLeft = 663
      FloatTop = 2
      FloatClientWidth = 0
      FloatClientHeight = 0
      IsMainMenu = True
      ItemLinks = <
        item
          Visible = True
          ItemName = 'BarSubItem_Skins'
        end
        item
          Visible = True
          ItemName = 'BarButton_Exit'
        end>
      MultiLine = True
      OneOnRow = False
      Row = 0
      ShowMark = False
      UseOwnFont = False
      Visible = True
      WholeRow = False
    end
    object BarManager_Memory: TdxBar
      AllowClose = False
      AllowCustomizing = False
      AllowQuickCustomizing = False
      AllowReset = False
      Caption = 'Memory'
      CaptionButtons = <>
      DockedDockingStyle = dsTop
      DockedLeft = 117
      DockedTop = 0
      DockingStyle = dsTop
      FloatLeft = 663
      FloatTop = 2
      FloatClientWidth = 0
      FloatClientHeight = 0
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ItemLinks = <
        item
          Visible = True
          ItemName = 'BarStatic_MemoryLabel'
        end
        item
          Visible = True
          ItemName = 'BarStatic_Memory'
        end>
      OneOnRow = False
      Row = 0
      ShowMark = False
      UseOwnFont = True
      Visible = True
      WholeRow = False
    end
    object BarSubItem_Skins: TdxBarSubItem
      Caption = 'Skins'
      Category = 0
      Visible = ivAlways
      ItemLinks = <
        item
          Visible = True
          ItemName = 'BarButton_DefaultSkin'
        end
        item
          Visible = True
          ItemName = 'BarSeparator_Skins'
        end
        item
          Visible = True
          ItemName = 'BarButton_Blueprint'
        end
        item
          Visible = True
          ItemName = 'BarButton_DevExpressDarkStyle'
        end
        item
          Visible = True
          ItemName = 'BarButton_DevExpressStyle'
        end
        item
          Visible = True
          ItemName = 'BarButton_HighContrast'
        end
        item
          Visible = True
          ItemName = 'BarButton_Office2016Dark'
        end
        item
          Visible = True
          ItemName = 'BarButton_Pumpkin'
        end
        item
          Visible = True
          ItemName = 'BarButton_Xmas2008Blue'
        end>
    end
    object BarButton_Exit: TdxBarButton
      Caption = 'Exit'
      Category = 0
      Hint = 'Exit'
      Visible = ivAlways
    end
    object BarButton_DefaultSkin: TdxBarButton
      Caption = 'Default'
      Category = 0
      Hint = 'Default'
      Visible = ivAlways
    end
    object BarSeparator_Skins: TdxBarSeparator
      Category = 0
      Visible = ivAlways
      ShowCaption = False
    end
    object BarButton_Blueprint: TdxBarButton
      Caption = 'Blueprint'
      Category = 0
      Hint = 'Blueprint'
      Visible = ivAlways
    end
    object BarButton_DevExpressDarkStyle: TdxBarButton
      Caption = 'DevExpressDarkStyle'
      Category = 0
      Hint = 'DevExpressDarkStyle'
      Visible = ivAlways
    end
    object BarButton_DevExpressStyle: TdxBarButton
      Caption = 'DevExpressStyle'
      Category = 0
      Hint = 'DevExpressStyle'
      Visible = ivAlways
    end
    object BarButton_HighContrast: TdxBarButton
      Caption = 'HighContrast'
      Category = 0
      Hint = 'HighContrast'
      Visible = ivAlways
    end
    object BarButton_Office2016Dark: TdxBarButton
      Caption = 'Office2016Dark'
      Category = 0
      Hint = 'Office2016Dark'
      Visible = ivAlways
    end
    object BarButton_Pumpkin: TdxBarButton
      Caption = 'Pumpkin'
      Category = 0
      Hint = 'Pumpkin'
      Visible = ivAlways
    end
    object BarButton_Xmas2008Blue: TdxBarButton
      Caption = 'Xmas2008Blue'
      Category = 0
      Hint = 'Xmas2008Blue'
      Visible = ivAlways
    end
    object BarStatic_MemoryLabel: TdxBarStatic
      Caption = 'Memory'
      Category = 0
      Hint = 'Memory'
      Visible = ivAlways
    end
    object BarStatic_Memory: TdxBarStatic
      Category = 0
      Visible = ivAlways
    end
  end
  object cxImageList1: TcxImageList
    SourceDPI = 400
    Height = 110
    Width = 128
    FormatVersion = 1
    DesignInfo = 32768008
    ImageInfo = <
      item
        ImageClass = 'TdxPNGImage'
        Image.Data = {
          89504E470D0A1A0A0000000D49484452000000800000006E0806000000EF701B
          39000000017352474200AECE1CE90000000467414D410000B18F0BFC61050000
          00097048597300000EC300000EC301C76FA8640000070449444154785EED9D59
          A86E6318C78F793CE6292E4CC95887284389435C208A2232854B4352860B642A
          AE2845A14C71816426992E7061BE301517328513991DB3FFAF7356F6393DEF59
          EB5DEB1DD6FAF6F3AB5FEDF6FEBEB5D6B7F6F3BDE3F3BE6B81E3388EE3388EE3
          388EE3388EE3388EE3388EE3E46223B98F3C542E76B3CA3D5E243794D5D954DE
          2497C87FE4BF6E11B9D75FC91BE44259852DE4DBD2BA40B79CAFCAE241B0867C
          545A17E496F77A59944BA575216E1D3F97C5A021F287B42EC4AD236D82226C23
          8936EB22DCBA66672DF9BCB44EEED6373BD74AEBC4EE38CCCA51F22F699D38E4
          7792F101B7BF4BA5756F2DB3B183FC465A270DF9885C533AC378405AF7D7320B
          EBCA57A475C2901FC9ADA4339CEA0170A3B44E16F25779A074D25035004E927F
          4BEB6496F445CF954E3AAA05C0EEF25B699D28E4FD922162271D55028069C637
          A4759290EF4B66069DB4140F80D5E51DD23A41C81FE4DED2494FF100384BC6D4
          FBBC96F73879281A007C8BF9365B070F4969B19ACC01C79DCA58022527A6A658
          006C26DF93D68143BE29379029E19F7E90BC4B7E283F93AFCBABE5B6724C3046
          72867C467EB25C7EE677EBC8141409005AEEF749EBA02119E6DD4DA6847FFE95
          F277699DF34B79A41C0304231363561A1CBFE36F9BCBA1140980F3A4F5414252
          EF9F2853738A6C6B7FFC22CF91B9AA9D2EEC29299DACEB9BEB4372E875660F00
          8ADB9FA575C0908C0EE6A06B7E219352D749A6A74B7384EC3A2F4230EF228790
          350018AF67DCDE3A58481210A9FB524363EF37699DD39212EB5E592A359A6F32
          BD9DD82FCB717208D902801BCE8C9D75A090443E3383B9E89369F492244B2927
          DCABABE49FD2BA865539745E245B005C2663EA7D3E3C39013921B3D53A779BD4
          C7D4CB39A097738F8CB9578D5CD7D06A2A4B001C2E638A5BA4CECD0DAB8BA862
          ACF3B7C92289C3644AB6962F48EB7C6D7E2F53CC8A260F80EDE4A7D23A40C8E7
          E4DAB20404416CD5D4480FE14C99A287401797F90DEB3C6D727FF79329481A00
          0C4E3C2BAD37876420A6F4000CC526CBCDFA14BBF410A8AF878C20B2F6EE6B69
          1DBF4D06C7B697A94816007C2BAE91D61B43322093BA58ED0AD77B81ECD3F022
          70EE96EBCB1838E7A99292C43A6E9B8FCBD433A2C902E018197B3359FD539B63
          65ECFC44E38BB26B6A1AE3F897CB9889B04602EE6699A39A4C12003BCAD8228D
          757F639988D957C6B65B1A3F906D43D6EBC93BA5F5FE36592175A1CC31110483
          0380419B97A5F586901FCB2DE598A05EA57EB5AEB74D7A0887480BC6EBFB2E76
          F9519E2073322800A8D362933AA9FF0E90636463F998B4AEBB4D92554F93737B
          080CD3F66DE9D338DE5FE666500030611353A7519731313466E8C950DFF6A9AB
          E92150CF33FB79B0A464B05ED7E65B72275982DE01B0AB64CAD67A61C8A92475
          52DF5E24FBAC5026C89F92B163FA8D4FCA14D3BC5DE915004C90C4D697EFCAA9
          257552FF32E2667D9ED452E2DC2A53257A74253A00A8E36E97D60B42D2CD6283
          A729427BA56F0FA1AB8C875C2C6B948ED101C05068CC081A917DB69C323BCB5C
          7B15D1D26781CCDCC66349A2028019B19FE6FCA28BB7C95C7DD89290D3F884B4
          3E635F999E2661A6265101F0F04ABF6893C51F4CBECC0A0CE8DC22FBF41056F6
          1D39349B27055101407165FDC1921EC21E72D6A09EBE44C6EE65305726CCD802
          6F0C440540CC98B90740D8C906406C1540BEBD5701B693AC02BC11687FC6BE4E
          AE1108DE0D4CEBA4BA81E00341E99DD440103014CC8485F5A290531C0A3E5EFA
          50F0FFAE804F06D9CE8BC9A0069F0E5ED179351D0CB4073C216499F33221043C
          256C593EE4BC4C096BF0A4D05533D349A10D47CBF99616CEC2514F0B5F0E75DF
          D416869C2FA7B63064139992640100BE34AC1B33B934ACC11787766326178736
          50ACFBF2F076862E0F4F3191942500A0CF0611342473C24310AD73B7E91B442C
          330AEAC8316D1143B13D8B5BC40C2D05B20500F82651DD2140676A93A806DF26
          2E8E99DA26AE612C1B459E2CDB066268E9D7DE28722FD965A3C807E5D0EB2C12
          00CC8E8D65ABD82B6468ABD82FA46F151B7610E4D49114621D3824831E39368B
          6677ADB99B45BF266984951E906AA3D92CFA69D96C16CDCFA7CB548923C50200
          C6B85DFC14125480B9841C1342450300FC8111E3A2780010C57D924AFD913179
          281E00E00F8D1A0F550200FCB171E3A05A00409F07478E3DA9746A540D00E8F3
          E8D8DACBA96689EA01405F37F6E1D12495FAC3A3D3503D00C01F1F5F8F510400
          F0B088D835F70C172F7107B9545AF7D6323BB149A56E59B343914E7EA07572B7
          BE4520FBA64FE68E9BDF622C96A1295BB78E8CC114855543D685B875A4542E0A
          43BEAC1FB42EC62D2F8FDC2B0E5BA9E5DA9BC7ED2E89BA0B651598016419177D
          D698BC427798DC6B16C3F0CDAFF6CF9F0BAB7AD8688A75753412DD7C728F17C9
          5229F18EE3388EE3388EE3388EE3388EE3388EE3384E5D162CF80FFA4C889B37
          6C88200000000049454E44AE426082}
      end
      item
        ImageClass = 'TdxPNGImage'
        Image.Data = {
          89504E470D0A1A0A0000000D49484452000000800000006E0806000000EF701B
          39000000017352474200AECE1CE90000000467414D410000B18F0BFC61050000
          00097048597300000EC300000EC301C76FA8640000090449444154785EED9D6B
          685C4518869B36B51A2F58ADC5FB8D222A529482567F54BC20227803154428FE
          D0A84851A8581564EB05A4923F822851AA4841496C89368854C11463A4924B63
          B2D9246D2E4DB76DD2369B6CB69BBD24D9E83BC9BB52AD353367E75C76FD1E38
          246DCEF7CD9CF9DE33977366E62C120441100441100441100441100441100441
          1004570887C317C7E3F17B3B3B3B1F94C3FD43957528143A8FC5EF1F5555552B
          90996D535353E93F044F51659E4AA53EAFABAB3B9FE1F096C3870F5F994C267B
          981FC12732994C787272F27286C51B50FD944F4F4F37330F82CFE472B91D0C8D
          3720F8D54C5B08080C8DFB64B3D92799A61020181E77999D9DBD098774F80208
          43E41E48A3026D4DEF7C7242D06098DC0377FE374C4B08200C933B20F82F331D
          6D6093C331234741C72C8B7341182AFB60AC7F0BAAFE134C478B743AFD1BF27E
          2E5D080EC168EB6716E982D0C42E8944620582DFCF34B4989A9A3ABE67CF1E6F
          1F4C94287E0BA06C6666C6B8DD8F4422F7D15E28105F0570E2C4898DF4AD0D6C
          DEA7B96001DF04108D46D7A2EA9FA66F2D3299CC6EFC584A1782057C11406363
          E372247C907EB5C0F9C343434397D28560093F04B0389BCDFE449F5A2093D923
          478EACA3BD6011CF05303C3CBC89FEB489C5629B682E58C65301F4F6F6AE4382
          19FAD30243BE069896CD7BB08EF25B3EFF6BE059CCC32A9E0960EFDEBD97A1EA
          1FA62F2D30448C86C3E10BE8C21665C78F1F7F249148D4435C09F5340CF93A32
          3E3EFE31D25AC57302416D6DED39F178FC0D8C7CDAF8D46E46FD8EBCBFBE6BD7
          AEB3795A41782280EAEAEAA59393930DF4A385BAD8919191DBE9C20A0D0D0DE5
          18497CCA244E21954A8D2593C96778BAAF6CDFBEFD2A94591BB3760AC86B6B24
          12B984A73BC6130140C5EFD38736B8C057686E0D045FABFF811AE13D9CEE56B3
          B3201825AD49A7D387989DD3821AF2779C5E503E5D1700AAFEFB70376BBF7050
          E0C2EAF1C37A00E0333E978006681EBE3E78F0E05934F58CB6B6B68791B6F67B
          1194D5E3347584AB02A8ABABBB0277D331DA6B91CBE506F163055D58031ABC63
          3E057D50B8BF62D4B2922EDCA6ACBBBBFB25A469F4700C6CA6BD23DC144039AA
          F13DB4D502178F666F720DEDAD02019CCD648C502FAAD0E9BA9E6EDCA2FCD0A1
          431F3049235066CFD187235C13007AD51FD24E1B04FF059ABB0282B983491901
          BB71F4BEEFA61BAB6CD9B2E5DC582CB693491981E08FA27FB59CAE1CE18A0086
          86869EA08D36A82DB6D2DC3520B0CBD1BE7632492320822C46084FD39515EAEB
          EB2F83B05A988411A8D1726363630FD39563AC0BE0C0810337A2B02669A30594
          DC87F6CF93C91D6A950BC4F6039336067D9A77E0A6E00E6A6B6BEB6A8C4A86E8
          D608043F09313F4457056155003B77EEAC40014578BE16BCB36EA60B4FA8ACAC
          5C3A3131F109B3600C0AEDCBC1C1C133E9CE989E9E9EFBE1437B44723228AFC3
          A8F6ADF5936C0AA00CC1AFE5B9DA20F8EB69EF35EA89E0265595322B46A0D66A
          84882EA42F5DCAA2D1E8B34AF4746304D2EC40B57F257D59C19A00D096BDC8F3
          B44115F819CD7D03BDEFC751B02966C90804723F44701D5D2DC46274F6DEA3A9
          31C8E3F710ACF566D28A00FAFBFB57E34E9AE1795A20E1D6502874065DF8CAFE
          FDFB6F477E46983523208218FA14FFF9AABABABABA02355D0D4D8C41DE3E528F
          B1E9CE2A050B40BDAC41CFDA683107D41C4767F11ABA0804E894AD4AA7D3DDCC
          A21110410622788AAEFE465B5BDB45A8E99A78AA11B8A96661BB91AE5CA15001
          94E1C28DDB7DB4830FD03E50D4D4D45C803BD5E8A5D5C9205821B8F96B84D0DB
          DB7B036E0EA319CF79107BF550EC51BA728D820480C27A957FD306EDE0BB340F
          241B366C58863C7EC1EC1A83806FDBB76FDFB2BEBEBE7B50B863FC6F2350A30C
          A3A77F2BB3E42A8E0580DEE83A55F5F16F5A40D16A72C792790F8166316AA9CD
          AA0A66D68D8008DA4DCB260F9AC7AEF1F1F1AB990FD7712400F4462F85A1D1E4
          0E9C7F4CEDF8411745412412598F7C3B0AA413209C1F4747473DDD97C75800E8
          F49D01951AB593B81BA68F1E3D7AFF9C8322A3B9B9F9AE6C363BCA4B710D04FF
          D3969616CFA7BC1B0B00EDFE9BFCB736A8D2DE9A332E5276EFDE7D039AAF3E5E
          8E75D0917E0DC9589FFFA08391001289C49DFC5D1BD87C8774AC4F66F49AAD5B
          B75E343131F10B2FCB0AE862A420ACC798842F18090055B9D15D8061D181F6F6
          76AF2654B84E65656505FA3F5FF1F20A0265791482B23AE7D1094602E04F6DBA
          BABA6E633AA5C492818101C78F7415E843F56098772DFDF98AAB02C0DD2F02F8
          178A5600D204FCCF9B00E904DAED044204C5D50954381906C662B1B7E78C8B14
          378781EA6163D10C0315F220C81D8AE64190423D0A86088C1F05F7F7F7CBA3E0
          FFA0281E05E7919741A747BD0CC20DE274DA57F05F06E591D7C1A782E0FF3F5E
          0713991072123627844004A830033E21442153C2E67AF2A79D12D6D4D4B412C2
          7034250C2208FC94B0399C4E0A55FB06D085AFC8A4503D68F2EFC8B4F00529DD
          69E14416862C4CE92E0C51A8A561E80FC8D2B00528D5A56173C8E2503D0A591C
          8AF20DE6E2D03C415E1E8E4277B43C1C4D45A096874304C15C1E9E67DCC10611
          18863D4F7357409995DC0611B8D982B7410431DE2286555BA0B68841210FC816
          31F3D0441FD924CA8892DB246A0ED926CE8C92DA262E0F862DB251A40125B551
          A4424D7440DB6E3A89C4FA56B1702B5BC5FE034F04A090CDA2CD511B42239FAF
          630452DC9B45E719181808E276F1C530414551DCDBC5E771F2C108B48745BDB6
          30C8782E00E0E89331E891DF497BC1227E086051474787F147A3D0148CC847A3
          ECE38B0014D168742D3A35C69F8DF363EA7429E39B0014E8D1CA87237DC65701
          803254EDDFD2BF36F2E9587BF82D00F978B4CFF82E0045523E1FEF1B81108002
          C17C99E968039B9C7A3A26474187F68B3A86CA3D9017E34FC90BDEC130B907D2
          A8405360B4C844F00E86C95D500BDC8423CD348500C110B94F369B7D92690A01
          82E1F106F44EAB99AE1010181A6F088542E5104133D3167C067DB31D0C8D77A8
          CDA593C9640FF320F844269309AB35150C8BB7545555AD88C7E3DB501B48C7D0
          635499A752A9CFD56A2A86C33FC2E1F0C510C2BD9D9D9D0FCAE1FEA1CA1ACDB0
          A7FB1509822008822008822008822008822008822008BEB168D19F471BF96A9B
          B940B00000000049454E44AE426082}
      end>
  end
  object dxSkinController1: TdxSkinController
    NativeStyle = False
    SkinName = 'Default'
    Left = 8
    Top = 92
  end
  object dxLayoutLookAndFeelList1: TdxLayoutLookAndFeelList
    Left = 8
    Top = 144
    object dxLayoutSkinLookAndFeel1: TdxLayoutSkinLookAndFeel
      PixelsPerInch = 96
    end
  end
end
