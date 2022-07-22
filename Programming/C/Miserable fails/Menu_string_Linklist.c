/*
    MISERABLE FAIL #2  (06-05-2021)
        LESSON LEARNT : 1) NEVER USE SCANF AND FGETS (GETS DEPRECATED) TOGETHER
                        2) C LANGUAGE SUCKS FOR USER STRING INPUTS

*/
#include <stdio.h>
#include <stdlib.h>

struct node{
    char *name;
    struct node *next;
};

struct node *creator;
struct node *create(struct node **head,char *s);

void display(struct node *head);

void search(struct node *head, char *s);

struct node *insert(struct node *head, char *s, int pos);

void delete(struct node *head, char *s);

void MENU(struct node *head){
    int choice;
    char ignore;
    printf("*--MENU--*\nPress '1' to add entry to linked list\nPress '2' to search for an item\nPress '3' to delete an entry\nPress '4' to display the list\nPress '5' to exit the program\n");
    scanf("%d",&choice);
    printf("Input taken\n");
    switch(choice){
        case 1:
            printf("Enter the name of the entry: ");
            char inp[50];
            ignore = getchar();//fgets(inp,50,stdin);
            fgets(inp,50,stdin);
            printf("Press '6' to add the entry at the end or '7' to add the entry in the middle: ");
            int further;
            scanf("%d",&further);
            struct node N,N1;
            switch(further){
                case 6:
                    N = *create(&head,inp);
                    break;
                case 7:
                    printf("Enter the position at which you want to insert: ");
                    int pos;
                    scanf("%d",&pos);
                    N1 = *insert(head,inp,pos);
                    break;
            }
            printf("Entry %s added\n", inp);
            MENU(head);
            break;
        case 2:
            printf("Enter entry to be searched: ");
            char ser[50];
            ignore =getchar();//fgets(ser,50,stdin);
            fgets(ser,50,stdin);
            search(head,ser);
            break;
        case 3:
            printf("Enter Entry to be deleted: ");
            char del[50];
            ignore =getchar();//fgets(del,50,stdin);
            fgets(del,50,stdin);
            delete(head,del);
            display(head);
            break;
        case 4:
            display(head);
            break;
        case 5:
            printf("All the data is deleted\nThank you for using the program\n");
            exit(0);
            break;
        default:
            printf("Invalid Entry,Try Again");
            MENU(head);
    }
}

int main(){
    struct node *head= 0;
    MENU(head);
    return 0;
}

void delete(struct node *head, char *s){
    struct node *deletor = head;
    struct node *prev;
    while(deletor != 0){
        if(deletor->name == s)
            break;
        prev = deletor;
        deletor = deletor->next;
    }
    if(deletor != 0)
        prev->next = deletor->next;
    else
        printf("Cannot delete something that doesn't exist\n");
    MENU(head);
}

struct node *insert(struct node *head, char *s, int pos){
    struct node *insertor = head;
    while(pos > 2){
        insertor = insertor->next;
        pos--;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->name = s;
    new->next = insertor->next;
    insertor->next = new;
    return new;
}

void search(struct node *head, char *s){
    struct node *searcher = head;
    int pos = 1;
    while(searcher != 0){
        if(searcher->name == s){
            printf("FOUND! %s %dth node\n",s,pos);
            break;
        }
        pos++;
        searcher = searcher->next;
    }
    if(searcher == 0)
        printf("%s Non-existent\n",s);
    MENU(head);
}

void display(struct node *head){
    struct node *displayer = head;
    int i =1;
    while(displayer != 0){
        printf("%d)%s\n",i,displayer->name);
        displayer = displayer->next;
        i++; 
    }
    MENU(head);
}

struct node *create(struct node **head,char *s){
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->name = s;
    if(*head == 0){
        *head = new;
        creator = new;
    }
    else{
        creator->next = new;
        creator = new;
    }
    new->next = 0;
    return new;
} 