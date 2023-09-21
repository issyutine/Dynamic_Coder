#include <stdio.h>

int pac(int su) {
	
	if (su == 0) return 1;

	return su * pac(su - 1);
}

int main(void) {
	int su;
	printf("수를 입력하세요 : ");
	scanf_s("%d", &su);
	printf("%d", pac(su));

}