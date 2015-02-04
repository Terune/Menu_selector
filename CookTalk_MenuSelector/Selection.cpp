// Selection.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "Selection.h"
#include "afxdialogex.h"


// CSelection 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSelection, CDialogEx)

CSelection::CSelection(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelection::IDD, pParent)
{
	
}

BOOL CSelection::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CTab3 *pDlg = (CTab3*)AfxGetMainWnd();
	//CString temp;
	//temp=pDlg->ComboName;

	if(Sel_name=="Type")
	{
		m_SelectList.InsertItem(0,TEXT("오븐"));
		m_SelectList.InsertItem(0,TEXT("토스트"));
	}
	else if(Sel_name=="Con")
	{
		m_SelectList.InsertItem(0,TEXT("법량접시"));
		m_SelectList.InsertItem(0,TEXT("석쇠"));
		m_SelectList.InsertItem(0,TEXT("구이전용 팬"));
	}
	else if(Sel_name=="Material")
	{
		m_SelectList.InsertItem(0,TEXT("가지"));
		m_SelectList.InsertItem(0,TEXT("감자"));
		m_SelectList.InsertItem(0,TEXT("계피가루"));
		m_SelectList.InsertItem(0,TEXT("고구마"));
		m_SelectList.InsertItem(0,TEXT("꿀"));
		m_SelectList.InsertItem(0,TEXT("냉동피자"));
		m_SelectList.InsertItem(0,TEXT("다진 돼지고기"));
		m_SelectList.InsertItem(0,TEXT("다진 마늘"));
		m_SelectList.InsertItem(0,TEXT("다진 쇠고기"));
		m_SelectList.InsertItem(0,TEXT("다진 실파"));
		m_SelectList.InsertItem(0,TEXT("달걀"));
		m_SelectList.InsertItem(0,TEXT("닭다리"));
		m_SelectList.InsertItem(0,TEXT("대추"));
		m_SelectList.InsertItem(0,TEXT("돼지고기 립"));
		m_SelectList.InsertItem(0,TEXT("또띠아"));
		m_SelectList.InsertItem(0,TEXT("멥쌀"));
		m_SelectList.InsertItem(0,TEXT("모짜렐라 치즈"));
		m_SelectList.InsertItem(0,TEXT("바닐라오일"));
		m_SelectList.InsertItem(0,TEXT("박력분"));
		m_SelectList.InsertItem(0,TEXT("밤"));
		m_SelectList.InsertItem(0,TEXT("버터"));
		m_SelectList.InsertItem(0,TEXT("베이글"));
		m_SelectList.InsertItem(0,TEXT("베이컨"));
		m_SelectList.InsertItem(0,TEXT("베이킹 소다"));
		m_SelectList.InsertItem(0,TEXT("베이킹 파우더"));
		m_SelectList.InsertItem(0,TEXT("블랙 올리브"));
		m_SelectList.InsertItem(0,TEXT("생닭"));
		m_SelectList.InsertItem(0,TEXT("생크림"));
		m_SelectList.InsertItem(0,TEXT("스파게티면"));
		m_SelectList.InsertItem(0,TEXT("식빵"));
		m_SelectList.InsertItem(0,TEXT("식은밥"));
		m_SelectList.InsertItem(0,TEXT("양송이"));
		m_SelectList.InsertItem(0,TEXT("양파"));
		m_SelectList.InsertItem(0,TEXT("오레가노"));
		m_SelectList.InsertItem(0,TEXT("올리고당"));
		m_SelectList.InsertItem(0,TEXT("우스터 소스"));
		m_SelectList.InsertItem(0,TEXT("월계수잎"));
		m_SelectList.InsertItem(0,TEXT("육수"));
		m_SelectList.InsertItem(0,TEXT("은행"));
		m_SelectList.InsertItem(0,TEXT("잣"));
		m_SelectList.InsertItem(0,TEXT("적포도주"));
		m_SelectList.InsertItem(0,TEXT("중력분"));
		m_SelectList.InsertItem(0,TEXT("찹쌀"));
		m_SelectList.InsertItem(0,TEXT("청피망"));
		m_SelectList.InsertItem(0,TEXT("초코칩"));
		m_SelectList.InsertItem(0,TEXT("콩"));
		m_SelectList.InsertItem(0,TEXT("크림치즈"));
		m_SelectList.InsertItem(0,TEXT("토마토 페이스트"));
		m_SelectList.InsertItem(0,TEXT("통삽겹살"));
		m_SelectList.InsertItem(0,TEXT("파마산 치즈"));
		m_SelectList.InsertItem(0,TEXT("파슬리 가루"));
		m_SelectList.InsertItem(0,TEXT("피자 빵가루"));
		m_SelectList.InsertItem(0,TEXT("피자소스"));
		m_SelectList.InsertItem(0,TEXT("햄"));
		m_SelectList.InsertItem(0,TEXT("홍피망"));
	}
	else if(Sel_name=="Menu")
	{
		m_SelectList.InsertItem(0,TEXT("감자그라탱"));
		m_SelectList.InsertItem(0,TEXT("군고구마"));
		m_SelectList.InsertItem(0,TEXT("냉동피자"));
		m_SelectList.InsertItem(0,TEXT("누룽지"));
		m_SelectList.InsertItem(0,TEXT("닭다리"));
		m_SelectList.InsertItem(0,TEXT("또띠아 피자"));
		m_SelectList.InsertItem(0,TEXT("롤케이크"));
		m_SelectList.InsertItem(0,TEXT("립 바비큐"));
		m_SelectList.InsertItem(0,TEXT("마늘빵"));
		m_SelectList.InsertItem(0,TEXT("베이글"));
		m_SelectList.InsertItem(0,TEXT("스콘"));
		m_SelectList.InsertItem(0,TEXT("스폰지 케이크"));
		m_SelectList.InsertItem(0,TEXT("식빵"));
		m_SelectList.InsertItem(0,TEXT("약식"));
		m_SelectList.InsertItem(0,TEXT("영양밥"));
		m_SelectList.InsertItem(0,TEXT("오븐 스파게티"));
		m_SelectList.InsertItem(0,TEXT("초코칩 쿠키"));
		m_SelectList.InsertItem(0,TEXT("치즈 케이크"));
		m_SelectList.InsertItem(0,TEXT("통감자"));
		m_SelectList.InsertItem(0,TEXT("통닭"));
		m_SelectList.InsertItem(0,TEXT("통삼겹살"));
		m_SelectList.InsertItem(0,TEXT("피자"));
		m_SelectList.InsertItem(0,TEXT("피자토스트"));
		m_SelectList.InsertItem(0,TEXT("햄버그 스테이크"));
		m_SelectList.InsertItem(0,TEXT("허니브레드"));
	}
	
	return true;
}

