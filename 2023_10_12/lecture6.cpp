#include <stdio.h>

void swap(int* pa, int* pb) {
	int c = *pa;
	*pa = *pb;
	*pb = c;
}

void sort(int* arr) {

	for (int i = 0; i < 5; i++) {

		for (int j = i; j < 5; j++) {

			if (arr[i] > arr[j]) {
				swap(&arr[i], &arr[j]);

			}

		}
	}

}

int main() {

	int arr[5] = { 5, 1, 4, 3, 2 };
	printf("arr = %d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
	sort(&arr[0]);
	printf("reverce arr = %d, %d, %d, %d, %d", arr[0], arr[1], arr[2], arr[3], arr[4]);

	return 0;
}