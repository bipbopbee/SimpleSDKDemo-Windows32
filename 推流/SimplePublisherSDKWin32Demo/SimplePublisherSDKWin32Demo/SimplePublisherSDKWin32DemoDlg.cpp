
// SimplePublisherSDKWin32DemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SimplePublisherSDKWin32Demo.h"
#include "SimplePublisherSDKWin32DemoDlg.h"
#include "afxdialogex.h"
#include "afxpriv.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSimplePublisherSDKWin32DemoDlg �Ի���



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


// CSimplePublisherSDKWin32DemoDlg ��Ϣ�������

BOOL CSimplePublisherSDKWin32DemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MINIMIZE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	m_capturesource.AddString(_T("����"));
	m_capturesource.AddString(_T("����ͷ"));
	

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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSimplePublisherSDKWin32DemoDlg::OnPaint()
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
HCURSOR CSimplePublisherSDKWin32DemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSimplePublisherSDKWin32DemoDlg::OnBnClickedCheck1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CSimplePublisherSDKWin32DemoDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
			m_publisher.selectAudioSource(0);//������
		}
		else
		{
			m_publisher.setEnableAudio(false);
		}
		m_publisher.setPushType(1);//0��RTSP 1:RTMP
		m_publisher.startPush();
		GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("ֹͣ"));
	}
	else
	{
		m_publisher.stopPush();
		GetDlgItem(IDC_BUTTON1)->SetWindowTextW(_T("����"));
	}
	rtmpflag = !rtmpflag;
}


void CSimplePublisherSDKWin32DemoDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

		m_publisher.setPushType(0);//0��RTSP 1:RTMP
		m_publisher.startPush();
		char* tempurl = m_publisher.getUrl();
		m_rtspUrl.SetWindowTextW(CString(tempurl));
		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("ֹͣ"));
	}
	else
	{
		m_publisher.stopPush();
		m_rtspUrl.SetWindowTextW(CString(""));
		GetDlgItem(IDC_BUTTON2)->SetWindowTextW(_T("����"));
	}
	flag = !flag;
}


void CSimplePublisherSDKWin32DemoDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CSimplePublisherSDKWin32DemoDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CSimplePublisherSDKWin32DemoDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CSimplePublisherSDKWin32DemoDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_publisher.setCameraIndex(m_cameraid);
	
	m_publisher.setPreviewWindow(GetDlgItem(IDC_PREVIEW)->GetSafeHwnd());
	//m_publisher.setPreviewWindow(m_hWnd);
	m_publisher.startPreview();
}


void CSimplePublisherSDKWin32DemoDlg::OnCbnSelchangeCombo3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_cameraid = m_cameraList.GetCurSel();
	m_publisher.setCaptureType(1);//0:���� 1������ͷ
}
