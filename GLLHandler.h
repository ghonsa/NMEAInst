// GLLHandler.h: interface for the GLLHandler class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLLHANDLER_H__7FE49782_F36A_11D8_BF98_00D0591A7DED__INCLUDED_)
#define AFX_GLLHANDLER_H__7FE49782_F36A_11D8_BF98_00D0591A7DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NMEAInstDlg.h"
#include "NMEASentenceHandler.h"

class GLLHandler : public NMEASentenceHandler  
{
public:
	//CString * getCMD();
	void process(CString & message,CDialog * dlg);
	GLLHandler();
	virtual ~GLLHandler();

};

#endif // !defined(AFX_GLLHANDLER_H__7FE49782_F36A_11D8_BF98_00D0591A7DED__INCLUDED_)
