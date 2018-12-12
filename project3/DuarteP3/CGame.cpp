/*********************************************************************
* Assignment: Project 3 - GUI Move and Match Game                    *
* Author: Gabriel Duarte                                             *
* Date: Fall 2017                                                    *
* File: CGame.cpp                                                    *
*                                                                    *
* Description: This file contains the essential functions.           *
*********************************************************************/

#include "CGame.h"
#include <time.h>
#include <fstream>
#include <mmsystem.h>

using namespace std;

static CBitmap images [NUMIMAGES];
static CBitmap masks [2];
static int topScores [1] = {0};
CGame * savedGame = NULL;


/*********************************************************************
* Function: CGameSquare ()                                           *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will initialize the variables.          *
*********************************************************************/

CGame::CGameSquare::CGameSquare ()
{
	what = BORDER;
	whichSymbol = 0;
	matched = false;
	value = 0;
}

/*********************************************************************
* Function: Fill()                                                   *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will fill the square randomly.          *
*********************************************************************/

void CGame::CGameSquare::Fill ()
{
	what = SYMBOL;
	whichSymbol = rand() % 7 + 1;
}

/*********************************************************************
* Function: Display (CDC * deviceContextP)                           *
*                                                                    *
* Parameters: CDC * deviceContextP                                   *
* Return value: None                                                 *
* Description: This function will create the rectangle.              *
*********************************************************************/

void CGame::CGameSquare::Display (CDC * deviceContextP)
{
	if (what == EMPTY)
		return;
	deviceContextP->Rectangle (where);
	CDC memDC;
	memDC.CreateCompatibleDC(deviceContextP);
	memDC.SelectObject(&images[whichSymbol]);
	int res = deviceContextP->TransparentBlt (where.left+1, where.top+1, where.Width()-2,where.Height()-2,
					&memDC, 0, 0, 100, 100, SRCCOPY); 
	DeleteDC (memDC);
}

/*********************************************************************
* Function: Swap (CGame::CGameSquare & other, CFrameWnd * windowP)   *
*                                                                    *
* Parameters: CGame::CGameSquare & other, CFrameWnd * windowP        *
* Return value: None                                                 *
* Description: This function will swap all values in a square        *
*	except for the where rectangles.                                 *
*********************************************************************/

void CGame::CGameSquare::Swap (CGame::CGameSquare & other, CFrameWnd * windowP)
{
	CGameSquare temp = *this;
	// Swap the images
	swap(*this, other);
	swap(where, other.where);
	windowP->InvalidateRect (where);
	windowP->InvalidateRect (other.where);
}

/*********************************************************************
* Function: SetWhere (CRect whereRect)                               *
*                                                                    *
* Parameters: CRect whereRect                                        *
* Return value: None                                                 *
* Description: This function will set the where.                     *
*********************************************************************/

void CGame::CGameSquare::SetWhere (CRect whereRect)
{
	where = whereRect;
}

/*********************************************************************
* Function: CGame ()                                                 *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will initialize grid and load images.   *                                   *
*********************************************************************/

CGame::CGame ()
{
	// Create the grid then call Init
	srand (unsigned (time (NULL)));
	numRows = numCols = 1;
	grid = new CGameSquare * [numRows+2];
	for (int r = 0; r < numRows+2; r++)
		grid[r] = new CGameSquare [numCols+2];
	savedGame = new CGame (*this);
	Init (DEFAULT_ROWS, DEFAULT_COLS);

	// Load all the images
	int res = bgImage.LoadBitmap(CString("BACKGROUND_BMP"));
	res = images[0].LoadBitmap(CString("ME_BMP"));
	res = images[1].LoadBitmap(CString("SNORLAX_BMP"));
	res = images[2].LoadBitmap(CString("GYARADOS_BMP")); 
	res = images[3].LoadBitmap(CString("PIKACHU_BMP"));
	res = images[4].LoadBitmap(CString("SQUIRTLE_BMP"));
	res = images[5].LoadBitmap(CString("CHARIZARD_BMP"));
	res = images[6].LoadBitmap(CString("BULBASAUR_BMP"));
	res = images[7].LoadBitmap(CString("CATERPIE_BMP"));
	srand (unsigned (time (NULL)));
}

/*********************************************************************
* Function: ~CGame ()                                                *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will delete the grid and savedGamed.    *
*********************************************************************/

