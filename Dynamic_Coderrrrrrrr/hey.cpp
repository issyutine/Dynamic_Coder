
/*  c실습 1일차 과제

#include <stdio.h>

int main(void) {



	int num;

	scanf_s("%d", &num);

	printf("%d층 피라미드\n", num);

	for (int i = 0; i < num; i++) {




		for (int j = i; j <= num - 1; j++) {

			printf(" ");

		}

		for (int c = 0; c <= (i * 2); c++) {

			printf("*");

		}

		printf("\n");

	}

	return 0;

}

*/


//Day Two.




//lecture 1
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	system("title 정수 1개 입력 후 출력");

	int num;
	printf("정수를 입력하세요. :");
	scanf_s("%d", &num);
	printf("키보드로 입력받은 값은 %d 입니다.\n",num);

	return 0;

}
