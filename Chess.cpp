#include<iostream>
#include<windows.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#include<iomanip>
using namespace std;

enum colour
{
	black, white
};
void color(int k)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, k);
}
struct board
{

	char sym = '-';
	colour clr;
	bool (*islegal)(board* [][8], int, int, int, int);
	void(*drawpiece)(int, int, char);
};

void getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT |
		ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState ==

			FROM_LEFT_1ST_BUTTON_PRESSED)

		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}

void gotoRowCol(int rpos, int cpos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = cpos;
	scrn.Y = rpos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void timer()
{
	cout << endl << endl;
	Sleep(1000);
	system("cls");
	color(6);
	cout << endl << "\t\t\t\t\t\tGAME STARTING IN" << endl;
	color(2);
	cout << "\t\t\t\t\t\t\t" << "3\r";
	Beep(500, 500); // Beep at 1000 Hz for 500 milliseconds
	Sleep(1000);
	color(3);
	cout << "\t\t\t\t\t\t\t" << "2\r";
	Beep(500, 500);
	Sleep(1000);
	color(4);
	cout << "\t\t\t\t\t\t\t" << "1\r";
	Beep(500, 500);
	Sleep(1000);
	color(5);
	cout << "\t\t\t\t\t\t\t" << "0\r";
	Beep(500, 500);
	Sleep(1000);
	Beep(1000, 1000);
	system("cls");
}

int instructions() {
	int delay = 2000;
	color(7);

	cout << "Here are the Rules for Chess: " << endl;
	cout << "                                                                                      Press 's' to SKIP " << endl;

	if (_kbhit() && _getch() == 's') return 0;

	Sleep(1000);
	cout << " 1. The goal of the game is to checkmate the opponent's king.\n" << endl;
	if (_kbhit() && _getch() == 's') {
		system("cls");
		return 0;
	}
	Sleep(delay);

	cout << " 2. The game ends if the opponent's king is checkmated or a stalemate occurs.\n" << endl;
	if (_kbhit() && _getch() == 's') {
		system("cls");
		return 0;
	}
	Sleep(delay);

	cout << " 3. The king can move one square in any direction.\n" << endl;
	if (_kbhit() && _getch() == 's') {
		system("cls");
		return 0;
	}
	Sleep(delay);

	cout << " 4. The queen can move any number of squares in any direction.\n" << endl;
	if (_kbhit() && _getch() == 's') {
		system("cls");
		return 0;
	}
	Sleep(delay);

	cout << " 5. The rook can move any number of squares along a row or column.\n" << endl;
	cout << "    Rook Controls: Move vertically or horizontally.\n" << endl;
	if (_kbhit() && _getch() == 's') {
		system("cls");
		return 0;
	}
	Sleep(delay);

	cout << " 6. The bishop can move any number of squares diagonally.\n" << endl;
	cout << "    Bishop Controls: Move diagonally.\n" << endl;
	if (_kbhit() && _getch() == 's') {
		system("cls");
		return 0;
	}
	Sleep(delay);

	cout << " 7. The knight moves in an 'L' shape and can jump over other pieces.\n" << endl;
	cout << "    Knight Controls: Move in an 'L' shape.\n" << endl;
	if (_kbhit() && _getch() == 's') {
		system("cls");
		return 0;
	}
	Sleep(delay);

	cout << " 8. The pawn moves forward one square at a time, but captures diagonally.\n" << endl;
	cout << "    Pawn Controls: Move forward, capture diagonally.\n" << endl;
	if (_kbhit() && _getch() == 's') {
		system("cls");
		return 0;
	}
	Sleep(delay);

	cout << " 9. Pawns can move two squares forward on their first move.\n" << endl;
	if (_kbhit() && _getch() == 's') {
		system("cls");
		return 0;
	}
	Sleep(delay);

	cout << " 10. Castling is a special move involving the king and a rook.\n" << endl;
	if (_kbhit() && _getch() == 's') {
		system("cls");
		return 0;
	}
	Sleep(delay);

	color(6);
	cout << "  Have fun playing Chess! Good Luck!" << endl;
	Sleep(delay);

	system("cls");
	system("pause");
	return 0;
}

void menu()
{
	color(7);
	system("pause");
	system("cls");
	color(4);
	gotoRowCol(40, 50);
	cout << "1. SAVED GAME" << endl;
	gotoRowCol(41, 50);
	cout << "2. NEW GAME" << endl;

}
void Gameover()
{
	system("cls");
	gotoRowCol(30, 10);
	cout << "\t\t\  #####     ##     ##       ##  ######   ######    ##    ##  ######  ######  \n";
	gotoRowCol(31, 10);
	cout << "\t\t\ ##    #   #  #    ###     ###  ##      ##    ##   ##    ##  ##      #    #  \n";
	gotoRowCol(32, 10);
	cout << "\t\t\ ##       ######   ## #   # ##  ####    ##    ##   ##    ##  ####    ######  \n";
	gotoRowCol(33, 10);
	cout << "\t\t\ ##   ### ##  ##   ##  # #  ##  ##      ##    ##   ##    ##  ##      ##    #    \n";
	gotoRowCol(34, 10);
	cout << "\t\t\  #####   ##  ##   ##   #   ##  ######   ######     ######   ######  ##     #  \n";
	gotoRowCol(35, 20);
}
void drawrook(int sr, int sc, char sym = -37)
{


	gotoRowCol(sr - 2, sc - 2);
	cout << sym;
	gotoRowCol(sr - 2, sc);
	cout << sym;
	gotoRowCol(sr - 2, sc + 2);
	cout << sym;
	gotoRowCol(sr - 1, sc - 1);
	cout << sym;
	gotoRowCol(sr - 1, sc);
	cout << sym;
	gotoRowCol(sr - 1, sc + 1);
	cout << sym;
	gotoRowCol(sr, sc - 1);
	cout << sym;
	gotoRowCol(sr, sc);
	cout << sym;
	gotoRowCol(sr, sc + 1);
	cout << sym;
	gotoRowCol(sr + 1, sc - 1);
	cout << sym;
	gotoRowCol(sr + 1, sc);
	cout << sym;
	gotoRowCol(sr + 1, sc + 1);
	cout << sym;
	for (int c = sc - 2; c <= sc + 2; c++)
	{
		gotoRowCol(sr + 2, c);
		cout << sym;
	}
	for (int x = sc - 3; x <= sc + 3; x++)
	{
		gotoRowCol(sr + 3, x);
		cout << sym;
	}
	cout << endl;

}

void drawbishup(int sr, int sc, char sym = -37)
{

	gotoRowCol(sr - 2, sc);
	cout << sym;
	gotoRowCol(sr - 1, sc - 1);
	cout << sym;
	gotoRowCol(sr - 1, sc + 1);
	cout << sym;

	gotoRowCol(sr, sc - 2);
	cout << sym;
	gotoRowCol(sr, sc);
	cout << sym;
	gotoRowCol(sr, sc + 2);
	cout << sym;
	gotoRowCol(sr + 1, sc - 1);
	cout << sym;
	gotoRowCol(sr + 1, sc + 1);
	cout << sym;

	for (int c = sc - 2; c <= sc + 2; c++)
	{
		gotoRowCol(sr + 2, c);
		cout << sym;
	}
	for (int x = sc - 3; x <= sc + 3; x++)
	{
		gotoRowCol(sr + 3, x);
		cout << sym;
	}
	cout << endl;

}

void drawknight(int sr, int sc, char sym = -37)
{

	gotoRowCol(sr + 2, sc + 1);
	cout << sym;
	gotoRowCol(sr - 1, sc - 1);
	cout << sym;
	gotoRowCol(sr - 1, sc + 1);
	cout << sym;
	gotoRowCol(sr - 2, sc);
	cout << sym;
	for (int c = sr + 2; c >= sr; c--)
	{
		gotoRowCol(c, sc - 2);
		cout << sym;
	}
	for (int c = sr + 1; c >= sr; c--)
	{
		gotoRowCol(c, sc + 2);
		cout << sym;
	}
	for (int x = sc - 2; x <= sc + 2; x++)
	{
		gotoRowCol(sr + 3, x);
		cout << sym;
	}
	cout << endl;

}

void drawpawn(int sr, int sc, char sym = -37)
{


	gotoRowCol(sr - 1, sc);
	cout << sym;

	gotoRowCol(sr, sc - 1);
	cout << sym;
	gotoRowCol(sr, sc);
	cout << sym;
	gotoRowCol(sr, sc + 1);
	cout << sym;
	gotoRowCol(sr + 1, sc - 1);
	cout << sym;
	gotoRowCol(sr + 1, sc);
	cout << sym;
	gotoRowCol(sr + 1, sc + 1);
	cout << sym;
	gotoRowCol(sr + 2, sc - 1);
	cout << sym;
	gotoRowCol(sr + 2, sc);
	cout << sym;
	gotoRowCol(sr + 2, sc + 1);
	cout << sym;
	for (int c = sc - 2; c <= sc + 2; c++)
	{
		gotoRowCol(sr + 3, c);
		cout << sym;
	}

}

void drawqueen(int sr, int sc, char sym = -37)
{


	gotoRowCol(sr - 1, sc - 1);
	cout << sym;
	gotoRowCol(sr - 1, sc + 1);
	cout << sym;
	for (int s = sr; s <= sr + 3; s++)
	{
		for (int c = sc - 2; c <= sc + 2; c++)
		{
			gotoRowCol(s, c);
			cout << sym;
		}
	}
	for (int c = sc - 2; c <= sc + 2; c++)
	{
		gotoRowCol(sr - 2, c);
		cout << sym;
	}
	gotoRowCol(sr - 3, sc);
	cout << sym;



}
void drawking(int sr, int sc, char sym = -37)
{


	gotoRowCol(sr - 1, sc - 1);
	cout << sym;
	gotoRowCol(sr - 1, sc + 1);
	cout << sym;
	for (int s = sr; s <= sr + 2; s++)
	{
		for (int c = sc - 2; c <= sc + 2; c++)
		{
			gotoRowCol(s, c);
			cout << sym;
		}
	}

	for (int c = sc - 3; c <= sc + 3; c++)
	{
		gotoRowCol(sr + 3, c);
		cout << sym;
	}
	for (int c = sc - 2; c <= sc + 2; c++)
	{
		gotoRowCol(sr - 2, c);
		cout << sym;
	}
	gotoRowCol(sr - 3, sc);
	cout << sym;
	gotoRowCol(sr - 3, sc - 2);
	cout << sym;
	gotoRowCol(sr - 3, sc + 2);
	cout << sym;
}
void drawdash(int sr, int sc, char sym = -37)
{

	for (int r = sr - 4; r <= sr + 6; r++)
	{
		for (int c = sc - 3; c <= sc + 5; c++)
		{
			gotoRowCol(r, c);
			cout << sym;
		}
	}
}

bool isHorixontal(board* B[][8], int sr, int sc, int er, int ec)
{
	return (sr == er);
}
bool isVertical(board* B[][8], int sr, int sc, int er, int ec)
{
	return (sc == ec);
}
bool isDigonal(board* B[][8], int sr, int sc, int er, int ec)
{
	int dr = sr - er;
	int dc = sc - ec;
	return (abs(dr) == abs(dc));
}

bool isHPC(board* B[][8], int sr, int sc, int er, int ec)
{
	if (ec > sc)
	{
		for (int c = sc + 1; c < ec; c++)
		{
			if (B[sr][c]->sym != '-')
				return false;
		}
	}
	else if (ec < sc)
	{
		for (int c = ec + 1; c < sc; c++)
		{
			if (B[sr][c]->sym != '-')
				return false;
		}
	}
}
bool isVPC(board* B[][8], int sr, int sc, int er, int ec)
{
	if (er > sr)
	{
		for (int r = sr + 1; r < er; r++)
		{
			if (B[r][sc]->sym != '-')
				return false;
		}
	}
	else if (er < sr)
	{
		for (int r = er + 1; r < sr; r++)
		{
			if (B[r][sc]->sym != '-')
				return false;
		}
	}
	return true;
}
bool isDPC(board* B[][8], int sr, int sc, int er, int ec)
{
	int rowStep, colStep;
	if (er > sr)
	{
		rowStep = 1;
	}
	else
	{
		rowStep = -1;
	}
	if (ec > sc)
	{
		colStep = 1;
	}
	else {
		colStep = -1;
	}
	int r = sr + rowStep;
	int c = sc + colStep;
	while (r != er && c != ec) {
		if (B[r][c]->sym != '-')
		{
			return false;
		}
		r += rowStep;
		c += colStep;
	}
	return true;
}
bool islegalrook(board* B[][8], int sr, int sc, int er, int ec)
{
	return(isHorixontal(B, sr, sc, er, ec) && isHPC(B, sr, sc, er, ec) || isVertical(B, sr, sc, er, ec) && isVPC(B, sr, sc, er, ec));
}
bool islegalbishup(board* B[][8], int sr, int sc, int er, int ec)
{
	return(isDigonal(B, sr, sc, er, ec) && isDPC(B, sr, sc, er, ec));
}
bool islegalqueen(board* B[][8], int sr, int sc, int er, int ec)
{
	return(islegalrook(B, sr, sc, er, ec) || islegalbishup(B, sr, sc, er, ec));
}
bool isLegalKing(board* B[][8], int sr, int sc, int er, int ec)
{
	int dr = abs(sr - er);
	int dc = abs(sc - ec);
	return (dr <= 1 && dc <= 1);
}
bool islegalpawnW(board* B[][8], int sr, int sc, int er, int ec)
{
	if (sr == 6)
	{
		if (er == sr - 2 && ec == sc)
		{
			return(isVPC(B, sr, sc, er, ec));
		}
	}
	else
	{
		if (er == sr - 1 && sc == ec)
		{
			return(isVPC(B, sr, sc, er, ec));
		}
	}
	return false;
}
bool islegaldash(board* B[][8], int sr, int sc, int er, int ec)
{
	return true;
}
bool islegalpawnB(board* B[][8], int sr, int sc, int er, int ec)
{
	if (sr == 1)
	{

		if (er == sr + 2 && ec == sc)
		{
			return(isVPC(B, sr, sc, er, ec));
		}

	}
	else
	{
		if (er == sr + 1 && sc == ec)
		{
			return(isVPC(B, sr, sc, er, ec));
		}
	}
	return false;
}
bool islegalknight(board* B[][8], int sr, int sc, int er, int ec)
{
	int dr = abs(sr - er);
	int dc = abs(sc - ec);
	return ((dr * dr + dc * dc) == 5);
}
void init(board* B[][8], int turn)
{
	B[0][0] = new board{ 'R',black,islegalrook ,drawrook };
	B[0][1] = new board{ 'N',black,islegalknight,drawknight };
	B[0][2] = new board{ 'B',black,islegalbishup ,drawbishup };
	B[0][3] = new board{ 'Q',black,islegalqueen ,drawqueen };
	B[0][4] = new board{ 'K',black,isLegalKing ,drawking };
	B[0][5] = new board{ 'B',black ,islegalbishup,drawbishup };
	B[0][6] = new board{ 'N',black ,islegalknight,drawknight };
	B[0][7] = new board{ 'R',black,islegalrook ,drawrook };


	B[7][0] = new board{ 'r',white,islegalrook,drawrook };
	B[7][1] = new board{ 'n',white,islegalknight,drawknight };
	B[7][2] = new board{ 'b',white,islegalbishup ,drawbishup };
	B[7][3] = new board{ 'q',white,islegalqueen,drawqueen };
	B[7][4] = new board{ 'k',white,isLegalKing ,drawking };
	B[7][5] = new board{ 'b',white,islegalbishup ,drawbishup };
	B[7][6] = new board{ 'n',white,islegalknight ,drawknight };
	B[7][7] = new board{ 'r',white,islegalrook ,drawrook };
	for (int i = 0; i < 8; i++)
	{
		B[1][i] = new board{ 'P', black ,islegalpawnB,drawpawn };
		B[6][i] = new board{ 'p', white,islegalpawnW ,drawpawn };
	}
	turn = black;
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			B[i][j] = new board{ '-',white,islegaldash,drawdash };
		}
	}

}

