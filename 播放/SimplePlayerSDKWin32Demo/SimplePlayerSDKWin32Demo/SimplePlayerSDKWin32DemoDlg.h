
// SimplePlayerSDKWin32DemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "SimplePlayerSDK.h"

// CSimplePlayerSDKWin32DemoDlg �Ի���
class CSimplePlayerSDKWin32DemoDlg : public CDialogEx
{
// ����
public:
	CSimplePlayerSDKWin32DemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SIMPLEPLAYERSDKWIN32DEMO_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	CEdit m_url;
	SimplePlayerSDK m_player;
	afx_msg void OnEnChangeEdit3();
	CEdit m_rotate;
};
