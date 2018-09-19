// NMEASentenceHandler.h: interface for the NMEASentenceHandler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NMEASENTENCEHANDLER_H__7FE49780_F36A_11D8_BF98_00D0591A7DED__INCLUDED_)
#define AFX_NMEASENTENCEHANDLER_H__7FE49780_F36A_11D8_BF98_00D0591A7DED__INCLUDED_
//#include "NMEAInstDlg.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class NMEASentenceHandler  
{
public:
	virtual void process(CString & message,CDialog * dlg) = 0;
	CString * getCMD();
	NMEASentenceHandler();
	virtual ~NMEASentenceHandler();
	bool operator==(CString*);
protected:
	CString m_CmdStr;
};

#endif // !defined(AFX_NMEASENTENCEHANDLER_H__7FE49780_F36A_11D8_BF98_00D0591A7DED__INCLUDED_)
