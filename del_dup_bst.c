#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};
struct tree *newnode(struct tree *p,int data){
	p = (struct tree *)malloc(sizeof(struct tree));
	p->info = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
struct tree *insert(struct tree * start, int data);
struct tree *deldup_rec(struct tree *start);
struct tree *del_rec(struct tree *start,int key);
void inorder (struct tree *start);
void postorder(struct tree *start);
void preorder(struct tree *start);
int main(){
	struct tree *start= NULL,*start2 = NULL,*p;
	int data,i,n,k,top=-1,front = -1,rear = -1,ch,t;
	struct tree *arr[MAX],*q[MAX];
	int path[MAX];
	scanf("%d",&n);
	for(i = 0; i<n; i++){
		scanf("%d",&data);
		start = insert(start,data);	
	}
	inorder(start);printf("\n");
	preorder(start);printf("\n");
	start = deldup_rec(start);		
	inorder(start);printf("\n");
	preorder(start);printf("\n");		
	return 0;
}
struct tree *insert(struct tree * start, int data){
	struct tree *temp;

	if(start == NULL){
		temp = newnode(temp,data);
		start = temp;
		return start;
	}
	if(data < start->info)
		start->left = insert(start->left,data);
	else if(data > start->info)
		start->right = insert(start->right,data);
	else {
		temp = newnode(temp,data);
		temp->right = start->right;
		start->right = temp;
	}
	return start;	
}
struct tree *del_rec(struct tree *start,int key){
	if(start == NULL )
		return start;
	struct tree *p = start,*suc;
	if(start->info < key){
		start->right = del_rec(start->right,key);
	}
	else if(start->info > key){
		start->left = del_rec(start->left,key);
	}
	else {
		if(start->left == NULL && start->right == NULL ){
			start = NULL;
			free(p);
			//return start;
		}
		else if(start->left != NULL && start->right == NULL){
			start = start->left;
			free(p);
		}		
		else if( start->right != NULL && start->left == NULL){
			start = start->right;
			free(p);
		}
		else {
			suc = start->right;
			while(suc->left != NULL)
				suc = suc->left;
			start->info = suc->info;
			start->right = del_rec(start->right,start->info);
		}
	}
	return start;
}
struct tree *deldup_rec(struct tree *start){
	if(start == NULL || (start->left == NULL && start->right == NULL))
		return start;
	struct tree *p = start,*suc;
	if(start->right != NULL && start->info == start->right->info ){
		start->right = del_rec(start->right,start->info);
	}
	else if(start->left != NULL && start->info == start->left->info){
		start->left = del_rec(start->left,start->info);
	}
	start->left = deldup_rec(start->left);
	start->right = deldup_rec(start->right);
	return start;
}

void inorder (struct tree *start){
	struct tree *p = start;
	if(p == NULL) return;
	inorder(p->left);
	printf("%d_",p->info);
	inorder(p->right);
}
 void preorder(struct tree *start){
	 struct tree *p = start;
	 if( p == NULL) return;
	 printf("%d__",p->info);
	 preorder(p->left);
	 preorder(p->right);
 }
void postorder(struct tree *start){
	struct tree *p =start;
	if(p == NULL) return;
	postorder(p->left);
	postorder(p->right);
	printf("%d_",p->info);
}
