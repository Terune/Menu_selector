
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
	, con_Radio(0)
	, Type_Radio(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCookTalk_MenuSelectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, con_Radio);
	DDX_Radio(pDX, IDC_RADIO4, Type_Radio);
	DDX_Control(pDX, IDC_LIST3, m_MaterialList);
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
	ON_CONTROL_RANGE(BN_CLICKED,IDC_RADIO1,IDC_RADIO3,CCookTalk_MenuSelectorDlg::SetRadioStatus1)
	ON_CONTROL_RANGE(BN_CLICKED,IDC_RADIO4,IDC_RADIO5,CCookTalk_MenuSelectorDlg::SetRadioStatus2)
	ON_NOTIFY(NM_CLICK, IDC_LIST3, &CCookTalk_MenuSelectorDlg::OnNMClickList3)
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
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(false);
	((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(false);

	m_MaterialList.InsertItem(0,TEXT("가지"));
	m_MaterialList.InsertItem(0,TEXT("감자"));
	m_MaterialList.InsertItem(0,TEXT("계피가루"));
	m_MaterialList.InsertItem(0,TEXT("고구마"));
	m_MaterialList.InsertItem(0,TEXT("꿀"));
	m_MaterialList.InsertItem(0,TEXT("냉동피자"));
	m_MaterialList.InsertItem(0,TEXT("다진 돼지고기"));
	m_MaterialList.InsertItem(0,TEXT("다진 마늘"));
	m_MaterialList.InsertItem(0,TEXT("다진 쇠고기"));
	m_MaterialList.InsertItem(0,TEXT("다진 실파"));
	m_MaterialList.InsertItem(0,TEXT("달걀"));
	m_MaterialList.InsertItem(0,TEXT("닭다리"));
	m_MaterialList.InsertItem(0,TEXT("대추"));
	m_MaterialList.InsertItem(0,TEXT("돼지고기 립"));
	m_MaterialList.InsertItem(0,TEXT("또띠아"));
	m_MaterialList.InsertItem(0,TEXT("멥쌀"));
	m_MaterialList.InsertItem(0,TEXT("모짜렐라 치즈"));
	m_MaterialList.InsertItem(0,TEXT("바닐라오일"));
	m_MaterialList.InsertItem(0,TEXT("박력분"));
	m_MaterialList.InsertItem(0,TEXT("밤"));
	m_MaterialList.InsertItem(0,TEXT("버터"));
	m_MaterialList.InsertItem(0,TEXT("베이글"));
	m_MaterialList.InsertItem(0,TEXT("베이컨"));
	m_MaterialList.InsertItem(0,TEXT("베이킹 소다"));
	m_MaterialList.InsertItem(0,TEXT("베이킹 파우더"));
	m_MaterialList.InsertItem(0,TEXT("블랙 올리브"));
	m_MaterialList.InsertItem(0,TEXT("생닭"));
	m_MaterialList.InsertItem(0,TEXT("생크림"));
	m_MaterialList.InsertItem(0,TEXT("스파게티면"));
	m_MaterialList.InsertItem(0,TEXT("식빵"));
	m_MaterialList.InsertItem(0,TEXT("식은밥"));
	m_MaterialList.InsertItem(0,TEXT("양송이"));
	m_MaterialList.InsertItem(0,TEXT("양파"));
	m_MaterialList.InsertItem(0,TEXT("오레가노"));
	m_MaterialList.InsertItem(0,TEXT("올리고당"));
	m_MaterialList.InsertItem(0,TEXT("우스터 소스"));
	m_MaterialList.InsertItem(0,TEXT("월계수잎"));
	m_MaterialList.InsertItem(0,TEXT("육수"));
	m_MaterialList.InsertItem(0,TEXT("은행"));
	m_MaterialList.InsertItem(0,TEXT("잣"));
	m_MaterialList.InsertItem(0,TEXT("적포도주"));
	m_MaterialList.InsertItem(0,TEXT("중력분"));
	m_MaterialList.InsertItem(0,TEXT("찹쌀"));
	m_MaterialList.InsertItem(0,TEXT("청피망"));
	m_MaterialList.InsertItem(0,TEXT("초코칩"));
	m_MaterialList.InsertItem(0,TEXT("콩"));
	m_MaterialList.InsertItem(0,TEXT("크림치즈"));
	m_MaterialList.InsertItem(0,TEXT("토마토 페이스트"));
	m_MaterialList.InsertItem(0,TEXT("통삽겹살"));
	m_MaterialList.InsertItem(0,TEXT("파마산 치즈"));
	m_MaterialList.InsertItem(0,TEXT("파슬리 가루"));
	m_MaterialList.InsertItem(0,TEXT("피자 빵가루"));
	m_MaterialList.InsertItem(0,TEXT("피자소스"));
	m_MaterialList.InsertItem(0,TEXT("햄"));
	m_MaterialList.InsertItem(0,TEXT("홍피망"));
	//ListView_SetItem((HWND)GetDlgItem(IDC_LIST3),"피자");
	//IDC_LIST3->

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
			{
                pWnd->EnableWindow(bCheck);
				if(bCheck==false)
				{
					((CButton*)pWnd)->SetCheck(false);
					
				}
			}
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


void CCookTalk_MenuSelectorDlg::SetRadioStatus1(UINT value)
{
	UpdateData(TRUE);
	
	switch(con_Radio)
	{
		case 0:
			//CEdit* p=(CEdit*)GetDlgItem(IDC_EDIT2);
			//p->SetWindowTextW("법량접시");
			SetDlgItemTextW(IDC_EDIT2,TEXT("법량접시"));
			//((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(false);
			//EnableWindow(IDC_RADIO1,1);
			break;
		case 1:
			SetDlgItemTextW(IDC_EDIT2,TEXT("석쇠"));
			break;
		case 2:
			SetDlgItemTextW(IDC_EDIT2,TEXT("구이전용팬"));
			break;
		default:
			SetDlgItemTextW(IDC_EDIT2,TEXT("없음"));
			break;
	}
}
void CCookTalk_MenuSelectorDlg::SetRadioStatus2(UINT value)
{
	UpdateData(TRUE);
	
	switch(Type_Radio)
	{
		case 0:
			//CEdit* p=(CEdit*)GetDlgItem(IDC_EDIT2);
			//p->SetWindowTextW("법량접시");
			SetDlgItemTextW(IDC_EDIT2,TEXT("오븐"));
			//((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(false);
			//EnableWindow(IDC_RADIO1,1);
			break;
		case 1:
			SetDlgItemTextW(IDC_EDIT2,TEXT("토스트"));
			break;
		default:
			SetDlgItemTextW(IDC_EDIT2,TEXT("없음"));
			break;
	}
}

void CCookTalk_MenuSelectorDlg::OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;
	int index = pNMView->iItem;

	SetDlgItemTextW(IDC_EDIT2,(LPCTSTR)index);
	*pResult = 0;
}
