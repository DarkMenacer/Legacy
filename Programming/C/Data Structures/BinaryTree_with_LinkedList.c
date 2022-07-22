/* 
    DATA STRUCTURE: regular binary tree

    CODE:   1) uses linked list 
            2) no menu but friendly function names
    
    FUNCTIONS CODED:
            1) create_node                  5) pre_order_tranverse
            2) go_right_from                6) in_order_tranverse
            3) go_left_from                 7) post_order_tranverse
            4) come_back_one_to_right        

    NOTE:   1) doesn't include deletion of nodes 

    EdataAMPLE USED: bst used in the code which converts to avl tree
                    G                           
                D        I                   
              C   E   H    N         
            A            M   O    
                      J
*/

#include <stdio.h>
#include <stdlib.h>
#define nl printf("\n")

struct node{
    /*int*/ char data;
    struct node *left;
    struct node *right;
};

struct node *create(struct node **traveller, char data){
    struct node *mtraveller = *traveller;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->left= NULL;
    new->right= NULL;
    if(mtraveller == NULL){mtraveller = new;}
    else{
        if(mtraveller->left == NULL){(mtraveller->left= new);}
        else{mtraveller->right = new;}
    }
    if(mtraveller->right != NULL){mtraveller = mtraveller->left;}
    *traveller = mtraveller;
    return new;
}

void go_right_from(struct node *parent, struct node **traveller){
    struct node *mtraveller = *traveller;
    mtraveller = parent;mtraveller = mtraveller->right;
    *traveller = mtraveller;
}
void go_left_from(struct node *parent,struct node **traveller){
    struct node *mtraveller = *traveller;
    mtraveller = parent;mtraveller = mtraveller->left;
    *traveller = mtraveller;
}
void come_back_one_to_right(struct node *root,struct node **traveller){
    struct node *mtraveller = *traveller;
    struct node *current_pos = mtraveller;
    mtraveller = root;
    while(mtraveller->left!=current_pos){mtraveller=mtraveller->left;}
    *traveller = mtraveller;
}

void pre_order_transverse(struct node *root){
    if(root == NULL){return;}
    printf("%c ",root->data);
    pre_order_transverse(root->left);
    pre_order_transverse(root->right);
}
void in_order_transverse(struct node *root){
    if(root == NULL){return;}
    in_order_transverse(root->left);
    printf("%c ",root->data);
    in_order_transverse(root->right);
}
void post_order_transverse(struct node *root){
    if(root == NULL){return;}
    post_order_transverse(root->left);
    post_order_transverse(root->right);
    printf("%c ",root->data);
}

int main(){
    struct node *traveller = NULL;
    struct node *root = create(&traveller,'G');
    struct node *child1 = create(&traveller,'D');
    struct node *child2 = create(&traveller,'I');
    struct node *child11 = create(&traveller,'C');
    struct node *child12 = create(&traveller,'E');
    struct node *child111 = create(&traveller,'A');
    go_right_from(root,&traveller);
    struct node *child21 = create(&traveller,'H');
    struct node *child22 = create(&traveller,'N');
    go_right_from(child2,&traveller);
    struct node *child221 = create(&traveller,'M');
    struct node *child222 = create(&traveller,'O');
    struct node *child2211 = create(&traveller,'J');

    pre_order_transverse(root);nl;
    in_order_transverse(root);nl;
    post_order_transverse(root);
    return 0;
}