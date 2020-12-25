
// SimplePublisherSDKWin32DemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "SimplePublisherSDK.h"

// CSimplePublisherSDKWin32DemoDlg �Ի���
class CSimplePublisherSDKWin32DemoDlg : public CDialogEx
{
// ����
public:
	CSimplePublisherSDKWin32DemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SIMPLEPUBLISHERSDKWIN32DEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
};
