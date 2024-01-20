#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {

	int data;
	struct _NODE* next;


}NODE;

NODE* head = NULL;
NODE* tail = NULL;

int main() {

	while (1) {

		int input;
		printf("연결할 데이터를 입력하세요. ");
		scanf_s("%d", &input);

		if (input <= 0) break;

		NODE* newnode = (NODE*)malloc(sizeof(NODE));

		newnode->data = input;
		newnode->next = NULL;

		if (head == NULL) head = newnode;
		else tail->next = newnode;

		tail = newnode;

	}
	//탐색할 노드가 없을 때 까지 계속 탐색
	printf("연결리스트 현재 상태: ");
	NODE* cur = head;
	while (cur != NULL) {

		printf("%d", cur->data);
		cur = cur->next;

	}
	puts("");

	//노드 삭제
	while (1) {

		int k;
		printf("삭제할 데이터를 입력하세요. ");
		scanf_s("%d", &k);

		if (k <= 0) break;

		int search = 0;
		NODE* cur_prev = NULL;
		cur = head;
		while (cur != NULL) {

			if (cur->data == k) {

				search = 1;
				break;

			}

			cur_prev = cur;
			cur = cur->next;

		}

		if (search == 1) {

			printf("%d를 삭제합니다.", k);
			if (cur == head)head = cur->next;
			else cur_prev->next = cur->next;

			free(cur);
			cur == NULL;


		}
		else {

			printf("%d를 찾을 수 없습니다.\n", k);

		}

		printf("(삭제 후)연결리스트 현재 상태: ");
		cur = head;
		while (cur != NULL) {

			printf("%d", cur->data);
			cur = cur->next;

		}
		puts("");
	}

}