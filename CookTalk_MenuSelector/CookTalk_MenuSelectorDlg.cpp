
// CookTalk_MenuSelectorDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "CookTalk_MenuSelectorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

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
	//ListView_SetItem((HWND)GetDlgItem(IDC_LIST3),"����");
	//IDC_LIST3->

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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnOK();
}




void CheckGroup(INT CheckID, INT GroupID, CWnd* pWndParent)
{
    // �ϴ� ��ư�� ýũ ���¸� �Ф��´�.
    BOOL bCheck = pWndParent->IsDlgButtonChecked(CheckID);
    
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
			SetDlgItemTextW(IDC_EDIT2,TEXT("��������"));
			//((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(false);
			//EnableWindow(IDC_RADIO1,1);
			break;
		case 1:
			SetDlgItemTextW(IDC_EDIT2,TEXT("����"));
			break;
		case 2:
			SetDlgItemTextW(IDC_EDIT2,TEXT("����������"));
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
			SetDlgItemTextW(IDC_EDIT2,TEXT("����"));
			//((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(false);
			//EnableWindow(IDC_RADIO1,1);
			break;
		case 1:
			SetDlgItemTextW(IDC_EDIT2,TEXT("�佺Ʈ"));
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

	SetDlgItemTextW(IDC_EDIT2,(LPCTSTR)index);
	*pResult = 0;
}
