#include <stdio.h>
#include <stdlib.h>

struct Student {

	int sno;
	char name[10];
	int score;

};

int main(void) {

	struct Student* base;

	int num, i;
	printf("가져올 학생 정보를 입력하세요.");
	scanf("%d", &num);
	base = (struct Student*)malloc(sizeof(struct Student) * num);

	for (i = 0; i < num; i++) {
		printf("학생%d의 정보를 입력하십시오 (학번, 이름, 성적 순):", i + 1);
		scanf("%d %s %d", &base[i].sno, base[i].name, &base[i].score);
		printf("\n");


	}





}