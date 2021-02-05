
// SimplePlayerSDKWin32DemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SimplePlayerSDKWin32Demo.h"
#include "SimplePlayerSDKWin32DemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimplePlayerSDKWin32DemoDlg �Ի���



CSimplePlayerSDKWin32DemoDlg::CSimplePlayerSDKWin32DemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSimplePlayerSDKWin32DemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimplePlayerSDKWin32DemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_url);
}

BEGIN_MESSAGE_MAP(CSimplePlayerSDKWin32DemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSimplePlayerSDKWin32DemoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CSimplePlayerSDKWin32DemoDlg ��Ϣ�������

BOOL CSimplePlayerSDKWin32DemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MAXIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_url.SetWindowTextW(_T("rtmp://58.200.131.2:1935/livetv/cctv1"));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSimplePlayerSDKWin32DemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSimplePlayerSDKWin32DemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSimplePlayerSDKWin32DemoDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	static bool flag = true;
	if (flag) {
		CString url;
		m_url.GetWindowTextW(url);
		int iLen = WideCharToMultiByte(CP_ACP, 0, url, -1, NULL, 0, NULL, NULL);

		char* chRtn = new char[iLen * sizeof(char)];

		WideCharToMultiByte(CP_ACP, 0, url, -1, chRtn, iLen, NULL, NULL);
		m_player.setPlayUrl(chRtn);
		HWND   playWnd = ::GetDlgItem(GetSafeHwnd(), IDC_STATIC);
		m_player.setPlayWnd(playWnd);
		m_player.play();
		GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("ֹͣ"));
	}
	else
	{
		m_player.stop();
		GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("����"));
	}
	flag = !flag;
}
