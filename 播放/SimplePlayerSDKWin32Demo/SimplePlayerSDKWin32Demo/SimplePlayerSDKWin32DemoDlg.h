
// SimplePlayerSDKWin32DemoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "SimplePlayerSDK.h"

// CSimplePlayerSDKWin32DemoDlg 对话框
class CSimplePlayerSDKWin32DemoDlg : public CDialogEx
{
// 构造
public:
	CSimplePlayerSDKWin32DemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SIMPLEPLAYERSDKWIN32DEMO_DIALOG };

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
	afx_msg void OnBnClickedButton1();
	CEdit m_url;
	SimplePlayerSDK m_player;
	afx_msg void OnEnChangeEdit3();
	CEdit m_rotate;
	CEdit m_recordPath;
	afx_msg void OnBnClickedButton2();
	CEdit m_picturepath;
	afx_msg void OnBnClickedButton3();
};
