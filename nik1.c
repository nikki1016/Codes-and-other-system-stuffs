#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node*link;
};
struct node*getnode(struct node*p){
	p = (struct node*)malloc(sizeof(struct node));
	return p;
}
struct node *ins_end(struct node *start,int data){
	struct node*temp,*p = start;
	temp = getnode(temp);
	temp->info = data;
	temp->link = NULL;
	while(p->link != NULL)
		p= p->link;
	p->link = temp;
	return start;
} 
struct node*create(struct node*start,int n){
	int data,i;
	printf("Enter the elements: ");
	scanf("%d",&data);
	struct node*temp;
	temp = getnode(temp);
	temp->info = data;
	temp->link = NULL;
	start = temp;
	for(i = 1; i<n ; i++){
		scanf("%d",&data);
		start = ins_end(start,data);
	}
	return start;
}
struct node *ins_beg(struct node *start,int data){
	struct node*temp;
	temp = getnode(temp);
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
} 

struct node *addafternode(struct node * start,int data,int pos){
	struct node*temp,*p = start;
	temp = getnode(temp);
	temp->info = data;
	temp->link = NULL;
	pos--;
	while(p->link != NULL && pos--)
		p= p->link;
	if(pos == 0 && p->link != NULL){
		temp->link =p->link;
		p->link = temp;
		return start;
	}
	if(pos == 0 && p->link == NULL){
		temp->link =p->link;
		p->link = temp;
		return start;
	}
	printf("%d pos does not exist\n",pos);
	return start;
}
struct node *addafter(struct node * start,int data,int item){
	struct node*temp,*p = start;
	temp = getnode(temp);
	temp->info = data;
	temp->link = NULL;
	if(start==NULL){
		printf("empty\n");
		return start;
	}
	while(p->link != NULL && p->info != item)
		p= p->link;
	if(p->info == item ){
		temp->link =p->link;
		p->link = temp;
		return start;
	}
	printf("%d element does not exist\n",item);
	return start;
}
struct node *addbefore(struct node * start,int data,int item){
	struct node*temp,*p = start;
	temp = getnode(temp);
	temp->info = data;
	temp->link = NULL;
	if(start==NULL){
		printf("empty\n");
		return start;
	}
	if(start->info == item){
		start = ins_beg(start,data);
		return start;
	}
	while(p->link != NULL && p->link->info != item)
		p= p->link;
	if(p->link->info == item ){
		temp->link =p->link;
		p->link = temp;
		return start;
	}
	printf("%d element does not exist\n",item);
	return start;
}
			 
struct node *addbeforenode(struct node * start,int data,int pos){
	struct node*temp,*p = start;
	temp = getnode(temp);
	temp->info = data;
	if(pos == 1){
		temp->link = start;
		start = temp;
		return start;
	}
	pos -= 2;
	while(p->link != NULL && pos>0){
		p= p->link;
		pos--;
	}
	if(pos == 0 && p->link != NULL){
		temp->link =p->link;
		p->link = temp;
		return start;
	}
	printf("%d pos does not exist\n",pos);
	return start;
}					 

struct node*del_beg(struct node*start){
	struct node *tmp = start;
	start = start->link;
	if(start != NULL){
		int i = tmp->info;
		printf("%d is deleted\n",i);
	}
	free(tmp);
	return start;	
}
struct node*del_end(struct node*start){
	struct node *temp = start;
	if(start == NULL){
		printf("empty\n");
		return start;
	}
	int i;
	if(start->link == NULL){
		i=start->info;
		printf("%d is deleted\n",i);
		free(start->link);
		start = NULL;
		return start;
	}
	while(temp->link->link != NULL){
		temp = temp->link;
	}
	i = temp->link->info;
	printf("%d is deleted\n",i);
	temp->link = temp->link->link;
	free(temp->link);
	return start;	
}
struct node*delete(struct node *start,int data){
	struct node *temp = start,*p;
	if(start == NULL){
		printf("empty\n");
		return start;
	}
	if(start->info == data){
		printf("%d is deleted\n",data);
		if(start->link == NULL ){
			free(start->link);
			start = NULL;	
		}
		start = start->link;
		return start;
	}
	while(temp->link->link != NULL && temp->link->info != data){
		temp = temp->link;
	}
	if(temp->link->info == data){
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
		printf("%d ->  ",p->info);
		p = p->link;
	}
	printf("NULL\n");
}
void count(struct node*start){
	if(start == NULL){
		printf("empty\n");
		return;
	}
	struct node*p = start;
	int c =0;
	while(p!=NULL){
		c++;
		p = p->link;
	}
	printf("%d\n is count",c);
}
struct node* insert_s(struct node* start,int data){
	struct node *p=start,*q;
	int t;
	if(start == NULL || start->info > data){
		start = ins_beg(start,data);
		return start;
	}
	while(p->link != NULL && p->info <= data)
		p = p->link;
	if(p->info > data && p != NULL){
		start = addbefore(start,data,p->info);
		return start;
	}
	if(p->link == NULL)
		start = ins_end(start,data);
	return start;
}
struct node* select_s_addr(struct node* start){
	struct node *p=start, *q = start->link , *p_prev=start, *q_prev=start->link, *temp=NULL;
	for(p = start ; p->link != NULL; p=p->link){
		 for ( q = p->link ; q !=NULL; q=q->link){
			if(p->info > q->info){
				if(p == start)
					start = q;
				temp = q->link;
				q->link = p->link;	
				p->link = temp;
				q_prev ->link = p;
				if(p != start)
					p_prev ->link = q;
				temp = p;
            			p=q; 
             			q =temp;
			}
			q_prev= q ;
		}
		p_prev = p;
	}
	return start;
}
struct node* bubble_s_addr(struct node* start){
	struct node *end,*p=start,*q=NULL,*prev,*temp;
	for(end = NULL; end!=start->link; end = p){
		prev = start;
		for(p = start, q=p->link; q != end; prev = p, p=p->link, q=q->link){
			if(p->info > q->info){
				if(p == start)
					start = q;
				else prev->link = q;
				p->link = q->link;
				q->link = p;
              temp = p;
             p=q; 
             q =temp;
			}
		}
	}
	return start;
}

