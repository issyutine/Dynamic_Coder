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
            //게임시작
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
    printf("        #####    #####    #####    #####    #####    ###  \n");
    printf("          #      #          #     #     #     #     #     \n");
    printf("          #      ####       #     # ###       #     ####  \n");
    printf("          #      #          #     #    #      #         # \n");
    printf("          #      #####      #     #     #   #####   ####  \n");
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