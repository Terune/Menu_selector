
// CookTalk_MenuSelectorDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CCookTalk_MenuSelectorDlg ��ȭ ����
class CCookTalk_MenuSelectorDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCookTalk_MenuSelectorDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_COOKTALK_MENUSELECTOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;
	//void CheckGroup(INT CheckID, INT GroupID, CWnd* pWndParent);
	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedRadio1();
	afx_msg void SetRadioStatus1(UINT value);//con control
	afx_msg void SetRadioStatus2(UINT value);//type control
	int con_Radio;
	int Type_Radio;
	CListCtrl m_MaterialList;
	afx_msg void OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult);
};
