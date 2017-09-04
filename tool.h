#if !defined(AFX_TOOL_H__A5BD15C0_F11C_4238_96D0_0D1235A9889F__INCLUDED_)
#define AFX_TOOL_H__A5BD15C0_F11C_4238_96D0_0D1235A9889F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Tool.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTool dialog

class CTool : public CDialog
{
// Construction
public:
	CTool(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTool)
	enum { IDD = IDD_TOOL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTool)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTool)
	afx_msg void OnButton();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOL_H__A5BD15C0_F11C_4238_96D0_0D1235A9889F__INCLUDED_)
