#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {

	int data;
	struct _NODE* next;


}NODE;


void print_list(NODE* head) {

	NODE* cur = head->next;
	while (cur != NULL) {

		printf("%d", cur->data);
		cur = cur->next;

	}

}

void insert_node_last(NODE* head, int data) {

	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = data;
	newnode->next = NULL;

	NODE* cur = head;
	while (cur->next != NULL) {

		cur = cur->next;

	}
	cur->next = newnode;
}


void insert_node_first(NODE* head, int data) {

	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = data;
	newnode->next = head->next;
	head->next = newnode;

}

void delete_node_last(NODE* head) {

	NODE* cur = head->next;
	NODE* cur_prev = head;

	while (cur->next != NULL) {

		cur_prev = cur;
		cur = cur->next;

	}

	cur_prev->next = NULL;
	free(cur);

}

void delete_node_first(NODE* head) {

	NODE* cur = head->next->next;
	free(head->next);
	head->next = cur;

}


int main() {

	NODE* head = (NODE*)malloc(sizeof(NODE));
	head->next = NULL;

	NODE* n1 = (NODE*)malloc(sizeof(NODE));
	n1->data = 2;
	n1->next = head->next;
	head->next = n1;

	NODE* n2 = (NODE*)malloc(sizeof(NODE));
	n2->data = 5;
	n2->next = n1->next;
	n1->next = n2;

	insert_node_last(head, 3);
	insert_node_last(head, 4);

	insert_node_first(head, 5);

	print_list(head);

	delete_node_last(head);
	print_list(head);

	delete_node_first(head);
	print_list(head);
	return 0;

}