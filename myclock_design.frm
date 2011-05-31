VERSION 5.00
Begin VB.Form myclock_design 
   BackColor       =   &H00000000&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Base Form"
   ClientHeight    =   7200
   ClientLeft      =   45
   ClientTop       =   360
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
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7200
   ScaleWidth      =   12015
   StartUpPosition =   3  'Windows Default
   Begin VB.TextBox txtname 
      BackColor       =   &H00000000&
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   36
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   1065
      Left            =   4440
      TabIndex        =   7
      Text            =   "Clock Name"
      Top             =   1320
      Width           =   6525
   End
   Begin myclock.titlebar titlebar1 
      Align           =   1  'Align Top
      Height          =   840
      Left            =   0
      TabIndex        =   3
      Top             =   0
      Width           =   12015
      _extentx        =   21193
      _extenty        =   1482
      caption         =   "My Clock Design screen"
   End
   Begin VB.Label Label5 
      Alignment       =   2  'Center
      BackColor       =   &H00000000&
      Caption         =   "Name:"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   495
      Left            =   960
      TabIndex        =   6
      Top             =   1560
      Width           =   2625
   End
   Begin VB.Label cmdsave 
      Alignment       =   2  'Center
      BackColor       =   &H00004000&
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
      Height          =   840
      Left            =   8100
      TabIndex        =   5
      Top             =   6360
      Width           =   3915
   End
   Begin VB.Label Label4 
      BackColor       =   &H00000000&
      Caption         =   "Create the components for your customised clock"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   525
      Left            =   990
      TabIndex        =   4
      Top             =   780
      Width           =   9975
   End
   Begin VB.Label cmdminutes 
      Alignment       =   2  'Center
      BackColor       =   &H00000000&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Minutes Hand"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   495
      Left            =   8160
      TabIndex        =   2
      Tag             =   "dialog=myclock_editor"
      Top             =   5520
      Width           =   2625
   End
   Begin VB.Label cmdhours 
      Alignment       =   2  'Center
      BackColor       =   &H00000000&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Hours Hand"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   495
      Left            =   4620
      TabIndex        =   1
      Tag             =   "dialog=myclock_editor"
      Top             =   5520
      Width           =   2625
   End
   Begin VB.Label cmdface 
      Alignment       =   2  'Center
      BackColor       =   &H00000000&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Clock Face"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   18
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   495
      Left            =   1080
      TabIndex        =   0
      Tag             =   "dialog=myclock_editor"
      Top             =   5520
      Width           =   2625
   End
   Begin VB.Image imaminutes 
      BorderStyle     =   1  'Fixed Single
      Height          =   2955
      Left            =   8010
      Picture         =   "myclock_design.frx":0000
      Stretch         =   -1  'True
      Tag             =   "dialog=myclock_editor"
      Top             =   2580
      Width           =   2955
   End
   Begin VB.Image imahours 
      BorderStyle     =   1  'Fixed Single
      Height          =   2955
      Left            =   4470
      Picture         =   "myclock_design.frx":75E36
      Stretch         =   -1  'True
      Tag             =   "dialog=myclock_editor"
      Top             =   2580
      Width           =   2955
   End
   Begin VB.Image imaface 
      BorderStyle     =   1  'Fixed Single
      Height          =   2955
      Left            =   900
      Picture         =   "myclock_design.frx":EBC6C
      Stretch         =   -1  'True
      Tag             =   "dialog=myclock_editor"
      Top             =   2580
      Width           =   2955
   End
End
Attribute VB_Name = "myclock_design"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

