#include <stdio.h>

int main(void) {

	for (int a = 0; a < 5; a++) {

		for (int b = 0; b < a; b++) {

			printf("  ");

		}

		

		if (a % 2 == 0) {

			printf("| 0 |");

		}
		else {

			printf("| X |");

		}


		
		printf("\n-------------------------\n");

}

	return 0;

}