#pragma once
#include "afxwin.h"
#include "Selection.h"

// CTab3 ��ȭ �����Դϴ�.

class CTab3 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab3)

public:
	CTab3(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTab3();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
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
