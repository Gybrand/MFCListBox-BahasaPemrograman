
// MFCApplication11Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication11.h"
#include "MFCApplication11Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication11Dlg dialog



CMFCApplication11Dlg::CMFCApplication11Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION11_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication11Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_daftarkota);
	DDX_Control(pDX, IDC_LIST3, m_pilihankota);
}

BEGIN_MESSAGE_MAP(CMFCApplication11Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST3, &CMFCApplication11Dlg::OnLbnSelchangeList3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication11Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication11Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCApplication11Dlg message handlers

BOOL CMFCApplication11Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.
	m_daftarkota.AddString("Surabaya");
	m_daftarkota.AddString("Gresik");
	m_daftarkota.AddString("Lamongan");
	m_daftarkota.AddString("Malang");
	m_daftarkota.AddString("Sidoarjo");
	m_daftarkota.AddString("Probolinggo");
	m_daftarkota.AddString("Situbondo");
	m_daftarkota.AddString("Banyuwangi");
	m_daftarkota.AddString("Magetan");
	m_daftarkota.AddString("Madiun");
	m_daftarkota.AddString("Jombang");
	m_daftarkota.AddString("Blitar");
	m_daftarkota.SetCurSel(0);
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication11Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication11Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication11Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication11Dlg::OnLbnSelchangeList3()
{
	// TODO: Add your control notification handler code here
}


void CMFCApplication11Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CString skota;
	m_daftarkota.GetText(m_daftarkota.GetCurSel(), skota);
	m_daftarkota.DeleteString(m_daftarkota.GetCurSel());
	m_daftarkota.SetCurSel(0);
	m_pilihankota.InsertString(m_pilihankota.GetCurSel(), skota);

}


void CMFCApplication11Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString skota;
	m_pilihankota.SetCurSel(m_daftarkota.GetCurSel());
	m_pilihankota.GetText(m_pilihankota.GetCurSel(), skota);
	m_pilihankota.DeleteString(m_pilihankota.GetCurSel());
	m_pilihankota.SetCurSel(0);
	m_daftarkota.InsertString(m_daftarkota.GetCurSel(), skota);
}
