
// SimplePlayerSDKWin32Demo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSimplePlayerSDKWin32DemoApp: 
// �йش����ʵ�֣������ SimplePlayerSDKWin32Demo.cpp
//

class CSimplePlayerSDKWin32DemoApp : public CWinApp
{
public:
	CSimplePlayerSDKWin32DemoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSimplePlayerSDKWin32DemoApp theApp;