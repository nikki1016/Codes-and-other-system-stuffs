#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node* create(struct node *start);
struct node *delete(struct node *start,int data);
struct node *insert_end(struct node *start,int data);
void sum (struct node *start);
struct node* getnode(struct node*p);
void display (struct node *start);
int main(){
	struct node *start = NULL;
	int n;
	start = create(start);
	display(start);
	sum(start);
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
			start->link = start;
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
	while(p->link != start){
		p = p->link;
	}
	q->link = p->link;
	p->link = q;
	return start;
}
struct node *delete(struct node *start,int data);

void sum (struct node *start){
	struct node *p = start;
	int sum;
	do {
		if(p->info % 2 == 0)
			sum += p->info;
		p = p->link;
	}
	while(p->link != start);
	printf("%d\n",sum);
}

void display (struct node *start){
	struct node* p = start;
	do {
		printf("%d -> ",p->info);
		p = p->link;
	}
	while(p->link != start);
	printf("%d\n",p->info);
}

