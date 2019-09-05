
// sentkbDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "sentkb.h"
#include "sentkbDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsentkbDlg 对话框



CsentkbDlg::CsentkbDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CsentkbDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsentkbDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CsentkbDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CsentkbDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CsentkbDlg 消息处理程序

BOOL CsentkbDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CsentkbDlg::OnPaint()
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
HCURSOR CsentkbDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CsentkbDlg::OnBnClickedButton1()
{
	//HWND hWnd = ::FindWindow(L"Qt5QWindowIcon", L"英雄传说：星之轨迹 - MuMu模拟器");
	HWND hWnd = ::FindWindow(L"Notepad", nullptr);
	if (hWnd)
	{
		HWND hEdit = ::FindWindowEx(hWnd, nullptr, L"Qt5QWindowIcon", nullptr);
		//keybd_event(,);
#if 0
		::PostMessage(hWnd, WM_KEYDOWN, 'B', 0);
		Sleep(100);
		::PostMessage(hWnd, WM_KEYUP, 'B', 0);
		Sleep(200);
		::PostMessage(hWnd, WM_KEYDOWN, 'A', 0);
		Sleep(100);
		::PostMessage(hWnd, WM_KEYUP, 'A', 0);
		Sleep(200);
		::PostMessage(hEdit, WM_KEYDOWN, 'B', 0);
		Sleep(100);
		::PostMessage(hEdit, WM_KEYUP, 'B', 0);
		Sleep(200);
		::PostMessage(hEdit, WM_KEYDOWN, 'A', 0);
		Sleep(100);
		::PostMessage(hEdit, WM_KEYUP, 'A', 0);
		Sleep(200);
#else
		int res = ::SendMessage(hWnd, WM_KEYDOWN, 'B', 0);
		Sleep(100);
		res = ::SendMessage(hWnd, WM_KEYUP, 'B', 0);
		Sleep(200);
		res = ::SendMessage(hWnd, WM_KEYDOWN, 'A', 0);
		Sleep(100);
		res = ::SendMessage(hWnd, WM_KEYUP, 'A', 0);
		Sleep(200);
		res = ::SendMessage(hEdit, WM_KEYDOWN, 'B', 0);
		Sleep(100);
		res = ::SendMessage(hEdit, WM_KEYUP, 'B', 0);
		Sleep(200);
		res = ::SendMessage(hEdit, WM_KEYDOWN, 'A', 0);
		Sleep(100);
		res = ::SendMessage(hEdit, WM_KEYUP, 'A', 0);
		Sleep(200);
#endif
		/*HWND hEdits = ::FindWindowEx(hWnd, nullptr, L"Qt5QWindowIcon", nullptr);
		HWND hEdit = ::FindWindowEx(hEdits, nullptr, L"canvasWin", nullptr);*/
	}
	else
	{
		AfxMessageBox(L"请打开记事本文件！");
		return;
	}
}
