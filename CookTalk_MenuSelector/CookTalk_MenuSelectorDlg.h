
// CookTalk_MenuSelectorDlg.h : ��� ����
//

#pragma once


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
//	afx_msg void OnBnClickedStatic3();
};
