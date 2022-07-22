/* Peterson's Solution
    ****** NOTE: Use control-C (^C) to terminate the code

    Only 2 threads at once problem
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define LIMIT 10
#define INITIAL_VAL 0

int data = INITIAL_VAL;
int key = 0;
//if key = 0, Producer has critical region, if key = 1, consumer has critical region

void *produce(){
    while(1){
        while(key){}
        if(data < LIMIT){
            int init_data = data;
            printf("Producer enters,(data = %d)  ",data);
            data+=1;
            printf("Producer exits,(data = %d)\n",data);
            if(data != init_data + 1){printf("THIS SHOULD NOT BE PRINTED\n");}
            key = rand()%2;
        }
        else{key=1;}
    }
    pthread_exit(0);
}

void *consume(){
    while(1){
        while(!key){}
        if(data > 0){
            int init_data = data;
            printf("Consumer enters,(data = %d)  ",data);
            data-=1;
            printf("Consumer exits,(data = %d)\n",data);
            if(data != init_data - 1){printf("THIS SHOULD NOT BE PRINTED\n");}
            key = rand()%2;
        }
        else{key = 0;}
    }
    pthread_exit(0);
}

//****** NOTE: Use control-C (^C) to terminate the code

int main(){
    pthread_t P, C;
    pthread_create(&P,NULL,produce,NULL);
    pthread_create(&C,NULL,consume,NULL);
    pthread_join(P,NULL);
    pthread_join(C,NULL);
    return 0;
}