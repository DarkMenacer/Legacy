//  Name: Pranav Chatur
//  Roll no: 20ucs138
/*  Question:-
    Q1.  Given below the set of vertices and edges of a directed graph G (V, E)  
            V = {1, 2, 3, 4, 5, 6, 7, 8}    
            E = {(1,2), (1,3), (2,4), (4,3), (2,5), (3,4), (4,6), (5,6), (4, 7), (5, 7), (6,8),(7,8)}
            Write C code to do the following:
                1.Represent the graph using adjacency list say Adjlist[].
                2.Find degree(Vertex V ): Which find the degree of a vertex V.
                3.Find Cycles(Adjlist[], N): Which find the cycles in a graph Also display the edges which form the cycle if any.
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create_node(struct node **head, int c, struct node **traveller){
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

void initialise_node(struct node **head, int c, struct node **traveller){
    struct node *nX = NULL, *nXt = NULL;
    nX = create_node(&nX,c,&nXt);
    *head = nX;*traveller = nXt;
}

void display(int nodes, struct node *nX[nodes]){
    int i;
    printf("Adjacency list is ==>\n");
    for(i=0;i<nodes;++i){
        struct node *displayer = nX[i];
        printf("%d: ",displayer->data);
        while(displayer != 0){
            if(displayer->next != 0){printf("%d ",displayer->next->data);}
            displayer = displayer->next;
        }
    printf("\n");
    }
}

void find_degree(int nodes,struct node *nX[nodes], int edges, struct node Edges[edges]){
    int choice = 1;
    while(choice){
        int degree = -1,vertex = 0,i;
        printf("Enter the vertex you want to find degree for: ");
        fflush(stdin);scanf("%d",&vertex);
        
        for(i=0;i<edges;++i){if(Edges[i].data == vertex){++degree;}}
        
        for(i=0;i<nodes;++i){
            if(nX[i]->data == vertex){
                struct node *dfinder = nX[i];
                while(dfinder!=0){
                    ++degree;
                    dfinder = dfinder->next; 
                }
            }    
        }
        printf("Degree of vertex %d is %d\n",vertex,degree);
        printf("Press '0' to stop finding degrees of vertices: ");fflush(stdin);scanf("%d",&choice);
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
            printf("%d ",traverser->data);
            traverser = traverser->next;
        }
    }
}

int main(){
    int nodes = 8, edges = 12,i;
    struct node *nX[nodes],*nXt[nodes];
    for(i=0;i<nodes;++i){nX[i] = NULL; nXt[i] = NULL;initialise_node(&nX[i],i+1,&nXt[i]);}

    struct node Edges[edges];
    Edges[0] = *create_node(&nX[0],2,&nXt[0]);
    Edges[1] = *create_node(&nX[0],3,&nXt[0]);
    Edges[2] = *create_node(&nX[1],4,&nXt[1]);
    Edges[3] = *create_node(&nX[3],3,&nXt[3]);
    Edges[4] = *create_node(&nX[1],5,&nXt[1]);
    Edges[5] = *create_node(&nX[2],4,&nXt[2]);
    Edges[6] = *create_node(&nX[3],6,&nXt[3]);
    Edges[7] = *create_node(&nX[4],6,&nXt[4]);
    Edges[8] = *create_node(&nX[3],7,&nXt[3]);
    Edges[9] = *create_node(&nX[4],7,&nXt[4]);
    Edges[10] = *create_node(&nX[5],8,&nXt[5]);
    Edges[11] = *create_node(&nX[6],8,&nXt[6]);
    
    display(nodes,nX);
    find_degree(nodes,nX,edges,Edges);
    find_cycle(nodes,nX);
    return 0;
}