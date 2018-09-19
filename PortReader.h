#if !defined(AFX_PORTREADER_H__CF09A9C7_05A5_11D9_BF98_00D0591A7DED__INCLUDED_)
#define AFX_PORTREADER_H__CF09A9C7_05A5_11D9_BF98_00D0591A7DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PortReader.h : header file
//
//#include "NMEAInstDlg.h"


/////////////////////////////////////////////////////////////////////////////
// PortReader thread

class PortReader : public CWinThread
{
	DECLARE_DYNCREATE(PortReader)
protected:
	PortReader();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	BOOL m_bRun;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PortReader)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL
	void SetOwner(CDialog *pOwner) { m_pOwner = pOwner; };
	void SetSource(HANDLE hand) { m_hSrc = hand; };


// Implementation
protected:
	CDialog * m_pOwner;
	HANDLE m_hSrc;
	virtual ~PortReader();

	// Generated message map functions
	//{{AFX_MSG(PortReader)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PORTREADER_H__CF09A9C7_05A5_11D9_BF98_00D0591A7DED__INCLUDED_)
