#include <stdio.h>

int main(void) {

	char season;

	printf("봄 : A 또는 a\n");
	printf("여름 : S 또는 s\n");
	printf("가을 : D 또는 s\n");
	printf("겨울 : F 또는 f\n");
	printf("좋아하는 계절에 해당하는 알파벳 입력 : ");
	scanf_s("%c", &season, sizeof(season));

	switch (season) {

	case 'A':
		
	

	case 'a':

		printf("봄");
		break;

	case 'S':

		

	case 's':

		printf("여름");
		break;

	case 'D':

	

	case 'd':

		printf("가을");
		break;

	case 'F':

	

	case 'f':

		printf("겨울");
		break;

	}

	printf("\n");

	printf("좋아하는 계절은 %c 입니다.", season);

	return 0;

}