#pragma once
#include "afxwin.h"
#include "Selection.h"

// CTab3 대화 상자입니다.

class CTab3 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab3)

public:
	CTab3(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTab3();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual BOOL OnInitDialog();
	CString ComboName;
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboDenyList;
	CComboBox m_comboInformList;
	//int ClickList;//0:deny, 1:inform
	afx_msg void OnBnClickedCheck12();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton9();
};
