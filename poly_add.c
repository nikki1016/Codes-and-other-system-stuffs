#include<stdio.h>
#include<stdlib.h>
struct node{
	int coef;
	int exp;
	struct node*link;
};
struct node*getnode(struct node*p);
struct node*create(struct node*start,int n);
struct node*delete(struct node *start,int data);
void display(struct node*start);
struct node* insert_s(struct node* start,int data,int ex);
struct node *poly_add(struct node *start1,struct node *start2);
struct node *poly_mult(struct node *start1,struct node *start2);
int main(){
	int choice, data, i,n,pos,max = -1,min = -1;
	struct node *start = NULL,*start1 = NULL,*start3 = NULL;
	printf("1. Create\n");
		printf("2. create 2nd\n3.display 1st\n4.Display 2nd\n5. delete\n ");
		printf("7. Add poly.\n8.mult poly\n");

	while (1)
	{
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : printf("Enter the no of elements: ");
					scanf("%d",&n);
					start = NULL;
					start = create(start,n);
					break;
			case 2 : printf("Enter the no of elements: ");
					scanf("%d",&n);
					start1 = NULL;
					start1 = create(start1,n);
					break;
			case 3: display(start);
					 break;	
			case 4: display(start1);
					break;				 		
			case 5 : printf("Enter the element to be deleted : ");
					  scanf("%d", &data);
					  start = delete(start, data);
					  break;
			case 6 : printf("Enter the element to be inserted : ");
					 scanf("%d", &data);
					 printf("Enter the exponent of the element : ");
					 scanf("%d", &pos);
					 start = insert_s(start, data, pos);
					 break;
			case 7 : start3 = poly_add(start,start1);
					display(start3);
					  break;
			case 8: start3 = poly_mult(start,start1);
					display(start3);
					break;
			default : printf("Wrong choice\n");
			exit(0);
		}
	}
	return 0;
}
struct node*getnode(struct node*p){
	p = (struct node*)malloc(sizeof(struct node));
	return p;
}

struct node*create(struct node*start,int n){
	int data,i,ex;
	if(n == 0)
		return start;
	printf("Enter the coef n exp: ");
	for(i = 1; i<=n ; i++){
		scanf("%d%d",&data,&ex);
		start = insert_s(start,data,ex);
	}
	return start;
}
struct node*delete(struct node *start,int data){
	struct node *temp = start,*p;
	if(start == NULL){
		printf("empty\n");
		return start;
	}
	if(start->coef == data){
		printf("%d is deleted\n",data);
		if(start->link == NULL ){
			free(start->link);
			start = NULL;	
		}
		start = start->link;
		return start;
	}
	while(temp->link->link != NULL && temp->link->coef != data){
		temp = temp->link;
	}
	if(temp->link->coef == data){
		p = temp->link;
		temp->link = p->link;
		free(p);
		return start;
	}
	printf("not found %d\n",data);
	return start;	
}
void display(struct node*start){
	if(start == NULL){
		printf("empty\n");
		return;
	}
	struct node*p = start;
	while(p !=NULL){
		printf("%dx ^ %d +  ",p->coef,p->exp);
		p = p->link;
	}
	printf("NULL\n");
}
 
struct node* insert_s(struct node* start,int data,int ex){
	struct node*temp,*p = start;
	int t;
	temp = getnode(temp);
	temp->coef = data;
	temp->exp =ex;
	temp->link = NULL;
	if(start == NULL || start->exp < ex){
		temp->link = start;
		start = temp;
		return start;
	}
	if(start->link == NULL && start->exp > ex){
		start->link = temp;
		return start;
	}
	if( start->exp==ex){
		start->coef = start->coef + data;
		return start;
	}
	while(p->link != NULL && p->link->exp >= ex)
		p = p->link;
	if(p->exp == ex ){
		p->coef = p->coef + data;
                return start;
        }
	temp->link = p->link;
	p->link = temp; 
	return start;
}


struct node *poly_add(struct node *start1,struct node *start2){
	struct node*temp,*p = start1, *q=start2, *start=NULL;
	int t;
	if(start1 == NULL )
		return start2;
	if(start2 == NULL )
		return start1;
	temp = getnode(temp);
	temp->link = NULL;
	start = temp;
	while(p != NULL && q != NULL){
		if(p->exp == q->exp){
			start = insert_s(start, q->coef + p->coef,p->exp);
			p = p->link;
			q = q->link;
		}
		else if(p->exp > q->exp ){
			start = insert_s(start,p->coef, p->exp);	
			p = p->link ;
		}
		else{
			start = insert_s(start,q->coef, q->exp);	
			q = q->link;
		}
	}
	while(p != NULL){
		start = insert_s(start,p->coef,p->exp);
		p = p->link;
	}
	while(q != NULL){
		start = insert_s(start, q->coef, q->exp);
		q = q->link;
	}
	return start;
}
struct node *poly_mult(struct node *start1,struct node *start2){
	struct node*temp,*p = start1, *q=start2, *start=NULL;
	int t;
	if(start1 == NULL )
		return start1;
	if(start2 == NULL )
		return start2;
	temp = getnode(temp);
	temp->link = NULL;
	start = temp;
	while(p != NULL ){
		q = start2;
		while(q != NULL){
			start = insert_s(start,p->coef*q->coef, p->exp + q->exp);
			q = q->link;
		}
		p = p->link;
	}
	return start;
}
