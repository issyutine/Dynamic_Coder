#include <stdio.h>

int main(void) {

	int score;

	res:
	printf("점수를 입력하세요 : ");
	scanf_s("%d", &score);

	if ((score > 100) || (score < 0)) {

		printf("잘못 입력하셨습니다!\n");
		goto res;

	}
	else
	{

		if (score >= 90) {

			printf("A학점입니다.\n");

		}
		else if (score >= 80) {

			printf("B학점입니다.");

		}
		else if (score >= 70) {

			printf("C학점입니다.");

		}
		else if (score >= 60) {

			printf("D학점입니다.");

		}
		else {

			printf("F학점입니다.");

		}

	}
	return 0;
}