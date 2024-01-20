#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//MY
#define M_UP 0
#define M_DOWN 1
#define M_LEFT 2
#define M_RIGHT 3
#define M_SUBMIT 4

#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))
#define delay(n) Sleep(n)
#define clrscr() system("cls")
#define gotoxy(x,y) { COORD Cur = {x, y}; \
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);}
#define showcursor(bShow) { CONSOLE_CURSOR_INFO CurInfo = {20, bShow}; \
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo); }


enum { ESC = 27, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 };
#define putsxy(x, y, s) {gotoxy(x, y);puts(s);}
#define BX 5
#define BY 1
#define BW 10
#define BH 20

//MY
int KeyControl();
void init();
void titleDraw();
int menuDraw();
void infoDraw();
void gotoxy_(int, int);



void DrawScreen();
BOOL ProcessKey();
void PrintBrick(BOOL Show);
int GetAround(int x, int y, int b, int r);
BOOL MoveDown();
void TestFull();
void Play();

struct Point {
	int x, y;
};
struct Point Shape[][4][4] = {
	{ { 0,0,1,0,2,0,-1,0 },{ 0,0,0,1,0,-1,0,-2 },{ 0,0,1,0,2,0,-1,0 },{ 0,0,0,1,0,-1,0,-2 } },
	{ { 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 } },
	{ { 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,1,-1,0,-1,-1 },{ 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,1,-1,0,-1,-1 } },
	{ { 0,0,-1,-1,0,-1,1,0 },{ 0,0,-1,0,-1,1,0,-1 },{ 0,0,-1,-1,0,-1,1,0 },{ 0,0,-1,0,-1,1,0,-1 } },
	{ { 0,0,-1,0,1,0,-1,-1 },{ 0,0,0,-1,0,1,-1,1 },{ 0,0,-1,0,1,0,1,1 },{ 0,0,0,-1,0,1,1,-1 } },
	{ { 0,0,1,0,-1,0,1,-1 },{ 0,0,0,1,0,-1,-1,-1 },{ 0,0,1,0,-1,0,-1,1 },{ 0,0,0,-1,0,1,1,1 } },
	{ { 0,0,-1,0,1,0,0,1 },{ 0,0,0,-1,0,1,1,0 },{ 0,0,-1,0,1,0,0,-1 },{ 0,0,-1,0,0,-1,0,1 } },
};

enum { EMPTY, BRICK, WALL };
char arTile[3][4] = { ". ","■","□" };
int board[BW + 2][BH + 2];
int nx, ny;
int brick, rot;
int score;



int main()
{
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			Play();//게임시작
		}
		else if (menuCode == 1) {
			infoDraw();//게임정보
		}
		else if (menuCode == 2) {
			return 0;//종료
		}
		system("cls");
	}

	return 0;
}



int KeyControl() {
	char temp = getch();
	if (temp == 'w' || temp == 'W') {
		return M_UP;
	}
	else if (temp == 'a' || temp == 'A') {
		return M_LEFT;
	}
	else if (temp == 's' || temp == 'S') {
		return M_DOWN;
	}
	else if (temp == 'd' || temp == 'D') {
		return M_RIGHT;
	}
	else if (temp == ' ') {
		return M_SUBMIT;
	}
}

void init() {
	system("mode con cols=80 lines=30 | title 게임제목");  // 더 큰 콘솔 창 크기로 변경

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; //false 0 == 숨기는 기능
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void titleDraw() {
	printf("\n\n\n\n");
	printf("\033[0;31m");
	printf("        ▣▣▣▣▣    ▣▣▣▣▣    ▣▣▣▣▣    ▣▣▣▣▣    ▣▣▣▣▣    ▣▣▣  \n");
	printf("\033[0m");
	printf("\033[0;33m");
	printf("          #      #          #     #     #     #     #     \n");
	printf("\033[0m");
	printf("\033[0;32m");
	printf("          #      ####       #     # ###       #     ####  \n");
	printf("\033[0m");
	printf("\033[0;36m");
	printf("          #      #          #     #    #      #         # \n");
	printf("\033[0m");
	printf("\033[0;35m");
	printf("          #      #####      #     #     #   #####   ####  \n");
	printf("\033[0m");
}

int menuDraw() {
	int x_d = 24;  // 중앙에 위치하도록 수정
	int y_d = 12;  // 메뉴 시작 위치 수정


	gotoxy_(x_d - 2, y_d);
	printf("> 게임 시작");
	gotoxy_(x_d, y_d + 1);
	printf("게임 정보");
	gotoxy_(x_d, y_d + 2);
	printf("종료");

	while (1) {
		int num_key = KeyControl();
		switch (num_key) {
		case M_UP: {
			if (y_d > 12) {
				gotoxy_(x_d - 2, y_d);
				printf(" ");
				gotoxy_(x_d - 2, --y_d);
				printf(">");
			}
			break;
		}
		case M_DOWN: {
			if (y_d < 14) {
				gotoxy_(x_d - 2, y_d);
				printf(" ");
				gotoxy_(x_d - 2, ++y_d);
				printf(">");
			}
			break;
		}
		case M_SUBMIT: {
			return y_d - 12;
		}
		}
	}
}


void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("                                [조작법]                               \n\n\n");
	printf("                      좌우:이동, 위:회전, 아래:내림                  \n\n");
	printf("                             공백:전부 내림\n\n\n\n");
	printf("              개발자: Z_E_R_0(이승주), 46실장(임재형)\n\n");
	printf("              스페이스바를 누르면 메인화면으로 이동합니다.");

	while (1) {

		if (KeyControl() == M_SUBMIT) {
			break;
		}

	}
}


