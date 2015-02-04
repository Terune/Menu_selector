// Tab3.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "Tab3.h"
#include "afxdialogex.h"


// CTab3 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTab3, CDialogEx)

CTab3::CTab3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTab3::IDD, pParent)
{

}

CTab3::~CTab3()
{
}

BOOL CTab3::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_comboDenyList.AddString(_T("Type"));
	m_comboDenyList.AddString(_T("Con"));
	m_comboDenyList.AddString(_T("Menu"));
	m_comboDenyList.AddString(_T("Material"));

	m_comboInformList.AddString(_T("Type"));
	m_comboInformList.AddString(_T("Con"));
	m_comboInformList.AddString(_T("Menu"));
	m_comboInformList.AddString(_T("Material"));
	return TRUE;
}

void CTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comboDenyList);
	DDX_Control(pDX, IDC_COMBO2, m_comboInformList);
}

void CheckGroup2(INT CheckID, INT GroupID, CWnd* pWndParent)
{
	// �ϴ� ��ư�� ýũ ���¸� �Ф��´�.
	BOOL bCheck = pWndParent->IsDlgButtonChecked(CheckID);

	//if(bCheck==false)
	//{
	//	switch (CheckID)
	//	{
	//	case 1001:
	//	case 1002:
	//		for(int i=0;i<MENU_NUM;i++)
	//			con_point[i]=0;
	//		break;
	//	case 1003:
	//		for(int i=0;i<MENU_NUM;i++)
	//			type_point[i]=0;
	//		break;
	//	case 1008:
	//	case 1004:	
	//		for(int i=0;i<MENU_NUM;i++)
	//			material_point[i]=0;
	//		break;
	//	default:
	//		break;
	//	}
	//}

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
				//if(bCheck==false)
				//{
				//((CButton*)pWnd)->SetCheck(false);
				//}
			}
		}
		pWnd = pWnd->GetWindow(GW_HWNDNEXT);
	}
}

BEGIN_MESSAGE_MAP(CTab3, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK12, &CTab3::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK13, &CTab3::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_BUTTON10, &CTab3::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &CTab3::OnBnClickedButton9)
END_MESSAGE_MAP()


// CTab3 �޽��� ó�����Դϴ�.


void CTab3::OnBnClickedCheck12()
{
	CheckGroup2(IDC_CHECK12,IDC_STATIC3 , this);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTab3::OnBnClickedCheck13()
{
	CheckGroup2(IDC_CHECK13,IDC_STATIC4, this);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTab3::OnBnClickedButton10()
{

	//ClickList=0;
	this->m_comboDenyList.GetLBText(this->m_comboDenyList.GetCurSel(), ComboName);
	
	CSelection pMainDialog;
	CString Get_name;

	pMainDialog.SetUserData(ComboName, 0);
	if(pMainDialog.DoModal()==IDOK)
	{
		pMainDialog.GetUserData(Get_name);
		this->ShowWindow(SW_SHOW);
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

void CTab3::OnBnClickedButton9()
{
	this->m_comboInformList.GetLBText(this->m_comboInformList.GetCurSel(), ComboName);
	
	CSelection pMainDialog;

	pMainDialog.SetUserData(ComboName, 1);
	if(pMainDialog.DoModal()==IDOK)
	{
		this->ShowWindow(SW_SHOW);
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
