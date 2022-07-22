/* 
    DATA STRUCTURE: linked list

    CODE:   1) contains menu
            2) user-friendly code
    
    FUNCTIONS CODED:
            1) create          4) insert
            2) display         5) delete
            3) search              

    NOTE:   1) functions contain extra printing to make them user-friendly. 

    EXAMPLE USED: dynamic code, run to create your own example
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(struct node **head,int s, struct node **traveller);

void display(struct node *head);

void search(struct node *head, int s);

struct node *insert(struct node *head, int s, int pos);

void delete(struct node **head, int s);

void menu(struct node *head, struct node *traveller){
    int choice;
    printf("\n\n*--menu--*\nPress '1' to add entry to linked list\nPress '2' to search for an item\nPress '3' to delete an entry\nPress '4' to display the list\nPress '5' to exit the program\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the number to be added: ");
            int inp;
            scanf("%d",&inp);
            printf("Press '6' to add the entry at the end\nPress '7' to add the entry in the middle\n");
            int further;
            scanf("%d",&further);
            struct node N,N1;
            switch(further){
                case 6:
                    N = *create(&head,inp,&traveller);
                    break;
                case 7:
                    printf("Enter the position at which you want to insert: ");
                    int pos;
                    scanf("%d",&pos);
                    N1 = *insert(head,inp,pos);
                    break;
            }
            printf("Entry %d is added to the list\n", inp);
            menu(head,traveller);
            break;
        case 2:
            printf("Enter entry to be searched: ");
            int ser;
            scanf("%d",&ser);
            search(head,ser);
            menu(head,traveller);
            break;
        case 3:
            printf("Enter Entry to be deleted: ");
            int del;
            scanf("%d",&del);
            delete(&head,del);
            display(head);
            menu(head,traveller);
            break;
        case 4:
            display(head);
            menu(head,traveller);
            break;
        case 5:
            printf("All the data is deleted\nThank you for using the program\n");
            exit(0);
            break;
        default:
            printf("Invalid Entry,Try Again");
            menu(head,traveller);
    }
}

int main(){
    struct node *head= 0,*traveller = 0;
    menu(head,traveller);
    return 0;
}

struct node *create(struct node **head,int s, struct node **traveller){
    struct node *creator = *traveller;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = s;
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

void display(struct node *head){
    struct node *displayer = head;
    int i =1;
    printf("\nFollowing are the elements of the list\n");
    while(displayer != 0){
        printf("%d) %d\n",i,displayer->data);
        displayer = displayer->next;
        i++; 
    }
}

void search(struct node *head, int s){
    struct node *searcher = head;
    int pos = 1;
    while(searcher != 0){
        if(searcher->data == s){
            printf("FOUND! %d is element %d in the list\n",s,pos);
            break;
        }
        pos++;
        searcher = searcher->next;
    }
    if(searcher == 0)
        printf("%d is non-existent in the list\n",s);
}

struct node *insert(struct node *head, int s, int pos){
    struct node *insertor = head;
    while(pos > 2){
        insertor = insertor->next;
        pos--;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = s;
    new->next = insertor->next;
    insertor->next = new;
    return new;
}

void delete(struct node **head, int s){
    struct node *deletor = *head;
    struct node *prev = deletor;
    while(deletor != 0){
        if(deletor->data == s){break;}
        prev = deletor;
        deletor = deletor->next;
    }
    if(prev == deletor){*head = deletor->next;}
    else{
        if(deletor != 0){prev->next = deletor->next;}
        else{printf("Cannot delete something that doesn't exist\n");}
    }
}