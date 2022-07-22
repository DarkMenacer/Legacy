#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#define cin(x) scanf("%d",&x)
#define cout_var(x) printf("%d\n",x)
#define display(x,n) for(int i=0;i<n;++i){printf("%d ",x[i]);}printf("\n")
#define nl printf("\n")
#define here printf("here\n")
#define CAPACITY 10
#define PRODUCER_COUNT 1
#define CONSUMER_COUNT 2

int buffer[CAPACITY];
int count = 0;
pthread_mutex_t m;
sem_t full_spaces, empty_spaces;

void *produce(void *par){
    while(1){
        int x = rand()%100;
        sem_wait(&empty_spaces);
        pthread_mutex_lock(&m);
        buffer[count++] = x;
        sem_post(&full_spaces);
        pthread_mutex_unlock(&m);
    }    
}

void *consume(void *par){
    while(1){
        sem_wait(&full_spaces);
        pthread_mutex_lock(&m);
        cout_var(buffer[--count]);
        sem_post(&empty_spaces);
        pthread_mutex_unlock(&m);
        sleep(1);
    }    
}


int main(){
    pthread_mutex_init(&m,NULL);
    sem_init(&full_spaces,0,0);
    sem_init(&empty_spaces,0,CAPACITY);
    pthread_t producers[PRODUCER_COUNT];
    pthread_t consumers[CONSUMER_COUNT];
    for(int i = 0;i<PRODUCER_COUNT;++i){pthread_create(&producers[i],NULL,produce,NULL);}
    for(int i = 0;i<CONSUMER_COUNT;++i){pthread_create(&consumers[i],NULL,consume,NULL);}
    for(int i = 0;i<PRODUCER_COUNT;++i){pthread_join(producers[i],NULL);}
    for(int i = 0;i<CONSUMER_COUNT;++i){pthread_join(consumers[i],NULL);}
    return 0;
}