bool isvalidselection(board* B[][8], int sr, int sc, int turn)
{

	if (sr < 0 || sr >= 8 || sc < 0 || sc >= 8) {
		return false;
	}


	if (B[sr][sc]->sym == '-' || B[sr][sc]->clr != turn) {
		return false;
	}


	return true;
}

bool isvalidgiven(board* B[][8], int sr, int sc, int turn)
{
	if ((B[sr][sc]->clr != turn || B[sr][sc]->sym == '-'))
	{
		return true;
	}
	if (B[sr][sc]->clr == turn)
	{
		return false;
	}

}
void drawChessCell(int sr, int sc, int rdim, int cdim, bool isFilled, char sym = -37)
{
	if (isFilled)
	{
		color(4);
	}
	else
	{
		color(7);
	}

	for (int ri = 0; ri < rdim; ri++)
	{

		for (int ci = 0; ci < cdim; ci++)
		{
			gotoRowCol(ri + sr + 10, ci + sc + 30);
			cout << sym;
		}
	}
	color(8);
}

void drawChessGrid(int rdim, int cdim)
{
	int gridSize = 8;
	char sym = -37;




	for (int ri = 0; ri < gridSize; ri++)
	{

		for (int ci = 0; ci < gridSize; ci++)
		{
			bool isFilled = (ri + ci) % 2 == 0;
			drawChessCell(ri * rdim, ci * cdim, rdim, cdim, isFilled, sym);
		}
	}

	for (int i = 0; i < gridSize; i++)
	{

		gotoRowCol(i * rdim + rdim / 2 + 10, 29);
		cout << (8 - i);


		gotoRowCol(gridSize * rdim + 10, i * cdim + cdim / 2 + 30);
		cout << char('A' + i);
	}

}
void cellno(int position, int& cri, int& cci)
{
	cri = (position - 1) / 8;
	cci = (position - 1) % 8;
}
void writeInCellCenter(int cri, int cci, int rdim, int cdim, char sym)
{
	int c = cri * rdim + (rdim / 2) + 10;
	int r = cci * cdim + (cdim / 2) - 1 + 30;
	gotoRowCol(cri * rdim + (rdim / 2) + 10, cci * cdim + (cdim / 2) - 1 + 30);
	bool isFilled = (cci + cri) % 2 == 0;
	color(3);
	drawChessCell(cri * rdim, cci * cdim, rdim, cdim, isFilled);
	if (sym == 'k' || sym == 'K')
	{
		if (sym == 'k')
		{
			color(3);
		}
		else if (sym == 'K')
		{
			color(5);
		}
		drawking(c, r);
	}
	else if (sym == 'q' || sym == 'Q')
	{
		if (sym == 'q')
		{
			color(3);
		}
		else if (sym == 'Q')
		{
			color(5);
		}
		drawqueen(c, r);
	}
	else if (sym == 'r' || sym == 'R')
	{
		if (sym == 'r')
		{
			color(3);
		}
		else if (sym == 'R')
		{
			color(5);
		}
		drawrook(c, r);
	}
	else if (sym == 'p' || sym == 'P')
	{
		if (sym == 'p')
		{
			color(3);
		}
		else if (sym == 'P')
		{
			color(5);
		}
		drawpawn(c, r);
	}
	else if (sym == 'n' || sym == 'N')
	{
		if (sym == 'n')
		{
			color(3);
		}
		else if (sym == 'N')
		{
			color(5);
		}
		drawknight(c, r);
	}
	else if (sym == 'b' || sym == 'B')
	{
		if (sym == 'b')
		{
			color(3);
		}
		else if (sym == 'B')
		{
			color(5);
		}
		drawbishup(c, r);
	}
	else if (sym == '-')
	{

		bool isFilled = (cci + cri) % 2 == 0;
		drawChessCell(cri * rdim, cci * cdim, rdim, cdim, isFilled);
	}


}


