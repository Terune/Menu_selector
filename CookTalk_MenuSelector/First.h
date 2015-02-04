#pragma once
#include "afxcmn.h"
#include "CookTalk_MenuSelectorDlg.h"
#include "Tab2.h"
#include "Tab3.h"

// CFirst 대화 상자입니다.

class CFirst : public CDialogEx
{
	DECLARE_DYNAMIC(CFirst)

public:
	CFirst(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CFirst();

	CCookTalk_MenuSelectorDlg m_tab1;
	CTab2 m_tab2;
	CTab3 m_tab3;

	CWnd* m_pwndShow;


// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	HICON m_hIcon;
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_MainTab;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
