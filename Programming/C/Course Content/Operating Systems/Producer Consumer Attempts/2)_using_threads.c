/*
    Date:-                          26 March 2022
    Name of the approach:-          Naive Approach
    Feature:-                       Threads
    One line description:-          2 Threads, Producer and Consumer are created and are made to run in a loop          
    How it beats its predecessor:-  Threads share address space (hence memory), unlike processes (which create a copy every time they are created)
    Points of failure:-             1) Not handling race conditions

    Explanation:-

*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define LIMIT 10
#define INITIAL_VAL 0

int data = INITIAL_VAL;

void *produce(){
    while(1){
        if(data < LIMIT){
            int init_data = data;
            printf("Producer enters,(data = %d)  ",data);
            data+=1;
            printf("Producer exits,(data = %d)\n",data);
            if(data != init_data + 1){printf("THIS SHOULD NOT BE PRINTED\n");}
            if(data < 0 || data > LIMIT){exit(0);}
        }
    }
    pthread_exit(0);
}

void *consume(){
    while(1){
        if(data > 0){
            int init_data = data;
            printf("Consumer enters,(data = %d)  ",data);
            data-=1;
            printf("Consumer exits,(data = %d)\n",data);
            if(data != init_data - 1){printf("THIS SHOULD NOT BE PRINTED\n");}
            if(data < 0 || data > LIMIT){exit(0);}
        }
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