/*********************************************************************
* Assignment: Project 3 - GUI Move and Match Game                    *
* Author: Gabriel Duarte                                             *
* Date: Fall 2017                                                    *
* File: CGameWin.cpp                                                 *
*                                                                    *
* Description: This file contains the                                *
*********************************************************************/

#include <afxwin.h>
#include "CGameWin.h"

/*********************************************************************
* Function:  CGameWin ()                                             *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will set the window title.              *
*********************************************************************/

CGameWin::CGameWin ()
{
	CString WindowTitle = "Match 'Em All";
	Create (NULL, WindowTitle);
	firstTime = true;
}

/************************************************************************
* Function: OnPaint ()                                                  *
*                                                                       *
* Parameters: None                                                      *
* Return value: None                                                    *
* Description: This function will displays the instructions message box.*
************************************************************************/

afx_msg void CGameWin::OnPaint ()
{
	myCGame.Display (this);
	if (firstTime)
	{
		myCGame.Instructions(this);
		firstTime = false;
		SetTimer (1, 1000, NULL);
	}
}

/*********************************************************************
* Function: OnLButtonDown( UINT nFlags, CPoint point )               *
*                                                                    *
* Parameters: UINT nFlags, CPoint point                              *
* Return value: None                                                 *
* Description: This function will gets the click point.              *
*********************************************************************/

afx_msg void CGameWin::OnLButtonDown( UINT nFlags, CPoint point )
{
	myCGame.Click (point.y, point.x, this);
}

/*********************************************************************
* Function: OnKeyDown (UINT achar, UINT repeat, UINT flags)          *
*                                                                    *
* Parameters: UINT achar, UINT repeat, UINT flags                    *
* Return value: None                                                 *
* Description: This function will checks to see key pushes.          *
*********************************************************************/

afx_msg void CGameWin::OnKeyDown (UINT achar, UINT repeat, UINT flags)
{
	switch(achar)
    {
		case VK_LEFT: case 'A':
			myCGame.Move ('a', this);
			break;
		case VK_RIGHT: case 'D':
			myCGame.Move ('d', this);
			break;
		case VK_UP: case 'W':
			myCGame.Move ('w', this);
			break;
		case VK_DOWN: case 'S':
			myCGame.Move ('s', this);
			break;
		default:
			myCGame.KeyDown(tolower(achar), this);
	}
}

/*********************************************************************
* Function: OnTimer (UINT nIDEvent)                                  *
*                                                                    *
* Parameters: UINT nIDEvent                                          *
* Return value: None                                                 *
* Description: This function will call both functions for timers.    *
*********************************************************************/

afx_msg void CGameWin::OnTimer (UINT nIDEvent)
{	
	if (nIDEvent == 1)
		myCGame.UpdateTime (this);  
	if (nIDEvent == 2)
		myCGame.TimerEvaluateAndUpdate (this); 
}

/*********************************************************************
* Function: MESSAGE_MAP                                              *
*                                                                    *
* Parameters: CGameWin, CFrameWnd                                    *
* Return value: None                                                 *
* Description: This function will allow us to use the functions      *
*              we created.                                           *
*********************************************************************/

BEGIN_MESSAGE_MAP (CGameWin, CFrameWnd)
	ON_WM_PAINT ()
	ON_WM_LBUTTONDOWN( )
	ON_WM_KEYDOWN ()
	ON_WM_TIMER ()
END_MESSAGE_MAP ()
