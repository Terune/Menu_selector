// Selection.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "Selection.h"
#include "afxdialogex.h"


// CSelection ��ȭ �����Դϴ�.

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
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("�佺Ʈ"));
	}
	else if(Sel_name=="Con")
	{
		m_SelectList.InsertItem(0,TEXT("��������"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("�������� ��"));
	}
	else if(Sel_name=="Material")
	{
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("���ǰ���"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("��"));
		m_SelectList.InsertItem(0,TEXT("�õ�����"));
		m_SelectList.InsertItem(0,TEXT("���� �������"));
		m_SelectList.InsertItem(0,TEXT("���� ����"));
		m_SelectList.InsertItem(0,TEXT("���� ����"));
		m_SelectList.InsertItem(0,TEXT("���� ����"));
		m_SelectList.InsertItem(0,TEXT("�ް�"));
		m_SelectList.InsertItem(0,TEXT("�ߴٸ�"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("������� ��"));
		m_SelectList.InsertItem(0,TEXT("�Ƕ��"));
		m_SelectList.InsertItem(0,TEXT("���"));
		m_SelectList.InsertItem(0,TEXT("��¥���� ġ��"));
		m_SelectList.InsertItem(0,TEXT("�ٴҶ����"));
		m_SelectList.InsertItem(0,TEXT("�ڷº�"));
		m_SelectList.InsertItem(0,TEXT("��"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("���̱�"));
		m_SelectList.InsertItem(0,TEXT("������"));
		m_SelectList.InsertItem(0,TEXT("����ŷ �Ҵ�"));
		m_SelectList.InsertItem(0,TEXT("����ŷ �Ŀ��"));
		m_SelectList.InsertItem(0,TEXT("�� �ø���"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("��ũ��"));
		m_SelectList.InsertItem(0,TEXT("���İ�Ƽ��"));
		m_SelectList.InsertItem(0,TEXT("�Ļ�"));
		m_SelectList.InsertItem(0,TEXT("������"));
		m_SelectList.InsertItem(0,TEXT("�����"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("��������"));
		m_SelectList.InsertItem(0,TEXT("�ø����"));
		m_SelectList.InsertItem(0,TEXT("�콺�� �ҽ�"));
		m_SelectList.InsertItem(0,TEXT("�������"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("��"));
		m_SelectList.InsertItem(0,TEXT("��������"));
		m_SelectList.InsertItem(0,TEXT("�߷º�"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("û�Ǹ�"));
		m_SelectList.InsertItem(0,TEXT("����Ĩ"));
		m_SelectList.InsertItem(0,TEXT("��"));
		m_SelectList.InsertItem(0,TEXT("ũ��ġ��"));
		m_SelectList.InsertItem(0,TEXT("�丶�� ���̽�Ʈ"));
		m_SelectList.InsertItem(0,TEXT("�����"));
		m_SelectList.InsertItem(0,TEXT("�ĸ��� ġ��"));
		m_SelectList.InsertItem(0,TEXT("�Ľ��� ����"));
		m_SelectList.InsertItem(0,TEXT("���� ������"));
		m_SelectList.InsertItem(0,TEXT("���ڼҽ�"));
		m_SelectList.InsertItem(0,TEXT("��"));
		m_SelectList.InsertItem(0,TEXT("ȫ�Ǹ�"));
	}
	else if(Sel_name=="Menu")
	{
		m_SelectList.InsertItem(0,TEXT("���ڱ׶���"));
		m_SelectList.InsertItem(0,TEXT("������"));
		m_SelectList.InsertItem(0,TEXT("�õ�����"));
		m_SelectList.InsertItem(0,TEXT("������"));
		m_SelectList.InsertItem(0,TEXT("�ߴٸ�"));
		m_SelectList.InsertItem(0,TEXT("�Ƕ�� ����"));
		m_SelectList.InsertItem(0,TEXT("������ũ"));
		m_SelectList.InsertItem(0,TEXT("�� �ٺ�ť"));
		m_SelectList.InsertItem(0,TEXT("���û�"));
		m_SelectList.InsertItem(0,TEXT("���̱�"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("������ ����ũ"));
		m_SelectList.InsertItem(0,TEXT("�Ļ�"));
		m_SelectList.InsertItem(0,TEXT("���"));
		m_SelectList.InsertItem(0,TEXT("�����"));
		m_SelectList.InsertItem(0,TEXT("���� ���İ�Ƽ"));
		m_SelectList.InsertItem(0,TEXT("����Ĩ ��Ű"));
		m_SelectList.InsertItem(0,TEXT("ġ�� ����ũ"));
		m_SelectList.InsertItem(0,TEXT("�밨��"));
		m_SelectList.InsertItem(0,TEXT("���"));
		m_SelectList.InsertItem(0,TEXT("�����"));
		m_SelectList.InsertItem(0,TEXT("����"));
		m_SelectList.InsertItem(0,TEXT("�����佺Ʈ"));
		m_SelectList.InsertItem(0,TEXT("�ܹ��� ������ũ"));
		m_SelectList.InsertItem(0,TEXT("��Ϻ극��"));
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
	// �θ� ��ȭ���ڿ��� ������ �����͸� ��� ������ �����Ѵ�.
	Sel_name = Select_name;
	Sel_value = Select_Tema;
}
void CSelection::GetUserData(CString &parm_name)
{
	// ���� ��� ������ ������ �ִ� ���� �Ű������� �������ش�.
	// �� �Լ��� ModifyDlg�� ������ �θ� ��ȭ���ڿ��� ȣ���Ұ��̸�
	// DoModal�� �����Ŀ� ����� ���̴�.
	parm_name = List_Select;
	//parm_age = Sel_value;
}
BEGIN_MESSAGE_MAP(CSelection, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSelection::OnBnClickedOk)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CSelection::OnNMClickList1)
END_MESSAGE_MAP()


// CSelection �޽��� ó�����Դϴ�.


void CSelection::OnBnClickedOk()
{

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
		//���⼭ index������ �޾ƿ��� �˴ϴ�.
		List_Select = m_SelectList.GetItemText(index,0);
	}
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}

CString CSelection::Matching_name(CString input)
{
	if(input=="����")
		return TEXT("oven");
	else if(input=="�佺Ʈ")
		return TEXT("toast");
	else if(input=="��������")
		return TEXT("plate");
	else if(input=="����")
		return TEXT("grate");
	else if(input=="�������� ��")
		return TEXT("pan");
	else if(input=="����")
		return TEXT("eggplant");
	else if(input=="����")
		return TEXT("potato");
	else if(input=="���ǰ���")
	return TEXT("cinnamon_powder");
	else if(input=="����")
		return TEXT("sweet_potato");
	else if(input=="��")
		return TEXT("honey");
	else if(input=="�õ�����")
		return TEXT("pizza");
	else if(input=="���� �������")
		return TEXT("pork");
	else if(input=="���� ����")
		return TEXT("crushed_galic");
	else if(input=="���� ����")
		return TEXT("beef");
	else if(input=="���� ����")
		return TEXT("small_green_onion");
	else if(input=="�ް�")
		return TEXT("egg");
	else if(input=="�ߴٸ�")
		return TEXT("drumstick");
	else if(input=="����")
		return TEXT("jujube");
	else if(input=="������� ��")
		return TEXT("pork");
	else if(input=="�Ƕ��")
		return TEXT("Tortilla");
	else if(input=="���")
		return TEXT("nonglutinous_rice");
	else if(input=="��¥���� ġ��")
		return TEXT("cheese");
	else if(input=="�ٴҶ����")
		return TEXT("vanilla_oil");
	else if(input=="�ڷº�")
		return TEXT("soft_flour");
	else if(input=="��")
		return TEXT("chestnut");
	else if(input=="����")
		return TEXT("butter");
	else if(input=="���̱�")
		return TEXT("bagle");
	else if(input=="������")
		return TEXT("bacon");
	else if(input=="����ŷ �Ҵ�")
		return TEXT("baking_soda");
	else if(input=="����ŷ �Ŀ��")
		return TEXT("baking_powder");
	else if(input=="�� �ø���")
		return TEXT("black_olive");
	else if(input=="����")
		return TEXT("chicken");
	else if(input=="��ũ��")
		return TEXT("cream");
	else if(input=="���İ�Ƽ��")
		return TEXT("spaghetti");
	else if(input=="�Ļ�")
		return TEXT("bread");
	else if(input=="������")
		return TEXT("rice");
	else if(input=="�����")
		return TEXT("button_mushroom");
	else if(input=="����")
		return TEXT("onion");
	else if(input=="��������")
		return TEXT("oregano");
	else if(input=="�ø����")
		return TEXT("oligosaccharides");
	else if(input=="�콺�� �ҽ�")
		return TEXT("worcester_sauce");
	else if(input=="�������")
		return TEXT("bay_leaf");
	else if(input=="����")
		return TEXT("meat_broth");
	else if(input=="����")
		return TEXT("ginkgo_nut");
	else if(input=="��")
		return TEXT("pine_nut");
	else if(input=="��������")
		return TEXT("red_wine");
	else if(input=="�߷º�")
		return TEXT("medium_flour");
	else if(input=="����")
		return TEXT("sticky_rice");
	else if(input=="û�Ǹ�")
		return TEXT("squid");
	else if(input=="����Ĩ")
		return TEXT("chocochip");
	else if(input=="��")
		return TEXT("bean");
	else if(input=="ũ��ġ��")
		return TEXT("cream_cheese");
	else if(input=="�丶�� ���̽�Ʈ")
		return TEXT("tomato_paste");
	else if(input=="�����")
		return TEXT("pork_belly");
	else if(input=="�ĸ��� ġ��")
		return TEXT("parmesan");
	else if(input=="�Ľ��� ����")
		return TEXT("parsley");
	else if(input=="���� ������")
		return TEXT("bread_crumbs");
	else if(input=="���ڼҽ�")
		return TEXT("pizza_source");
	else if(input=="��")
		return TEXT("ham");
	else if(input=="ȫ�Ǹ�")
		return TEXT("red_peppers");
	else if(input=="���ڱ׶���")
	return TEXT("	gratin	");
	else if(input=="������")
return TEXT("	roasted_sweet_potato	");
	else if(input=="�õ�����")
return TEXT("	frozen_pizza	");
	else if(input=="������")
return TEXT("	nurungji	");
	else if(input=="�ߴٸ�")
		return TEXT("	drumstick	");

	else if(input=="�Ƕ�� ����")
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

	else if(input=="������ũ");
	else if(input=="�� �ٺ�ť");
	else if(input=="���û�");
	else if(input=="���̱�");
	else if(input=="����");
	else if(input=="������ ����ũ");
	else if(input=="�Ļ�");
	else if(input=="���");
	else if(input=="�����");
	else if(input=="���� ���İ�Ƽ");
	else if(input=="����Ĩ ��Ű");
	else if(input=="ġ�� ����ũ");
	else if(input=="�밨��");
	else if(input=="���");
	else if(input=="�����");
	else if(input=="����");
	else if(input=="�����佺Ʈ");
	else if(input=="�ܹ��� ������ũ");
	else if(input=="��Ϻ극��");
}
