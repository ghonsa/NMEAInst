// NMEAInstDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NMEAInst.h"
#include "NMEAInstDlg.h"

#include <atlbase.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNMEAInstDlg dialog

CNMEAInstDlg::CNMEAInstDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNMEAInstDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNMEAInstDlg)
	m_lat = _T("");
	m_long = _T("");
	m_heading = _T("");
	m_wayptLat = _T("");
	m_wayptLong = _T("");
	m_wayptName = _T("");
	m_wpHead = _T("");
	m_wpDist = _T("");
	m_date = _T("");
	m_time = _T("");
	m_bLog = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_reader=0;
	m_nTimer=0;
	m_bConnected = FALSE;
}

void CNMEAInstDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNMEAInstDlg)
	DDX_Text(pDX, IDC_LATITUDE, m_lat);
	DDX_Text(pDX, IDC_LONGITUDE, m_long);
	DDX_Text(pDX, IDC_HEADING, m_heading);
	DDX_Text(pDX, IDC_WPTLAT, m_wayptLat);
	DDX_Text(pDX, IDC_WPTLON, m_wayptLong);
	DDX_Text(pDX, IDC_WPTNAME, m_wayptName);
	DDX_Text(pDX, IDC_WPHEAD, m_wpHead);
	DDX_Text(pDX, IDC_WPDIST, m_wpDist);
	DDX_Text(pDX, IDC_DATE, m_date);
	DDX_Text(pDX, IDC_TIME, m_time);
	DDX_Check(pDX, IDC_LOG, m_bLog);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNMEAInstDlg, CDialog)
	//{{AFX_MSG_MAP(CNMEAInstDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK, OnTest)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_LOG, OnLog)
	ON_COMMAND(ID_COM1, OnCom1)
	ON_COMMAND(ID_COM2, OnCom2)
	ON_COMMAND(ID_COM3, OnCom3)
	ON_COMMAND(ID_COM4, OnCom4)
	ON_WM_CANCELMODE()
	ON_COMMAND(ID_CONNECT_COM10, OnConnectCom10)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNMEAInstDlg message handlers