void displayboard(board* B[][8])
{
	char sym = 'a';

	for (int i = 0; i < 8; i++)
	{
		gotoRowCol(30 + i, 50);
		cout << i + 1 << " ";
		for (int j = 0; j < 8; j++)
		{
			cout << B[i][j]->sym << " ";
		}
		cout << endl;
	}

	gotoRowCol(39, 52);
	for (int k = 0; k < 8; k++)
	{
		sym = 'a' + k;
		cout << sym << " ";
	}
}

void turnmsg(int turn)
{
	gotoRowCol(9, 55);
	cout << "player" << turn + 1;
}

void changeturn(int& turn, int NOPs)
{
	turn = (turn + 1) % NOPs;
}

void printChessBoard(int rdim, int cdim, board* B[8][8])
{
	for (int cri = 0; cri < 8; cri++)
	{
		for (int cci = 0; cci < 8; cci++)
		{
			/*/ color(2); /*/

			writeInCellCenter(cri, cci, rdim, cdim, B[cri][cci]->sym);
		}
	}
}
void dublicateupdateboardbyleft(board* B[][8], board* D[][8])
{

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j)
		{
			D[i][j] = new board{};
		}
	}
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j)
		{
			D[i][j]->clr = B[i][j]->clr;
			D[i][j]->islegal = B[i][j]->islegal;
			D[i][j]->sym = B[i][j]->sym;
		}
	}

}
void saveGame(board* B[][8], int turn, const char* filename)
{
	ofstream wrt(filename);

	if (!wrt) {
		cout << "Error opening file to save game!" << endl;
		return;
	}


	wrt << turn << endl;


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			wrt << B[i][j]->sym << " ";
		}
		wrt << endl;
	}

	cout << "Game saved successfully!" << endl;
	wrt.close();  // Close the file
}
void replayGame(board* B[][8], int turn, ofstream& wrt)
{

	wrt << turn << endl;


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)
		{
			wrt << B[i][j]->sym << " ";
		}
		wrt << endl;
	}
	wrt << endl;


}



