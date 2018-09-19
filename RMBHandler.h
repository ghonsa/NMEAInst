// RMBHandler.h: interface for the RMBHandler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RMBHANDLER_H__0B01A220_F543_11D8_BF98_00D0591A7DED__INCLUDED_)
#define AFX_RMBHANDLER_H__0B01A220_F543_11D8_BF98_00D0591A7DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NMEASentenceHandler.h"
#include "NMEAInstDlg.h"

class RMBHandler : public NMEASentenceHandler  
{
public:
	RMBHandler();
	virtual ~RMBHandler();
	void process(CString & message,CDialog * dlg);

};

#endif // !defined(AFX_RMBHANDLER_H__0B01A220_F543_11D8_BF98_00D0591A7DED__INCLUDED_)
