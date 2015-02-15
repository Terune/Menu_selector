// Tab3.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "Tab3.h"
#include "afxdialogex.h"


// CTab3 대화 상자입니다.

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

	m_ComboConfirmList.AddString(_T("Type"));
	m_ComboConfirmList.AddString(_T("Con"));
	m_ComboConfirmList.AddString(_T("Menu"));
	m_ComboConfirmList.AddString(_T("Material"));

	m_ComboRequestList.AddString(_T("Type"));
	m_ComboRequestList.AddString(_T("Con"));
	m_ComboRequestList.AddString(_T("Menu"));
	m_ComboRequestList.AddString(_T("Material"));
	
	for(int i=0;i<55;i++)
		Materials[i]=0;
	//User_input=_T("");
	Slot_input=_T("");
	return TRUE;
}

void CTab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comboDenyList);
	DDX_Control(pDX, IDC_COMBO2, m_comboInformList);
	DDX_Control(pDX, IDC_COMBO3, m_ComboConfirmList);
	DDX_Control(pDX, IDC_COMBO4, m_ComboRequestList);
}

void CheckGroup2(INT CheckID, INT GroupID, CWnd* pWndParent)
{
	// 일단 버튼의 첵크 상태를 읽ㅇ온다.
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
	ON_BN_CLICKED(IDC_BUTTON6, &CTab3::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CTab3::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_CHECK19, &CTab3::OnBnClickedCheck19)
	ON_BN_CLICKED(IDC_CHECK18, &CTab3::OnBnClickedCheck18)
	ON_BN_CLICKED(IDC_BUTTON7, &CTab3::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON12, &CTab3::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_CHECK1, &CTab3::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CTab3::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK4, &CTab3::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK7, &CTab3::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CTab3::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &CTab3::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &CTab3::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &CTab3::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK14, &CTab3::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_CHECK15, &CTab3::OnBnClickedCheck15)
	ON_BN_CLICKED(IDC_CHECK17, &CTab3::OnBnClickedCheck17)
	ON_BN_CLICKED(IDC_CHECK16, &CTab3::OnBnClickedCheck16)
	ON_BN_CLICKED(IDC_BUTTON13, &CTab3::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON11, &CTab3::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON1, &CTab3::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTab3 메시지 처리기입니다.


void CTab3::OnBnClickedCheck12()
{
	CheckGroup2(IDC_CHECK12,IDC_STATIC3 , this);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck13()
{
	CheckGroup2(IDC_CHECK13,IDC_STATIC4, this);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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

		SetDlgItemTextW(IDC_EDIT1,ComboName+TEXT(": ")+Get_name);

		if(Get_name.GetLength()>0)
		{
			deny_In_slot=ComboName;
			deny_In_value=Get_name;
		}

		this->ShowWindow(SW_SHOW);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CTab3::OnBnClickedButton9()
{
	this->m_comboInformList.GetLBText(this->m_comboInformList.GetCurSel(), ComboName);
	
	CSelection pMainDialog;
	CString Get_name;

	pMainDialog.SetUserData(ComboName, 1);
	if(pMainDialog.DoModal()==IDOK)
	{
		pMainDialog.GetUserData(Get_name);
		SetDlgItemTextW(IDC_EDIT5,ComboName+TEXT(": ")+Get_name);
		
		if(Get_name.GetLength()>0)
		{
			inform_In_slot=ComboName;
			inform_In_value=Get_name;
		}
		this->ShowWindow(SW_SHOW);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedButton6()
{
	// 초기화 버튼 클릭 이벤트
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

// deny add
void CTab3::OnBnClickedButton8()
{
	if(deny_In_slot.GetLength()>0)
	{
		CString Get_value;
		if(deny_In_slot=="Materials")
		{
			Materials[returnMaterialNum(deny_In_value)]=-1;
		}
		else
		{
			if(slots.Lookup(deny_In_slot,Get_value))
			{
				if(Get_value==deny_In_value)
				{
					slots.RemoveKey(deny_In_slot);
				}
			}
		}

		if(Slot_input.GetLength()>0)
			Slot_input+=TEXT(", ");
		Slot_input+=TEXT("deny(")+deny_In_slot+TEXT(":")+deny_In_value+TEXT(")");

		deny_In_slot=_T("");
		deny_In_value=_T("");
	}
	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck19()
{
	CheckGroup2(IDC_CHECK19,IDC_STATIC6 , this);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck18()
{
	CheckGroup2(IDC_CHECK18,IDC_STATIC5 , this);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
int CTab3::returnMaterialNum(CString input)
{
	CString Material_names[55]={TEXT("eggplant"),TEXT("potato"),TEXT("cinnamon_powder"),TEXT("sweet_potato"),TEXT("honey"),TEXT("pizza"),
	TEXT("pork"),TEXT("crushed_galic"),TEXT("beef"),TEXT("small_green_onion"),TEXT("egg"),TEXT("drumstick"),TEXT("jujube"),TEXT("pork_rib"),
	TEXT("Tortilla"),TEXT("nonglutinous_rice"),TEXT("cheese"),TEXT("vanilla_oil"),TEXT("soft_flour"),TEXT("chestnut"),TEXT("butter"),
	TEXT("bagle"),TEXT("bacon"),TEXT("baking_soda"),TEXT("baking_powder"),TEXT("black_olive"),TEXT("chicken"),TEXT("cream"),TEXT("spaghetti"),
	TEXT("bread"),TEXT("rice"),TEXT("button_mushroom"),TEXT("onion"),TEXT("oregano"),TEXT("oligosaccharides"),
	TEXT("worcester_sauce"),TEXT("bay_leaf"),TEXT("meat_broth"),TEXT("ginkgo_nut"),TEXT("pine_nut"),TEXT("red_wine"),
	TEXT("medium_flour"),TEXT("sticky_rice"),TEXT("squid"),TEXT("chocochip"),TEXT("bean"),TEXT("cream_cheese"),
	TEXT("tomato_paste"),TEXT("pork_belly"),TEXT("parmesan"),TEXT("parsley"),TEXT("bread_crumbs"),TEXT("pizza_source"),
	TEXT("ham"),TEXT("red_peppers")};

	for(int i=0;i<55;i++)
		if(Material_names[i]==input)
			return i;
}


void CTab3::OnBnClickedButton7()
{
	if(inform_In_slot.GetLength()>0)
	{
		CString Get_value;
		if(inform_In_slot=="Materials")
		{
			Materials[returnMaterialNum(inform_In_value)]=1;
		}
		else
		{
			if(slots.Lookup(inform_In_slot,Get_value))
			{
				slots.RemoveKey(inform_In_slot);
			}
			slots.SetAt(inform_In_slot,inform_In_value);
		}
	
		if(Slot_input.GetLength()>0)
			Slot_input+=TEXT(", ");
		Slot_input+=TEXT("inform(")+inform_In_slot+TEXT(":")+inform_In_value+TEXT(")");
	
		inform_In_slot=_T("");
		inform_In_value=_T("");
	}
	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedButton12()
{
	this->m_ComboConfirmList.GetLBText(this->m_ComboConfirmList.GetCurSel(), ComboName);
	
	CSelection pMainDialog;
	CString Get_name;

	pMainDialog.SetUserData(ComboName, 1);
	if(pMainDialog.DoModal()==IDOK)
	{
		pMainDialog.GetUserData(Get_name);
		SetDlgItemTextW(IDC_EDIT6,ComboName+TEXT(": ")+Get_name);
		if(Get_name.GetLength()>0)
		{
			Confirm_In_slot=ComboName;
			Confirm_In_value=Get_name;
		}

		this->ShowWindow(SW_SHOW);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck1()
{
	if(this->IsDlgButtonChecked(IDC_CHECK1))
	{
		Check_Input[0]=1;
	}
	else
		Check_Input[0]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CTab3::ViewNowValue()
{
	CString DA_NAME[12]={TEXT("end"),TEXT("goback"),TEXT("restart"),TEXT("null"),TEXT("repeat"),TEXT("affirm"),TEXT("negate"),
	TEXT("alarm_start"),TEXT("movie_start"),TEXT("heat_start"),TEXT("next"),TEXT("reqalts")};
	
	CString User_input=_T("");
	BOOL first=true;
	for(int i=0;i<12;i++)
	{
		if(Check_Input[i]==1){
			if(first==true)
			{
				User_input+=DA_NAME[i];
				first=false;
			}
			else
				User_input+=TEXT(", ")+DA_NAME[i];
		}
	}

	if(first==true)
	{
		User_input+=Slot_input;
		first=false;
	}
	else
		User_input+=TEXT(", ")+Slot_input;
	SetDlgItemTextW(IDC_EDIT7,User_input);
}


void CTab3::OnBnClickedCheck2()
{
	if(this->IsDlgButtonChecked(IDC_CHECK2))
	{
		Check_Input[1]=1;
	}
	else
		Check_Input[1]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck4()
{
	if(this->IsDlgButtonChecked(IDC_CHECK4))
	{
		Check_Input[2]=1;
	}
	else
		Check_Input[2]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck7()
{
	if(this->IsDlgButtonChecked(IDC_CHECK7))
	{
		Check_Input[3]=1;
	}
	else
		Check_Input[3]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck8()
{
	if(this->IsDlgButtonChecked(IDC_CHECK8))
	{
		Check_Input[4]=1;
	}
	else
		Check_Input[4]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck9()
{
	if(this->IsDlgButtonChecked(IDC_CHECK9))
	{
		Check_Input[5]=1;
	}
	else
		Check_Input[5]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck10()
{
	if(this->IsDlgButtonChecked(IDC_CHECK10))
	{
		Check_Input[6]=1;
	}
	else
		Check_Input[6]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck11()
{
	if(this->IsDlgButtonChecked(IDC_CHECK11))
	{
		Check_Input[7]=1;
	}
	else
		Check_Input[7]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck14()
{
	if(this->IsDlgButtonChecked(IDC_CHECK14))
	{
		Check_Input[8]=1;
	}
	else
		Check_Input[8]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck15()
{
	if(this->IsDlgButtonChecked(IDC_CHECK15))
	{
		Check_Input[9]=1;
	}
	else
		Check_Input[9]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck17()
{
	if(this->IsDlgButtonChecked(IDC_CHECK17))
	{
		Check_Input[10]=1;
	}
	else
		Check_Input[10]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedCheck16()
{
	if(this->IsDlgButtonChecked(IDC_CHECK16))
	{
		Check_Input[11]=1;
	}
	else
		Check_Input[11]=0;

	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedButton13()
{
	this->m_ComboRequestList.GetLBText(this->m_ComboRequestList.GetCurSel(), ComboName);
	
	if(Slot_input.GetLength()>0)
			Slot_input+=TEXT(", ");
	Slot_input+=TEXT("request(")+ComboName+TEXT(")");
	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTab3::OnBnClickedButton11()
{
	if(Slot_input.GetLength()>0)
			Slot_input+=TEXT(", ");
	Slot_input+=TEXT("request(")+Confirm_In_slot+TEXT(":")+Confirm_In_value+TEXT(")");
	ViewNowValue();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//확인버튼
void CTab3::OnBnClickedButton1()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