void gotoxy_(int x_d, int y_d) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x_d;
	pos.Y = y_d;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void DrawScreen() //줄 제거
{
	for (int x = 0; x < BW + 2; x++) {
		for (int y = 0; y < BH + 2; y++) {
			putsxy(BX + x * 2, BY + y, arTile[board[x][y]]);
		}
	}

	putsxy(50, 3, "Tetris Ver 1.0");
	putsxy(50, 5, "좌우:이동, 위:회전, 아래:내림");
	putsxy(50, 6, "공백:전부 내림");



}




BOOL ProcessKey()
{
	if (kbhit()) {
		int ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
			switch (ch) {
			case LEFT:
				if (GetAround(nx - 1, ny, brick, rot) == EMPTY) {
					PrintBrick(FALSE);
					nx--;
					PrintBrick(TRUE);
				}
				break;
			case RIGHT:
				if (GetAround(nx + 1, ny, brick, rot) == EMPTY) {
					PrintBrick(FALSE);
					nx++;
					PrintBrick(TRUE);
				}
				break;
			case UP:
				if (GetAround(nx, ny, brick, (rot + 1) % 4) == EMPTY) {
					PrintBrick(FALSE);
					rot = (rot + 1) % 4;
					PrintBrick(TRUE);
				}
				break;
			case DOWN:
				if (MoveDown()) {
					return TRUE;
				}
				break;
			}
		}
		else {
			switch (ch) {
			case ' ':
				while (MoveDown() == FALSE) { ; }
				return TRUE;
			case ESC:
				exit(0);
			}
		}
	}
	return FALSE;
}

void PrintBrick(BOOL Show)
{
	for (int i = 0; i < 4; i++) {
		gotoxy(BX + (Shape[brick][rot][i].x + nx) * 2, BY + Shape[brick][rot][i].y + ny);
		puts(arTile[Show ? BRICK : EMPTY]);
	}
}

int GetAround(int x, int y, int b, int r)
{
	int k = EMPTY;

	// 벽돌이 차지한 타일 모양 중 가장 큰 값을 찾는다.
	for (int i = 0; i < 4; i++) {
		k = max(k, board[x + Shape[b][r][i].x][y + Shape[b][r][i].y]);
	}
	return k;
}

BOOL MoveDown()
{
	// 바닥에 닿았으면 가득찼는지 점검하고 TRUE를 리턴한다.
	if (GetAround(nx, ny + 1, brick, rot) != EMPTY) {
		TestFull();
		return TRUE;
	}
	// 아직 공중에 떠 있으면 한칸 아래로 내린다.
	PrintBrick(FALSE);
	ny++;
	PrintBrick(TRUE);
	return FALSE;
}

void TestFull() // 제거
{
	// 바닥에 내려앉은 벽돌 기록
	for (int i = 0; i < 4; i++) {
		board[nx + Shape[brick][rot][i].x][ny + Shape[brick][rot][i].y] = BRICK;
	}

	// 수평으로 가득찬 벽돌 제거 //여기다 점수 넣자!
	for (int y = 1; y < BH + 1; y++) {
		BOOL bFull = TRUE;
		for (int x = 1; x < BW + 1; x++) {
			if (board[x][y] == EMPTY) {
				bFull = FALSE;

				break;
			}
		}
		// 한줄이 가득 찼으면 이 줄을 제거한다.
		if (bFull) {
			for (int ty = y; ty > 1; ty--) {
				for (int x = 1; x < BW + 1; x++) {
					board[x][ty] = board[x][ty - 1];
				}
			}

			DrawScreen();
			delay(200);
		}
	}
}


void Play() {
	system("cls");
	int score = 0; // 점수 인티저형 변수 0으로 초기화
	int nFrame, nStay;
	int x, y;

	showcursor(FALSE);
	randomize();
	clrscr();

	// 가장자리는 벽, 나머지는 빈 공간으로 초기화한다.
	for (x = 0; x < BW + 2; x++) {
		for (y = 0; y < BH + 2; y++) {
			if (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) {
				board[x][y] = WALL;
			}
			else {
				board[x][y] = EMPTY;
			}
		}
	}
	DrawScreen();
	nFrame = 20;

	// 전체 게임 루프
	for (; 1;) {
		brick = random(sizeof(Shape) / sizeof(Shape[0]));
		nx = BW / 2;
		ny = 3;
		rot = 0;
		PrintBrick(TRUE);

		if (GetAround(nx, ny, brick, rot) != EMPTY) break;

		// 벽돌 하나가 바닥에 닿을 때까지의 루프
		nStay = nFrame;
		for (; 2;) {
			if (--nStay == 0) {
				nStay = nFrame;
				if (MoveDown()) break;
			}
			if (ProcessKey()) break;
			delay(1000 / 20);
		}



	}
	clrscr();
	putsxy(30, 12, "G A M E  O V E R");
	putsxy(18, 14, "스페이스바를 누르시면 타이틀로 돌아갑니다.");


	getchar();

}