void replayGameRdr(board* B[][8], int& turn, const char* filename) {
	ifstream Rdr(filename);

	gotoRowCol(0, 20);
	cout << "Replaying";
	if (!Rdr) {
		cout << "Error opening file for replay!" << endl;
		return;
	}

	while (Rdr >> turn) {
		// Print turn message
		turnmsg(turn);

		// Read and update the board
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				char piece;
				Rdr >> piece;
				B[i][j]->sym = piece;
			}
		}

		// Print the updated board
		printChessBoard(8, 8, B);


		Sleep(1000);
	}
	gotoRowCol(0, 20);
	cout << "            ";

}

void loadGame(board* B[][8], int& turn, const char* filename) {
	ifstream Rdr(filename);

	if (!Rdr) {
		cout << "Error opening file to load game!" << endl;
		return;
	}

	Rdr >> turn;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char piece;
			Rdr >> piece;
			B[i][j]->sym = piece;

			// Assign legality functions based on piece type
			if (piece == 'k' || piece == 'K') {
				B[i][j]->islegal = isLegalKing;
			}
			else if (piece == 'p') {
				B[i][j]->islegal = islegalpawnW;
			}
			else if (piece == 'P') {
				B[i][j]->islegal = islegalpawnB;
			}
			else if (piece == 'r' || piece == 'R') {
				B[i][j]->islegal = islegalrook;
			}
			else if (piece == 'n' || piece == 'N') {
				B[i][j]->islegal = islegalknight;
			}
			else if (piece == 'b' || piece == 'B') {
				B[i][j]->islegal = islegalbishup;
			}
			else if (piece == 'q' || piece == 'Q') {
				B[i][j]->islegal = islegalqueen;
			}
			else {
				B[i][j]->islegal = islegaldash;  // Empty square or unknown piece
			}
		}
	}

	cout << "Game loaded successfully!" << endl;
	Rdr.close();
}


void clickgrid(int sr, int sc, int rdim, int cdim, char sym = -37)
{
	color(8);
	for (int ri = 0; ri < rdim; ri++) {
		for (int ci = 0; ci < cdim; ci++)
		{
			if (ri == 0 || ri == rdim - 1 || ci == 0 || ci == cdim - 1) {
				gotoRowCol(ri + sr, ci + sc);
				cout << sym;
			}
		}
	}
	gotoRowCol(4 + sr, 2 + sc);
	cout << "Exit" << endl;

}

void clickgridforreplay(int sr, int sc, int rdim, int cdim, char sym = -37)
{
	color(8);
	for (int ri = 0; ri < rdim; ri++) {
		for (int ci = 0; ci < cdim; ci++)
		{
			if (ri == 0 || ri == rdim - 1 || ci == 0 || ci == cdim - 1) {
				gotoRowCol(ri + sr, ci + sc);
				cout << sym;
			}
		}
	}
	gotoRowCol(4 + sr, 1 + sc);
	cout << "Replay" << endl;

}


bool replay(int rdim, int cdim, int c, int j, board* B[][8], int turn, const char* filename)
{
	int Xmin = 13 * cdim;
	int Xmax = Xmin + cdim - 1;
	int Ymin = rdim + 10;
	int Ymax = Ymin + rdim - 1;
	char choice;

	int rpos = 0, cpos = 0;
	getRowColbyLeftClick(rpos, cpos);

	if (cpos >= Xmin && cpos <= Xmax && rpos >= Ymin && rpos <= Ymax)
	{
		return true;

	}
	return false;
}

