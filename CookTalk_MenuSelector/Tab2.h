#pragma once
#include "afxcmn.h"


// CTab2 ��ȭ �����Դϴ�.

class CTab2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab2)

public:
	CTab2(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTab2();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ManuList;
	CListCtrl m_MaterialList;
	CListCtrl m_RecipeList;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnNMDblclkList3(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnHdnItemdblclickList3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkList3(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult);
};
