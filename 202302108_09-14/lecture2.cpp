#include <stdio.h>
#include <stdlib.h>

int main(void) {

	system("title �迭�� ���ڿ� ó���ϱ�");

	char ch;
	char str[10];

	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%c", & ch, sizeof(ch));

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf_s("%s", &str, sizeof(str));

	printf("�Է��� ���ڸ� ����մϴ� : %c \n", ch);
	printf("�Է��� ���ڿ��� ����մϴ� : %s \n", str);

	return 0;

}