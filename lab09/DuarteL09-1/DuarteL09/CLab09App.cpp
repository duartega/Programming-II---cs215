#include <afxwin.h>
#include "CLab09App.h"

BOOL CLab09App::InitInstance()
{
	m_pMainWnd = new CLab09Win();
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return true;
}

CLab09App Lab09App;