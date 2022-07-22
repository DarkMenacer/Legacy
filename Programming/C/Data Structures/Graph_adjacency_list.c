/* 
    DATA STRUCTURE: adjecency list representation of graph

    CODE:   1) uses array of linked lists
            2) No menu present, but friendly function names
    
    FUNCTIONS CODED:
            1) create_node    3) initialise_node
            2) display        4) take_input

    EXAMPLE USED: dynamic code, run directly
            
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
};

struct node *create_node(struct node **head,char c, struct node **traveller){
    struct node *creator = *traveller;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = c;
    if(*head == 0){
        *head = new;
        creator = new;
    }
    else{
        creator->next = new;
        creator = new;
    }
    *traveller = creator;
    new->next = 0;
    return new;
}

void initialise_node(struct node **head, char c, struct node **traveller){
    struct node *nX = NULL,*nXt = NULL;
    nX = create_node(&nX,c,&nXt);
    *head = nX;*traveller = nXt;
}

void display(int nodes,struct node *nX[nodes]){
    int i;
    printf("\nAdjacency list is ==>\n");
    for(i=0;i<nodes;++i){
        struct node *displayer = nX[i];
        printf("%c: ",displayer->data);
        while(displayer != 0){
            if(displayer->next!= 0){printf("%c ",displayer->next->data);}
            displayer = displayer->next;
        }
    printf("\n");
    }
}

void take_input(int nodes, struct node *nX[nodes],struct node *nXt[nodes], char letters[nodes]){
    int i,j;
    printf("Enter letters to represent each of %d nodes\n",nodes);
    for(i=0;i<nodes;++i){
        printf("node %d: ",i+1);
        fflush(stdin);scanf("%c",&letters[i]);
        nX[i] = NULL;nXt[i] = NULL; initialise_node(&nX[i],letters[i],&nXt[i]);
    }
    printf("All node acronyms successfully received.\n");

    int connect = 0;
    printf("For every question, for yes, reply '1', and no, reply '0'\n");
    for(i=0;i<nodes;++i){
        for(j=0;j<nodes;++j){
            if(i==j){continue;}
            printf("Are %c and %c neighbours? : ",letters[i],letters[j]);
            fflush(stdin);scanf("%d",&connect);
            if(connect == 1){struct node nY = *create_node(&nX[i],letters[j],&nXt[i]);}
        }
    }
}

void find_cycle(int nodes,struct node *nX[nodes]){
    int status[nodes],i;
    for(i=0;i<nodes;++i){status[i]=0;}
    struct node *traverser = nX[0];status[0] = 1;
    while(traverser != 0){
        int temp = 0;
        for(i=0;i<nodes;++i){
            if(traverser->next->data == nX[i]->data){
                if(status[i] == 0){traverser = nX[i];status[i] = 1;}
                else{temp = 1;break;}
            }
        }
        if(temp==1){break;}
    }
    if(traverser == 0){printf("No cycle is present\n");return;}
    else{
        printf("Cycle is present\n");
        while(traverser){
            for(i=0;i<nodes;++i){
                if(traverser->data == nX[i]->data){
                    if(status[i] != 2){status[i] = 2;}
                    else{break;}
                }
            }
            printf("%c ",traverser->data);
            traverser = traverser->next;
        }
    }
}

int main(){
    printf("Enter the number of nodes: ");
    int nodes,i;
    scanf("%d",&nodes);

    struct node *nX[nodes], *nXt[nodes];
    char letters[nodes];
    take_input(nodes,nX,nXt,letters);
    display(nodes,nX);
    find_cycle(nodes,nX);
    return 0;
}