CGame::~CGame ()
{
	for (int r = 0; r < numRows + 2; r++)
		delete[] grid[r];
	delete[] grid;
	if (this != savedGame  && savedGame != NULL)
		delete savedGame;
	savedGame = NULL;
}

/*********************************************************************
* Function: CGame (const CGame & other)                              *
*                                                                    *
* Parameters: const CGame & other                                    *
* Return value: None                                                 *
* Description: This function will copy everything.                   *
*********************************************************************/

CGame::CGame (const CGame & other)
{
	// Do a deep copy
	numRows = other.numRows;
	numCols = other.numCols;
	myRow = other.myRow;
	myCol = other.myCol;

	state = other.state;
	score = other.score;
	thisRect = other.thisRect;
	movesLeft = other.movesLeft;
	grid = new CGameSquare *[numRows + 2];
	for (int i = 0; i < numRows + 2; i++)
	{
		grid[i] = new CGameSquare[numCols + 2];
		for (int j = 1; j <= numCols; j++)
		{
			grid[i][j] = other.grid[i][j];
		}
	}
}

/*********************************************************************
* Function: operator = (const CGame & other)                         *
*                                                                    *
* Parameters: const CGame & other                                    *
* Return value: *this                                                *
* Description: This function will allow us to use copy constructor.  *
*********************************************************************/

CGame & CGame::operator = (const CGame & other)
{
	if (this == & other)
		return *this;
	// Do a clean up
	for (int r = 0; r < numRows + 2; r++)
		delete[] grid[r];
	delete[] grid;
	// Do a deep copy
	numRows = other.numRows;
	numCols = other.numCols;
	myRow = other.myRow;
	myCol = other.myCol;
	state = other.state;
	score = other.score;
	thisRect = other.thisRect;
	movesLeft = other.movesLeft;
	
	
	grid = new CGameSquare * [numRows + 2];
	for (int i = 0; i < numRows + 2; i++)
	{
		grid[i] = new CGameSquare[numCols + 2];
		for (int j = 1; j <= numCols; j++)
		{
			grid[i][j] = other.grid[i][j];
		}
	}
	return * this;
}

/*********************************************************************
* Function: Init (int R, int C)                                      *
*                                                                    *
* Parameters: int R, int C                                           *
* Return value: None                                                 *
* Description: This function will create grid and initialize values. *
*********************************************************************/

void CGame::Init (int R, int C)
{
	for (int r = 0; r < numRows + 2; r++)
		delete[] grid[r];
	delete[] grid;
	numRows = R; // 5
	numCols = C; // 9
	grid = new CGameSquare *[numRows + 2];
	for (int r = 0; r < numRows + 2; r++)
		grid[r] = new CGameSquare[numCols + 2];
	FillIn  ();
	PlaceMe ();

	state = 0;
	score = 0;
	hs = 0;
	movesLeft = DEFAULT_MOVES;
	elapsedTime = 0;
	finished = 0;
	thisRect = CRect (0,0,0,0);
	*savedGame = *this;
}

/*********************************************************************
* Function: Instructions (CFrameWnd * windowP)                       *
*                                                                    *
* Parameters: CFrameWnd * windowP                                    *
* Return value: None                                                 *
* Description: This function will write out the instructions.        *
*********************************************************************/

void CGame::Instructions (CFrameWnd * windowP)
{
	CString message = "Welcome to Match 'Em All!\n\n";
	message += "The goal of this game is to match at least 3 Pokemon in a row!\n";
	message += "Controls of the game are:\n";
	message += "\t\t\tw: up\n";
	message += "\t\t\ta: left\n";
	message += "\t\t\ts: down\n";
	message += "\t\t\td: right\n";
	message += "You will get 1 point per square for 3 or more matches in a row.\n";
	message += "You are also limited to 100 moves\n";
	message += "\t\t\tKey: i will show the instructions\n";
	message += "\t\t\tKey: n will create a new game\n";
	message += "\t\t\tKey: r will restart the game to original state\n";
	message += "\t\t\tKey: e will exit the game\n";
	message += "\n\t\t     GOOD LUCK!\n";
	
	CString title = "Instructions";
	windowP->MessageBox (message, title);
}

