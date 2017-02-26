#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100
struct tree {
	int info;
	struct tree *left;
	struct tree *right;
};
struct tree **push(struct tree *p,struct tree *arr[],int *top);
struct tree **pop(struct tree **p,struct tree *arr[],int *top);
struct tree **enqueue(struct tree *p,struct tree *arr[],int *top,int *rear);
struct tree **dequeue(struct tree **p,struct tree *arr[],int *top ,int *rear);
struct tree *insert(struct tree * start, int data);
struct tree *delete(struct tree *start, int data);
struct tree *del_tree(struct tree *start);
struct tree *case_1(struct tree *start,struct tree *par,struct tree *p);
struct tree *case_2(struct tree *start,struct tree *par,struct tree *p);
struct tree *case_3(struct tree *start,struct tree *par,struct tree *p);
struct tree *search (struct tree *start,int data);
struct tree *search_par(struct tree *start,struct tree *par,int data);
struct tree *min(struct tree *start);
struct tree *max(struct tree *start);
int height(struct tree *start);
int isbst(struct tree *start,int max,int min);
void inorder (struct tree *start);
void postorder(struct tree *start);
void preorder(struct tree *start);
void inorder_nrec( struct tree *start,int *top,struct tree *arr[]);
void postorder_nrec(struct tree *start,int *top,struct tree *arr[]);
void preorder_nrec(struct tree *start,int *top,struct tree *arr[]);
void levelorder( struct tree *start,int *top,int *rear,struct tree *arr[]);

int main(){
	struct tree *start= NULL,*p;
	int data,i,n,k,top=-1,front = -1,rear = -1;
	struct tree *arr[MAX],*q[MAX];
	scanf("%d",&n);
	for(i = 0; i<n; i++){
		scanf("%d",&data);
		start = insert(start,data);
	}
	scanf("%d",&k);
	for(i =0; i<k; i++){
		scanf("%d",&data);
		p = search(start,data);
  		if(p == NULL)
			printf("n\n");
		else{
			start = delete(start, data);
			printf("y\n");
		}
	}
				preorder(start);
				printf("\n");
				postorder(start);			
				printf("\n");
				//levelorder(start,&front,&rear,q);
				inorder(start);			
				printf("\n");
	if( isbst(start, INT_MAX ,INT_MIN ))
		printf("yes\n");
	else printf("no\n");
	start = del_tree(start);
	if(start != NULL)
		preorder(start);
	printf("\n");
	return 0;
}
struct tree **push(struct tree *p,struct tree *arr[],int *top){
	if(*top == MAX){
		printf("overflow\n");
		return;
	}
	(*top)++;
	arr[*top] = p;
	//printf("hi\n");
	return arr;
}
struct tree **pop(struct tree **p,struct tree *arr[],int *top){
	if(*top == -1){
		printf("underflow\n");
		return;
	}
	*p = arr[*top];
	(*top)--;
	//printf("pop\n");
	return arr;
}
struct tree **enqueue(struct tree *p,struct tree *arr[],int *top,int *rear){
	if(*top == (*rear+1) % MAX){
		printf("overflow\n");
		return;
	}
	if(*top == -1)
		(*top)++;
	(*rear) = (*rear+1)%MAX;
	arr[*rear] = p;
	//printf("hi\n");
	return arr;
}
struct tree **dequeue(struct tree **p,struct tree *arr[],int *top ,int *rear){
	if(*top == -1 && *rear == -1){
		printf("underflow\n");
		return;
	}
	*p = arr[*top];
	if(*top == *rear)
		*top = *rear = -1;
	else
		(*top) = (*top + 1)% MAX;
	//printf("pop\n");
	return arr;
}
struct tree *newnode(struct tree *p,int data){
	p = (struct tree *)malloc(sizeof(struct tree));
	p->info = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
struct tree *insert(struct tree * start, int data){
	struct tree *p = start, *temp;

