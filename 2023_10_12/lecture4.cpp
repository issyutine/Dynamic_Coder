#include <stdio.h>

int main(void) {

	int score[5] = { 87, 92, 89, 98, 78 };
	int cnt;

	printf("score[5] = { 87, 92, 89, 98, 78 } 배열 요소 출력\n"); //배열도 포인터임!

	for (cnt = 0; cnt < 5; cnt++)
		printf("score[%d] = [%d]\n", cnt, score[cnt]);
	return 0;
}

/*     int* p_score = score; (배열도 포인터라& 생략가능)
 
 for (int i = 0; i < 3; i++){
     printf(("%d\n", score[i]);
	 }


	 or

	 int*p_score = &score ㄱㄴ
*/
