#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int info;
	struct node *next;
};
struct node*getnode(struct node*p){
	p = (struct node*)malloc(sizeof(struct node));
	return p;
}
struct node *ins_beg(struct node *start,int data);
struct node *ins_end(struct node *start,int data);
struct node*create(struct node*start,int n);
struct node *addafternode(struct node * start,int data,int pos);
struct node *addafter(struct node * start,int data,int item);
struct node *addbefore(struct node * start,int data,int item);			 
struct node *addbeforenode(struct node * start,int data,int pos);			 
struct node *addatpos(struct node * start,int data,int pos);	
struct node*del_beg(struct node*start);
struct node*del_end(struct node*start);
struct node*delete(struct node *start,int data);
int search(struct node *start,int data);
void display(struct node*start);
int count(struct node*start);
int min(struct node*start);
int max(struct node*start);
struct node* insert_s(struct node* start,int data);
struct node* select_s_data(struct node* start);
struct node* reverse(struct node* start);
void copy(struct node* start);
int main(){
	int choice, data, i,n,pos,maximum, minimum;
	struct node *start = NULL,*start1= NULL;
	printf("1. Create\n");
		printf("2. Display\n3. Add at beg / Add to empty list.\n");
		printf("4. Add at end.\n");
		printf("5. Count.\n");
		printf("6. Search.\n");
		printf("7. Add after node.\n");
		printf("8. Add before node.\n");
		printf("9. Add at pos.\n");
		printf("10. Delete.\n");
		printf("11.del_beg\n12.del_end\n13.addafter\n14.max_min\n15.reverse\n16.copy\n");
	while (1)
	{
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : 
					printf("Enter the no of elements: ");
					scanf("%d",&n);
					start = NULL;
					start = create(start,n);
					break;
			case 2 : display(start);
					 break;
			case 3 : printf("Enter the element to be inserted at beg: ");
					 scanf("%d", &data);
					 start = ins_beg(start, data);
					 break;
			case 4 : printf("Enter the element to be inserted at end: ");
					 scanf("%d", &data);
					 start = ins_end(start, data);
					 break;
			case 5 : data = count(start);
					printf("%d \n",data);
					 break;
			case 6 : printf("Enter the element to search: ");
					 scanf("%d", &data);
					 n = search(start, data);
					 break;
			case 7 : printf("Enter the element to be inserted : ");
					 scanf("%d", &data);
					 printf("Enter the position after which to insert the element : ");
					 scanf("%d", &pos);
					 start = addafternode(start, data, pos);
					 break;
			case 8 : printf("Enter the element to be inserted : ");
					 scanf("%d", &data);
					 printf("Enter the position before which to insert the element : ");
					 scanf("%d", &pos);
					 start = addbeforenode(start, data, pos);
					 break;
			case 9 : printf("Enter the element to be inserted : ");
					 scanf("%d", &data);
					 printf("Enter the position at which to insert the element : ");
					 scanf("%d", &pos);
					 start = addatpos(start, data, pos);
					 break;
			case 10 : printf("Enter the element to be deleted : ");
					  scanf("%d", &data);
					  start = delete(start, data);
					  break;
			case 11 : start = del_beg(start);
					  break;
			case 12 : start=del_end(start);
					  break;
			case 13 : printf("Enter the element to be inserted : ");
					 scanf("%d", &data);
					 printf("Enter the item after which to insert the element : ");
					 scanf("%d", &pos);
					 start = addafter(start, data, pos);
					 break;
			case 14 : minimum = min(start);
				  maximum = max (start);
				  printf("%d n %d r max n min in list\n",minimum,maximum);
				  break;
			case 15 : start = reverse(start);
				  display (start);
				  break;
			case 16 : copy(start);

				  break;
			default : printf("Wrong choice\n");
				  exit(0);
		}
	}
	return 0;
}
struct node *ins_beg(struct node *start,int data){
	struct node *p;
	p = getnode(p);
	p->info = data;
	p->prev = NULL;	
	p->next = start;
	if(start != NULL)
		p->next->prev = p;
	start = p;
	return start;
}	
struct node *ins_end(struct node *start,int data){
	struct node *p = start,*temp;
	temp = getnode(temp);
	temp->info = data;
	if(p == NULL){
		start = ins_beg(start,data);
		return start;
	}	
	while(p->next != NULL){
		p = p->next;
	}
	temp->next = p->next;
	p->next = temp;
	temp->prev = p;
	return start;
}
struct node*create(struct node*start,int n){
	int i,data;
	if(n == 0)
		return start;
	scanf("%d",&data);
	start = ins_beg(start,data);
	for(i =2; i <= n; i++){
		scanf("%d",&data);
		start = ins_end(start,data);
	}
	return start;
}
struct node *addafternode(struct node * start,int data,int pos){
	struct node *p = start,*temp;
	temp = getnode(temp);
	temp->info = data;
	int i=1,c;
	c = count(start);
	if(p == NULL || pos>c){
		printf("position doesnt exist\n");
		return start;
	}
	if(c==pos){
		start = ins_end(start,data);
		return start;
	}
	while(p->next != NULL && i <pos){
		p = p->next;
		i++;
	}
	if(p->next != NULL && i < pos){
		temp->next = p->next;
		p->next = temp;
		temp->prev = p;
		temp->next->prev = temp;
		return start;
	}
	return start;
}

