
// SimplePublisherSDKWin32Demo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSimplePublisherSDKWin32DemoApp: 
// �йش����ʵ�֣������ SimplePublisherSDKWin32Demo.cpp
//

class CSimplePublisherSDKWin32DemoApp : public CWinApp
{
public:
	CSimplePublisherSDKWin32DemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	afx_msg void OnCbnSelchangeCombo3();
};

extern CSimplePublisherSDKWin32DemoApp theApp;