BOOL CNMEAInstDlg::OnInitDialog()
{
	USES_CONVERSION;

	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	m_compas = (CSpeedo *) GetDlgItem(IDC_COMPASVW);
	m_compas->SetAlertLevel(0);
	m_compas->SetWarningLevel(0);
	m_compas->SetDampening(0);
	m_compas->SetValue(270);
	m_compas->SetStart(-90);
	m_compas->SetScaleHigh(360);
	m_compas->SetScaleIncrement(30);
	m_compas->SetCenterLabel("COMPASS");

	m_sog = (CSpeedo *) GetDlgItem(IDC_SOG);
	m_sog->SetAlertLevel(0);
	m_sog->SetWarningLevel(0);
	m_sog->SetDampening(0);
	m_sog->SetGtype(2);
	m_sog->SetValue(2);
	m_sog->SetScaleHigh(100);
	m_sog->SetScaleIncrement(10);
	m_sog->SetCenterLabel("SOG KNOTS");

	m_boat_speed = (CSpeedo *) GetDlgItem(IDC_BOATSPEED);
	m_boat_speed->SetAlertLevel(0);
	m_boat_speed->SetWarningLevel(0);
	m_boat_speed->SetDampening(0);
	m_boat_speed->SetGtype(2);
	m_boat_speed->SetValue(2);
	m_boat_speed->SetScaleHigh(20);
	m_boat_speed->SetScaleIncrement(2);
	m_boat_speed->SetCenterLabel("BOAT SPEED KNOTS");

	m_wind_dir = (CSpeedo *) GetDlgItem(IDC_WINDDIRECTION);
	m_wind_dir->SetAlertLevel(0);
	m_wind_dir->SetWarningLevel(0);
	m_wind_dir->SetDampening(0);
	m_wind_dir->SetStart(270);
	m_wind_dir->SetValue(2);
	m_wind_dir->SetScaleHigh(360);
	m_wind_dir->SetScaleIncrement(45);
	m_wind_dir->SetCenterLabel("WIND DIRECTION");

	m_wind_speed = (CSpeedo *) GetDlgItem(IDC_WINDSPEED);
	m_wind_speed->SetAlertLevel(0);
	m_wind_speed->SetWarningLevel(0);
	m_wind_speed->SetDampening(0);
	m_wind_speed->SetGtype(2);
	m_wind_speed->SetValue(2);
	m_wind_speed->SetScaleHigh(60);
	m_wind_speed->SetScaleIncrement(5);
	m_wind_speed->SetCenterLabel("WIND KNOTS");

	m_wptdir= (CSpeedo *) GetDlgItem(IDC_WAYPT);
	m_wptdir->SetAlertLevel(0);
	m_wptdir->SetWarningLevel(0);
	m_wptdir->SetDampening(0);
	m_wptdir->SetStart(270);
	m_wptdir->SetValue(2);
	m_wptdir->SetScaleHigh(360);
	m_wptdir->SetScaleIncrement(45);
	m_wptdir->SetCenterLabel("WAYPOINT HEADING");
	initialize();
	//OnConnectCom10();
	OnCom1();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNMEAInstDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNMEAInstDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNMEAInstDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


BOOL CNMEAInstDlg::InitComms(LPCTSTR port)
{
	BOOL brslt;   
	DCB dcb;
	COMMTIMEOUTS ctm;
	hComm = CreateFile( port,  
                    GENERIC_READ | GENERIC_WRITE, 
                    0, 
                    0, 
                    OPEN_EXISTING,FILE_FLAG_NO_BUFFERING,
                    //FILE_FLAG_OVERLAPPED,
                    0);
	if (hComm == INVALID_HANDLE_VALUE)
   // error opening port;
	{
		MessageBox(_T("Create Comms handle failed"),_T("ERROR"),MB_OK);
		return FALSE;
	}

   FillMemory(&dcb, sizeof(dcb), 0);
   if (!GetCommState(hComm, &dcb))     // get current DCB
   {   // Error in GetCommState
	   DWORD error =GetLastError();
		CString txt;
		txt.Format("GetCommState failed:%x",error);
		
	   MessageBox(txt,_T("ERROR"),MB_OK);
	   return FALSE;
   }
   // Update DCB rate.
   dcb.BaudRate = CBR_4800 ;

   // Set new state.
   if (!SetCommState(hComm, &dcb))
      // Error in SetCommState. Possibly a problem with the communications 
      // port handle or a problem with the DCB structure itself.
		return FALSE;
	brslt=GetCommTimeouts(hComm,&ctm);
	ctm.ReadIntervalTimeout=3000;
	ctm.ReadTotalTimeoutConstant= 30;
	ctm.ReadTotalTimeoutMultiplier=20;
	brslt=SetCommTimeouts(hComm,&ctm);
 

   m_nTimer = SetTimer( IDT_TIMER1,            // timer identifier 
						1000,                 // 10-second interval 
						(TIMERPROC) NULL);     // no timer callback 
 
   return TRUE;




}
void CNMEAInstDlg::OnTimer(UINT_PTR nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnTimer(nIDEvent);
	

	OVERLAPPED osReader = {0};
	if(nIDEvent==IDT_TIMER1)
	{
		TRACE ("Timer in --->\n");
		UpdateData(false);
	   // done processing this buff
		TRACE ("<-- Timer 0ut\n");

   }
}
void CNMEAInstDlg::OnTest() 
{

	hComm = CreateFile( _T("nmea.txt"),  
                    GENERIC_READ | GENERIC_WRITE, 
                    0, 
                    0, 
                    OPEN_EXISTING,
                    FILE_FLAG_OVERLAPPED,
                    0);
	if (hComm == INVALID_HANDLE_VALUE)
   // error opening port;
	{
		MessageBox(_T("Test file open failed"),_T("ERROR"),MB_OK);
		return ;
	}
	DWORD dwRead;
	char lpBuf[516];
	char * bufptr = lpBuf;

	OVERLAPPED osReader = {0};
   // Issue read operation.
	memset(lpBuf,0,516);
   while ( ReadFile(hComm, bufptr, 512-(bufptr-lpBuf), &dwRead, NULL))
   {
	   char seps[] = "\n";
	   char *sentence;
		if (dwRead==0) break;
		/* Establish string and get the first token: */
	   sentence = strtok( lpBuf, seps );
	   while( sentence != NULL )
		{
		    int r=0; 
			char * end = NULL;
			char * endptr;
			char * nexts = strtok(NULL, seps);
			if((end = strchr( sentence, 0x0d)) != (endptr= sentence+ (r=strlen(sentence)-1) ))
			{
				strcpy(lpBuf,sentence);
				bufptr= lpBuf+strlen(sentence);
				break;
			}
		   ProcessSentence(sentence);
			// get the next sentence
			sentence = nexts;
			bufptr=lpBuf;
		}
	   // done processing this buff

   }
	CloseHandle(hComm);
}

void CNMEAInstDlg::ProcessSentence(char *sentence)
{
	char sseps[]   = ",\r";;
	char buff[512];
	strcpy(buff,sentence);
	CString sbuf;
	CString cmdstr=buff;
	
	// if logging, send to logfile
	if(m_bLog)
	{
		DWORD bsent;
		WriteFile(m_Hlogfile,cmdstr,cmdstr.GetLength(),&bsent,0);
	}
	int idx = cmdstr.Find(',');
	CString cmd = cmdstr.Left(idx);

	// first element is the identifier starts with $
	//$SSMMM   SS = sender GP-gps II-Instruments
	//         MMM = message type

	if(!cmd.IsEmpty())
	{
		
		CString sender = cmd.Left(3);
		CString sCmd = cmd.Right(3);
		NMEASentenceHandler * handler = getHandler(&sCmd);

		sbuf = cmdstr.Right(cmdstr.GetLength()-(idx+1));
		if(handler!=NULL)
			handler->process(sbuf,this);
		if(m_bLog)
		{

		}

	}
#if 0
	sbuf = cmdstr.Right(cmdstr.GetLength()-(idx+1));
	
	
	while( !sbuf.IsEmpty() )
	{
		CString element;
		int idx1 = sbuf.Find(',');
		if( idx1!=-1)
		{
			element=sbuf.Left(idx1);
			sbuf = sbuf.Right(sbuf.GetLength()-(idx1+1));
		}
		else
		{
			// last element usally checksum
			element = sbuf;
			break;
		}

	}
#endif
}

void CNMEAInstDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(m_reader!=0) m_reader->m_bRun = FALSE;
	cleanup();

	if(m_reader!=0)
	{
		for(int t=0; t<50000;t++)
		{
			for(int r=0; r<50000;r++)
			{
				if(!m_bAlive) break;
			}
			if(!m_bAlive) break;

		}
		if(m_nTimer) KillTimer(m_nTimer);
	}
	CDialog::OnClose();
}

