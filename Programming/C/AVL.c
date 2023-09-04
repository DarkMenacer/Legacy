#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define here printf("here")
#define nl printf('\n')

struct node {
	int data;
	struct node *left;
	struct node *right;
	int balance_factor;
};

int find_height(struct node *root){
	if(root == NULL){return 0;}
	int left = find_height(root->left);
	int right = find_height(root->right);
	return fmax(left, right) + 1;
}

void modifybf(struct node **root){
	if(root == NULL){return;}
	struct node *modifier = *root;
	modifier->balance_factor = find_height(modifier->left) - find_height(modifier->right);
	if(modifier->left !=NULL){modifybf(&modifier->left);}
	if(modifier->right !=NULL){modifybf(&modifier->right);}
	*root = modifier;
}

void inorder(struct node *root){
	if(root == NULL){return;}
	inorder(root->left);
	printf("%d (%d) ", root->data, root->balance_factor);
	inorder(root->right);
}

struct node *find_critical(struct node *root){
	if(root == NULL){return NULL;}
	struct node *returner = root;
	if(returner->balance_factor > 1 || returner->balance_factor < -1){
		if(returner->left != NULL && find_critical(returner->left) != NULL){
			returner = find_critical(returner->left);
		}
		else if(returner->right != NULL && find_critical(returner->right) != NULL){
			returner = find_critical(returner->right);
		}
	}
	else{returner = NULL;}
	return returner;
}

void left_rotate(struct node **pivot_parent){
	struct node *rotator = *pivot_parent, *pivot = rotator->right;
	rotator->right = pivot->right;
	pivot->right->left = pivot;
	*pivot_parent = rotator;
}


struct node *create(struct node **root, int x){
	if(*root == NULL){
		struct node *creator = (struct node *)malloc(sizeof(struct node));
		creator->data = x;
		creator->left = NULL;
		creator->right = NULL;
		creator->balance_factor = 0;
		*root = creator;
		return creator;;
	}
	else{
		struct node *creator = *root;
		if(x > creator->data){creator->right = create(&creator->right, x);}
		//not added case for x == root.data
		else {creator->left = create(&creator->left, x);}
		*root = creator;
		modifybf(root);
		struct node *critical = find_critical(*root);
		if(critical != NULL){
			printf("critical: %d\n", critical->data);
		}
		return creator;
	}
}

int main(){
	struct node *root = NULL;
	root = create(&root, 5);
	struct node *N1 = create(&root, 10);
	struct node *N2 = create(&root, 6);
	inorder(root);
	return 0;
}
