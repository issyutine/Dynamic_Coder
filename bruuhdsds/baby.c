#define _CRT_NONSTDC_NO_WARNINGS
#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define randomize() srand((unsigned)time(NULL))
#define random(n) (rand() % (n))
#define delay(n) Sleep(n)
#define clrscr() system("cls")
#define gotoxy(x,y) { COORD Cur = {x, y}; \
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);}
#define showcursor(bShow) { CONSOLE_CURSOR_INFO CurInfo = {20, bShow}; \
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo); }


enum { ESC = 27, LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80, ENTER = 13, W = 119, A = 97, S = 115, D = 100, HOLD = 114 };
#define putsxy(x, y, s) {gotoxy(x, y);puts(s);}
#define BX 13
#define BY 6
#define BW 30
#define BH 20

void DrawScreen();
BOOL ProcessKey();
void PrintBrick(BOOL Show);
int GetAround(int x, int y, int b, int r);
BOOL MoveDown();
void TestFull();
int PlusScore(int combo);
int CheckLevel();
int compare(const int* a, const int* b);

struct Point {
	int x, y;
};
struct Point Shape[][4][4] = {
	{ { 0,0,1,0,2,0,-1,0 },{ 0,0,0,1,0,-1,0,-2 },{ 0,0,1,0,2,0,-1,0 },{ 0,0,0,1,0,-1,0,-2 } },// I�� ��
	{ { 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 } },// ���� ��
	{ { 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,1,-1,0,-1,-1 },{ 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,1,-1,0,-1,-1 } },// Z�� ��
	{ { 0,0,-1,-1,0,-1,1,0 },{ 0,0,-1,0,-1,1,0,-1 },{ 0,0,-1,-1,0,-1,1,0 },{ 0,0,-1,0,-1,1,0,-1 } },// �� Z�� ��
	{ { 0,0,-1,0,1,0,-1,-1 },{ 0,0,0,-1,0,1,-1,1 },{ 0,0,-1,0,1,0,1,1 },{ 0,0,0,-1,0,1,1,-1 } },// �� ���� ��
	{ { 0,0,1,0,-1,0,1,-1 },{ 0,0,0,1,0,-1,-1,-1 },{ 0,0,1,0,-1,0,-1,1 },{ 0,0,0,-1,0,1,1,1 } },// ���� ��
	{ { 0,0,-1,0,1,0,0,1 },{ 0,0,0,-1,0,1,1,0 },{ 0,0,-1,0,1,0,0,-1 },{ 0,0,-1,0,0,-1,0,1 } },// ���� ��
};

enum { EMPTY, BRICK, WALL };
char arTile[3][4] = { ". ","��","��" };
int BrickList[3];
int hold[2] = { -1, -1 };
int board[BW + 2][BH + 2];
int nx, ny;
int brick, rot;
int combo = 0;
int score = 0;
int level = 0;
int exp = 0;
int speed = 50;
int dupl = 0;
clock_t start, end;

