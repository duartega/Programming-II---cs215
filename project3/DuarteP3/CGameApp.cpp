/*********************************************************************
* Assignment: Project 3 - GUI Move and Match Game                    *
* Author: Gabriel Duarte                                             *
* Date: Fall 2017                                                    *
* File: CGameApp.cpp                                                 *
*                                                                    *
* Description: This file contains the window                         *
*********************************************************************/

#include <afxwin.h>
#include "CGameApp.h"

/*********************************************************************
* Function: InitInstance ()                                          *
*                                                                    *
* Parameters: None                                                   *
* Return value: True                                                 *
* Description: This function will allow us to create a window.       *
*********************************************************************/

BOOL CGameApp::InitInstance ()
{
		m_pMainWnd = new CGameWin();
		m_pMainWnd->ShowWindow (m_nCmdShow);
		m_pMainWnd->UpdateWindow ();

		return TRUE;
}

CGameApp CGameApp;
