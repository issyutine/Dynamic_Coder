#include <stdio.h>

void swap(int *pa, int*pb) {

	int a_b = *pa;
	int b_b = *pb;

	* pa = b_b;
	*pb = a_b;




}

int main(void) {

	int a = 10;
	int b = 20;

	int* pt1 = &a;
	int* pt2 = &b;
	printf("a의 원래값 : %d, b의 원래값: %d", a, b);
	swap(&a, &b);
	printf("a의 원래값 : %d, b의 원래값: %d", a, b);
}