struct node* insertion_s_addr(struct node* start){
	struct node *temp = NULL,*p=start; 
	while(p != NULL){
		if(temp == NULL)
			temp = ins_beg(temp,p->info);
		else {
			temp = insert_s(temp,p->info);
		}
		p=p->link;
	}
	start = temp;	
	return start;
}
struct node* concate(struct node* start1,struct node*start2){
	struct node *temp = start1;
	if(start1 ==NULL)
		return start2;
	if(start2 == NULL)
		return start1;
	while(temp->link != NULL)
		temp = temp->link;
	temp->link = start2;
	return start1;
}
struct node* mergesort_2(struct node* start1,struct node*start2){
	start1 = insertion_s_addr(start1);
	start2 = insertion_s_addr(start2);
	struct node *temp = NULL,*p=start1,*q = start2,*r = NULL; 
	while(p != NULL && q!= NULL){
		if(temp == NULL){
			if(p->info < q->info){
				temp = ins_beg(temp,p->info);
				p = p->link;
			}
			else{
				temp = ins_beg(temp,q->info);
				q = q->link;
			}
		}
		else {
			if(p->info < q->info){
				temp = ins_end(temp,p->info);
				p = p->link;
			}
			else if(p->info > q->info){
				temp = ins_end(temp,q->info);
				q = q->link;
			}
			else {
				temp = ins_end(temp,p->info);
				p = p->link;
				q = q->link;
			}	
		}
	}
	while(p != NULL){
		temp = ins_end(temp, p->info);
		p = p->link;
	}
	while(q != NULL){
		temp = ins_end(temp, q->info);
		q = q->link;
	}
	return temp;
}
struct node* reverse(struct node* start){
	struct node *ptr = start, *next, *prev = NULL;
	while(ptr != NULL){
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}
struct node* divide(struct node *start){
	struct node *second,*p=start,*q=start->link;
	while(q != NULL){
		q=q->link;
		if(q != NULL && q->link != NULL)
			q=q->link;
		else break;
		p = p->link;
	}
	second = p->link;
	p->link = NULL;
	return second;
}
struct node* merge(struct node* first,struct node *second){
	struct node *p = first ,*q = second,*merged = first,*start_mer;	
	if(first->info < second->info){
		start_mer = first;
		p = p->link;
	}
	else{
		start_mer = second;
		q = q->link ;
	}
	merged = start_mer;
	while( p!= NULL && q != NULL){
		if( p->info < q->info){
			merged->link = p;
			p = p->link;
		}
		else{
			merged->link = q;
			q = q->link;
		}
       merged = merged -> link;
	}
	if(p != NULL)
		merged->link = p;
	else 
		merged->link = q;
	return start_mer;
}        
struct node* mergesort_1(struct node* start){
	struct node *first = start,*second ; 
	second = divide(start);
	first = mergesort_1(first);
	second = mergesort_1(second);
	start = merge(first,second);
	return start;
}

int main(){
	int choice, data, i,n,pos,max = -1,min = -1;
	struct node *start = NULL,*start2 = NULL,*start3 = NULL;
	printf("1. Create 1st\n");
		printf("2. Create 2nd\n3. Add at beg / Add to empty list.\n");
		printf("4. Add at end.\n");
		printf("5. Concate.\n");
		printf("6. merge the two lists.\n");
		printf("7. Add after node.\n");
		printf("8. Add before node.\n");
		printf("9..\n");
		printf("10. Delete.\n");
		printf("11.del_beg\n");
		printf("12. del_end\n13.addafter\n14.insert_sort\n15.mergesort\n18.selectsort_address\n19.bubblesort_address\n20.insertionsort_address\n21.reverse\n22.\n26.exit\n");
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
			case 2 :printf("Enter the no of elements: ");
					scanf("%d",&n);
					start2 = NULL;
					start2 = create(start2,n);
					break;
			case 3 : printf("Enter the element to be inserted at beg: ");
					 scanf("%d", &data);
					 start = ins_beg(start, data);
					 break;
			case 4 : printf("Enter the element to be inserted at end: ");
					 scanf("%d", &data);
					 start = ins_end(start, data);
					 break;
			case 5 : start = concate(start,start2);
					 break;
			case 6 : start3 = mergesort_2(start,start2);
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
			case 9 : start = mergesort_1(start);
					display(start);
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
			case 14 : printf("Enter the element to be inserted : ");
					 scanf("%d", &data);
					 start=insert_s(start,data);
					  break;
			case 15 : display(start);
					  break;
			case 16 : display(start2);
					  break;
			case 17 : display(start3);
					  break;
			
			case 18 : start=select_s_addr(start);
					  break;
			case 19 : start=bubble_s_addr(start);
					  break;
			case 20 : start = insertion_s_addr(start);
					  break;
			case 21 : start = reverse(start);
					  break;
			
			default : printf("Wrong choice\n");
			exit(0);
		}
	}
	return 0;
}

