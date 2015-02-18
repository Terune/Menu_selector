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
	for(int i=0;i<25;i++)
	{
		material_point[i]=0;
		con_point[i]=0;
		type_point[i]=0;
	}
	//User_input=_T("");
	Slot_input=_T("");
	SetDlgItemTextW(IDC_EDIT4,TEXT("start"));
	now_act.push(TEXT("start"));
	//before_act=TEXT("start");
	SetDlgItemTextW(IDC_EDIT3,TEXT("LG Dios ���Ŀ��� ����� �Դϴ�. ������ ���͵帱���?"));
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

		SetDlgItemTextW(IDC_EDIT1,ComboName+TEXT(": ")+Get_name);

		if(Get_name.GetLength()>0)
		{
			deny_In_slot=ComboName;
			deny_In_value=Get_name;
		}

		this->ShowWindow(SW_SHOW);
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTab3::OnBnClickedButton6()
{
	SetDlgItemTextW(IDC_EDIT4,TEXT("start"));
	SetDlgItemTextW(IDC_EDIT3,TEXT("LG Dios ���Ŀ��� ����� �Դϴ�. ������ ���͵帱���?"));

	slots.RemoveAll();

	for(int i=0;i<55;i++)
		Materials[i]=0;
	for(int i=0;i<25;i++)
	{
		material_point[i]=0;
		con_point[i]=0;
		type_point[i]=0;
	}

	SetDlgItemTextW(IDC_EDIT2,TEXT("Material:/ Menu:/ Con:/ Type:/ By:"));
	Slot_input=_T("");
	now_act.push(TEXT("start"));
	print_DA=_T("start");
	//before_act=TEXT("start");
	ViewNowValue();
	// �ʱ�ȭ ��ư Ŭ�� �̺�Ʈ
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTab3::OnBnClickedCheck19()
{
	CheckGroup2(IDC_CHECK19,IDC_STATIC6 , this);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTab3::OnBnClickedCheck18()
{
	CheckGroup2(IDC_CHECK18,IDC_STATIC5 , this);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
		if(inform_In_slot=="Material")
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTab3::OnBnClickedButton13()
{
	this->m_ComboRequestList.GetLBText(this->m_ComboRequestList.GetCurSel(), ComboName);

	if(Slot_input.GetLength()>0)
		Slot_input+=TEXT(", ");
	Slot_input+=TEXT("request(")+ComboName+TEXT(")");
	ViewNowValue();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CTab3::OnBnClickedButton11()
{
	if(Slot_input.GetLength()>0)
		Slot_input+=TEXT(", ");
	Slot_input+=TEXT("request(")+Confirm_In_slot+TEXT(":")+Confirm_In_value+TEXT(")");
	ViewNowValue();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}

//Ȯ�ι�ư
void CTab3::OnBnClickedButton1()
{
	CString DA_NAME[12]={TEXT("end"),TEXT("goback"),TEXT("restart"),TEXT("null"),TEXT("repeat"),TEXT("affirm"),TEXT("negate"),
		TEXT("alarm_start"),TEXT("movie_start"),TEXT("heat_start"),TEXT("next"),TEXT("reqalts")};
	CString slot_material;
	CString slot_menu;
	CString slot_con;
	CString slot_type;
	CString By=TEXT("none");
	BOOL Use_material=false;
	//BOOL first=true;
		
	if(Check_Input[0]==1)//end input
		Doact(TEXT("end"));
	if(Check_Input[4]==1)//repeat input
		Doact(TEXT("repeat"));
	if(Check_Input[1]==1)//goback input
		Doact(TEXT("goback"));

	for(int i=0;i<55;i++)
	{
		if(Materials[i]==1)
			Use_material=TRUE;
	}

	if(Use_material)
		By=TEXT("bymaterial");
	if(slots.Lookup(TEXT("Type"),slot_type))
		By=TEXT("bytype");
	if(slots.Lookup(TEXT("Con"),slot_con))
		By=TEXT("bycon");
	if(slots.Lookup(TEXT("Menu"),slot_menu))
		By=TEXT("bymenu");

	SetDlgItemTextW(IDC_EDIT2,TEXT("Material:")+Find_Material(TEXT("english"))+TEXT("/ Menu:")+slot_menu+TEXT("/ Con:")+slot_con+TEXT("/ Type:")+slot_type+TEXT("/ By:")+By);


	if(now_act.top()=="start")
	{
		if(By=="none"){

			if(Check_Input[3]==1)//null input
				Doact(TEXT("null"));
			if(Check_Input[5]==1)//affirm input
				Doact(TEXT("affirm"));
			if(Check_Input[6]==1)//negate input
				Doact(TEXT("negate"));
			if(Check_Input[7]==1)//negate input
				Doact(TEXT("alarm_start"));
			if(Check_Input[8]==1)//negate input
				Doact(TEXT("movie_start"));
			if(Check_Input[9]==1)//negate input
				Doact(TEXT("heat_start"));
			if(Check_Input[10]==1)//negate input
				Doact(TEXT("next"));
			if(Check_Input[11]==1)//negate input
				Doact(TEXT("reqalts"));
		}
		else if(By=="bymaterial")
		{
			Doact(TEXT("explain"),TEXT("material"));
		}
		else if(By=="bymenu")
		{
			Doact(TEXT("impl_confirm"),TEXT("Menu"),slot_menu);
			Doact(TEXT("explain"),TEXT("Menu"),slot_menu);
			Doact(TEXT("recipe_q"));
		}
		else if(By=="bycon")
			Doact(TEXT("explain"),TEXT("Con"),slot_con);
		else if(By=="bytype")
			Doact(TEXT("explain"),TEXT("Type"),slot_type);
	}
	else
	{
		if(Check_Input[3]==1)//null input
			Doact(TEXT("null"));
		if(Check_Input[5]==1)//affirm input
			Doact(TEXT("affirm"));
		if(Check_Input[6]==1)//negate input
			Doact(TEXT("negate"));
		if(Check_Input[7]==1)//negate input
			Doact(TEXT("alarm_start"));
		if(Check_Input[8]==1)//negate input
			Doact(TEXT("movie_start"));
		if(Check_Input[9]==1)//negate input
			Doact(TEXT("heat_start"));
		if(Check_Input[10]==1)//negate input
			Doact(TEXT("next"));
	}
	if(Check_Input[3]==1)//null input
				Doact(TEXT("null"));
	if(Check_Input[2]==1)//restart input
		Doact(TEXT("restart"));
	Slot_input=_T("");
	ViewNowValue();
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
void CTab3::Doact(CString act,CString Slot,CString Value)
{
	//CString print_act;
	if(act=="explain"&&Slot=="Menu")
	{
		now_act.push(TEXT("explain"));
		now_slot.push(Slot);
		now_value.push(Value);
		print_act+=Conv_Korean(Value)+TEXT("�� ")+Menu_Material(Conv_Korean(Value))+TEXT("�� ���� �ʿ��մϴ�.");
		print_DA+=TEXT("explain(menu:")+Value+TEXT(")");
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="explain"&&Slot=="Con")
	{
		now_act.push(TEXT("explain"));
		now_slot.push(Slot);
		now_value.push(Value);
		print_act=Conv_Korean(Value)+TEXT("���� �� �� �ִ� �丮�� ")+Menu_Con(Value)+TEXT("�� �ֽ��ϴ�.");
		SetDlgItemTextW(IDC_EDIT4,TEXT("explain(Con:")+Value+TEXT(")"));
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="explain"&&Slot=="Type")
	{
		now_act.push(TEXT("explain"));
		now_slot.push(Slot);
		now_value.push(Value);
		print_act=Conv_Korean(Value)+TEXT("�� �� �� �ִ� �丮�� ")+Menu_Type(Value)+TEXT("�� �ֽ��ϴ�.");
		SetDlgItemTextW(IDC_EDIT4,TEXT("explain(Type:")+Value+TEXT(")"));
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="impl_confirm"&&Slot=="Menu")
	{
		print_DA=TEXT("impl_confirm(Menu:"+Value+TEXT(")"));
		print_act=TEXT("�丮�� ")+Conv_Korean(Value)+TEXT("�� �����Ͽ����ϴ�.");
	}
	else if(act=="impl_confirm"&&Slot=="Con")
	{
		print_act=TEXT("�μ�ǰ���� ")+Conv_Korean(Value)+TEXT("�� �����Ͽ����ϴ�.");
	}
	else if(act=="impl_confirm"&&Slot=="Material")
	{
		print_act=TEXT("���� ")+Find_Material(TEXT("Korean"))+TEXT("�� �����Ͽ����ϴ�.");
	}
	else if(act=="impl_confirm"&&Slot=="Type")
	{
		print_act=TEXT("������ ")+Conv_Korean(Value)+TEXT("�� �����Ͽ����ϴ�.");
	}
	else if(act=="recipe")
	{
		CString info;
		info=Find_recipe(Slot,_ttoi(Value));
		if(info!="end")
		{
			SetDlgItemTextW(IDC_EDIT3,info);
			now_act.push(act);
			now_slot.push(Slot);
			now_value.push(Value);

			SetDlgItemTextW(IDC_EDIT4,TEXT("recipe(")+Slot+TEXT(":")+Value+TEXT(")"));
		}
		else
			Doact(TEXT("recipe_end"));
	}
	
}
void CTab3::Doact(CString act,CString Slot)
{
	//CString print_act;
	if(act=="explain")
	{
		now_act.push(TEXT("explain"));
		now_slot.push(Slot);
		print_act=Find_Material(TEXT("korean"))+TEXT("���� ����� �ִ� �丮�� ")+Find_menu()+TEXT("�� �ֽ��ϴ�");
		SetDlgItemTextW(IDC_EDIT4,TEXT("explain(material:")+Find_Material(TEXT("english"))+TEXT(")"));
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
}
void CTab3::Doact(CString act)
{
	
	if(act=="end")
	{
		//before_act=now_act;
		now_act.push(act);
		SetDlgItemTextW(IDC_EDIT4,TEXT("end"));
		SetDlgItemTextW(IDC_EDIT3,TEXT("���α׷��� �����մϴ�."));
	}
	else if(act=="setting_ok")
	{
		now_act.push(act);
		print_act=_T("�˶��� �����Ǿ����ϴ�");
		print_DA=act;
	}
	else if(act=="alarm_end")
	{
		now_act.push(act);
		print_act+=("�ð��� �Ǿ����ϴ�. ���� �ܰ踦 �����ұ��?");
		print_DA+=act;
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="movie_end")
	{
		now_act.push(act);
		print_act=("����� �Ϸ�Ǿ����ϴ�. ���� �ܰ踦 �����ұ��?");
		print_DA=act;
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="heat_start")
	{
		now_act.push(act);
		print_act=("������ �����Ǿ����ϴ�.");
		print_DA=act;
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="heat_end")
	{
		now_act.push(act);
		print_act=("���� �����ð��� �� �ƽ��ϴ�. ���� �ܰ踦 �����ұ��?");
		print_DA=act;
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="recipe_end")
	{
		now_act.push(act);
		SetDlgItemTextW(IDC_EDIT4,act);
		SetDlgItemTextW(IDC_EDIT3,TEXT("�丮�� �Ϸ�Ǿ����ϴ�. ���α׷��� �����մϴ�."));
	}
	else if(act=="start")
	{
		SetDlgItemTextW(IDC_EDIT4,TEXT("start"));
		SetDlgItemTextW(IDC_EDIT3,TEXT("LG Dios ���Ŀ��� ����� �Դϴ�. ������ ���͵帱���?"));

		slots.RemoveAll();

		for(int i=0;i<55;i++)
			Materials[i]=0;
		for(int i=0;i<25;i++)
		{
			material_point[i]=0;
			con_point[i]=0;
			type_point[i]=0;
		}

		SetDlgItemTextW(IDC_EDIT2,TEXT("Material:/ Menu:/ Con:/ Type:/ By:"));
		Slot_input=_T("");
		now_act.push(TEXT("start"));
		//before_act=TEXT("start");
		ViewNowValue();
	}
	else if(act=="restart")
	{
		now_act.~Stack();
		
		slots.RemoveAll();
		for(int i=0;i<55;i++)
			Materials[i]=0;
		for(int i=0;i<25;i++)
		{
			material_point[i]=0;
			con_point[i]=0;
			type_point[i]=0;
		}

		SetDlgItemTextW(IDC_EDIT2,TEXT("Material:/ Menu:/ Con:/ Type:/ By:"));
		Slot_input=_T("");
		ViewNowValue();
		now_act.push(TEXT("start"));
		SetDlgItemTextW(IDC_EDIT4,TEXT("start"));
		SetDlgItemTextW(IDC_EDIT3,TEXT("LG Dios ���Ŀ��� ����� �Դϴ�. ������ ���͵帱���?"));
	}
	else if(act=="goback")
	{
		print_act=TEXT("�������� �̵��մϴ�. ");

		if(now_act.top()=="recipe_q")
		{
			now_act.pop();
		}
		if(now_act.top()=="start")
		{
			print_act+=TEXT("LG Dios ���Ŀ��� ����� �Դϴ�. ������ ���͵帱���?");
			SetDlgItemTextW(IDC_EDIT4,now_act.top());
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else
		{
			now_act.pop();
			Doact(now_act.top());
		}
	}
	else if(act=="explain")
	{
		if(now_slot.top()=="material")
		{
			Doact(act,now_slot.top());
			now_slot.pop();
		}
		else
		{
			Doact(act,now_slot.top(),now_value.top());
			now_slot.pop();
			now_value.pop();
		}
	}
	else if(act=="recipe_q")
	{
		now_act.push(act);
		print_act+=TEXT("�׷� �丮���� �ȳ��� �帱���?");
		print_DA+=TEXT("recipe_q");
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
		//SetDlgItemTextW(IDC_EDIT4,now_act.top());
		//SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="null")
	{
		if(now_act.top()=="start")
		{
			now_act.push(TEXT("start_example"));
			print_act=TEXT("������ �ִ� ��� �Ǵ� ���Ͻô� �丮���� �������ּ���. �丮�� �Ҷ� ����ϰ��� �ϴ� �μ�ǰ �Ǵ� ����ϰ��� �ϴ� ��带 ������ �ּ���.");
			SetDlgItemTextW(IDC_EDIT4,now_act.top());
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else if(now_act.top()=="start_example")
		{
			now_act.push(TEXT("menu_example"));
			print_act=TEXT("������ �ִ� ��� �Ǵ� ���Ͻô� �丮���� ������ �ּ���. ���� ��� �����ڷ� ����� �ִ� �ִ� �丮�� ����? Ȥ�� ���õ� ���ڸ� ����� �ͽ��ϴ١� ��� ������ �ּ���.");
			SetDlgItemTextW(IDC_EDIT4,now_act.top());
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else if(now_act.top()=="menu_example")
		{
			now_act.push(TEXT("con_example"));
			print_act=TEXT("�μ�ǰ��  ��������,����,������������ �ֽ��ϴ�. ���� ��� ���������ø� ����ϴ� �丮�� ����� �; ��� ������ �ּ���.");
			SetDlgItemTextW(IDC_EDIT4,now_act.top());
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else if(now_act.top()=="con_example")
		{
			now_act.push(TEXT("type_example"));
			print_act=TEXT("���� �佺Ʈ�� ������ �ֽ��ϴ�. ���� ��� ���佺Ʈ ��带 ����ϰ� �; ��� ������ �ּ���.");
			SetDlgItemTextW(IDC_EDIT4,now_act.top());
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else if(now_act.top()=="explain")
		{
			Doact(_T("plase_repeat"));
		}
		else
		{
			print_act=TEXT("�˼��մϴ�. �� �𸣰ڽ��ϴ�. ���� �ܰ踦 �����Ͻðڽ��ϱ�?");
			SetDlgItemTextW(IDC_EDIT4,TEXT("sorry"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
	else if(act=="repeat")
	{
		if(now_act.top()=="recipe_q")
			now_act.pop();
		
		if(now_act.top()=="recipe")
			Doact(_T("recipe"),now_slot.top(),now_value.top());
		else if(now_act.top()=="explain")
		{
			if(now_slot.top()=="Type"||now_slot.top()=="Con")
				Doact(_T("explain"),now_slot.top(),now_value.top());
			else if(now_slot.top()=="Menu")
			{
				Doact(_T("explain"),now_slot.top(),now_value.top());
				Doact(_T("recipe_q"));
			}
			else 
			{
				Doact(_T("explain"),now_slot.top());
			}
		}
		else
			Doact(now_act.top());
	}
	else if(act=="affirm")
	{
		CString slot_menu;
		if(now_act.top()=="start")
		{
			print_act=TEXT("�߸��� �Է��Դϴ�. �ٽ� �ѹ� ������ �ֽʽÿ�.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else if(now_act.top()=="recipe_q")
		{
			CString slot_menu;
			slots.Lookup(TEXT("Menu"),slot_menu);
			Doact(TEXT("recipe"),slot_menu,TEXT("1"));
			//print_act=
			//SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			//SetDlgItemTextW(IDC_EDIT3,print_act);
			//impl_confirm("Menu",slot_menu);
		}
		else if(now_act.top()=="recipe"||now_act.top()=="alarm_end"||now_act.top()=="movie_end"||now_act.top()=="heat_end")
		{
			BOOL Done=false;

			CString Video_menu[5]={_T("gratin"),_T("roll_cake"),_T("scorn"),_T("sponge_cake"),_T("chocochip")};
			int Video_phase[5]={2,1,1,1,1};
			CString Heat_menu[25]={_T("gratin"),_T("roasted_sweet_potato"),_T("frozen_pizza"),_T("nurungji"),_T("drumstick"),_T("Tortilla"),_T("roll_cake"),
				_T("barbeque"),_T("scorn"),_T("sponge_cake"),_T("sweet_rice"),_T("deluxe_rice"),_T("spaghetti"),_T("chocochip"),_T("cheese_cake"),
				_T("potato"),_T("chicken"),_T("pork_belly"),_T("pizza"),_T("hamburger"),_T("garlic_bread"),_T("bagle"),_T("bread"),_T("pizza_toast"),
				_T("honey_bread")};
			int Heat_phase[25]={6,2,1,2,2,5,11,3,6,9,3,5,6,7,5,2,3,2,7,4,2,2,1,7,4};
			CString alarm_menu[10]={_T("drumstick"),_T("Tortilla"),_T("barbeque"),_T("scorn"),_T("sweet_rice"),_T("sweet_rice"),_T("deluxe_rice"),
				_T("deluxe_rice"),_T("chicken"),_T("pizza_toast")};
			int alarm_phase[10]={1,1,1,3,1,4,1,6,1,1};

			for(int i=0;i<5;i++)
			{
				if(now_slot.top()==Video_menu[i]&&_ttoi(now_value.top())==Video_menu[i])
				{
					Doact(_T("movie_end"));
					Done=true;
				}
			}
			for(int i=0;i<25;i++)
			{
				if(now_slot.top()==Heat_menu[i]&&_ttoi(now_value.top())==Heat_menu[i])
				{
					Doact(_T("heat_start"));
					Doact(_T("heat_end"));
					Done=true;
				}
			}
			for(int i=0;i<10;i++)
			{
				if(now_slot.top()==alarm_menu[i]&&_ttoi(now_value.top())==alarm_menu[i])
				{
					Doact(_T("setting_ok"));
					Doact(_T("alarm_end"));
					Done=true;
				}
			}
			if(!Done)
			{
				CString str;
				str.Format( _T("%d"),(_ttoi(now_value.top())+1));
				Doact(TEXT("recipe"),now_slot.top(),str);
			}
		}
		else
		{
			Doact(_T("please_repeat"));
		}
	}
	else if(act=="negate")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("�߸��� �Է��Դϴ�. �ٽ� �ѹ� ������ �ֽʽÿ�.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
	else if(act=="alarm_start")
	{
		BOOL Done=false;
		if(now_act.top()=="recipe")
		{
			CString alarm_menu[10]={_T("drumstick"),_T("Tortilla"),_T("barbeque"),_T("scorn"),_T("sweet_rice"),_T("sweet_rice"),_T("deluxe_rice"),
				_T("deluxe_rice"),_T("chicken"),_T("pizza_toast")};
			int alarm_phase[10]={1,1,1,3,1,4,1,6,1,1};

			for(int i=0;i<10;i++)
			{
				if(now_slot.top()==alarm_menu[i]&&_ttoi(now_value.top())==alarm_phase[i]);
				{
					Doact(_T("setting_ok"));
					Doact(_T("alarm_end"));
					Done=true;
				}
			}
			if(!Done)
				Doact(_T("sorry"));
		}
		else
			Doact(_T("please_repeat"));
		
	}
	else if(act=="movie_start")
	{
		BOOL Done=false;
		if(now_act.top()=="recipe")
		{
			CString Video_menu[5]={_T("gratin"),_T("roll_cake"),_T("scorn"),_T("sponge_cake"),_T("chocochip")};
			int Video_phase[5]={2,1,1,1,1};

			for(int i=0;i<5;i++)
			{
				if(now_slot.top()==Video_menu[i]&&_ttoi(now_value.top())==Video_phase[i]);
				{
					Doact(_T("movie_end"));
					Done=true;
				}
			}
			if(!Done)
				Doact(_T("sorry"));
		}
		else
			Doact(_T("please_repeat"));
	}
	else if(act=="heat_start")
	{
		BOOL Done=false;
		if(now_act.top()=="recipe")
		{
			CString Heat_menu[25]={_T("gratin"),_T("roasted_sweet_potato"),_T("frozen_pizza"),_T("nurungji"),_T("drumstick"),_T("Tortilla"),_T("roll_cake"),
				_T("barbeque"),_T("scorn"),_T("sponge_cake"),_T("sweet_rice"),_T("deluxe_rice"),_T("spaghetti"),_T("chocochip"),_T("cheese_cake"),
				_T("potato"),_T("chicken"),_T("pork_belly"),_T("pizza"),_T("hamburger"),_T("garlic_bread"),_T("bagle"),_T("bread"),_T("pizza_toast"),
				_T("honey_bread")};
			int Heat_phase[25]={6,2,1,2,2,5,11,3,6,9,3,5,6,7,5,2,3,2,7,4,2,2,1,7,4};

			for(int i=0;i<5;i++)
			{
				if(now_slot.top()==Heat_menu[i]&&_ttoi(now_value.top())==Heat_phase[i]);
				{
					Doact(_T("heat_start"));
					Doact(_T("heat_end"));
					Done=true;
				}
			}
			if(!Done)
				Doact(_T("sorry"));
		}
		else
			Doact(_T("please_repeat"));
	}
	else if(act=="next")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("�߸��� �Է��Դϴ�. �ٽ� �ѹ� ������ �ֽʽÿ�.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else if(now_act.top()=="recipe_q")
		{
			CString slot_menu;
			slots.Lookup(TEXT("Menu"),slot_menu);
			Doact(TEXT("recipe"),slot_menu,TEXT("1"));
			//print_act=
			//SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			//SetDlgItemTextW(IDC_EDIT3,print_act);
			//impl_confirm("Menu",slot_menu);
		}
		else if(now_act.top()=="recipe"||now_act.top()=="alarm_end"||now_act.top()=="movie_end"||now_act.top()=="heat_end")
		{
			BOOL Done=false;
			CString Heat_menu[25]={_T("gratin"),_T("roasted_sweet_potato"),_T("frozen_pizza"),_T("nurungji"),_T("drumstick"),_T("Tortilla"),_T("roll_cake"),
				_T("barbeque"),_T("scorn"),_T("sponge_cake"),_T("sweet_rice"),_T("deluxe_rice"),_T("spaghetti"),_T("chocochip"),_T("cheese_cake"),
				_T("potato"),_T("chicken"),_T("pork_belly"),_T("pizza"),_T("hamburger"),_T("garlic_bread"),_T("bagle"),_T("bread"),_T("pizza_toast"),
				_T("honey_bread")};
			int Heat_phase[25]={6,2,1,2,2,5,11,3,6,9,3,5,6,7,5,2,3,2,7,4,2,2,1,7,4};
			for(int i=0;i<25;i++)
			{
				if(now_slot.top()==Heat_menu[i]&&_ttoi(now_value.top())==Heat_menu[i])
				{
					Doact(_T("heat_start"));
					Doact(_T("heat_end"));
					Done=true;
				}
			}
			//CString slot_menu;
			//slots.Lookup(TEXT("Menu"),slot_menu);
			if(!Done)
			{
				CString str;
				str.Format( _T("%d"),(_ttoi(now_value.top())+1));
				Doact(TEXT("recipe"),now_slot.top(),str);
			}
			//int endlevel[25]={6,2,1,2,3,5,13,};
		}
		else
		{
			Doact(_T("please_repeat"));
		}
	}
	else if(act="please_repeat")
	{
		print_act=TEXT("�߸��� �Է��Դϴ�. �ٽ� �ѹ� ������ �ֽʽÿ�.");
		SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="reqalts")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("�߸��� �Է��Դϴ�. �ٽ� �ѹ� ������ �ֽʽÿ�.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
}
CString CTab3::Find_menu()
{
	CString Menu_Names[25]={TEXT("���� �׶���"),TEXT("������"),TEXT("�õ�����"),TEXT("������"),
		TEXT("�ߴٸ�"),TEXT("�Ƕ�� ����"),TEXT("������ũ"),TEXT("�� �ٺ�ť"),
		TEXT("����"),TEXT("������ ����ũ"),TEXT("���"),TEXT("�����"),TEXT("���� ���İ�Ƽ"),
		TEXT("����Ĩ ��Ű"),TEXT("ġ�� ����ũ"),TEXT("�밨��"),TEXT("���"),TEXT("�����"),TEXT("����"),
		TEXT("�ܹ��� ������ũ"),TEXT("���û�"),TEXT("���̱�"),TEXT("�Ļ�"),TEXT("�����佺Ʈ"),TEXT("��Ϻ극��")};
	
	CString list;
	BOOL first=true;
	int highst=0;

	get_bycon();
	get_bymaterial();
	get_bytype();
	for(int i=0;i<25;i++)
	{
		if(highst<type_point[i]+con_point[i]+material_point[i])
			highst=type_point[i]+con_point[i]+material_point[i];
	}

	for(int i=0;i<25;i++)
	{
		if(highst==type_point[i]+con_point[i]+material_point[i])
		{
			if(first)
			{
				list=Menu_Names[i];
				first=false;
			}
			else
				list+=TEXT(", ")+Menu_Names[i];
		}
	}
	return list;
}
CString CTab3::Find_Material(CString language)
{
	CString Material_Names[55]={TEXT("����"),TEXT("����"),TEXT("���ǰ���"),TEXT("����"),TEXT("��"),
		TEXT("�õ�����"),TEXT("���� �������"),TEXT("��������"),TEXT("��������"),TEXT("��������"),
		TEXT("�ް�"),TEXT("�ߴٸ�"),TEXT("����"),TEXT("������� ��"),TEXT("�Ƕ��"),TEXT("���"),
		TEXT("��¥���� ġ��"),TEXT("�ٴҶ����"),TEXT("�ڷº�"),TEXT("��"),TEXT("����"),TEXT("���̱�"),
		TEXT("������"),TEXT("����ŷ �Ҵ�"),TEXT("����ŷ�Ŀ��"),TEXT("���ø���"),TEXT("����"),
		TEXT("��ũ��"),TEXT("���İ�Ƽ��"),TEXT("�Ļ�"),TEXT("������"),TEXT("�����"),TEXT("����"),
		TEXT("��������"),TEXT("�ø����"),TEXT("�콺�� �ҽ�"),TEXT("�������"),TEXT("����"),TEXT("����"),
		TEXT("��"),TEXT("��������"),TEXT("�߷º�"),TEXT("����"),TEXT("û�Ǹ�"),TEXT("����Ĩ"),TEXT("��"),
		TEXT("ũ��ġ��"),TEXT("�丶�� ���̽�Ʈ"),TEXT("�����"),TEXT("�ĸ��� ġ��"),TEXT("�Ľ��� ����"),
		TEXT("���� ������"),TEXT("���ڼҽ�"),TEXT("��"),TEXT("ȫ�Ǹ�")};
	CString Material_ENames[55]={TEXT("eggplant"),TEXT("potato"),TEXT("cinnamon_powder"),TEXT("sweet_potato"),
		TEXT("honey"),TEXT("pizza"),TEXT("pork"),TEXT("crushed_galic"),TEXT("beef"),TEXT("small_green_onion"),
		TEXT("egg"),TEXT("drumstick"),TEXT("jujube"),TEXT("pork_rib"),TEXT("Tortilla"),TEXT("nonglutinous_rice"),
		TEXT("cheese"),TEXT("vanilla_oil"),TEXT("soft_flour"),TEXT("chestnut"),TEXT("butter"),TEXT("bagle"),
		TEXT("bacon"),TEXT("baking_soda"),TEXT("baking_powder"),TEXT("black_olive"),TEXT("chicken"),
		TEXT("cream"),TEXT("spaghetti"),TEXT("bread"),TEXT("rice"),TEXT("button_mushroom"),TEXT("onion"),
		TEXT("oregano"),TEXT("oligosaccharides"),TEXT("worcester_sauce"),TEXT("bay_leaf"),TEXT("meat_broth"),
		TEXT("ginkgo_nut"),TEXT("pine_nut"),TEXT("red_wine"),TEXT("medium_flour"),TEXT("sticky_rice"),
		TEXT("squid"),TEXT("chocochip"),TEXT("bean"),TEXT("cream_cheese"),TEXT("tomato_paste"),
		TEXT("pork_belly"),TEXT("parmesan"),TEXT("parsley"),TEXT("bread_crumbs"),TEXT("pizza_source"),
		TEXT("ham"),TEXT("red_peppers")};

	CString list;
	BOOL first=true;

	for(int i=0;i<55;i++)
	{
		if(Materials[i]==1)
		{
			if(first)
			{
				if(language=="korean")
					list=Material_Names[i];
				else if(language=="english")
					list=Material_ENames[i];

				first=false;
			}
			else
			{
				if(language=="korean")
					list+=TEXT(", ")+Material_Names[i];
				else if(language=="english")
					list+=TEXT(", ")+Material_ENames[i];
			}
		}
	}
	return list;
}
void CTab3::get_bytype()
{
	CString slot_type;
	if(slots.Lookup(TEXT("Type"),slot_type))
	{
		if(slot_type=="oven")
		{
			for(int i=0; i<20;i++)
				type_point[i]=100;
			for(int i=20; i<25;i++)
				type_point[i]=-300;
		}
		else if(slot_type=="toast")
		{
			for(int i=0; i<20;i++)
				type_point[i]=-300;
			for(int i=20; i<25;i++)
				type_point[i]=100;
		}
	}
}
void CTab3::get_bycon()
{
	CString slot_con;
	if(slots.Lookup(TEXT("Con"),slot_con))
	{
		if(slot_con=="plate")
		{
			for(int i=0; i<3;i++)
				con_point[i]=100;
			for(int i=3; i<6;i++)
				con_point[i]=-300;
			for(int i=6; i<18;i++)
				con_point[i]=100;
			for(int i=18; i<20;i++)
				con_point[i]=-300;

			con_point[20]=100;//���û�
			con_point[21]=-300;
			con_point[22]=-300;
			con_point[23]=100;//�����佺Ʈ
			con_point[24]=100;//��Ϻ극��
		}
		else if(slot_con=="grate")
		{
			for(int i=0; i<3;i++)
				con_point[i]=100;
			for(int i=3; i<7;i++)
				con_point[i]=-300;

			con_point[7]=100;
			con_point[8]=-300;
			for(int i=9; i<13;i++)
				con_point[i]=100;
			con_point[13]=-300;
			for(int i=14; i<18;i++)
				con_point[i]=100;
			for(int i=18; i<25;i++)
				con_point[i]=-300;
		}
		else if(slot_con=="pan")
		{
			for(int i=0; i<3;i++)
				con_point[i]=-300;
			for(int i=3; i<6;i++)
				con_point[i]=100;
			for(int i=6; i<13;i++)
				con_point[i]=-300;

			con_point[13]=100;

			for(int i=14; i<18;i++)
				con_point[i]=-300;
			con_point[18]=100;
			con_point[19]=100;
			con_point[20]=-300;
			con_point[21]=100;
			con_point[22]=100;
			con_point[23]=-300;
			con_point[24]=-300;
		}
	}
}
void CTab3::get_bymaterial()
{
	for(int i=0;i<55;i++)
	{
		if(Materials[i]==1)
		{
			switch(i)
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
	}
}
CString CTab3::Menu_Material(CString menu)
{
	CString list;
	CString Menu_Names[25]={TEXT("���� �׶���"),TEXT("������"),TEXT("�õ�����"),TEXT("������"),
		TEXT("�ߴٸ�"),TEXT("�Ƕ�� ����"),TEXT("������ũ"),TEXT("�� �ٺ�ť"),
		TEXT("����"),TEXT("������ ����ũ"),TEXT("���"),TEXT("�����"),TEXT("���� ���İ�Ƽ"),
		TEXT("����Ĩ ��Ű"),TEXT("ġ�� ����ũ"),TEXT("�밨��"),TEXT("���"),TEXT("�����"),TEXT("����"),
		TEXT("�ܹ��� ������ũ"),TEXT("���û�"),TEXT("���̱�"),TEXT("�Ļ�"),TEXT("�����佺Ʈ"),TEXT("��Ϻ극��")};
	int index;

	for(int i=0;i<25;i++)
	{
		if(menu==Menu_Names[i])
			index=i;
	}

	switch(index)
	{
	case 0:
		list=TEXT("����, ������, ����, ��¥���� ġ��");
		break;
	case 1:
		list=TEXT("����");
		break;
	case 2:
		list=TEXT("�õ�����");
		break;
	case 3:
		list=TEXT("������");
		break;
	case 4:
		list=TEXT("�ߴٸ�");
		break;
	case 5:
		list=TEXT("8��ġ �Ƕ��, �����ϴ� ���ڼҽ�, ������, ��, �����, û�Ǹ�, ȫ�Ǹ�, ����, �� �ø���, ��¥���� ġ��");
		break;
	case 6:
		list=TEXT("�ڷº�, �ް�, �ٴҶ����");
		break;
	case 7:
		list=TEXT("������� ��");
		break;
	case 8:
		list=TEXT("�߷º�, ����ŷ�Ŀ��, �ް�");
		break;
	case 9:
		list=TEXT("�ڷº�, �ٴҶ� ����, �ް�");
		break;
	case 10:
		list=TEXT("����, ���ǰ���, ��, ����, ��");
		break;
	case 11:
		list=TEXT("���, ����, ��, ����, ��, ��, ����");
		break;
	case 12:
		list=TEXT("���İ�Ƽ��, ����, ��¥���� ġ��, ���� ����, �ĸ��� ġ��");
		break;
	case 13:
		list=TEXT("�ڷº�, ����ŷ�Ŀ��, ����ŷ �Ҵ�, �ް�, ����Ĩ");
		break;
	case 14:
		list=TEXT("ũ��ġ��, �ް�, �ڷº�, ��ũ��");
		break;
	case 15:
		list=TEXT("����");
		break;
	case 16:
		list=TEXT("����");
		break;
	case 17:
		list=TEXT("�����");
		break;
	case 18:
		list=TEXT("���� ������, ��������, ��������, ���� ����, �丶�� ���̽�Ʈ, �������, ��������, ����, ������, ��, �����, û�Ǹ�, ȫ�Ǹ�, ����, ���ø���, ��¥���� ġ��");
		break;
	case 19:
		list=TEXT("���� ����, ���� �������, ���� ����, ���� ����, �ް�, ������, ����, �콺�� �ҽ�, ��������, ����");
		break;
	case 20:
		list=TEXT("�Ļ�, ���� ����, ���� �Ľ���, ����");
		break;
	case 21:
		list=TEXT("���̱�");
		break;
	case 22:
		list=TEXT("�Ļ�");
		break;
	case 23:
		list=TEXT("�Ļ�, ����, ���� �ҽ�, ������, ��, �����, û�Ǹ�, ȫ�Ǹ�, ����, ���ø���, ��¥����");
		break;
	case 24:
		list=TEXT("�Ļ�, ��, ����");
		break;
	}
	return list;
}
CString CTab3::Menu_Con(CString con)
{
	if(con=="plate")
		return TEXT("���� �׶���, ������, �õ�����, ������ũ, �� �ٺ�ť, ����, ������ ����ũ, ���, �����, ���� ���İ�Ƽ, ����Ĩ ��Ű, ġ�� ����ũ, �밨��, ���, �����, ���û�, �����佺Ʈ, ��Ϻ극��");
	else if(con=="grate")
		return TEXT("���� �׶���, ������, �õ�����, �� �ٺ�ť, ������ ����ũ, ���, �����, ���� ���İ�Ƽ, ġ�� ����ũ, �밨��, ���, �����");
	else if(con=="pan")
		return TEXT("������, �ߴٸ�, �Ƕ�� ����, ����Ĩ ��Ű, ����, �ܹ��� ������ũ, ���̱�, �Ļ�");
}
CString CTab3::Menu_Type(CString type)
{
	if(type=="oven")
		return TEXT("���� �׶���, ������, �õ�����, ������, �ߴٸ�, �Ƕ�� ����, ������ũ, �� �ٺ�ť, ����, ������ ����ũ, ���, �����, ���� ���İ�Ƽ, ����Ĩ ��Ű, ġ�� ����ũ, �밨��, ���, �����, ����, �ܹ��� ������ũ");
	else if(type=="toast")
		return TEXT("���û�, ���̱�, �Ļ�, �����佺Ʈ, ��Ϻ극��");
}
CString CTab3::Conv_Korean(CString ename)
{
	CString Menu_Names[30]={TEXT("����"),TEXT("�佺Ʈ"),TEXT("��������"),TEXT("����"),TEXT("����������"),TEXT("���� �׶���"),TEXT("������"),TEXT("�õ�����"),TEXT("������"),
		TEXT("�ߴٸ�"),TEXT("�Ƕ�� ����"),TEXT("������ũ"),TEXT("�� �ٺ�ť"),
		TEXT("����"),TEXT("������ ����ũ"),TEXT("���"),TEXT("�����"),TEXT("���� ���İ�Ƽ"),
		TEXT("����Ĩ ��Ű"),TEXT("ġ�� ����ũ"),TEXT("�밨��"),TEXT("���"),TEXT("�����"),TEXT("����"),
		TEXT("�ܹ��� ������ũ"),TEXT("���û�"),TEXT("���̱�"),TEXT("�Ļ�"),TEXT("�����佺Ʈ"),TEXT("��Ϻ극��")};
	CString Menu_ENames[30]={TEXT("oven"),TEXT("toast"),TEXT("plate"),TEXT("grate"),TEXT("pan"),TEXT("gratin"),TEXT("roasted_sweet_potato"),TEXT("frozen_pizza"),TEXT("nurungji"),TEXT("drumstick"),
		TEXT("Tortilla"),TEXT("roll_cake"),TEXT("barbeque"),TEXT("scorn"),TEXT("sponge_cake"),TEXT("sweet_rice"),TEXT("deluxe_rice"),
		TEXT("spaghetti"),TEXT("chocochip"),TEXT("cheese_cake"),TEXT("potato"),TEXT("chicken"),TEXT("pork_belly"),TEXT("pizza"),
		TEXT("hamburger"),TEXT("garlic_bread"),TEXT("bagle"),TEXT("bread"),TEXT("pizza_toast"),TEXT("honey_bread")};

	for(int i=0;i<30;i++)
	{
		if(ename==Menu_ENames[i])
			return Menu_Names[i];
	}
}
CString CTab3::Find_recipe(CString menu,int level)
{
	if(menu=="gratin")
	{
		switch(level)
		{
		case 1:
			return TEXT("���ڴ� ��� ����� �غ��մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return TEXT("������, ���ĸ� ä��� ���Ϳ� ���ƵӴϴ�. ä��� ������ ���ðڽ��ϱ�?");
			break;
		case 3:
			return TEXT("�ҿ� �а���, ���͸� �־� ���� �� ������ ���ݾ� �־� ���� �а��� �ۿ��� Ǯ�� �ұ�, ���߷� ���Ͽ� �ҽ��� ����ϴ�. �̶� ���� �ణ ���� �ϰ� �ҽ��� �ణ ���� �մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return TEXT("ȭ��Ʈ�ҽ� �̺��� �� �з��� ���� ���� ���ڸ� �־� �����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return TEXT("�׶�������, ���� 23��Ƽ ������ �������ÿ� �ҽ��� ������ ��Ḧ ��� ���� �ҽ��� ������ �� ���� ġ��, ������, �Ľ��� ������ �ø��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return TEXT("�������ÿ� ���踦 ���� �׶��� ���ø� �ø� �� 2�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="roasted_sweet_potato")
	{
		switch(level)
		{
		case 1:
			return TEXT("������ �ʹ� ũ�� �ʴ� ������ ��� ������ ���� �� ���⸦ �۾� ������ ��ũ�� ������ �� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return TEXT("1�ܿ� �������� ���� ���踦 ���� ������ �������� �÷��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="frozen_pizza")
	{
		switch(level)
		{
		case 1:
			return TEXT("�������ø� ���迡 ���� ������ ������ �õ����ڸ� �ø� �� 3�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="nurungji")
	{
		switch(level)
		{
		case 1:
			return TEXT("��¿� ������ ���� �� �̹�׶��� �������� �� ���� ��� ��ü�� �� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return TEXT("�ڵ��丮���쿡�� �������� ������ �� 4�ܿ� �÷��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="drumstick")
	{
		switch(level)
		{
		case 1:
			return TEXT("�ߴٸ��� Į���� �־��� �� �ұ�, ����, û�ֿ� �� ��ʺ� ���� ���ϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?");
			break;
		case 2:
			return TEXT("�ߴٸ��� �ø������� �ٸ� �� �������� �� ���� �������� ����, 4�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		case 3:
			return TEXT("���߿� ��ε� �︮�� �ѹ� �������ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="Tortilla")
	{
		switch(level)
		{
		case 1:
			return TEXT("������ ������ ���� �غ��մϴ�. ���� ����, û, ȫ�Ǹ�, ����̴� ������ ũ��� �� ������⿡ ��� ���� ���� �����丮������ ������� 2~3�� ������ �� ���⸦ ���۴ϴ�.  �˶������� �Ͻðڽ��ϱ�?");
			break;
		case 2:
			return TEXT("������, ���� ������ ũ��� �ڸ��ϴ�. ��¥���� ġ��� �߰� ������, �ø���� ����� ��� ����ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return TEXT("�Ƕ�� 2���� ���� �������� �ҿ� �ø��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return TEXT("��� �κп� ���ڼҽ��� ��� �� �ٸ��� ��, ������, �����, ����, �Ǹ� ������ �����մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return TEXT("��¥���� ġ� ��� �Ѹ� �� �ø���� ����Ͽ� 4�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="roll_cake")
	{
		switch(level)
		{
		case 1:
			return TEXT("�ڷº��� ü�� �Ӵϴ�. üġ�� ������ ���ðڽ��ϱ�?");
			break;
		case 2:
			return TEXT("������ ������ ������ �����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return TEXT("���� 2�� �غ��Ͽ� ������ ����, �ٸ� �� ���� �븥�ڸ� �и��� ���� �븥�� 1���� ���� ���Ӵϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return TEXT("�븥�ڸ� Ǯ�� �ұ�, ����, ����, ������ �Բ� �ְ� ���̺������� �ǵ��� ��ǰ�� ���ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return TEXT("���ڴ� ��� ���� ��ǰ�� �ø� �� ������ ���ݾ� ������ ������ ��ǰ�� �����ϰ� ���ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return TEXT("�븥�ڿ� ���ڸ� ����� ������ �ְ� ������ ���ٰ� ü�� ģ �а��縦 �־� �ְ����� ������ ������ �����ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 7:
			return _T("�Ŀ����� �־� ��� ���� ���� ������ ���� ��ǰ�� �־� ��ǰ�� ������� �ʵ��� �绡�� ���� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 8:
			return _T("�������ÿ� �������� ��� ������ �����ϰ� �ξ��ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 9:
			return _T("�븥�� 1���� �ұ��� �ణ �־� �� Ǯ�� ��Һ����� ��� ������ �۰� �վ� ���� ���� �긮�鼭 ������׷� ���̸� ����� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 10:
			return _T("���� �ݴ����� ���������� �ٽ� ������׷� ������ ���� ���̸� ����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 11:
			return _T("���� 2�ܿ� ��Ḧ �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		case 12:
			return _T("���� �麸�� �غ��Ͽ� �ٴڿ� ��� ������ ����ũ�� �ٴ��� ���� ������ ���� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 13:
			return _T("����ũ ���� ���� ��� �ٸ� �� �麸 �Ʒ��� ����̸� ��� ����ũ�� �о� ���� �����ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="barbeque")
	{
		switch(level)
		{
		case 1:
			return _T("���� ������ �غ��Ͽ� �⸧�� ���װ� ������ 2�ð����� �㰡 �͹��� ���ϴ�. �̸� ���� �˶������� �Ͻðڽ��ϱ�?");
			break;
		case 2:
			return _T("���⸦ �����ϰ� ���� ��, �ұ�, ���߷� �ذ��� �մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("�������� ���� ���踦 ���� ���� �÷��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		case 4:
			return _T("�з���� ���� �ҽ��� ����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return _T("���߿� ��ε� �︮�� �ҽ��� ������ ��� �ٸ� �� ���� �ð� ���� �� �����ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return _T("���� ���ÿ� ��� �ҽ��� �ѹ� �� ����� ���ϴ�. �����ܰ�� �����ұ��?");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="scorn")
	{
		switch(level)
		{
		case 1:
			return _T("�߷º�, ����ŷ �Ŀ���� üġ�� ����, �ұ�, ���� ������ ���͸� �ְ� �ڸ����� �����ϴ�. ���Ϳ� �а��簡 ��� ���� �ν��ν��� ���°� �ǵ��� ����ϴ�. �̿� ���� üġ�� �������� ���ðڽ��ϱ�?");
			break;
		case 2:
			return _T("�̸� ���� �ް��� ������ 1�� �ְ� �ڸ��� ��� �����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("���� ���簡 ������ �ʰ�, ������ �ϳ��� �������� ���� ���� ������� 30������ ���� ��ŵ�ϴ�. �̸� ���� �˸������� �Ͻðڽ��ϱ�?");
			break;
		case 4:
			return _T("������ �� 2.5��ġ �β��� �ǵ��� �д�� �� ���� ���� ũ��� �ڸ��ϴ�. �̶� �����縦 ����ؾ� �о� ��Ⱑ ���մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return _T("���� ���ÿ� �������� ��� ������ �ø� �� ǥ�鿡 �ް����� ĥ�մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return _T("2�ܿ� �ش� �������ø� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="sponge_cake")
	{
		switch(level)
		{
		case 1:
			return _T("�ڷº��� ü�� �Ӵϴ�. üġ�� ������ ���ðڽ��ϱ�?");
			break;
		case 2:
			return _T("����ũ Ʋ �ٴڰ� ���鿡 ���̸� ��� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("���͸� ������ �Բ� �쿩 �� �� �ٴҶ� ������ �� ��� ���� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return _T("�ް��� ������ ������ ������ �� ���� �ְ� Ǯ���ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return _T("�ް��� ������ �Ѳ����� �ְ� ��ǰ�⸦ ���� ���� �����ϰ� ��¦ ������ ������ ��ǰ�� ���ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return _T("��ǰ�� �ް��� �ڷº��� �ְ� ���� ���� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 7:
			return _T("�� ������ �Ϻθ� ���� ���� ������ �־� ���� �� �ٽ� ���׿� �־� �绡�� ���� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 8:
			return _T("������ Ʋ�� �װ� Ʋ�� �ѹ� ����ٰ� �ٴڿ� ���� ���� ���� ������ ���� �� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 9:
			return _T("�������� ���� ���踦 ���� ����ũ Ʋ�� �ø� �� 1�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="sweet_rice")
	{
		switch(level)
		{
		case 1:
			return _T("������ �� �ð� �̻� ���� �ҷ� ü�� ���� �Ӵϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?");
			break;
		case 2:
			return _T("���� ������ ���� 4����ϰ�, ���ߴ� ���� ������ 2����ϰ�, ���� ����� ������ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("���� ���ÿ� ���踦 ���� 2���� ���� ũ���� ���� ��⸦ �ø� �� �Ѳ� �Ǵ� �˷�̴� ȣ�Ϸ� ���� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		case 4:
			return _T("������ ������ ���쿡 �� 10�� ���� �״�� �ξ� �� ���� �� ������ ���⸧�� �ְ� ��� ���� �ݴϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?");
			break;
		case 5:
			return _T("���� ������ ���� ������ �����մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return _T("���쿡�� ���� ���� �� �����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 7:
			return _T("�ణ ������ ���� ��������� ���� ���� ���ÿ� �������ϴ�. �����ܰ�� �����ұ��?");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="deluxe_rice")
	{
		switch(level)
		{
		case 1:
			return _T("���, ������ �ľ 3�ð� �̻� �ҷ� �����ϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?");
			break;
		case 2:
			return _T("���� ������ ���� 2����ϰ�, ���� ����� ���� �����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("���ߴ� ���� ���� 2����ϰ�, ���� 6�ð� �̻� �ҷ��� �غ��մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return _T("������⿡ �Ҹ� ��, ��, ��, ����, ����, ��, �ұ��� �ְ� ���� �׽��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return _T("�������ÿ� ���踦 ���� 2�������� ũ���� ������⸦ �ø� �� �Ѳ� �Ǵ� �˷�̴� ȣ�Ϸ� ���� 1�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		case 6:
			return _T("������ ������ ���쿡 �� 10�� ���� �״�� �ξ� ���� ���Դϴ�. �̸� ���� �˶������� �Ͻðڽ��ϱ�?");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="spaghetti")
	{
		switch(level)
		{
		case 1:
			return _T("���� �ұݹ��� ���İ�Ƽ���� �ְ� ��� ���� ���� �����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return _T("������ 0.5��Ƽ �β��� �ձ۰� ��� �ұ�, ����, �ø������� �ణ�� �ְ� �������ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("�ҿ� ������ ��¦ ���� ���ÿ� �Ű� ����, �ø������� �ҿ� ��¦ �θ��� ���� ���ð� ���ĸ� �־� ���� �� �� ���� ����, �ұ�, ���߸� �ְ� ���� �����, ���, ������ ���� ���� �־� �����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return _T("3�� �丶�� ���̽�Ʈ�� ��ø�� �ְ� ������ ���� ������ �丶�並 �־� �� �� ����, �ּҽ�, ����� ��, ���� �־� ���̸鼭 �ұ�, ���߷� ���� �ϰ� �������� ���� ���� ������ �������븦 �־� ������ ���·� ����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return _T("��� ���� ���İ�Ƽ���� 4�� �ְ� ������ �������ÿ� ��� ���� ��¥���� ġ��� �ĸ��� ġ� ��� �ۼ� �� ���ĸ� �Ѹ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return _T("�������ÿ� ���踦 ���� �������ø� �÷��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="chocochip")
	{
		switch(level)
		{
		case 1:
			return _T("�ڷº�, ����ŷ�Ŀ��, ����ŷ �Ҵٴ� ü�� �Ӵϴ�. üġ�� ������ ���ðڽ��ϱ�?");
			break;
		case 2:
			return _T("�ǿ¿� �� ���͸� �� Ǯ�� ũ�� ���¸� ����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("������ �ְ� ���� ������ �� �����ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return _T("�ް��� Ǯ�� ���ݾ� ������ ������ ���Ϳ� �и����� �ʵ��� �绡�� �����ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return _T("üģ ����� ����Ĩ�� �־� ������ �� �⸧ �ٸ� �������ÿ� �������� �ҿ� ������ ������ �ΰ� �� ������ ���� ���� ��ũ�� ������ ���� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return _T("�������ô� 1�ܿ�, �������� ���� 4�ܿ� ���� �ֽ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 7:
			return _T("�������ÿ� �������� ���� �ְ� �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="cheese_cake")
	{
		switch(level)
		{
		case 1:
			return _T("ũ��ġ� ��¿� �ξ� �ε巯�� ���°� �ǵ��� �� �� ��ǰ�⸦ �̿��Ͽ� �� Ǯ���ݴϴ�. �ް��� �̸� Ǯ��Ӵϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return _T("1�� ũ��ġ� ������ �ް��� ���ݾ� ������ �־�� ��ǰ��� �����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("�ε巴�� Ǯ�� ���׿� �ڷºа� ��ũ���� �ְ� �ְ����� ��� �����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return _T("����ũ Ʋ�� �������� ��� �ٴڿ� ī���ڶ� ��Ʈ�� ���� ���� 3�� ������ �׽��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return _T("�������ÿ� ���踦 ���� ����ũƲ�� �ø� �� 1�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="potato")
	{
		switch(level)
		{
		case 1:
			return _T("���ڸ� ����� �ձ۰� ������ ũ��� ��� ������ ���� �� ���⸦ �۾�, ������ ��ũ�� ������ �� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return _T("�������� ���� ���踦 ���� ���ڸ� �������� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="chicken")
	{
		switch(level)
		{
		case 1:
			return _T("���� �ľ ���⸦ �۰� ������ ���� ���� �߶� ���� �� ������ Į���� ���� �ұ�, ����, û�ֿ� �� 30�� ���� ����ݴϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?");
			break;
		case 2:
			return _T("�� ������ �ø������� �ٸ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("�������ÿ� ���踦 ���� ���� �����κ��� �Ʒ��� ������ �Ͽ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		case 4:
			return _T("���߿� ��ε� �︮�� �ѹ� �������ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="pork_belly")
	{
		switch(level)
		{
		case 1:
			return _T("������ ��°�� �����Ͽ� 2~3���� ����� �ڸ� �� Į���� ���� �ұ�, ����, �ø������� ���緮 �Ѹ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return _T("�������� ���� ���踦 ���� ������� �����κ��� �Ʒ��� ������ �Ͽ� 1�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="pizza")
	{
		switch(level)
		{
		case 1:
			return _T("ũ����Ʈ�� ���� ���� ������� ���� �ְ� ���ױ�� ǥ���� �Ų��������� ġ�� ��, ������ �о �������� �ҿ� �ø��ϴ�.  �����ܰ�� �����ұ��?");
			break;
		case 2:
			return _T("�ҽ��� ���� �ޱ��� ���� ����, ���ĸ� �ְ� ���� �� ���� ���⸦ �ְ� ���� ��, �丶�����̽�Ʈ�� �ְ� �� ���� �� ������ �װ� ����� ���� �־� ������ ���·� ���̰� �������븦 �־� �� �����ݴϴ�. �������� �ұ�, ���߷� ���մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("������ ����, �Ǹ�, ����̴� ������ ũ��� �� ��¦ ���ļ� ���⸦ ���� ��, ������, ���� ������ ũ��� �ڸ��ϴ�. �׸���, ��¥���� ġ��� �߰� ������ �ø���� ����� ��� ��� �Ӵϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return _T("1�� ũ����Ʈ �����ڸ� 1��ġ ������ ����� ��� �κ��� ��ũ�� ���ְ�, �����ڸ� 1��ġ ���� �κп� �ø������� ��¦ �߶� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return _T("ũ����Ʈ ��� �κ��� 2�� �ҽ��� �� �� �ٸ��� ��¥���� ġ�� 50�׷��� ��� �Ѹ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return _T("��, ������, �����, ����, �Ǹ� ������ �����մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 7:
			return _T("���������� ������ ��¥���� ġ� ��� �Ѹ� �� �ø���� ����Ͽ� 4�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="hamburger")
	{
		switch(level)
		{
		case 1:
			return _T("���� �ޱ��� ���� ����, ���ĸ� �ְ� ���� �� �ѱ� �����ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return _T("���� ����, ������⿡ ���� ����, ����, �ް�, ����, ������, �ұ�, ����, ������ �ְ� ���Ⱑ ���� ������ ���� ġ�� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("���Ⱑ ���� ��� ������ 4����Ͽ� 1.5��ġ �β�, ���� 8��ġ�� ���� �����ϰ� ����� ��� �κ��� �����ϰ� ���� �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return _T("�������� �ҿ� �ø������� ������ �θ��� �������� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		case 5:
			return _T("���߿� ��ε� �︮�� �ѹ� ������ �ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return _T("���� �ޱ��� ���� ����, ���ĸ� �ְ� ���� �� ��ø�� �־� ��� ���̵��� ���� �ݴϴ�. �콺�� �ҽ�, ��������, ������ ���� �� �̺��� �Ϸ� �ɶ����� ���Դϴ�. �����ܰ�� �����ұ��?");
			break;
		case 7:
			return _T("������ ���ݾ� �־� ���� ������ �� �ұ�, ���߷� ���Ͽ� �������� ü�� �ɷ� �ܹ��� ������ũ�� ��鿩 ���ϴ�. �����ܰ�� �����ұ��?");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="garlic_bread")
	{
		switch(level)
		{
		case 1:
			return _T("��� ���Ϳ� ���� ����, ���� �Ľ����� ���� �Ļ��� �� �鿡 �ٸ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return _T("�������ÿ� �������� ��� �Ļ��� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="bagle")
	{
		switch(level)
		{
		case 1:
			return _T("���̱��� ������ �ڸ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return _T("���̱��� ���� ���� ���� �����Ͽ� �������� �ҿ� ��ġ�� �ʰ� �ø�����. �غ�ǽø� �����̶�� ������ �ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="bread")
	{
		switch(level)
		{
		case 1:
			return _T("�������� �ҿ� �Ļ��� ��ġ�� �ʰ� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		case 2:
			return _T("���߿� ��ε� �︮�� �ѹ� ������ �ش�. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="pizza_toast")
	{
		switch(level)
		{
		case 1:
			return _T("������ ������ ���� ����ϴ�. ����,û,ȫ�Ǹ�,����̴� ������ ũ��� �� ������⿡ ��� ���� ���� �����丮������ ������� 2~3�� ������ �� ���⸦ ���۴ϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?");
			break;
		case 2:
			return _T("������, ���� ������ ũ��� �ڸ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("��¥���� ġ��� �߰� ������ �ø���� ����� ��� ��� �Ӵϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return _T("��� ���͸� �Ļ��� �� �鿡 �ٸ� ��, ���ڼҽ��� �ٸ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 5:
			return _T("��, ������, �����, ����, �Ǹ� ������ �����մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 6:
			return _T("��¥���� ġ� ��� �Ѹ� �� �ø���� ����մϴ�. �����ܰ�� �����ұ��?");
			break;
		case 7:
			return _T("�������ÿ� �������� ��� �Ļ��� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}
	else if(menu=="honey_bread")
	{
		switch(level)
		{
		case 1:
			return _T("�� �Ļ��� ������ �ڸ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 2:
			return _T("�Ļ��� ���� ���� ���� ���� �Ͽ� �عٴڿ� ������ ���� �ʰ� ������ Į���� �־��ݴϴ�. �����ܰ�� �����ұ��?");
			break;
		case 3:
			return _T("Į���� �� �κп� ���� �ְ� �Ļ� �޸鿡 ���͸� �ٸ��ϴ�. �����ܰ�� �����ұ��?");
			break;
		case 4:
			return _T("�������ÿ� �������� ��� �Ļ��� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}

}