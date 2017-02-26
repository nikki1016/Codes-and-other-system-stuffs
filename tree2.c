#include<stdio.h>
#include<stdlib.h>
struct tree{
	int info;
	struct tree *left,*right;
};
struct node {
	int info;
	struct node *next;
};
struct node *getnode(struct node *start,int info){
	start = (struct node *)malloc(sizeof(struct node ));
	start->info = info;
	start->next = NULL;
	return start;
}
struct node *insert_end(struct node *start,int info){
	struct node *p = start,*tmp;
	tmp = getnode(tmp,info);
	if(start == NULL){
		return tmp;
	}
	while(p->next != NULL){
		p = p->next;
	}
	p->next = tmp;
	return start;
}
struct node *insert_beg(struct node *start,int info){
        struct node *p = start,*tmp;
        tmp = getnode(tmp,info);
	if(start == NULL){
                return tmp;
        }
	tmp->next = p->next;
	 p->next= tmp;;
      return start;
}
struct tree *newnode(struct tree *start,int info){
	start = (struct tree*)malloc(sizeof(struct tree ));
	start->info = info;
	start->left = start->right = NULL;
	return start;
}
struct tree *insert(struct tree *start,int info){
	if(start == NULL){
		start = newnode(start,info);
		return start;
	}
	if(start->info > info)
		start->left = insert(start->left,info);
	else if(start->info < info)
		start->right = insert(start->right,info);
	return start;
}
void left_right(struct tree *start,int k){
	if(start == NULL)   return;
	left_right(start->right,k+1);
	int i;
	for(i =0;i<k;i++)
		printf("  ");
	printf("%d\n",start->info);
	left_right(start->left,k+1);
}
void root_leaf(struct tree *start,int k){
	if(start == NULL)   return;
	if( k == 0){
		printf("%d ",start->info);
	}
	root_leaf(start->left,k-1);
	root_leaf(start->right,k-1);
}
struct tree *remove_ksum(struct tree *start,int *sum,int key){
	if(start == NULL)    return start;
	int lsum,rsum;
	lsum = rsum = *sum +start->info;
	start->left = remove_ksum(start->left,&lsum,key);
	start->right = remove_ksum(start->right,&rsum,key);
	*sum = (lsum>rsum) ? lsum : rsum;
	if(*sum < key){
		free(start);
		return NULL;
	}
	return start;
}
struct tree *recreate(struct tree *start,struct node *in,struct node *pre,int n){
	if(n == 0)  return start;
	start = newnode(start,pre->info);
	int i,data = pre->info;
	if(n == 1){
		return start;
	}
	struct node *p = in,*ptr = pre;
	for(i =0; in->info != data; i++){
		in = in->next;
		pre = pre->next;
	}
	start->left = recreate(start->left,p,ptr->next,i);
	start->right = recreate(start->right,in->next,pre->next,n-i-1);
	return start;
} 
struct tree *recreate_post(struct tree *start,struct node *in,struct node *pre,int n){
	if(n == 0)  return start;
	int i=0,data;
	struct node *p = pre,*ptr = in;
	while(p->next != NULL && i< n-1){
		p = p->next;
		i++;
	}
	start = newnode(start,p->info);
	data = p->info;
	if(n == 1){
		return start;
	}
	p = pre;
	for(i =0; in->info != data; i++){
		in = in->next;
		p= p->next;
	}
	start->left = recreate_post(start->left,ptr,pre,i);
	start->right = recreate_post(start->right,in->next,p,n-i-1);
	return start;
} 
int main(){
	struct tree *root = NULL;
	struct node *start = NULL,*start2 = NULL;
	int data,i,n;
	scanf("%d",&n);
	for(i =0; i<n; i++){
		scanf("%d",&data);
		start = insert_end(start,data);
	}
	for(i =0; i<n; i++){
		scanf("%d",&data);
		start2 = insert_end(start2,data);
	}
	root = recreate_post(root,start2,start,n);
	left_right(root,0);
	scanf("%d",&data);
	i = 0;
	root = remove_ksum(root,&i,data);
	left_right(root,0);
	return 0;
}
