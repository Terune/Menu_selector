
// CookTalk_MenuSelectorDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "CookTalk_MenuSelectorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define MENU_NUM 25
#define MATERIAL_NUM 55

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
int material_point[25];
int type_point[25];
int con_point[25];

BOOL __ClipCopy(char *txt);
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
		//CString tabOne = _T("요리검색");
	//CString tabTwo = _T("레시피 검색");

	//m_MainTab.InsertItem(1,tabOne);
	//m_MainTab.InsertItem(2,tabTwo);
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
	m_MaterialList.SetExtendedStyle( LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT );
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

	for(int i=0;i<MENU_NUM;i++)
	{
		material_point[i]=0;
		type_point[i]=0;
		con_point[i]=0;
	}

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
	int highest=0;
	int recommenu[MENU_NUM];
	int high_Num=0;
	CString Menu[MENU_NUM]={L"감자 그라탱",L"군고구마",L"냉동피자",L"누룽지",L"닭다리",L"또띠아 피자",L"롤케이크",L"립 바비큐",L"스콘",L"스폰지 케이크",L"약식",L"영양밥",L"오븐 스파게티",L"초코칩 쿠키",L"치즈 케이크",L"통감자",L"통닭",L"통삼겹살",L"피자",L"햄버그 스테이크",L"마늘빵",L"베이글",L"식빵",L"피자토스트",L"허니브레드"};
	CString results;
	for(int i=0;i<MENU_NUM;i++)
	{
		if(highest<type_point[i]+con_point[i]+material_point[i])
		{
			highest=type_point[i]+con_point[i]+material_point[i];
		}
	}
	
	for(int i=0;i<MENU_NUM;i++)
	{
		if(highest==type_point[i]+con_point[i]+material_point[i])
		{
			recommenu[high_Num++]=i;
		}
	}

	if(high_Num>0)
	{
		for(int i=0;i<high_Num-1;i++)
		{
			results+=Menu[recommenu[i]]+L", ";
		}
		results+=Menu[recommenu[high_Num-1]];
		
		

	
	}
	else
		results=L"맞는 조건의 메뉴가 없습니다";
	SetDlgItemTextW(IDC_EDIT2,results);
	//char* ss = (LPSTR)(LPCSTR)results;
	//char* ss = new char[results.GetLength()+1];
	wchar_t* wchar_str;     //첫번째 단계(CString to wchar_t*)를 위한 변수
	char*    char_str;      //char* 형의 변수
	int      char_str_len;  //char* 형 변수의 길이를 위한 변수

	//1. CString to wchar_t* conversion
	wchar_str = results.GetBuffer(results.GetLength());

	//2. wchar_t* to char* conversion
	//char* 형에 대한길이를 구함
	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
	char_str = new char[char_str_len];  //메모리 할당
	//wchar_t* to char* conversion
	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  

	if(__ClipCopy(char_str)&&high_Num>0)
	{
		AfxMessageBox(TEXT("추천 메뉴가 클립보드에 복사되었습니다"));
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CDialogEx::OnOK();
}




