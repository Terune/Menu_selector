
// CookTalk_MenuSelectorDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"

#ifndef ListView_SetCheckState
#define ListView_SetCheckState(hwndLV, i, fCheck) \
        ListView_SetItemState(hwndLV, i, \
        INDEXTOSTATEIMAGEMASK((fCheck)+1), LVIS_STATEIMAGEMASK)
#endif

// CCookTalk_MenuSelectorDlg 대화 상자
class CCookTalk_MenuSelectorDlg : public CDialogEx
{
// 생성입니다.
public:
	CCookTalk_MenuSelectorDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_COOKTALK_MENUSELECTOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	/*HICON m_hIcon;*/
	//void CheckGroup(INT CheckID, INT GroupID, CWnd* pWndParent);
	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	//afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//afx_msg void OnPaint();
	/*afx_msg HCURSOR OnQueryDragIcon();*/
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
	afx_msg void SetConValue();
	int con_Radio;
	int Type_Radio;

	CListCtrl m_MaterialList;
	afx_msg void OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck5();
};
