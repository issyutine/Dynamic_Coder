#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int sum = 0;
	int input;
	int* score = (int*)malloc(input * sizeof(int));
	printf("please enter to play: ");
	scanf_s("%d", &input);

	for (int i = 0; i < input; i++) {

		printf("학생 # %d-%d 성적 입력: ", input, i + 1);
		scanf_s("%d", score[i]);
		sum += score[i];
	}
	printf("%d\n", sum);

	for (int j = 0; j < input; j++) {

		printf("학생 # %d-%d 성적 출력: %d\n", input, j + 1, score[j]);


	}

	return 0;
}