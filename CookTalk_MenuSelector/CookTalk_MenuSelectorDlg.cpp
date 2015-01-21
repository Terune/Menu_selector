
// CookTalk_MenuSelectorDlg.cpp : ���� ����
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

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.
int material_point[25];
int type_point[25];
int con_point[25];

BOOL __ClipCopy(char *txt);
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.


	// �����Դϴ�.
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


// CCookTalk_MenuSelectorDlg ��ȭ ����



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



// CCookTalk_MenuSelectorDlg �޽��� ó����

BOOL CCookTalk_MenuSelectorDlg::OnInitDialog()
{
		//CString tabOne = _T("�丮�˻�");
	//CString tabTwo = _T("������ �˻�");

	//m_MainTab.InsertItem(1,tabOne);
	//m_MainTab.InsertItem(2,tabTwo);
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(false);
	((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(false);
	m_MaterialList.SetExtendedStyle( LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT );
	m_MaterialList.InsertItem(0,TEXT("����"));
	m_MaterialList.InsertItem(0,TEXT("����"));
	m_MaterialList.InsertItem(0,TEXT("���ǰ���"));
	m_MaterialList.InsertItem(0,TEXT("����"));
	m_MaterialList.InsertItem(0,TEXT("��"));
	m_MaterialList.InsertItem(0,TEXT("�õ�����"));
	m_MaterialList.InsertItem(0,TEXT("���� �������"));
	m_MaterialList.InsertItem(0,TEXT("���� ����"));
	m_MaterialList.InsertItem(0,TEXT("���� ����"));
	m_MaterialList.InsertItem(0,TEXT("���� ����"));
	m_MaterialList.InsertItem(0,TEXT("�ް�"));
	m_MaterialList.InsertItem(0,TEXT("�ߴٸ�"));
	m_MaterialList.InsertItem(0,TEXT("����"));
	m_MaterialList.InsertItem(0,TEXT("������� ��"));
	m_MaterialList.InsertItem(0,TEXT("�Ƕ��"));
	m_MaterialList.InsertItem(0,TEXT("���"));
	m_MaterialList.InsertItem(0,TEXT("��¥���� ġ��"));
	m_MaterialList.InsertItem(0,TEXT("�ٴҶ����"));
	m_MaterialList.InsertItem(0,TEXT("�ڷº�"));
	m_MaterialList.InsertItem(0,TEXT("��"));
	m_MaterialList.InsertItem(0,TEXT("����"));
	m_MaterialList.InsertItem(0,TEXT("���̱�"));
	m_MaterialList.InsertItem(0,TEXT("������"));
	m_MaterialList.InsertItem(0,TEXT("����ŷ �Ҵ�"));
	m_MaterialList.InsertItem(0,TEXT("����ŷ �Ŀ��"));
	m_MaterialList.InsertItem(0,TEXT("�� �ø���"));
	m_MaterialList.InsertItem(0,TEXT("����"));
	m_MaterialList.InsertItem(0,TEXT("��ũ��"));
	m_MaterialList.InsertItem(0,TEXT("���İ�Ƽ��"));
	m_MaterialList.InsertItem(0,TEXT("�Ļ�"));
	m_MaterialList.InsertItem(0,TEXT("������"));
	m_MaterialList.InsertItem(0,TEXT("�����"));
	m_MaterialList.InsertItem(0,TEXT("����"));
	m_MaterialList.InsertItem(0,TEXT("��������"));
	m_MaterialList.InsertItem(0,TEXT("�ø����"));
	m_MaterialList.InsertItem(0,TEXT("�콺�� �ҽ�"));
	m_MaterialList.InsertItem(0,TEXT("�������"));
	m_MaterialList.InsertItem(0,TEXT("����"));
	m_MaterialList.InsertItem(0,TEXT("����"));
	m_MaterialList.InsertItem(0,TEXT("��"));
	m_MaterialList.InsertItem(0,TEXT("��������"));
	m_MaterialList.InsertItem(0,TEXT("�߷º�"));
	m_MaterialList.InsertItem(0,TEXT("����"));
	m_MaterialList.InsertItem(0,TEXT("û�Ǹ�"));
	m_MaterialList.InsertItem(0,TEXT("����Ĩ"));
	m_MaterialList.InsertItem(0,TEXT("��"));
	m_MaterialList.InsertItem(0,TEXT("ũ��ġ��"));
	m_MaterialList.InsertItem(0,TEXT("�丶�� ���̽�Ʈ"));
	m_MaterialList.InsertItem(0,TEXT("�����"));
	m_MaterialList.InsertItem(0,TEXT("�ĸ��� ġ��"));
	m_MaterialList.InsertItem(0,TEXT("�Ľ��� ����"));
	m_MaterialList.InsertItem(0,TEXT("���� ������"));
	m_MaterialList.InsertItem(0,TEXT("���ڼҽ�"));
	m_MaterialList.InsertItem(0,TEXT("��"));
	m_MaterialList.InsertItem(0,TEXT("ȫ�Ǹ�"));

	for(int i=0;i<MENU_NUM;i++)
	{
		material_point[i]=0;
		type_point[i]=0;
		con_point[i]=0;
	}

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CCookTalk_MenuSelectorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CCookTalk_MenuSelectorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCookTalk_MenuSelectorDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCookTalk_MenuSelectorDlg::OnBnClickedOk()
{
	int highest=0;
	int recommenu[MENU_NUM];
	int high_Num=0;
	CString Menu[MENU_NUM]={L"���� �׶���",L"������",L"�õ�����",L"������",L"�ߴٸ�",L"�Ƕ�� ����",L"������ũ",L"�� �ٺ�ť",L"����",L"������ ����ũ",L"���",L"�����",L"���� ���İ�Ƽ",L"����Ĩ ��Ű",L"ġ�� ����ũ",L"�밨��",L"���",L"�����",L"����",L"�ܹ��� ������ũ",L"���û�",L"���̱�",L"�Ļ�",L"�����佺Ʈ",L"��Ϻ극��"};
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
		results=L"�´� ������ �޴��� �����ϴ�";
	SetDlgItemTextW(IDC_EDIT2,results);
	//char* ss = (LPSTR)(LPCSTR)results;
	//char* ss = new char[results.GetLength()+1];
	wchar_t* wchar_str;     //ù��° �ܰ�(CString to wchar_t*)�� ���� ����
	char*    char_str;      //char* ���� ����
	int      char_str_len;  //char* �� ������ ���̸� ���� ����

	//1. CString to wchar_t* conversion
	wchar_str = results.GetBuffer(results.GetLength());

	//2. wchar_t* to char* conversion
	//char* ���� ���ѱ��̸� ����
	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
	char_str = new char[char_str_len];  //�޸� �Ҵ�
	//wchar_t* to char* conversion
	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  

	if(__ClipCopy(char_str)&&high_Num>0)
	{
		AfxMessageBox(TEXT("��õ �޴��� Ŭ�����忡 ����Ǿ����ϴ�"));
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//CDialogEx::OnOK();
}




void CheckGroup(INT CheckID, INT GroupID, CWnd* pWndParent)
{
	// �ϴ� ��ư�� ýũ ���¸� �Ф��´�.
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

	// �׷�ڽ��� ���� ������ �о�´�.
	pWndParent->GetDlgItem(GroupID)->GetWindowRect(rcGroup);

	// ���� ���̾˷α��� ���ϵ� �������� ù��° ���� �����´�.
	CWnd* pWnd = pWndParent->GetWindow(GW_CHILD);
	while (pWnd)
	{
		// �ش� �׷��, ��ư�� ������ ���ϵ� ������.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCookTalk_MenuSelectorDlg::OnBnClickedCheck2()
{
	CheckGroup(IDC_CHECK2,IDC_STATIC2 , this);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CCookTalk_MenuSelectorDlg::OnBnClickedCheck3()
{
	CheckGroup(IDC_CHECK3,IDC_STATIC3 , this);
	if(this->IsDlgButtonChecked(IDC_CHECK3)==false)
	{
		for(int i=0;i<MATERIAL_NUM;i++)
			m_MaterialList.SetCheck(i,false);
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CCookTalk_MenuSelectorDlg::SetRadioStatus1(UINT value)
{
	UpdateData(TRUE);

	switch(con_Radio)
	{
	case 0:
		//CEdit* p=(CEdit*)GetDlgItem(IDC_EDIT2);
		//p->SetWindowTextW("��������");
		//SetDlgItemTextW(IDC_EDIT2,TEXT("��������"));

		for(int i=0; i<4;i++)
			con_point[i]=100;
		for(int i=4; i<6;i++)
			con_point[i]=-300;
		for(int i=6; i<18;i++)
			con_point[i]=100;
		for(int i=18; i<20;i++)
			con_point[i]=-300;

		con_point[20]=100;//���û�
		con_point[23]=100;//�����佺Ʈ
		con_point[24]=100;//��Ϻ극��
		//���� �߰�
		//((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(false);
		//EnableWindow(IDC_RADIO1,1);
		break;
	case 1:
		//SetDlgItemTextW(IDC_EDIT2,TEXT("����"));

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
		//SetDlgItemTextW(IDC_EDIT2,TEXT("����������"));

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
		SetDlgItemTextW(IDC_EDIT2,TEXT("����"));
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
		//p->SetWindowTextW("��������");
		//SetDlgItemTextW(IDC_EDIT2,TEXT("����"));
		//((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(false);
		//EnableWindow(IDC_RADIO1,1);
		for(int i=0; i<20;i++)
			type_point[i]=100;
		for(int i=20; i<25;i++)
			type_point[i]=-300;
		break;
	case 1:
		//SetDlgItemTextW(IDC_EDIT2,TEXT("�佺Ʈ"));
		for(int i=0; i<20;i++)
			type_point[i]=-300;
		for(int i=20; i<25;i++)
			type_point[i]=100;
		break;
	default:
		SetDlgItemTextW(IDC_EDIT2,TEXT("����"));
		break;
	}
}

void CCookTalk_MenuSelectorDlg::OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
			case 0://����
				material_point[12]+=10;
				break;
			case 1://����
				material_point[0]+=10;
				material_point[15]+=10;
				break;
			case 2://���ǰ���
				material_point[10]+=10;
				break;
			case 3://����
				material_point[1]+=10;
				break;
			case 4://��
				material_point[24]+=10;
				break;
			case 5://�õ�����
				material_point[2]+=10;
				break;
			case 6://���� �������
				material_point[19]+=10;
				break;
			case 7://���� ����
				material_point[18]+=10;
				material_point[19]+=10;
				material_point[20]+=10;
				break;
			case 8://���� ����
				material_point[18]+=10;
				material_point[19]+=10;
				break;
			case 9://���� ����
				material_point[12]+=10;
				break;
			case 10://�ް�
				material_point[6]+=10;
				material_point[8]+=10;
				material_point[9]+=10;
				material_point[13]+=10;
				material_point[14]+=10;
				material_point[19]+=10;
				break;
			case 11://�ߴٸ�
				material_point[4]+=10;
				break;
			case 12://����
				material_point[10]+=10;
				material_point[11]+=10;
				break;
			case 13://������� ��
				material_point[7]+=10;
				break;
			case 14://�Ƕ��
				material_point[5]+=10;
				break;
			case 15://���
				material_point[11]+=10;
				break;
			case 16://��¥���� ġ��
				material_point[0]+=10;
				material_point[5]+=10;
				material_point[12]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 17://�ٴҶ� ����
				material_point[6]+=10;
				material_point[9]+=10;
				break;
			case 18://�ڷº�
				material_point[6]+=10;
				material_point[9]+=10;
				material_point[13]+=10;
				material_point[14]+=10;
				break;
			case 19://��
				material_point[10]+=10;
				material_point[11]+=10;
				break;
			case 20://����
				material_point[20]+=10;
				material_point[23]+=10;
				material_point[24]+=10;
			case 21://���̱�
				material_point[21]+=10;
				break;
			case 22://������
				material_point[0]+=10;
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 23://����ŷ�Ҵ�
				material_point[13]+=10;
				break;
			case 24://����ŷ�Ŀ��
				material_point[8]+=10;
				break;
			case 25://���ø���
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 26://����
				material_point[16]+=10;
				break;
			case 27://��ũ��
				material_point[14]+=10;
				break;
			case 28://���İ�Ƽ��
				material_point[12]+=10;
				break;
			case 29://�Ļ�
				material_point[20]+=10;
				material_point[22]+=10;
				material_point[23]+=10;
				material_point[24]+=10;
				break;
			case 30://������
				material_point[3]+=10;
				break;
			case 31://�����
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 32://����
				material_point[0]+=10;
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[19]+=10;
				material_point[23]+=10;
				break;
			case 33://��������
				material_point[18]+=10;
				break;
			case 34://�ø����
				//material_point[24]+=10;
				break;
			case 35://�콺�ͼҽ�
				material_point[19]+=10;
			case 36://�������
				material_point[18]+=10;
				break;
			case 37://����
				material_point[18]+=10;
				material_point[19]+=10;
				break;
			case 38://����
				material_point[11]+=10;
				break;
			case 39://��
				material_point[10]+=10;
				material_point[11]+=10;
				break;
			case 40://��������
				material_point[19]+=10;
				break;
			case 41://�߷º�
				material_point[8]+=10;
				break;
			case 42://����
				material_point[10]+=10;
				material_point[11]+=10;
				break;
			case 43://û�Ǹ�
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 44://����Ĩ
				material_point[13]+=10;
				break;
			case 45://��
				material_point[11]+=10;
				break;
			case 46://ũ��ġ��
				material_point[13]+=10;
				break;
			case 47://�丶�� ���̽�Ʈ
				material_point[18]+=10;
				break;
			case 48://�����
				material_point[17]+=10;
				break;
			case 49://�ĸ���ġ��
				material_point[12]+=10;
				break;
			case 50://�Ľ��� ����
				material_point[20]+=10;
			case 51://���� ������
				material_point[18]+=10;
				material_point[19]+=10;
				break;
			case 52://���ڼҽ�
				material_point[5]+=10;
				break;
			case 53://��
				material_point[5]+=10;
				material_point[18]+=10;
				material_point[23]+=10;
				break;
			case 54://ȫ�Ǹ�
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
			case 0://����
				material_point[12]-=10;
				break;
			case 1://����
				material_point[0]-=10;
				material_point[15]-=10;
				break;
			case 2://���ǰ���
				material_point[10]-=10;
				break;
			case 3://����
				material_point[1]-=10;
				break;
			case 4://��
				material_point[24]-=10;
				break;
			case 5://�õ�����
				material_point[2]-=10;
				break;
			case 6://���� �������
				material_point[19]-=10;
				break;
			case 7://���� ����
				material_point[18]-=10;
				material_point[19]-=10;
				material_point[20]-=10;
				break;
			case 8://���� ����
				material_point[18]-=10;
				material_point[19]-=10;
				break;
			case 9://���� ����
				material_point[12]-=10;
				break;
			case 10://�ް�
				material_point[6]-=10;
				material_point[8]-=10;
				material_point[9]-=10;
				material_point[13]-=10;
				material_point[14]-=10;
				material_point[19]-=10;
				break;
			case 11://�ߴٸ�
				material_point[4]-=10;
				break;
			case 12://����
				material_point[10]-=10;
				material_point[11]-=10;
				break;
			case 13://������� ��
				material_point[7]-=10;
				break;
			case 14://�Ƕ��
				material_point[5]-=10;
				break;
			case 15://���
				material_point[11]-=10;
				break;
			case 16://��¥���� ġ��
				material_point[0]-=10;
				material_point[5]-=10;
				material_point[12]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 17://�ٴҶ� ����
				material_point[6]-=10;
				material_point[9]-=10;
				break;
			case 18://�ڷº�
				material_point[6]-=10;
				material_point[9]-=10;
				material_point[13]-=10;
				material_point[14]-=10;
				break;
			case 19://��
				material_point[10]-=10;
				material_point[11]-=10;
				break;
			case 20://����
				material_point[20]-=10;
				material_point[23]-=10;
				material_point[24]-=10;
			case 21://���̱�
				material_point[21]-=10;
				break;
			case 22://������
				material_point[0]-=10;
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 23://����ŷ�Ҵ�
				material_point[13]-=10;
				break;
			case 24://����ŷ�Ŀ��
				material_point[8]-=10;
				break;
			case 25://���ø���
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 26://����
				material_point[16]-=10;
				break;
			case 27://��ũ��
				material_point[14]-=10;
				break;
			case 28://���İ�Ƽ��
				material_point[12]-=10;
				break;
			case 29://�Ļ�
				material_point[20]-=10;
				material_point[22]-=10;
				material_point[23]-=10;
				material_point[24]-=10;
				break;
			case 30://������
				material_point[3]-=10;
				break;
			case 31://�����
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 32://����
				material_point[0]-=10;
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[19]-=10;
				material_point[23]-=10;
				break;
			case 33://��������
				material_point[18]-=10;
				break;
			case 34://�ø����
				//material_point[24]-=10;
				break;
			case 35://�콺�ͼҽ�
				material_point[19]-=10;
			case 36://�������
				material_point[18]-=10;
				break;
			case 37://����
				material_point[18]-=10;
				material_point[19]-=10;
				break;
			case 38://����
				material_point[11]-=10;
				break;
			case 39://��
				material_point[10]-=10;
				material_point[11]-=10;
				break;
			case 40://��������
				material_point[19]-=10;
				break;
			case 41://�߷º�
				material_point[8]-=10;
				break;
			case 42://����
				material_point[10]-=10;
				material_point[11]-=10;
				break;
			case 43://û�Ǹ�
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 44://����Ĩ
				material_point[13]-=10;
				break;
			case 45://��
				material_point[11]-=10;
				break;
			case 46://ũ��ġ��
				material_point[13]-=10;
				break;
			case 47://�丶�� ���̽�Ʈ
				material_point[18]-=10;
				break;
			case 48://�����
				material_point[17]-=10;
				break;
			case 49://�ĸ���ġ��
				material_point[12]-=10;
				break;
			case 50://�Ľ��� ����
				material_point[20]-=10;
			case 51://���� ������
				material_point[18]-=10;
				material_point[19]-=10;
				break;
			case 52://���ڼҽ�
				material_point[5]-=10;
				break;
			case 53://��
				material_point[5]-=10;
				material_point[18]-=10;
				material_point[23]-=10;
				break;
			case 54://ȫ�Ǹ�
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