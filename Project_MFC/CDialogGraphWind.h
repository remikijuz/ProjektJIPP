#pragma once
#include "afxdialogex.h"


class CDialogGraphWind : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogGraphWind)

public:
	CDialogGraphWind(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDialogGraphWind();

	
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_GRAPHWIND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);   

	DECLARE_MESSAGE_MAP()
public:
	int PointRad;
	LOGFONT lf;
	afx_msg void OnClickedButtonFont();
};
