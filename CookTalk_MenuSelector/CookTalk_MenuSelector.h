
// CookTalk_MenuSelector.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCookTalk_MenuSelectorApp:
// �� Ŭ������ ������ ���ؼ��� CookTalk_MenuSelector.cpp�� �����Ͻʽÿ�.
//

class CCookTalk_MenuSelectorApp : public CWinApp
{
public:
	CCookTalk_MenuSelectorApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCookTalk_MenuSelectorApp theApp;