bool exit(int rdim, int cdim, int c, int j, board* B[][8], int turn, const char* filename)
{
	int Xmin = 13 * cdim;
	int Xmax = Xmin + cdim - 1;
	int Ymin = rdim;
	int Ymax = Ymin + rdim - 1;
	char choice;

	int rpos = 0, cpos = 0;
	getRowColbyLeftClick(rpos, cpos);

	if (cpos >= Xmin && cpos <= Xmax && rpos >= Ymin && rpos <= Ymax)
	{
		system("cls");
		gotoRowCol(0, 0);
		cout << "Do you want to save the game? (y/n): ";
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			saveGame(B, turn, "savegame.txt");
			exit(0);
			return true;
		}
	}
	return false;
}
void selectPosition(
	int& row,
	int& col,
	board* B[][8],
	int turn,
	const char* loadfilename,
	const char* replayfilename,
	const char* undofilename
) {
	int mouseRow, mouseCol;
	getRowColbyLeftClick(mouseRow, mouseCol);


	int rdim = 8, cdim = 8;
	int offsetRow = 10, offsetCol = 30;


	row = (mouseRow - offsetRow) / rdim;
	col = (mouseCol - offsetCol) / cdim;


	if (row >= 0 && row < 8 && col >= 0 && col < 8) {

		return;
	}


	if (exit(rdim, cdim, 2, 0, B, turn, loadfilename)) {
		return;
	}


	if (replay(rdim, cdim, 9, 0, B, turn, replayfilename)) {
		board* temp[8][8];
		dublicateupdateboardbyleft(B, temp);
		int tempturn = 0;
		replayGameRdr(temp, tempturn, replayfilename);
		return;
	}

	row = -1;
	col = -1;
}



void updateboardbyleft(board* B[][8], int sr, int sc, int er, int ec, int rdim, int cdim)
{

	//B[er][ec] = B[sr][sc];
	//B[sr][sc] = new board{ '-', black };

	if (B[sr][sc] != nullptr)
	{
		delete B[er][ec];


		B[er][ec] = B[sr][sc];


		B[sr][sc] = new board{ '-', black,islegaldash };
	}
}
void printboard(board* B[][8], int sr, int sc, int er, int ec, int rdim, int cdim)
{
	bool isFilled = (sr + sc) % 2 == 0;
	drawChessCell(sr * rdim, sc * cdim, rdim, cdim, isFilled);
	writeInCellCenter(sr, sc, rdim, cdim, B[sr][sc]->sym);

	writeInCellCenter(er, ec, rdim, cdim, B[er][ec]->sym);

}
bool** computehighlight(board* B[][8], int sr, int sc, int turn)
{
	bool** Bmap = new bool* [8];
	for (int bi = 0; bi < 8; bi++)
	{
		Bmap[bi] = new bool[8]();
	}


	int er, ec;
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			er = ri;
			ec = ci;
			if (B[sr][sc] == nullptr) {
				cout << "Error: Piece at " << sr << ", " << sc << " is nullptr!" << endl;
			}
			if (sr < 0 || sr >= 8 || sc < 0 || sc >= 8) {
				cout << "Error: Invalid coordinates!" << endl;
			}

			if (B[sr][sc] != nullptr && isvalidgiven(B, er, ec, turn) && B[sr][sc]->islegal(B, sr, sc, er, ec))
			{

				Bmap[ri][ci] = true;
			}
		}
	}
	return Bmap;
}

void freeBmap(bool** Bmap)
{
	if (Bmap != nullptr)
	{
		for (int i = 0; i < 8; i++)
		{
			if (Bmap[i] != nullptr)
			{
				delete[] Bmap[i];
				Bmap[i] = nullptr; // Avoid dangling pointer
			}
		}
		delete[] Bmap;
		Bmap = nullptr; // Avoid dangling pointer
	}
}

void highlightCellBorder(int row, int col, int rdim, int cdim) {

	color(6);
	char sym = -37;


	for (int ci = 0; ci < cdim; ci++) {
		gotoRowCol(row * rdim + 10, col * cdim + ci + 30);
		cout << sym;
	}


	for (int ci = 0; ci < cdim; ci++) {
		gotoRowCol((row + 1) * rdim - 1 + 10, col * cdim + ci + 30);
		cout << sym;
	}


	for (int ri = 0; ri < rdim; ri++) {
		gotoRowCol(row * rdim + ri + 10, col * cdim + 30);
		cout << sym;
	}

	for (int ri = 0; ri < rdim; ri++) {
		gotoRowCol(row * rdim + ri + 10, (col + 1) * cdim - 1 + 30);
		cout << sym;
	}
	color(7);
}
void unhighlightCellBorder(int row, int col, int rdim, int cdim)
{

	char sym = -37;
	if ((row + col) % 2 == 0)
	{
		color(4);
	}
	else if ((row + col) % 2 != 0)
	{
		color(7);
	}

	for (int ci = 0; ci < cdim; ci++) {
		gotoRowCol(row * rdim + 10, col * cdim + ci + 30);
		cout << sym;
	}
	for (int ci = 0; ci < cdim; ci++) {
		gotoRowCol((row + 1) * rdim - 1 + 10, col * cdim + ci + 30);
		cout << sym;
	}
	for (int ri = 0; ri < rdim; ri++) {
		gotoRowCol(row * rdim + ri + 10, col * cdim + 30);
		cout << sym;
	}

	for (int ri = 0; ri < rdim; ri++) {
		gotoRowCol(row * rdim + ri + 10, (col + 1) * cdim - 1 + 30);
		cout << sym;
	}
	color(7);
}
void highlightValidMoves(board* B[][8], bool** M, int rdim, int cdim)
{
	if (M == nullptr) return;

	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (M[ri][ci])
			{
				highlightCellBorder(ri, ci, rdim, cdim);
			}
		}
	}
}
void unhighlightValidMoves(board* B[][8], bool** M, int rdim, int cdim)
{
	if (M == nullptr) return;

	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (M[ri][ci])
			{
				unhighlightCellBorder(ri, ci, rdim, cdim);
			}
		}
	}
}





