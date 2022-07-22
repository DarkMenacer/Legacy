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

/*int check_cyclic(int nodes,int adjacency_matrix[nodes][nodes],char letters[nodes]){
    int flag = 0,i;

}*/

int indegree_of(char c,int nodes,int adjacency_matrix[nodes][nodes],char letters[nodes]){
    int indegree=0,i,j,pos;
    for(i=0;i<nodes;++i){if(letters[i] == c){pos = i;break;}}
    for(i=0;i<nodes;++i){indegree+=adjacency_matrix[i][pos];}
    return indegree;
}

void lazy_topological_sort(int nodes, int adjacency_matrix[nodes][nodes], char letters[nodes]){
    int nodes_printed = 0,i,j, indegrees[nodes], temp[nodes][nodes],pos, printed[nodes];
    for(i=0;i<nodes;++i){
        for(j=0;j<nodes;++j){temp[i][j]= adjacency_matrix[i][j];}
    }
    for(i=0;i<nodes;++i){printed[i]=0;}
    printf("Lazy Topological sort: ");
    while(nodes_printed != nodes){
        for(i=0;i<nodes;++i){indegrees[i] = indegree_of(letters[i],nodes,temp,letters);}
        for(i=0;i<nodes;++i){if(indegrees[i]==0 && printed[i]==0){pos = i;break;}}
        printed[pos] = 1;
        printf("%c ",letters[pos]); ++nodes_printed;
        for(i=0;i<nodes;++i){if(temp[pos][i] == 1){temp[pos][i]=0;}}
    }
}

void busy_topological_sort(int nodes,int adjacency_matrix[nodes][nodes],char letters[nodes]){
    int indegrees[nodes],temp[nodes][nodes],i,j;
    for(i=0;i<nodes;++i){
        for(j=0;j<nodes;++j){temp[i][j] = adjacency_matrix[i][j];}
    }
    for(i=0;i<nodes;++i){indegrees[i] = indegree_of(letters[i],nodes,temp,letters);}
    char queue[nodes];
    int front = 0, rear = -1, pos = -1; 
    for(i=0;i<nodes;++i){if(indegrees[i] == 0){queue[++rear] = letters[i];}}
    printf("Busy Topological sort: ");
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
    int nodes,i=1,j,choice;
    scanf("%d",&nodes);
    int adjacency_matrix[nodes][nodes];
    char letters[nodes];
    take_input(nodes,letters,adjacency_matrix);
    display(nodes,adjacency_matrix,letters);
    printf("For topological sort, is the given graph directed and acyclic?(press '1' for yes, '0' for no): ");
    scanf("%d",&choice);
    if(choice == 1){lazy_topological_sort(nodes,adjacency_matrix,letters);printf("\n");busy_topological_sort(nodes,adjacency_matrix,letters);}
    return 0;
}