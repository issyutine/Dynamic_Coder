#include <stdio.h>

int main(void) {

	int a;
	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s("%d", &a);

	if (a % 2 == 0) {

		printf("¦���Դϴ�.\n");

	}
	else {

		printf("Ȧ���Դϴ�.\n");

	}

	return 0;

}