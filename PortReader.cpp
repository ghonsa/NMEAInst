// PortReader.cpp : implementation file
//

#include "stdafx.h"
#include "NMEAInst.h"
//#include "PortReader.h"
#include "NMEAInstDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PortReader

IMPLEMENT_DYNCREATE(PortReader, CWinThread)

PortReader::PortReader()
{
}

PortReader::~PortReader()
{
}

BOOL PortReader::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int PortReader::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(PortReader, CWinThread)
	//{{AFX_MSG_MAP(PortReader)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PortReader message handlers

int PortReader::Run() 
{
	DWORD dwRead;
	DWORD dwReq ;
	char lpBuf[516];
	char * bufptr = lpBuf;
	OVERLAPPED osReader = {0};
	dwReq =512-(bufptr-lpBuf);

	TRACE("Port Reader Thread\n");
	// Issue read operation
	//ReadFile(hComm, bufptr, 512-(bufptr-lpBuf), &dwRead, NULL);
	while ( ReadFile(m_hSrc, bufptr, dwReq, &dwRead, NULL))
	{
		char seps[]   = "\n";
		char *sentence;
		TRACE("Read: %d \n",dwRead);
		if(!m_bRun)
		{
			((CNMEAInstDlg*)m_pOwner)->m_bAlive = FALSE;
			return 0;
	 	}
		if(dwRead<=0)
		{
			//if(MessageBox(m_pOwner->m_hWnd,"Timeout occured during read. Retry? ","Data Timeout",MB_YESNO)==IDNO)
			//{
			//	((CNMEAInstDlg*)m_pOwner)->m_bAlive = FALSE;
			//	return 0;
			//}
		}
		else
		{
			*(bufptr+dwRead)=0;
			/* Establish string and get the first token: */
			sentence = strtok( lpBuf, seps );
			while( sentence != NULL )
			{
				int r=0; 
				char * end = NULL;
				char * endptr;
				char * nexts =strtok( NULL, seps );
				if((end = strrchr( sentence, 0x0d)) != (endptr= sentence+ (r=strlen(sentence)-1) ))
				{
					strcpy(lpBuf,sentence);
					bufptr= lpBuf+strlen(sentence);
					break;
				}
				// Pass the sentance back to be handled
				TRACE( "DATA: %s \n",sentence);
				((CNMEAInstDlg*)m_pOwner)->ProcessSentence(sentence);
				// get the next sentence
				sentence = nexts;
				bufptr=lpBuf;
			}
			dwReq =512-(bufptr-lpBuf);

		}
	}
	Sleep(0);
	   // done processing this buff
	return 0;
}
