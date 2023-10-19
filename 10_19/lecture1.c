/*#include <stdio.h>
#include <stdlib.h>
int main(void) {

	int *su;
	printf("학생수 입력: ");
	scanf_s("%d", &su);
	su = (int*)malloc(*su * sizeof(int));
	for (int i = 0; i < su; i++) {

		printf("학생 # 3-%d 성적 입력 : ");
		scanf_s("%d", su[i]);
		printf("\n");

	}

}  */

#include <stdio.h>
#include <stdlib.h>

int main() {

	int num_students;
	printf("학생 수 입력: ");
	scanf_s("%d", &num_students);

	int* scores;
	scores = (int*)malloc(sizeof(int) * num_students);

	for (int i = 0; i < num_students; i++) {

		printf("학생 # %d-%d 성적 입력: ", num_students, i + 1);
		scanf_s("%d", scores + i);

	}

	int sum = 0;
	for (int i = 0; i < num_students; i++) {

		sum += scores[i];

	}

	printf("%d\n", sum);

}