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
		printf("please input the data: ");
		scanf_s("%d", &input);

		if (input <= 0) {
			break;
		}

		NODE* newnode = (NODE*)malloc(sizeof(NODE));
		newnode->data = input;
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
		}
		else {
			tail->next = newnode;
		}
		tail = newnode;
	}
	NODE* cur = head;
	while (cur != NULL) {

		printf("%d", cur->data);
		cur = cur->next;
	}
	while (1) {

		int k;
		printf("select to delete NODE: ");
		scanf_s("%d", &k);

		if (k <= 0) {
			break;
		}

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

			printf("delete %d\n", k);
			if (cur == head) {

				head = cur->next;
				
			}
			else {

				cur_prev->next = cur->next;
				free(cur);
				cur = NULL;
				
			}

		}
		else {

			printf("error!");

		}

	
	}
	cur = head;
	while (cur != NULL) {

		printf("%d", cur->data);
		cur = cur->next;

	}

}