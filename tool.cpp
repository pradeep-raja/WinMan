// Tool.cpp : implementation file
//

#include "stdafx.h"
#include "WinMan.h"
#include "Tool.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTool dialog


CTool::CTool(CWnd* pParent /*=NULL*/)
	: CDialog(CTool::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTool)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTool)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTool, CDialog)
	//{{AFX_MSG_MAP(CTool)
	ON_BN_CLICKED(IDC_BUTTON, OnButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTool message handlers

void CTool::OnButton() 
{
	AfxGetApp()->m_pMainWnd->ShowWindow(SW_SHOWNA);
	
	
	CDialog::OnCancel();
}

BOOL CTool::OnInitDialog() 
{
	CDialog::OnInitDialog();
	

	POINT pt;
	pt.x = 0;
	pt.y = 0;
	ClientToScreen(&pt);
	SetWindowPos(NULL,730,510,0,0,SWP_NOSIZE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTool::OnCancel() 
{

	AfxGetApp()->m_pMainWnd->ShowWindow(1);
	
	CDialog::OnCancel();
}
