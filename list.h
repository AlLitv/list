#pragma once
typedef struct HeadList
{
    int value;
    Node* next;
    
} HeadList;

typedef struct Node
{
    int value;
    struct Node *next; 
} Node;

void push(Node**, int);
int pop(Node**);
void print_list(Node*);
Node* getNth(Node*, int);
Node* getLast(Node*);
void pushBack(Node**, int);
int popBack(Node**);
void insert(Node*, int, int);
void fromArray(Node**, int*, size_t);