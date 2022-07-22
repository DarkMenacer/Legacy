/* 
    DATA STRUCTURE: binary search tree

    CODE:   1) uses linked list 
            2) create, find_path, find_height, in-order transverse, smallest, highest number, search, delete functions coded
            3) no menu but friendly function names

    NOTE:   1) deletion of root of the bst (7 here) gives error for which the code needs to be modified 

    EXAMPLE USED: bst used in the code
            7
        4       9
          6   8   14
                13  15
              10
                11
                  12
*/

#include <stdio.h>
#include <stdlib.h>
#define nl printf("\n")
#define goright printf("Right ")
#define goleft printf("Left ")

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(struct node **root,int x){
    if(*root == 0){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = x;
        new->left = NULL;
        new->right = NULL;
        *root = new;
        return new;
    }
    else{
        struct node *parent = *root, *creator;
        if(x==parent->data){printf("Illegal to input same same twice\nProgram exits");exit(0);}
        if(x<parent->data){creator = create(&parent->left,x);}
        else{creator = create(&parent->right,x);}
        return creator; 
    }
}

int find_height(struct node *root){
    if(root==NULL){return 0;}
    int left_subtree = find_height(root->left);
    int right_subtree = find_height(root->right);
    int height = (left_subtree>right_subtree)? left_subtree: right_subtree;
    return height + 1;
}

void path_ii(struct node *root,int x){
    if(root == NULL){printf("\nErr,NODE NOT FOUND\n");return;}
    if(x==root->data){return;}
    if(x<root->data){goleft; path_ii(root->left,x);}
    if(x>root->data){goright; path_ii(root->right,x);}
}
void find_path(struct node *root,int x){
    printf("Given number present at: ");
    path_ii(root,x);
    printf("from the root");
}

void in_order_transverse(struct node *root){
    if(root == NULL){return;}
    in_order_transverse(root->left);
    printf("%d ",root->data);
    in_order_transverse(root->right);
}

struct node *smallest_in(struct node *root){
    if(root->left!= NULL){root = smallest_in(root->left);}
    return root;
}

struct node *highest_in(struct node *root){
    if(root->right != NULL){root = highest_in(root->right);}
    return root;
}

void search(struct node *root, int x, struct node **parent, struct node **here){
    if(root->right== NULL && root->left == NULL){printf("Value doesn't exist\n");return;}
    *parent = root;
    if(!(root->right== NULL || root->left == NULL)){
        if(root->right->data == x || root->left->data == x){
            *here = (root->left->data == x)? root->left: root->right;
            return;
            }
        }
    else{*here = (root->right == NULL)?root->left:root->right; return;}
    if(x > root->data){search(root->right,x,parent,here);}
    else{search(root->left,x,parent,here);}
}

struct node *delete(struct node *root, int x){
    if(root->data == x){printf("This case is unresolved in the code, need to work on it ");exit(0);} //// ATTENTION NEEDED
    struct node *deletor = NULL, *parent_of_deletor = NULL;
    search(root,x,&parent_of_deletor,&deletor);
    if(parent_of_deletor == NULL){return root;}
    if(deletor->right == NULL && deletor->left == NULL){
        if(parent_of_deletor->left == deletor){parent_of_deletor->left = NULL;}
        else{parent_of_deletor->right = NULL;}
    }
    else{
        if(deletor->right!=0 && deletor->left == 0){
            if(parent_of_deletor->left == deletor){parent_of_deletor->left = deletor->right;}
            else{parent_of_deletor->right = deletor->right;}
        }
        else if(deletor->left!=0 && deletor->right == 0){
            if(parent_of_deletor->left == deletor){parent_of_deletor->left = deletor->left;}
            else{parent_of_deletor->right = deletor->left;}
        }
        else{
            struct node *in_order_successor = smallest_in(deletor->right), *parent_of_in_order_successor = NULL;
            struct node *connecter = highest_in(in_order_successor);
            search(root,in_order_successor->data, &parent_of_in_order_successor,&in_order_successor);
            if(parent_of_in_order_successor->right == in_order_successor){parent_of_in_order_successor->right = NULL;}
            else{parent_of_in_order_successor->left = NULL;}
            if(parent_of_deletor->right == deletor){parent_of_deletor->right = in_order_successor;}
            else{parent_of_deletor->left = in_order_successor;} 
            if(deletor->right != connecter){connecter->right = deletor->right;}
            if(deletor->left != connecter){in_order_successor->left = deletor->left;}
        }
    }
    free(deletor);
    return root;
}

int main(){
    struct node *root = NULL, *parent_of = NULL,*here = NULL;
    root = create(&root,7);
    struct node N1 = *create(&root,4);
    struct node N2 = *create(&root,9);
    struct node N3 = *create(&root,8);
    struct node N4 = *create(&root,14);
    struct node N5 = *create(&root,6);
    struct node N6 = *create(&root,13);
    struct node N7 = *create(&root,10);
    struct node N8 = *create(&root,11);
    struct node N9 = *create(&root,12);
    struct node N10 = *create(&root,15);
    in_order_transverse(root);
    nl;
    root = delete(root,9);
    in_order_transverse(root);
    return 0;
}

