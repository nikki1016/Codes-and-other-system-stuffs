#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};
struct node {
	int info;
	struct node *next;
};
struct tree *newnode(struct tree *tmp,int i){
	tmp = (struct tree *)malloc(sizeof(struct tree));
	tmp->info = i;
	tmp->left = tmp->right = NULL;
	return tmp;
}
struct node *insert_end(struct node *start,int i);
struct node *reverse(struct node *start);
struct tree *create_pre(struct tree *start,struct node *pre,int n);
struct tree *create_post(struct tree *start,struct node *pre,int n);
void postorder(struct tree *start);
void inorder(struct tree *start);
void preorder(struct tree *start);

int main(){
	struct tree *start = NULL,*p = NULL;
	struct node *pre = NULL , *post = NULL;
	int data,i,n,front =-1,rear = -1,max = -999;
	scanf("%d",&n);
	for(i =0; i<n; i++){
		scanf("%d",&data);
		pre = insert_end(pre,data);
	}
	for(i =0; i<n; i++){
		scanf("%d",&data);
		post = insert_end(post,data);
	}	
	post = reverse(post);
	start = create_post(start,post,n);
	inorder(start);
	printf("\n");
	preorder(start);
	printf("\n");
	postorder(start);
	printf("\n");
	return 0;
}	

struct tree *create_pre(struct tree *start,struct node *pre,int n){
	if( n == 0)
		return start;
	start = newnode(start,pre->info);
	if( n== 1)
		return start;
	struct node * q =pre;
	int i,data = pre->info;
	pre = pre->next;
	for( i =0; pre->info < data ; i++){
		pre = pre->next;
		if(pre == NULL)  break;
	}
	start->left = create_pre(start->left,q->next,i);
	start->right = create_pre(start->right,pre,n-i-1);	
	return start;
}

struct tree *create_post(struct tree *start,struct node *post,int n){
	if( n == 0)
		return start;
	start = newnode(start,post->info);
	if( n== 1)
		return start;
	struct node * q =post;
	int i,data = post->info;
	post = post->next;
	for( i =0; post->info > data ; i++){
		post = post->next;
		if(post == NULL)  break;
	}
	start->right= create_post(start->right,q->next,i);
	start->left = create_post(start->left,post,n-i-1);	
	return start;
}


struct node *insert_end(struct node *start,int i){
	struct node *tmp, *p = start;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info = i;
	tmp->next = NULL;
	if(start == NULL)
		return tmp;
	while(p->next != NULL)
		p = p->next;
	p->next = tmp;
	return start;
}
struct node *reverse(struct node *start){
	struct node *p = start, *prev = NULL,*nex;
	if(start == NULL || start->next == NULL)
		return start;
	while(p != NULL){
		nex = p->next;
		p->next = prev;
		prev = p;
		p = nex;
	}
	start = prev;
	return start;
}
void preorder(struct tree *start){
	if(start == NULL)   return;
	printf("%d_",start->info);
	preorder(start->left);
	preorder(start->right);
}
void inorder(struct tree *start){
	if(start == NULL)   return;
	inorder(start->left);
	printf("%d_",start->info);
	inorder(start->right);
}
void postorder(struct tree *start){
	if(start == NULL)   return;
	postorder(start->left);
	postorder(start->right);
	printf("%d_",start->info);
}

