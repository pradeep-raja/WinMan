// WinManDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WinMan.h"
#include "WinManDlg.h"
#include "tool.h"
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
// CWinManDlg dialog

CWinManDlg::CWinManDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWinManDlg::IDD, pParent)

{
	//{{AFX_DATA_INIT(CWinManDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	s_all = 0;
}

void CWinManDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWinManDlg)
	DDX_Control(pDX, IDC_LIST, m_ListBox);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWinManDlg, CDialog)
	//{{AFX_MSG_MAP(CWinManDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SHOWWINDOW()
	ON_WM_SIZE()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	ON_WM_TIMER()
	ON_COMMAND(ID_WINMAN_REFRESH, OnWinmanRefresh)
	ON_COMMAND(ID_WINMAN_SHOWALL, OnWinmanShowall)
	ON_COMMAND(ID_VIEW_ICONIC, OnViewIconic)
	ON_NOTIFY(NM_CLICK, IDC_LIST, OnClickList)
	ON_NOTIFY(NM_RCLICK, IDC_LIST, OnRclickList)
	ON_COMMAND(ID_A_MAXIMIZEWINDOW, OnAMaximizewindow)
	ON_COMMAND(ID_A_MINIMIZEWINDOW, OnAMinimizewindow)
	ON_COMMAND(ID_A_SHOWNORMAL, OnAShownormal)
	ON_COMMAND(ID_A_HIDEWINDOW, OnAHidewindow)
	ON_COMMAND(ID_WINDOW_RESTOREWINDOW, OnWindowRestorewindow)
	ON_COMMAND(ID_HELP_ABOUTWINMAN, OnHelpAboutwinman)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWinManDlg message handlers

BOOL CWinManDlg::OnInitDialog()
{
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

	m_ListBox.InsertColumn(0, L"Application", LVCFMT_LEFT, 300);
	m_ListBox.InsertColumn(1, L"Handle", LVCFMT_LEFT, 100);
	m_ListBox.InsertColumn(2, L"State", LVCFMT_LEFT, 100);

	Load();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWinManDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWinManDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);

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
HCURSOR CWinManDlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}

void CWinManDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);
}

void CWinManDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	static __int16 firVar;

	if (firVar == 0)
	{
		firVar = 1;
	}
	else
	{
		m_ListBox.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOMOVE);
	}

}

void CWinManDlg::Load()
{
	int irr = 0;

	HWND hFirst = ::GetWindow(m_hWnd, GW_HWNDFIRST);
	if (hFirst)
	{
		Display(hFirst, irr);
	}

	for (; hFirst != NULL;)
	{
		hFirst = ::GetWindow(hFirst, GW_HWNDNEXT);
		if (hFirst)
		{
			Display(hFirst, irr);
		}
	}
}

void CWinManDlg::UpdateWindowStatus(HWND h, int ir)
{
	if (::IsWindowVisible(h))
	{
		if (::IsIconic(h))
		{
			m_ListBox.SetItemText(ir, 2, L"Minimized");
		}
		else
		{
			m_ListBox.SetItemText(ir, 2, L"Normal/Maximized");
		}
	}
	else
	{
		m_ListBox.SetItemText(ir, 2, L"Invisible");
	}
}

void CWinManDlg::Display(HWND &h, int& ir)
{
	wchar_t winCap[200];
	int totFound = ::GetWindowText(h, winCap, 200);
	winCap[totFound] = 0;

	CString s_winCap = winCap;
	s_winCap.TrimLeft();
	s_winCap.TrimRight();

	if (totFound == 0)
	{
		wchar_t winCls[200];
		int totFound_ = ::GetClassName(h, winCls, 200);
		winCls[totFound_] = 0;
		s_winCap = winCls;
	}

	if ((::IsWindowVisible(h)) || (s_all))
	{
		CString s;
		s.Format(L"%d", reinterpret_cast<int>(h));
		ir++;
		m_ListBox.InsertItem(ir, s_winCap);
		m_ListBox.SetItemText(ir - 1, 1, s);
		if (::IsIconic(h))
		{
			m_ListBox.SetItemText(ir - 1, 2, L"Minimized");

		}
		else if (!::IsWindowVisible(h))
		{
			m_ListBox.SetItemText(ir - 1, 2, L"Invisible");
		}
		else
		{
			m_ListBox.SetItemText(ir - 1, 2, L"Normal/Maximized");
		}
	}
}

void CWinManDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult)
{
	int selMark = m_ListBox.GetSelectionMark();
	if (selMark != -1)
	{
		CString s = m_ListBox.GetItemText(selMark, 1);

		int hw = 0;
		swscanf(s.GetBuffer(0), L"%d", &hw);

		HWND h = reinterpret_cast<HWND>(hw);

		int windowState = ::IsWindowVisible(h);
		if (windowState)
		{
			windowState = 0;
			m_ListBox.SetItemText(selMark, 2, L"Invisible");
		}
		else
		{
			windowState = 8;
			if (::IsIconic(h))
			{
				m_ListBox.SetItemText(selMark, 2, L"Minimized");
			}
			else
			{
				m_ListBox.SetItemText(selMark, 2, L"Normal/Maximized");
			}
		}

		::ShowWindow(h, windowState);
	}

	*pResult = 0;
}

void CWinManDlg::OnTimer(UINT nIDEvent)
{
	CDialog::OnTimer(nIDEvent);
}

void CWinManDlg::OnWinmanRefresh()
{
	m_ListBox.DeleteAllItems();
	Load();
}

void CWinManDlg::OnWinmanShowall()
{

	CMenu* menu = GetMenu()->GetSubMenu(0);

	int s = s_all ? MF_UNCHECKED : MF_CHECKED;
	menu->CheckMenuItem(1, MF_BYPOSITION | s);

	s_all = !s_all;

	m_ListBox.DeleteAllItems();

	Load();
}

void CWinManDlg::OnViewIconic()
{

	ShowWindow(FALSE);
	CTool dl;
	dl.DoModal();

}

void CWinManDlg::OnClickList(NMHDR* pNMHDR, LRESULT* pResult)
{
	*pResult = 0;
}

void CWinManDlg::OnRclickList(NMHDR* pNMHDR, LRESULT* pResult)
{
	CMenu m;
	m.LoadMenu(IDR_MENU);
	CMenu *pm = m.GetSubMenu(2);

	POINT pt;
	GetCursorPos(&pt);

	pm->TrackPopupMenu(NULL, pt.x, pt.y, this);

	*pResult = 0;
}

void CWinManDlg::OnAMaximizewindow()
{
	int sMark = m_ListBox.GetSelectionMark();
	if (sMark != -1)
	{
		CString s = m_ListBox.GetItemText(sMark, 1);

		int iH(0);
		swscanf(s.GetBuffer(0), L"%d", &iH);
		if (iH)
		{
			::ShowWindow(reinterpret_cast<HWND>(iH), SW_SHOWMAXIMIZED);
			UpdateWindowStatus(reinterpret_cast<HWND>(iH), sMark);
		}

	}
}

void CWinManDlg::OnAMinimizewindow()
{
	int sMark = m_ListBox.GetSelectionMark();
	if (sMark != -1)
	{
		CString s = m_ListBox.GetItemText(sMark, 1);

		int iH(0);
		swscanf(s.GetBuffer(0), L"%d", &iH);
		if (iH)
		{
			::ShowWindow(reinterpret_cast<HWND>(iH), SW_SHOWMINIMIZED);
			UpdateWindowStatus(reinterpret_cast<HWND>(iH), sMark);
		}

	}
}

void CWinManDlg::OnAShownormal()
{

	int sMark = m_ListBox.GetSelectionMark();
	if (sMark != -1)
	{
		CString s = m_ListBox.GetItemText(sMark, 1);

		int iH(0);
		swscanf(s.GetBuffer(0), L"%d", &iH);
		if (iH)
		{
			::ShowWindow(reinterpret_cast<HWND>(iH), SW_SHOWNA);
			UpdateWindowStatus(reinterpret_cast<HWND>(iH), sMark);
		}

	}
}

void CWinManDlg::OnAHidewindow()
{
	int sMark = m_ListBox.GetSelectionMark();
	if (sMark != -1)
	{
		CString s = m_ListBox.GetItemText(sMark, 1);

		int iH(0);
		swscanf(s.GetBuffer(0), L"%d", &iH);
		if (iH)
		{
			::ShowWindow(reinterpret_cast<HWND>(iH), FALSE);
			UpdateWindowStatus(reinterpret_cast<HWND>(iH), sMark);
		}

	}

}

void CWinManDlg::OnWindowRestorewindow()
{
	int sMark = m_ListBox.GetSelectionMark();
	if (sMark != -1)
	{
		CString s = m_ListBox.GetItemText(sMark, 1);

		int iH(0);
		swscanf(s.GetBuffer(0), L"%d", &iH);
		if (iH)
		{
			::ShowWindow(reinterpret_cast<HWND>(iH), SW_SHOWNORMAL);
			UpdateWindowStatus(reinterpret_cast<HWND>(iH), sMark);
		}

	}
}

void CWinManDlg::OnHelpAboutwinman()
{
	CAboutDlg dlg;
	dlg.DoModal();
}
