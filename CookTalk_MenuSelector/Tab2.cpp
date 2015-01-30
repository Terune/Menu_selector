// Tab2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "Tab2.h"
#include "afxdialogex.h"


// CTab2 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTab2, CDialogEx)
int index;
BOOL __ClipCopy2(char *txt);
int index2;
int indexsub;
CTab2::CTab2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTab2::IDD, pParent)
{


}

CTab2::~CTab2()
{
}

BOOL CTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	m_ManuList.InsertColumn(0,_T("요리이름"),LVCFMT_LEFT, 140, -1);
	m_ManuList.InsertItem(0,TEXT("감자그라탱"));
	m_ManuList.InsertItem(0,TEXT("군고구마"));
	m_ManuList.InsertItem(0,TEXT("냉동피자"));
	m_ManuList.InsertItem(0,TEXT("누룽지"));
	m_ManuList.InsertItem(0,TEXT("닭다리"));
	m_ManuList.InsertItem(0,TEXT("또띠아 피자"));
	m_ManuList.InsertItem(0,TEXT("롤케이크"));
	m_ManuList.InsertItem(0,TEXT("립 바비큐"));
	m_ManuList.InsertItem(0,TEXT("마늘빵"));
	m_ManuList.InsertItem(0,TEXT("베이글"));
	m_ManuList.InsertItem(0,TEXT("스콘"));
	m_ManuList.InsertItem(0,TEXT("스폰지 케이크"));
	m_ManuList.InsertItem(0,TEXT("식빵"));
	m_ManuList.InsertItem(0,TEXT("약식"));
	m_ManuList.InsertItem(0,TEXT("영양밥"));
	m_ManuList.InsertItem(0,TEXT("오븐 스파게티"));
	m_ManuList.InsertItem(0,TEXT("초코칩 쿠키"));
	m_ManuList.InsertItem(0,TEXT("치즈 케이크"));
	m_ManuList.InsertItem(0,TEXT("통감자"));
	m_ManuList.InsertItem(0,TEXT("통닭"));
	m_ManuList.InsertItem(0,TEXT("통삼겹살"));
	m_ManuList.InsertItem(0,TEXT("피자"));
	m_ManuList.InsertItem(0,TEXT("피자토스트"));
	m_ManuList.InsertItem(0,TEXT("햄버그 스테이크"));
	m_ManuList.InsertItem(0,TEXT("허니브레드"));

	m_MaterialList.InsertColumn(0,_T("재료이름"),LVCFMT_LEFT, 100, -1);
	m_MaterialList.InsertColumn(1,_T("양"),LVCFMT_LEFT,270, -1);

	m_RecipeList.InsertColumn(0,_T("레시피"),LVCFMT_LEFT, 370, -1);
//	m_RecipeList.InsertColumn(1,_T("내용"),LVCFMT_LEFT,320, -1);
	return TRUE;
}
void CTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ManuList);
	DDX_Control(pDX, IDC_LIST2, m_MaterialList);
	DDX_Control(pDX, IDC_LIST3, m_RecipeList);
}


