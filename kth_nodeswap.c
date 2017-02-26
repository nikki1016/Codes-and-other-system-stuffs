#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node* create(struct node *start);
struct node *delete(struct node *start,int data);
struct node *insert_end(struct node *start,int data);
struct node *swap_kth(struct node* start,int k);
struct node* getnode(struct node*p);
void display (struct node *start);
int count(struct node *start);
struct node* copy(struct node*p,struct node *q);
int main(){
	struct node *start = NULL,*start2= NULL;
	int k;
	start = create(start);
	display(start);
	scanf("%d",&k);
	start = swap_kth(start,k);
	start2 = copy(start,start2);
	display(start2);
	//scanf("%d",&data);
	//start = delete(start,data);
	display(start);
	return 0;
}
struct node* getnode(struct node* p){
	p = (struct node*)malloc(sizeof(struct node));
	return p;
}
struct node* create(struct node *start){
	int data,n,i;
	scanf("%d",&n);
	scanf("%d",&data);
	if(n >=1){
		if(start == NULL){
			start = getnode(start);
			start->info = data;
			start->link = NULL;
		}
		for(i = 2; i<=n; i++ ){
			scanf("%d",&data);
			start = insert_end(start,data);
		}
	}
	return start;
}
struct node *insert_end(struct node* start,int data){
	struct node *p = start,*q ;
	q = getnode(q);
	q->info = data;
	q->link = NULL;
	while(p->link != NULL){
		p = p->link;
	}
	p->link = q;
	return start;
}
struct node *delete(struct node *start,int data){
	struct node *p = start,*temp ;
	if(p->info == data){
		temp =p;
		start = start->link;
		free(temp);
		return start;
	}
	while(p->link != NULL && p->link->info != data){
		p = p->link;
	}
	if( p->link == NULL){
		printf("not found\n");
		return start;
	}
	temp = p->link;
	p->link = p->link->link;
	free(temp);
	return start;
} 
struct node *swap_kth(struct node* start,int k){
	struct node *p = start, *temp = NULL,*q = start, *temp2 ;
	int c,i=2;
	c = count (start);
	if(p == NULL || k > c){
		return start;
	}
	while(p->link != NULL && i<k){		
		p = p->link;
		i++;
	}
	i = 2;
	while(q->link != NULL && i < c-k+1){
		q = q->link;
		i++;
	}
	if(p == start && q->link != NULL && (k == 1 || k == c)){
		start = q->link;
		temp = start->link;
		start->link = p->link;
		q->link = p;
		p->link = temp;
		return start;
	}	
	if(q == start && p->link != NULL && (k== 1|| k == c)){
		temp = p;
		p = q;
		q= temp;
		start = q->link;
		temp = start->link;
		start->link = p->link;
		q->link = p;
		p->link = temp;
		return start;
	}	
	if(p->link == q	){
		temp =p->link;
		p->link = q->link;
		temp2 = q->link->link;
		q->link->link = temp;
		q->link = temp2;
		//temp2 = temp;
		return start;
	}
	if(q->link == p	){
		temp = p;
		p = q;
		q= temp;
		temp =p->link;
		p->link = q->link;
		temp2 = q->link->link;
		q->link->link = temp;
		q->link = temp2;
		//temp2 = temp;
		return start;
	}
	temp = p->link->link;
	p->link->link = q->link->link;
	q->link->link = temp;	
	temp = p->link;
	p->link = q->link;
	q->link = temp;
	return start;
}
struct node* copy(struct node*start,struct node *q){
	struct node *p = start,*temp = q;
	if(q == NULL){
		q = getnode(q);
		q->info = p->info;
		q->link = NULL;
		p = p->link;	
	}
	while(p != NULL){
		q = insert_end(q,p->info);
		p = p->link;
	}
	return q;
}
int count (struct node *start){
	struct node* p = start;
	int c=0;	
	if(p == NULL){
		printf("empty\n");
		return;
	}	
	do {
		c++;
		p = p->link;
	}
	while(p !=NULL);
	return c;
}

void display (struct node *start){
	struct node* p = start;
	if(p == NULL){
		printf("empty\n");
		return;
	}	
	do {
		printf("%d -> ",p->info);
		p = p->link;
	}
	while(p->link !=NULL);
	printf("%d\n",p->info);
}

