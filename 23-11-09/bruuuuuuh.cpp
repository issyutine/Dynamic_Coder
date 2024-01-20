#include <stdio.h>

double Div(double a, double b) {

	double div = a / b;
	return div;

}

int main(void) {

	int a, b;

	scanf_s("%d", &a);
	scanf_s("%d", &b);

	printf("%lf", Div(a, b));
	return 0;


}