#include <stdio.h>

int main(void) {

	int score;

	res:
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &score);

	if ((score > 100) || (score < 0)) {

		printf("�߸� �Է��ϼ̽��ϴ�!\n");
		goto res;

	}
	else
	{

		if (score >= 90) {

			printf("A�����Դϴ�.\n");

		}
		else if (score >= 80) {

			printf("B�����Դϴ�.");

		}
		else if (score >= 70) {

			printf("C�����Դϴ�.");

		}
		else if (score >= 60) {

			printf("D�����Դϴ�.");

		}
		else {

			printf("F�����Դϴ�.");

		}

	}
	return 0;
}