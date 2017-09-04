// WinMan.h : main header file for the WINMAN application
//

#if !defined(AFX_WINMAN_H__4FA540B8_9090_476E_917F_CB5F119791F9__INCLUDED_)
#define AFX_WINMAN_H__4FA540B8_9090_476E_917F_CB5F119791F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWinManApp:
// See WinMan.cpp for the implementation of this class
//

class CWinManApp : public CWinApp
{
public:
	CWinManApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinManApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWinManApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINMAN_H__4FA540B8_9090_476E_917F_CB5F119791F9__INCLUDED_)
