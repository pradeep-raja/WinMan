// WinManDlg.h : header file
//

#if !defined(AFX_WINMANDLG_H__8E2CA492_0490_492B_9142_FF7047947420__INCLUDED_)
#define AFX_WINMANDLG_H__8E2CA492_0490_492B_9142_FF7047947420__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWinManDlg dialog

class CWinManDlg : public CDialog
{
// Construction
public:
	void Display(HWND &h,int& ir);
	void Load();
    void UpdateWindowStatus(HWND h, int ir);
	CWinManDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL s_all;
// Dialog Data
	//{{AFX_DATA(CWinManDlg)
	enum { IDD = IDD_WINMAN_DIALOG };
	CListCtrl	m_ListBox;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinManDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWinManDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnWinmanRefresh();
	afx_msg void OnWinmanShowall();
	afx_msg void OnViewIconic();
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAMaximizewindow();
	afx_msg void OnAMinimizewindow();
	afx_msg void OnAShownormal();
	afx_msg void OnAHidewindow();
	afx_msg void OnWindowRestorewindow();
	afx_msg void OnHelpAboutwinman();    
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINMANDLG_H__8E2CA492_0490_492B_9142_FF7047947420__INCLUDED_)
