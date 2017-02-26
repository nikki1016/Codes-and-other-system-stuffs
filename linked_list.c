#include <stdio.h>
#include <stdlib.h>
struct node {
	int info;
	struct node *link;
};
struct node *insert (struct node **start,int data,char ch);
struct node *insert_specific (struct node **start,int data,int pos);
struct node *delete (struct node **start,char ch);
struct node *delete_specific (struct node **start,int pos);
void display (struct node *start);
void display_alter( struct node *start);
int main(){
	struct node *start = NULL;
	int n,item,pos;
	char ch;
	printf("create linked list\n");
	while(1){
		printf("1.insert 2.insert after pos 3.delete 4.delete the item 5.display the linked list 6.display the alternate elements\n");
		scanf("%d",&n);
		switch(n){
			case 1:
				printf("enter char n data\n");
				scanf("%d",&item);
				ch = getchar();
				ch = getchar();
				start = insert(&start,item,ch);
				break;
			case 2:
				printf("enter item n pos\n");
				scanf("%d%d",&item,&pos);
				start = insert_specific(&start, item,pos);
				break;
			case 3:
				printf("from where u want to delete b/e\n");
				ch = getchar();
				ch = getchar();
				start = delete(&start,ch);
				break;
			case 4:
				printf("enter pos at which element to be deleted\n");
				scanf("%d",&item);
				start = delete_specific(&start,item);
				break;
			case 5:
				display(start);
				break;
			case 6:
				display_alter(start);
				break;
			default:
				exit(0);
		}
	}
	return 0;
}

struct node *insert (struct node **start,int data,char ch){
	struct node *temp,*p = *start;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = NULL;
	if(*start == NULL){
		*start = temp;
		temp->link = NULL;
	}
	else if( ch == 'b' || ch == 'B'){
		temp->link = *start;
		*start = temp;
		printf("nik\n");
		
	}
	else if(ch == 'e' || ch == 'E'){
		while(p->link != NULL)
			p = p->link;
		p->link = temp;
	}
	return *start;
}
struct node *insert_specific (struct node **start,int data,int pos){
	struct node *temp,*p = *start;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->info = data;
	temp->link = NULL;
	int i = 2;
	if(*start == NULL){
	       printf("invalid list is empty\n");
	       
	}
	else if(pos == 1){
		temp->link = *start;
		*start = temp;
	
	}
	else {
		while(p != NULL && i<pos){
			p = p->link;
			i++;
		}
		if( p == NULL && i <pos){
			printf("invalid pos\n");
			
		}
		else {
			temp->link = p->link;
			p->link = temp;
			
		}
	}
	return *start;
}	
struct node *delete (struct node **start,char ch){
	struct node *p = *start,*temp;
	int item;
	if(start == NULL){
		printf("empty list\n");
	}
	else if( ch == 'b' || ch == 'B'){
		p = *start;
		item = p->info;
		printf("%d is deleted at %c\n",item,ch);
		*start = (*start)->link;
		free(p);
		
	}
	else if(ch == 'e' || ch == 'E'){
		while(p->link->link != NULL)
			p = p->link;
		temp = p->link;
		item = temp->info;
		p->link = p->link->link;
		printf("%d is deleted at %c\n",item,ch);
		free(temp);
	}
	return *start;
}
struct node *delete_specific (struct node **start,int pos){
	struct node *temp,*p = *start;
	int item,i=1;
	if(*start == NULL){
		printf("empty list\n");	
	}
	else if( pos ==1){
		p = *start;
		item = p->info;
		printf("%d is deleted at %d\n",item,pos);
		*start = (*start)->link;
		free(p);
	}
	else {
		while(p->link != NULL && i++<pos-1)
			p = p->link;
		if(p->link == NULL && i < pos){
			printf("no element at %d\n",pos);	
		}
		else{
			temp = p->link;
			p->link = temp->link;
			item = temp->info;
			printf("%d is deleted at %d\n",item,pos);
			free(temp);	
		}
	}
	return *start;
}
void display (struct node *start){
	struct node *p = start;
	if(start == NULL){
	       printf("list is empty\n");
	       return;
	}
	printf("list elements are:\n");
	while(p != NULL){
		printf("%d ",p->info);
		p = p->link;
	}
	printf("\n");
}	
	
	
void display_alter( struct node *start){
	struct node *p = start;
	if(start == NULL){
	       printf("list is empty\n");
	       return;
	}
	 printf("alternative list elements are:\n");
	while(p != NULL){
		printf("%d ",p->info);
		p = p->link->link;
	}
	printf("\n");
}	

