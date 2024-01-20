#include <stdio.h>
#include <stdlib.h>

int main() {

	int num;
	printf("학생 수 입력: ");
	scanf_s("%d", &num);

	int* mal_s;
	mal_s = (int*)malloc(num * sizeof(int));

	int sum = 0;

	for (int i = 0; i < num; i++) {

		printf("학생 # %d-%d 성적 입력: ", num, i + 1);
		scanf_s("%d", &mal_s[i]);
		printf("\n");
		sum += mal_s[i];
	}
	printf("총점: %d\n", sum);
	int mean = sum / num;
	for (int j = 0; j < num; j++) {

		printf("학생 # %d-%d 성적 출력: %d", num, j + 1, mal_s[j]);
		printf("\n");

	}
	printf("평균 점수: %d ", mean);
	free (mal_s);
	mal_s = NULL;
	return 0;

}