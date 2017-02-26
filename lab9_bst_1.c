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
struct tree *insert_nrec(struct tree * start, int data);
struct tree *delete(struct tree *start,struct tree *p,int  n);
struct tree *case_a(struct tree *start,struct tree *par);
struct tree *case_b(struct tree *start,struct tree *par);
struct tree *case_c(struct tree *start,struct tree *par);
struct tree *search (struct tree *start,int data);
struct tree *search_par(struct tree *start,int n);
struct tree *min(struct tree *start);
struct tree *max(struct tree *start);
struct tree *mirror_tree(struct tree *start1,struct tree *start2);
struct tree *pred(struct tree *start,int key);
struct tree *succ(struct tree *start,int key);
struct tree *del_rec(struct tree *start,int key);
struct tree *tree_del_in(struct tree *start);
struct tree *tree_del_leaf(struct tree *start);
struct tree *copy_tree(struct tree *start1,struct tree *start2);
void level_sum_max(struct tree *start,struct tree *q[],int *front,int *rear,int *max);
void level_knode(struct tree *start,int k);

int isbst(struct tree *start,int min,int max);
int isidentical(struct tree *start1,struct tree *start2);
int issimilar(struct tree *start1,struct tree *start2);
int ismirror(struct tree *start1,struct tree *start2);
int is_sum_tree(struct tree *start1);
void printknode(struct tree *start,int k);
void ancestor(struct tree *start,int key);
void displayLR(struct tree *start,int level);
int count (struct tree *start);
int check(struct tree *start1,struct tree *start2,int *top,struct tree *arr[]);
int no_leaf(struct tree *start);
int sum_leaf(struct tree *start);
int height(struct tree *start);
int diameter(struct tree *start);
void root_leaf(struct tree *start,int path[],int i);
void inorder (struct tree *start);
void postorder(struct tree *start);
void preorder(struct tree *start);
void inorder_nrec( struct tree *start,int *top,struct tree *arr[]);
void postorder_nrec(struct tree *start,int *top,struct tree *arr[]);
void preorder_nrec(struct tree *start,int *top,struct tree *arr[],int pre[]);
void levelorder( struct tree *start,int *top,int *rear,struct tree *arr[]);

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
	while(1){
		scanf("%d",&ch);
		//start =  NULL;
		start2 =  NULL;
		switch(ch){
			case 1:		
				
				/*scanf("%d",&k);
				for(i =0; i<k; i++){
					scanf("%d",&data);
					p = search(start,data);
  					if(p == NULL)
						printf("n\n");
					else
						printf("y\n");
				}*/
				inorder(start);			
				printf("\n");
				start2 = copy_tree(start,start2);
				inorder(start2);

				scanf("%d",&data);
				start = del_rec(start,data);inorder(start);			
				printf("\n");
				start = tree_del_leaf(start);
				inorder(start);printf("hi\n");

				break;
			case 2:
				preorder(start);
				printf("\n");
				inorder(start);			
				printf("\n");
				postorder(start);			
				printf("\n");
				n = diameter(start);
				printf("%d is diameter\n",n);
				start2 = mirror_tree(start,start2);
				inorder(start2);
				data = ismirror(start,start2);	
				if(data == 1)
					printf("yes mirror\n");
				else printf("nopes mirror\n");
				data = isidentical(start,start2);
				if(data == 1)
					printf("yes identical\n");
				else printf("nopes identical\n");	
				data = issimilar(start,start2);	
				if(data == 1)
					printf("yes similar\n");
				else printf("nopes similar\n");
				data = isbst(start2,INT_MIN,INT_MAX);	
	//printf("%d data\n",data);
				if(data == 1)
					printf("yes BST\n");
				else printf("nopes BST\n");
				data = is_sum_tree(start);	
				if(data == 1)
					printf("yes sum tree\n");
				else printf("nopes sum tree\n");
				scanf("%d",&data);
				p = pred(start,data);
				if(p == NULL)
					printf("%d has no pred\n",data);
				else 
					printf("%d is pred of %d\n",p->info,data);		
				printf("%d \n",count(start));
				p = succ(start,data);
				if(p == NULL)
					printf("%d has no succ\n",data);
				else 
					printf("%d is suc of %d\n",p->info,data);		
				printf("\n");
				printknode(start,data);
				ancestor(start,data);
				break;
			case 3:
				displayLR(start,0);
				break;
			case 4:
				scanf("%d",&t);
				scanf("%d",&n);
				while(t--){
					start = NULL; start2 = NULL;
					for(i = 0; i < n; i++){
						scanf("%d",&data);
						start = insert(start,data);
					}
					for(i = 0; i < n; i++){
						scanf("%d",&data);
						start2 = insert(start2,data);
					}
					//if(check(start,start2,&top,arr))
						//printf("y\n");
					//else printf("n\n");
					root_leaf(start,path,0);inorder(start);printf("\n");
					root_leaf(start2,path,0);inorder(start2);printf("\n");
				}
				break;
		}
	}
	return 0;
}

