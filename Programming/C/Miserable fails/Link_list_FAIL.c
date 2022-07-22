/*
    MISERABLE FAIL #1  (29-04-2021)
        LESSON LEARNT : MEMORY ADDRESS OF A VARIABLE IS NON-MODIFIABLE
*/
#include <stdio.h>
#include <stdlib.h>
#define NIL 0

struct node{
    int key;
    int *prev;
    int *next;
};

struct list{
    int *head;
    int *tail;
    int *next;
};

struct list *create(){
    struct list *L = (struct list *)malloc(sizeof(struct list));
    L->head = NIL;
    L->tail = NIL;
    return L;
}

struct node *inserter(struct list *L, int k){
    struct node *N = (struct node *)malloc(sizeof(struct node));
    if(L->head == NIL)
        L->head = &N->key;
    else{
        N->prev = L->tail;
        &N->key = L->next;
    }
    N->key = k;
    L->tail = &N->key;
    N->next = &N->key + 1;
    L->next = &N->key + 1;
    return N;
}

void display(struct list L){
    printf("Displaying Linked List\n");
    printf("%d\n", *L.head);
}

int main(){
    struct list L1;
    L1 = *create();
    struct node n1 = *inserter(&L1,10);
    struct node n2 = *inserter(&L1,20);
    display(L1);


    return 0;
}