void findking(board* B[][8], int turn, int& er, int& ec) {
	for (int ri = 0; ri < 8; ri++) {
		for (int ci = 0; ci < 8; ci++) {
			if ((turn == black && B[ri][ci]->sym == 'K') ||
				(turn == white && B[ri][ci]->sym == 'k')) {
				er = ri;
				ec = ci;
				return;
			}
		}
	}
}
bool check(board* B[][8], int turn, int NOPs)
{

	int originalTurn = turn;
	changeturn(turn, NOPs);
	int er = 0, ec = 0;
	findking(B, turn, er, ec);

	turn = originalTurn;


	for (int sr = 0; sr < 8; sr++)
	{
		for (int sc = 0; sc < 8; sc++)
		{

			if (B[sr][sc]->sym != '-' &&
				isvalidselection(B, sr, sc, turn) &&
				B[sr][sc]->islegal(B, sr, sc, er, ec))
			{
				return true;
			}
		}
	}

	return false;
}

bool selfcheck(board* B[][8], int turn, int NOPs)
{
	int originalTurn = turn;
	changeturn(turn, NOPs);  // Switch to opponent's turn
	bool inCheck = check(B, turn, NOPs);
	turn = originalTurn;    // Restore original turn
	return inCheck;

}

bool isExitKeyPressed() {
	if (_kbhit()) {
		char key = _getch();  // Get the pressed key without blocking the program
		return (key == 's' || key == 'S');  // Check if it's the 'S' key (save and exit)
	}
	return false;  // No key pressed
}
void debugTempBoard(board* tempBoard[][8]) {
	cout << "Temporary board state:" << endl;
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			cout << tempBoard[r][c]->sym << " ";
		}
		cout << endl;
	}
}


void cleanupBoard(board* D[][8])
{
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j)
		{
			if (D[i][j] != nullptr) {
				delete D[i][j];
				D[i][j] = nullptr;
			}
		}
	}
}
int chooseoption()
{
	gotoRowCol(20, 0);
	int option;
	cout << "U have got a promotion" << endl;
	cout << "1.Queen" << endl;
	cout << "2.Rook" << endl;
	cout << "3.Knight" << endl;
	cout << "4.Bishop" << endl;
	cin >> option;
	cout << option;
	gotoRowCol(20, 0);

	cout << "                         " << endl;
	gotoRowCol(21, 0);
	cout << "          " << endl;
	gotoRowCol(22, 0);
	cout << "           " << endl;
	gotoRowCol(23, 0);
	cout << "              " << endl;
	gotoRowCol(24, 0);
	cout << "              " << endl;
	return option;
}
void pawnpromotion(board* B[][8], int sr, int sc, int er, int ec, int rdim, int cdim)
{
	if (B[er][ec] != nullptr && B[er][ec]->sym == 'p' && er == 0)
	{
		int option = chooseoption();
		switch (option)
		{
		case 1:
			B[er][ec]->sym = 'q';
			break;
		case 2:
			B[er][ec]->sym = 'r';
			break;
		case 3:
			B[er][ec]->sym = 'n';
			break;
		case 4:
			B[er][ec]->sym = 'b';
			break;
		default:
			cout << "Invalid option. Defaulting to Queen." << endl;
			B[er][ec]->sym = 'q';
		}
		B[sr][sc]->sym = B[er][ec]->sym;
		B[sr][sc]->islegal = B[er][ec]->islegal;
		B[sr][sc]->clr = B[er][ec]->clr;

		updateboardbyleft(B, sr, sc, er, ec, rdim, cdim);
		printboard(B, sr, sc, er, ec, rdim, cdim);
	}
	else if (B[er][ec] != nullptr && B[er][ec]->sym == 'P' && er == 7)
	{
		int option = chooseoption();
		switch (option)
		{
		case 1:
			B[er][ec]->sym = 'Q';
			break;
		case 2:
			B[er][ec]->sym = 'R';
			break;
		case 3:
			B[er][ec]->sym = 'N';
			break;
		case 4:
			B[er][ec]->sym = 'B';
			break;
		default:
			cout << "Invalid option. Defaulting to Queen." << endl;
			B[er][ec]->sym = 'Q';
		}
		B[sr][sc]->sym = B[er][ec]->sym;
		updateboardbyleft(B, sr, sc, er, ec, rdim, cdim);
		printboard(B, sr, sc, er, ec, rdim, cdim);
	}
}



bool checkmate(board* B[][8], int turn, int NOPs) {
	if (!check(B, turn, NOPs)) {
		cout << "King is not in check. Not checkmate." << endl;
		return false;
	}


	changeturn(turn, NOPs);
	for (int sr = 0; sr < 8; sr++) {
		for (int sc = 0; sc < 8; sc++) {
			if (isvalidselection(B, sr, sc, turn)) {
				for (int er = 0; er < 8; er++) {
					for (int ec = 0; ec < 8; ec++) {
						if (isvalidgiven(B, er, ec, turn) && B[sr][sc]->islegal(B, sr, sc, er, ec)) {
							board* tempBoard[8][8];
							dublicateupdateboardbyleft(B, tempBoard);
							/*debugTempBoard(tempBoard);*/
							updateboardbyleft(tempBoard, sr, sc, er, ec, 8, 8);
							/*debugTempBoard(tempBoard);*/
							if (!selfcheck(tempBoard, turn, NOPs)) {

								cleanupBoard(tempBoard);
								changeturn(turn, NOPs);
								return false;
							}

							cleanupBoard(tempBoard);
						}
					}
				}
			}
		}
	}

	cout << "Checkmate detected." << endl;
	changeturn(turn, NOPs); // Restore turn
	return true;
}
bool stalemate(board* B[][8], int turn, int NOPs)
{
	if (check(B, turn, NOPs)) {

		cout << "King is in check. Not stalemate." << endl;
		return false;
	}
	changeturn(turn, NOPs);

	for (int sr = 0; sr < 8; sr++) {
		for (int sc = 0; sc < 8; sc++) {
			if (isvalidselection(B, sr, sc, turn)) {
				for (int er = 0; er < 8; er++) {
					for (int ec = 0; ec < 8; ec++) {
						if (isvalidgiven(B, er, ec, turn) && B[sr][sc]->islegal(B, sr, sc, er, ec)) {
							board* tempBoard[8][8];
							dublicateupdateboardbyleft(B, tempBoard);
							updateboardbyleft(tempBoard, sr, sc, er, ec, 8, 8);


							if (!selfcheck(tempBoard, turn, NOPs)) {
								cleanupBoard(tempBoard);
								changeturn(turn, NOPs);
								return false;
							}

							cleanupBoard(tempBoard);
						}
					}
				}
			}
		}
	}

	cout << "Stalemate detected." << endl;
	return true;
}

