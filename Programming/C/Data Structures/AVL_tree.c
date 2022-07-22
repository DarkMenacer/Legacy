/* 
    DATA STRUCTURE: avl tree

    CODE:   1) uses linked list 
            2) no menu but friendly function names
    
    FUNCTIONS CODED:
            1) in_order transverse          8) rotate_right
            2) parent_of                    9) rotate_left
            3) find_height                  10) rotation
            4) modify_balancefactor         11) find_path
            5) find_critical                12) search 
            6) smallest_in                  13) delete
            7) highest_in                   14) adjust_delete


    NOTE:   1) deletion of root gives error for which the code needs to be modified 

    EXAMPLE USED: bst used in the code which converts to avl tree
            7                           10
        4       9                   7       13
          6   8   14      -->     4   9   11  14
                13  15           6   8     12   15
              10
                11
                  12
*/

#include <stdio.h>
#include <stdlib.h>
#define nl printf("\n") 

struct node{
    int data;
    int balance_factor;
    struct node *left;
    struct node *right;
};

void in_order_transverse(struct node *root){
    if(root == NULL){return;}
    in_order_transverse(root->left);
    printf("%d ",root->data);
    in_order_transverse(root->right);
}

void parent_of(int x, struct node *root, struct node **parent){
    if(root == NULL){return;}
    if(root->right== NULL && root->left == NULL){printf("Value doesn't exist\n");return;}
    *parent = root;
    if(root->left != NULL && x<=root->left->data){
        if(x<root->left->data){parent_of(x,root->left,parent);}
        return;
    }
    else if(root->right != NULL && x>=root->right->data){
        if(x>root->right->data){parent_of(x,root->right,parent);}
        return;
    }
}

int find_height(struct node *root){
    if(root==NULL){return 0;}
    int left_subtree = find_height(root->left);
    int right_subtree = find_height(root->right);
    int height = (left_subtree>right_subtree)? left_subtree: right_subtree;
    return height + 1;
}

void modify_bf(struct node **root){
    if(root == NULL){return;}
    struct node *modifier = *root;
    if(modifier->left != NULL && modifier->right != NULL ){
        modifier->balance_factor = find_height(modifier->left) - find_height(modifier->right);
        modify_bf(&modifier->left);
        modify_bf(&modifier->right);
    }
    else{
        if(modifier->left == NULL && modifier->right == NULL){return;}
        else if(modifier->left == NULL){modifier->balance_factor = 0-find_height(modifier->right);modify_bf(&modifier->right);}
        else{modifier->balance_factor = find_height(modifier->left);modify_bf(&modifier->left);}
    }
    *root = modifier;
}

struct node *find_critical(struct node *root){
    struct node *critical = NULL;
    if(root->balance_factor >1 || root->balance_factor < -1 ){
        if(root->left!= NULL){
            if(root->left->balance_factor >1 || root->left->balance_factor < -1 ){
                critical = find_critical(root->left);
                if(critical == NULL){critical = root->left;}
            }
            else{critical = root;}
        }
        if(root->right!= NULL){
            if(root->right->balance_factor >1 || root->right->balance_factor < -1 ){
                critical = find_critical(root->right);
                if(critical == NULL){critical = root->right;}
            }
            else{critical = root;}
        }
    }
    return critical;
}

void rotate_right(struct node **root, struct node **pivot){
    struct node *mpivot = *pivot, *mroot = *root;
    mroot->left = mpivot->right;
    mpivot->right = mroot;
    *root = mpivot;
    printf("right rotated subtree: ");in_order_transverse(*root);nl;
}

void rotate_left(struct node **root, struct node **pivot){
    struct node *mpivot = *pivot, *mroot = *root;
    mroot->right = mpivot->left;
    mpivot->left = mroot;
    *root = mpivot;
    printf("left rotated subtree: ");in_order_transverse(*root);nl;
}

void rotation(struct node **root, int x){
    struct node *mroot = *root;
     if(x<mroot->data){
        if(x>mroot->left->data){rotate_left(&mroot->left,&mroot->left->right);}
        rotate_right(&mroot,&mroot->left);
    }
    else{
        if(x<mroot->right->data){rotate_right(&mroot->right,&mroot->right->left);}
        rotate_left(&mroot,&mroot->right);
    }
    *root = mroot;
}

struct node *create(struct node **root,int x){
    if(*root == 0){
        struct node *new = (struct node *)malloc(sizeof(struct node));
        new->data = x;
        new->left = NULL;
        new->right = NULL;
        new->balance_factor = 0;
        *root = new;
        return new;
    }
    else{
        struct node *parent = *root, *creator;
        if(x==parent->data){printf("Illegal to input same number twice\nProgram exits");exit(0);}
        if(x<parent->data){creator = create(&parent->left,x);}
        else{creator = create(&parent->right,x);}
        modify_bf(root);

        struct node *critical = find_critical(*root), *og_critical = critical;
        if(critical == NULL){return creator;}
        rotation(&critical,creator->data);

        struct node *final = *root, *fparent = NULL;
        if(og_critical != final){parent_of(og_critical->data,final,&fparent);}
        if(fparent == NULL){final = critical;}
        else if(fparent->left == og_critical){fparent->left = critical;}
        else{fparent->right = critical;}
        *root = final;
        modify_bf(root);
        return creator;
    }
}

void path_ii(struct node *root,int x){
    if(root == NULL){printf("\nErr,NODE NOT FOUND\n");return;}
    if(x==root->data){return;}
    if(x<root->data){printf("Left "); path_ii(root->left,x);}
    if(x>root->data){printf("Right "); path_ii(root->right,x);}
}
void find_path(struct node *root,int x){
    printf("Number %d present at: ",x);
    path_ii(root,x);
    printf("from the root");
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

void adjust_deletion(struct node **root){
    struct node *adjuster = *root, *critical = find_critical(adjuster);
    if(critical == NULL){return;}
    if(critical->balance_factor > 0){
        if(critical->left->balance_factor == -1){rotate_left(&critical->left,&critical->left->right);}
        rotate_right(&critical,&critical->left);
    }
    else{
        if(critical->right->balance_factor == -1){rotate_right(&critical->left,&critical->right->left);}
        rotate_left(&critical,&critical->right);
    }
    *root = adjuster;
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
    modify_bf(&root);
    adjust_deletion(&root);
    return root;
}

int main(){
    struct node *root = NULL;
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
    in_order_transverse(root);nl;
    root = delete(root,7);
    in_order_transverse(root);nl;
    return 0;
}