struct node *addafter(struct node * start,int data,int item){
	struct node *p = start,*temp;
	temp = getnode(temp);
	temp->info = data;
	if(p == NULL){
		printf("position doesnt exist\n");
		return start;
	}
	while(p->next != NULL && p->info != item){
		p = p->next;
	}
	if(p->next == NULL && p->info != item){
		printf("position doesnt exist\n");
		return start;
	}
	temp->next = p->next;
	p->next = temp;
	temp->prev = p;
	if(temp->next != NULL)
		temp->next->prev = temp;
	return start;
}
struct node *addbefore(struct node * start,int data,int item){
	struct node *p = start,*temp;
	temp = getnode(temp);
	temp->info = data;
	if(p == NULL){
		printf("position doesnt exist\n");
		return start;
	}
	if(p == start && p->info == item){
		start = ins_beg(start,data);
		return start;
	}
	while(p != NULL && p->info != item){
		p = p->next;
	}
	p = p->prev;
	temp->next = p->next;
	p->next = temp;
	temp->prev = p;
	temp->next->prev = temp;
	return start;
}	 
struct node *addbeforenode(struct node * start,int data,int pos){
	struct node *p = start,*temp;
	temp = getnode(temp);
	temp->info = data;
	int i =1;
	if(p == NULL){
		printf("position doesnt exist\n");
		return start;
	}
	if( pos == 1){
		start = ins_beg(start,data);
		return start;
	}
	while(p != NULL && i<pos ){
		p = p->next;
		i++;
	}
	p = p->prev;
	temp->next = p->next;
	p->next = temp;
	temp->prev = p;
	temp->next->prev = temp;
	return start;
}
struct node *addatpos(struct node * start,int data,int pos){
	struct node *p = start,*temp;
	temp = getnode(temp);
	temp->info = data;
	int i=1;
	if(p == NULL){
		printf("position doesnt exist\n");
		return start;
	}
	if( pos == 1){
		start = ins_beg(start,data);
		return start;
	}
	while(p != NULL && i < pos-1){
		p = p->next;
		i++;
	}
	temp->next = p->next;
	p->next = temp;
	temp->prev = p;
	temp->next->prev = temp;
	return start;
}
	
struct node*del_beg(struct node*start){
	struct node *p =start;
	if(start == NULL){
		printf("no element\n");
		return start;
	}
	start = start->next;
	free(p);
	return start;
}
	
struct node*del_end(struct node*start){
	struct node *p =start, *temp;
	if(start == NULL){
		printf("no element\n");
		return start;
	}
	if(start->next == NULL){
		start = start->next;
		free(p);
		return start;
	}
	while(p->next != NULL){
		p = p->next;
	}
	temp = p;
	p = p->prev;
	p->next = temp->next;
	free(temp);
	return start;
}
	
struct node*delete(struct node *start,int data){
	struct node *p =start, *temp;
	if(start == NULL){
		printf("no element\n");
		return start;
	}
	if(start->next == NULL && start->info == data){
		start = start->next;
		free(p);
		return start;
	}
	while(p->next != NULL && p->info != data){
		p = p->next;
	}
	if(p->info == data){
		temp = p;
		p = p->prev;
		p->next = temp->next;
		free(temp);
		return start;
	}
	printf("not found %d to delete\n",data);
	return start;
}
int search(struct node *start,int data){
	if(start == NULL){
		printf("empty\n");
		return;
	}
	struct node*p = start;
	int pos = 1;
	while(p!=NULL && p->info != data ){
		p = p->next;
		pos++;
	}
	if(p->info == data)   return pos;
	else if(p == NULL){
		printf("not found\n");
		return -1;
	}
}
void display(struct node *start){
	if(start == NULL){
		printf("empty\n");
		return;
	}
	struct node *p = start;
	while(p != NULL){
		printf("%d ->  ",p->info);
		p = p->next;
	}
	printf("NULL\n");
}
int count(struct node*start){
	if(start == NULL){
		printf("empty\n");
		return;
	}
	struct node*p = start;
	int c =0;
	while(p!=NULL){
		c++;
		p = p->next;
	}
	return c;
}
int max(struct node*start){
	if(start == NULL){
		printf("empty\n");
		return;
	}
	struct node*p = start->next;
	int c = start->info;
	while(p!=NULL){
		if(c < p->info)  c = p->info;
		p = p->next;
	}
	return c;
}
int min(struct node*start){
	if(start == NULL){
		printf("empty\n");
		return;
	}
	struct node*p = start->next;
	int c = start->info;
	while(p!=NULL){
		if(c > p->info)  c = p->info;
		p = p->next;
	}
	return c;
}
void copy(struct node* start){
	struct node *p = start,*dup = NULL;
	while(p != NULL){
		dup = ins_end(dup, p->info);
		p = p->next;
	}
	display (dup);
}

struct node* reverse(struct node* start){
	struct node *ptr = start,*prv = NULL,*next;
	if(start == NULL || start->next == NULL)
		return start;
	while(ptr != NULL){
		next = ptr->next;
		ptr->next = prv;
		ptr->prev = next;		
		prv = ptr;
		ptr = next;
	}
	start = prv;
	return start;
}