void displayBoard(board* B[][8])
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << B[i][j]->sym << " ";
		}
		cout << endl;
	}
}


bool promptUndoRedo(board* B[][8], board* tempBoard[][8], board* redoBoard[][8], int& turn, int rdim, int cdim) {
	int secondsRemaining = 3;
	bool actionTriggered = false;
	char action = '\0';

	color(12);
	gotoRowCol(0, 0);
	color(7);
	cout << "Press 'u' to undo, or wait for the countdown: ";
	gotoRowCol(0, 0);
	cout << "                                                                    ";

	for (int i = 0; i < secondsRemaining; ++i) {
		gotoRowCol(3, 40);
		cout << "You have " << secondsRemaining - i << " seconds. Press 'u' to undo.";

		if (_kbhit()) {
			char input = _getch();
			if (input == 'u' || input == 'U') {
				actionTriggered = true;
				action = 'u';
				break;
			}
		}

		Sleep(1000);
	}

	gotoRowCol(3, 40);
	cout << "                                                                                                        ";


	if (actionTriggered && action == 'u')
	{

		dublicateupdateboardbyleft(B, redoBoard);

		dublicateupdateboardbyleft(tempBoard, B);
		printChessBoard(rdim, cdim, B);



		secondsRemaining = 3;
		actionTriggered = false;
		gotoRowCol(0, 0);
		cout << "Press 'r' to redo, or wait for the countdown: ";
		gotoRowCol(0, 0);
		cout << "                                                                    ";

		for (int i = 0; i < secondsRemaining; ++i)
		{
			gotoRowCol(3, 40);
			cout << "You have " << secondsRemaining - i << " seconds. Press 'r' to redo.";

			if (_kbhit()) {
				char input = _getch();
				if (input == 'r' || input == 'R') {
					actionTriggered = true;
					action = 'r';
					break;
				}
			}

			Sleep(1000);
		}

		gotoRowCol(3, 40);
		cout << "                                                                                                        ";


		if (actionTriggered && action == 'r')
		{

			dublicateupdateboardbyleft(redoBoard, B);

			changeturn(turn, 2);
			return true;
		}
		return true;
	}
	else
	{

		changeturn(turn, 2);
		return false;
	}

	return actionTriggered;
}

bool isKingSideCastlingAllowed(board* B[][8], int turn, int NOPs)
{


	if (B[0][4] == nullptr)
	{
		cout << "King pointer is null!" << endl;
		return false;
	}
	if (B[0][7] == nullptr) {
		cout << "Rook pointer is null!" << endl;
		return false;
	}
	int kingRow;
	if (turn == white) {
		kingRow = 7;
	}
	else {
		kingRow = 0;
	}

	int kingCol = 4;


	if (turn == 1 && B[kingRow][kingCol]->sym != 'k')
	{
		return false;
	}
	if (turn == black && B[kingRow][kingCol]->sym != 'K') {
		return false;
	}


	if (turn == white && B[kingRow][7]->sym != 'r') {
		return false;
	}
	if (turn == black && B[kingRow][7]->sym != 'R') {
		return false;
	}


	if (B[kingRow][5]->sym != '-') {
		return false;
	}
	if (B[kingRow][6]->sym != '-') {
		return false;
	}


	if (check(B, turn, NOPs)) { // Current position
		return false;
	}
	if (selfcheck(B, turn, NOPs)) {
		return false;
	}
	if (selfcheck(B, turn, NOPs)) {
		return false;
	}

	return true;
}

bool performKingSideCastling(board* B[][8], int turn)
{

	int kingRow;
	if (turn == white) {
		kingRow = 7;
	}
	else {
		kingRow = 0;
	}
	/*debugTempBoard(B);*/

	gotoRowCol(3, 30);
	cout << "Do u want King side castling ?y/n";
	char sym;
	cin >> sym;
	gotoRowCol(3, 30);
	cout << "                                    ";
	if (sym == 'y' || sym == 'Y')
	{
		B[kingRow][6] = B[kingRow][4]; // King moves to g1/g8
		B[kingRow][4] = new board{ '-', white, islegaldash, drawdash };  // Replacing nullptr with dash
		B[kingRow][5] = B[kingRow][7]; // Rook moves to f1/f8
		B[kingRow][7] = new board{ '-', white, islegaldash, drawdash };  // Replacing nullptr with dash
		return true;

	}
	return false;


}

bool attemptKingSideCastling(board* B[][8], int turn, int NOPs) {


	if (isKingSideCastlingAllowed(B, turn, NOPs))
	{
		if (performKingSideCastling(B, turn))
		{

			return true;
		}
	}
	else
	{
		return false;

	}
}

bool isQueenSideCastlingAllowed(board* B[][8], int turn, int NOPs)
{

	if (B[0][4] == nullptr)
	{
		cout << "King pointer is null!" << endl;
		return false;
	}
	if (B[0][0] == nullptr) {
		cout << "Rook pointer is null!" << endl;
		return false;
	}

	int kingRow;
	if (turn == white) {
		kingRow = 7;
	}
	else {
		kingRow = 0;
	}

	int kingCol = 4;

	if (turn == white && B[kingRow][kingCol]->sym != 'k')
	{
		return false;
	}
	if (turn == black && B[kingRow][kingCol]->sym != 'K') {
		return false;
	}

	if (turn == white && B[kingRow][0]->sym != 'r') {
		return false;
	}
	if (turn == black && B[kingRow][0]->sym != 'R') {
		return false;
	}

	if (B[kingRow][1]->sym != '-') {
		return false;
	}
	if (B[kingRow][2]->sym != '-') {
		return false;
	}
	if (B[kingRow][3]->sym != '-') {
		return false;
	}

	if (check(B, turn, NOPs)) { // Current position
		return false;
	}
	if (selfcheck(B, turn, NOPs)) {
		return false;
	}

	return true;
}

