#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};
struct tree *newnode(struct tree *tmp,int i){
	tmp = (struct tree *)malloc(sizeof(struct tree ));
	tmp->info = i;
	tmp->left = tmp->right = NULL;
	return tmp;
}
struct tree **enqueue(struct tree *start,struct tree *q[],int *front,int *rear);
struct tree **dequeue(struct tree **start,struct tree *q[],int *front,int *rear);
void bfs(struct tree *start,struct tree *q[],int *front,int *rear);
void level_spiral(struct tree *start,struct tree *q[],int *front,int *rear);
void level_sum_max(struct tree *start,struct tree *q[],int *front,int *rear,int *max);
void level_knode(struct tree *start,int k);
struct tree *range_bound(struct tree *start,int min,int max);                         //delete nodes not lie in range[min,max],
struct tree *count_bound(struct tree *start,int min,int max,int *c);                    //count nodes  lie in range[min,max].
struct tree *min(struct tree *start);
struct tree *insert(struct tree *start,int  n);
struct tree *search_par(struct tree *start,struct tree *par,int n);
struct tree *case_a(struct tree *start,struct tree *par);
struct tree *case_b(struct tree *start,struct tree *par);
struct tree *case_c(struct tree *start,struct tree *par);
struct tree *delete(struct tree *start,struct tree *p,int  n);
struct tree *del_rec(struct tree *start,int data);
void postorder(struct tree *start);
void inorder(struct tree *start);
void preorder(struct tree *start);
int main(){
	struct tree *start = NULL,*p = NULL;
	struct tree * q[MAX];
	int data,i,n,front =-1,rear = -1,max = -999;
	scanf("%d",&n);
	for(i =0; i<n; i++){
		scanf("%d",&data);
		start = insert(start,data);
	}
	inorder(start);
	printf("\n");
	preorder(start);
	printf("\n");
	postorder(start);
	printf("\n");
	level_spiral(start,q,&front,&rear);
	level_sum_max(start,q,&front,&rear,&max);
	printf("%d is max\n",max);
	scanf("%d%d",&data,&n);
	i = 0;
	//level_knode(start,data);
		//p = search_par(start,NULL,data);
	start = count_bound(start,data,n,&i);
	printf("%d is count\n",i);
	start = range_bound(start,data,n);
	//start = del_rec(start,data);
	inorder(start);
	printf("\n");
	preorder(start);
	printf("\n");
	postorder(start);
	printf("\n");
	return 0;
}	
struct tree *range_bound(struct tree *start,int min,int max){                     //delete nodes not lie in range[min,max].
	if(start == NULL){
		return start;
	}
	start->left = range_bound(start->left,min,max);
	start->right = range_bound(start->right,min,max);
	if(min > start->info ){
		return start->right;
	}
	if(start->info > max ){
		return start->left;
	}
	
	return start;
}

struct tree *count_bound(struct tree *start,int min,int max,int *c){                     //count nodes  lie in range[min,max].
	if(start == NULL){
		return start;
	}
	if(min <= start->info && start->info <= max ){
		(*c)++;
		//return start;
	}
	start->left = count_bound(start->left,min,max,c);
	start->right = count_bound(start->right,min,max,c);
	
	return start;
}


struct tree **enqueue(struct tree *p,struct tree *q[],int *front,int *rear){
	if(*front == (*rear+1)%MAX){
		printf("overflow\n");
		return q;
	}
	if(*front == -1)
		*front = 0;
	*rear = (*rear +1) % MAX;
	q[*rear] = p;
	//printf("hi\n");
	
	return q;
}

struct tree **dequeue(struct tree **ptr,struct tree *q[],int *front,int *rear){
	if(*front == -1){
		printf("overflow\n");
		return NULL;
	}
	*ptr = q[*front] ;
	//printf("hifi\n");
	if(*front == *rear){
		*front = *rear = -1;
	}
	else *front = (*front +1) % MAX;
	//printf("ji\n");
	return q;
}