int main()
{


	FILE* file;
	fopen_s(&file, "score.dat", "rt");
	if (file == NULL) {
		score = 0;
	}
	else {
		fscanf_s(file, "%d", &score);
		fclose(file);
	}
	/*
	int scoreList[11] = { 0 };
	FILE* fp = fopen("ScoreRecord.dat", "r");

	rewind(fp);

	char buffer[100];
	int count = 0;

	char** dataList = NULL;
	size_t dataSize = 0;
	*/

	int nFrame, nStay;
	int x, y;

	showcursor(FALSE);
	randomize();
	clrscr();

	//�� ����
	for (x = 0; x < 16; x++) {
		putsxy(29 + (x * 2), 1, arTile[WALL]);
	}
	for (x = 0; x < 4; x++) {
		for (y = 0; y < 4; y++) {
			putsxy(29 + (x * 10), y + 2, arTile[WALL]);
		}
	}

	for (x = 0; x < 5; x++) {
		putsxy(3 + (x * 2), 6, arTile[WALL]);
		putsxy(77 + (x * 2), 6, arTile[WALL]);
		putsxy(3 + (x * 2), 11, arTile[WALL]);
		putsxy(77 + (x * 2), 11, arTile[WALL]);
	}
	for (y = 0; y < 4; y++) {
		putsxy(3, y + 7, arTile[WALL]);
		putsxy(85, y + 7, arTile[WALL]);
	}

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

	//�̸����� ����
	for (int i = 0; i < 3; i++) {
		BrickList[i] = random(sizeof(Shape) / sizeof(Shape[0]));
	}

	// ��ü ���� ����
	for (; 1;) {
		nFrame = CheckLevel();
		brick = BrickList[0];
		BrickList[0] = BrickList[1];
		BrickList[1] = BrickList[2];
		BrickList[2] = random(sizeof(Shape) / sizeof(Shape[0]));

		//�̸�����->���� ��
		for (int j = 0; j < 3; j++) {
			int px = 0;
			int py = 4;
			switch (BrickList[j])
			{
			case 0:
				px = 33 + (j * 10);
				break;
			case 1:
				px = 33 + (j * 10);
				py -= 1;
				break;
			case 2:
			case 3:
			case 4:
			case 5:
				px = 34 + (j * 10);
				break;
			case 6:
				px = 34 + (j * 10);
				py -= 1;
				break;
			}
			for (int i = 0; i < 4; i++) {
				putsxy(px + (Shape[BrickList[j]][0][i].x) * 2, py + Shape[BrickList[j]][0][i].y, arTile[BRICK]);
			}
		}

		nx = BW / 2;
		ny = 2;
		rot = 0;
		dupl = 0;
		PrintBrick(TRUE);

		if (GetAround(nx, ny, brick, rot) != EMPTY) break;

		// ���� �ϳ��� �ٴڿ� ���� �������� ����
		nStay = nFrame;
		for (; 2;) {
			if (--nStay == 0) {
				nStay = nFrame;
				if (MoveDown()) break;
			}
			if (ProcessKey()) break;
			delay((DWORD)speed);
		}

		for (int j = 0; j < 3; j++) {
			int px = 0;
			int py = 4;
			switch (BrickList[j])
			{
			case 0:
				px = 33 + (j * 10);
				break;
			case 1:
				px = 33 + (j * 10);
				py -= 1;
				break;
			case 2:
			case 3:
			case 4:
			case 5:
				px = 34 + (j * 10);
				break;
			case 6:
				px = 34 + (j * 10);
				py -= 1;
				break;
			}
			for (int i = 0; i < 4; i++) {
				putsxy(px + (Shape[BrickList[j]][0][i].x) * 2, py + Shape[BrickList[j]][0][i].y, " ");
			}
		}
	}
	clrscr();

	putsxy(40, 10, "G A M E  O V E R");
	gotoxy(40, 13);
	printf("S C O R E  :  %d\n\n\n\n\n\n\n\n\n\n\n", score);

	FILE* scoreFile;
	fopen_s(&scoreFile, "score.dat", "wt");
	if (scoreFile != NULL) {
		fprintf(scoreFile, "%d", score);
		fclose(scoreFile);
	}

	putsxy(20, 30, "\n");
	showcursor(TRUE);
}

void DrawScreen()
{
	for (int x = 0; x < BW + 2; x++) {
		for (int y = 0; y < BH + 2; y++) {
			putsxy(BX + x * 2, BY + y, arTile[board[x][y]]);
		}
	}

	putsxy(90, 3, "Tetris Ver 1.0");
	putsxy(90, 5, "�¿�:�̵�, ��:ȸ��, �Ʒ�:����");
	putsxy(90, 6, "����:���� ����");
	gotoxy(90, 10);
	printf("SCORE : %d\n", score);
	gotoxy(90, 12);
	printf("%d COMBO!\n", combo);
	gotoxy(90, 14);
	printf("%d LEVEL(%d)\n", level, exp);
}

