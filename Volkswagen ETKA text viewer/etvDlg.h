#if !defined(AFX_ETVDLG_H__9883740B_C597_4144_A841_7D544DCC0FB5__INCLUDED_)
#define AFX_ETVDLG_H__9883740B_C597_4144_A841_7D544DCC0FB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEtvDlg : public CDialog
{
   private:

      FILE*             _pOut;
      CString           _sDBPath;

// Construction
public:
	CEtvDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEtvDlg)
	enum { IDD = IDD_ETV_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEtvDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEtvDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

   private:

      void  Print_01(BYTE F1,BYTE F2,BYTE F3,BYTE F4,BYTE F5,const BYTE* const pCurr,WORD wSize,const BYTE* const pBuf);
      void  Print_02(BYTE F1,BYTE F2,BYTE F3,BYTE F4,BYTE F5,const BYTE* const pCurr,WORD wSize,const BYTE* const pBuf);
      void  Print_03(BYTE F1,BYTE F2,BYTE F3,BYTE F4,BYTE F5,const BYTE* const pCurr,WORD wSize,const BYTE* const pBuf);
      void  Print_XX(BYTE F0,BYTE F1,BYTE F2,BYTE F3,BYTE F4,BYTE F5,const BYTE* const pCurr,WORD wSize,const BYTE* const pBuf);

      void  Print_22(BYTE byTextSize,BYTE* pNext,WORD wSize);
      void  Print_22_60(BYTE byTextSize,BYTE* pNext,WORD wSize);

      void  Print_23(BYTE byTextSize,BYTE* pNext,WORD wSize);
      void  Print_23_40(BYTE byTextSize,BYTE* pNext,WORD wSize);
      
      void  Print_2A(BYTE byTextSize,BYTE* pNext,WORD wSize);
      void  Print_2A_60(BYTE byTextSize,BYTE* pNext,WORD wSize);

      void  GetOverviewInfo(const CString& sPath);

      const char* const GetRegion(const char* const pszAbbr);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ETVDLG_H__9883740B_C597_4144_A841_7D544DCC0FB5__INCLUDED_)
