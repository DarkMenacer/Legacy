/*
Understanding the need of threads

PLEASE REFER hierarchial_process_ordering.c before going through this code

Create 3 threads (initiate, eliminate and genocide) and make them run in all possible combinations

We start with population = 100. initiate populates by 100 more, eliminates depopulates by 30, genocide depopulates by 50%.

1) I -> E -> G (100 -> 200 -> 170 -> 85)
2) I -> G -> E (100 -> 200 -> 100 -> 70)
3) E -> I -> G (100 -> 70 -> 170 -> 85)
4) E -> G -> I (100 -> 70 -> 35 -> 135)
5) G -> I -> E (100 -> 50 -> 150 -> 120)
6) G -> E -> I (100 -> 50 -> 20 -> 120)

*/

#include <stdio.h>
#include <pthread.h>
#define who(name,action) pthread_create(&name,NULL,action,NULL);pthread_join(name,NULL)

int population = 100;
pthread_t I,E,G;

void *initiate(){printf("Enter initiater\n");population+=100;printf("    population left: %d\n",population);printf("Exit initiater\n");pthread_exit(0);}
void *eliminate(){printf("Enter eliminator\n");population-=30;printf("    population left: %d\n",population);printf("Exit eliminator\n");pthread_exit(0);}
void *genocide(){printf("Enter genocide\n");population/=2;printf("    population left: %d\n",population);printf("Exit genocide\n");pthread_exit(0);}

void I_E_G(){
    who(I,initiate);
    who(E,eliminate);
    who(G,genocide);
}

void I_G_E(){
    who(I,initiate);
    who(G,genocide);
    who(E,eliminate);
}

void E_I_G(){
    who(E, eliminate);
    who(I, initiate);
    who(G, genocide);

}

void E_G_I(){
    who(E, eliminate);
    who(G, genocide);
    who(I, initiate);
}

void G_I_E(){
    who(G, genocide);
    who(I, initiate);
    who(E, eliminate);
}   

void G_E_I(){
    who(G, genocide);
    who(E, eliminate);
    who(I, initiate);
}

int main(){
    printf("1) I -> E -> G\n2) I -> G -> E\n3) E -> I -> G\n4) E -> G -> I\n5) G -> I -> E\n6) G -> E -> I\n0) To stop\n");
    int choice;
    while(choice){
        printf("Choose the corresponding number: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                I_E_G();
                break;
            case 2:
                I_G_E();
                break;
            case 3:
                E_I_G();
                break;
            case 4:
                E_G_I();
                break;
            case 5:
                G_I_E();
                break;
            case 6:
                G_E_I();
                break;
            default:
                break;
        }
        population = 100;
    }
    return 0;
}