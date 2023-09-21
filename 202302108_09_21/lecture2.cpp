#include <stdio.h>

int sum(double num1, double num2) {

	printf("더하기를 시작합니다.\n");
	printf("%lf + %lf = %lf", num1, num2, num1 + num2);
	return num1 + num2;

}

int sub(double num1, double num2) {

	printf("빼기를 시작합니다.\n");
	printf("%lf - %lf = %lf", num1, num2, num1 - num2);
	return num1 - num2;

}

int mul(double num1, double num2) {

	printf("곱셈을 시작합니다.\n");
	printf("%lf * %lf = %lf", num1, num2, num1 * num2);
	return num1 * num2;

}

int div(double num1, double num2) {


	printf("나눗셈을 시작합니다.\n");
		printf("%lf / %lf = %lf", num1, num2, num1 / num2);
		return num1 / num2;
}

void calculator(int selector) {

	double num1, num2;

	printf("숫자 1을 입력하시오 :");
	scanf_s("%lf", &num1);

	printf("숫자 2를 입력하시오 :");
	scanf_s("%lf", &num2);

	if (selector == 1) sum(num1, num2);
	else if (selector == 2) sub(num1, num2);
	else if (selector == 3) mul(num1, num2);
	else if (selector == 4) div(num1, num2);
}



int main(void) {

	int sel;

	printf("1. 더하기 2.빼기 3.곱하기 4.나누기 : ");
	scanf_s("%d", &sel);

	calculator(sel);

	return 0;

}