#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node* create(struct node *start);
struct node *delete(struct node *start,int data);
void max_min(struct node *start,int *max,int *min);
struct node *insert_end(struct node *start,int data);
struct node *merge(struct node* start,struct node *start2);
struct node* getnode(struct node*p);
void display (struct node *start);
struct node *kth(struct node *start,int k);
int main(){
	struct node *start = NULL,*start2= NULL;
	int max1,max2,min1,min2,k;
	start = create(start);
	//start2 = create(start2);
	max1 = min1 = start->info;
	//max2 = min2 = start2->info;
	 max_min(start,&max1,&min1);
	//max_min(start2,&max2,&min2);
	printf("%d n %d r max of these frt \n",max1,max2);
	display(start);
	//display(start2);
	//start = merge(start,start2);
	display(start);
	scanf("%d",&k);
	start = kth(start,k);
	//start = delete(start,start->link->link->info);
	//display(start);
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
	if(n == 0 ) return start;
	if(start == NULL){
		start = getnode(start);
		start->info = data;
		start->link = start;
	}
	for(i = 2; i<=n; i++ ){
		scanf("%d",&data);
		start = insert_end(start,data);
	}
	return start;
}
struct node *insert_end(struct node* start,int data){
	struct node *p = start,*q ;
	q = getnode(q);
	q->info = data;
	if(p->link == p){
		p->link = q;
		q->link = p;
		return start;
	}
	p = p->link;
	while(p->link != start){
		p = p->link;
	}
	p->link = q;
	q->link = start;
	return start;
}
struct node *delete(struct node *start,int data){
	struct node *p = start,*temp ;
	if(p->info == data){
		temp =p;
		while(p->link != start){
			p = p->link;
		}
		p ->link = temp->link;
		start = temp->link;
		free(temp);
	}
	while(p->link != start && p->link->info != data){
		p = p->link;
	}
	temp = p->link;
	p->link = p->link->link;
	free(temp);
	return start;
}
struct node *merge(struct node* start,struct node *start2){
	struct node *p = start,*q = start2, *temp = NULL,*temp2 = NULL ;
	if(p == NULL){
		return q;
	}
	if(q == NULL){
		return p;
	}
	int max1,max2,min1,min2;
	max1 = min1 = start->info;
	//max2 = min2 = start2->info;
	 max_min(start,&max1,&min1);
	//max_min(start2,&max2,&min2);
		printf("bbb  %d n %d r max of these \n",max1,max2);
	while(q->info != max2){
		q=q->link;
		if(q == start2) break;
	}
	if(p->info == max1 && q->info == max2){
		temp = p->link;
		p->link = q;
		q = q->link;
		while(q->link != start2){
			q = q->link;
		}
		q->link = temp;
		return start;
	}
	p = p->link;
	while(p->link != start && p->info != max1){
		p = p->link;
	}
	if(p->info == max1){		
		temp = p->link;
		p->link = q;
		while(q->link != start2){
			q = q->link;
		}
		q->link = temp;
		return start;
	}
}
struct node *kth(struct node *start,int k){
	struct node *p =start,*q;
	int i = 1;
	if(start == NULL){
		printf("empty\n");
		return start;
	}
	//printf("%d -> ",p->info);
	//p = p->link;
	while( 1){
		printf("%d -> ",p->info);
		i = 1;
		while( i<k){
			p = p->link;
			i++;
		}
		p = p->link;
		if(p == start) {
			printf("NULL\n");
			return start;
		}
	}
	return start;
}
void max_min(struct node *start, int *max,int *min){
	if(start == NULL){
		printf("empty\n");
		return;	
	}
	struct node *p = start;
	p = p->link;
	while(p != start){
		if (*max < p->info)
			*max = p->info;
		if (*min > p->info)
			*min = p->info;
		p = p->link;
	}
	//return max;
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
	while(p->link != start);
	printf("%d\n",p->info);
}