	if(start == NULL){
		temp = newnode(temp,data);
		start = temp;
		return start;
	}
	if(data < start->info)
		start->left = insert(start->left,data);
	else if(data > start->info)
		start->right = insert(start->right,data);
	else return start;	
}

struct tree *delete(struct tree *start, int data){
	struct tree *p,*par = NULL;
	p = search(start,data);
	if(p == NULL){
		printf("not found\n");
		return start;
	}
	par = search_par(start,par,data);
	if(par != NULL)
		printf("%d is parent of %d\n",par->info,p->info);
	if(p->left == NULL && p->right == NULL){
		start = case_1(start,par,p);
	}
	else if(p->left == NULL || p->right == NULL){
		start = case_2(start,par,p);
	}
	else {
		start = case_3(start,par,p);
	}
	return start;
}
struct tree *del_tree(struct tree *start){
	if(start == NULL)
		return start;
	struct tree *p;
	int minim;
	while(start != NULL){
		p = min(start);
		//printf("%d is min\n",p->info);
		start = delete(start,p->info);
	}
	return start;
}
struct tree *case_1(struct tree *start,struct tree *par,struct tree *p){
	struct tree *tmp;
	tmp = p;
	if(par == NULL){
		printf("%d is deleted\n",tmp->info);
		free(tmp);
		return par;
	}
	if(par->left == p){
		par->left = NULL;
	}
	else if(par->right == p)
		par->right = NULL;
	printf("%d is deleted\n",tmp->info);
	free(tmp);
	return start;
}
struct tree *case_2(struct tree *start,struct tree *par,struct tree *p){
	struct tree *tmp;
	tmp = p;
	if(par == NULL){
		if(tmp ->left != NULL)
			start = tmp->left;
		else 
			start = tmp->right;
	}
	else if(par->left == p){
		if(tmp ->left != NULL)
			par->left = tmp->left;
		else par->left = tmp->right;
	}
	else if(par->right == p){
		if(tmp ->left != NULL)
			par->right = tmp->left;
		else par->right = tmp->right;
	}
	printf("%d is deleted\n",tmp->info);
	free(tmp);
	return start;
}
struct tree *case_3(struct tree *start,struct tree *par,struct tree *p){
	struct tree *tmp , *suc;
	int t;
	tmp = p;
	suc = min(tmp->right);
	t = tmp->info;
	tmp->info = suc->info;
	suc->info = t;
	start = delete(start,suc->info);
	return start;
}
struct tree *search (struct tree *start,int data){
	if(start == NULL || start->info == data){
		return start;
	}
	if(data < start->info)
		return search(start->left,data);
	else if(data > start->info)
		return  search(start->right,data);
	else return start;	

}
struct tree *search_par(struct tree *start,struct tree *par,int data){
	if(start == NULL || start->info == data){
		return par;
	}
	if(data < start->info)
		return search_par(start->left,start,data);
	else if(data > start->info)
		return  search_par(start->right,start,data);
	else return par;	

}
struct tree *min(struct tree *start){
	if(start == NULL ){
		return start;
	}
	struct tree *p = start;
	while(p->left != NULL)
		p = p->left;
	return p;	
}
struct tree *max(struct tree *start){
	if(start == NULL ){
		return start;
	}
	struct tree *p = start;
	while(p->right != NULL)
		p = p->right;
	return p;	
}
int isbst(struct tree *start,int max,int min){
	if(start == NULL)   return 1;
	if(start->info > max || start->info < min )
		return 0; 
	return isbst(start->left,(start->info)-1,min) && isbst(start->right,max,(start->info)+1);
}

int height(struct tree *start){
	if (start == NULL)
		return 0;
	int h_left,h_right;
	h_left = 1+height(start->left);
	h_right = 1+height(start->right);
	if(h_left > h_right)
		return h_left;
	else return h_right;
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
	 printf("%d_",p->info);
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
void inorder_nrec(struct tree *start,int *top,struct tree *arr[]){
	struct tree *p = start;
	if(start == NULL){
		printf("EMPTY\n");
		return;
	}

	while(1){
		while(p->left != NULL){
			arr = push(p,arr,top);
			p = p->left;
		}
		//printf("%d ",p->info);
		while(p->right == NULL){
			printf("%d ",p->info);
			if(*top == -1)
				return;
			arr = pop(&p,arr,top);
		}	//printf("hello3\n");
		printf("%d ",p->info);
		p = p->right;

	}
	printf("\n");
}
	
void preorder_nrec(struct tree *start,int *top,struct tree *arr[]){
	struct tree *p = start;
	if(start == NULL){
		printf("EMPTY\n");
		return;
	}

	while(1){
		while(p->left != NULL){
			printf("%d ",p->info);
			arr = push(p,arr,top);
			p = p->left;
		}
		//printf("%d ",p->info);
		while(p->right == NULL){
			printf("%d ",p->info);
			if(*top == -1)
				return;
			arr = pop(&p,arr,top);
		}	//printf("hello3\n");
		//printf("%d ",p->info);
		p = p->right;

	}
	printf("\n");
}
void postorder_nrec(struct tree *start,int *top,struct tree *arr[]){
	struct tree *p = start,*q = NULL;
	if(start == NULL){
		printf("EMPTY\n");
		return;
	}
	q = start;
	while(1){
		while(p->left != NULL){
			arr = push(p,arr,top);
			p = p->left;
		}
		//printf("%d ",p->info);
		while(p->right == NULL || p->right == q){
			printf("%d ",p->info);
			q = p;		
			if(*top == -1)
				return;
			arr = pop(&p,arr,top);
		}	//printf("hello3\n");
		arr = push(p,arr,top);		
		p = p->right;
		
	}
	printf("\n");
}
void levelorder( struct tree *start,int *top,int *rear,struct tree *arr[]){
	struct tree *p = start;
	if(start == NULL){
		printf("EMPTY\n");
		return;
	}
	arr = enqueue(p,arr,top,rear);
	while( *top != -1){
		arr = dequeue(&p,arr,top,rear);
		printf("%d ",p->info);
		if(p->left != NULL)
			arr = enqueue(p->left,arr,top,rear);
		if(p->right != NULL)		
			arr = enqueue(p->right,arr,top,rear);
	}
	printf("\n");
}
