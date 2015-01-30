// Tab2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CookTalk_MenuSelector.h"
#include "Tab2.h"
#include "afxdialogex.h"


// CTab2 ��ȭ �����Դϴ�.

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
	
	m_ManuList.InsertColumn(0,_T("�丮�̸�"),LVCFMT_LEFT, 140, -1);
	m_ManuList.InsertItem(0,TEXT("���ڱ׶���"));
	m_ManuList.InsertItem(0,TEXT("������"));
	m_ManuList.InsertItem(0,TEXT("�õ�����"));
	m_ManuList.InsertItem(0,TEXT("������"));
	m_ManuList.InsertItem(0,TEXT("�ߴٸ�"));
	m_ManuList.InsertItem(0,TEXT("�Ƕ�� ����"));
	m_ManuList.InsertItem(0,TEXT("������ũ"));
	m_ManuList.InsertItem(0,TEXT("�� �ٺ�ť"));
	m_ManuList.InsertItem(0,TEXT("���û�"));
	m_ManuList.InsertItem(0,TEXT("���̱�"));
	m_ManuList.InsertItem(0,TEXT("����"));
	m_ManuList.InsertItem(0,TEXT("������ ����ũ"));
	m_ManuList.InsertItem(0,TEXT("�Ļ�"));
	m_ManuList.InsertItem(0,TEXT("���"));
	m_ManuList.InsertItem(0,TEXT("�����"));
	m_ManuList.InsertItem(0,TEXT("���� ���İ�Ƽ"));
	m_ManuList.InsertItem(0,TEXT("����Ĩ ��Ű"));
	m_ManuList.InsertItem(0,TEXT("ġ�� ����ũ"));
	m_ManuList.InsertItem(0,TEXT("�밨��"));
	m_ManuList.InsertItem(0,TEXT("���"));
	m_ManuList.InsertItem(0,TEXT("�����"));
	m_ManuList.InsertItem(0,TEXT("����"));
	m_ManuList.InsertItem(0,TEXT("�����佺Ʈ"));
	m_ManuList.InsertItem(0,TEXT("�ܹ��� ������ũ"));
	m_ManuList.InsertItem(0,TEXT("��Ϻ극��"));

	m_MaterialList.InsertColumn(0,_T("����̸�"),LVCFMT_LEFT, 100, -1);
	m_MaterialList.InsertColumn(1,_T("��"),LVCFMT_LEFT,270, -1);

	m_RecipeList.InsertColumn(0,_T("������"),LVCFMT_LEFT, 370, -1);
//	m_RecipeList.InsertColumn(1,_T("����"),LVCFMT_LEFT,320, -1);
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


