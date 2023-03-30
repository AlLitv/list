#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void push(Node **head, int data){
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = *head;
    *head = tmp;
}

int pop(Node **head){
    Node* prev = NULL;
    int val;
    if (head == NULL) exit(-1);
    prev =(*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

void print_list(Node* head){
    int count = 0;
    do{
        printf("item %d: %d\n", count, head->value);
        count++;
    }while (head = head->next);       
}
Node* getNth(Node* head, int n){
    int count = 0;
    while (count < n && head)
    {
        head = head->next;
        count++;
    }
    return head;
}

Node* getLast(Node *head) {
    if (head == NULL) return NULL;
    while (head->next) head = head->next;
    return head;
}

void pushBack(Node **head, int value){
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    if(*head == NULL){
        *head = tmp;
        return;
    }
    Node *last = getLast(*head);
    last->next = tmp;
    return;
}

int popBack(Node **head){
    Node* pFwd = NULL; // текущий узел
    Node* pBwd = NULL; // предыдущий узел
    int value;
    if(!head) exit(-1);
    if (!(*head)) exit(-1);
    pFwd = *head;
    while(pFwd->next){
        pBwd = pFwd;
        pFwd = pFwd->next;
    }
    if(pBwd == NULL){
        value = pFwd->value;
        free(*head);
        *head = NULL;
        return value;
    }else{
        value = pFwd->value;
        free(pFwd->next);
        pBwd->next = NULL;
        return value;
    }
}

void insert(Node *head, int nam_node ,int value){
    Node *tmp = NULL;
    if(head->next == NULL){
        pushBack(&head, value);
        return;
    }
    head = getNth(head, nam_node);
    tmp = (Node*)malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = head->next;
    head->next = tmp;

}
void fromArray(Node **head, int *arr, size_t size) {
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        pushBack(head, arr[i]);
    } while(i--!=0);
}