#pragma once
#include "afxcmn.h"
#include "Tab3.h"

// CSelection ��ȭ �����Դϴ�.

class CSelection : public CDialogEx
{
	DECLARE_DYNAMIC(CSelection)

public:
	CSelection(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSelection();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();
	CString Matching_name(CString input);
	CString Sel_name;
	int Sel_value;
	CString List_Select;
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_SelectList;
	void SetUserData(CString Select_name, int Select_Tema);
	void GetUserData(CString &parm_name);
	afx_msg void OnBnClickedOk();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
