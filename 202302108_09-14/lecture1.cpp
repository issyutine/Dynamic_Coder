//lecture 1


#include <stdio.h>
#include <stdlib.h>

int main(void) {

	system("title 정수 1개 입력 후 출력");

	int num;
	printf("정수를 입력하세요. :");
	scanf_s("%d", &num);
	printf("키보드로 입력받은 값은 %d 입니다.\n", num);

	return 0;

}
