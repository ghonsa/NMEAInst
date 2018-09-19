; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNMEAInstDlg
LastTemplate=CWinThread
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NMEAInst.h"

ClassCount=4
Class1=CNMEAInstApp
Class2=CNMEAInstDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_NMEAINST_DIALOG
Resource2=IDR_MAINFRAME
Class4=PortReader
Resource3=IDD_ABOUTBOX
Resource4=IDR_MENU1

[CLS:CNMEAInstApp]
Type=0
HeaderFile=NMEAInst.h
ImplementationFile=NMEAInst.cpp
Filter=N

[CLS:CNMEAInstDlg]
Type=0
HeaderFile=NMEAInstDlg.h
ImplementationFile=NMEAInstDlg.cpp
Filter=D
LastObject=ID_CONNECT_COM10
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=NMEAInstDlg.h
ImplementationFile=NMEAInstDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_NMEAINST_DIALOG]
Type=1
Class=CNMEAInstDlg
ControlCount=38
Control1=IDOK,button,1342242817
Control2=IDC_BOATSPEED,{36AF7CE0-F8CD-42BF-AA3B-1CC98BB5A0A7},1342242816
Control3=IDC_COMPASVW,{36AF7CE0-F8CD-42BF-AA3B-1CC98BB5A0A7},1342242816
Control4=IDC_SOG,{36AF7CE0-F8CD-42BF-AA3B-1CC98BB5A0A7},1342242816
Control5=IDC_WINDDIRECTION,{36AF7CE0-F8CD-42BF-AA3B-1CC98BB5A0A7},1342242816
Control6=IDC_WINDSPEED,{36AF7CE0-F8CD-42BF-AA3B-1CC98BB5A0A7},1342242816
Control7=IDC_LATITUDE,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_DEPTH,edit,1350631552
Control11=IDC_LONGITUDE,edit,1350631552
Control12=IDC_HEADING,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_WINDDIR,edit,1350631552
Control16=IDC_WINDSPD,edit,1350631552
Control17=IDC_STATIC,static,1342308352
Control18=IDC_BOATSPD,edit,1350631552
Control19=IDC_SOGT,edit,1350631552
Control20=IDC_WAYPT,{36AF7CE0-F8CD-42BF-AA3B-1CC98BB5A0A7},1342242816
Control21=IDC_WPTLAT,edit,1350631552
Control22=IDC_WPTLON,edit,1350631552
Control23=IDC_WPTNAME,edit,1350631552
Control24=IDC_STATIC,button,1342177287
Control25=IDC_STATIC,button,1342177287
Control26=IDC_STATIC,button,1342177287
Control27=IDC_STATIC,button,1342177287
Control28=IDC_WPHEAD,edit,1350631552
Control29=IDC_WPDIST,edit,1350631552
Control30=IDC_STATIC,button,1342177287
Control31=IDC_STATIC,button,1342177287
Control32=IDC_STATIC,button,1342177287
Control33=IDC_STATIC,button,1342177287
Control34=IDC_STATIC,button,1342177287
Control35=IDC_STATIC,button,1342177287
Control36=IDC_LOG,button,1342242819
Control37=IDC_DATE,edit,1350631552
Control38=IDC_TIME,edit,1350631552

[CLS:PortReader]
Type=0
HeaderFile=PortReader.h
ImplementationFile=PortReader.cpp
BaseClass=CWinThread
Filter=N
VirtualFilter=TC

[MNU:IDR_MENU1]
Type=1
Class=CNMEAInstDlg
Command1=ID_COM1
Command2=ID_COM2
Command3=ID_COM3
Command4=ID_COM4
Command5=ID_CONNECT_COM10
CommandCount=5

