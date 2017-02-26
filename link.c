#include<stdio.h>
#include<stdlib.h>
struct node {
	int info;
	struct node *link;
};
struct node *getnode(struct node *p){
	p = (struct node*) malloc (sizeof(struct node));
	return p;
}
int isempty(struct node *start){
	if(start == NULL)
		return 1;
	return 0;
}
struct node *insert_beg(struct node *start,int data);
struct node *insert_end(struct node *start,int data);
struct node *insert_after(struct node *start,int data,int item);
struct node *insert_before(struct node *start,int data,int item);
struct node *del_beg(struct node *start);
struct node *del_end(struct node *start);
struct node *del_after(struct node *start,int data);
struct node *del_before(struct node *start,int data);
struct node *del_item(struct node *start,int data);
struct node *create(struct node *start,int n);
struct node *reverse(struct node *start,int k);
struct node  *divide(struct node *start);
struct node  *mergesort(struct node *start);
struct node  *merge(struct node *start,struct node *start2);
void display(struct node *start);

int main(){
	struct node *start = NULL;
	int data,n;
	scanf("%d",&n);
	start = create(start,n);
	display(start);
	scanf("%d",&data);
	start = insert_after(start,data,4);
	display(start);
	start = insert_before(start,data,4);
	display(start);
	scanf("%d",&data);
	start = reverse(start,data);
	display(start);
	start = mergesort(start);
	/*start = del_after(start,4);
	display(start);
	start = del_before(start,4);
	display(start);
	start = del_beg(start);
	display(start);
	start = del_end(start);
	display(start);
	start = del_item(start,4);*/
	display(start);
	return 0;
}

struct node *create(struct node *start,int n){
	int i,data;
	start = NULL;
	if (n == 0)
		return start;
	scanf("%d",&data);
	start = insert_beg(start,data);
	for(i =2; i<= n; i++){
		scanf("%d",&data);
		start = insert_end(start,data);
	}
	return start;
}
struct node *insert_beg(struct node *start,int data){
	struct node *p ;
	p = getnode(p);
	p->info = data;
	p->link = start;
	start = p;
	return start;
}
struct node *insert_end(struct node *start,int data){
	if(isempty(start)){
		start = insert_beg(start,data);
		return start;
	}
	struct node *p, *q = start ;
	p = getnode(p);
	p->info = data;
	p->link = NULL;
	while(q ->link != NULL)	
		q= q->link;
	q->link = p;
	return start;
}
	