void CNMEAInstDlg::OnLog() 
{
	UpdateData(true);
	
}

HRESULT CNMEAInstDlg::initLogfile()
{
	CString filename;

	m_Hlogfile = CreateFile( filename,  
                    GENERIC_READ | GENERIC_WRITE, 
                    0, 
                    0, 
                    CREATE_NEW,FILE_FLAG_OVERLAPPED,
                    0);
	if (m_Hlogfile == INVALID_HANDLE_VALUE)
   // error opening port;
	{
		MessageBox("Create logfile failed","ERROR",MB_OK);
		return -1;
	}
	return 0;
}
void  CNMEAInstDlg::SetConnected(LPCTSTR PortID)
{
	CWnd* pMain = AfxGetMainWnd();

	// The main window _can_ be NULL, so this code
	// doesn't ASSERT and actually tests.
	if (pMain != NULL)
	{
		// Get the main window's menu
		CMenu* pMenu = pMain->GetMenu();

		// If there is a menu and it has items, we'll
		// delete the first one.
		if (pMenu != NULL && pMenu->GetMenuItemCount() > 0)
		{
			int count = pMenu->GetMenuItemCount();
			for (int i = 0; i < count; i++)
			{
				CString str;
				if (pMenu->GetMenuString(i, str, MF_BYPOSITION))
				{
					if(strcmp(str, "Connect") == 0)
					{
						UINT id = pMenu->GetMenuItemID(i);
					    pMenu->ModifyMenu(i, MF_BYPOSITION, id, "&Disconnect");
						pMain->DrawMenuBar();
					}
				}
			}	
		}
	}
	StartReader();
	m_bConnected = TRUE;

}

void  CNMEAInstDlg::SetDisConnected(LPCTSTR PortID)
{
	CWnd* pMain = AfxGetMainWnd();

	// The main window _can_ be NULL, so this code
	// doesn't ASSERT and actually tests.
	if (pMain != NULL)
	{
		// Get the main window's menu
		CMenu* pMenu = pMain->GetMenu();
		UINT id = pMenu->GetMenuItemID(0);
	    pMenu->ModifyMenu(0, MF_BYPOSITION, id, "&Connect");
		pMain->DrawMenuBar();
		CloseHandle(hComm);

	}
	m_bConnected = FALSE;

}

void CNMEAInstDlg::StartReader()
{
	m_reader = (PortReader*)
	AfxBeginThread(RUNTIME_CLASS(PortReader), THREAD_PRIORITY_NORMAL,
			0, CREATE_SUSPENDED);
	m_reader->SetOwner(this);
	m_reader->SetSource(hComm);
	m_reader->m_bRun = TRUE;
	m_reader->m_bAutoDelete=TRUE;
	m_bAlive = TRUE;
	m_reader->ResumeThread();
}
void CNMEAInstDlg::OnCom1() 
{
	if(m_bConnected)
	{
		if(m_reader) m_reader->m_bRun = FALSE;
		SetDisConnected("COM2");	
	}
	else if(InitComms("COM1"))
	{
		SetConnected("COM1");	
	}
}

void CNMEAInstDlg::OnCom2() 
{
	if(m_bConnected)
	{
		if(m_reader) m_reader->m_bRun = FALSE;
		SetDisConnected("COM2");	

	}
	else if(InitComms("COM2"))
	{
		SetConnected("COM2");	
	}
}

void CNMEAInstDlg::OnCom3() 
{
	if(m_bConnected)
	{
		if(m_reader) m_reader->m_bRun = FALSE;
		SetDisConnected("COM2");	
	}
	else	if(InitComms("COM3"))
	{
		SetConnected("COM3");	
	}
}

void CNMEAInstDlg::OnCom4() 
{
	if(m_bConnected)
	{
		if(m_reader) m_reader->m_bRun = FALSE;
		SetDisConnected("COM2");	
	}
	else	if(InitComms("COM4"))
	{
		SetConnected("COM4");	
	}
}

void CNMEAInstDlg::OnConnectCom10() 
{
	if(m_bConnected)
	{
		if(m_reader) m_reader->m_bRun = FALSE;
		SetDisConnected("COM5");	
	}
	else	if(InitComms("COM5"))
	{
		SetConnected("COM5");	
	}
}
	

