#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node* link;
};
struct node *insert(struct node*,int data);
struct node *del(struct node *);
struct node *insertafter(struct node *,int data,int pos);
struct node *del_after(struct node *,int pos);
struct node *insertbefore(struct node *,int data,int after);
struct node *del_before(struct node *,int data);
struct node *reverse(struct node *);
void display(struct node *);
int main(){
	struct node *start = NULL;
	int i,choice,data,pos;
	printf("1.insert element\t2.insert after any element\t3.insert before any element\t4.delete last ele\t5.delete ele before any ele\t6.delete any ele after any ele\t7.reverse\t8.disply\t9.exit\n");
	while(1){
		printf("enter ur choice\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("enter data\n");
				scanf("%d",&data);
				start = insert(start,data);
				break;
			case 2:
				printf("enter data n ele after \n");
				scanf("%d",&data);
				scanf("%d",&pos);
				start = insertafter(start,data,pos);
				break;
			case 3:
				printf("enter data n ele before\n");
				scanf("%d",&data);
				scanf("%d",&pos);
				start = insertbefore(start,data,pos);
				break;
			case 4:
				start = del(start);
				break;
			case 5:
				printf("enter ele after\n");
				scanf("%d",&data);
				start = del_after(start,data);
				break;

			case 6:
				printf("enter ele before\n");
				scanf("%d",&data);
				start = del_before(start,data);
				break;
			case 7:
				start = reverse(start);
				display(start);
				break;
			case 8:
				display(start);
				break;
			default:
				exit(0);
		}
	}
	return 0;
}

struct node *insert(struct node* start,int data){
	struct node *tmp,*ptr = start;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = NULL;
	if(start == NULL){
		start = tmp;
		return start;
	}
	while(ptr->link !=NULL)
		ptr=ptr->link;
	ptr->link = tmp;
	return start;
}

struct node *del(struct node *start){
	struct node *tmp,*ptr = start;
	if(start == NULL){
		printf("no element to delete\n");
		return start;
	}
	while(ptr->link->link !=NULL)
		ptr=ptr->link;
	tmp = ptr->link;
	ptr->link=tmp->link;
	free(tmp);
	return start;	
}


struct node *insertafter(struct node *start,int data,int item){
	struct node *tmp,*ptr = start;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = NULL;
	if(start == NULL){
		printf("no element\n");
		return start;
	}
	while(ptr!=NULL && ptr->info != item)
		ptr=ptr->link;
	if(ptr->info == item){
		tmp->link = ptr->link;
		ptr->link = tmp;
	}
	else if(ptr == NULL)
		printf("not found %d ele\n",item);
	return start;
}
struct node *del_after(struct node *start,int item){
	struct node *tmp,*ptr = start;
	if(start == NULL){
		printf("no element to delete\n");
	}
	else if(start->info == item){
		tmp = start;
		start = start->link;
		free(tmp);
		return start;
	}
	while(ptr!=NULL && ptr->info != item)
		ptr=ptr->link;
	if(ptr->info == item){
		tmp = ptr->link;
		ptr->link = tmp->link;
		free(tmp);
	}
	else if(ptr == NULL)
		printf("not found %d ele to delete after it\n",item);
	return start;
}	


struct node *insertbefore(struct node *start,int data,int item){
	struct node *tmp,*ptr = start,*q;
	tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = data;
	tmp->link = NULL;
	if(start == NULL){
		printf("no element\n");
		return start;
	}
	else if(start->info == item){
		tmp->link=start;
		start = tmp;
		return start;
	}
	q=ptr->link;
	while(q!=NULL && q->info != item){
		ptr=ptr->link;
		q = q->link;
	}
	if(q->info == item){
		tmp->link = ptr->link;
		ptr->link = tmp;
		return start;
	}
	else if(q == NULL)
		printf("no %d ele to insert before\n",item);
	return start;	
}
struct node *del_before(struct node *start,int item){
	struct node *tmp,*ptr = start,*q;
	if(start == NULL){
		printf("no element to delete\n");
		return start;
	}
	else if(start->info == item){
		printf("not found %d ele to delete before it\n",item);
		return start;
	}
	else if(start->link->info == item){
		tmp = start;
		start=start->link;
		free(tmp);
		return start;
	}
	q=ptr->link->link;
	while(q!=NULL && q->info != item){
		q=q->link;
		ptr=ptr->link;
	}
	if(q->info == item){
		tmp = ptr->link;
		ptr->link = q;
		free(tmp);
	}
	else if(q == NULL)
		printf("not found %d ele to delete before it\n",item);
	return start;
}	

struct node *reverse(struct node *start){
	struct node *prev=NULL,*ptr=start,*next;
	if(start == NULL){
		printf("no element to reverse\n");
		return start;
	}
	else if(start->link == NULL){
		return start;
	}
	while(ptr !=NULL){
		next = ptr->link;
		ptr->link = prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;	
}
void display(struct node *start){
	struct node *ptr = start;
	if(start == NULL){
		printf("no element to display\n");
	}
	else{
		while(ptr!=NULL){
			printf("%d ",ptr->info);
			ptr=ptr->link;
		}
	}
	printf("\n");
}