// CTab2 �޽��� ó�����Դϴ�.


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
		m_MaterialList.InsertItem(0,TEXT("����"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("������"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("����"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1/4��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("��¥���� ġ��"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("���ڴ� ��� ����� �غ��մϴ�. �����ܰ�� �����ұ��?"));
		//m_RecipeList.SetItem(0, 1, LVIF_TEXT, _T("���ڴ� ��� ����� �غ��մϴ�."), 0, 0, 0, NULL );
		m_RecipeList.InsertItem(1,TEXT("������, ���ĸ� ä��� ���Ϳ� ���ƵӴϴ�. ä��� ������ ���ðڽ��ϱ�?"));
		//m_RecipeList.SetItem(1, 1, LVIF_TEXT, _T("������, ���ĸ� ä��� ���Ϳ� ���ƵӴϴ�. ä��� ������ ���ðڽ��ϱ�?"), 0, 0, 0, NULL );
		m_RecipeList.InsertItem(2,TEXT("�ҿ� �а���, ���͸� �־� ���� �� ������ ���ݾ� �־� ���� �а��� �ۿ��� Ǯ�� �ұ�, ���߷� ���Ͽ� �ҽ��� ����ϴ�. �̶� ���� �ణ ���� �ϰ� �ҽ��� �ణ ���� �մϴ�. �����ܰ�� �����ұ��?"));
		//m_RecipeList.SetItem(2, 1, LVIF_TEXT, _T("�ҿ� �а���, ���͸� �־� ���� �� ������ ���ݾ� �־� ���� �а��� �ۿ��� Ǯ�� �ұ�, ���߷� ���Ͽ� �ҽ��� ����ϴ�. �̶� ���� �ణ ���� �ϰ� �ҽ��� �ణ ���� �մϴ�."), 0, 0, 0, NULL );
		m_RecipeList.InsertItem(3,TEXT("ȭ��Ʈ�ҽ� �̺��� �� �з��� ���� ���� ���ڸ� �־� �����ϴ�. �����ܰ�� �����ұ��?"));

		m_RecipeList.InsertItem(4,TEXT("�׶�������, ���� 23��Ƽ ������ �������ÿ� �ҽ��� ������ ��Ḧ ��� ���� �ҽ��� ������ �� ���� ġ��, ������, �Ľ��� ������ �ø��ϴ�. �����ܰ�� �����ұ��?"));
		
		m_RecipeList.InsertItem(5,TEXT("�������ÿ� ���踦 ���� �׶��� ���ø� �ø� �� 2�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		
		break;
	case 1:
		m_MaterialList.InsertItem(0,TEXT("����"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.4~ 1.2kg"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("������ �ʹ� ũ�� �ʴ� ������ ��� ������ ���� �� ���⸦ �۾� ������ ��ũ�� ������ �� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("1�ܿ� �������� ���� ���踦 ���� ������ �������� �÷��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 2:
		m_MaterialList.InsertItem(0,TEXT("�õ�����"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.2~ 0.6kg"), 0, 0, 0, NULL );
		
		m_RecipeList.InsertItem(0,TEXT("�������ø� ���迡 ���� ������ ������ �õ����ڸ� �ø� �� 3�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 3:
		m_MaterialList.InsertItem(0,TEXT("������"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.2kg"), 0, 0, 0, NULL );
		
		m_RecipeList.InsertItem(0,TEXT("��¿� ������ ���� �� �̹�׶��� �������� �� ���� ��� ��ü�� �� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("�ڵ��丮���쿡�� �������� ������ �� 4�ܿ� �÷��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 4:
		m_MaterialList.InsertItem(0,TEXT("�ߴٸ�"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.3~1.0kg"), 0, 0, 0, NULL );
		
		m_RecipeList.InsertItem(0,TEXT("�ߴٸ��� Į���� �־��� �� �ұ�, ����, û�ֿ� �� ��ʺ� ���� ���ϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("�ߴٸ��� �ø������� �ٸ� �� �������� �� ���� �������� ����, 4�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		m_RecipeList.InsertItem(2,TEXT("���߿� ��ε� �︮�� �ѹ� �������ݴϴ�. �����ܰ�� �����ұ��?"));
		break;
	case 5:
		m_MaterialList.InsertItem(0,TEXT("�Ƕ��"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("���ڼҽ�"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("������"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("��"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("�����"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(5,TEXT("û�Ǹ�"));
		m_MaterialList.SetItem(5, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(6,TEXT("ȫ�Ǹ�"));
		m_MaterialList.SetItem(6, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(7,TEXT("����"));
		m_MaterialList.SetItem(7, 1, LVIF_TEXT, _T("1/4��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(8,TEXT("�� �ø���"));
		m_MaterialList.SetItem(8, 1, LVIF_TEXT, _T("3��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(9,TEXT("��¥���� ġ��"));
		m_MaterialList.SetItem(9, 1, LVIF_TEXT, _T("70g"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("������ ������ ���� �غ��մϴ�. ���� ����, û, ȫ�Ǹ�, ����̴� ������ ũ��� �� ������⿡ ��� ���� ���� �����丮������ ������� 2~3�� ������ �� ���⸦ ���۴ϴ�.  �˶������� �Ͻðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("������, ���� ������ ũ��� �ڸ��ϴ�. ��¥���� ġ��� �߰� ������, �ø���� ����� ��� ����ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("�Ƕ�� 2���� ���� �������� �ҿ� �ø��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("��� �κп� ���ڼҽ��� ��� �� �ٸ��� ��, ������, �����, ����, �Ǹ� ������ �����մϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("��¥���� ġ� ��� �Ѹ� �� �ø���� ����Ͽ� 4�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 6:
		m_MaterialList.InsertItem(0,TEXT("�ڷº�"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("130g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("�ް�"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("6��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("�ٴҶ����"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T( "1/4 ������"), 0, 0, 0, NULL );
	
		m_RecipeList.InsertItem(0,TEXT("�ڷº��� ü�� �Ӵϴ�. üġ�� ������ ���ðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("������ ������ ������ �����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("���� 2�� �غ��Ͽ� ������ ����, �ٸ� �� ���� �븥�ڸ� �и��� ���� �븥�� 1���� ���� ���Ӵϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("�븥�ڸ� Ǯ�� �ұ�, ����, ����, ������ �Բ� �ְ� ���̺������� �ǵ��� ��ǰ�� ���ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("���ڴ� ��� ���� ��ǰ�� �ø� �� ������ ���ݾ� ������ ������ ��ǰ�� �����ϰ� ���ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(5,TEXT("�븥�ڿ� ���ڸ� ����� ������ �ְ� ������ ���ٰ� ü�� ģ �а��縦 �־� �ְ����� ������ ������ �����ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(6,TEXT("�Ŀ����� �־� ��� ���� ���� ������ ���� ��ǰ�� �־� ��ǰ�� ������� �ʵ��� �绡�� ���� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(7,TEXT("�������ÿ� �������� ��� ������ �����ϰ� �ξ��ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(8,TEXT("�븥�� 1���� �ұ��� �ణ �־� �� Ǯ�� ��Һ����� ��� ������ �۰� �վ� ���� ���� �긮�鼭 ������׷� ���̸� ����� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(9,TEXT("���� �ݴ����� ���������� �ٽ� ������׷� ������ ���� ���̸� ����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(10,TEXT("���� 2�ܿ� ��Ḧ �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		m_RecipeList.InsertItem(11,TEXT("���� �麸�� �غ��Ͽ� �ٴڿ� ��� ������ ����ũ�� �ٴ��� ���� ������ ���� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(12,TEXT("����ũ ���� ���� ��� �ٸ� �� �麸 �Ʒ��� ����̸� ��� ����ũ�� �о� ���� �����ݴϴ�. �����ܰ�� �����ұ��?"));
		break;
	case 7:
		m_MaterialList.InsertItem(0,TEXT("������� ��"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("1.0kg"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("���� ������ �غ��Ͽ� �⸧�� ���װ� ������ 2�ð����� �㰡 �͹��� ���ϴ�. �̸� ���� �˶������� �Ͻðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("���⸦ �����ϰ� ���� ��, �ұ�, ���߷� �ذ��� �մϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("�������� ���� ���踦 ���� ���� �÷��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		m_RecipeList.InsertItem(3,TEXT("�з���� ���� �ҽ��� ����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("���߿� ��ε� �︮�� �ҽ��� ������ ��� �ٸ� �� ���� �ð� ���� �� �����ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(5,TEXT("���� ���ÿ� ��� �ҽ��� �ѹ� �� ����� ���ϴ�. �����ܰ�� �����ұ��?"));
		break;

	case 8:
		m_MaterialList.InsertItem(0,TEXT("�Ļ�"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2~4��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("���� ����"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("2ū��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("���� �Ľ���"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("2ū��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("����"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("4ū��"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("��� ���Ϳ� ���� ����, ���� �Ľ����� ���� �Ļ��� �� �鿡 �ٸ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("�������ÿ� �������� ��� �Ļ��� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;

	case 9:
		m_MaterialList.InsertItem(0,TEXT("���̱�"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("1~3��"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("���̱��� ������ �ڸ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("���̱��� ���� ���� ���� �����Ͽ� �������� �ҿ� ��ġ�� �ʰ� �ø�����. �غ�ǽø� �����̶�� ������ �ּ���."));
		break;

	case 10:
		m_MaterialList.InsertItem(0,TEXT("�߷º�"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("300g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("����ŷ�Ŀ��"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1������"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("�ް�"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("2��"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("�߷º�, ����ŷ �Ŀ���� üġ�� ����, �ұ�, ���� ������ ���͸� �ְ� �ڸ����� �����ϴ�. ���Ϳ� �а��簡 ��� ���� �ν��ν��� ���°� �ǵ��� ����ϴ�. �̿� ���� üġ�� �������� ���ðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("�̸� ���� �ް��� ������ 1�� �ְ� �ڸ��� ��� �����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("���� ���簡 ������ �ʰ�, ������ �ϳ��� �������� ���� ���� ������� 30������ ���� ��ŵ�ϴ�. �̸� ���� �˸������� �Ͻðڽ��ϱ�?"));
		m_RecipeList.InsertItem(3,TEXT("������ �� 2.5��ġ �β��� �ǵ��� �д�� �� ���� ���� ũ��� �ڸ��ϴ�. �̶� �����縦 ����ؾ� �о� ��Ⱑ ���մϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("���� ���ÿ� �������� ��� ������ �ø� �� ǥ�鿡 �ް����� ĥ�մϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(5,TEXT("2�ܿ� �ش� �������ø� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;

	case 11:
		m_MaterialList.InsertItem(0,TEXT("�ڷº�"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("�ٴҶ� ����"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("�ѹ��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT(" �ް�"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("4��"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("�ڷº��� ü�� �Ӵϴ�. üġ�� ������ ���ðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("����ũ Ʋ �ٴڰ� ���鿡 ���̸� ��� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("���͸� ������ �Բ� �쿩 �� �� �ٴҶ� ������ �� ��� ���� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("�ް��� ������ ������ ������ �� ���� �ְ� Ǯ���ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("�ް��� ������ �Ѳ����� �ְ� ��ǰ�⸦ ���� ���� �����ϰ� ��¦ ������ ������ ��ǰ�� ���ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(5,TEXT("��ǰ�� �ް��� �ڷº��� �ְ� ���� ���� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(6,TEXT("�� ������ �Ϻθ� ���� ���� ������ �־� ���� �� �ٽ� ���׿� �־� �绡�� ���� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(7,TEXT("������ Ʋ�� �װ� Ʋ�� �ѹ� ����ٰ� �ٴڿ� ���� ���� ���� ������ ���� �� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(8,TEXT("�������� ���� ���踦 ���� ����ũ Ʋ�� �ø� �� 1�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 12:
		m_MaterialList.InsertItem(0,TEXT("�Ļ�"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2~4��"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("�������� �ҿ� �Ļ��� ��ġ�� �ʰ� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		m_RecipeList.InsertItem(1,TEXT("���߿� ��ε� �︮�� �ѹ� ������ �ش�."));
		break;
	case 13:
		m_MaterialList.InsertItem(0,TEXT("����"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2��(340g)"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("���ǰ���"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1/2������"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("��"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("5��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("����"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("10��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("��"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("1ū��"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("������ �� �ð� �̻� ���� �ҷ� ü�� ���� �Ӵϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("���� ������ ���� 4����ϰ�, ���ߴ� ���� ������ 2����ϰ�, ���� ����� ������ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("���� ���ÿ� ���踦 ���� 2���� ���� ũ���� ���� ��⸦ �ø� �� �Ѳ� �Ǵ� �˷�̴� ȣ�Ϸ� ���� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		m_RecipeList.InsertItem(3,TEXT("������ ������ ���쿡 �� 10�� ���� �״�� �ξ� �� ���� �� ������ ���⸧�� �ְ� ��� ���� �ݴϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?"));
		m_RecipeList.InsertItem(4,TEXT("���� ������ ���� ������ �����մϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(5,TEXT("���쿡�� ���� ���� �� �����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(6,TEXT("�ణ ������ ���� ��������� ���� ���� ���ÿ� �������ϴ�. �����ܰ�� �����ұ��?"));
		break;

	case 14:
		m_MaterialList.InsertItem(0,TEXT("���"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("����"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("��"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("5��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("����"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("3��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("��"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("1ū��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(5,TEXT("��"));
		m_MaterialList.SetItem(5, 1, LVIF_TEXT, _T("4ū��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(6,TEXT("����"));
		m_MaterialList.SetItem(6, 1, LVIF_TEXT, _T("6��"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("���, ������ �ľ 3�ð� �̻� �ҷ� �����ϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("���� ������ ���� 2����ϰ�, ���� ����� ���� �����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("���ߴ� ���� ���� 2����ϰ�, ���� 6�ð� �̻� �ҷ��� �غ��մϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("������⿡ �Ҹ� ��, ��, ��, ����, ����, ��, �ұ��� �ְ� ���� �׽��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("�������ÿ� ���踦 ���� 2�������� ũ���� ������⸦ �ø� �� �Ѳ� �Ǵ� �˷�̴� ȣ�Ϸ� ���� 1�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		m_RecipeList.InsertItem(5,TEXT("������ ������ ���쿡 �� 10�� ���� �״�� �ξ� ���� ���Դϴ�. �̸� ���� �˶������� �Ͻðڽ��ϱ�?"));
		break;
	case 15:
		m_MaterialList.InsertItem(0,TEXT("���İ�Ƽ��"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("����"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("��¥���� ġ��"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("40g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("���� ����"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("1ū��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("�ĸ��� ġ��"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("�ణ"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("���� �ұݹ��� ���İ�Ƽ���� �ְ� ��� ���� ���� �����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("������ 0.5��Ƽ �β��� �ձ۰� ��� �ұ�, ����, �ø������� �ణ�� �ְ� �������ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("�ҿ� ������ ��¦ ���� ���ÿ� �Ű� ����, �ø������� �ҿ� ��¦ �θ��� ���� ���ð� ���ĸ� �־� ���� �� �� ���� ����, �ұ�, ���߸� �ְ� ���� �����, ���, ������ ���� ���� �־� �����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("3�� �丶�� ���̽�Ʈ�� ��ø�� �ְ� ������ ���� ������ �丶�並 �־� �� �� ����, �ּҽ�, ����� ��, ���� �־� ���̸鼭 �ұ�, ���߷� ���� �ϰ� �������� ���� ���� ������ �������븦 �־� ������ ���·� ����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("��� ���� ���İ�Ƽ���� 4�� �ְ� ������ �������ÿ� ��� ���� ��¥���� ġ��� �ĸ��� ġ� ��� �ۼ� �� ���ĸ� �Ѹ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(5,TEXT("�������ÿ� ���踦 ���� �������ø� �÷��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 16:
		m_MaterialList.InsertItem(0,TEXT("�ڷº�"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("180g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("����ŷ�Ŀ��"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1/2 ������"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("����ŷ �Ҵ�"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1/4 ������"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("�ް�"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("����Ĩ"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("�ڷº�, ����ŷ�Ŀ��, ����ŷ �Ҵٴ� ü�� �Ӵϴ�. üġ�� ������ ���ðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("�ǿ¿� �� ���͸� �� Ǯ�� ũ�� ���¸� ����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("������ �ְ� ���� ������ �� �����ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("�ް��� Ǯ�� ���ݾ� ������ ������ ���Ϳ� �и����� �ʵ��� �绡�� �����ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("üģ ����� ����Ĩ�� �־� ������ �� �⸧ �ٸ� �������ÿ� �������� �ҿ� ������ ������ �ΰ� �� ������ ���� ���� ��ũ�� ������ ���� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(5,TEXT("�������ô� 1�ܿ�, �������� ���� 4�ܿ� ���� �ֽ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(6,TEXT("�������ÿ� �������� ���� �ְ� �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 17:
		m_MaterialList.InsertItem(0,TEXT("ũ��ġ��"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("400g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("�ް�"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("2 1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("�ڷº�"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("��ũ��"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("2 1/2ū��"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("ũ��ġ� ��¿� �ξ� �ε巯�� ���°� �ǵ��� �� �� ��ǰ�⸦ �̿��Ͽ� �� Ǯ���ݴϴ�. �ް��� �̸� Ǯ��Ӵϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("1�� ũ��ġ� ������ �ް��� ���ݾ� ������ �־�� ��ǰ��� �����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("�ε巴�� Ǯ�� ���׿� �ڷºа� ��ũ���� �ְ� �ְ����� ��� �����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("����ũ Ʋ�� �������� ��� �ٴڿ� ī���ڶ� ��Ʈ�� ���� ���� 3�� ������ �׽��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("�������ÿ� ���踦 ���� ����ũƲ�� �ø� �� 1�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 18:
		m_MaterialList.InsertItem(0,TEXT("����"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.4~1.2kg"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("���ڸ� ����� �ձ۰� ������ ũ��� ��� ������ ���� �� ���⸦ �۾�, ������ ��ũ�� ������ �� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("�������� ���� ���踦 ���� ���ڸ� �������� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 19:
		m_MaterialList.InsertItem(0,TEXT("����"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0.8~1.2kg"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("���� �ľ ���⸦ �۰� ������ ���� ���� �߶� ���� �� ������ Į���� ���� �ұ�, ����, û�ֿ� �� 30�� ���� ����ݴϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("�� ������ �ø������� �ٸ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("�������ÿ� ���踦 ���� ���� �����κ��� �Ʒ��� ������ �Ͽ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		m_RecipeList.InsertItem(3,TEXT("���߿� ��ε� �︮�� �ѹ� �������ݴϴ�. �����ܰ�� �����ұ��?"));
		break;
	case 20:
		m_MaterialList.InsertItem(0,TEXT("�����"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("1.0~1.5kg"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("������ ��°�� �����Ͽ� 2~3���� ����� �ڸ� �� Į���� ���� �ұ�, ����, �ø������� ���緮 �Ѹ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("�������� ���� ���踦 ���� ������� �����κ��� �Ʒ��� ������ �Ͽ� 1�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 21:
		m_MaterialList.InsertItem(0,TEXT("���� ������"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("180g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("��������"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1������"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("��������"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("���� ����"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("�丶�� ���̽�Ʈ"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("3ū��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(5,TEXT("�������"));
		m_MaterialList.SetItem(5, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(6,TEXT("��������"));
		m_MaterialList.SetItem(6, 1, LVIF_TEXT, _T("�ణ"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(7,TEXT("����"));
		m_MaterialList.SetItem(7, 1, LVIF_TEXT, _T("1/4��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(8,TEXT("������"));
		m_MaterialList.SetItem(8, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(9,TEXT("��"));
		m_MaterialList.SetItem(9, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(10,TEXT("�����"));
		m_MaterialList.SetItem(10, 1, LVIF_TEXT, _T("2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(11,TEXT("û�Ǹ�"));
		m_MaterialList.SetItem(11, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(12,TEXT("ȫ�Ǹ�"));
		m_MaterialList.SetItem(12, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(13,TEXT("����"));
		m_MaterialList.SetItem(13, 1, LVIF_TEXT, _T("1/4��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(14,TEXT("���ø���"));
		m_MaterialList.SetItem(14, 1, LVIF_TEXT, _T("3��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(15,TEXT("��¥���� ġ��"));
		m_MaterialList.SetItem(15, 1, LVIF_TEXT, _T("150g"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("ũ����Ʈ�� ���� ���� ������� ���� �ְ� ���ױ�� ǥ���� �Ų��������� ġ�� ��, ������ �о �������� �ҿ� �ø��ϴ�.  �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("�ҽ��� ���� �ޱ��� ���� ����, ���ĸ� �ְ� ���� �� ���� ���⸦ �ְ� ���� ��, �丶�����̽�Ʈ�� �ְ� �� ���� �� ������ �װ� ����� ���� �־� ������ ���·� ���̰� �������븦 �־� �� �����ݴϴ�. �������� �ұ�, ���߷� ���մϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("������ ����, �Ǹ�, ����̴� ������ ũ��� �� ��¦ ���ļ� ���⸦ ���� ��, ������, ���� ������ ũ��� �ڸ��ϴ�. �׸���, ��¥���� ġ��� �߰� ������ �ø���� ����� ��� ��� �Ӵϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("1�� ũ����Ʈ �����ڸ� 1��ġ ������ ����� ��� �κ��� ��ũ�� ���ְ�, �����ڸ� 1��ġ ���� �κп� �ø������� ��¦ �߶� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("ũ����Ʈ ��� �κ��� 2�� �ҽ��� �� �� �ٸ��� ��¥���� ġ�� 50�׷��� ��� �Ѹ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(5,TEXT("��, ������, �����, ����, �Ǹ� ������ �����մϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(6,TEXT("���������� ������ ��¥���� ġ� ��� �Ѹ� �� �ø���� ����Ͽ� 4�ܿ� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 22:
		m_MaterialList.InsertItem(0,TEXT("�Ļ�"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("2~4��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("����"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("1ū��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("���� �ҽ�"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("80g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("������"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("��"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(5,TEXT("�����"));
		m_MaterialList.SetItem(5, 1, LVIF_TEXT, _T("2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(6,TEXT("û�Ǹ�"));
		m_MaterialList.SetItem(6, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(7,TEXT("ȫ�Ǹ�"));
		m_MaterialList.SetItem(7, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(8,TEXT("����"));
		m_MaterialList.SetItem(8, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(9,TEXT("���ø���"));
		m_MaterialList.SetItem(9, 1, LVIF_TEXT, _T("3��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(10,TEXT("��¥����"));
		m_MaterialList.SetItem(10, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("������ ������ ���� ����ϴ�. ����,û,ȫ�Ǹ�,����̴� ������ ũ��� �� ������⿡ ��� ���� ���� �����丮������ ������� 2~3�� ������ �� ���⸦ ���۴ϴ�. �̸� ���� �˶� ������ �Ͻðڽ��ϱ�?"));
		m_RecipeList.InsertItem(1,TEXT("������, ���� ������ ũ��� �ڸ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("��¥���� ġ��� �߰� ������ �ø���� ����� ��� ��� �Ӵϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("��� ���͸� �Ļ��� �� �鿡 �ٸ� ��, ���ڼҽ��� �ٸ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(4,TEXT("��, ������, �����, ����, �Ǹ� ������ �����մϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(5,TEXT("��¥���� ġ� ��� �Ѹ� �� �ø���� ����մϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(6,TEXT("�������ÿ� �������� ��� �Ļ��� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	case 23:
		m_MaterialList.InsertItem(0,TEXT("���� ����"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("300g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("���� �������"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("100g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("���� ����"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("2ū��+1������"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(3,TEXT("���� ����"));
		m_MaterialList.SetItem(3, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(4,TEXT("�ް�"));
		m_MaterialList.SetItem(4, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(5,TEXT("������"));
		m_MaterialList.SetItem(5, 1, LVIF_TEXT, _T("30g"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(6,TEXT("����"));
		m_MaterialList.SetItem(6, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(7,TEXT("�콺�� �ҽ�"));
		m_MaterialList.SetItem(7, 1, LVIF_TEXT, _T("1ū��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(8,TEXT("��������"));
		m_MaterialList.SetItem(8, 1, LVIF_TEXT, _T("2ū��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(9,TEXT("����"));
		m_MaterialList.SetItem(9, 1, LVIF_TEXT, _T("1/2��"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("���� �ޱ��� ���� ����, ���ĸ� �ְ� ���� �� �ѱ� �����ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("���� ����, ������⿡ ���� ����, ����, �ް�, ����, ������, �ұ�, ����, ������ �ְ� ���Ⱑ ���� ������ ���� ġ�� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("���Ⱑ ���� ��� ������ 4����Ͽ� 1.5��ġ �β�, ���� 8��ġ�� ���� �����ϰ� ����� ��� �κ��� �����ϰ� ���� �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("�������� �ҿ� �ø������� ������ �θ��� �������� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		m_RecipeList.InsertItem(4,TEXT("���߿� ��ε� �︮�� �ѹ� ������ �ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(5,TEXT("���� �ޱ��� ���� ����, ���ĸ� �ְ� ���� �� ��ø�� �־� ��� ���̵��� ���� �ݴϴ�. �콺�� �ҽ�, ��������, ������ ���� �� �̺��� �Ϸ� �ɶ����� ���Դϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(6,TEXT("������ ���ݾ� �־� ���� ������ �� �ұ�, ���߷� ���Ͽ� �������� ü�� �ɷ� �ܹ��� ������ũ�� ��鿩 ���ϴ�. �����ܰ�� �����ұ��?"));
		break;
	case 24:
		m_MaterialList.InsertItem(0,TEXT("�Ļ�"));
		m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("1��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(1,TEXT("��"));
		m_MaterialList.SetItem(1, 1, LVIF_TEXT, _T("3ū��"), 0, 0, 0, NULL );
		m_MaterialList.InsertItem(2,TEXT("����"));
		m_MaterialList.SetItem(2, 1, LVIF_TEXT, _T("1ū��"), 0, 0, 0, NULL );

		m_RecipeList.InsertItem(0,TEXT("�� �Ļ��� ������ �ڸ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(1,TEXT("�Ļ��� ���� ���� ���� ���� �Ͽ� �عٴڿ� ������ ���� �ʰ� ������ Į���� �־��ݴϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(2,TEXT("Į���� �� �κп� ���� �ְ� �Ļ� �޸鿡 ���͸� �ٸ��ϴ�. �����ܰ�� �����ұ��?"));
		m_RecipeList.InsertItem(3,TEXT("�������ÿ� �������� ��� �Ļ��� �ø� �� �־��ּ���. �غ�ǽø� �����̶�� �������ּ���."));
		break;
	}
	//m_MaterialList.InsertItem(0,TEXT("��Ϻ극��"));
	//m_MaterialList.SetItem(0, 1, LVIF_TEXT, _T("0�� 1��"), 0, 0, 0, NULL );
	*pResult = 0;
}


//void CTab2::OnNMDblclkList3(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;
//	index2 = pNMItemActivate->iItem;
//	indexsub = pNMItemActivate->iSubItem;
//
//	CString recipelog=m_RecipeList.GetItemText(index2, indexsub);
//	//char* recipe= NULL;
//	switch(index2)
//	{
//	case 0:
//		//recipe="���ڴ� ��� ����� �غ��մϴ�.";
//		break;
//	}
//	wchar_t* wchar_str;     //ù��° �ܰ�(CString to wchar_t*)�� ���� ����
//	char*    char_str;      //char* ���� ����
//	int      char_str_len;  //char* �� ������ ���̸� ���� ����
//
//	//1. CString to wchar_t* conversion
//	wchar_str = recipelog.GetBuffer(recipelog.GetLength());
//
//	//2. wchar_t* to char* conversion
//	//char* ���� ���ѱ��̸� ����
//	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
//	char_str = new char[char_str_len];  //�޸� �Ҵ�
//	//wchar_t* to char* conversion
//	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  
//
//	if(__ClipCopy2(char_str))
//	{
//		AfxMessageBox(TEXT("�����ǰ� Ŭ�����忡 ����Ǿ����ϴ�"));
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
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;
//	index2 =  pNMView->iItem;
//	indexsub =  pNMView->iSubItem;
//
//	CString recipelog=m_RecipeList.GetItemText(index2, indexsub);
//	//char* recipe= NULL;
//	switch(index2)
//	{
//	case 0:
//		//recipe="���ڴ� ��� ����� �غ��մϴ�.";
//		break;
//	}
//	wchar_t* wchar_str;     //ù��° �ܰ�(CString to wchar_t*)�� ���� ����
//	char*    char_str;      //char* ���� ����
//	int      char_str_len;  //char* �� ������ ���̸� ���� ����
//
//	//1. CString to wchar_t* conversion
//	wchar_str = recipelog.GetBuffer(recipelog.GetLength());
//
//	//2. wchar_t* to char* conversion
//	//char* ���� ���ѱ��̸� ����
//	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
//	char_str = new char[char_str_len];  //�޸� �Ҵ�
//	//wchar_t* to char* conversion
//	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  
//
//	if(__ClipCopy2(char_str))
//	{
//		AfxMessageBox(TEXT("�����ǰ� Ŭ�����忡 ����Ǿ����ϴ�"));
//	}
//	*pResult = 0;
//}


void CTab2::OnNMDblclkList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	NM_LISTVIEW* pNMView = (NM_LISTVIEW*)pNMHDR;
	index2 = pNMItemActivate->iItem;
	indexsub = pNMItemActivate->iSubItem;

	CString recipelog=m_RecipeList.GetItemText(index2, indexsub);
	//char* recipe= NULL;
	switch(index2)
	{
	case 0:
		//recipe="���ڴ� ��� ����� �غ��մϴ�.";
		break;
	}
	wchar_t* wchar_str;     //ù��° �ܰ�(CString to wchar_t*)�� ���� ����
	char*    char_str;      //char* ���� ����
	int      char_str_len;  //char* �� ������ ���̸� ���� ����

	//1. CString to wchar_t* conversion
	wchar_str = recipelog.GetBuffer(recipelog.GetLength());

	//2. wchar_t* to char* conversion
	//char* ���� ���ѱ��̸� ����
	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
	char_str = new char[char_str_len];  //�޸� �Ҵ�
	//wchar_t* to char* conversion
	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  

	if(__ClipCopy2(char_str))
	{
		AfxMessageBox(TEXT("�����ǰ� Ŭ�����忡 ����Ǿ����ϴ�"));
	}
	*pResult = 0;
}


//void CTab2::OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	*pResult = 0;
//}


void CTab2::OnNMClickList3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	index2 = pNMItemActivate->iItem;
	indexsub = pNMItemActivate->iSubItem;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

	wchar_t* wchar_str;     //ù��° �ܰ�(CString to wchar_t*)�� ���� ����
	char*    char_str;      //char* ���� ����
	int      char_str_len;  //char* �� ������ ���̸� ���� ����

	//1. CString to wchar_t* conversion
	wchar_str = materials.GetBuffer(materials.GetLength());

	//2. wchar_t* to char* conversion
	//char* ���� ���ѱ��̸� ����
	char_str_len = WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, NULL, 0, NULL, NULL);
	char_str = new char[char_str_len];  //�޸� �Ҵ�
	//wchar_t* to char* conversion
	WideCharToMultiByte(CP_ACP, 0, wchar_str, -1, char_str, char_str_len, 0,0);  

	if(__ClipCopy2(char_str))
	{
		AfxMessageBox(TEXT("��ᰡ Ŭ�����忡 ����Ǿ����ϴ�"));
	}
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