struct tree *newnode(struct tree *p,int data){
	p = (struct tree *)malloc(sizeof(struct tree));
	p->info = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}
int isbst(struct tree *start,int min,int max){
	if(start == NULL)
		return 1;
	if(start->info < min || start->info > max)
		return 0;
	return isbst(start->left,min,start->info) && isbst(start->right,start->info,max);
}
struct tree *pred(struct tree *start,int key){
	struct tree *p,*tmp,*par ;
	p = search(start,key);
	if(p == NULL)
	return;
	if(p->left != NULL){
		tmp = max(p->left);
		return tmp;
	}
	else {
		tmp = p;
		par = search_par(start,key);
		while(  par != NULL){
			if(par->info > key){	
				p = par;
				par = search_par(start,p->info);
			}
			else break;
		}
	}
	return par;
}
struct tree *succ(struct tree *start,int key){
	struct tree *p,*tmp,*par ;
	p = search(start,key);
	if(p == NULL)
		return p;
	if(p->right != NULL){
		tmp = min(p->right);
		return tmp;
	}
	else {
		tmp = p;
		par = search_par(start,key);
		while( par != NULL){
			if(par->info < key){
				p = par;
				par = search_par(start,p->info);
			}
			else break;
		}
	}
	return par;
}
int count (struct tree *start){
	int i;
	if(start == NULL)
		return 0;
	return  count(start->left) + count (start->right) + 1; 
}
void printknode(struct tree *start,int k){
	if(start == NULL){
		printf("hi\n");return;
	}
	if(k > count(start))
	return;
	if(k == 0){
		printf("%d->",start->info);
		return;
	}
	printknode(start->left,k-1);
	printknode(start->right,k-1);
}
void ancestor(struct tree *start,int key){
	struct tree *p,*par;
	int i = 0,an[MAX];
	p = search(start,key);
	par = search_par(start,key);
	while(par != NULL){
		an[i++] = par->info;
		p = par;
		par = search_par(start,p->info);
	}
	while(--i)
		printf("%d--",an[i]);
	printf("%d\n",an[i]);
	return;
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
	return start;	
}
struct tree *mirror_tree(struct tree *start1,struct tree *start2){
	struct tree * tmp = start1;
	if(start1 == NULL)  return start1;
	int data;
	data = start1->info;
	if(start2 == NULL){
		tmp = newnode(tmp,data);
		start2 = tmp;
		//return start;
	}
	//start2 = ins_mir(start2,tmp->info);
	tmp = start1;
	if(tmp->left != NULL){
		//start2 = ins_mir(start2,tmp->left->info);	
		start2->right = mirror_tree(start1->left,start2->right);
	}
	if(tmp->right != NULL){
		//start2 = ins_mir(start2,tmp->right->info);
		start2->left = mirror_tree(start1->right,start2->left);	
	}
	return start2;
}

	 
struct tree *insert_nrec(struct tree * start, int data){
	struct tree *p = start, *temp,*par = NULL;
	if(start == NULL){
		temp = newnode(temp,data);
		start = temp;
		return start;
	}
	while(p!= NULL){
		par = p;
		if(p->info > data)
			p = p->left;
		else if(p->info < data)
			p = p->right;
		else  return start;
	}
	if(data < par->info)
		par->left = newnode(par->left,data);
	else if(data > par->info)
		par->right = newnode(par->right,data);
	return start;	
}
struct tree *copy_tree(struct tree *start1,struct tree *start2){
	if(start1 == NULL)
		return start1;
	start2 = newnode(start2,start1->info);
	start2->left = copy_tree(start1->left, start2->left);
	start2->right = copy_tree(start1->right, start2->left);
	return start2;
}
struct tree *search_par(struct tree *start,int n){
	if(start == NULL){
		printf("not found\n");
		return start;
	}
	struct tree *tmp= start,*par= NULL;
	if(start->info == n){
		return par;
	}
	while(tmp != NULL){
		par = tmp;
		if(tmp->info > n)
			tmp = tmp->left;
		else 
			tmp = tmp->right;
		if(tmp->info == n)
			return par;
	}
	return tmp;	
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
		tmp = search_par(start->right,start->info);
		suc = case_a(suc,tmp);
	}
	else if(suc->left == NULL || suc->right ==NULL){
		tmp = search_par(start->right,start->info);
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
		printf("left\n");
	}
	else if(start->info < n){
		start->right = delete(start->right,start,n);
		printf("rightt\n");
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
			suc = min(start->right);
			start->info = suc->info;
			start->right = del_rec(start->right,start->info);
		}
	}
	return start;
}
struct tree *tree_del_in(struct tree *start){
	if(start == NULL)
		return start;
	start->left = tree_del_in(start->left);
	printf("%d _ ",start->info);
	start->right = tree_del_in(start->right);
	free(start);
	return NULL;
}
struct tree *tree_del_leaf(struct tree *start){
	if(start == NULL)
		return start;
	if(start->left == NULL && start->right == NULL){
		free(start);
		return NULL;
	}
	start->left = tree_del_leaf(start->left);
	//printf("%d _ ",start->info);
	start->right = tree_del_leaf(start->right);
	
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
void displayLR(struct tree *start,int level){
	if(start == NULL)  return;
	displayLR(start->right, level+1);
	int i;
	for(i = 0; i< level; i++)
		printf("@ ");
	printf("%d\n",start->info);
	displayLR(start->left, level+1);	
}
int isidentical(struct tree *start1,struct tree *start2){
	if(start1 == NULL &&  start2 == NULL)
		return 1;
	if(start1 != NULL && start2 != NULL){
		if(start1->info == start2->info)
			return isidentical(start1->left,start2->left) && isidentical(start1->right,start2->right);
	}
	return 0;
}

int issimilar(struct tree *start1,struct tree *start2){
	if(start1 == NULL &&  start2 == NULL)
		return 1;
	if(start1 != NULL && start2 != NULL){
		return issimilar(start1->left,start2->left) && issimilar(start1->right,start2->right);
	}
	return 0;
}
int ismirror(struct tree *start1,struct tree *start2){
	if(start1 == NULL &&  start2 == NULL)
		return 1;
	if(start1 != NULL && start2 != NULL){
		if(start1->info == start2->info)
			return ismirror(start1->left,start2->right) && ismirror(start1->right,start2->left);
	}
	return 0;
}
int is_sum_tree(struct tree *start1){
	if(start1 == NULL )
		return 1;
	if(start1->left == NULL && start1->right == NULL)
		return 1;
	if(start1->left != NULL && start1->right == NULL)
		return 0;
	if(start1->left == NULL && start1->right != NULL)
		return 0;
	if(start1->info == start1->right->info + start1->left->info)
		return is_sum_tree(start1->left) && is_sum_tree(start1->right);
	return 0;
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

int check(struct tree *start1,struct tree *start2,int *top,struct tree *arr[]){
	int pre1[MAX],pre2[MAX],n,i;
	preorder_nrec(start1,top,arr,pre1);
	//preorder(start1);
	int h1,h2;
	printf("%d & %d  & %d & %d leaves\n",height(start1),height(start2),sum_leaf(start1),sum_leaf(start2));
	preorder_nrec(start2,top,arr,pre2);
	//preorder(start2);
	if(h1 != h2)
		return 0;
	for(i = 0; i<n; i++){
		if(pre1[i] != pre2[i])
			return 0;
	}
	return 1;
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
int diameter(struct tree *start){
	int lh = 0,rh = 0, ldia = 0, rdia =0,dia;
	if(start == NULL)
		return 0;
	lh = height(start->left);
	rh = height(start->right);
	ldia = diameter(start->left);
	rdia = diameter(start->right);
	dia = (ldia > rdia) ? ldia : rdia;
	if(dia > lh+rh +1)
		return dia;
	else return lh+rh+1;
}
		
int no_leaf(struct tree *start){
	if (start == NULL)
		return 0;
	int h_left,h_right;
	if(start->left == NULL && start->right == NULL)
		return 1;
	h_left = no_leaf(start->left);
	h_right =no_leaf(start->right);
	return h_left + h_right;
}
int sum_leaf(struct tree *start){
	if (start == NULL)
		return 0;
	int h_left,h_right;
	if(start->left == NULL && start->right == NULL)
		return start->info;
	h_left = sum_leaf(start->left);
	h_right =sum_leaf(start->right);
	return h_left + h_right;
}
void root_leaf(struct tree *start,int path[],int i){
	if(start == NULL)
		return;
	path[i++] = start->info;
	int j;
	if(start->left == NULL && start->right == NULL){
		for(j =0; j < i; j++)
			printf("%d-",path[j] );
		printf("\n");
	}
	root_leaf(start->left,path,i);
	root_leaf(start->right,path,i);
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
			if(*top == -1){
				printf("\n");
				return;
			}
			arr = pop(&p,arr,top);
		}	//printf("hello3\n");
		printf("%d ",p->info);
		p = p->right;

	}
	printf("\n");
}
	
void preorder_nrec(struct tree *start,int *top,struct tree *arr[],int pre[]){
	struct tree *p = start;
	if(start == NULL){
		printf("EMPTY\n");
		return;
	}
	int n = 0;
	arr = push(p,arr,top);
	while(*top != -1){
		arr = pop(&p,arr,top);
		printf("%d--",p->info);
		pre[(n)++] = p->info;
		if(p->right != NULL){
			arr = push(p->right,arr,top);
		}
		if(p->left != NULL){
			arr = push(p->left,arr,top);
		}
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
			if(*top == -1){
				printf("\n");
				return;
			}
			arr = pop(&p,arr,top);
		}	//printf("hello3\n");
		arr = push(p,arr,top);		
		p = p->right;
		
	}
	printf("\n");
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