bool performQueenSideCastling(board* B[][8], int turn)
{
	int kingRow;
	if (turn == white) {
		kingRow = 7;
	}
	else {
		kingRow = 0;
	}

	gotoRowCol(3, 30);
	cout << "Do you want Queen side castling ?y/n";
	char sym;
	cin >> sym;
	gotoRowCol(3, 30);
	cout << "                                         ";

	if (sym == 'y' || sym == 'Y')
	{
		B[kingRow][2] = B[kingRow][4];
		B[kingRow][4] = new board{ '-', white, islegaldash, drawdash };
		B[kingRow][3] = B[kingRow][0];
		B[kingRow][0] = new board{ '-', white, islegaldash, drawdash };
		return true;
	}
	return false;
}

bool attemptQueenSideCastling(board* B[][8], int turn, int NOPs) {
	if (isQueenSideCastlingAllowed(B, turn, NOPs))
	{
		if (performQueenSideCastling(B, turn))
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

void enterNames(string& player1, string& player2)
{
	cout << "Enter name for Player 1: ";
	cin >> player1;
	cout << "Enter name for Player 2: ";
	cin >> player2;
}
void displayArt()
{
	color(13);
	gotoRowCol(36, 35);
	cout << "  ____   _   _   _____   ____    ____  " << endl;

	gotoRowCol(37, 35);
	cout << " / ___| | | | | | ____| / ___|  / ___| " << endl;

	gotoRowCol(38, 35);
	cout << "| |     | |_| | |  _|   \\___ \\  \\___ \\ " << endl;

	gotoRowCol(39, 35);
	cout << "| |___  |  _  | | |___   ___) |  ___) |" << endl;

	gotoRowCol(40, 35);
	cout << " \\____| |_| |_| |_____| |____/  |____/ " << endl;
}
int main()
{
	ofstream wrt("replay.txt");
	displayArt();
	timer();
	instructions();
	string player1, player2;
	enterNames(player1, player2);

	int rdim = 8;
	int cdim = 8;
	int turn = 0;
	int NOPs = 2;
	board* B[8][8];
	board* D[8][8];
	board* temp[8][8];
	board* Rtemp[8][8];
	init(B, turn);

	menu();
	gotoRowCol(42, 50);
	int choice;
	cout << "Choice";
	cin >> choice;

	if (choice == 1)
	{
		loadGame(B, turn, "savegame.txt");

		printChessBoard(rdim, cdim, B);

	}
	else if (choice == 2)
	{
		drawChessGrid(rdim, cdim);
		printChessBoard(rdim, cdim, B);
	}
	clickgrid(rdim, 13 * cdim, rdim, cdim);
	clickgridforreplay(10 + rdim, 13 * cdim, rdim, cdim);
	int sc = 0, sr = 0, ec = 0, er = 0;

	color(7);
	bool** M;
	dublicateupdateboardbyleft(B, D);

	bool moveSuccessful = false;

	gotoRowCol(0, 0);
	cout << "                                                      ";
	replayGame(B, turn, wrt);

	do
	{
		moveSuccessful = false;
		dublicateupdateboardbyleft(B, temp);


		do {
			turnmsg(turn);
			if (attemptKingSideCastling(B, turn, NOPs))
			{
				printChessBoard(rdim, cdim, B);
				replayGame(B, turn, wrt);
				if (promptUndoRedo(B, temp, Rtemp, turn, rdim, cdim))
				{
					printChessBoard(rdim, cdim, B);
				}

				continue;
			}
			else if (attemptQueenSideCastling(B, turn, NOPs))
			{
				printChessBoard(rdim, cdim, B);
				replayGame(B, turn, wrt);
				if (promptUndoRedo(B, temp, Rtemp, turn, rdim, cdim))
				{
					printChessBoard(rdim, cdim, B);
				}

				continue;
			}

			do
			{


				do {

					do {

						char c = 'A';
						gotoRowCol(15, 0);
						cout << "Click to select source";
						selectPosition(sr, sc, B, turn, "savegame.txt", "replay.txt", "undo.txt");


						gotoRowCol(15, 95);
						c = c + sc;



					} while (!isvalidselection(B, sr, sc, turn));

					gotoRowCol(15, 0);
					cout << "                             ";
					M = computehighlight(B, sr, sc, turn);
					highlightValidMoves(D, M, rdim, cdim);

					char d = 'A';
					gotoRowCol(15, 0);
					cout << "Click to select destination";
					selectPosition(er, ec, B, turn, "savegame.txt", "replay.txt", "undo.txt");
					gotoRowCol(16, 95);
					d = d + ec;


					gotoRowCol(15, 0);
					cout << "                             ";
				} while (!isvalidgiven(B, er, ec, turn));


				unhighlightValidMoves(D, M, rdim, cdim);

			} while (!M[er][ec]);
			unhighlightValidMoves(D, M, rdim, cdim);
			freeBmap(M);
			dublicateupdateboardbyleft(B, D);
			updateboardbyleft(D, sr, sc, er, ec, rdim, cdim);

			if (selfcheck(D, turn, NOPs))
			{
				cleanupBoard(D);

				gotoRowCol(17, 0);
				cout << "Move not allowed!";
				Sleep(1000);
				gotoRowCol(17, 0);
				cout << "                    ";
			}
			else
			{
				moveSuccessful = true;
			}
		} while (!moveSuccessful);

		updateboardbyleft(B, sr, sc, er, ec, rdim, cdim);
		printboard(B, sr, sc, er, ec, rdim, cdim);



		if ((B[er][ec]->sym == 'p' && er == 0) || (B[er][ec]->sym == 'P' && er == 7))
		{
			pawnpromotion(B, sr, sc, er, ec, rdim, cdim);
		}
		cleanupBoard(D);
		replayGame(B, turn, wrt);

		if (check(B, turn, NOPs))
		{
			gotoRowCol(18, 0);
			cout << "You are in check ";
			Sleep(1000);
			gotoRowCol(18, 0);
			cout << "                  ";
			if (checkmate(B, turn, NOPs))
			{
				gotoRowCol(19, 0);

				cout << "Checkmate! Game over.";
				Gameover();
				return 0;
				break;
			}
		}
		else if (stalemate(B, turn, NOPs)) {
			gotoRowCol(19, 0);
			cout << "Stalemate! It's a draw.";
			Gameover();
			return 0;

		}
		if (promptUndoRedo(B, temp, Rtemp, turn, rdim, cdim))
		{
			printChessBoard(rdim, cdim, B);
		}
		/*changeturn(turn, NOPs);*/

	} while (true);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			delete B[i][j];
			delete D[i][j];
			delete temp[i][j];
			delete Rtemp[i][j];
		}
	}

	return 0;

}
