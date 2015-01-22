#pragma once
#include "afxcmn.h"
#include "CookTalk_MenuSelectorDlg.h"
#include "Tab2.h"

// CFirst ��ȭ �����Դϴ�.

class CFirst : public CDialogEx
{
	DECLARE_DYNAMIC(CFirst)

public:
	CFirst(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CFirst();

	CCookTalk_MenuSelectorDlg m_tab1;
	CTab2 m_tab2;

	CWnd* m_pwndShow;


// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_MainTab;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
