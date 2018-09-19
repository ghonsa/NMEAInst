// NMEAManager.h: interface for the NMEAManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NMEAMANAGER_H__7FE49781_F36A_11D8_BF98_00D0591A7DED__INCLUDED_)
#define AFX_NMEAMANAGER_H__7FE49781_F36A_11D8_BF98_00D0591A7DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NMEASentenceHandler.h"

#define MAX_HANDLERS 20

class NMEAManager  
{
public:
	HRESULT cleanup();
	HRESULT initialize();
	int addHandler(NMEASentenceHandler * handler);
	NMEASentenceHandler * getHandler(CString * cmd);
	NMEAManager();
	virtual ~NMEAManager();

private:
	NMEASentenceHandler * m_handlers[MAX_HANDLERS];
};

#endif // !defined(AFX_NMEAMANAGER_H__7FE49781_F36A_11D8_BF98_00D0591A7DED__INCLUDED_)
