/*
    Date:-                          24 April 2022
    Name of the approach:-          Peterson's Solution
    Feature:-                       Mutex
    One line description:-          Unsatisfactory but atleast Jack and Jill stay together
    How it beats its predecessor:-  Mutual Exclusion in critical section
    Points of failure:-             A lot of busy-waiting

    Explanation:-
        So what changed from last time? Unable to figure out a solution, you took help from our OS expert friend Peterson.
        He suggested using sticky notes (mutexes). Whenever in doubt, use a sticky note.
        Introduction of (sticky notes) mutexes solves almost all synchronization issues. Mutexes are just fancy booleans. 
        When mutex is (say) '1', only Jack (puts a sticky note and goes to buy milk) is allowed to access the critical region.
        And when mutex is (say) '2', only Jill is allowed.
        
        The disadvantage of this method (had higher expectations from you, Peterson) is that the person who is waiting for the other
        to come from market lives in anxiety of too less/more milk, i.e. the thread is continously using the CPU, 
        checking when the mutex is unlocked so that it can be locked again. Hence solution has a scope of improvement.

    NOTE: Run multiple times if the mentioned points of failure are not incurred.
    
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#define cin(x) scanf("%d",&x)
#define cout_var(x) printf("%d ",x)
#define display(x,n) for(int i=0;i<n;++i){printf("%d ",x[i]);}printf("\n")
#define nl printf("\n")
#define here printf("here\n")
#define TOO_MUCH 11
#define INITIAL 5
#define LIMITING_QUANTITY 1     //Quantity below which milk has to be bought
#define QUANTITY_BOUGHT 10
#define QUANTITY_CONSUMED 5
#define JACK_ID 111
#define JILL_ID 222
#define NO_OF_DAYS 7
#define who_does if(id==JACK_ID){printf("Jack");}else if(id==JILL_ID){printf("Jill");}else{printf("Stranger");}
#define how_much_milk printf("Milk quantity: ");cout_var(milk);nl;

int milk = INITIAL;
pthread_mutex_t sticky_note;

bool check_milk(int id){
    who_does;
    if(milk < LIMITING_QUANTITY){printf(" says: Oh no! Time to buy milk\n");return 0;}
    else{printf(" says: Sufficient milk for today\n");return 1;}
}

void buy_milk(int id){
    who_does;
    printf(" buys milk, now ");
    milk+=QUANTITY_BOUGHT;
    how_much_milk;
}

void *routine(void *arg){
    pthread_mutex_lock(&sticky_note);
    int id = *(int *)arg;
    bool quantity = check_milk(id);
    if(!quantity){buy_milk(id);}
    else{who_does;printf(" didn't buy milk that day\n");}
    who_does;printf(" consumed milk, ");
    milk-=QUANTITY_CONSUMED;
    how_much_milk;
    pthread_mutex_unlock(&sticky_note);
    pthread_exit(0);
}

int main(){
    pthread_mutex_init(&sticky_note,NULL);
    nl;
    pthread_t jack, jill;
    int jack_id = JACK_ID, jill_id = JILL_ID;
    int no_of_days = NO_OF_DAYS;
    while(no_of_days--){
        pthread_create(&jack,NULL,routine,&jack_id);
        pthread_create(&jill,NULL,routine,&jill_id);
        pthread_join(jack,NULL);
        pthread_join(jill,NULL);
        if(milk<0){printf("No milk today\nDivorce, game over!");exit(0);}
        else if(milk >= TOO_MUCH){printf("Too much milk today\nDivorce!");exit(0);}
        else{printf("\nNext day\n");}
    }
    printf("They lived happily ever after\n");
    return 0;
}