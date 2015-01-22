// First.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "First.h"
#include "afxdialogex.h"


// CFirst 대화 상자입니다.
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.


	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

IMPLEMENT_DYNAMIC(CFirst, CDialogEx)

CFirst::CFirst(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFirst::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		//CString tabOne = _T("요리검색");
	//CString tabTwo = _T("레시피 검색");

	//m_MainTab.InsertItem(1,tabOne);
	//m_MainTab.InsertItem(2,tabTwo);

}
BOOL CFirst::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

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


// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFirst::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFirst::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

void CFirst::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_MainTab);
}


BEGIN_MESSAGE_MAP(CFirst, CDialogEx)

	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
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
void CFirst::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

