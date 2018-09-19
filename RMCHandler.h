// RMCHandler.h: interface for the RMCHandler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RMCHANDLER_H__8B8758E0_F386_11D8_BF98_00D0591A7DED__INCLUDED_)
#define AFX_RMCHANDLER_H__8B8758E0_F386_11D8_BF98_00D0591A7DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NMEASentenceHandler.h"
#include "NMEAInstDlg.h"

class RMCHandler : public NMEASentenceHandler  
{
public:
	RMCHandler();
	virtual ~RMCHandler();
	void process(CString & message,CDialog * dlg);

};

#endif // !defined(AFX_RMCHANDLER_H__8B8758E0_F386_11D8_BF98_00D0591A7DED__INCLUDED_)
