#include <stdio.h>

int add(int num) {

	printf("�Ҽ����� Ȯ���� ���� �Է��ϼ��� : ");
	scanf_s("%d", &num);
	if ((num == 1) || (num == 2)) {

		printf("�ش� ���� �Ҽ��Դϴ�.\n");

		return 1;
	}
	else {

		printf("�ش� ���� �Ҽ��� �ƴմϴ�.\n");
		return 0;

	}
	

}

int main(void) {

	int num;
	scanf_s("%d", &num);

	printf("%d\n", add(num));

	return 0;


}

