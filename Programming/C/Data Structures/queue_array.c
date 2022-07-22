/* 
    DATA STRUCTURE: queue

    CODE:   1) uses array
            2) no menu but friendly function names
    
    FUNCTIONS CODED:
            1) create                3) enqueue
            2) display               4) dequeue

    NOTE:   1) Contains SIZE MACRO

    EXAMPLE USED: 4 1 3 --> 3 3 3 3 3 3    
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

struct queue{
    unsigned cap;
    int *ar;
    int head;
    int tail;
};

struct queue *create(unsigned n){
    struct queue *q =  (struct queue *) malloc(sizeof(struct queue));
    q->cap = n;
    q->head = 0;
    q->tail = 0;
    q->ar = (int*)malloc(n*sizeof(int));
    return q;
}

void enqueue(struct queue *q, int e){
    if(q->head == q->tail + 1){
        printf("\nQueue Full\n");
    }
    else{
        q->ar[q->tail] = e;
        printf("\n%d is added\n", e);
        if(q->tail==q->cap)
            q->tail = 0;
        else
            q->tail++;
    }
}

void dequeue(struct queue *q){
    if(q->head==q->tail){
        printf("\nQueue Empty\n");
    }
    else{
        printf("\n%d is removed\n",q->ar[q->head]);
        if(q->head == q->cap)
            q->head = 0;
        else
            q->head++;
    }
}

void display(struct queue q){
    int i;
    if(q.head>q.tail){
        for(i=q.head;i<=q.cap;i++){
            printf("%d ",q.ar[i]);
        }
        for(i=0;i<=q.tail-1;i++){
            printf("%d ",q.ar[i]);
        }
    }
    else{
        for(i=q.head;i<=q.tail-1;i++){
            printf("%d ",q.ar[i]);
        }
    }
}

int main(){
    struct queue Q;
    Q = *create(SIZE);
    enqueue(&Q,4);
    display(Q);
    enqueue(&Q,1);
    display(Q);
    enqueue(&Q,3);
    display(Q);
    dequeue(&Q);
    display(Q);
    enqueue(&Q,3);
    display(Q);
    dequeue(&Q);
    display(Q);
    enqueue(&Q,3);
    display(Q);
    enqueue(&Q,3);
    display(Q);
    enqueue(&Q,3);
    display(Q);
    enqueue(&Q,3);
    display(Q);
    enqueue(&Q,3);
    return 0;
}