struct node *insert_after(struct node *start,int data,int item){
	struct node *p, *q = start ;
	p = getnode(p);
	p->info = data;
	p->link = NULL;
	while(q->link != NULL && q->info != item)
		q= q->link;
	if(q->link == NULL && q->info != item){
		printf("not found %d\n",item);
		return start;
	}
	p->link = q->link;
	q->link = p;
	return start;
}
struct node *insert_before(struct node *start,int data,int item){
	if(isempty(start)){
		printf("not found %d as list is empty\n",item);
		return start;
	}
	if(start->info == item){
		start = insert_beg(start,data);
		return start;
	}	
	struct node *p, *q = start ;
	p = getnode(p);
	p->info = data;
	p->link = NULL;
	while(q->link != NULL && q->link->info != item)
		q= q->link;
	if(q->link == NULL && q->info != item){
		printf("not found %d\n",item);
		return start;
	}
	p->link = q->link;
	q->link = p;
	return start;
}
struct node *del_beg(struct node *start){
	struct node *p = start,*temp;
	if(isempty(start)){
		printf("list is empty\n");
		return start;
	}
	start = start->link;
	free(p);
	return start;
}
struct node *del_end(struct node *start){
	struct node *p = start,*temp;
	if(isempty(start)){
		printf("list is empty\n");
		return start;
	}
	if(start->link == NULL){
		p = start;
		start = start->link;
		free(p);
		return start;
	}
	while( p->link->link != NULL)
		p = p->link;
	temp = p->link;
	p->link = p->link->link;
	free(temp);
	return start;
}
struct node *del_after(struct node *start,int data){
	struct node *p = start,*temp;
	if(isempty(start)){
		printf("list is empty\n");
		return start;
	}
	if(start->link == NULL){
		printf("one node only\n");
		return start;
	}
	while( p->link != NULL && p->info != data )
		p = p->link;
	if(p->link == NULL){
		printf("no element %d\n",data);
		return start;
	}
	temp = p->link;
	p->link = p->link->link;
	free(temp);
	return start;
}
struct node *del_before(struct node *start,int data){
	struct node *p = start,*temp;
	if(isempty(start)){
		printf("list is empty\n");
		return start;
	}
	if(start->link == NULL){
		printf("one node only\n");
		return start;
	}
	if(start->link->info == data){
		p = start;
		start = start->link;
		free(p);
		return start;
	}
	while( p->link->link != NULL && p->link->link->info != data )
		p = p->link;
	if(p->link->link == NULL){
		printf("no element %d\n",data);
		return start;
	}
	temp = p->link;
	p->link = p->link->link;
	free(temp);
	return start;
}
struct node *del_item(struct node *start,int data){
	struct node *p = start,*temp;
	if(isempty(start)){
		printf("list is empty\n");
		return start;
	}
	if(start->info == data){
		p = start;
		start = start->link;
		free(p);
		return start;
	}
	while( p->link != NULL && p->link->info != data )
		p = p->link;
	if(p->link == NULL){
		printf("no element %d\n",data);
		return start;
	}
	temp = p->link;
	p->link = p->link->link;
	free(temp);
	return start;
}
struct node *reverse(struct node *start,int k){
	struct node *ptr = start,*prev= NULL,*next;
	int i = 1;
	if(isempty(start))
		return start;
	while( ptr != NULL && i<=k){
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
		i++;
	}
	//start = prev;
	start->link = reverse(next,k);
	start = prev;
	return start;
}
void display(struct node *start){
	struct node *p = start;
	if(isempty(start)){
		printf("empty\n");
		return;
	}
	while(p->link != NULL){
		printf("%d -> ",p->info);
		p =p->link;
	}
	printf("%d\n",p->info);
}
struct node  *divide(struct node *start){
	struct node *p =start, *q = start;
	if(p == NULL || p->link == NULL){
		return start;
	}
	while(q->link != NULL){
		q=q->link;
		if(q->link != NULL){
			q = q->link;
			p = p->link;
		}
	}
	q = p->link;
	p->link = NULL;
	display(start);display(q);
	return q;
}
struct node  *mergesort(struct node *start){
	struct node *first = start,*second;
	if(start == NULL || start->link == NULL)
		return start;	
	second = divide(start);
	first = mergesort(first);
	second = mergesort(second);
	start = merge(first, second);
	return start;
}
struct node  *merge(struct node *start1, struct node *start2){	
	struct node *p = start1, *q = start2, *temp = p, *start_merge;
	//temp = (struct node*) malloc (sizeof(start1) * sizeof(start2));
	if(p == NULL)
		return q;
	if(q == NULL)
		return p;
	start_merge = temp;
	if(p->info < q->info){
		temp = p;
	//	p = p->link;
		temp->link = merge(p->link,q);
	}
	else {
		temp = q;
		//q = q->link;
		temp->link = merge(p,q->link);
	}
	return temp;
}
	/*if(p->info < q->info){
		temp = p;
		p = p->link;
	}
	else {
		temp = q;
		q = q->link;
	}
	start_merge = temp;
	while(p != NULL && q != NULL){
		if(p->info < q->info){
			temp->link = p;
			p = p->link;
			temp =temp->link;
		}
		else {
			temp->link = q;
			q = q->link;
			temp =temp->link;
		}
	}
	if( p != NULL){
		temp->link = p;
	}
	if( q != NULL){
		temp->link = q;
	}
	return start_merge;
}*/
