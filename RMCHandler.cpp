// RMCHandler.cpp: implementation of the RMCHandler class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NMEAInst.h"
#include "RMCHandler.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RMCHandler::RMCHandler()
{
	m_CmdStr= "RMC";

}

RMCHandler::~RMCHandler()
{

}
void RMCHandler::process(CString & message,CDialog* dlg)
{
	int elementid=0;
	CNMEAInstDlg* viewer = (CNMEAInstDlg*) dlg;
	CString utcTime;
	CString Date;
	CString lat;
	CString lng;
	CString heading;
	float sog=0;
	float cog=0;
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
				utcTime= element;
				break;

			}
			case 2: 
			{
				lat = element;
				lat.Insert(2,' ');
				break;
			}
			case 3:
			{
				lat+= element;
				break;
			}
			case 4:
			{
				lng=element;
				lng.Insert(3,' ');
				break;
			}
			case 5:
			{
				lng+=element;
				break;
			}
			case 6:
			{
				sog=atof(element);
				break;
			}
			case 7:
			{
				heading=element;

				cog=atof(element);
				break;
			}
			case 8:
			{
				Date = element;
				Date.Insert(4,'/');
				Date.Insert(2,'/');
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
		viewer->m_sog->SetValue(sog);
		viewer->m_compas->SetStart(270-cog);
		viewer->m_compas->SetValue(cog);
		viewer->m_wptdir->SetStart(270-cog);
		viewer->m_heading=heading;
		viewer->m_date=Date;
		viewer->m_time=utcTime;
		//viewer->UpdateData(false);
		//viewer->Invalidate();
}
