#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
void main() {
	PlaySound(TEXT("tetris.wav"), NULL, SND_FILENAME | SND_ASYNC);
	_getch(); //�̰� ������ ��� �� ��, ���� �� �ڵ� ����
}