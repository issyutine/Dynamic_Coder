#include <stdio.h>

void swap(int* pa, int* pb) {

	int save;
	save = *pa;
	*pa = *pb;
	*pb = save;

}

void sort(int* arr, int len) {

	for (int i = 0; i < len - 1; i++) {

		for (int j = i; j < len; j++) {

			if (arr[i] > arr[j]) {

				swap(&arr[i], &arr[j]);

			}

		}

	}

}

int main(){

	int arr[5] = { 4,2,5,3,1 };
	int length = sizeof(arr) / sizeof(arr[0]);
	printf("check the arr's length %d\n", length);
	
	for (int i = 0; i < length; i++) {

		printf("pre sort: %d\n", arr[i]);

	}

	sort(&arr[0], length);



}