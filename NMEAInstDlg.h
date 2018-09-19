// NMEAInstDlg.h : header file
//

#if !defined(AFX_NMEAINSTDLG_H__8EE80CC8_E182_11D8_BF98_00D0591A7DED__INCLUDED_)
#define AFX_NMEAINSTDLG_H__8EE80CC8_E182_11D8_BF98_00D0591A7DED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "speedo.h"
#include "NMEAManager.h"
#include "PortReader.h"

/////////////////////////////////////////////////////////////////////////////
//#define 	IDT_TIMER1 0x20
#define 	IDT_TIMER1 0x21

// CNMEAInstDlg dialog

class CNMEAInstDlg : public CDialog , public NMEAManager
{
// Construction
public:
	CSpeedo * m_compas;
	CSpeedo * m_boat_speed;
	CSpeedo * m_sog;
	CSpeedo * m_wptdir;
	CSpeedo * m_wind_speed;
	CSpeedo * m_wind_dir;
	PortReader * m_reader;
	
	CNMEAInstDlg(CWnd* pParent = NULL);	// standard constructor
	void StartReader();
	void SetConnected(LPCTSTR);
	void SetDisConnected(LPCTSTR );
	BOOL InitComms(LPCTSTR);
	BOOL m_bAlive;
// Dialog Data
	//{{AFX_DATA(CNMEAInstDlg)
	enum { IDD = IDD_NMEAINST_DIALOG };
	CString	m_lat;
	CString	m_long;
	CString	m_heading;
	CString	m_wayptLat;
	CString	m_wayptLong;
	CString	m_wayptName;
	CString	m_wpHead;
	CString	m_wpDist;
	CString	m_date;
	CString	m_time;
	BOOL	m_bLog;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNMEAInstDlg)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL
	public:
		void ProcessSentence(char * sentence);

// Implementation
protected:
	HICON m_hIcon;
	HANDLE hComm;
	char gszPort[10];
//	NMEAManager m_manager;
	// Generated message map functions
	//{{AFX_MSG(CNMEAInstDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnTest();
	afx_msg void OnClose();
	afx_msg void OnLog();
	afx_msg void OnCom1();
	afx_msg void OnCom2();
	afx_msg void OnCom3();
	afx_msg void OnCom4();
	afx_msg void OnConnectCom10();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bConnected;
	UINT m_nTimer;
	HRESULT initLogfile();
	HANDLE m_Hlogfile;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NMEAINSTDLG_H__8EE80CC8_E182_11D8_BF98_00D0591A7DED__INCLUDED_)
