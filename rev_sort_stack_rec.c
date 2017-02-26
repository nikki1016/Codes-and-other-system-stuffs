#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *getnode(struct node *p){
	p = (struct node *)malloc(sizeof(struct node));
	return p;
}
void display(struct node *strat);
struct node *push(struct node *start,int data);
struct node *pop(struct node *start);
int peek(struct node *start);
struct node *reverse(struct node *start);
struct node *sortstack(struct node *start);
struct node *insert_bot(struct node *start,int data);
struct node *insert_sort(struct node *start,int data);
int main(){
	struct node *start = NULL;
	int data,i;
	scanf("%d",&data);
	start = push(start,data);
	scanf("%d",&data);
        start = push(start,data);
	scanf("%d",&data);
        start = push(start,data);
	scanf("%d",&data);
        start = push(start,data);
	display(start);
	//start = pop(start);
	//display(start);
	start = sortstack(start);
	display(start);
	return 0;
}
struct node *push(struct node *start,int data){
	struct node *temp ;
	temp = getnode(temp);
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
}
struct node *pop(struct node *start){
	struct node *p = start;
	int i;
	if(p == NULL){
		printf("underflow\n");
		return start;
	}
	start = start->link;
	//printf("%d is popped\n",p->info);
	i = p->info;
	free(p);
	return start;
}
int peek(struct node *start){
	struct node *p = start;
	int i;
	if(p == NULL){
		printf("underflow\n");
		return -1;
	}
	//start = start->link;
	//printf("%d is popped\n",p->info);
	i = p->info;
	//free(p);
	return i;
}
void display(struct node *start){
	struct node *p =start;
	while(p->link != NULL){
		printf("%d-> ",p->info);
		p = p->link;
	}
	printf("%d\n",p->info);
}
struct node *reverse(struct node *start){
//	struct node *p = start;
	if(start == NULL)
		return start;
	int data = peek(start);
	start = pop(start);
	start = reverse(start);
	start =insert_bot(start,data);
	return start;
}
struct node *insert_bot(struct node *start,int data){
//	struct node *p = start;
	if(start == NULL){
		start = push(start,data);
		return start;
	}
	int tt = peek(start);
	start = pop(start);
	start = insert_bot(start,data);
	start = push(start,tt);
	return start;
}
struct node *sortstack(struct node *start){
	if(start == NULL)
		return start;
	int data = peek(start);
	start = pop(start);
	start = sortstack(start);
	start =insert_sort(start,data);
	return start;
}
struct node *insert_sort(struct node *start,int data){
//	struct node *p = start;
	if(start == NULL || data > peek(start)){
		start = push(start,data);
		return start;
	}
	int tt = peek(start);
	start = pop(start);
	start = insert_sort(start,data);
	start = push(start,tt);
	return start;
}
