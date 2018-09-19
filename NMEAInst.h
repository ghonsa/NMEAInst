// NMEAInst.h : main header file for the NMEAINST application
//

#if !defined(AFX_NMEAINST_H__8EE80CC6_E182_11D8_BF98_00D0591A7DED__INCLUDED_)
#define AFX_NMEAINST_H__8EE80CC6_E182_11D8_BF98_00D0591A7DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "NMEAInst_i.h"

/////////////////////////////////////////////////////////////////////////////
// CNMEAInstApp:
// See NMEAInst.cpp for the implementation of this class
//

class CNMEAInstApp : public CWinApp
{
public:
	CNMEAInstApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNMEAInstApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNMEAInstApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NMEAINST_H__8EE80CC6_E182_11D8_BF98_00D0591A7DED__INCLUDED_)
