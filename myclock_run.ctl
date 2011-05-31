VERSION 5.00
Object = "{A964BDA3-3E93-11CF-9A0F-9E6261DACD1C}#3.0#0"; "Resize32.ocx"
Begin VB.UserControl myclock_run 
   BackColor       =   &H00000000&
   ClientHeight    =   7200
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   12015
   ScaleHeight     =   7200
   ScaleWidth      =   12015
   Begin ResizeLibCtl.ReSize ReSize1 
      Left            =   3090
      Top             =   180
      _Version        =   196608
      _ExtentX        =   741
      _ExtentY        =   741
      _StockProps     =   64
      Enabled         =   -1  'True
      Enabled         =   -1  'True
      FormMinWidth    =   0
      FormMinHeight   =   0
      FormDesignHeight=   7200
      FormDesignWidth =   12015
   End
   Begin VB.Image canvass 
      Height          =   7200
      Left            =   2340
      Picture         =   "myclock_run.ctx":0000
      Stretch         =   -1  'True
      Top             =   0
      Width           =   7200
   End
End
Attribute VB_Name = "myclock_run"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

