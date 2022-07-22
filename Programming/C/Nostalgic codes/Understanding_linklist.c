/*
    LinkList functions using Detective Conan 
    April 2021
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    char *name;
    struct node *next;
};

struct node *creator;
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

int display_counter = 1;
void display(struct node *head){
    printf("---%d---\n",display_counter);
    ++display_counter;
    struct node *displayer = head;
    int i =1;
    while(displayer != 0){
        printf("%d)%s\n",i,displayer->name);
        displayer = displayer->next;
        i++; 
    }
    printf("\n\n");
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
        printf("%s Non-existent\n\n\n",s);
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

void delete(struct node **head, char *s){
    struct node *deletor = *head;
    struct node *prev = deletor;
    while(deletor != 0){
        if(deletor->name == s)
            break;
        prev = deletor;
        deletor = deletor->next;
    }
    if(prev == deletor)
        *head = deletor->next;
    else{
        if(deletor != 0)
            prev->next = deletor->next;
        else
            printf("Cannot delete something that doesn't exist\n");
    }
}

int main(){
    struct node *head1 = 0;
    struct node N1 = *create(&head1,"Conan");
    struct node N2 = *create(&head1,"Ran");
    struct node N3 = *create(&head1,"Kogoro");
    display(head1);
    search(head1,"Haibara");
    struct node N4 = *create(&head1,"Haibara");
    struct node N5 = *create(&head1,"Vermouth");
    display(head1);
    struct node N6 = *insert(head1,"Akai",5);
    struct node N7 = *insert(head1,"Agasa",2);
    struct node N8 = *insert(head1,"Akemi",5);
    display(head1);
    delete(&head1,"Akemi");
    display(head1);
    delete(&head1,"Akai");
    display(head1);
    struct node N9 = *insert(head1,"Yusaku",2);
    struct node N10 = *insert(head1,"Yukiko",3);
    struct node N11 = *create(&head1,"Amuro");
    display(head1);
    return 0;
}
