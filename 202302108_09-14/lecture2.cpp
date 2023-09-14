#include <stdio.h>
#include <stdlib.h>

int main(void) {

	system("title 배열로 문자열 처리하기");

	char ch;
	char str[10];

	printf("문자를 입력하세요 : ");
	scanf_s("%c", & ch, sizeof(ch));

	printf("문자열을 입력하세요 : ");
	scanf_s("%s", &str, sizeof(str));

	printf("입력한 문자를 출력합니다 : %c \n", ch);
	printf("입력한 문자열을 출력합니다 : %s \n", str);

	return 0;

}