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

	if(Check_Input[2]==1)//goback input
		Doact(TEXT("restart"));
	if(Check_Input[0]==1)//end input
		Doact(TEXT("end"));
	if(Check_Input[4]==1)//repeat input
		Doact(TEXT("repeat"));

	if(now_act.top()=="start")
	{
		if(By=="none"){
			if(Check_Input[1]==1)//goback input
				Doact(TEXT("goback"));
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
			Doact(TEXT("explain"),TEXT("material"));
		else if(By=="bymenu")
			Doact(TEXT("explain"),TEXT("menu"),slot_menu);
	}

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
void CTab3::Doact(CString act,CString Slot,CString Value)
{
	if(act=="explain")
	{
	}
}
void CTab3::Doact(CString act,CString Slot)
{
	CString print_act;
	if(act=="explain")
	{
		now_act.push(TEXT("explain"));
		print_act=Find_Material(TEXT("korean"))+TEXT("���� ����� �ִ� �丮�� ")+Find_menu()+TEXT("�� �ֽ��ϴ�");
		SetDlgItemTextW(IDC_EDIT4,TEXT("explain(material:")+Find_Material(TEXT("english"))+TEXT(")"));
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
}
void CTab3::Doact(CString act)
{
	CString print_act;
	if(act=="end")
	{
		//before_act=now_act;
		now_act.push(act);
		SetDlgItemTextW(IDC_EDIT4,TEXT("end"));
		SetDlgItemTextW(IDC_EDIT3,TEXT("���α׷��� �����մϴ�."));
	}
	
	else if(act=="restart")
	{
		now_act.~Stack();
		now_act.push(TEXT("start"));
		SetDlgItemTextW(IDC_EDIT4,TEXT("start"));
		SetDlgItemTextW(IDC_EDIT3,TEXT("LG Dios ���Ŀ��� ����� �Դϴ�. ������ ���͵帱���?"));
	}
	else if(act=="goback")
	{
		print_act=TEXT("�������� �̵��մϴ�. ");

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
		else
		{
			print_act=TEXT("�˼��մϴ�. �� �𸣰ڽ��ϴ�. ���� �ܰ踦 �����Ͻðڽ��ϱ�?");
			SetDlgItemTextW(IDC_EDIT4,TEXT("sorry"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
	else if(act=="repeat")
	{
		Doact(now_act.top());
	}
	else if(act=="affirm")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("�߸��� �Է��Դϴ�. �ٽ� �ѹ� ������ �ֽʽÿ�.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
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
		if(now_act.top()=="start")
		{
			print_act=TEXT("�߸��� �Է��Դϴ�. �ٽ� �ѹ� ������ �ֽʽÿ�.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
	else if(act=="movie_start")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("�߸��� �Է��Դϴ�. �ٽ� �ѹ� ������ �ֽʽÿ�.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
	else if(act=="heat_start")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("�߸��� �Է��Դϴ�. �ٽ� �ѹ� ������ �ֽʽÿ�.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
	else if(act=="next")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("�߸��� �Է��Դϴ�. �ٽ� �ѹ� ������ �ֽʽÿ�.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
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
