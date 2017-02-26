#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int info;
	struct node *next;
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
struct node *reverse(struct node *start);
struct node *reverse_k(struct node *start,int k);
struct node  *divide(struct node *start);
struct node  *mergesort(struct node *start);
struct node  *merge(struct node *start,struct node *start2);
void *print(struct node *start,int k);
void display(struct node *start);
void display_rev(struct node *start);

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
	start = reverse(start);
	start = reverse(start);
	display(start);
	scanf("%d",&data);
	print(start,data);
	printf("\n");
	display(start);
	//start = mergesort(start);
	/*start = del_after(start,4);
	display(start);
	start = del_before(struct node *print(struct node *start,int k);start,4);
	display(start);
	start = del_beg(start);
	display(start);
	start = del_end(start);
	display(start);
	start = del_item(start,4);*/
	display_rev(start);
	return 0;
}

struct node *insert_beg(struct node *start,int data){
	struct node *temp;
	temp = getnode(temp);
	temp->prev = NULL;
	temp->info =data;
	temp->next = start;
	start = temp;
	return start;
}
struct node *insert_end(struct node *start,int data){
	struct node *temp,*p=start;
	if(isempty(start)){
		start = insert_beg(start,data);
		return start;
	}
	temp = getnode(temp);
	temp->prev = NULL;
	temp->info =data;
	temp->next = NULL;
	while(p->next != NULL){
		p = p->next;
	}
	temp->prev = p;
	temp->next = p->next;
	p->next = temp;
	return start;
}
struct node *insert_after(struct node *start,int data,int item){
	struct node *temp,*p=start;
	if(isempty(start)){
		printf("empty\n");
		return start;
	}
	temp = getnode(temp);
	temp->prev = NULL;
	temp->info =data;
	temp->next = NULL;
	while(p->next != NULL && p->info != item){
		p = p->next;
	}
	temp->prev = p;
	temp->next = p->next;
	p->next = temp;
	return start;
}
struct node *insert_before(struct node *start,int data,int item){
	struct node *temp,*p=start;
	if(isempty(start)){
		printf("empty\n");
		return start;
	}
	if(start->info == item){
		start = insert_beg(start,data);
		return start;
	}
	temp = getnode(temp);
	temp->prev = NULL;
	temp->info =data;
	temp->next = NULL;
	while(p->next != NULL && p->info != item){
		p = p->next;
	}
	p = p->prev;
	temp->prev = p;
	temp->next = p->next;
	p->next = temp;
	return start;
}
struct node *del_beg(struct node *start){
	struct node *p = start;
	if(isempty(start)){
		printf("empty\n");
		return start;
	}
	start = start->next;
	start->prev = p->prev;
	free(p);
	return start;
}
struct node *del_end(struct node *start){
	struct node *p = start,*temp;
	if(isempty(start)){
		printf("empty\n");
		return start;
	}
	if(start->next == NULL){
		start = start->next;
		start->prev = p->prev;
		free(p);
		return start;
	}
	while(p->next != NULL)
		p = p->next;
	temp = p;
	p = p->prev;
	p->next = temp->next;
	free(temp);
	return start;
}
struct node *del_after(struct node *start,int data){
	struct node *p = start, *temp;
	if(isempty(start)){
		printf("empty\n");
		return start;
	}
	if(start->next == NULL){
		start = start->next;
		start->prev = p->prev;
		free(p);
		return start;
	}
	while(p->next != NULL && p->info != data)
		p = p->next;
	if(p->next == NULL){
		printf("no element\n");
		return start;
	}
	temp = p->next;
	p->next = temp->next;
	p->next->prev = p;
	free(temp);
	return start;
}
struct node *del_before(struct node *start,int data){
	struct node *p = start,*temp;
	if(isempty(start)){
		printf("empty\n");
		return start;
	}
	if(start->next->info == data){
		start = start->next;
		start->prev = p->prev;
		free(p);
		return start;
	}
	while(p->next != NULL && p->info != data)
		p = p->next;
	if(p->next == NULL && p->info != data){
		printf("no element\n");
		return start;
	}
	temp = p->prev;
	p = p->prev->prev;
	p->next = temp->next;
	p->next->prev = p;
	free(temp);
	return start;
}
struct node *del_item(struct node *start,int data){
	struct node *p = start,*temp;
	if(isempty(start)){
		printf("empty\n");
		return start;
	}
	if(start->info == data){
		start = start->next;
		start->prev = p->prev;
		free(p);
		return start;
	}
	while(p->next != NULL && p->info != data)
		p = p->next;
	if(p->next == NULL && p->info != data){
		printf("no element\n");
		return start;
	}
	temp = p;
	p = p->prev;
	p->next = temp->next;
	p->next->prev = p;
	free(temp);
	return start;
}
struct node *create(struct node *start,int n){
	struct node *temp;
	temp = getnode(temp);
	int data,i;
	if(n ==0)
		return start;
	scanf("%d",&data);
	start = insert_beg(start,data);
	for(i = 2; i <= n; i++){
		scanf("%d",&data);
		start = insert_end(start,data);
	}
	return start;
}
struct node *reverse(struct node *start){
	struct node *ptr = start,*pv= NULL,*nt;
	if(isempty(start))
		return start;
	while( ptr != NULL){
		nt = ptr->next;
		ptr->next = pv;
		ptr->prev = nt;
		pv = ptr;
		ptr = nt;
	}
	start = pv;
	return start;
}
struct node *reverse_k(struct node *start,int k){
	struct node *ptr = start,*pv= NULL,*nt;
	int i = 1;
	if(isempty(start))
		return start;
	while( ptr != NULL && i<=k){
		nt = ptr->next;
		ptr->next = pv;
		ptr->prev = nt;
		pv = ptr;
		ptr = nt;
		i++;
	}
	start->next = reverse_k(nt,k);
	start = pv;
	return start;
}
struct node  *divide(struct node *start);
struct node  *mergesort(struct node *start);
struct node  *merge(struct node *start,struct node *start2);
void display(struct node *start){
	struct node *p = start;
	if(isempty(start)){
		printf("empty\n");
		return;
	}
	while(p->next != NULL){
		printf("%d -> ",p->info);
		p =p->next;
	}
	printf("%d\n",p->info);
}
void display_rev(struct node *start){
	struct node *p = start;
	if(isempty(start)){
		printf("empty\n");
		return;
	}
	while(p->next != NULL){
		p =p->next;
	}
	while(p->prev != NULL){
		printf("%d -> ",p->info);
		p = p->prev;
	}
	printf("%d\n",p->info);
}
void *print(struct node *start,int k){
	struct node *p = start;
	if(isempty(start) || k ==0 || k == 1){
		printf("empty\n");
		return start;
	}
	int i = 1;
	while(i <= k){
		while(p->next != NULL){
			printf("%d -> ",p->info);
			p = p->next;
			i++;
			if( i > k) return;
		}
		printf("%d -> ",p->info);
		p =p->prev;
		while(p->prev != NULL ){
			printf("%d -> ", p->info);
			p = p->prev;
			i++;
			if( i >= k) return;
		}
		printf("%d -> ",p->info);
		p = p->next;
	}
}