BOOL ProcessKey()
{
	if (kbhit()) {
		int ch = getch();
		if ((ch == 0xE0 || ch == 0) && nx > BW / 2) {
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
			case ENTER:
				putsxy(40, 15, "P A U S E");
				ch = getch();
				putsxy(40, 15, " ");
				for (int x = 14; x < 18; x++) {
					putsxy(BX + x * 2, 15, arTile[board[x][9]]);
					putsxy(BX + x * 2 + 1, 15, " ");
				}
				PrintBrick(TRUE);
			}
		}


		if ((ch == W || ch == A || ch == S || ch == D) && nx <= BW / 2) {
			switch (ch) {
			case 97:
				if (GetAround(nx - 1, ny, brick, rot) == EMPTY) {
					PrintBrick(FALSE);
					nx--;
					PrintBrick(TRUE);
				}
				break;
			case D:
				if (GetAround(nx + 1, ny, brick, rot) == EMPTY) {
					PrintBrick(FALSE);
					nx++;
					PrintBrick(TRUE);
				}
				break;
			case W:
				if (GetAround(nx, ny, brick, (rot + 1) % 4) == EMPTY) {
					PrintBrick(FALSE);
					rot = (rot + 1) % 4;
					PrintBrick(TRUE);
				}
				break;
			case S:
				if (MoveDown()) {
					return TRUE;
				}
				break;
			}
		}
		if (ch == HOLD) {
			if (dupl == 0) {
				int px = 0;
				int py = 9;

				for (int i = 0; i < 4; i++) {
					gotoxy(BX + (Shape[brick][rot][i].x + nx) * 2, BY + Shape[brick][rot][i].y + ny);
					puts(arTile[EMPTY]);
				}

				if (nx <= BW / 2) {
					if (hold[0] == -1) {
						hold[0] = brick;

						switch (hold[0])
						{
						case 0:
							px = 7;
							break;
						case 1:
							px = 7;
							py -= 1;
							break;
						case 2:
						case 3:
						case 4:
						case 5:
							px = 8;
							break;
						case 6:
							px = 8;
							py -= 1;
							break;
						}
						for (int i = 0; i < 4; i++) {
							putsxy(px + (Shape[hold[0]][0][i].x) * 2, py + Shape[hold[0]][0][i].y, arTile[BRICK]);
						}

						return TRUE;
					}
					else {
						switch (hold[0])
						{
						case 0:
							px = 7;
							break;
						case 1:
							px = 7;
							py -= 1;
							break;
						case 2:
						case 3:
						case 4:
						case 5:
							px = 8;
							break;
						case 6:
							px = 8;
							py -= 1;
							break;
						}
						for (int i = 0; i < 4; i++) {
							putsxy(px + (Shape[hold[0]][rot][i].x) * 2, py + Shape[hold[0]][rot][i].y, " ");
						}

						int temp = brick;
						brick = hold[0];
						hold[0] = temp;

						py = 9;
						switch (hold[0])
						{
						case 0:
							px = 7;
							break;
						case 1:
							px = 7;
							py -= 1;
							break;
						case 2:
						case 3:
						case 4:
						case 5:
							px = 8;
							break;
						case 6:
							px = 8;
							py -= 1;
							break;
						}
						for (int i = 0; i < 4; i++) {
							putsxy(px + (Shape[hold[0]][0][i].x) * 2, py + Shape[hold[0]][0][i].y, arTile[BRICK]);
						}
					}
				}
				else {
					if (hold[1] == -1) {
						hold[1] = brick;

						switch (hold[1])
						{
						case 0:
							px = 79;
							break;
						case 1:
							px = 79;
							py -= 1;
							break;
						case 2:
						case 3:
						case 4:
						case 5:
							px = 80;
							break;
						case 6:
							px = 80;
							py -= 1;
							break;
						}
						for (int i = 0; i < 4; i++) {
							putsxy(px + (Shape[hold[1]][0][i].x) * 2, py + Shape[hold[1]][0][i].y, arTile[BRICK]);
						}

						return TRUE;
					}
					else {
						switch (hold[1])
						{
						case 0:
							px = 79;
							break;
						case 1:
							px = 79;
							py -= 1;
							break;
						case 2:
						case 3:
						case 4:
						case 5:
							px = 80;
							break;
						case 6:
							px = 80;
							py -= 1;
							break;
						}
						for (int i = 0; i < 4; i++) {
							putsxy(px + (Shape[hold[1]][rot][i].x) * 2, py + Shape[hold[1]][rot][i].y, " ");
						}

						int temp = brick;
						brick = hold[1];
						hold[1] = temp;

						py = 9;
						switch (hold[1])
						{
						case 0:
							px = 79;
							break;
						case 1:
							px = 79;
							py -= 1;
							break;
						case 2:
						case 3:
						case 4:
						case 5:
							px = 80;
							break;
						case 6:
							px = 80;
							py -= 1;
							break;
						}
						for (int i = 0; i < 4; i++) {
							putsxy(px + (Shape[hold[1]][0][i].x) * 2, py + Shape[hold[1]][0][i].y, arTile[BRICK]);
						}
					}
				}

				for (int i = 0; i < 4; i++) {
					gotoxy(BX + (Shape[brick][rot][i].x + nx) * 2, BY + Shape[brick][rot][i].y + ny);
					puts(arTile[BRICK]);
				}
				dupl = 1;
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

	// ������ ������ Ÿ�� ��� �� ���� ū ���� ã�´�.
	for (int i = 0; i < 4; i++) {
		k = max(k, board[x + Shape[b][r][i].x][y + Shape[b][r][i].y]);
	}
	return k;
}

BOOL MoveDown()
{
	end = clock();
	if (((double)(end - start)) / CLOCKS_PER_SEC > 7) {
		combo = 0;
		gotoxy(90, 12);
		printf("%d COMBO!\n", combo);
	}
	// �ٴڿ� ������� ����á���� �����ϰ� TRUE�� �����Ѵ�.
	if (GetAround(nx, ny + 1, brick, rot) != EMPTY) {
		TestFull();
		score += PlusScore(combo);
		if (level != 10) {
			/**/
			exp += 5;
		}
		CheckLevel();
		gotoxy(90, 10);
		printf("SCORE : %d\n", score);
		gotoxy(90, 14);
		printf("%d LEVEL(%d)\n", level, exp);
		return TRUE;
	}
	// ���� ���߿� �� ������ ��ĭ �Ʒ��� ������.
	PrintBrick(FALSE);
	ny++;
	PrintBrick(TRUE);
	return FALSE;
}

void TestFull()
{
	// �ٴڿ� �������� ���� ���
	for (int i = 0; i < 4; i++) {
		board[nx + Shape[brick][rot][i].x][ny + Shape[brick][rot][i].y] = BRICK;
	}

	// �������� ������ ���� ����
	for (int y = 1; y < BH + 1; y++) {
		BOOL bFull = TRUE;
		for (int x = 1; x < BW + 1; x++) {
			if (board[x][y] == EMPTY) {
				bFull = FALSE;
				break;
			}
		}
		// ������ ���� á���� �� ���� �����Ѵ�.
		if (bFull) {
			//exp += 1;
			if (combo == 0) {
				combo++;
			}
			else {
				end = clock();
				if (((double)(end - start)) / CLOCKS_PER_SEC <= 7) {
					combo++;
				}
				else {
					combo = 0;
				}
			}
			for (int ty = y; ty > 1; ty--) {
				for (int x = 1; x < BW + 1; x++) {
					board[x][ty] = board[x][ty - 1];
				}
			}
			DrawScreen();
			start = clock();
			delay(200);
		}
	}
}

int PlusScore(int combo) {
	if (combo == 0 || combo == 1) {
		return 100;
	}
	else {
		return 100 + (combo / 100 + 1) * 10;
	}
}

int CheckLevel() {
	if (exp == 10 && level != 10) {
		level += 1;
		exp = 0;
	}
	switch (level)
	{
	case 1:
		speed = 40;
		return 20;
	case 2:
		speed = 30;
		return 20;
	case 3:
		speed = 20;
		return 20;
	case 4:
	case 5:
		speed = 15;
		return 15;
	case 6:
	case 7:
	case 8:
	case 9:
		speed = 15;
		return 10;
	case 10:
		speed = 15;
		return 5;
	default:
		return 20;
		break;
	}
}

int compare(const int* a, const int* b) {
	return (*b - *a);
}