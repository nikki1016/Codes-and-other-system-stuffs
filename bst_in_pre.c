#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};

struct tree *newnode(struct tree *tmp,int i){
	tmp = (struct tree *)malloc(sizeof(struct tree *));
	tmp->info = i;
	tmp->left = tmp->right = NULL;
	return tmp;
}
void inorder(struct tree *start){
	if(start == NULL)   return;
	inorder(start->left);
	printf("%d_",start->info);
	inorder(start->right);
}
void postorder(struct tree *start){
	struct tree *p =start;
	if(p == NULL) return;
	postorder(p->left);
	postorder(p->right);
	printf("%d_",p->info);
}
struct tree *recreate_pre(struct tree *start,int pre[],int *p,int in[],int instart,int inend){
	if(instart > inend )
		return start;
	int i,data;
	struct tree *tmp;
	data=pre[*p];
	tmp = newnode(tmp,data);
	//printf("hi\n");
	start = tmp;
	(*p)++;
	for(i = instart ; in[i] != data; i++);
	start->left = recreate_pre(tmp->left,pre,p,in,instart,i-1);
	start->right = recreate_pre(tmp->right,pre,p,in,i+1,inend);
	return start;
}
struct tree *recreate_post(struct tree *start,int post[],int n,int in[],int instart,int inend){
	if(instart > inend )
		return start;
	int i,data;
	struct tree *tmp;
	data = post[n];//printf("bbb  %d  \n",data);
	tmp = newnode(tmp,data);
	//printf("hki\n");
	start = tmp;
	//(*p)++;
	for(i = instart ; in[i] != data; i++);
	start->left = recreate_post(tmp->left,post,i-1,in,instart,i-1);
	start->right = recreate_post(tmp->right,post,n-1,in,i+1,inend);
	return start;
}
int main(){
	struct tree *start = NULL,*start2 = NULL;
	int pre[MAX],in[MAX],post[MAX],i,j,n;
	scanf("%d",&n);
	for(i =0; i<n; i++)
		scanf("%d",&pre[i]);
	for(i =0; i<n; i++)
		scanf("%d",&in[i]);
	i =0;
	start = recreate_pre(start,pre,&i,in,0,n-1);
	inorder(start);
	printf("\n");
	postorder(start);
	printf("\n");
	for(i =0; i<n; i++)
		scanf("%d",&post[i]);
	start2 = recreate_post(start2,post,n-1,in,0,n-1);
	inorder(start2);
	return 0;
}