/*********************************************************************
* Function: Display (CFrameWnd * windowP)                            *
*                                                                    *
* Parameters: CFrameWnd * windowP                                    *
* Return value: None                                                 *
* Description: This function will set up the grid and set texts'.    *
*********************************************************************/

void CGame::Display (CFrameWnd * windowP)
{
	CPaintDC dc (windowP);
	CRect rect;
	windowP->GetClientRect (&rect);
	if (rect != thisRect)
		SetUp (rect);

	CDC memDC;
	int res = memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bgImage);
	dc.TransparentBlt (0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, 1800, 880, SRCCOPY); 
	DeleteDC (memDC);
	
	dc.SetBkMode(TRANSPARENT);	
	CFont font;
	CString fontName = "Verdana";
	font.CreatePointFont(rect.Width() / 6, fontName, &dc);
	CFont* def_font = dc.SelectObject(&font);
	COLORREF def_color = dc.SetTextColor (RGB (0, 0, 0));	
	GameDisplay (&dc);
	DataDisplay (&dc);
	dc.SetTextColor (RGB (0, 0, 0));
	ButtonDisplay (&dc);
	dc.SelectObject(def_font);
	dc.SetTextColor(def_color);
}

/*********************************************************************
* Function: SetUp (CRect rect)                                       *
*                                                                    *
* Parameters: CRect rect                                             *
* Return value: None                                                 *
* Description: This function will create the button sizes and texts. *
*********************************************************************/

void CGame::SetUp (CRect rect)
{
	thisRect = rect;

	// Setup all the sizes for the rectangles
	int sixthW = rect.Width() / 6;
	int fourthH = rect.Height() / 4;
	int twelfthW = rect.Width() / 12;
	int twelfthH = rect.Height() / 12;

	gameRect = CRect (sixthW, fourthH, rect.Width()-sixthW, rect.Height()-twelfthH);
	dataRect = CRect (0, 5 * twelfthH, sixthW, rect.Height()/2);
	nameRect = CRect(sixthW*5,1.5 * twelfthH, sixthW, rect.Height() /4);
	highscoreRect = CRect(0, 6 * twelfthH, sixthW, rect.Height());
	buttonRect = CRect(sixthW*5, 5 * twelfthH, sixthW*6, rect.Height() / 2);
	movesleftRect = CRect(sixthW*10, 5 * twelfthH, sixthW, rect.Height()/2);
	//					  (l          t          r            b           )
	restartbuttonRect = CRect(sixthW*5, 5 * twelfthH, sixthW * 6, rect.Height() / 2);
	exitbuttonRect = CRect(sixthW * 5, 5 * twelfthH, sixthW * 6, rect.Height() / 2);
	scoreRect = CRect (dataRect.left, dataRect.bottom, dataRect.right, dataRect.bottom + twelfthH);
	hsRect = CRect(dataRect.left, dataRect.bottom*2.15, dataRect.right, dataRect.bottom + twelfthH);
	mRect = CRect(buttonRect.left + twelfthW / 3, 4 * twelfthH, buttonRect.right - twelfthW / 3, 9 * twelfthH);
	
	newButton = CRect (buttonRect.left+twelfthW/3, 7 * twelfthH, buttonRect.right-twelfthW/3, 8 * twelfthH);
	restartButton = CRect (restartbuttonRect.left+twelfthW/3, 8.5 * twelfthH, restartbuttonRect.right-twelfthW/3, 9.5 * twelfthH);
	exitButton = CRect(exitbuttonRect.left + twelfthW / 3, 10 * twelfthH, exitbuttonRect.right - twelfthW / 3, 11 * twelfthH);

	int sqHeight = gameRect.Height() / numRows;
	int sqWidth = gameRect.Width() / numCols;
	int top = gameRect.top + (gameRect.Height() - sqHeight * numRows) / 2;
	int left = gameRect.left + (gameRect.Width() - sqWidth * numCols) / 2;
	for (int r = 1; r <= numRows; r++)
		for (int c = 1; c <= numCols; c++)
			grid[r][c].SetWhere (CRect(left + (c-1)*sqWidth, top + (r-1)*sqHeight, left + (c)*sqWidth, top + (r)*sqHeight));
}

/*********************************************************************
* Function: GameDisplay (CDC * deviceContextP)                       *
*                                                                    *
* Parameters: CDC * deviceContextP                                   *
* Return value: None                                                 *
* Description: This function will display the grid.                  *
*********************************************************************/

