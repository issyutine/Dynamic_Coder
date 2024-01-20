#include <stdio.h>

void swap(int* p_a, int* p_b) {

	int save;  //ﾆﾎﾅﾍ ﾀ惕蟆｣
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

	int n; //ｹ霑ｭﾀﾇ ｰｳｼｦ ﾀﾔｷﾂｹﾞｴﾂ intﾇ・ｺｯｼ・
	int arr[100]; //ｹ霑ｭﾀﾇ ﾇﾑｰ・ｼｳﾁ､
	printf("ｹ霑ｭﾀﾇ ｰｳｼｦ ﾀﾔｷﾂﾇﾏｽﾊｽﾃｿﾀ.\n");
	scanf_s("%d", &n);
	printf("\n");

	//ｹ霑ｭﾀﾇ ｰｳｼ・ｸｸﾅｭ ﾀﾔｷﾂｹﾞｱ・

	for (int i = 0; i < n; i++) {

		printf("%d ﾀﾎｵｦｽｺ ﾀﾔｷﾂ: ", i);
		scanf_s("%d", &arr[i]);
		printf("\n");
	}

	//ﾇ・ﾀﾔｷﾂﾇﾑ ｹ霑ｭ ﾃ箙ﾂ
	printf("ﾇ・ﾁ､ｷﾄ ﾀ・ｰｪ");
	for (int j = 0; j < n; j++) {

		printf("%d ", arr[j]);

	}
	printf("\n\n");
	selection_sort(&arr[0], n);

	printf("ﾁ､ｷﾄ ﾈﾄ ｰｪ");
	for (int j = 0; j < n; j++) {

		printf("%d ", arr[j]);

	}


	return 0;

}