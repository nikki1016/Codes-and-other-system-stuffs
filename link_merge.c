#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node* create(struct node *start);
struct node *delete(struct node *start,int data);
struct node *insert_end(struct node *start,int data);
struct node *merge(struct node* start,struct node *start2);
struct node* getnode(struct node*p);
void display (struct node *start);
int main(){
	struct node *start = NULL,*start2= NULL;
	start = create(start);
	start2 = create(start2);
	display(start);
	display(start2);
	start = merge(start,start2);
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
struct node *delete(struct node *start,int data);
struct node *merge(struct node* start,struct node *start2){
	struct node *p = start,*q = start2, *temp = NULL,*temp2 = NULL ;
	if(p == NULL){
		return q;
	}
	if(q == NULL){
		return p;
	}
	while(p->link != NULL && q->link != NULL){
		if(p->link != NULL)		
			temp = p->link;		
		p->link = q;
		if(q->link != NULL)		
			temp2 = q->link;
		q->link = temp;
		if(temp2 != NULL) q = temp2;
		if(temp != NULL) p = temp;
	}
	p->link = q;
	return start;
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

