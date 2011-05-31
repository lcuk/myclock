VERSION 5.00
Begin VB.Form myclock_cover 
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
   Begin VB.Image preview 
      Height          =   3840
      Left            =   6840
      Picture         =   "myclock_cover.frx":0000
      Stretch         =   -1  'True
      Top             =   2220
      Width           =   3960
   End
   Begin VB.Label cmdclockfacemanage 
      Alignment       =   2  'Center
      BackColor       =   &H00004000&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "View History"
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
      Height          =   1215
      Left            =   480
      TabIndex        =   7
      Top             =   5310
      Width           =   5115
   End
   Begin VB.Label cmdclockfacecreate 
      Alignment       =   2  'Center
      BackColor       =   &H00004000&
      BorderStyle     =   1  'Fixed Single
      Caption         =   "Create Clock Face"
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
      Height          =   1215
      Left            =   480
      TabIndex        =   6
      Tag             =   "dialog=myclock_design"
      Top             =   3960
      Width           =   5115
   End
   Begin VB.Label slidetext1 
      BackColor       =   &H00000000&
      Caption         =   "A personal clock."
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   465
      Left            =   390
      TabIndex        =   5
      Top             =   2130
      Width           =   6645
   End
   Begin VB.Label slidetext2 
      BackColor       =   &H00000000&
      Caption         =   "Unique hand written digital"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   465
      Left            =   390
      TabIndex        =   4
      Top             =   2730
      Width           =   6645
   End
   Begin VB.Label slidetext3 
      BackColor       =   &H00000000&
      Caption         =   "Distinctive analogue design."
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   465
      Left            =   390
      TabIndex        =   3
      Top             =   3360
      Width           =   6645
   End
   Begin VB.Label author 
      BackColor       =   &H00000000&
      Caption         =   "written by Gary Birkett."
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
      Height          =   735
      Left            =   360
      TabIndex        =   2
      Top             =   1260
      Width           =   10455
   End
   Begin VB.Label lbltitle 
      BackColor       =   &H00000000&
      Caption         =   "My Clock"
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   48
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   1215
      Left            =   0
      TabIndex        =   1
      Top             =   0
      Width           =   12015
   End
   Begin VB.Label Label3 
      Alignment       =   2  'Center
      BackColor       =   &H00000000&
      Caption         =   "open source comes from the heart.  please donate to all projects."
      BeginProperty Font 
         Name            =   "Trebuchet MS"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   465
      Left            =   210
      TabIndex        =   0
      Top             =   6690
      Width           =   11475
   End
End
Attribute VB_Name = "myclock_cover"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdall_Click()

End Sub

Private Sub cmdinvert_Click()

End Sub

Private Sub Form_Load()
    ScaleMode = vbPixels
    canvas.ScaleMode = vbPixels
    canvas.Move 50, 50, 401, 401


    canvas.BackColor = RGB(0, 0, 0)
    canvas.Cls
    canvas.DrawWidth = 5: canvas.Circle (200, 200), 190 - 2, RGB(30, 90, 30)
    canvas.DrawWidth = 5: canvas.Line (200, 200)-Step(0, -170 - 2), RGB(30, 90, 30)
    canvas.DrawWidth = 5: canvas.Line (200, 200)-Step(110 - 2, 0), RGB(30, 90, 30)
    SavePicture canvas.Image, "template.myclock.all.bmp"

    canvas.BackColor = RGB(0, 0, 0)
    canvas.Cls
    canvas.DrawWidth = 5: canvas.Circle (200, 200), 190 - 2, RGB(30, 90, 30)
    canvas.DrawWidth = 3: canvas.Line (200, 200)-Step(0, -170 - 2), RGB(30, 30, 30)
    canvas.DrawWidth = 3: canvas.Line (200, 200)-Step(110 - 2, 0), RGB(30, 30, 30)
    SavePicture canvas.Image, "template.myclock.face.bmp"

    canvas.BackColor = RGB(0, 0, 0)
    canvas.Cls
    canvas.DrawWidth = 3: canvas.Circle (200, 200), 190 - 2, RGB(30, 30, 30)
    canvas.DrawWidth = 5: canvas.Line (200, 200)-Step(0, -170 - 2), RGB(30, 90, 30)
    canvas.DrawWidth = 3: canvas.Line (200, 200)-Step(110 - 2, 0), RGB(30, 30, 30)
    SavePicture canvas.Image, "template.myclock.minutes.bmp"

    canvas.BackColor = RGB(0, 0, 0)
    canvas.Cls
    canvas.DrawWidth = 3: canvas.Circle (200, 200), 190 - 2, RGB(30, 30, 30)
    canvas.DrawWidth = 3: canvas.Line (200, 200)-Step(0, -170 - 2), RGB(30, 30, 30)
    canvas.DrawWidth = 5: canvas.Line (200, 200)-Step(110 - 2, 0), RGB(30, 90, 30)
    SavePicture canvas.Image, "template.myclock.hours.bmp"

End Sub



'
'    ScaleMode = vbPixels
'    canvas.ScaleMode = vbPixels
'    canvas.Move 50, 50, 401, 401
'
'
'    canvas.BackColor = RGB(0, 0, 0)
'    canvas.Cls
'    canvas.DrawWidth = 5: canvas.Circle (200, 200), 200 - 2, RGB(30, 90, 30)
'    canvas.DrawWidth = 5: canvas.Line (200, 200)-Step(0, -180 - 2), RGB(30, 90, 30)
'    canvas.DrawWidth = 5: canvas.Line (200, 200)-Step(120 - 2, 0), RGB(30, 90, 30)
'    SavePicture canvas.Image, "template.myclock.all.bmp"
'
'    canvas.BackColor = RGB(0, 0, 0)
'    canvas.Cls
'    canvas.DrawWidth = 5: canvas.Circle (200, 200), 200 - 2, RGB(30, 90, 30)
'    canvas.DrawWidth = 3: canvas.Line (200, 200)-Step(0, -180 - 2), RGB(30, 30, 30)
'    canvas.DrawWidth = 3: canvas.Line (200, 200)-Step(120 - 2, 0), RGB(30, 30, 30)
'    SavePicture canvas.Image, "template.myclock.face.bmp"
'
'    canvas.BackColor = RGB(0, 0, 0)
'    canvas.Cls
'    canvas.DrawWidth = 3: canvas.Circle (200, 200), 200 - 2, RGB(30, 30, 30)
'    canvas.DrawWidth = 5: canvas.Line (200, 200)-Step(0, -180 - 2), RGB(30, 90, 30)
'    canvas.DrawWidth = 3: canvas.Line (200, 200)-Step(120 - 2, 0), RGB(30, 30, 30)
'    SavePicture canvas.Image, "template.myclock.minutes.bmp"
'
'    canvas.BackColor = RGB(0, 0, 0)
'    canvas.Cls
'    canvas.DrawWidth = 3: canvas.Circle (200, 200), 200 - 2, RGB(30, 30, 30)
'    canvas.DrawWidth = 3: canvas.Line (200, 200)-Step(0, -180 - 2), RGB(30, 30, 30)
'    canvas.DrawWidth = 5: canvas.Line (200, 200)-Step(120 - 2, 0), RGB(30, 90, 30)
'    SavePicture canvas.Image, "template.myclock.hours.bmp"
'
