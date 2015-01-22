// First.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "First.h"
#include "afxdialogex.h"


// CFirst 대화 상자입니다.

IMPLEMENT_DYNAMIC(CFirst, CDialogEx)

CFirst::CFirst(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFirst::IDD, pParent)
{

		//CString tabOne = _T("요리검색");
	//CString tabTwo = _T("레시피 검색");

	//m_MainTab.InsertItem(1,tabOne);
	//m_MainTab.InsertItem(2,tabTwo);

}
BOOL CFirst::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	CString tabOne = _T("요리검색");
	CString tabTwo = _T("레시피 검색");

	m_MainTab.InsertItem(1,tabOne);
	m_MainTab.InsertItem(2,tabTwo);

	CRect rect;
	m_MainTab.GetClientRect(&rect);
	m_tab1.Create(IDD_COOKTALK_MENUSELECTOR_DIALOG,&m_MainTab);
	m_tab1.SetWindowPos(NULL, 5, 25, rect.Width() -10, rect.Height() -30, SWP_SHOWWINDOW | SWP_NOZORDER);

	m_tab2.Create(IDD_DIALOG2,&m_MainTab);
	m_tab2.SetWindowPos(NULL,5, 25, rect.Width() -10, rect.Height() -30, SWP_NOZORDER);

	m_pwndShow = &m_tab1;

	return TRUE;
}

CFirst::~CFirst()
{
}

void CFirst::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_MainTab);
}


BEGIN_MESSAGE_MAP(CFirst, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CFirst::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CFirst 메시지 처리기입니다.


void CFirst::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	if(m_pwndShow != NULL)
	{
		m_pwndShow->ShowWindow(SW_HIDE);
		m_pwndShow = NULL;
	}

	int tabIndex = m_MainTab.GetCurSel();

	switch(tabIndex)
	{
		case 0:
			m_tab1.ShowWindow(SW_SHOW);
			m_pwndShow=&m_tab1;
			break;
		case 1:
			m_tab2.ShowWindow(SW_SHOW);
			m_pwndShow = &m_tab2;
			break;
	}
	*pResult = 0;
}
