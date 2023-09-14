#include <stdio.h>

int main(void) {

	int a;
	printf("숫자를 입력하세요 : ");
	scanf_s("%d", &a);

	if (a % 2 == 0) {

		printf("짝수입니다.\n");

	}
	else {

		printf("홀수입니다.\n");

	}

	return 0;

}