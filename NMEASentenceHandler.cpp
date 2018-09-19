// NMEASentenceHandler.cpp: implementation of the NMEASentenceHandler class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NMEAInst.h"
#include "NMEASentenceHandler.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NMEASentenceHandler::NMEASentenceHandler()
{

}

NMEASentenceHandler::~NMEASentenceHandler()
{

}

CString * NMEASentenceHandler::getCMD()
{
	return  &m_CmdStr;
}

void NMEASentenceHandler::process(CString & message,CDialog * dlg)
{
	int t=1;
}

bool NMEASentenceHandler::operator==(CString* cmd)
{
	if(cmd->Compare(m_CmdStr)==0)
		return true;

	return false;
}