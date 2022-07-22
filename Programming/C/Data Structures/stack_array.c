/* 
    DATA STRUCTURE: stack

    CODE:   1) uses array
            2) no menu but friendly function names
    
    FUNCTIONS CODED:
            1) create_stack          3) push
            2) display               4) pop   

    NOTE:   1) Contains SIZE MACRO

    EXAMPLE USED: 5 10 15 19 --> 5 10 15
           
*/

#include <stdio.h>
#include <stdlib.h>
#define nl printf("\n")
#define SIZE 50        // SIZE OF THE STACK

struct stack{
    int size;
    int *array;
    int top;
};

struct stack *create(int size){
    struct stack *new = (struct stack *)malloc(sizeof(struct stack));
    new->size = size;
    new->array = (int*)malloc(size * sizeof(int));
    new->top = -1;
    return new;
}

void push(struct stack *in,int x){
    if(in->top == in->size){printf("OVERFLOW\nINCREASE SIZE\nProgram exits");exit(0);}
    in->array[++in->top] = x;
}

void pop(struct stack *in){
    if(in->top == -1){printf("UNDERFLOW\nProgram exits");exit(0);}
    in->top--;
}

void display(struct stack in){
    int i = 0;
    if(in.top == -1){printf("Stack empty\n");return;}
    while(1){
        if(i==in.top){printf("%d",in.array[i]);break;}
        printf("%d ",in.array[i++]);
    }
    nl;
}

int main(){
    struct stack first = *create(SIZE);
    push(&first,5);
    push(&first,10);
    push(&first,15);
    push(&first,19);
    display(first);
    pop(&first);
    display(first);
    return 0;
}