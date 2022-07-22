/* 
    DATA STRUCTURE: adjecency matrix representation of graph

    CODE:   1) uses array
            2) kind-of a menu present, run directly
            3) incomplete, need to code check_cyclic
    
    FUNCTIONS CODED:
            1) take_input    4) breadth_first_search
            2) display       5) depth_first_search
            3) indegree_of   6) topological_sort

    EXAMPLE USED: dynamic code, run directly
*/

#include <stdio.h>

void take_input(int nodes, char letters[nodes],int adjacency_matrix[nodes][nodes]){
    int i,j;
    printf("Enter letters to represent each of %d nodes\n",nodes);
    for(i=0;i<nodes;++i){
        printf("node %d: ",i+1);
        fflush(stdin);scanf("%c",&letters[i]);
    }
    printf("All node acronyms successfully received.\n");
    
    printf("For every question, for yes, reply '1', and no, reply '0'\n");
    for(i=0;i<nodes;++i){
        for(j=0;j<nodes;++j){
            if(i==j){adjacency_matrix[i][j] = 0;continue;}
            printf("Are %c and %c neighbours? : ",letters[i],letters[j]);
            scanf("%d",&adjacency_matrix[i][j]);
        }
    }
}

void display(int nodes, int adjacency_matrix[nodes][nodes],char letters[nodes]){
    int i,j;
    printf("\nAdjacency matrix is => \n  ");
    for(i=0;i<nodes;++i){printf("%c ",letters[i]);}
    for(i=0;i<nodes;++i){
        printf("\n%c ",letters[i]);
        for(j=0;j<nodes;++j){
            printf("%d ",adjacency_matrix[i][j]);
        }
    }
    printf("\n");
}

void breadth_first_search(int nodes, int adjacency_matrix[nodes][nodes], char letters[nodes]){
    int status[nodes],i;
    for(i=0;i<nodes;++i){status[i] = 0;}
    printf("enter the origin node: ");
    fflush(stdin);
    char c;scanf("%c",&c);
    char queue[nodes];
    int front = 0, rear = -1, pos = -1;
    for(i=0;i<nodes;++i){
        if(letters[i] == c){
            queue[++rear] = c;
            status[i]=1;pos = i;
        }
    }
    if(rear == -1){printf("Such node doesn't exist.\n");return;}
    else{printf("Breadth First Search is ");}
    while(front != rear + 1){
        for(i=0;i<nodes;++i){
            if(adjacency_matrix[pos][i] == 1 && status[i] == 0){
                queue[++rear] = letters[i];
                status[i] = 1;
            }
        }
        printf("%c ",queue[front++]);
        for(i=0;i<nodes;++i){if(queue[front] == letters[i]){pos = i;}}
    }
}

void depth_first_search(int nodes,int adjacency_matrix[nodes][nodes],char letters[nodes]){
    int status[nodes],i;
    for(i=0;i<nodes;++i){status[i] = 0;}
    printf("Enter the origin node: ");
    fflush(stdin);
    char c;scanf("%c",&c);
    char stack[nodes];
    int top =-1,pos = -1;
    for(i=0;i<nodes;++i){
        if(letters[i] == c){
            stack[++top] = c;
            status[i]=1;pos = i;
        }
    }
    if(top == -1){printf("Such node doesn't exist.\n");return;}
    else{printf("Depth First Search is ");}
    while(top!=-1){
        printf("%c ",stack[top--]);
        for(i=0;i<nodes;++i){
            if(adjacency_matrix[pos][i] == 1 && status[i] == 0){
                stack[++top] = letters[i];
                status[i] = 1;
            }
        }
        for(i=0;i<nodes;++i){if(stack[top] == letters[i]){pos = i;}}
    }
}

/*int check_cyclic(int nodes,int adjacency_matrix[nodes][nodes],char letters[nodes]){
    int flag = 0,i;

}*/

int indegree_of(char c,int nodes,int adjacency_matrix[nodes][nodes],char letters[nodes]){
    int indegree=0,i,j,pos;
    for(i=0;i<nodes;++i){if(letters[i] == c){pos = i;break;}}
    for(i=0;i<nodes;++i){indegree+=adjacency_matrix[i][pos];}
    return indegree;
}

void topological_sort(int nodes,int adjacency_matrix[nodes][nodes],char letters[nodes]){
    int indegrees[nodes],temp[nodes][nodes],i,j;
    for(i=0;i<nodes;++i){
        for(j=0;j<nodes;++j){temp[i][j] = adjacency_matrix[i][j];}
    }
    for(i=0;i<nodes;++i){indegrees[i] = indegree_of(letters[i],nodes,temp,letters);}
    char queue[nodes];
    int front = 0, rear = -1, pos = -1; 
    for(i=0;i<nodes;++i){if(indegrees[i] == 0){queue[++rear] = letters[i];}}
    printf("Topological sort: ");
    while(front != rear + 1){
        for(i=0;i<nodes;++i){if(letters[i] == queue[front]){pos = i;}}
        for(i=0;i<nodes;++i){
            if(temp[pos][i] == 1){
                temp[pos][i]=0;
                if(indegree_of(letters[i],nodes,temp,letters) == 0){queue[++rear] = letters[i];}
            }
        }
        printf("%c ",queue[front++]);
    }
}

int main(){
    printf("Enter the number of nodes: ");
    int nodes,i=1,j;
    scanf("%d",&nodes);
    int adjacency_matrix[nodes][nodes];
    char letters[nodes];
    take_input(nodes,letters,adjacency_matrix);
    display(nodes,adjacency_matrix,letters);
    int choice = 1; printf("For Breadth first search, ");
    while(choice){
        breadth_first_search(nodes,adjacency_matrix,letters);
        printf("\nPress '0' to exit breadth first search: ");scanf("%d",&choice);
    }
    choice = 1; printf("For Depth first search, ");
    while(choice){
        depth_first_search(nodes,adjacency_matrix,letters);
        printf("\nPress '0' to exit depth first search: ");scanf("%d",&choice);
    }
    printf("For topological sort, is the given graph directed and acyclic?(press '1' for yes, '0' for no): ");
    scanf("%d",&choice);
    if(choice == 1){topological_sort(nodes,adjacency_matrix,letters);}
    return 0;
}