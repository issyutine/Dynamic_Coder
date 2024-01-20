#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {

    int data;
    struct _NODE* next;


}NODE;
//리스트 확인
void print_list(NODE* head) {

    printf("-------\n");
    NODE* cur = head->next;


    while (cur != NULL) {

        printf("%d ", cur->data);
        cur = cur->next;


    }
    printf("--------\n");
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

void node_first_delete(NODE* head) {

    NODE* cur = head->next->next;
    free(head->next);

    head->next = cur;

}

void node_last_delete(NODE* head) {

    NODE* cur = head->next;
    NODE* cur_prev = head;
    while (cur->next != NULL) {

        cur_prev = cur;
        cur = cur->next;

    }

    cur_prev->next = NULL;
    free(cur);

}



int main(void) {

    NODE* head = (NODE*)malloc(sizeof(NODE));
    head->next = NULL;

    NODE* n1 = (NODE*)malloc(sizeof(NODE));
    n1->data = 1;
    n1->next = head->next;
    head->next = n1;

    NODE* n2 = (NODE*)malloc(sizeof(NODE));
    n2->data = 3;
    n2->next = n1->next;
    n1->next = n2;;


    insert_node_last(head, 3);
    insert_node_last(head, 4);

    insert_node_first(head, 5);

    print_list(head);

    node_last_delete(head);
    print_list(head);

    node_first_delete(head);
    print_list(head);
    return 0;

}     