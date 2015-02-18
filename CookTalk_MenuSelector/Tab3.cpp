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
	SetDlgItemTextW(IDC_EDIT3,TEXT("LG Dios 광파오븐 제어기 입니다. 무엇을 도와드릴까요?"));
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
	SetDlgItemTextW(IDC_EDIT4,TEXT("start"));
	SetDlgItemTextW(IDC_EDIT3,TEXT("LG Dios 광파오븐 제어기 입니다. 무엇을 도와드릴까요?"));

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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
void CTab3::Doact(CString act,CString Slot,CString Value)
{
	//CString print_act;
	if(act=="explain"&&Slot=="Menu")
	{
		now_act.push(TEXT("explain"));
		now_slot.push(Slot);
		now_value.push(Value);
		print_act+=Conv_Korean(Value)+TEXT("는 ")+Menu_Material(Conv_Korean(Value))+TEXT("가 재료로 필요합니다.");
		print_DA+=TEXT("explain(menu:")+Value+TEXT(")");
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="explain"&&Slot=="Con")
	{
		now_act.push(TEXT("explain"));
		now_slot.push(Slot);
		now_value.push(Value);
		print_act=Conv_Korean(Value)+TEXT("으로 할 수 있는 요리는 ")+Menu_Con(Value)+TEXT("가 있습니다.");
		SetDlgItemTextW(IDC_EDIT4,TEXT("explain(Con:")+Value+TEXT(")"));
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="explain"&&Slot=="Type")
	{
		now_act.push(TEXT("explain"));
		now_slot.push(Slot);
		now_value.push(Value);
		print_act=Conv_Korean(Value)+TEXT("로 할 수 있는 요리는 ")+Menu_Type(Value)+TEXT("가 있습니다.");
		SetDlgItemTextW(IDC_EDIT4,TEXT("explain(Type:")+Value+TEXT(")"));
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="impl_confirm"&&Slot=="Menu")
	{
		print_DA=TEXT("impl_confirm(Menu:"+Value+TEXT(")"));
		print_act=TEXT("요리로 ")+Conv_Korean(Value)+TEXT("를 선택하였습니다.");
	}
	else if(act=="impl_confirm"&&Slot=="Con")
	{
		print_act=TEXT("부속품으로 ")+Conv_Korean(Value)+TEXT("을 선택하였습니다.");
	}
	else if(act=="impl_confirm"&&Slot=="Material")
	{
		print_act=TEXT("재료로 ")+Find_Material(TEXT("Korean"))+TEXT("를 선택하였습니다.");
	}
	else if(act=="impl_confirm"&&Slot=="Type")
	{
		print_act=TEXT("종류로 ")+Conv_Korean(Value)+TEXT("를 선택하였습니다.");
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
		print_act=Find_Material(TEXT("korean"))+TEXT("으로 만들수 있는 요리는 ")+Find_menu()+TEXT("가 있습니다");
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
		SetDlgItemTextW(IDC_EDIT3,TEXT("프로그램을 종료합니다."));
	}
	else if(act=="setting_ok")
	{
		now_act.push(act);
		print_act=_T("알람이 설정되었습니다");
		print_DA=act;
	}
	else if(act=="alarm_end")
	{
		now_act.push(act);
		print_act+=("시간이 되었습니다. 이후 단계를 진행할까요?");
		print_DA+=act;
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="movie_end")
	{
		now_act.push(act);
		print_act=("재생이 완료되었습니다. 이후 단계를 진행할까요?");
		print_DA=act;
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="heat_start")
	{
		now_act.push(act);
		print_act=("오븐이 설정되었습니다.");
		print_DA=act;
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="heat_end")
	{
		now_act.push(act);
		print_act=("오븐 설정시간이 다 됐습니다. 이후 단계를 진행할까요?");
		print_DA=act;
		SetDlgItemTextW(IDC_EDIT4,print_DA);
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="recipe_end")
	{
		now_act.push(act);
		SetDlgItemTextW(IDC_EDIT4,act);
		SetDlgItemTextW(IDC_EDIT3,TEXT("요리가 완료되었습니다. 프로그램을 종료합니다."));
	}
	else if(act=="start")
	{
		SetDlgItemTextW(IDC_EDIT4,TEXT("start"));
		SetDlgItemTextW(IDC_EDIT3,TEXT("LG Dios 광파오븐 제어기 입니다. 무엇을 도와드릴까요?"));

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
		SetDlgItemTextW(IDC_EDIT3,TEXT("LG Dios 광파오븐 제어기 입니다. 무엇을 도와드릴까요?"));
	}
	else if(act=="goback")
	{
		print_act=TEXT("이전으로 이동합니다. ");

		if(now_act.top()=="recipe_q")
		{
			now_act.pop();
		}
		if(now_act.top()=="start")
		{
			print_act+=TEXT("LG Dios 광파오븐 제어기 입니다. 무엇을 도와드릴까요?");
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
		print_act+=TEXT("그럼 요리법을 안내해 드릴까요?");
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
			print_act=TEXT("가지고 있는 재료 또는 원하시는 요리명을 말씀해주세요. 요리를 할때 사용하고자 하는 부속품 또는 사용하고자 하는 모드를 말씀해 주세요.");
			SetDlgItemTextW(IDC_EDIT4,now_act.top());
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else if(now_act.top()=="start_example")
		{
			now_act.push(TEXT("menu_example"));
			print_act=TEXT("가지고 있는 재료 또는 원하시는 요리명을 말씀해 주세오. 예를 들면 “감자로 만들수 있는 있는 요리는 뭐야? 혹은 “냉동 피자를 만들고 싶습니다” 라고 말씀해 주세요.");
			SetDlgItemTextW(IDC_EDIT4,now_act.top());
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else if(now_act.top()=="menu_example")
		{
			now_act.push(TEXT("con_example"));
			print_act=TEXT("부속품은  법량접시,석쇠,구이전용팬이 있습니다. 예를 들면 “법량접시를 사용하는 요리를 만들고 싶어” 라고 말씀해 주세요.");
			SetDlgItemTextW(IDC_EDIT4,now_act.top());
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else if(now_act.top()=="con_example")
		{
			now_act.push(TEXT("type_example"));
			print_act=TEXT("모드는 토스트와 오븐이 있습니다. 예를 들면 “토스트 모드를 사용하고 싶어” 라고 말씀해 주세요.");
			SetDlgItemTextW(IDC_EDIT4,now_act.top());
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
		else if(now_act.top()=="explain")
		{
			Doact(_T("plase_repeat"));
		}
		else
		{
			print_act=TEXT("죄송합니다. 잘 모르겠습니다. 이후 단계를 진행하시겠습니까?");
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
			print_act=TEXT("잘못된 입력입니다. 다시 한번 말씀해 주십시오.");
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
			print_act=TEXT("잘못된 입력입니다. 다시 한번 말씀해 주십시오.");
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
			print_act=TEXT("잘못된 입력입니다. 다시 한번 말씀해 주십시오.");
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
		print_act=TEXT("잘못된 입력입니다. 다시 한번 말씀해 주십시오.");
		SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
		SetDlgItemTextW(IDC_EDIT3,print_act);
	}
	else if(act=="reqalts")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("잘못된 입력입니다. 다시 한번 말씀해 주십시오.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
}
CString CTab3::Find_menu()
{
	CString Menu_Names[25]={TEXT("감자 그라탱"),TEXT("군고구마"),TEXT("냉동피자"),TEXT("누룽지"),
		TEXT("닭다리"),TEXT("또띠아 피자"),TEXT("롤케이크"),TEXT("립 바비큐"),
		TEXT("스콘"),TEXT("스폰지 케이크"),TEXT("약식"),TEXT("영양밥"),TEXT("오븐 스파게티"),
		TEXT("초코칩 쿠키"),TEXT("치즈 케이크"),TEXT("통감자"),TEXT("통닭"),TEXT("통삼겹살"),TEXT("피자"),
		TEXT("햄버그 스테이크"),TEXT("마늘빵"),TEXT("베이글"),TEXT("식빵"),TEXT("피자토스트"),TEXT("허니브레드")};
	
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
	CString Material_Names[55]={TEXT("가지"),TEXT("감자"),TEXT("계피가루"),TEXT("고구마"),TEXT("꿀"),
		TEXT("냉동피자"),TEXT("다진 돼지고기"),TEXT("다진마늘"),TEXT("다진쇠고기"),TEXT("다진실파"),
		TEXT("달걀"),TEXT("닭다리"),TEXT("대추"),TEXT("돼지고기 립"),TEXT("또띠아"),TEXT("멥쌀"),
		TEXT("모짜렐라 치즈"),TEXT("바닐라오일"),TEXT("박력분"),TEXT("밤"),TEXT("버터"),TEXT("베이글"),
		TEXT("베이컨"),TEXT("베이킹 소다"),TEXT("베이킹파우더"),TEXT("블랙올리브"),TEXT("생닭"),
		TEXT("생크림"),TEXT("스파게티면"),TEXT("식빵"),TEXT("식은밥"),TEXT("양송이"),TEXT("양파"),
		TEXT("오레가노"),TEXT("올리고당"),TEXT("우스터 소스"),TEXT("월계수잎"),TEXT("육수"),TEXT("은행"),
		TEXT("잣"),TEXT("적포도주"),TEXT("중력분"),TEXT("찹쌀"),TEXT("청피망"),TEXT("초코칩"),TEXT("콩"),
		TEXT("크림치즈"),TEXT("토마토 페이스트"),TEXT("통삼겹살"),TEXT("파마산 치즈"),TEXT("파슬리 가루"),
		TEXT("피자 빵가루"),TEXT("피자소스"),TEXT("햄"),TEXT("홍피망")};
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

			con_point[20]=100;//마늘빵
			con_point[21]=-300;
			con_point[22]=-300;
			con_point[23]=100;//피자토스트
			con_point[24]=100;//허니브레드
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
	}
}
CString CTab3::Menu_Material(CString menu)
{
	CString list;
	CString Menu_Names[25]={TEXT("감자 그라탱"),TEXT("군고구마"),TEXT("냉동피자"),TEXT("누룽지"),
		TEXT("닭다리"),TEXT("또띠아 피자"),TEXT("롤케이크"),TEXT("립 바비큐"),
		TEXT("스콘"),TEXT("스폰지 케이크"),TEXT("약식"),TEXT("영양밥"),TEXT("오븐 스파게티"),
		TEXT("초코칩 쿠키"),TEXT("치즈 케이크"),TEXT("통감자"),TEXT("통닭"),TEXT("통삼겹살"),TEXT("피자"),
		TEXT("햄버그 스테이크"),TEXT("마늘빵"),TEXT("베이글"),TEXT("식빵"),TEXT("피자토스트"),TEXT("허니브레드")};
	int index;

	for(int i=0;i<25;i++)
	{
		if(menu==Menu_Names[i])
			index=i;
	}

	switch(index)
	{
	case 0:
		list=TEXT("감자, 베이컨, 양파, 모짜렐라 치즈");
		break;
	case 1:
		list=TEXT("고구마");
		break;
	case 2:
		list=TEXT("냉동피자");
		break;
	case 3:
		list=TEXT("식은밥");
		break;
	case 4:
		list=TEXT("닭다리");
		break;
	case 5:
		list=TEXT("8인치 또띠아, 시판하는 피자소스, 베이컨, 햄, 양송이, 청피망, 홍피망, 양파, 블랙 올리브, 모짜렐라 치즈");
		break;
	case 6:
		list=TEXT("박력분, 달걀, 바닐라오일");
		break;
	case 7:
		list=TEXT("돼지고기 립");
		break;
	case 8:
		list=TEXT("중력분, 베이킹파우더, 달걀");
		break;
	case 9:
		list=TEXT("박력분, 바닐라 오일, 달걀");
		break;
	case 10:
		list=TEXT("찹쌀, 계피가루, 밤, 대추, 잣");
		break;
	case 11:
		list=TEXT("멥쌀, 찹쌀, 밤, 대추, 잣, 콩, 은행");
		break;
	case 12:
		list=TEXT("스파게티면, 가지, 모짜렐라 치즈, 다진 실파, 파마산 치즈");
		break;
	case 13:
		list=TEXT("박력분, 베이킹파우더, 베이킹 소다, 달걀, 초코칩");
		break;
	case 14:
		list=TEXT("크림치즈, 달걀, 박력분, 생크림");
		break;
	case 15:
		list=TEXT("감자");
		break;
	case 16:
		list=TEXT("생닭");
		break;
	case 17:
		list=TEXT("통삼겹살");
		break;
	case 18:
		list=TEXT("피자 빵가루, 다진마늘, 다진양파, 다진 쇠고기, 토마토 페이스트, 월계수잎, 오레가노, 육수, 베이컨, 햄, 양송이, 청피망, 홍피망, 양파, 블랙올리브, 모짜렐라 치즈");
		break;
	case 19:
		list=TEXT("다진 쇠고기, 다진 돼지고기, 다진 마늘, 다진 양파, 달걀, 빵가루, 양파, 우스터 소스, 적포도주, 육수");
		break;
	case 20:
		list=TEXT("식빵, 다진 마늘, 다진 파슬리, 버터");
		break;
	case 21:
		list=TEXT("베이글");
		break;
	case 22:
		list=TEXT("식빵");
		break;
	case 23:
		list=TEXT("식빵, 버터, 피자 소스, 베이컨, 햄, 양송이, 청피망, 홍피망, 양파, 블랙올리브, 모짜렐라");
		break;
	case 24:
		list=TEXT("식빵, 꿀, 버터");
		break;
	}
	return list;
}
CString CTab3::Menu_Con(CString con)
{
	if(con=="plate")
		return TEXT("감자 그라탱, 군고구마, 냉동피자, 롤케이크, 립 바비큐, 스콘, 스폰지 케이크, 약식, 영양밥, 오븐 스파게티, 초코칩 쿠키, 치즈 케이크, 통감자, 통닭, 통삼겹살, 마늘빵, 피자토스트, 허니브레드");
	else if(con=="grate")
		return TEXT("감자 그라탱, 군고구마, 냉동피자, 립 바비큐, 스폰지 케이크, 약식, 영양밥, 오븐 스파게티, 치즈 케이크, 통감자, 통닭, 통삼겹살");
	else if(con=="pan")
		return TEXT("누룽지, 닭다리, 또띠아 피자, 초코칩 쿠키, 피자, 햄버그 스테이크, 베이글, 식빵");
}
CString CTab3::Menu_Type(CString type)
{
	if(type=="oven")
		return TEXT("감자 그라탱, 군고구마, 냉동피자, 누룽지, 닭다리, 또띠아 피자, 롤케이크, 립 바비큐, 스콘, 스폰지 케이크, 약식, 영양밥, 오븐 스파게티, 초코칩 쿠키, 치즈 케이크, 통감자, 통닭, 통삼겹살, 피자, 햄버그 스테이크");
	else if(type=="toast")
		return TEXT("마늘빵, 베이글, 식빵, 피자토스트, 허니브레드");
}
CString CTab3::Conv_Korean(CString ename)
{
	CString Menu_Names[30]={TEXT("오븐"),TEXT("토스트"),TEXT("법량접시"),TEXT("석쇠"),TEXT("구이전용팬"),TEXT("감자 그라탱"),TEXT("군고구마"),TEXT("냉동피자"),TEXT("누룽지"),
		TEXT("닭다리"),TEXT("또띠아 피자"),TEXT("롤케이크"),TEXT("립 바비큐"),
		TEXT("스콘"),TEXT("스폰지 케이크"),TEXT("약식"),TEXT("영양밥"),TEXT("오븐 스파게티"),
		TEXT("초코칩 쿠키"),TEXT("치즈 케이크"),TEXT("통감자"),TEXT("통닭"),TEXT("통삼겹살"),TEXT("피자"),
		TEXT("햄버그 스테이크"),TEXT("마늘빵"),TEXT("베이글"),TEXT("식빵"),TEXT("피자토스트"),TEXT("허니브레드")};
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
			return TEXT("감자는 삶아 으깨어서 준비합니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return TEXT("베이컨, 양파를 채썰어 버터에 볶아둡니다. 채썰기 영상을 보시겠습니까?");
			break;
		case 3:
			return TEXT("팬에 밀가루, 버터를 넣어 볶은 후 우유를 조금씩 넣어 가며 밀가루 멍울을 풀고 소금, 후추로 간하여 소스를 만듭니다. 이때 간을 약간 세게 하고 소스는 약간 묽게 합니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return TEXT("화이트소스 이분의 삼 분량에 볶은 재료와 감자를 넣어 섞습니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return TEXT("그라탱접시, 지름 23센티 정도의 내열접시에 소스를 버무린 재료를 담고 남은 소스를 끼얹은 후 다진 치즈, 빵가루, 파슬리 순으로 올립니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return TEXT("법랑접시에 석쇠를 놓고 그라탱 접시를 올린 후 2단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return TEXT("고구마는 너무 크지 않는 것으로 골라 깨끗이 씻은 후 물기를 닦아 껍질을 포크로 몇차례 찔러 줍니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return TEXT("1단에 법랑접시 위에 석쇠를 놓고 고구마를 가지런히 올려주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return TEXT("법랑접시를 석쇠에 놓고 포장을 제거한 냉동피자를 올린 후 3단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return TEXT("상온에 보관된 식은 밥 이백그람을 구이전용 팬 위에 얇게 전체로 펴 줍니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return TEXT("자동요리오븐에서 누룽지를 선택한 후 4단에 올려주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return TEXT("닭다리에 칼집을 넣어준 후 소금, 후추, 청주에 약 삼십분 정도 재웁니다. 이를 위한 알람 셋팅을 하시겠습니까?");
			break;
		case 2:
			return TEXT("닭다리에 올리브유를 바른 후 구이전용 팬 위에 가지런히 놓고, 4단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
			break;
		case 3:
			return TEXT("도중에 멜로디가 울리면 한번 뒤집어줍니다. 다음단계로 진행할까요?");
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
			return TEXT("토핑을 다음과 같이 준비합니다. 먼저 양파, 청, 홍피망, 양송이는 적당한 크기롤 썰어서 내열용기에 담고 랩을 씌워 수동요리레인지 기능으로 2~3분 가열한 후 물기를 없앱니다.  알람설정을 하시겠습니까?");
			break;
		case 2:
			return TEXT("베이컨, 햄은 적당한 크기로 자릅니다. 모짜렐라 치즈는 잘게 다지고, 올리브는 모양대로 얇게 썰어줍니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return TEXT("또띠아 2장을 겹쳐 구이전용 팬에 올립니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return TEXT("가운데 부분에 피자소스를 고루 펴 바르고 햄, 베이컨, 양송이, 양파, 피망 순으로 토핑합니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return TEXT("모짜렐라 치즈를 고루 뿌린 뒤 올리브로 장식하여 4단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return TEXT("박력분은 체쳐 둡니다. 체치기 영상을 보시겠습니까?");
			break;
		case 2:
			return TEXT("설탕은 적당히 반으로 나눕니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return TEXT("볼을 2개 준비하여 한쪽은 흰자, 다른 한 쪽은 노른자를 분리해 놓고 노른자 1개는 따로 빼둡니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return TEXT("노른자를 풀어 소금, 설탕, 물엿, 우유를 함께 넣고 아이보리색이 되도록 거품을 냅니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return TEXT("흰자는 어느 정도 거품을 올린 후 설탕을 조금씩 나누어 넣으며 거품을 빳빳하게 내줍니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return TEXT("노른자에 흰자를 삼분의 일정도 넣고 가볍게 섞다가 체에 친 밀가루를 넣어 주걱으로 가볍고 빠르게 섞어줍니다. 다음단계로 진행할까요?");
			break;
		case 7:
			return _T("식용유를 넣어 고루 섞은 다음 나머지 흰자 거품을 넣어 거품이 가라앉지 않도록 재빨리 섞어 줍니다. 다음단계로 진행할까요?");
			break;
		case 8:
			return _T("법랑접시에 유산지를 깔고 반죽을 평평하게 부어줍니다. 다음단계로 진행할까요?");
			break;
		case 9:
			return _T("노른자 1개에 소금을 약간 넣어 잘 풀어 비닐봉지에 담고 구멍을 작게 뚫어 반죽 위에 흘리면서 지그재그로 무늬를 만들어 줍니다. 다음단계로 진행할까요?");
			break;
		case 10:
			return _T("무늬 반대편을 젓가락으로 다시 지그재그로 휘저어 물결 무늬를 만듭니다. 다음단계로 진행할까요?");
			break;
		case 11:
			return _T("오븐 2단에 재료를 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
			break;
		case 12:
			return _T("젖은 면보를 준비하여 바닥에 깔고 구워낸 케이크를 바닥이 위로 오도록 엎어 줍니다. 다음단계로 진행할까요?");
			break;
		case 13:
			return _T("케이크 위에 잼을 고루 바른 뒤 면보 아래로 방망이를 대고 케이크를 밀어 가며 말아줍니다. 다음단계로 진행할까요?");
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
			return _T("립은 통으로 준비하여 기름을 떼네고 찬물에 2시간정도 담가 핏물을 뺍니다. 이를 위한 알람셋팅을 하시겠습니까?");
			break;
		case 2:
			return _T("물기를 제거하고 레몬 즙, 소금, 후추로 밑간을 합니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("법랑접시 위에 석쇠를 놓고 립을 올려주세요. 준비되시면 다음이라고 말씀해주세요.");
			break;
		case 4:
			return _T("분량대로 섞어 소스를 만듭니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return _T("도중에 멜로디가 울리면 소스를 붓으로 고루 바른 후 남은 시간 동안 더 구워줍니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return _T("립을 접시에 담고 소스를 한번 더 끼얹어 냅니다. 다음단계로 진행할까요?");
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
			return _T("중력분, 베이킹 파우더는 체치고 설탕, 소금, 냉장 보관한 버터를 넣고 자르듯이 섞습니다. 버터와 밀가루가 고루 섞여 부슬부슬한 상태가 되도록 만듭니다. 이에 관한 체치기 동영상을 보시겠습니까?");
			break;
		case 2:
			return _T("미리 섞은 달걀과 우유를 1에 넣고 자르듯 고루 섞습니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("마른 가루가 보이지 않고, 반죽이 하나로 뭉쳐지면 랩을 덮어 냉장고에서 30분정도 숙성 시킵니다. 이를 위한 알림셋팅을 하시겠습니까?");
			break;
		case 4:
			return _T("반죽을 약 2.5센치 두께가 되도록 밀대로 민 다음 같은 크기로 자릅니다. 이때 덧가루를 사용해야 밀어 펴기가 편리합니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return _T("법랑 접시에 유산지를 깔고 스콘을 올린 후 표면에 달걀물을 칠합니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return _T("2단에 해당 법랑접시를 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("박력분은 체쳐 둡니다. 체치기 영상을 보시겠습니까?");
			break;
		case 2:
			return _T("케이크 틀 바닥과 옆면에 종이를 깔아 줍니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("버터를 우유에 함께 녹여 준 후 바닐라 오일을 한 방울 섞어 줍니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return _T("달걀을 따뜻한 물에서 중탕한 후 볼에 넣고 풀어줍니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return _T("달걀과 설탕을 한꺼번에 넣고 거품기를 들어보아 끝이 뾰족하고 살짝 숙여질 때까지 거품을 냅니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return _T("거품낸 달걀에 박력분을 넣고 골고루 섞어 줍니다. 다음단계로 진행할까요?");
			break;
		case 7:
			return _T("위 반죽의 일부를 버터 녹인 우유에 넣어 섞은 후 다시 반죽에 넣어 재빨리 섞어 줍니다. 다음단계로 진행할까요?");
			break;
		case 8:
			return _T("반죽을 틀에 붓고 틀을 한번 들었다가 바닥에 놓아 반죽 속의 기포를 고르게 해 줍니다. 다음단계로 진행할까요?");
			break;
		case 9:
			return _T("법랑접시 위에 석쇠를 놓고 케이크 틀을 올린 후 1단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("찹쌀을 한 시간 이상 물에 불려 체에 건져 둡니다. 이를 위한 알람 셋팅을 하시겠습니까?");
			break;
		case 2:
			return _T("밤은 껍질을 벗겨 4등분하고, 대추는 씨를 빼내어 2등분하고, 잣은 고깔을 떼어냅니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("법랑 접시에 석쇠를 놓고 2리터 정도 크기의 내열 용기를 올린 후 뚜껑 또는 알루미늄 호일로 덮어 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
			break;
		case 4:
			return _T("가열이 끝나면 오븐에 약 10분 정도 그대로 두어 뜸 들인 후 꺼내어 참기름을 넣고 고루 섞어 줍니다. 이를 위한 알람 셋팅을 하시겠습니까?");
			break;
		case 5:
			return _T("잣이 완전히 익을 때까지 가열합니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return _T("오븐에서 꺼낸 다음 잘 식힙니다. 다음단계로 진행할까요?");
			break;
		case 7:
			return _T("약간 따뜻한 밥을 공모양으로 만든 다음 접시에 내놓습니다. 다음단계로 진행할까요?");
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
			return _T("멥쌀, 찹쌀은 씻어서 3시간 이상 불려 놓습니다. 이를 위한 알람 셋팅을 하시겠습니까?");
			break;
		case 2:
			return _T("밤은 껍질을 벗겨 2등분하고, 잣은 고깔을 떼어 놓습니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("대추는 씨를 빼고 2등분하고, 콩은 6시간 이상 불려서 준비합니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return _T("내열용기에 불린 쌀, 콩, 밤, 은행, 대추, 잣, 소금을 넣고 물을 붓습니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return _T("법랑접시에 석쇠를 놓고 2리터정도 크기의 내열용기를 올린 후 뚜껑 또는 알루미늄 호일로 덮어 1단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
			break;
		case 6:
			return _T("가열이 끝나면 오븐에 약 10분 정도 그대로 두어 뜸을 들입니다. 이를 위한 알람셋팅을 하시겠습니까?");
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
			return _T("끓는 소금물에 스파게티면을 넣고 삶아 물기 없이 건집니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return _T("가지는 0.5센티 두께로 둥글게 썰어 소금, 후추, 올리브유를 약간씩 넣고 버무립니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("팬에 가지를 살짝 볶아 접시에 옮겨 놓고, 올리브유를 팬에 살짝 두르고 다진 마늘과 양파를 넣어 볶아 준 후 갈은 쇠고기, 소금, 후추를 넣고 볶아 양송이, 당근, 샐러리 다진 것을 넣어 익힙니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return _T("3에 토마토 페이스트와 케첩을 넣고 껍질과 씨를 제거한 토마토를 넣어 준 후 설탕, 핫소스, 월계수 잎, 물을 넣어 끓이면서 소금, 후추로 간을 하고 마지막에 볶아 놓은 가지와 오레가노를 넣어 걸쭉한 상태로 만듭니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return _T("삶아 놓은 스파게티면을 4에 넣고 버무려 내열접시에 담고 다진 모짜렐라 치즈와 파마산 치즈를 얹어 송송 썬 실파를 뿌립니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return _T("법랑접시에 석쇠를 놓고 내열접시를 올려주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("박력분, 베이킹파우더, 베이킹 소다는 체쳐 둡니다. 체치기 영상을 보시겠습니까?");
			break;
		case 2:
			return _T("실온에 둔 버터를 잘 풀어 크림 상태를 만듭니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("설탕을 넣고 녹을 때까지 잘 섞어줍니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return _T("달걀을 풀어 조금씩 나누어 넣으며 버터와 분리되지 않도록 재빨리 섞어줍니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return _T("체친 가루와 초코칩을 넣어 반죽한 후 기름 바른 법랑접시와 구이전용 팬에 적당한 간격을 두고 반 수저씩 놓은 다음 포크로 가볍게 눌러 줍니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return _T("법랑접시는 1단에, 구이전용 팬은 4단에 각각 넣습니다. 다음단계로 진행할까요?");
			break;
		case 7:
			return _T("법랑접시와 구이전용 팬을 넣고 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("크림치즈를 상온에 두어 부드러운 상태가 되도록 한 뒤 거품기를 이용하여 잘 풀어줍니다. 달걀도 미리 풀어둡니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return _T("1의 크림치즈에 설탕과 달걀을 조금씩 나누어 넣어가며 거품기로 섞습니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("부드럽게 풀린 반죽에 박력분과 생크림을 넣고 주걱으로 고루 섞습니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return _T("케이크 틀에 유산지를 깔고 바닥에 카스텔라 시트를 놓은 다음 3의 반죽을 붓습니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return _T("법랑접시에 석쇠를 놓고 케이크틀을 올린 후 1단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("감자를 모양이 둥글고 적당한 크기로 골라 깨끗이 씻은 후 물기를 닦아, 껍질을 포크로 몇차례 찔러 줍니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return _T("법랑접시 위에 석쇠를 놓고 감자를 가지런히 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("닭을 씻어서 물기를 닦고 꽁지와 날개 끝을 잘라 내고 닭 껍질에 칼집을 내어 소금, 후추, 청주에 약 30분 정도 재워줍니다. 이를 위한 알람 셋팅을 하시겠습니까?");
			break;
		case 2:
			return _T("닭 껍질에 올리브유를 바릅니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("법량접시에 석쇠를 놓고 닭의 가슴부분이 아래로 가도록 하여 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
			break;
		case 4:
			return _T("도중에 멜로디가 울리면 한번 뒤집어줍니다. 다음단계로 진행할까요?");
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
			return _T("삼겹살은 통째로 구입하여 2~3개의 덩어리로 자른 후 칼집을 내고 소금, 후추, 올리브유를 적당량 뿌립니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return _T("법랑접시 위에 석쇠를 놓고 통삼겹살의 껍질부분이 아래로 가도록 하여 1단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("크러스트는 볼에 피자 빵가루와 물을 넣고 반죽기로 표면이 매끈해지도록 치댄 후, 반죽을 밀어서 구이전용 팬에 올립니다.  다음단계로 진행할까요?");
			break;
		case 2:
			return _T("소스는 팬을 달구어 다진 마늘, 양파를 넣고 볶은 후 다진 쇠고기를 넣고 볶은 후, 토마토페이스트를 넣고 잘 섞은 후 육수를 붓고 월계수 잎을 넣어 걸쭉한 상태로 졸이고 오레가노를 넣어 잘 섞어줍니다. 마지막에 소금, 후추로 간합니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("토핑은 양파, 피망, 양송이는 적당한 크기로 썰어서 살짝 데쳐서 물기를 없앤 후, 베이컨, 햄은 적당한 크기로 자릅니다. 그리고, 모짜렐라 치즈는 잘게 다지고 올리브는 모양대로 얇게 썰어 둡니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return _T("1의 크러스트 가장자리 1센치 정도만 남기고 가운데 부분은 포크로 찔러주고, 가장자리 1센치 남긴 부분에 올리브유를 살짝 발라 줍니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return _T("크러스트 가운데 부분의 2의 소스를 고구 펴 바르고 모짜렐라 치즈 50그램을 얇게 뿌립니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return _T("햄, 베이컨, 양송이, 양파, 피망 순으로 토핑합니다. 다음단계로 진행할까요?");
			break;
		case 7:
			return _T("마지막으로 나머지 모짜렐라 치즈를 고루 뿌린 뒤 올리브로 장식하여 4단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("팬을 달구어 다진 마늘, 양파를 넣고 볶은 후 한김 식힙니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return _T("다진 쇠고기, 돼지고기에 다진 마늘, 양파, 달걀, 우유, 빵가루, 소금, 후추, 분유를 넣고 끈기가 생길 때까지 힘껏 치대 줍니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("끈기가 생긴 고기 반죽을 4등분하여 1.5센치 두께, 지름 8센치로 동글 납작하게 만들어 가운데 부분을 오목하게 눌러 줍니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return _T("구이전용 팬에 올리브유를 적당히 두르고 가지런히 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
			break;
		case 5:
			return _T("도중에 멜로디가 울리면 한번 뒤집어 줍니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return _T("팬을 달구어 다진 마늘, 양파를 넣고 볶은 후 케첩을 넣어 고루 섞이도록 볶아 줍니다. 우스터 소스, 적포도주, 육수를 넣은 후 이분의 일로 될때까지 졸입니다. 다음단계로 진행할까요?");
			break;
		case 7:
			return _T("우유를 조금씩 넣어 가며 섞어준 후 소금, 후추로 간하여 웨지감자 체에 걸러 햄버그 스테이크에 곁들여 냅니다. 다음단계로 진행할까요?");
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
			return _T("상온 버터와 다진 마늘, 다진 파슬리를 섞어 식빵의 한 면에 바릅니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return _T("법량접시에 유산지를 깔고 식빵을 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("베이글을 반으로 자릅니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return _T("베이글의 안쪽 면이 위로 오게하여 구이전용 팬에 겹치지 않게 올리세요. 준비되시면 다음이라고 말씀해 주세요.");
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
			return _T("구이전용 팬에 식빵을 겹치지 않게 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
			break;
		case 2:
			return _T("도중에 멜로디가 울리면 한번 뒤집어 준다. 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("토핑은 다음과 같이 만듭니다. 양파,청,홍피망,양송이는 적당한 크기로 썰어서 내열용기에 담고 랩을 씌워 수동요리레인지 기능으로 2~3분 가열한 후 물기를 없앱니다. 이를 위한 알람 셋팅을 하시겠습니까?");
			break;
		case 2:
			return _T("베이컨, 햄은 적당한 크기로 자릅니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("모짜렐라 치즈는 잘게 다지고 올리브는 모양대로 얇게 썰어 둡니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return _T("상온 버터를 식빵의 한 면에 바른 후, 피자소스를 바릅니다. 다음단계로 진행할까요?");
			break;
		case 5:
			return _T("햄, 베이컨, 양송이, 양파, 피망 순으로 토핑합니다. 다음단계로 진행할까요?");
			break;
		case 6:
			return _T("모짜렐라 치즈를 고루 뿌린 뒤 올리브로 장식합니다. 다음단계로 진행할까요?");
			break;
		case 7:
			return _T("법량접시에 유산지를 깔고 식빵을 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
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
			return _T("통 식빵을 반으로 자릅니다. 다음단계로 진행할까요?");
			break;
		case 2:
			return _T("식빵의 한쪽 면이 위로 오게 하여 밑바닥에 구멍이 나지 않게 엑스자 칼집을 넣어줍니다. 다음단계로 진행할까요?");
			break;
		case 3:
			return _T("칼집을 낸 부분에 꿀을 넣고 식빵 뒷면에 버터를 바릅니다. 다음단계로 진행할까요?");
			break;
		case 4:
			return _T("법량접시에 유산지를 깔고 식빵을 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요.");
			break;
		default:
			return TEXT("end");
			break;
		}
	}

}