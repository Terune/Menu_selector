
// CookTalk_MenuSelectorDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "CookTalk_MenuSelectorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

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


// CCookTalk_MenuSelectorDlg 대화 상자



CCookTalk_MenuSelectorDlg::CCookTalk_MenuSelectorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCookTalk_MenuSelectorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCookTalk_MenuSelectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCookTalk_MenuSelectorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CCookTalk_MenuSelectorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &CCookTalk_MenuSelectorDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK3, &CCookTalk_MenuSelectorDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK1, &CCookTalk_MenuSelectorDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CCookTalk_MenuSelectorDlg::OnBnClickedCheck2)
//	ON_BN_CLICKED(IDC_STATIC3, &CCookTalk_MenuSelectorDlg::OnBnClickedStatic3)
END_MESSAGE_MAP()


// CCookTalk_MenuSelectorDlg 메시지 처리기

BOOL CCookTalk_MenuSelectorDlg::OnInitDialog()
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

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCookTalk_MenuSelectorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCookTalk_MenuSelectorDlg::OnPaint()
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

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCookTalk_MenuSelectorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCookTalk_MenuSelectorDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCookTalk_MenuSelectorDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}




void CheckGroup(INT CheckID, INT GroupID, CWnd* pWndParent)
{
    // 일단 버튼의 첵크 상태를 읽ㅇ온다.
    BOOL bCheck = pWndParent->IsDlgButtonChecked(CheckID);
    
    CRect rcGroup, rcChild;
    
    // 그룹박스의 영역 정보를 읽어온다.
    pWndParent->GetDlgItem(GroupID)->GetWindowRect(rcGroup);
    
    // 현재 다이알로그의 차일드 윈도우중 첫번째 것을 가져온다.
    CWnd* pWnd = pWndParent->GetWindow(GW_CHILD);
    while (pWnd)
    {
        // 해당 그룹과, 버튼을 제외한 차일드 윈도우.
        if(pWnd->GetDlgCtrlID() != CheckID && pWnd->GetDlgCtrlID() != GroupID)
        {
            pWnd->GetWindowRect(rcChild);
            if (rcChild.IntersectRect(rcGroup, rcChild))
                pWnd->EnableWindow(bCheck);
        }
        pWnd = pWnd->GetWindow(GW_HWNDNEXT);
    }
}


void CCookTalk_MenuSelectorDlg::OnBnClickedCheck1()
{
	 CheckGroup(IDC_CHECK1,IDC_STATIC1 , this);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CCookTalk_MenuSelectorDlg::OnBnClickedCheck2()
{
	CheckGroup(IDC_CHECK2,IDC_STATIC2 , this);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CCookTalk_MenuSelectorDlg::OnBnClickedCheck3()
{
	CheckGroup(IDC_CHECK3,IDC_STATIC3 , this);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//void CCookTalk_MenuSelectorDlg::OnBnClickedStatic3()
//{
//	CheckGroup(IDC_CHECK3,IDC_STATIC3 , this);
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}
