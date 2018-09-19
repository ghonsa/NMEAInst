// GLLHandler.cpp: implementation of the GLLHandler class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NMEAInst.h"
#include "GLLHandler.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GLLHandler::GLLHandler()
{

	m_CmdStr= "GLL";

}

GLLHandler::~GLLHandler()
{

}
//CString * GLLHandler::getCMD()
//{
//	return &m_CmdStr;
//}
void GLLHandler::process(CString & message,CDialog* dlg)
{
	int elementid=0;
	CNMEAInstDlg* viewer = (CNMEAInstDlg*) dlg;
	CString lat;
	CString lng;
	while( !message.IsEmpty() )
	{
		CString element;
		int idx1 = message.Find(',');
		if( idx1!=-1)
		{
			element=message.Left(idx1);
			message = message.Right(message.GetLength()-(idx1+1));
		}
		else
		{
			// last element usally checksum
			element = message;
			break;
		}
		switch( elementid)
		{
			case 0: 
			{
				lat = element;
				lat.Insert(2,' ');
				break;
			}
			case 1:
			{
				lat+= element;
				break;
			}
			case 2:
			{
				lng=element;
				lng.Insert(3,' ');
				break;
			}
			case 3:
			{
				lng+=element;
				break;
			}
			default:
			{
				break;
			}
		}
		elementid++;
	}
		viewer->m_lat=lat;
		viewer->m_long = lng;
		//viewer->UpdateData(false);
}
