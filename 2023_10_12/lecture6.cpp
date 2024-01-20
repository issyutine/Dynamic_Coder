#include <stdio.h>

void swap(int* p_a, int* p_b) {

	int save;  //포인터 저장공간
	save = *p_a;
	*p_a = *p_b;
	*p_b = save;

}

void selection_sort(int* arr, int n) {

	for (int k = 0; k < n - 1; k++) {

		for (int m = k + 1; m < n; m++) {

			if (arr[k] > arr[m]) {

				swap(&arr[k], &arr[m]);

			}

		}

	}

}

int main(void) {

	int n; //배열의 개수를 입력받는 int�갋변펯E
	int arr[100]; //배열의 한컖E설정
	printf("배열의 개수를 입력하십시오.\n");
	scanf_s("%d", &n);
	printf("\n");

	//배열의 개펯E만큼 입력받콅E

	for (int i = 0; i < n; i++) {

		printf("%d 인덱스 입력: ", i);
		scanf_s("%d", &arr[i]);
		printf("\n");
	}

	//현픸E입력한 배열 출력
	printf("현픸E정렬 픸E값");
	for (int j = 0; j < n; j++) {

		printf("%d ", arr[j]);

	}
	printf("\n\n");
	selection_sort(&arr[0], n);

	printf("정렬 후 값");
	for (int j = 0; j < n; j++) {

		printf("%d ", arr[j]);

	}


	return 0;

}