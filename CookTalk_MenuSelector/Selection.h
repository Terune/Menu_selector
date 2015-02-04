#pragma once
#include "afxcmn.h"
#include "Tab3.h"

// CSelection 대화 상자입니다.

class CSelection : public CDialogEx
{
	DECLARE_DYNAMIC(CSelection)

public:
	CSelection(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSelection();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
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
