#include <stdio.h>

int add(int num) {

	printf("소수인지 확인할 수를 입력하세요 : ");
	scanf_s("%d", &num);
	if ((num == 1) || (num == 2)) {

		printf("해당 수는 소수입니다.\n");

		return 1;
	}
	else {

		printf("해당 수는 소수가 아닙니다.\n");
		return 0;

	}
	

}

int main(void) {

	int num;
	scanf_s("%d", &num);

	printf("%d\n", add(num));

	return 0;


}

