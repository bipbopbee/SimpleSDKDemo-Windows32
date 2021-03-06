
// SimplePlayerSDKWin32DemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SimplePlayerSDKWin32Demo.h"
#include "SimplePlayerSDKWin32DemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimplePlayerSDKWin32DemoDlg 对话框



CSimplePlayerSDKWin32DemoDlg::CSimplePlayerSDKWin32DemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSimplePlayerSDKWin32DemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimplePlayerSDKWin32DemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_url);
	DDX_Control(pDX, IDC_EDIT3, m_rotate);
	DDX_Control(pDX, IDC_EDIT4, m_recordPath);
	DDX_Control(pDX, IDC_EDIT5, m_picturepath);
}

BEGIN_MESSAGE_MAP(CSimplePlayerSDKWin32DemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CSimplePlayerSDKWin32DemoDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT3, &CSimplePlayerSDKWin32DemoDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON2, &CSimplePlayerSDKWin32DemoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSimplePlayerSDKWin32DemoDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CSimplePlayerSDKWin32DemoDlg 消息处理程序

BOOL CSimplePlayerSDKWin32DemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	// TODO:  在此添加额外的初始化代码
	m_url.SetWindowTextW(_T("rtmp://58.200.131.2:1935/livetv/cctv1"));
	m_recordPath.SetWindowTextW(_T("D:\\record.mp4"));
	m_picturepath.SetWindowTextW(_T("D:"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSimplePlayerSDKWin32DemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSimplePlayerSDKWin32DemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSimplePlayerSDKWin32DemoDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	static bool flag = true;
	if (flag) {
		CString url;
		CString degree;
		m_url.GetWindowTextW(url);
		int iLen = WideCharToMultiByte(CP_ACP, 0, url, -1, NULL, 0, NULL, NULL);
		char* chRtn = new char[iLen * sizeof(char)];

		WideCharToMultiByte(CP_ACP, 0, url, -1, chRtn, iLen, NULL, NULL);
		m_player.setPlayUrl(chRtn);
		m_rotate.GetWindowTextW(degree);
		int i_degree = _ttoi(degree);
		if (i_degree > 0)
		{
			m_player.setRotate(i_degree);
		}
		HWND   playWnd = ::GetDlgItem(GetSafeHwnd(), IDC_STATIC);
		m_player.setPlayWnd(playWnd);
		m_player.play();
		GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("停止"));
	}
	else
	{
		m_player.stop();
		GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("播放"));
	}
	flag = !flag;
}


void CSimplePlayerSDKWin32DemoDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSimplePlayerSDKWin32DemoDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	static bool recordflag = true;
	if (recordflag)
	{
		CString recordpath;
		CString degree;
		m_recordPath.GetWindowTextW(recordpath);
		int iLen = WideCharToMultiByte(CP_ACP, 0, recordpath, -1, NULL, 0, NULL, NULL);
		char* chRtn = new char[iLen * sizeof(char)];

		WideCharToMultiByte(CP_ACP, 0, recordpath, -1, chRtn, iLen, NULL, NULL);
		m_player.setRecordPath(chRtn);
		m_player.setEnableRecord(true);
		m_player.startRecord();
		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("停止录制"));
	}
	else
	{
		m_player.stopRecord();
		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("开始录制"));
	}
	recordflag = !recordflag;
}


void CSimplePlayerSDKWin32DemoDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString picturepath;
	m_picturepath.GetWindowTextW(picturepath);
	int iLen = WideCharToMultiByte(CP_ACP, 0, picturepath, -1, NULL, 0, NULL, NULL);
	char* chRtn = new char[iLen * sizeof(char)];

	WideCharToMultiByte(CP_ACP, 0, picturepath, -1, chRtn, iLen, NULL, NULL);
	m_player.setBitmapPath(chRtn);
	m_player.captureBitmap();
}
