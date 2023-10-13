#include <stdio.h>

void swap(int* p_a, int* p_b) {

	int save;  //������ �������
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

	int n; //�迭�� ������ �Է¹޴� int�� ����
	int arr[100]; //�迭�� �Ѱ� ����
	printf("�迭�� ������ �Է��Ͻʽÿ�.\n");
	scanf_s("%d", &n);
	printf("\n");

	//�迭�� ���� ��ŭ �Է¹ޱ�

	for (int i = 0; i < n; i++) {

		printf("%d �ε��� �Է�: ", i);
		scanf_s("%d", &arr[i]);
		printf("\n");
	}

	//���� �Է��� �迭 ���
	printf("���� ���� �� ��");
	for (int j = 0; j < n; j++) {

		printf("%d ", arr[j]);

	}
	printf("\n\n");
	selection_sort(&arr[0], n);

	printf("���� �� ��");
	for (int j = 0; j < n; j++) {

		printf("%d ", arr[j]);

	}


	return 0;

}