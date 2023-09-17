/* 
    DATA STRUCTURE: avl tree

    CODE:   1) uses linked list 
            2) no menu but friendly function names
    
    FUNCTIONS CODED:
            1) inorder traverse            8) rotate_right
            2) pre_order traverse		    9) rotate_left
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

void inorder(struct node *root){
    if(root == NULL){return;}
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct node *root){
    if(root == NULL){return;}
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
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

void rotate_right(struct node **critical){
	struct node *rotator = *critical;
	struct node *pivot = rotator->left;
	struct node *temp = pivot->right;
	pivot->right = rotator;
	rotator->left = temp;
	*critical = pivot;
}

void rotate_left(struct node **critical){
	struct node *rotator = *critical;
	struct node *pivot = rotator->right;
	struct node *temp = pivot->left;
	pivot->left = rotator;
	rotator->right = temp;
	*critical = pivot;
}

void rotation(struct node **critical){
	struct node *rotator = *critical;
	if(rotator->balance_factor == 2){
		if(rotator->left->right != NULL){rotate_left(&(rotator->left));}
		rotate_right(&rotator);
	}
	else{
		if(rotator->right->left != NULL){rotate_right(&(rotator->right));}
		rotate_left(&rotator);
	}
	*critical = rotator;
}

struct node *create(struct node **root, int x){
	if(*root == NULL){
		struct node *creator = (struct node *)malloc(sizeof(struct node));
		creator->data = x;
		creator->left = NULL;
		creator->right = NULL;
		creator->balance_factor = 0;
		*root = creator;
		return creator;
	}
	else{
		struct node *creator = *root;
		if(x > creator->data){creator->right = create(&creator->right, x);}
		else if(x == creator->data){printf("Duplicate value detected, exit protocol activated..."); exit(0);}
		else {creator->left = create(&creator->left, x);}
		*root = creator;
		modify_bf(root);

		struct node *critical = find_critical(*root);
		if(critical == NULL){return *root;}
		rotation(&critical);
		*root = critical;
		modify_bf(root);
		return *root;
	}
}

void path_printer(struct node *root,int x){
    if(root == NULL){printf("\nErr,NODE NOT FOUND\n");return;}
    if(x==root->data){return;}
    if(x<root->data){printf("Left "); path_printer(root->left,x);}
    if(x>root->data){printf("Right "); path_printer(root->right,x);}
}
void find_path(struct node *root,int x){
    printf("Number %d present at: ",x);
    path_printer(root,x);
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
        if(critical->left->balance_factor == -1){rotate_left(&critical->left);}
        rotate_right(&critical);
    }
    else{
        if(critical->right->balance_factor == -1){rotate_right(&critical->left);}
        rotate_left(&critical);
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
            struct node *inorder_successor = smallest_in(deletor->right), *parent_of_inorder_successor = NULL;
            struct node *connecter = highest_in(inorder_successor);
            search(root,inorder_successor->data, &parent_of_inorder_successor,&inorder_successor);
            if(parent_of_inorder_successor->right == inorder_successor){parent_of_inorder_successor->right = NULL;}
            else{parent_of_inorder_successor->left = NULL;}
            if(parent_of_deletor->right == deletor){parent_of_deletor->right = inorder_successor;}
            else{parent_of_deletor->left = inorder_successor;} 
            if(deletor->right != connecter){connecter->right = deletor->right;}
            if(deletor->left != connecter){inorder_successor->left = deletor->left;}
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
    inorder(root);nl;
    root = delete(root,7);
    inorder(root);nl;
    return 0;
}
