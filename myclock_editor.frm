VERSION 5.00
Begin VB.Form myclock_editor 
   BackColor       =   &H00000000&
   Caption         =   "Base Form"
   ClientHeight    =   7200
   ClientLeft      =   60
   ClientTop       =   375
   ClientWidth     =   12015
   BeginProperty Font 
      Name            =   "Trebuchet MS"
      Size            =   9.75
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   LinkTopic       =   "frmBase800x480"
   ScaleHeight     =   7200
   ScaleWidth      =   12015
   StartUpPosition =   3  'Windows Default
   Begin myclock.titlebar titlebar1 
      Align           =   1  'Align Top
      Height          =   840
      Left            =   0
      TabIndex        =   0
      Top             =   0
      Width           =   12015
      _extentx        =   21193
      _extenty        =   1482
      caption         =   "My Clock Editing : ClockFace"
   End
   Begin VB.Image canvass 
      BorderStyle     =   1  'Fixed Single
      Height          =   6000
      Left            =   3120
      Picture         =   "myclock_editor.frx":0000
      Stretch         =   -1  'True
      Top             =   930
      Width           =   6000
   End
   Begin VB.Label cmdsave 
      Alignment       =   2  'Center
      BackColor       =   &H00006400&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Save"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   720
      Left            =   7980
      TabIndex        =   3
      Top             =   6480
      Visible         =   0   'False
      Width           =   4005
   End
   Begin VB.Label cmdclear 
      Alignment       =   2  'Center
      BackColor       =   &H00640000&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Clear"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   720
      Left            =   3990
      TabIndex        =   2
      Top             =   6480
      Visible         =   0   'False
      Width           =   4005
   End
   Begin VB.Label cmdundo 
      Alignment       =   2  'Center
      BackColor       =   &H00640064&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Undo"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   27.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   720
      Left            =   0
      TabIndex        =   1
      Top             =   6480
      Visible         =   0   'False
      Width           =   4005
   End
End
Attribute VB_Name = "myclock_editor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

