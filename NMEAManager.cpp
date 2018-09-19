// NMEAManager.cpp: implementation of the NMEAManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NMEAInst.h"
#include "NMEAManager.h"

#include  "GLLHandler.h"
#include  "RMCHandler.h"
#include  "WPLHandler.h"
#include  "RMBHandler.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NMEAManager::NMEAManager()
{

}

NMEAManager::~NMEAManager()
{

}

NMEASentenceHandler * NMEAManager::getHandler(CString *cmd)
{
	NMEASentenceHandler ** cptr = &m_handlers[0];
	while (*cptr !=NULL)
	{
		if (**cptr==cmd)
			return *cptr;
		cptr++;
	}

	return NULL;
}

int NMEAManager::addHandler(NMEASentenceHandler * handler)
{
	return 1;
}

HRESULT NMEAManager::initialize()
{
	int ctr;
	// zero out array
	for(ctr=0;ctr<MAX_HANDLERS; ctr++)
		m_handlers[ctr]=NULL;

	m_handlers[0] = (NMEASentenceHandler *) new GLLHandler();
	m_handlers[1] = (NMEASentenceHandler *) new RMCHandler();
	m_handlers[2] = (NMEASentenceHandler *) new WPLHandler();
	m_handlers[3] = (NMEASentenceHandler *) new RMBHandler();
	return S_OK;
}

HRESULT NMEAManager::cleanup()
{
	int ctr = 0;
	// zero out array
	while(m_handlers[ctr]!=NULL)
	{
		delete m_handlers[ctr];
		ctr++;
	}
	return S_OK;
}
