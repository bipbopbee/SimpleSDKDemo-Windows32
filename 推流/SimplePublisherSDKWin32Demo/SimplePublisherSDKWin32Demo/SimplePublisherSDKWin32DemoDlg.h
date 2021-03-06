
// SimplePublisherSDKWin32DemoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "SimplePublisherSDK.h"

// CSimplePublisherSDKWin32DemoDlg 对话框
class CSimplePublisherSDKWin32DemoDlg : public CDialogEx
{
// 构造
public:
	CSimplePublisherSDKWin32DemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SIMPLEPUBLISHERSDKWIN32DEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit m_rtmpUrl;
	CComboBox m_encodeType;
	CComboBox m_encodeType2;
	CButton m_audioCheck;
	afx_msg void OnEnChangeEdit2();
	CEdit m_rtmpRate;
	afx_msg void OnEnChangeEdit3();
	CEdit m_rtmpFrameRate;
	afx_msg void OnEnChangeEdit4();
	CEdit m_rtspRate;
	CEdit m_rtspFrameRate;
	CEdit m_rtspPort;
	CEdit m_rtspStream;
	CEdit m_rtspUrl;
	SimplePublisherSDK m_publisher;
	int m_cameraid;
	CComboBox m_capturesource;
	CComboBox m_cameraList;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnBnClickedButton4();
	CEdit m_recordpath;
};
