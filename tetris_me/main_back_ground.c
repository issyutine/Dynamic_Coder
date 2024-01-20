#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define M_UP 0
#define M_DOWN 1
#define M_LEFT 2
#define M_RIGHT 3
#define M_SUBMIT 4

int KeyControl();
void init();
void titleDraw();
int menuDraw();
void infoDraw();
void gotoxy_(int, int);

int main() {
    init();
    while (1) {
        titleDraw();
        int menuCode = menuDraw();
        if (menuCode == 0) {
            //���ӽ���
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
    printf("        #####    #####    #####    #####    #####    ###  \n");
    printf("          #      #          #     #     #     #     #     \n");
    printf("          #      ####       #     # ###       #     ####  \n");
    printf("          #      #          #     #    #      #         # \n");
    printf("          #      #####      #     #     #   #####   ####  \n");
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