void CheckGroup(INT CheckID, INT GroupID, CWnd* pWndParent)
{
	// 일단 버튼의 첵크 상태를 읽ㅇ온다.
	BOOL bCheck = pWndParent->IsDlgButtonChecked(CheckID);

	if(bCheck==false)
	{
		switch (CheckID)
		{
		case 1001:
			for(int i=0;i<MENU_NUM;i++)
				con_point[i]=0;
			break;
		case 1003:
			for(int i=0;i<MENU_NUM;i++)
				type_point[i]=0;
			break;
		case 1008:
			
			for(int i=0;i<MENU_NUM;i++)
				material_point[i]=0;
			break;
		default:
			break;
		}
	}

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
	if(this->IsDlgButtonChecked(IDC_CHECK3)==false)
	{
		for(int i=0;i<MATERIAL_NUM;i++)
			m_MaterialList.SetCheck(i,false);
	}
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
		//SetDlgItemTextW(IDC_EDIT2,TEXT("법량접시"));

		for(int i=0; i<4;i++)
			con_point[i]=100;
		for(int i=4; i<6;i++)
			con_point[i]=-300;
		for(int i=6; i<18;i++)
			con_point[i]=100;
		for(int i=18; i<20;i++)
			con_point[i]=-300;

		con_point[20]=100;//마늘빵
		con_point[23]=100;//피자토스트
		con_point[24]=100;//허니브레드
		//점수 추가
		//((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(false);
		//EnableWindow(IDC_RADIO1,1);
		break;
	case 1:
		//SetDlgItemTextW(IDC_EDIT2,TEXT("석쇠"));

		for(int i=0; i<4;i++)
			con_point[i]=100;
		for(int i=4; i<7;i++)
			con_point[i]=-200;

		con_point[7]=100;
		con_point[8]=-300;
		for(int i=9; i<13;i++)
			con_point[i]=100;
		con_point[13]=-300;
		for(int i=14; i<18;i++)
			con_point[i]=100;
		for(int i=18; i<25;i++)
			con_point[i]=-300;

		break;
	case 2:
		//SetDlgItemTextW(IDC_EDIT2,TEXT("구이전용팬"));

		for(int i=0; i<3;i++)
			con_point[i]=-300;
		for(int i=3; i<6;i++)
			con_point[i]=100;
		for(int i=6; i<13;i++)
			con_point[i]=-300;

		con_point[13]=100;

		for(int i=14; i<18;i++)
			con_point[i]=0;
		con_point[18]=100;
		con_point[19]=100;
		con_point[20]=-300;
		con_point[21]=100;
		con_point[22]=100;
		con_point[23]=-300;
		con_point[24]=-300;
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
		//SetDlgItemTextW(IDC_EDIT2,TEXT("오븐"));
		//((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(false);
		//EnableWindow(IDC_RADIO1,1);
		for(int i=0; i<20;i++)
			type_point[i]=100;
		for(int i=20; i<25;i++)
			type_point[i]=-300;
		break;
	case 1:
		//SetDlgItemTextW(IDC_EDIT2,TEXT("토스트"));
		for(int i=0; i<20;i++)
			type_point[i]=-300;
		for(int i=20; i<25;i++)
			type_point[i]=100;
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

	//SetDlgItemTextW(IDC_EDIT2,(LPCTSTR)index);
	LVHITTESTINFO oInfo;
	oInfo.pt = pNMView->ptAction;
	m_MaterialList.HitTest(&oInfo);

	if(oInfo.flags==LVHT_ONITEMSTATEICON)
	{
		SetDlgItemTextW(IDC_EDIT2,(LPCTSTR)index);
		if(m_MaterialList.GetCheck(index)==FALSE)
		{

			switch(index)
			{
			#pragma region materials
			case 0://가지
				material_point[12]+=10;
				break;
			case 1://감자
				material_point[0]+=10;
				material_point[15]+=10;
				break;
			case 2://계피가루
				material_point[10]+=10;
				break;
			case 3://고구마
				material_point[1]+=10;
				break;
			case 4://꿀
				material_point[24]+=10;
				break;
			case 5://냉동피자
				material_point[2]+=10;
				break;
			case 6://다진 돼지고기
				material_point[19]+=10;
				break;
			case 7://다진 마늘
				material_point[18]+=10;
				material_point[19]+=10;
				material_point[20]+=10;
				break;
			case 8://다진 쇠고기
				material_point[18]+=10;
				material_point[19]+=10;
				break;
			case 9://다진 실파
				material_point[12]+=10;
				break;
			case 10://달걀
				material_point[6]+=10;
				material_point[8]+=10;
				material_point[9]+=10;
				material_point[13]+=10;
				material_point[14]+=10;
				material_point[19]+=10;
				break;
			case 11://닭다리
				material_point[4]+=10;
				break;
			case 12://대추
				material_point[10]+=10;
				material_point[11]+=10;
				break;
			case 13://돼지고기 립
				material_point[7]+=10;
				break;
			case 14://또띠아
				material_point[5]+=10;
				break;
			case 15://멥쌀
				material_point[11]+=10;
				break;
			case 16://모짜렐라 치즈
				material_point[0]+=10;
				material_point[5]+=10;
				material_point[12]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 17://바닐라 오일
				material_point[6]+=10;
				material_point[9]+=10;
				break;
			case 18://박력분
				material_point[6]+=10;
				material_point[9]+=10;
				material_point[13]+=10;
				material_point[14]+=10;
				break;
			case 19://밤
				material_point[10]+=10;
				material_point[11]+=10;
				break;
			case 20://버터
				material_point[20]+=10;
				material_point[23]+=10;
				material_point[24]+=10;
			case 21://베이글
				material_point[21]+=10;
				break;
			case 22://베이컨
				material_point[0]+=10;
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 23://베이킹소다
				material_point[13]+=10;
				break;
			case 24://베이킹파우더
				material_point[8]+=10;
				break;
			case 25://블랙올리브
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 26://생닭
				material_point[16]+=10;
				break;
			case 27://생크림
				material_point[14]+=10;
				break;
			case 28://스파게티면
				material_point[12]+=10;
				break;
			case 29://식빵
				material_point[20]+=10;
				material_point[22]+=10;
				material_point[23]+=10;
				material_point[24]+=10;
				break;
			case 30://식은밥
				material_point[3]+=10;
				break;
			case 31://양송이
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 32://양파
				material_point[0]+=10;
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[19]+=10;
				material_point[23]+=10;
				break;
			case 33://오레가노
				material_point[18]+=10;
				break;
			case 34://올리고당
				//material_point[24]+=10;
				break;
			case 35://우스터소스
				material_point[19]+=10;
			case 36://월계수잎
				material_point[18]+=10;
				break;
			case 37://육수
				material_point[18]+=10;
				material_point[19]+=10;
				break;
			case 38://은행
				material_point[11]+=10;
				break;
			case 39://잣
				material_point[10]+=10;
				material_point[11]+=10;
				break;
			case 40://적포도주
				material_point[19]+=10;
				break;
			case 41://중력분
				material_point[8]+=10;
				break;
			case 42://찹쌀
				material_point[10]+=10;
				material_point[11]+=10;
				break;
			case 43://청피망
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 44://초코칩
				material_point[13]+=10;
				break;
			case 45://콩
				material_point[11]+=10;
				break;
			case 46://크림치즈
				material_point[13]+=10;
				break;
			case 47://토마토 페이스트
				material_point[18]+=10;
				break;
			case 48://통삽겹살
				material_point[17]+=10;
				break;
			case 49://파마산치즈
				material_point[12]+=10;
				break;
			case 50://파슬리 가루
				material_point[20]+=10;
			case 51://피자 빵가루
				material_point[18]+=10;
				material_point[19]+=10;
				break;
			case 52://피자소스
				material_point[5]+=10;
				break;
			case 53://햄
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 54://홍피망
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			default:
				break;
			#pragma endregion add_point
			}

		}
		else
		{
			switch(index)
			{
			#pragma region material_not
			case 0://가지
				material_point[12]-=10;
				break;
			case 1://감자
				material_point[0]-=10;
				material_point[15]-=10;
				break;
			case 2://계피가루
				material_point[10]-=10;
				break;
			case 3://고구마
				material_point[1]-=10;
				break;
			case 4://꿀
				material_point[24]-=10;
				break;
			case 5://냉동피자
				material_point[2]-=10;
				break;
			case 6://다진 돼지고기
				material_point[19]-=10;
				break;
			case 7://다진 마늘
				material_point[18]-=10;
				material_point[19]-=10;
				material_point[20]-=10;
				break;
			case 8://다진 쇠고기
				material_point[18]-=10;
				material_point[19]-=10;
				break;
			case 9://다진 실파
				material_point[12]-=10;
				break;
			case 10://달걀
				material_point[6]-=10;
				material_point[8]-=10;
				material_point[9]-=10;
				material_point[13]-=10;
				material_point[14]-=10;
				material_point[19]-=10;
				break;
			case 11://닭다리
				material_point[4]-=10;
				break;
			case 12://대추
				material_point[10]-=10;
				material_point[11]-=10;
				break;
			case 13://돼지고기 립
				material_point[7]-=10;
				break;
			case 14://또띠아
				material_point[5]-=10;
				break;
			case 15://멥쌀
				material_point[11]-=10;
				break;
			case 16://모짜렐라 치즈
				material_point[0]-=10;
				material_point[5]-=10;
				material_point[12]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 17://바닐라 오일
				material_point[6]-=10;
				material_point[9]-=10;
				break;
			case 18://박력분
				material_point[6]-=10;
				material_point[9]-=10;
				material_point[13]-=10;
				material_point[14]-=10;
				break;
			case 19://밤
				material_point[10]-=10;
				material_point[11]-=10;
				break;
			case 20://버터
				material_point[20]-=10;
				material_point[23]-=10;
				material_point[24]-=10;
			case 21://베이글
				material_point[21]-=10;
				break;
			case 22://베이컨
				material_point[0]-=10;
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 23://베이킹소다
				material_point[13]-=10;
				break;
			case 24://베이킹파우더
				material_point[8]-=10;
				break;
			case 25://블랙올리브
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 26://생닭
				material_point[16]-=10;
				break;
			case 27://생크림
				material_point[14]-=10;
				break;
			case 28://스파게티면
				material_point[12]-=10;
				break;
			case 29://식빵
				material_point[20]-=10;
				material_point[22]-=10;
				material_point[23]-=10;
				material_point[24]-=10;
				break;
			case 30://식은밥
				material_point[3]-=10;
				break;
			case 31://양송이
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 32://양파
				material_point[0]-=10;
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[19]-=10;
				material_point[23]-=10;
				break;
			case 33://오레가노
				material_point[18]-=10;
				break;
			case 34://올리고당
				//material_point[24]-=10;
				break;
			case 35://우스터소스
				material_point[19]-=10;
			case 36://월계수잎
				material_point[18]-=10;
				break;
			case 37://육수
				material_point[18]-=10;
				material_point[19]-=10;
				break;
			case 38://은행
				material_point[11]-=10;
				break;
			case 39://잣
				material_point[10]-=10;
				material_point[11]-=10;
				break;
			case 40://적포도주
				material_point[19]-=10;
				break;
			case 41://중력분
				material_point[8]-=10;
				break;
			case 42://찹쌀
				material_point[10]-=10;
				material_point[11]-=10;
				break;
			case 43://청피망
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 44://초코칩
				material_point[13]-=10;
				break;
			case 45://콩
				material_point[11]-=10;
				break;
			case 46://크림치즈
				material_point[13]-=10;
				break;
			case 47://토마토 페이스트
				material_point[18]-=10;
				break;
			case 48://통삽겹살
				material_point[17]-=10;
				break;
			case 49://파마산치즈
				material_point[12]-=10;
				break;
			case 50://파슬리 가루
				material_point[20]-=10;
			case 51://피자 빵가루
				material_point[18]-=10;
				material_point[19]-=10;
				break;
			case 52://피자소스
				material_point[5]-=10;
				break;
			case 53://햄
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 54://홍피망
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			default:
				break;
			#pragma endregion minus
			}
		}


		*pResult = 0;
	}
}
BOOL __ClipCopy(char *txt)
{
 HGLOBAL hglbCopy;
 char* lptstrCopy; 
 
 if (!::OpenClipboard(AfxGetMainWnd()->GetSafeHwnd())) 
  return FALSE; 
 EmptyClipboard();  
 
 hglbCopy = GlobalAlloc(GMEM_MOVEABLE, strlen(txt)+1);
 if (hglbCopy == NULL) 
 {
  CloseClipboard(); 
  return FALSE; 
 } 
 lptstrCopy =(char*)GlobalLock(hglbCopy); 
 memcpy(lptstrCopy, txt, strlen(txt)+1); 
 //lptstrCopy[strlen(txt)] = 0;
 GlobalUnlock(hglbCopy); 
 
 
 SetClipboardData(CF_TEXT, hglbCopy); 
 
 CloseClipboard();  
 return TRUE;
 
} 