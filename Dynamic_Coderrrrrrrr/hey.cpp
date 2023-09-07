
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


