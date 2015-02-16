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

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
		print_act=Find_Material(TEXT("korean"))+TEXT("으로 만들수 있는 요리는 ")+Find_menu()+TEXT("가 있습니다");
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
		SetDlgItemTextW(IDC_EDIT3,TEXT("프로그램을 종료합니다."));
	}
	
	else if(act=="restart")
	{
		now_act.~Stack();
		now_act.push(TEXT("start"));
		SetDlgItemTextW(IDC_EDIT4,TEXT("start"));
		SetDlgItemTextW(IDC_EDIT3,TEXT("LG Dios 광파오븐 제어기 입니다. 무엇을 도와드릴까요?"));
	}
	else if(act=="goback")
	{
		print_act=TEXT("이전으로 이동합니다. ");

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
		else
		{
			print_act=TEXT("죄송합니다. 잘 모르겠습니다. 이후 단계를 진행하시겠습니까?");
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
			print_act=TEXT("잘못된 입력입니다. 다시 한번 말씀해 주십시오.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
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
		if(now_act.top()=="start")
		{
			print_act=TEXT("잘못된 입력입니다. 다시 한번 말씀해 주십시오.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
	else if(act=="movie_start")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("잘못된 입력입니다. 다시 한번 말씀해 주십시오.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
	else if(act=="heat_start")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("잘못된 입력입니다. 다시 한번 말씀해 주십시오.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
	}
	else if(act=="next")
	{
		if(now_act.top()=="start")
		{
			print_act=TEXT("잘못된 입력입니다. 다시 한번 말씀해 주십시오.");
			SetDlgItemTextW(IDC_EDIT4,TEXT("please_repeat"));
			SetDlgItemTextW(IDC_EDIT3,print_act);
		}
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