CSelection::~CSelection()
{
}

void CSelection::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_SelectList);
}

void CSelection::SetUserData(CString Select_name, int Select_Tema)
{
	// 부모 대화상자에서 전달한 데이터를 멤버 변수에 저장한다.
	Sel_name = Select_name;
	Sel_value = Select_Tema;
}
void CSelection::GetUserData(CString &parm_name)
{
	// 현재 멤버 변수가 가지고 있는 값을 매개변수에 복사해준다.
	// 이 함수는 ModifyDlg를 생성한 부모 대화상자에서 호출할것이며
	// DoModal이 끝난후에 사용할 것이다.
	parm_name = List_Select;
	//parm_age = Sel_value;
}
BEGIN_MESSAGE_MAP(CSelection, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSelection::OnBnClickedOk)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CSelection::OnNMClickList1)
END_MESSAGE_MAP()


// CSelection 메시지 처리기입니다.


void CSelection::OnBnClickedOk()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CSelection::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	int index;

	NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;
	//index = pNMView->iItem;
	index = pNMItemActivate->iItem;
	if(index >= 0 && index < m_SelectList.GetItemCount())
	{
		//여기서 index값으로 받아오면 됩니다.
		List_Select = m_SelectList.GetItemText(index,0);
	}
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

CString CSelection::Matching_name(CString input)
{
	if(input=="오븐")
		return TEXT("oven");
	else if(input=="토스트")
		return TEXT("toast");
	else if(input=="법량접시")
		return TEXT("plate");
	else if(input=="석쇠")
		return TEXT("grate");
	else if(input=="구이전용 팬")
		return TEXT("pan");
	else if(input=="가지")
		return TEXT("eggplant");
	else if(input=="감자")
		return TEXT("potato");
	else if(input=="계피가루")
	return TEXT("cinnamon_powder");
	else if(input=="고구마")
		return TEXT("sweet_potato");
	else if(input=="꿀")
		return TEXT("honey");
	else if(input=="냉동피자")
		return TEXT("pizza");
	else if(input=="다진 돼지고기")
		return TEXT("pork");
	else if(input=="다진 마늘")
		return TEXT("crushed_galic");
	else if(input=="다진 쇠고기")
		return TEXT("beef");
	else if(input=="다진 실파")
		return TEXT("small_green_onion");
	else if(input=="달걀")
		return TEXT("egg");
	else if(input=="닭다리")
		return TEXT("drumstick");
	else if(input=="대추")
		return TEXT("jujube");
	else if(input=="돼지고기 립")
		return TEXT("pork");
	else if(input=="또띠아")
		return TEXT("Tortilla");
	else if(input=="멥쌀")
		return TEXT("nonglutinous_rice");
	else if(input=="모짜렐라 치즈")
		return TEXT("cheese");
	else if(input=="바닐라오일")
		return TEXT("vanilla_oil");
	else if(input=="박력분")
		return TEXT("soft_flour");
	else if(input=="밤")
		return TEXT("chestnut");
	else if(input=="버터")
		return TEXT("butter");
	else if(input=="베이글")
		return TEXT("bagle");
	else if(input=="베이컨")
		return TEXT("bacon");
	else if(input=="베이킹 소다")
		return TEXT("baking_soda");
	else if(input=="베이킹 파우더")
		return TEXT("baking_powder");
	else if(input=="블랙 올리브")
		return TEXT("black_olive");
	else if(input=="생닭")
		return TEXT("chicken");
	else if(input=="생크림")
		return TEXT("cream");
	else if(input=="스파게티면")
		return TEXT("spaghetti");
	else if(input=="식빵")
		return TEXT("bread");
	else if(input=="식은밥")
		return TEXT("rice");
	else if(input=="양송이")
		return TEXT("button_mushroom");
	else if(input=="양파")
		return TEXT("onion");
	else if(input=="오레가노")
		return TEXT("oregano");
	else if(input=="올리고당")
		return TEXT("oligosaccharides");
	else if(input=="우스터 소스")
		return TEXT("worcester_sauce");
	else if(input=="월계수잎")
		return TEXT("bay_leaf");
	else if(input=="육수")
		return TEXT("meat_broth");
	else if(input=="은행")
		return TEXT("ginkgo_nut");
	else if(input=="잣")
		return TEXT("pine_nut");
	else if(input=="적포도주")
		return TEXT("red_wine");
	else if(input=="중력분")
		return TEXT("medium_flour");
	else if(input=="찹쌀")
		return TEXT("sticky_rice");
	else if(input=="청피망")
		return TEXT("squid");
	else if(input=="초코칩")
		return TEXT("chocochip");
	else if(input=="콩")
		return TEXT("bean");
	else if(input=="크림치즈")
		return TEXT("cream_cheese");
	else if(input=="토마토 페이스트")
		return TEXT("tomato_paste");
	else if(input=="통삽겹살")
		return TEXT("pork_belly");
	else if(input=="파마산 치즈")
		return TEXT("parmesan");
	else if(input=="파슬리 가루")
		return TEXT("parsley");
	else if(input=="피자 빵가루")
		return TEXT("bread_crumbs");
	else if(input=="피자소스")
		return TEXT("pizza_source");
	else if(input=="햄")
		return TEXT("ham");
	else if(input=="홍피망")
		return TEXT("red_peppers");
	else if(input=="감자그라탱")
	return TEXT("	gratin	");
	else if(input=="군고구마")
return TEXT("	roasted_sweet_potato	");
	else if(input=="냉동피자")
return TEXT("	frozen_pizza	");
	else if(input=="누룽지")
return TEXT("	nurungji	");
	else if(input=="닭다리")
		return TEXT("	drumstick	");

	else if(input=="또띠아 피자")
		return TEXT("	Tortilla	");
return TEXT("	roll_cake	");
return TEXT("	barbeque	");
return TEXT("	garlic_bread	");
return TEXT("	bagle	");
return TEXT("	scorn	");
return TEXT("	sponge_cake	");
return TEXT("	bread	");
return TEXT("	sweet_rice	");
return TEXT("	deluxe_rice	");
return TEXT("	spaghetti	");
return TEXT("	chocochip	");
return TEXT("	cheese_cake	");
return TEXT("	potato	");
return TEXT("	chicken	");
return TEXT("	pork_belly	");
return TEXT("	pizza	");
return TEXT("	pizza_toast	");
return TEXT("	hamburger	");
return TEXT("	honey_bread	");

	else if(input=="롤케이크");
	else if(input=="립 바비큐");
	else if(input=="마늘빵");
	else if(input=="베이글");
	else if(input=="스콘");
	else if(input=="스폰지 케이크");
	else if(input=="식빵");
	else if(input=="약식");
	else if(input=="영양밥");
	else if(input=="오븐 스파게티");
	else if(input=="초코칩 쿠키");
	else if(input=="치즈 케이크");
	else if(input=="통감자");
	else if(input=="통닭");
	else if(input=="통삼겹살");
	else if(input=="피자");
	else if(input=="피자토스트");
	else if(input=="햄버그 스테이크");
	else if(input=="허니브레드");
}
