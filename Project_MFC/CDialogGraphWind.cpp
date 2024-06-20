#include "pch.h"
#include "Project_MFC.h"
#include "afxdialogex.h"
#include "CDialogGraphWind.h"


// CDialogGraphWind dialog

IMPLEMENT_DYNAMIC(CDialogGraphWind, CDialogEx)

CDialogGraphWind::CDialogGraphWind(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_GRAPHWIND, pParent)
	, PointRad(0)
{

}

CDialogGraphWind::~CDialogGraphWind()
{
}

void CDialogGraphWind::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RADIUS, PointRad);
}


BEGIN_MESSAGE_MAP(CDialogGraphWind, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_FONT, &CDialogGraphWind::OnClickedButtonFont)
END_MESSAGE_MAP()




void CDialogGraphWind::OnClickedButtonFont()
{
	CFontDialog dlg;
	dlg.DoModal();
	dlg.GetCurrentFont(&lf);
}

