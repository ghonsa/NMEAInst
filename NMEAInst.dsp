# Microsoft Developer Studio Project File - Name="NMEAInst" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=NMEAInst - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "NMEAInst.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "NMEAInst.mak" CFG="NMEAInst - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "NMEAInst - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "NMEAInst - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "NMEAInst - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "NMEAInst - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "NMEAInst - Win32 Release"
# Name "NMEAInst - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\GLLHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\NMEAInst.cpp
# End Source File
# Begin Source File

SOURCE=.\NMEAInst.idl
# ADD MTL /h "NMEAInst_i.h" /iid "NMEAInst_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\NMEAInst.rc
# End Source File
# Begin Source File

SOURCE=.\NMEAInstDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NMEAManager.cpp
# End Source File
# Begin Source File

SOURCE=.\NMEASentenceHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\PortReader.cpp
# End Source File
# Begin Source File

SOURCE=.\RMBHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\RMCHandler.cpp
# End Source File
# Begin Source File

SOURCE=.\speedo.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\WPLHandler.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\GLLHandler.h
# End Source File
# Begin Source File

SOURCE=.\NMEAInst.h
# End Source File
# Begin Source File

SOURCE=.\NMEAInstDlg.h
# End Source File
# Begin Source File

SOURCE=.\NMEAManager.h
# End Source File
# Begin Source File

SOURCE=.\NMEASentenceHandler.h
# End Source File
# Begin Source File

SOURCE=.\PortReader.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RMBHandler.h
# End Source File
# Begin Source File

SOURCE=.\RMCHandler.h
# End Source File
# Begin Source File

SOURCE=.\speedo.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\WPLHandler.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\NMEAInst.ico
# End Source File
# Begin Source File

SOURCE=.\res\NMEAInst.rc2
# End Source File
# Begin Source File

SOURCE=.\NMEAInst.rgs
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section NMEAInst : {36AF7CE0-F8CD-42BF-AA3B-1CC98BB5A0A7}
# 	2:21:DefaultSinkHeaderFile:speedo1.h
# 	2:16:DefaultSinkClass:CSpeedo
# End Section
# Section NMEAInst : {00080005-0006-0008-0700-080008000800}
# 	1:12:IDR_NMEAINST:103
# End Section
# Section NMEAInst : {DED9A713-656D-46FA-A261-D8F4A7F8A56C}
# 	2:5:Class:CSpeedo
# 	2:10:HeaderFile:speedo1.h
# 	2:8:ImplFile:speedo1.cpp
# End Section
