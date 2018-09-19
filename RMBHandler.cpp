// RMBHandler.cpp: implementation of the RMBHandler class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NMEAInst.h"
#include "RMBHandler.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RMBHandler::RMBHandler()
{
	m_CmdStr= "RMB";

}

RMBHandler::~RMBHandler()
{

}
void RMBHandler::process(CString & message,CDialog* dlg)
{
	int elementid=0;
	CNMEAInstDlg* viewer = (CNMEAInstDlg*) dlg;
	CString lat;
	CString lng;
	CString heading;
	CString dirwpt;
	CString name;
	CString range;
	float rng=0;
	float brg=0;
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
			case 3:
			{

				name=element;
				break;
			}
			case 5: 
			{
				lat = element;
				lat.Insert(2,' ');
				break;
			}
			case 6:
			{
				lat+= element;
				break;
			}
			case 7:
			{
				lng=element;
				lng.Insert(3,' ');
				break;
			}
			case 8:
			{
				lng+=element;
				break;
			}
			case 9:
			{
				range = element;
				rng=atof(element);
				break;
			}
			case 10:
			{
				heading=element;

				brg=atof(element);
				break;
			}
			default:
			{
				break;
			}
		}
		elementid++;
	}
		viewer->m_wayptLat=lat;
		viewer->m_wayptLong = lng;
		viewer->m_wptdir->SetValue(brg);
		viewer->m_wayptName = name;
		viewer->m_wpHead=heading;
		viewer->m_wpDist=range;
		//viewer->UpdateData(false);
		//viewer->Invalidate();
}