BEGIN_MESSAGE_MAP(CTab2, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CTab2::OnNMClickList1)
//	ON_NOTIFY(NM_DBLCLK, IDC_LIST3, &CTab2::OnNMDblclkList3)
//	ON_NOTIFY(HDN_ITEMDBLCLICK, 0, &CTab2::OnHdnItemdblclickList3)
ON_NOTIFY(NM_DBLCLK, IDC_LIST3, &CTab2::OnNMDblclkList3)
//ON_NOTIFY(NM_CLICK, IDC_LIST3, &CTab2::OnNMClickList3)
ON_NOTIFY(NM_CLICK, IDC_LIST3, &CTab2::OnNMClickList3)
ON_BN_CLICKED(IDC_BUTTON1, &CTab2::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTab2 메시지 처리기입니다.


void CTab2::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	m_MaterialList.DeleteAllItems();
	m_RecipeList.DeleteAllItems();
	NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;
	index = pNMView->iItem;

	switch(index)
	{
	case 0:
		m_MaterialList.InsertItem(0,TEXT("감자"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("베이컨"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("2장"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("양파"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1/4개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("모짜렐라 치즈"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("감자는 삶아 으깨어서 준비합니다. 다음단계로 진행할까요?"));
		//m_RecipeList.SetItem(0, 1, LVIF_TEXT, _T("감자는 삶아 으깨어서 준비합니다."), 0, 0, 0, NULL );
		m_RecipeList.InsertItem(1,TEXT("베이컨, 양파를 채썰어 버터에 볶아둡니다. 채썰기 영상을 보시겠습니까?"));
		//m_RecipeList.SetItem(1, 1, LVIF_TEXT, _T("베이컨, 양파를 채썰어 버터에 볶아둡니다. 채썰기 영상을 보시겠습니까?"), 0, 0, 0, NULL );
		m_RecipeList.InsertItem(2,TEXT("팬에 밀가루, 버터를 넣어 볶은 후 우유를 조금씩 넣어 가며 밀가루 멍울을 풀고 소금, 후추로 간하여 소스를 만듭니다. 이때 간을 약간 세게 하고 소스는 약간 묽게 합니다. 다음단계로 진행할까요?"));
		//m_RecipeList.SetItem(2, 1, LVIF_TEXT, _T("팬에 밀가루, 버터를 넣어 볶은 후 우유를 조금씩 넣어 가며 밀가루 멍울을 풀고 소금, 후추로 간하여 소스를 만듭니다. 이때 간을 약간 세게 하고 소스는 약간 묽게 합니다."), 0, 0, 0, NULL );
		m_RecipeList.InsertItem(3,TEXT("화이트소스 이분의 삼 분량에 볶은 재료와 감자를 넣어 섞습니다. 다음단계로 진행할까요?"));

		m_RecipeList.InsertItem(4,TEXT("그라탱접시, 지름 23센티 정도의 내열접시에 소스를 버무린 재료를 담고 남은 소스를 끼얹은 후 다진 치즈, 빵가루, 파슬리 순으로 올립니다. 다음단계로 진행할까요?"));
		
		m_RecipeList.InsertItem(5,TEXT("법랑접시에 석쇠를 놓고 그라탱 접시를 올린 후 2단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		
		break;
	case 1:
		m_MaterialList.InsertItem(0,TEXT("고구마"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.4~ 1.2kg"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("고구마는 너무 크지 않는 것으로 골라 깨끗이 씻은 후 물기를 닦아 껍질을 포크로 몇차례 찔러 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("1단에 법랑접시 위에 석쇠를 놓고 고구마를 가지런히 올려주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 2:
		m_MaterialList.InsertItem(0,TEXT("냉동피자"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.2~ 0.6kg"), 0, 0, 0, NULL );
		
		m_RecipeList.InsertItem(0,TEXT("법랑접시를 석쇠에 놓고 포장을 제거한 냉동피자를 올린 후 3단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 3:
		m_MaterialList.InsertItem(0,TEXT("식은밥"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.2kg"), 0, 0, 0, NULL );
		
		m_RecipeList.InsertItem(0,TEXT("상온에 보관된 식은 밥 이백그람을 구이전용 팬 위에 얇게 전체로 펴 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("자동요리오븐에서 누룽지를 선택한 후 4단에 올려주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 4:
		m_MaterialList.InsertItem(0,TEXT("닭다리"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.3~1.0kg"), 0, 0, 0, NULL );
		
		m_RecipeList.InsertItem(0,TEXT("닭다리에 칼집을 넣어준 후 소금, 후추, 청주에 약 삼십분 정도 재웁니다. 이를 위한 알람 셋팅을 하시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("닭다리에 올리브유를 바른 후 구이전용 팬 위에 가지런히 놓고, 4단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		m_RecipeList.InsertItem(2,TEXT("도중에 멜로디가 울리면 한번 뒤집어줍니다. 다음단계로 진행할까요?"));
		break;
	case 5:
		m_MaterialList.InsertItem(0,TEXT("또띠아"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2장"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("피자소스"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("베이컨"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1장"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("햄"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("양송이"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("1개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(5,TEXT("청피망"));
		m_MaterialList.SetItem(5, 1, LVIF_TEXT, _T("1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(6,TEXT("홍피망"));
		m_MaterialList.SetItem(6, 1, LVIF_TEXT, _T("1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(7,TEXT("양파"));
		m_MaterialList.SetItem(7, 1, LVIF_TEXT, _T("1/4개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(8,TEXT("블랙 올리브"));
		m_MaterialList.SetItem(8, 1, LVIF_TEXT, _T("3개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(9,TEXT("모짜렐라 치즈"));
		m_MaterialList.SetItem(9, 1, LVIF_TEXT, _T("70g"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("토핑을 다음과 같이 준비합니다. 먼저 양파, 청, 홍피망, 양송이는 적당한 크기롤 썰어서 내열용기에 담고 랩을 씌워 수동요리레인지 기능으로 2~3분 가열한 후 물기를 없앱니다.  알람설정을 하시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("베이컨, 햄은 적당한 크기로 자릅니다. 모짜렐라 치즈는 잘게 다지고, 올리브는 모양대로 얇게 썰어줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("또띠아 2장을 겹쳐 구이전용 팬에 올립니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("가운데 부분에 피자소스를 고루 펴 바르고 햄, 베이컨, 양송이, 양파, 피망 순으로 토핑합니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("모짜렐라 치즈를 고루 뿌린 뒤 올리브로 장식하여 4단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 6:
		m_MaterialList.InsertItem(0,TEXT("박력분"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("130g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("달걀"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("6개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("바닐라오일"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T( "1/4 작은술"), 0, 0, 0, NULL );
	
		m_RecipeList.InsertItem(0,TEXT("박력분은 체쳐 둡니다. 체치기 영상을 보시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("설탕은 적당히 반으로 나눕니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("볼을 2개 준비하여 한쪽은 흰자, 다른 한 쪽은 노른자를 분리해 놓고 노른자 1개는 따로 빼둡니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("노른자를 풀어 소금, 설탕, 물엿, 우유를 함께 넣고 아이보리색이 되도록 거품을 냅니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("흰자는 어느 정도 거품을 올린 후 설탕을 조금씩 나누어 넣으며 거품을 빳빳하게 내줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(5,TEXT("노른자에 흰자를 삼분의 일정도 넣고 가볍게 섞다가 체에 친 밀가루를 넣어 주걱으로 가볍고 빠르게 섞어줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(6,TEXT("식용유를 넣어 고루 섞은 다음 나머지 흰자 거품을 넣어 거품이 가라앉지 않도록 재빨리 섞어 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(7,TEXT("법랑접시에 유산지를 깔고 반죽을 평평하게 부어줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(8,TEXT("노른자 1개에 소금을 약간 넣어 잘 풀어 비닐봉지에 담고 구멍을 작게 뚫어 반죽 위에 흘리면서 지그재그로 무늬를 만들어 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(9,TEXT("무늬 반대편을 젓가락으로 다시 지그재그로 휘저어 물결 무늬를 만듭니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(10,TEXT("오븐 2단에 재료를 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		m_RecipeList.InsertItem(11,TEXT("젖은 면보를 준비하여 바닥에 깔고 구워낸 케이크를 바닥이 위로 오도록 엎어 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(12,TEXT("케이크 위에 잼을 고루 바른 뒤 면보 아래로 방망이를 대고 케이크를 밀어 가며 말아줍니다. 다음단계로 진행할까요?"));
		break;
	case 7:
		m_MaterialList.InsertItem(0,TEXT("돼지고기 립"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("1.0kg"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("립은 통으로 준비하여 기름을 떼네고 찬물에 2시간정도 담가 핏물을 뺍니다. 이를 위한 알람셋팅을 하시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("물기를 제거하고 레몬 즙, 소금, 후추로 밑간을 합니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("법랑접시 위에 석쇠를 놓고 립을 올려주세요. 준비되시면 다음이라고 말씀해주세요."));
		m_RecipeList.InsertItem(3,TEXT("분량대로 섞어 소스를 만듭니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("도중에 멜로디가 울리면 소스를 붓으로 고루 바른 후 남은 시간 동안 더 구워줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(5,TEXT("립을 접시에 담고 소스를 한번 더 끼얹어 냅니다. 다음단계로 진행할까요?"));
		break;

	case 8:
		m_MaterialList.InsertItem(0,TEXT("식빵"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2~4장"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("다진 마늘"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("2큰술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("다진 파슬리"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("2큰술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("버터"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("4큰술"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("상온 버터와 다진 마늘, 다진 파슬리를 섞어 식빵의 한 면에 바릅니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("법량접시에 유산지를 깔고 식빵을 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;

	case 9:
		m_MaterialList.InsertItem(0,TEXT("베이글"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("1~3개"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("베이글을 반으로 자릅니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("베이글의 안쪽 면이 위로 오게하여 구이전용 팬에 겹치지 않게 올리세요. 준비되시면 다음이라고 말씀해 주세요."));
		break;

	case 10:
		m_MaterialList.InsertItem(0,TEXT("중력분"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("300g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("베이킹파우더"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1작은술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("달걀"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("2개"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("중력분, 베이킹 파우더는 체치고 설탕, 소금, 냉장 보관한 버터를 넣고 자르듯이 섞습니다. 버터와 밀가루가 고루 섞여 부슬부슬한 상태가 되도록 만듭니다. 이에 관한 체치기 동영상을 보시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("미리 섞은 달걀과 우유를 1에 넣고 자르듯 고루 섞습니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("마른 가루가 보이지 않고, 반죽이 하나로 뭉쳐지면 랩을 덮어 냉장고에서 30분정도 숙성 시킵니다. 이를 위한 알림셋팅을 하시겠습니까?"));
		m_RecipeList.InsertItem(3,TEXT("반죽을 약 2.5센치 두께가 되도록 밀대로 민 다음 같은 크기로 자릅니다. 이때 덧가루를 사용해야 밀어 펴기가 편리합니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("법랑 접시에 유산지를 깔고 스콘을 올린 후 표면에 달걀물을 칠합니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(5,TEXT("2단에 해당 법랑접시를 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;

	case 11:
		m_MaterialList.InsertItem(0,TEXT("박력분"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("바닐라 오일"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("한방울"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT(" 달걀"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("4개"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("박력분은 체쳐 둡니다. 체치기 영상을 보시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("케이크 틀 바닥과 옆면에 종이를 깔아 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("버터를 우유에 함께 녹여 준 후 바닐라 오일을 한 방울 섞어 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("달걀을 따뜻한 물에서 중탕한 후 볼에 넣고 풀어줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("달걀과 설탕을 한꺼번에 넣고 거품기를 들어보아 끝이 뾰족하고 살짝 숙여질 때까지 거품을 냅니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(5,TEXT("거품낸 달걀에 박력분을 넣고 골고루 섞어 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(6,TEXT("위 반죽의 일부를 버터 녹인 우유에 넣어 섞은 후 다시 반죽에 넣어 재빨리 섞어 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(7,TEXT("반죽을 틀에 붓고 틀을 한번 들었다가 바닥에 놓아 반죽 속의 기포를 고르게 해 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(8,TEXT("법랑접시 위에 석쇠를 놓고 케이크 틀을 올린 후 1단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 12:
		m_MaterialList.InsertItem(0,TEXT("식빵"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2~4개"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("구이전용 팬에 식빵을 겹치지 않게 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		m_RecipeList.InsertItem(1,TEXT("도중에 멜로디가 울리면 한번 뒤집어 준다."));
		break;
	case 13:
		m_MaterialList.InsertItem(0,TEXT("찹쌀"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2컵(340g)"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("계피가루"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1/2작은술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("밤"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("5개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("대추"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("10개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("잣"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("1큰술"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("찹쌀을 한 시간 이상 물에 불려 체에 건져 둡니다. 이를 위한 알람 셋팅을 하시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("밤은 껍질을 벗겨 4등분하고, 대추는 씨를 빼내어 2등분하고, 잣은 고깔을 떼어냅니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("법랑 접시에 석쇠를 놓고 2리터 정도 크기의 내열 용기를 올린 후 뚜껑 또는 알루미늄 호일로 덮어 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		m_RecipeList.InsertItem(3,TEXT("가열이 끝나면 오븐에 약 10분 정도 그대로 두어 뜸 들인 후 꺼내어 참기름을 넣고 고루 섞어 줍니다. 이를 위한 알람 셋팅을 하시겠습니까?"));
		m_RecipeList.InsertItem(4,TEXT("잣이 완전히 익을 때까지 가열합니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(5,TEXT("오븐에서 꺼낸 다음 잘 식힙니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(6,TEXT("약간 따뜻한 밥을 공모양으로 만든 다음 접시에 내놓습니다. 다음단계로 진행할까요?"));
		break;

	case 14:
		m_MaterialList.InsertItem(0,TEXT("멥쌀"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("1컵"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("찹쌀"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1컵"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("밤"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("5개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("대추"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("3개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("잣"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("1큰술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(5,TEXT("콩"));
		m_MaterialList.SetItem(5, 1, LVIF_TEXT, _T("4큰술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(6,TEXT("은행"));
		m_MaterialList.SetItem(6, 1, LVIF_TEXT, _T("6알"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("멥쌀, 찹쌀은 씻어서 3시간 이상 불려 놓습니다. 이를 위한 알람 셋팅을 하시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("밤은 껍질을 벗겨 2등분하고, 잣은 고깔을 떼어 놓습니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("대추는 씨를 빼고 2등분하고, 콩은 6시간 이상 불려서 준비합니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("내열용기에 불린 쌀, 콩, 밤, 은행, 대추, 잣, 소금을 넣고 물을 붓습니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("법랑접시에 석쇠를 놓고 2리터정도 크기의 내열용기를 올린 후 뚜껑 또는 알루미늄 호일로 덮어 1단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		m_RecipeList.InsertItem(5,TEXT("가열이 끝나면 오븐에 약 10분 정도 그대로 두어 뜸을 들입니다. 이를 위한 알람셋팅을 하시겠습니까?"));
		break;
	case 15:
		m_MaterialList.InsertItem(0,TEXT("스파게티면"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("가지"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("모짜렐라 치즈"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("40g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("다진 실파"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("1큰술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("파마산 치즈"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("약간"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("끓는 소금물에 스파게티면을 넣고 삶아 물기 없이 건집니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("가지는 0.5센티 두께로 둥글게 썰어 소금, 후추, 올리브유를 약간씩 넣고 버무립니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("팬에 가지를 살짝 볶아 접시에 옮겨 놓고, 올리브유를 팬에 살짝 두르고 다진 마늘과 양파를 넣어 볶아 준 후 갈은 쇠고기, 소금, 후추를 넣고 볶아 양송이, 당근, 샐러리 다진 것을 넣어 익힙니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("3에 토마토 페이스트와 케첩을 넣고 껍질과 씨를 제거한 토마토를 넣어 준 후 설탕, 핫소스, 월계수 잎, 물을 넣어 끓이면서 소금, 후추로 간을 하고 마지막에 볶아 놓은 가지와 오레가노를 넣어 걸쭉한 상태로 만듭니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("삶아 놓은 스파게티면을 4에 넣고 버무려 내열접시에 담고 다진 모짜렐라 치즈와 파마산 치즈를 얹어 송송 썬 실파를 뿌립니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(5,TEXT("법랑접시에 석쇠를 놓고 내열접시를 올려주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 16:
		m_MaterialList.InsertItem(0,TEXT("박력분"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("180g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("베이킹파우더"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1/2 작은술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("베이킹 소다"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1/4 작은술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("달걀"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("1개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("초코칩"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("박력분, 베이킹파우더, 베이킹 소다는 체쳐 둡니다. 체치기 영상을 보시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("실온에 둔 버터를 잘 풀어 크림 상태를 만듭니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("설탕을 넣고 녹을 때까지 잘 섞어줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("달걀을 풀어 조금씩 나누어 넣으며 버터와 분리되지 않도록 재빨리 섞어줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("체친 가루와 초코칩을 넣어 반죽한 후 기름 바른 법랑접시와 구이전용 팬에 적당한 간격을 두고 반 수저씩 놓은 다음 포크로 가볍게 눌러 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(5,TEXT("법랑접시는 1단에, 구이전용 팬은 4단에 각각 넣습니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(6,TEXT("법랑접시와 구이전용 팬을 넣고 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 17:
		m_MaterialList.InsertItem(0,TEXT("크림치즈"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("400g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("달걀"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("2 1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("박력분"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1/2컵"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("생크림"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("2 1/2큰술"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("크림치즈를 상온에 두어 부드러운 상태가 되도록 한 뒤 거품기를 이용하여 잘 풀어줍니다. 달걀도 미리 풀어둡니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("1의 크림치즈에 설탕과 달걀을 조금씩 나누어 넣어가며 거품기로 섞습니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("부드럽게 풀린 반죽에 박력분과 생크림을 넣고 주걱으로 고루 섞습니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("케이크 틀에 유산지를 깔고 바닥에 카스텔라 시트를 놓은 다음 3의 반죽을 붓습니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("법랑접시에 석쇠를 놓고 케이크틀을 올린 후 1단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 18:
		m_MaterialList.InsertItem(0,TEXT("감자"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.4~1.2kg"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("감자를 모양이 둥글고 적당한 크기로 골라 깨끗이 씻은 후 물기를 닦아, 껍질을 포크로 몇차례 찔러 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("법랑접시 위에 석쇠를 놓고 감자를 가지런히 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 19:
		m_MaterialList.InsertItem(0,TEXT("생닭"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.8~1.2kg"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("닭을 씻어서 물기를 닦고 꽁지와 날개 끝을 잘라 내고 닭 껍질에 칼집을 내어 소금, 후추, 청주에 약 30분 정도 재워줍니다. 이를 위한 알람 셋팅을 하시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("닭 껍질에 올리브유를 바릅니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("법량접시에 석쇠를 놓고 닭의 가슴부분이 아래로 가도록 하여 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		m_RecipeList.InsertItem(3,TEXT("도중에 멜로디가 울리면 한번 뒤집어줍니다. 다음단계로 진행할까요?"));
		break;
	case 20:
		m_MaterialList.InsertItem(0,TEXT("통삼겹살"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("1.0~1.5kg"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("삼겹살은 통째로 구입하여 2~3개의 덩어리로 자른 후 칼집을 내고 소금, 후추, 올리브유를 적당량 뿌립니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("법랑접시 위에 석쇠를 놓고 통삼겹살의 껍질부분이 아래로 가도록 하여 1단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 21:
		m_MaterialList.InsertItem(0,TEXT("피자 빵가루"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("180g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("다진마늘"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1작은술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("다진양파"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("다진 쇠고기"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("토마토 페이스트"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("3큰술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(5,TEXT("월계수잎"));
		m_MaterialList.SetItem(5, 1, LVIF_TEXT, _T("1장"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(6,TEXT("오레가노"));
		m_MaterialList.SetItem(6, 1, LVIF_TEXT, _T("약간"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(7,TEXT("육수"));
		m_MaterialList.SetItem(7, 1, LVIF_TEXT, _T("1/4컵"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(8,TEXT("베이컨"));
		m_MaterialList.SetItem(8, 1, LVIF_TEXT, _T("1장"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(9,TEXT("햄"));
		m_MaterialList.SetItem(9, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(10,TEXT("양송이"));
		m_MaterialList.SetItem(10, 1, LVIF_TEXT, _T("2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(11,TEXT("청피망"));
		m_MaterialList.SetItem(11, 1, LVIF_TEXT, _T("1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(12,TEXT("홍피망"));
		m_MaterialList.SetItem(12, 1, LVIF_TEXT, _T("1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(13,TEXT("양파"));
		m_MaterialList.SetItem(13, 1, LVIF_TEXT, _T("1/4개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(14,TEXT("블랙올리브"));
		m_MaterialList.SetItem(14, 1, LVIF_TEXT, _T("3개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(15,TEXT("모짜렐라 치즈"));
		m_MaterialList.SetItem(15, 1, LVIF_TEXT, _T("150g"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("크러스트는 볼에 피자 빵가루와 물을 넣고 반죽기로 표면이 매끈해지도록 치댄 후, 반죽을 밀어서 구이전용 팬에 올립니다.  다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("소스는 팬을 달구어 다진 마늘, 양파를 넣고 볶은 후 다진 쇠고기를 넣고 볶은 후, 토마토페이스트를 넣고 잘 섞은 후 육수를 붓고 월계수 잎을 넣어 걸쭉한 상태로 졸이고 오레가노를 넣어 잘 섞어줍니다. 마지막에 소금, 후추로 간합니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("토핑은 양파, 피망, 양송이는 적당한 크기로 썰어서 살짝 데쳐서 물기를 없앤 후, 베이컨, 햄은 적당한 크기로 자릅니다. 그리고, 모짜렐라 치즈는 잘게 다지고 올리브는 모양대로 얇게 썰어 둡니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("1의 크러스트 가장자리 1센치 정도만 남기고 가운데 부분은 포크로 찔러주고, 가장자리 1센치 남긴 부분에 올리브유를 살짝 발라 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("크러스트 가운데 부분의 2의 소스를 고구 펴 바르고 모짜렐라 치즈 50그램을 얇게 뿌립니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(5,TEXT("햄, 베이컨, 양송이, 양파, 피망 순으로 토핑합니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(6,TEXT("마지막으로 나머지 모짜렐라 치즈를 고루 뿌린 뒤 올리브로 장식하여 4단에 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 22:
		m_MaterialList.InsertItem(0,TEXT("식빵"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2~4개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("버터"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1큰술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("피자 소스"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("80g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("베이컨"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("1장"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("햄"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(5,TEXT("양송이"));
		m_MaterialList.SetItem(5, 1, LVIF_TEXT, _T("2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(6,TEXT("청피망"));
		m_MaterialList.SetItem(6, 1, LVIF_TEXT, _T("1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(7,TEXT("홍피망"));
		m_MaterialList.SetItem(7, 1, LVIF_TEXT, _T("1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(8,TEXT("양파"));
		m_MaterialList.SetItem(8, 1, LVIF_TEXT, _T("1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(9,TEXT("블랙올리브"));
		m_MaterialList.SetItem(9, 1, LVIF_TEXT, _T("3개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(10,TEXT("모짜렐라"));
		m_MaterialList.SetItem(10, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("토핑은 다음과 같이 만듭니다. 양파,청,홍피망,양송이는 적당한 크기로 썰어서 내열용기에 담고 랩을 씌워 수동요리레인지 기능으로 2~3분 가열한 후 물기를 없앱니다. 이를 위한 알람 셋팅을 하시겠습니까?"));
		m_RecipeList.InsertItem(1,TEXT("베이컨, 햄은 적당한 크기로 자릅니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("모짜렐라 치즈는 잘게 다지고 올리브는 모양대로 얇게 썰어 둡니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("상온 버터를 식빵의 한 면에 바른 후, 피자소스를 바릅니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(4,TEXT("햄, 베이컨, 양송이, 양파, 피망 순으로 토핑합니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(5,TEXT("모짜렐라 치즈를 고루 뿌린 뒤 올리브로 장식합니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(6,TEXT("법량접시에 유산지를 깔고 식빵을 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	case 23:
		m_MaterialList.InsertItem(0,TEXT("다진 쇠고기"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("300g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("다진 돼지고기"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("다진 마늘"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("2큰술+1작은술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("다진 양파"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("1개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("달걀"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("1개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(5,TEXT("빵가루"));
		m_MaterialList.SetItem(5, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(6,TEXT("양파"));
		m_MaterialList.SetItem(6, 1, LVIF_TEXT, _T("1/2개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(7,TEXT("우스터 소스"));
		m_MaterialList.SetItem(7, 1, LVIF_TEXT, _T("1큰술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(8,TEXT("적포도주"));
		m_MaterialList.SetItem(8, 1, LVIF_TEXT, _T("2큰술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(9,TEXT("육수"));
		m_MaterialList.SetItem(9, 1, LVIF_TEXT, _T("1/2컵"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("팬을 달구어 다진 마늘, 양파를 넣고 볶은 후 한김 식힙니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("다진 쇠고기, 돼지고기에 다진 마늘, 양파, 달걀, 우유, 빵가루, 소금, 후추, 분유를 넣고 끈기가 생길 때까지 힘껏 치대 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("끈기가 생긴 고기 반죽을 4등분하여 1.5센치 두께, 지름 8센치로 동글 납작하게 만들어 가운데 부분을 오목하게 눌러 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("구이전용 팬에 올리브유를 적당히 두르고 가지런히 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		m_RecipeList.InsertItem(4,TEXT("도중에 멜로디가 울리면 한번 뒤집어 줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(5,TEXT("팬을 달구어 다진 마늘, 양파를 넣고 볶은 후 케첩을 넣어 고루 섞이도록 볶아 줍니다. 우스터 소스, 적포도주, 육수를 넣은 후 이분의 일로 될때까지 졸입니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(6,TEXT("우유를 조금씩 넣어 가며 섞어준 후 소금, 후추로 간하여 웨지감자 체에 걸러 햄버그 스테이크에 곁들여 냅니다. 다음단계로 진행할까요?"));
		break;
	case 24:
		m_MaterialList.InsertItem(0,TEXT("식빵"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("1개"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("꿀"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("3큰술"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("버터"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1큰술"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("통 식빵을 반으로 자릅니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(1,TEXT("식빵의 한쪽 면이 위로 오게 하여 밑바닥에 구멍이 나지 않게 엑스자 칼집을 넣어줍니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(2,TEXT("칼집을 낸 부분에 꿀을 넣고 식빵 뒷면에 버터를 바릅니다. 다음단계로 진행할까요?"));
		m_RecipeList.InsertItem(3,TEXT("법량접시에 유산지를 깔고 식빵을 올린 후 넣어주세요. 준비되시면 다음이라고 말씀해주세요."));
		break;
	}
	//m_MaterialList.InsertItem(0,TEXT("허니브레드"));
	//m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0행 1열"), 0, 0, 0, NULL );
	*pResult = 0;
}


//void CTab2::OnNMDblclkList3(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;
//	index2 = pNMItemActivate->iItem;
//	indexsub = pNMItemActivate->iSubItem;
//
//	CString recipelog=m_RecipeList.GetItemText(index2, indexsub);
//	//char* recipe= NULL;
//	switch(index2)
//	{
//	case 0:
//		//recipe="감자는 삶아 으깨어서 준비합니다.";
//		break;
//	}
//	wchar_t* wchar_str;     //첫번째 단계(CString to wchar_t*)를 위한 변수
//	char*    char_str;      //char* 형의 변수
//	int      char_str_len;  //char* 형 변수의 길이를 위한 변수
//
//	//1. CString to wchar_t* conversion
//	wchar_str = recipelog.GetBuffer(recipelog.GetLength());
//
//	//2. wchar_t* to char* conversion
//	//char* 형에 대한길이를 구함
//	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
//	char_str = new char[char_str_len];  //메모리 할당
//	//wchar_t* to char* conversion
//	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  
//
//	if(__ClipCopy2(char_str))
//	{
//		AfxMessageBox(TEXT("레시피가 클립보드에 복사되었습니다"));
//	}
//	*pResult = 0;
//}
BOOL __ClipCopy2(char *txt)
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

//void CTab2::OnHdnItemdblclickList3(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;
//	index2 =  pNMView->iItem;
//	indexsub =  pNMView->iSubItem;
//
//	CString recipelog=m_RecipeList.GetItemText(index2, indexsub);
//	//char* recipe= NULL;
//	switch(index2)
//	{
//	case 0:
//		//recipe="감자는 삶아 으깨어서 준비합니다.";
//		break;
//	}
//	wchar_t* wchar_str;     //첫번째 단계(CString to wchar_t*)를 위한 변수
//	char*    char_str;      //char* 형의 변수
//	int      char_str_len;  //char* 형 변수의 길이를 위한 변수
//
//	//1. CString to wchar_t* conversion
//	wchar_str = recipelog.GetBuffer(recipelog.GetLength());
//
//	//2. wchar_t* to char* conversion
//	//char* 형에 대한길이를 구함
//	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
//	char_str = new char[char_str_len];  //메모리 할당
//	//wchar_t* to char* conversion
//	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  
//
//	if(__ClipCopy2(char_str))
//	{
//		AfxMessageBox(TEXT("레시피가 클립보드에 복사되었습니다"));
//	}
//	*pResult = 0;
//}


void CTab2::OnNMDblclkList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;
	index2 = pNMItemActivate->iItem;
	indexsub = pNMItemActivate->iSubItem;

	CString recipelog=m_RecipeList.GetItemText(index2, indexsub);
	//char* recipe= NULL;
	switch(index2)
	{
	case 0:
		//recipe="감자는 삶아 으깨어서 준비합니다.";
		break;
	}
	wchar_t* wchar_str;     //첫번째 단계(CString to wchar_t*)를 위한 변수
	char*    char_str;      //char* 형의 변수
	int      char_str_len;  //char* 형 변수의 길이를 위한 변수

	//1. CString to wchar_t* conversion
	wchar_str = recipelog.GetBuffer(recipelog.GetLength());

	//2. wchar_t* to char* conversion
	//char* 형에 대한길이를 구함
	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
	char_str = new char[char_str_len];  //메모리 할당
	//wchar_t* to char* conversion
	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  

	if(__ClipCopy2(char_str))
	{
		AfxMessageBox(TEXT("레시피가 클립보드에 복사되었습니다"));
	}
	*pResult = 0;
}


//void CTab2::OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	*pResult = 0;
//}


void CTab2::OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	index2 = pNMItemActivate->iItem;
	indexsub = pNMItemActivate->iSubItem;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString recipelog=m_RecipeList.GetItemText(index2, indexsub);
	SetDlgItemTextW(IDC_EDIT1,recipelog);
	*pResult = 0;
}


void CTab2::OnBnClickedButton1()
{
	CString materials;
	int count = m_MaterialList.GetItemCount(), index = 0;
	for(int i = 0; i < count-1; i++)
		materials+=m_MaterialList.GetItemText(i,0)+TEXT(",");
	if(count-1>=0)
		materials+=m_MaterialList.GetItemText(count-1,0);

	wchar_t* wchar_str;     //첫번째 단계(CString to wchar_t*)를 위한 변수
	char*    char_str;      //char* 형의 변수
	int      char_str_len;  //char* 형 변수의 길이를 위한 변수

	//1. CString to wchar_t* conversion
	wchar_str = materials.GetBuffer(materials.GetLength());

	//2. wchar_t* to char* conversion
	//char* 형에 대한길이를 구함
	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
	char_str = new char[char_str_len];  //메모리 할당
	//wchar_t* to char* conversion
	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  

	if(__ClipCopy2(char_str))
	{
		AfxMessageBox(TEXT("재료가 클립보드에 복사되었습니다"));
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
