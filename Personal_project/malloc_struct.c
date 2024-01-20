#include <stdio.h>
#include <stdlib.h>

struct student {

	int sno;
	int score;
	char name[10];

};

int main(void) {

	int num,sum = 0;
	printf("학생 수를 입력하세요: ");
	scanf_s("%d", &num);

	struct student* s = (struct student*)malloc(num * sizeof(struct student));
	for (int i = 0; i < num; i++) {

		printf("학생 %d-%d의 학번: ", num, i+1);
		scanf_s("%d", &s[i].sno);
		printf("학생 %d-%d의 성적: ", num, i+1);
		scanf_s("%d", &s[i].score);
		printf("학생 %d-%d의 이름: ", num, i+1);
		scanf_s("%s", s[i].name);
		printf("\n");

	}
	for (int j = 0; j < num; j++) {

		sum += s[j].score;

	}
	int mean = sum / num;

	printf("모든 점수: %d", sum);
	printf("평균: %d", mean);


	free(s);
	s = NULL;


}