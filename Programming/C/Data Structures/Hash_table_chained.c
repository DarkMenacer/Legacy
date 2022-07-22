/* 
    DATA STRUCTURE: hash table (with chaining)

    CODE:   1) uses array of structures (structures are linked list) for chaining
            2) no menu but friendly function names
    
    FUNCTIONS CODED:
            1) hash_function    3) add_element
            2) create_node      4) search


    NOTE:   1) hash function conatins multiple options to choose from (not all complete)
            2) macros used:- size, m, a (check code for description)
            3) doesn't include deletion of element

    EXAMPLE USED:
         hash table     elements
            0|          37
            1|          38  75  112
            2|          39  76
            3|          -
            ..
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 50     // Size of hash table
#define M 37        // number for hashing using division method
#define A 0.639     // number for hashing using multiplication method

struct node{
    int data;
    struct node *next;
};

struct node *create_node(struct node **head,int x, struct node **maker){
    struct node *creator = *maker;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    if(*head == 0){
        *head = new;
        creator = new;
    }
    else{
        creator->next = new;
        creator = new;
    }
    *maker = creator;
    new->next = 0;
    return new;
}

int hash_function(int x){
    return x % M;       //METHOD 1: Division method
    /*return x*A;*/     //METHOD 2: Multiplication method
    /**/                //METHOD 3: Mid-Square method
    /**/                //METHOD 4: Folding method
}

struct node *add_element(struct node **head,struct node **maker,int x){
    struct node *new = create_node(&head[hash_function(x)],x,&maker[hash_function(x)]);
    //printf("%d\n", new->data);
    return new;
}

void search(int x, struct node **head){
    int pos = 0;
    struct node *searcher = head[hash_function(x)];
    while(searcher->data != x){
        if(searcher->next == NULL){printf("Number not present\n");return;}
        searcher = searcher->next;++pos;
    }
    printf("%d is present at index %d, %d step(s) away\n",x,hash_function(x),pos);
}

int main(){
    struct node *hash_table[SIZE];
    struct node *travellers[SIZE];
    int i;
    for(i=0;i<SIZE;++i){
        hash_table[i] = NULL;
        travellers[i] = NULL;
    }
    struct node n1 = *add_element(hash_table,travellers,37);
    struct node n2 = *add_element(hash_table,travellers,38);
    struct node n3 = *add_element(hash_table,travellers,75);
    struct node n4 = *add_element(hash_table,travellers,112);
    struct node n5 = *add_element(hash_table,travellers,39);
    struct node n6 = *add_element(hash_table,travellers,76);
    search(76,hash_table);

    return 0;
}