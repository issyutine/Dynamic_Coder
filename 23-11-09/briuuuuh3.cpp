#include <stdio.h>

void Swap(int* pa, int* pb) {

	int save;
	save = *pa;
	*pa = *pb;
	*pb = save;

}

int main(void) {

	int a;
	int b;

	scanf_s("%d %d", &a, &b);
	Swap(&a, &b);
	printf("%d %d", a, b);

}