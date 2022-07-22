/*

Create a parent process and its 2 children and make them run in all possible combinations

We start with int chocolates = 100. Parent adds 100 more chocolates, Child_1 eats 30 chocolates, Child_2 eats 50% chocolates.

1) P -> C1 -> C2 (100 -> 200 -> 170 -> 85)
2) P -> C2 -> C1 (100 -> 200 -> 100 -> 70)
3) C1 -> P -> C2 (100 -> 70 -> 170 -> 85)
4) C1 -> C2 -> P (100 -> 70 -> 35 -> 135)
5) C2 -> P -> C1 (100 -> 50 -> 150 -> 120)
6) C2 -> C1 -> P (100 -> 50 -> 20 -> 120)

But this doesn't happen because each process, child and parent both have their own copy of global variable and local variables.
*/

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#define parent_processing printf("Enter parent\n");chocolates+=100;printf("    chocolates left: %d\n",chocolates)
#define child_1_processing printf("Enter child_1\n");chocolates-=30;printf("    chocolates left: %d\n",chocolates);printf("Exit child_1\n")
#define child_2_processing printf("Enter child_2\n");chocolates/=2;printf("    chocolates left: %d\n",chocolates);printf("Exit child_2\n")

int chocolates = 100;

void p_c1_c2(){
    int status;
    parent_processing;
    pid_t child1, child2;
    child1 = fork();
    if(child1==0){child_1_processing;exit(0);}
    else{
        waitpid(child1,&status,0);
        child2 = fork();
        if(child2==0){child_2_processing;exit(0);}
        else{waitpid(child2,&status,0);printf("Exit parent\n");}
    }
}

void p_c2_c1(){
    int status;
    parent_processing;
    pid_t child1, child2;
    child2 = fork();
    if(child2==0){child_2_processing;exit(0);}
    else{
        waitpid(child2,&status,0);
        child1 = fork();
        if(child1==0){child_1_processing;exit(0);}
        else{waitpid(child1,&status,0);printf("Exit parent\n");}
    }
}

void c1_p_c2(){
    int status;
    pid_t child1, child2;
    child1 = fork();
    if(child1==0){child_1_processing;exit(0);}
    else{
        waitpid(child1,&status,0);
        parent_processing;
        child2 = fork();
        if(child2==0){child_2_processing;exit(0);}
        else{waitpid(child2,&status,0);printf("Exit parent\n");}
    }
}

void c1_c2_p(){
    int status;
    pid_t child1,child2;
    child1 = fork();
    if(child1 == 0){child_1_processing;exit(0);}
    else{
        waitpid(child1,&status,0);
        child2 = fork();
        if(child2 == 0){child_2_processing;exit(0);}
        else{
            waitpid(child2,&status,0);
            parent_processing;
            printf("Exit parent\n");
        }
    }
}

void c2_p_c1(){
    int status;
    pid_t child1, child2;
    child2 = fork();
    if(child2==0){child_2_processing;exit(0);}
    else{
        waitpid(child2,&status,0);
        parent_processing;
        child1 = fork();
        if(child1==0){child_1_processing;exit(0);}
        else{waitpid(child1,&status,0);printf("Exit parent\n");}
    }
}

void c2_c1_p(){
    int status;
    pid_t child1,child2;
    child2 = fork();
    if(child2 == 0){child_2_processing;exit(0);}
    else{
        waitpid(child2,&status,0);
        child1 = fork();
        if(child1 == 0){child_1_processing;exit(0);}
        else{
            waitpid(child1,&status,0);
            parent_processing;
            printf("Exit parent\n");
        }
    }
}

int main(){
    printf("1) P -> C1 -> C2\n2) P -> C2 -> C1\n3) C1 -> P -> C2\n4) C1 -> C2 -> P\n5) C2 -> P -> C1\n6) C2 -> C1 -> P\n0) To stop\n");
    int choice;
    while(choice){
        printf("Choose the corresponding number: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                p_c1_c2();
                break;
            case 2:
                p_c2_c1();
                break;
            case 3:
                c1_p_c2();
                break;
            case 4:
                c1_c2_p();
                break;
            case 5:
                c2_p_c1();
                break;
            case 6:
                c2_c1_p();
                break;
            default:
                break;
        }
        chocolates = 100;
    }
    return 0;
}