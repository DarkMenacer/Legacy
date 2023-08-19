/*
Banker's Algorithm (Operating Systems)

Example-
___________________________________________
|    |    max    | allocation | available  |
|    |   A B C   |   A B C    |   A B C    | 
|----|-----------|------------|------------|
| P1 |   7 5 3   |   3 0 1    |   3 3 2    |
| P2 |   3 2 2   |   0 2 0    |            |
| P3 |   9 0 2   |   0 3 0    |            |
| P4 |   2 2 2   |   2 2 1    |            |
| P5 |   2 4 3   |   1 0 0    |            |
▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔▔
Dynamic code hence input can be given on the way.

Input in one line:- 5 3 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2 3 3 2
Expected Output :- 2 -> 4 -> 1 -> 3 -> 5

*/

#include <stdio.h>
#include <stdlib.h>

int enough_resources_available(int resources, int *need_of_p,int *available_r){
    int i;
    for(i=0;i<resources;++i){if(need_of_p[i]>available_r[i]){return 0;}}
    return 1;
}

int bankers_algorithm(int processes, int resources, int **need, int **allocation,int *available, int *executed, int iteration){
    if(iteration == processes){return 1;}
    int i,j;
    for(i=0;i<processes;++i){
        if(executed[i]){continue;}
        if(enough_resources_available(resources,need[i],available)){break;}
    }
    if(i==processes){return 0;}
    printf("%d -> ",i+1);
    executed[i] = 1;
    for(j=0;j<resources;++j){available[j]+=allocation[i][j];}
    return bankers_algorithm(processes,resources, need, allocation, available, executed, iteration+1);
}

int main(){
    printf("Enter the number of processes and resources respectively:- ");
    int processes, resources;
    scanf("%d %d",&processes,&resources);
    int max[processes][resources];
    int available[resources];
    int **need = (int **)malloc(processes * sizeof(int*)), **allocation = (int**)malloc(processes * sizeof(int*));
    int i,j;
    for(i=0;i<processes;++i){
        need[i] = (int *)malloc(resources * sizeof(int));
        allocation[i] = (int *)malloc(resources * sizeof(int));
    }
    for(i=0;i<processes;++i){
        printf("Enter maximum of each resource needed by process %d: ",i+1);
        for(j=0;j<resources;++j){scanf("%d",&max[i][j]);}
    }
    for(i=0;i<processes;++i){
        printf("Enter the no. of instances of each resource allocated to process %d: ",i+1);
        for(j=0;j<resources;++j){scanf("%d",&allocation[i][j]);}
    }
    printf("Enter the no. of free instances of each resource: ");
    for(i=0;i<resources;++i){scanf("%d",&available[i]);}
    for(i=0;i<processes;++i){for(j=0;j<resources;++j){need[i][j] = max[i][j] - allocation[i][j];}}
    int executed[processes];
    for(i=0;i<processes;++i){executed[i]=0;}
    printf("Order of execution of processes:- ");
    if(!(bankers_algorithm(processes,resources,need,allocation,available,executed,0))){
        printf("DEADLOCK DETECTED\n");
    }
    return 0;
}
