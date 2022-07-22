/*
    Date:-                              23 April 2022
    Name of the approach:-              Naive
    Feature:-                           Threads
    One line description:-              Problems in Race conditions
    How it beats its predecessor:-      Naive
    Points of failure:-           
        1) Too less milk when:-      
            #define LIMITING_QUANTITY 1     //Quantity below which milk has to be bought

        2) Too much milk when:- 
            #define LIMITING_QUANTITY 6

    Explanation:-
        In case of 1), code fails when Jack checks quantity of milk and realises that there is sufficient milk and 
        Jill has drank her part and Jill thinks the same hence no one buys milk.
        Output (in some cases):-
            JackJill says: Sufficient milk for today
            Jack didn't buy milk that day
            Jack consumed milk,  says: Sufficient milk for today
            Jill didn't buy milk that day
            Jill consumed milk, Milk quantity: -5 
            Milk quantity: -5 
            No milk today
            Divorce!

        In case of 2), code fails when both Jack and Jill buy milk due to problems in timings.
        Jill goes to market to buy a pack when Jack is already on his way from market with a pack of milk.
        Output (in some cases):-
            JackJill says: Oh no! Time to buy milk
            Jack buys milk, now  says: Oh no! Time to buy milk
            Jill buys milk, now Milk quantity: 25 
            Jill consumed milk, Milk quantity: 20 
            Milk quantity: 20 
            Jack consumed milk, Milk quantity: 15 
            Too much milk today
            Divorce!

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
#define LIMITING_QUANTITY 6     //Quantity below which milk has to be bought
#define QUANTITY_BOUGHT 10
#define QUANTITY_CONSUMED 5
#define JACK_ID 111
#define JILL_ID 222
#define NO_OF_DAYS 7
#define who_does if(id==JACK_ID){printf("Jack");}else if(id==JILL_ID){printf("Jill");}else{printf("Stranger");}
#define how_much_milk printf("Milk quantity: ");cout_var(milk);nl;

int milk = INITIAL;

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
    int id = *(int *)arg;
    bool quantity = check_milk(id);
    if(!quantity){buy_milk(id);}
    else{who_does;printf(" didn't buy milk that day\n");}
    who_does;printf(" consumed milk, ");
    milk-=QUANTITY_CONSUMED;
    how_much_milk;
    pthread_exit(0);
}

int main(){
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