void CGame::GameDisplay (CDC * deviceContextP)
{
	deviceContextP->Rectangle(gameRect);
	for (int r = 1; r <= numRows; r++)
		for (int c = 1; c <= numCols; c++)
			grid [r][c].Display (deviceContextP);
}

/*********************************************************************
* Function: DataDisplay (CDC * deviceContextP)                       *
*                                                                    *
* Parameters: CDC * deviceContextP                                   *
* Return value: None                                                 *
* Description: This function will display the texts and data.        *
*********************************************************************/

void CGame::DataDisplay (CDC * deviceContextP)
{
	// Display the text on the screen like score and high score and moves left
	deviceContextP->DrawText (CString ("Your Score"), dataRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	char buffer [50];
	sprintf_s (buffer, "%d", score);
	deviceContextP->DrawText(CString (buffer), scoreRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	deviceContextP->DrawText(CString("Match 'Em All"), nameRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	deviceContextP->DrawText(CString("High Score"), highscoreRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	char sbuffer[50];
	sprintf_s(sbuffer, "%d", topScores[0]);
	deviceContextP->DrawText(CString(sbuffer), hsRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	deviceContextP->DrawText(CString("Moves Left"), movesleftRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
	char mbuffer[50];
	sprintf_s(mbuffer, "%d", movesLeft);
	deviceContextP->DrawText(CString(mbuffer), mRect, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}

/*********************************************************************
* Function: ButtonDisplay (CDC * deviceContextP)                     *
*                                                                    *
* Parameters: CDC * deviceContextP                                   *
* Return value: None                                                 *
* Description: This function will display the buttons.               *
*********************************************************************/

void CGame::ButtonDisplay (CDC * deviceContextP)
{
	// Create a shape of the recatangle and put text on it
	CPoint corner = CPoint (newButton.Width() / 5, newButton.Height() / 5);
	deviceContextP->RoundRect (newButton, corner);
	deviceContextP->DrawText(CString ("New"), newButton, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	CPoint rcorner = CPoint(restartButton.Width() / 5, restartButton.Height() / 5);
	deviceContextP->RoundRect(restartButton, rcorner);
	deviceContextP->DrawText(CString("Restart"), restartButton, DT_SINGLELINE | DT_VCENTER | DT_CENTER);

	CPoint tcorner = CPoint(exitButton.Width() / 5, exitButton.Height() / 5);
	deviceContextP->RoundRect(exitButton, tcorner);
	deviceContextP->DrawText(CString("Exit"), exitButton, DT_SINGLELINE | DT_VCENTER | DT_CENTER);
}

/*********************************************************************
* Function: Click(int y, int x, CFrameWnd * windowP)                 *
*                                                                    *
* Parameters: int y, int x, CFrameWnd * windowP                      *
* Return value: None                                                 *
* Description: This function will check to see if there was a click. *
*********************************************************************/

void CGame::Click(int y, int x, CFrameWnd * windowP)
{
	if (newButton.PtInRect(CPoint(x, y))) // Check if click was in newButton
	{
		Init(numRows, numCols);
		windowP->SetTimer(1, 1000, NULL);
		windowP->Invalidate(true);
	}
	if (restartButton.PtInRect(CPoint(x, y))) // Check if click was in restartButton
	{
		restart();
		windowP->Invalidate(true);
	}
	if (exitButton.PtInRect(CPoint(x, y))) // Check if click was in exitButton
	{
	CString message = "Are you sure you want to quit?\n";
	CString title = "Quit";
	if (windowP->MessageBox(message, title, MB_OKCANCEL) == IDOK)
		windowP->DestroyWindow();
	}
}

/*********************************************************************
* Function: Move (char direction, CFrameWnd * windowP)               *
*                                                                    *
* Parameters: char direction, CFrameWnd * windowP                    *
* Return value: None                                                 *
* Description: This function will move the symbols around.           *
*********************************************************************/

void CGame::Move (char direction, CFrameWnd * windowP)
{
	if (finished)
	{
		if (score > topScores[0]) // Set the top score 
			topScores[0] = score;	
		return;
	}
	
	int row = myRow;
	int col = myCol;
	switch (direction)
	{
		case 'a': // moving left
		{
			if (col == 1) // Checking the bounds
			{col = 1; break;}
			col--;
			break;
		}
		case 'w': // moving up
		{
			if (row == 1) // Checking the bounds
			{row = 1; break;}
			row--;
			break;
		}

		case 'd': // moving right
		{
			if (col == numCols) // Checking the bounds
			{col = numCols; break;}
			col++;
			break;
		}

		case 's': // moving down
		{
			if (row == numRows) // Checking the bounds
			{row = numRows; break;}
			row++;
			break;
		}
		
	}
	if (row != myRow || col  != myCol)
	{
		if (grid[row][col].value > 0)
		{
			score += grid[row][col].value;
			grid[row][col].value = 0;
			windowP->InvalidateRect(scoreRect);
		}
		grid[myRow][myCol].Swap (grid[row][col], windowP);
		myRow = row;
		myCol = col;
		movesLeft--;
		windowP->InvalidateRect(mRect);
		if (movesLeft < 1)
			finished = true;
		if (state == 0)
		{
			state = 1;
			TimerEvaluateAndUpdate (windowP);
		}
	}
}

/*********************************************************************
* Function: KeyDown (char key, CFrameWnd * windowP)                  *
*                                                                    *
* Parameters: char key, CFrameWnd * windowP                          *
* Return value: None                                                 *
* Description: This function will check to see if keys were clicked. *
*********************************************************************/

void CGame::KeyDown (char key, CFrameWnd * windowP)
{	
	if (key == 'i') // Show instructions key
		Instructions(windowP);
	if (key == 'r') // Restart game key
	{
		restart();
		windowP->Invalidate(true);
	}
	if (key == 'n') // New game key
	{
		Init(numRows, numCols);
		windowP->SetTimer(1, 1000, NULL);
		windowP->Invalidate(true);
	}
	if (key == 'e') // Exit key
	{
		CString message = "Are you sure you want to quit?\n";
		CString title = "Quit";
		if (windowP->MessageBox(message, title, MB_OKCANCEL) == IDOK)
			windowP->DestroyWindow();
	}
}

/*********************************************************************
* Function: restart()                                                *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will call the copy constructor.         *
*********************************************************************/

void CGame::restart()
{
	*this = *savedGame;
}

/*********************************************************************
* Function: Message (CFrameWnd * windowP)                            *
*                                                                    *
* Parameters: CFrameWnd * windowP                                    *
* Return value: None                                                 *
* Description: This function will write the ending message box.      *
*********************************************************************/

void CGame::Message (CFrameWnd * windowP)
{
	char buffer [30];
	sprintf_s (buffer, "Your score is: %d", score);
	CString message = "Match 'Em All is Over\nThank you for playing!\n" + CString(buffer);
	CString title = "Match 'Em All Over";
	windowP->KillTimer(1);
	windowP->MessageBox (message, title);
	windowP->Invalidate(true);
}

/*********************************************************************
* Function: UpdateTime (CFrameWnd * windowP)                         *
*                                                                    *
* Parameters: CFrameWnd * windowP                                    *
* Return value: None                                                 *
* Description: This function will add a second to the timer.         *
*********************************************************************/

void CGame::UpdateTime (CFrameWnd * windowP)
{
	elapsedTime++;
}

/*********************************************************************
* Function:  FillIn()                                                *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will call the Fill function.            *
*********************************************************************/

void CGame::FillIn()
{
	for (int r = 1; r <= numRows; r++)
		for (int c = 1; c <= numCols; c++)
			grid[r][c].Fill ();
}

/*********************************************************************
* Function: PlaceMe ()                                               *
*                                                                    *
* Parameters: None                                                   *
* Return value: None                                                 *
* Description: This function will place ME in a random spot on grid. *
*********************************************************************/

void CGame::PlaceMe ()
{
	// Randomly place our ME symbol
	myRow = 1 + rand() % numRows;
	myCol = 1+ rand() % numCols;
	grid [myRow][myCol].what = ME;
	grid [myRow][myCol].whichSymbol = 0;
	grid [myRow][myCol].value = 0;
 	grid [myRow][myCol].matched = false;
}
/*********************************************************************
* Function: FindMatches (CFrameWnd * windowP)                        *
*                                                                    *
* Parameters: CFrameWnd * windowP                                    *
* Return value: bool                                                 *
* Description: This function will find matches in the grid.          *
*********************************************************************/

bool CGame::FindMatches (CFrameWnd * windowP)
{	
	bool foundm = false;

	// This gets the matches going up and down
	for (int i = 1; i <= numRows-1; i++)
		for (int j = 1; j <= numCols; j++)
			if (grid[i][j].whichSymbol == grid[i + 1][j].whichSymbol &&
				grid[i][j].whichSymbol == grid[i + 2][j].whichSymbol)
			{
				grid[i][j].matched = true;
				grid[i + 1][j].matched = true;
				grid[i + 2][j].matched = true;
				score += 3;
				foundm = true;
				BOOL soundPlayed = PlaySound(CString("SOUND_WAV"),
					GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
			}
	for (int i = 1; i <= numRows; i++)
		for (int j = 1; j <= numCols-1; j++)

				// This gets the matches going across
				if (grid[i][j].whichSymbol == grid[i][j + 1].whichSymbol &&
					grid[i][j].whichSymbol == grid[i][j + 2].whichSymbol)
				{
					grid[i][j].matched = true;
					grid[i][j + 1].matched = true;
					grid[i][j + 2].matched = true;
					score += 3;
					foundm = true;
					BOOL soundPlayed = PlaySound(CString("SOUND_WAV"),
						GetModuleHandle(NULL), SND_RESOURCE | SND_ASYNC);
				}
	
	return foundm;
}

/*********************************************************************
* Function: RemoveMatches (CFrameWnd * windowP)                      *
*                                                                    *
* Parameters: CFrameWnd * windowP                                    *
* Return value: 0                                                    *
* Description: This function will remove the found matches.          *
*********************************************************************/

int CGame:: RemoveMatches (CFrameWnd * windowP)
{	
	// This loop will run through each i and j in the grid and replace the matched
	// symbols with a random symbol, then set the grid[i][j] position of the
	// matched symbol to false.
	for (int i = 0; i <= numRows; i++)
		for (int j = 0; j <= numCols; j++)
			if (grid[i][j].matched == true)
			{
				grid[i][j].what = EMPTY;
				grid[i][j].matched = false;
			}
	return 0;
}

/*********************************************************************
* Function: UpdateGrid (int row, int col, CFrameWnd * windowP)       *
*                                                                    *
* Parameters: int row, int col, CFrameWnd * windowP					 *
* Return value: None                                                 *
* Description: This function will update empty squares after match.  *
*********************************************************************/

void CGame::UpdateGrid (int row, int col, CFrameWnd * windowP)
{
	
	for (int i = 0; i <= numRows; i++)
		for (int j = 0; j <= numCols; j++)
			if (grid[i][j].what == EMPTY)
				grid[i][j].Fill();
	windowP->Invalidate(TRUE);
}

/******************************************************************************
* Function: TimerEvaluateAndUpdate (CFrameWnd * windowP)					  *
*																			  *
* Parameters: CFrameWnd * windowP											  *
* Return value: 0															  *
* Description: This function will loop through each function 1 sec at a time. *
*******************************************************************************/

int CGame::TimerEvaluateAndUpdate (CFrameWnd * windowP)
{
	int matchesFound = 0;
	static int row, col;
	switch (state)
	{
	case 1:
		matchesFound = FindMatches (windowP);
		if (matchesFound == 0)
		{
			state = 0;
			if (finished)
			{
				Message(windowP);
				if (score > topScores[0])
					topScores[0] = score;
			}
			return 0;
		}
		windowP->InvalidateRect (scoreRect);
		state = 2;
		windowP->SetTimer(2, 100, NULL);
		break;
	case 2:
		state = 3;
		break;
	case 3:
		RemoveMatches (windowP);
		state = 4;
		break;
	case 4: // This can help with cascading effect
		UpdateGrid (row, col, windowP);
		state = 5;
		break;
	case 5:
		matchesFound = FindMatches (windowP);
		if (matchesFound == 0)
		{
			state = 0;
			windowP->KillTimer(2);
			if (finished)
			{
				Message(windowP);
				if (score > topScores[0])
					topScores[0] = score;
			}
			return 0;
		}
		windowP->InvalidateRect (scoreRect);
		state = 2;
		break;
	}
	return 0;
}
