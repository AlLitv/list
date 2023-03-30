#include <stdio.h>
#include <stdlib.h>
#include "list.h"



int main(int argc, char *argv){
    const int count = 100;
    int arr[count];
    for (int i = 0; i < count; i++)
    {
        arr[i] = rand() % 100 - 50;
    }
    Node *head = NULL;
    fromArray(&head, arr, count);
    insert(head, 0, 129432);
    print_list(head);
    return 0;
}