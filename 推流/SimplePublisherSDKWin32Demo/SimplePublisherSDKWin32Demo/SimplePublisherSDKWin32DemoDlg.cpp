
// SimplePublisherSDKWin32DemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "SimplePublisherSDKWin32Demo.h"
#include "SimplePublisherSDKWin32DemoDlg.h"
#include "afxdialogex.h"
#include "afxpriv.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimplePublisherSDKWin32DemoDlg 对话框



CSimplePublisherSDKWin32DemoDlg::CSimplePublisherSDKWin32DemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSimplePublisherSDKWin32DemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimplePublisherSDKWin32DemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_rtmpUrl);
	DDX_Control(pDX, IDC_COMBO1, m_encodeType);
	DDX_Control(pDX, IDC_COMBO2, m_encodeType2);
	DDX_Control(pDX, IDC_CHECK1, m_audioCheck);
	DDX_Control(pDX, IDC_EDIT2, m_rtmpRate);
	DDX_Control(pDX, IDC_EDIT3, m_rtmpFrameRate);
	DDX_Control(pDX, IDC_EDIT4, m_rtspRate);
	DDX_Control(pDX, IDC_EDIT5, m_rtspFrameRate);
	DDX_Control(pDX, IDC_EDIT6, m_rtspPort);
	DDX_Control(pDX, IDC_EDIT7, m_rtspStream);
	DDX_Control(pDX, IDC_EDIT8, m_rtspUrl);
	DDX_Control(pDX, IDC_COMBO3, m_capturesource);
	DDX_Control(pDX, IDC_COMBO4, m_cameraList);
}

BEGIN_MESSAGE_MAP(CSimplePublisherSDKWin32DemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CSimplePublisherSDKWin32DemoDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, &CSimplePublisherSDKWin32DemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSimplePublisherSDKWin32DemoDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &CSimplePublisherSDKWin32DemoDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CSimplePublisherSDKWin32DemoDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CSimplePublisherSDKWin32DemoDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON3, &CSimplePublisherSDKWin32DemoDlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO3, &CSimplePublisherSDKWin32DemoDlg::OnCbnSelchangeCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CSimplePublisherSDKWin32DemoDlg::OnCbnSelchangeCombo4)
END_MESSAGE_MAP()


// CSimplePublisherSDKWin32DemoDlg 消息处理程序

BOOL CSimplePublisherSDKWin32DemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MINIMIZE);

	// TODO:  在此添加额外的初始化代码

	m_capturesource.AddString(_T("桌面"));
	m_capturesource.AddString(_T("摄像头"));
	

	m_encodeType.AddString(_T("H264"));
	m_encodeType.AddString(_T("H265"));
	m_encodeType2.AddString(_T("H264"));
	m_encodeType2.AddString(_T("H265"));

	m_capturesource.SetCurSel(0);
	m_encodeType.SetCurSel(0);
	m_encodeType2.SetCurSel(0);

	m_rtmpRate.SetWindowTextW(_T("4"));
	m_rtmpFrameRate.SetWindowTextW(_T("25"));
	m_rtmpUrl.SetWindowTextW(_T("rtmp://192.168.0.102:1935/live/livestream"));

	m_rtspRate.SetWindowTextW(_T("4"));
	m_rtspFrameRate.SetWindowTextW(_T("25"));
	m_rtspPort.SetWindowTextW(_T("8554"));
	m_rtspStream.SetWindowTextW(_T("livestream"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSimplePublisherSDKWin32DemoDlg::OnPaint()
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
HCURSOR CSimplePublisherSDKWin32DemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSimplePublisherSDKWin32DemoDlg::OnBnClickedCheck1()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CSimplePublisherSDKWin32DemoDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	static bool rtmpflag = true;
	if (rtmpflag) {
		CString url;
		CString rate;
		CString framerate;
		bool isH264;
		bool isAudio;

		m_rtmpUrl.GetWindowTextW(url);
		m_rtmpRate.GetWindowTextW(rate);
		m_rtmpFrameRate.GetWindowTextW(framerate);

		int iLen = WideCharToMultiByte(CP_ACP, 0, (LPCTSTR)url, -1, NULL, 0, NULL, NULL);

		char* chRtn = new char[iLen * sizeof(char)];

		WideCharToMultiByte(CP_ACP, 0, (LPCTSTR)url, -1, chRtn, iLen, NULL, NULL);
		m_publisher.setRtmpUrl(chRtn);


		//m_publisher.setEncodeRate(_ttoi(rate));
		//m_publisher.setFrameRate(_ttoi(framerate));
		if (m_encodeType.GetCurSel() == 1)
			isH264 = false;
		else
			isH264 = true;
		if (isH264)
			m_publisher.setEncodeType(0);
		else
			m_publisher.setEncodeType(1);
		if (m_audioCheck.GetCheck())
		{
			m_publisher.setEnableAudio(true);
			m_publisher.selectAudioSource(0);//扬声器
		}
		else
		{
			m_publisher.setEnableAudio(false);
		}
		m_publisher.setPushType(1);//0，RTSP 1:RTMP
		m_publisher.startPush();
		GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("停止"));
	}
	else
	{
		m_publisher.stopPush();
		GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("发布"));
	}
	rtmpflag = !rtmpflag;
}


