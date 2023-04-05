
// MFCAppKompasDlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CMFCAppKompasDlg
class CMFCAppKompasDlg : public CDialogEx
{
// Создание
public:
	CMFCAppKompasDlg(CWnd* pParent = nullptr);	// стандартный конструктор


// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPKOMPAS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	bool CheckData();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	double m_Dup;
	double m_Ddown;
	double m_L;
	double m_L1;
	double m_L2;
	double m_L3;
	double m_D1;
	double m_B1;
	double Otstup = m_L1 - m_L - m_L3;
	double m_B;
	double m_Dzv;
	double m_dzv;
	double m_Hzv;
	double m_Bzv;
	double m_b;
	double m_dt1;
};
