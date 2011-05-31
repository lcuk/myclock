VERSION 5.00
Begin VB.UserControl titlebar 
   Alignable       =   -1  'True
   BackColor       =   &H00000000&
   ClientHeight    =   840
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   8160
   BeginProperty Font 
      Name            =   "Trebuchet MS"
      Size            =   9.75
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   ForeColor       =   &H00808080&
   ScaleHeight     =   840
   ScaleWidth      =   8160
   Begin VB.Image imaback 
      Height          =   825
      Left            =   6750
      Top             =   0
      Width           =   1245
   End
   Begin VB.Image iconifiy 
      BorderStyle     =   1  'Fixed Single
      Height          =   645
      Left            =   90
      Picture         =   "titlebar.ctx":0000
      Stretch         =   -1  'True
      Top             =   90
      Width           =   705
   End
   Begin VB.Label lblTitle 
      BackColor       =   &H00000000&
      Caption         =   "Caption Goes Here"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   18
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   420
      Left            =   990
      TabIndex        =   0
      Top             =   180
      Width           =   6720
   End
   Begin VB.Image Image1 
      Height          =   690
      Left            =   45
      Stretch         =   -1  'True
      Top             =   60
      Width           =   915
   End
End
Attribute VB_Name = "titlebar"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

Property Get hWnd() As Long
Attribute hWnd.VB_UserMemId = -515
    hWnd = UserControl.hWnd
End Property


Property Let Caption(arg As String)
    lblTitle = arg
    'lblTitleShadow = arg
    'Label1 = arg
End Property


Property Get Caption() As String
Attribute Caption.VB_UserMemId = 0
    Caption = lblTitle.Caption
End Property

Private Sub UserControl_InitProperties()
    Extender.Align = vbAlignTop
    Caption = "Title Goes Here"
End Sub

Private Sub UserControl_ReadProperties(PropBag As PropertyBag)
    Caption = PropBag.ReadProperty("Caption", "Title Goes Here")
End Sub


Private Sub UserControl_Show()
On Error Resume Next
    Image1.Picture = LoadPicture("AppImage.jpg")
    UserControl_Resize
End Sub

Private Sub UserControl_WriteProperties(PropBag As PropertyBag)
    Call PropBag.WriteProperty("Caption", Caption, "Title Goes Here")
End Sub



Private Sub UserControl_Resize()
On Error Resume Next
    Height = 840
    imaback.Move 0, 0, ScaleWidth, ScaleHeight
    
    'Frame1.Move 90, ScaleHeight - Frame1.Height - 45, ScaleWidth - 180
    
    Const xs = 20
    Const ys = 20
    
    lblTitle.Width = ScaleWidth - lblTitle.Left
    
    'Label1.Move lblTitle.Left - xs, lblTitle.Top - ys, lblTitle.Width
    'lblTitleShadow.Move lblTitle.Left + xs, lblTitle.Top + ys, lblTitle.Width
    

End Sub



