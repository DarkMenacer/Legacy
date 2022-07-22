/* 
    **************************(INCOMPLETE)**************************
    DATA STRUCTURE: stack 

    CODE:   1) uses linked list
            2) no menu but friendly function names
    
    FUNCTIONS CODED: (INCOMPLETE)
            1) create_stack          3) push
            2) display               4) pop   

    NOTE:   1) (INCOMPLETE)

    EXAMPLE USED: 
           
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct stack{
    unsigned size;
    struct node *head;
    struct node *traveller;
};

struct stack *create(unsigned size){
    struct stack *new = (struct stack *)malloc(sizeof(struct stack));
    new->size = size;
    new->head = NULL;
    new->traveller = NULL;
    return new;
}

struct node *push(struct stack *S, int data){
    struct node *creator = S->traveller;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    if(S->head == NULL){
        S->head = new;
        creator = new;
    }
    else{
        creator->next = new;
        creator = new;
    }
    S->traveller = creator;
    new->next = 0;
    return new;
}

void display(struct stack S){
    struct node *displayer = S.head;
    int i =1;
    printf("\nFollowing are the elements of the stack\n");
    while(displayer != 0){
        printf("%d) %d\n",i,displayer->data);
        displayer = displayer->next;
        i++; 
    }
}

void pop(struct stack *S){
    struct stack popper = *S;
    while(popper.head->next != NULL){
        
    }
}

int main(){
    struct stack S1 = *create(10);
    struct node N1 = *push(&S1,3);
    struct node N2 = *push(&S1,6);
    struct node N3 = *push(&S1,9);
    display(S1);
    pop(&S1);
    display(S1);
    return 0;
}