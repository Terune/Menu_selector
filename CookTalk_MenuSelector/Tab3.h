#pragma once
#include "afxwin.h"
#include "Selection.h"
#include "Stack.h"

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
	void ViewNowValue();
	void Doact(CString act);
	void Doact(CString act,CString Slot);
	void Doact(CString act,CString Slot,CString value);
	CString Menu_Con(CString con);
	CString Menu_Type(CString type);
	CString Conv_Korean(CString ename);
	CString Menu_Material(CString menu);
	//CString impl_confirm(CString slot,CString Value);
	CString Find_recipe(CString menu,int level);
	void get_bymaterial();
	void get_bytype();
	void get_bycon();
	CString Find_Material(CString language);
	CString Find_menu();
	int returnMaterialNum(CString input);
	CString ComboName;
	DECLARE_MESSAGE_MAP()
	CMap<CString,LPCTSTR,CString,LPCTSTR> slots;
	CString deny_In_slot;
	CString deny_In_value;
	CString inform_In_slot;
	CString inform_In_value;
	CString Confirm_In_slot;
	CString Confirm_In_value;
	//CString now_act;
	Stack<CString> now_act;
	Stack<CString> now_slot;
	Stack<CString> now_value;
	CString print_act;
	CString print_DA;
	CString Slot_input;
	int Materials[55];
	int Check_Input[12];

public:
	CComboBox m_comboDenyList;
	CComboBox m_comboInformList;
	//int ClickList;//0:deny, 1:inform
	afx_msg void OnBnClickedCheck12();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedCheck19();
	afx_msg void OnBnClickedCheck18();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton12();
	CComboBox m_ComboConfirmList;
	CComboBox m_ComboRequestList;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck14();
	afx_msg void OnBnClickedCheck15();
	afx_msg void OnBnClickedCheck17();
	afx_msg void OnBnClickedCheck16();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton1();
};
