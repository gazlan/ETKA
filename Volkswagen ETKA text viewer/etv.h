// etv.h : main header file for the ETV application
//

#if !defined(AFX_ETV_H__C4B4FA29_77FE_40C4_B852_89DC94FC672D__INCLUDED_)
#define AFX_ETV_H__C4B4FA29_77FE_40C4_B852_89DC94FC672D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEtvApp:
// See etv.cpp for the implementation of this class
//

class CEtvApp : public CWinApp
{
public:
	CEtvApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEtvApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEtvApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ETV_H__C4B4FA29_77FE_40C4_B852_89DC94FC672D__INCLUDED_)