void CSimplePublisherSDKWin32DemoDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	static bool flag = true;
	if (flag) {
		CString url;
		CString rate;
		CString framerate;
		CString port;
		CString streamname;
		bool isH264;
		bool isAudio;

		m_rtspUrl.GetWindowTextW(url);
		m_rtspRate.GetWindowTextW(rate);
		m_rtspFrameRate.GetWindowTextW(framerate);
		m_rtspPort.GetWindowTextW(port);
		m_rtspStream.GetWindowTextW(streamname);


		int iLen = WideCharToMultiByte(CP_ACP, 0, (LPCTSTR)streamname, -1, NULL, 0, NULL, NULL);

		char* chRtn = new char[iLen * sizeof(char)];

		WideCharToMultiByte(CP_ACP, 0, (LPCTSTR)streamname, -1, chRtn, iLen, NULL, NULL);



		m_publisher.setEncodeRate(_ttoi(rate));
		m_publisher.setFrameRate(_ttoi(framerate));
		m_publisher.setRtspPort(_ttoi(port));
		m_publisher.setRtspStream(chRtn);
		if (m_encodeType2.GetCurSel() == 1)
			isH264 = false;
		else
			isH264 = true;
		if (isH264)
			m_publisher.setEncodeType(0);
		else
			m_publisher.setEncodeType(1);

		m_publisher.setPushType(0);//0，RTSP 1:RTMP
		m_publisher.startPush();
		char* tempurl = m_publisher.getUrl();
		m_rtspUrl.SetWindowTextW(CString(tempurl));
		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("停止"));
	}
	else
	{
		m_publisher.stopPush();
		m_rtspUrl.SetWindowTextW(CString(""));
		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("发布"));
	}
	flag = !flag;
}


void CSimplePublisherSDKWin32DemoDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSimplePublisherSDKWin32DemoDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CSimplePublisherSDKWin32DemoDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CSimplePublisherSDKWin32DemoDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_publisher.setCameraIndex(m_cameraid);
	
	m_publisher.setPreviewWindow(GetDlgItem(IDC_PREVIEW)->GetSafeHwnd());
	//m_publisher.setPreviewWindow(m_hWnd);
	m_publisher.startPreview();
}


void CSimplePublisherSDKWin32DemoDlg::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_capturesource.GetCurSel() == 1)
	{
		std::map<int, std::string> camralist = m_publisher.getCameraList();
		std::map<int, std::string>::iterator ite;
		for (ite = camralist.begin(); ite != camralist.end(); ite++)
		{
			std::string name = ite->second;
			m_cameraList.AddString((LPCTSTR)name.c_str());
		}
	}
	else 
	{
		m_publisher.setCaptureType(0);
	}
}


void CSimplePublisherSDKWin32DemoDlg::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_cameraid = m_cameraList.GetCurSel();
	m_publisher.setCaptureType(1);//0:桌面 1：摄像头
}