void bfs(struct tree *start,struct tree *q[],int *front,int *rear){
	struct tree *p = start ;
	if(start == NULL)    return;
	q = enqueue(p,q,front,rear);
	while(*front != -1){
		q = dequeue(&p,q,front,rear);	
		printf("%d->",p->info);
		if(p->left != NULL)
			q = enqueue(p->left,q,front,rear);	
		if(p->right != NULL)
			q = enqueue(p->right,q,front,rear);
	}
}
void level_spiral(struct tree *start,struct tree *q[],int *front,int *rear){
	struct tree *p = start ;
	int i=0;
	if(start == NULL)    return;
	q = enqueue(p,q,front,rear);
	q = enqueue(NULL,q,front,rear);
	while(*front != -1){
		q = dequeue(&p,q,front,rear);
		if(p != NULL){	
			printf("%d->",p->info);
			if(i % 2 ){
				if(p->left != NULL){
					q = enqueue(p->left,q,front,rear);
				}
				if(p->right != NULL){
					q = enqueue(p->right,q,front,rear);
				}
			}
			else {
				if(p->right != NULL){
					q = enqueue(p->right,q,front,rear);
				}
				if(p->left != NULL){
					q = enqueue(p->left,q,front,rear);	
				}
			}
		}
		else if(p == NULL){
			i++;
			if(*front == *rear && q[*front] == NULL)
				return;  
			//printf(" --%d  ",sum);
			q = enqueue(NULL,q,front,rear);
		}
	}
}
void level_sum_max(struct tree *start,struct tree *q[],int *front,int *rear,int *max){
	struct tree *p = start ;
	int sum=0;
	if(start == NULL)    return;
	q = enqueue(p,q,front,rear);
	*max = start->info;
	q = enqueue(NULL,q,front,rear);
	while(*front != -1){
		q = dequeue(&p,q,front,rear);
		if(p != NULL){	
			//printf("%d->",p->info);
			if(p->left != NULL){
				q = enqueue(p->left,q,front,rear);	
				sum += p->left->info;
			}
			if(p->right != NULL){
				q = enqueue(p->right,q,front,rear);
				sum += p->right->info;
			}
		}
		else if(p == NULL){
			if(*front == *rear && q[*front] == NULL)
				return;  
			printf(" --%d  ",sum);
			q = enqueue(NULL,q,front,rear);
			if(sum > *max){
				*max = sum;
				sum = 0;
			}
		}
	}
}
void level_knode(struct tree *start,int k){
	if(start == NULL)   return;
	if( k ==0 ){	
		printf("%d_",start->info);
		return;
	}
	level_knode(start->left,k-1);
	level_knode(start->right,k-1);
}

struct tree *min(struct tree *start){
	struct tree *tmp = start;
	while(tmp->left != NULL)
		tmp = tmp->left;
	return tmp;
}
struct tree *insert(struct tree *start,int  n){
	if(start == NULL){
		struct tree *tmp;
		tmp = newnode(tmp,n);
		return tmp;
	}
	if(start->info > n)
		start->left = insert(start->left,n);
	else if (start->info < n )
		start->right = insert(start->right,n);
	return start;
}
struct tree *search_par(struct tree *start,struct tree *par,int n){
	if(start == NULL){
		printf("not found\n");
		return start;
	}
	struct tree *tmp= start;
	if(start->info == n){
		return par;
	}
	else if( start->info > n){
		tmp = search_par(start->left,start,n);
	}
	else 
		tmp = search_par(start->right,start,n);
	return tmp;
}
struct tree *del_rec(struct tree *start,int data){
	if(start == NULL){
		printf("not found\n");
		return start;
	}
	if(data > start->info ){
		start->right = del_rec(start->right, data);
	}
	else if(data < start->info ){
		start->left = del_rec(start->left, data);
	}
	else {
		struct tree *p = start,*suc;
		if(start->left != NULL && start->right != NULL){
			suc = min(start->right);
			start->info = suc->info;
			start->right = del_rec(start->right,start->info);
		}
		else if(start->left != NULL){
			start = start->left;
			free(p);
			return start;
		}
		else if(start->right != NULL){
			start = start->right;
			free(p);
			return start;
		}
		else {
			free(p);
			return start;
		}
	}
	return start;
}
		
struct tree *case_a(struct tree *start,struct tree *par){
	struct tree *p = start;
	if(par != NULL){
		if(par->left == start)
			par->left = NULL;
		else 
			par->right = NULL;

	}
	start = NULL;
	free(p);
	return start;
}

struct tree *case_b(struct tree *start,struct tree *par){
	struct tree *p = start;
	if(par == NULL){
		if(start->left != NULL)
			start = start->left;
		else 
			start = start->right;
	}
	else {
		if(start->right != NULL){
			if(par->left == start){
				par->left = start->right;
				start = par->left;
			}
			else {
				par->right = start->right;
				start = par->right;
			}
		}
		else if(start->left != NULL){
			if(par->left == start){
				par->left = start->left;
				start = par->left;
			}
			else {
				par->right = start->left;
				start = par->right;
			}
		}	
	}
	free(p);
	return start;
}

struct tree *case_c(struct tree *start,struct tree *par){
	struct tree *p = start,*suc,*tmp;
	suc = min(start->right);
	int t;
	//t = start->info;
	start->info = suc->info;
	//suc->info = t;
	if(suc->left == NULL && suc->right ==NULL){
		tmp = search_par(start->right,start,start->info);
		suc = case_a(suc,tmp);
	}
	else if(suc->left == NULL || suc->right ==NULL){
		tmp = search_par(start->right,p,start->info);
		suc = case_b(suc,tmp);
	}
	//start = delete(start,par,t);
	return start;
}

struct tree *delete(struct tree *start,struct tree *p,int  n){
	struct tree *tmp;
	if(start == NULL){
		printf("not found %d\n",n);
		return start;
	}
	if(start->info > n){
		start->left = delete(start->left,start,n);
		//printf("left\n");
	}
	else if(start->info < n){
		start->right = delete(start->right,start,n);
		//printf("rightt\n");
	}	
	else {
		//tmp = search_par(start,p,n);
		if(start->left == NULL && start->right == NULL)
			start = case_a(start,p);
		else if(start->left == NULL || start->right == NULL)
			start = case_b(start,p);
		else 
			start = case_c(start,p);
	}
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

