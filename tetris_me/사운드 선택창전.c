//brick = ������ ���� ����� �������� ����

#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")
//MY


/*�Ҹ� �κ� ����
#include <windows.h>
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>;
*/

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

#define BNX 55
#define BNY 16

//MY


#define putssc(x,y,s) {\
gotoxy(x,y);\
printf("%d", s);\
}

BOOL sts;
BOOL bFull;
int score = 0;
int KeyControl();
void init();
void titleDraw();
int menuDraw();
void infoDraw();
void gotoxy_(int, int);
//�̸� ���

//BGM + ȿ�� �Լ���
void Tsound();
void Gsound();
void STsound(BOOL sts);


void DrawScreen();
BOOL ProcessKey();
void PrintBrick(BOOL Show);
int GetAround(int x, int y, int b, int r);
BOOL MoveDown();
void TestFull();
void Play();

struct Point {
	int x, y;
};  //������ ���� ����� ���� ���⼭!
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
char arTile[3][4] = { ". ","��","��" }; //��� ����

int board[BW + 2][BH + 2];
int nx, ny;
int brick[2] = { 0 }, rot;
int score;

void next();




int main()
{
	int now = 0;
	Tsound();
	init();
	while (1) {

		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			now = 1;
			STsound(TRUE);
			Play();//���ӽ���




		}
		else if (menuCode == 1) {
			infoDraw();//��������
		}
		else if (menuCode == 2) {
			return 0;//����
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

void Tsound() {

	PlaySound(TEXT("tet_m"), NULL, SND_ASYNC | SND_LOOP); //���� ���


}

void Gsound() {

	PlaySound(TEXT("tetris"), NULL, SND_ASYNC | SND_LOOP);

}

void STsound(BOOL sts) {

	if (sts == 1) {

		PlaySound(NULL, 0, 0);

	}

}

void init() {
	system("mode con cols=80 lines=30 | title ��������");  // �� ū �ܼ� â ũ��� ����

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0; //false 0 == ����� ���
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void titleDraw() {
	printf("\n\n\n\n");
	printf("\033[0;31m");
	printf("        #####    #####    #####    #####    #####    ###  \n");
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
	int x_d = 24;  // �߾ӿ� ��ġ�ϵ��� ����
	int y_d = 12;  // �޴� ���� ��ġ ����


	gotoxy_(x_d - 2, y_d);
	printf("> ���� ����");
	gotoxy_(x_d, y_d + 1);
	printf("���� ����");
	gotoxy_(x_d, y_d + 2);
	printf("����");

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
	printf("                                [���۹�]                               \n\n\n");
	printf("                      �¿�:�̵�, ��:ȸ��, �Ʒ�:����                  \n\n");
	printf("                             ����:���� ����\n\n\n\n");
	printf("              ������: Z_E_R_0(�̽���), 46����(������)\n\n");
	printf("              �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.");

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

void DrawScreen() //�� ����
{

	for (int x = 0; x < BW + 2; x++) {
		for (int y = 0; y < BH + 2; y++) {
			putsxy(BX + x * 2, BY + y, arTile[board[x][y]]);
		}
	}


	putsxy(50, 3, "Tetris Ver 1.0");
	putsxy(50, 5, "�¿�:�̵�, ��:ȸ��, �Ʒ�:����");
	putsxy(50, 6, "����:���� ����");
	putssc(50, 8, score);


}




BOOL ProcessKey()
{
	if (kbhit()) {
		int ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
			switch (ch) {
			case LEFT:
				if (GetAround(nx - 1, ny, brick[0], rot) == EMPTY) {
					PrintBrick(FALSE);
					nx--;
					PrintBrick(TRUE);
				}
				break;
			case RIGHT:
				if (GetAround(nx + 1, ny, brick[0], rot) == EMPTY) {
					PrintBrick(FALSE);
					nx++;
					PrintBrick(TRUE);
				}
				break;
			case UP:
				if (GetAround(nx, ny, brick[0], (rot + 1) % 4) == EMPTY) {
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

void PrintBrick(BOOL Show)	// ������ ����ϰų� �����Ѵ�.
{				// �̵����� ������ ������� �Ѵ�.

	int i;

	for (i = 0; i < 4; i++) {	// 4��¥�� ������ �׷��� �ϹǷ� 4�� �ݺ�

		gotoxy(BX + (Shape[brick[0]][rot][i].x + nx) * 2, BY + Shape[brick[0]][rot][i].y + ny);
		// ��� ����� ��ǥ�� �°� Ŀ���� �̵���Ų��.

		puts(arTile[Show ? BRICK : EMPTY]);	// show�� true�� ����, false�� �� ���� ���
	}
}

int GetAround(int x, int y, int b, int r)
{
	int i, k = EMPTY;	// k�� �� ����(0) ������ �ʱ�ȭ

	for (i = 0; i < 4; i++)
		k = max(k, board[x + Shape[b][r][i].x][y + Shape[b][r][i].y]);
	// �ش� ������ ��ǥ ��(0 or 1 or 2)�� k�� ���ؼ� ū ���� k�� ����

	return k;	// ���� �� ��ȯ
}

BOOL MoveDown()
{
	// �ٴڿ� ������� ����á���� �����ϰ� TRUE�� �����Ѵ�.
	if (GetAround(nx, ny + 1, brick[0], rot) != EMPTY) {
		TestFull();
		return TRUE;
	}
	// ���� ���߿� �� ������ ��ĭ �Ʒ��� ������.
	PrintBrick(FALSE);
	ny++;
	PrintBrick(TRUE);
	return FALSE;
}

void TestFull() // ����
{
	// �ٴڿ� �������� ���� ���
	for (int i = 0; i < 4; i++) {
		board[nx + Shape[brick[0]][rot][i].x][ny + Shape[brick[0]][rot][i].y] = BRICK;
	}

	// �������� ������ ���� ���� //����� ���� ����!
	for (int y = 1; y < BH + 1; y++) {
		BOOL bFull = TRUE;
		for (int x = 1; x < BW + 1; x++) {
			if (board[x][y] == EMPTY) {
				bFull = FALSE;

				if (bFull == TRUE) score++;

				break;
			}
		}
		// ������ ���� á���� �� ���� �����Ѵ�.
		if (bFull) {
			for (int ty = y; ty > 1; ty--) {
				for (int x = 1; x < BW + 1; x++) {
					board[x][ty] = board[x][ty - 1];
				}
			}
			score++;
			DrawScreen();
			delay(200);
		}
	}
}



void next() {

	int Next[8][7];
	int i;

	gotoxy(34, 8); puts("���� ���");

	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 7; y++) {
			Next[x][y] = (y == 0 || y == 6 | x == 0 || x == 7) ? WALL : EMPTY; //�ܺ� �� ĥ�ϱ�!

			gotoxy(34 + x * 2, 10 + y);

			puts(arTile[Next[x][y]]);
		}
	}

	brick[1] = random(sizeof(Shape) / sizeof(Shape[0])); //���� ����� ��ȣ �����ϱ�
	for (i = 0; i < 4; i++) {

		gotoxy(40 + (Shape[brick[1]][rot][i].x) * 2, 13 + Shape[brick[1]][rot][i].y);
		//��� ����� ��ǥ�� �°� Ŀ�� �̵�
		puts(arTile[1]);

	}

}




void Play() {

	Gsound();
	system("cls");
	// ���� ��Ƽ���� ���� 0���� �ʱ�ȭ
	int nFrame, nStay;
	int x, y;


	showcursor(FALSE);
	randomize();
	clrscr();

	// �����ڸ��� ��, �������� �� �������� �ʱ�ȭ�Ѵ�.
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




	// ��ü ���� ����
	for (; 1;) {

		if (!brick[0])		// �� ó������ ����
			brick[0] = random(sizeof(Shape) / sizeof(Shape[0]));	// ����� ��ȣ�� �������� �����Ѵ�.

		else		// �� ��°���� ���� ����� ����� �����Ѵ�.
			brick[0] = brick[1];	// ���� ����� ����� ����

		next();

		nx = BW / 2;
		ny = 3;
		rot = 0;
		PrintBrick(TRUE);


		//PrintNextBrick();

		if (GetAround(nx, ny, brick[0], rot) != EMPTY) break;

		// ���� �ϳ��� �ٴڿ� ���� �������� ����
		nStay = nFrame;
		for (; 2;) {
			if (--nStay == 0) {
				nStay = nFrame;
				if (MoveDown()) break;
				if (bFull == TRUE) {

					score++;
				}

			}
			if (ProcessKey()) {
				break;

			}
			delay(1000 / 20);
		}



	}
	clrscr();
	STsound(TRUE);
	putsxy(30, 12, "G A M E  O V E R");
	putsxy(18, 14, "�����̽��ٸ� �����ø� Ÿ��Ʋ�� ���ư��ϴ�.");



	getchar();

}