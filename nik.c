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
struct node *ins_beg(struct node *start,int data){
	struct node*temp;
	temp = getnode(temp);
	temp->info = data;
	temp->link = start;
	start = temp;
	return start;
} 

struct node *ins_end(struct node *start,int data){
	struct node*temp,*p = start;
	temp = getnode(temp);
	temp->info = data;
	temp->link = NULL;
	if(start == NULL){
		start = ins_beg(start,data);
		return start;
	}
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
struct node *addatpos(struct node * start,int data,int pos){
	struct node*temp,*p = start,*q = NULL;
	temp = getnode(temp);
	temp->info = data;
	pos--;
	while(p->link != NULL && pos--){
		p= p->link;
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
	if(start == NULL){
		printf("empty\n");
		return start;
	}
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
int search(struct node *start,int data){
	struct node *temp = start;
	if(start == NULL){
		printf("empty\n");
		return 0;
	}
	int pos = 1;
	if(start->info == data){
		printf("%d is found at %d\n",data,pos);
		return pos;
	}
	while(temp->link != NULL && temp->info != data){
		temp = temp->link;
		pos++;
	}
	if(temp->info == data){
		printf("%d is found at %d\n",data,pos);
		return pos;
	}
	printf("not found %d\n",data);
	return -1;	
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
struct node* select_s_data(struct node* start){
	struct node *p=start,*q;
	int t;
	for(p=start; p->link != NULL; p=p->link){
		for(q=p->link; q!=NULL; q=q->link){
			if(p->info > q->info){
				t = p->info;
				p->info = q->info;
				q->info =t;
			}
		}
	}
	return start;
}
struct node* bubble_s_data(struct node* start){
	struct node *end,*p=start,*q=NULL;
	int t;
	for(end = NULL; end!=start->link; end = p){
		for(p=start,q=p->link; q != end; p=p->link, q=q->link){
			if(p->info > q->info){
				t = p->info;
				p->info = q->info;
				q->info =t;
			}
		}
	}
	return start;
}

struct node* insertion_s_data(struct node* start){
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
void kth_element(struct node *start,int k ){
	struct node *ptr = start;
	int i =0;
	if(start == NULL){
		printf("NULL\n");
		return;
	}
	printf("%d -> ",ptr->info);
	while(ptr != NULL && i < k){
		ptr = ptr->link;
		i++;
	}
	kth_element(ptr, k);
}
void max_min(struct node *start ){
	struct node *ptr = start;
	int max = -1,min=99999;
   if (start == NULL){
            printf("empty\n");
            return start;
    }
	while(ptr != NULL){
		if(ptr->info > max)
			max = ptr->info;
		if(ptr->info <min)
			min = ptr->info;
	}
	printf("%d is max & %d is min in list & their diff is %d\n",max,min,max-min);
}
struct node *del_dup_end(struct node *start){
	start = reverse(start);
	struct node *ptr = start,*q = start->link;
	while(ptr != NULL){
		q = ptr->link;
		while(q != NULL){
			if(ptr->info == q->info){
				start = delete(start,ptr->info);
			}
			q=q->link;
		}
		ptr = ptr->link;
	}
	start = reverse(start);
	return start;
}
struct node *del_alt_node(struct node *start){
	struct node *p = start;
	while(p->link != NULL){
		p = p->link;
		start = delete(start, p->info);
		p = p->link;
	}
	return start;
}
struct node* rev_k(struct node* start,int k){
	struct node *ptr = start, *next, *prev = NULL;
	int i=0;
	if(ptr == NULL)
		return ptr;
	while(ptr != NULL && i<k){
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
		i++;
	}
	start->link= rev_k(ptr,k);
    start = prev;
	return start;
}
struct node* right_grt(struct node* start){
	struct node *p = start, *next = start->link,*temp;
	while(p->link != NULL ) {
		if(p->info < next->info && p == start){
			temp = p;
			start = next;
			free(temp);
		}
		else if(p->info < next->info )
			start = delete(start, p->info);
		p=next;
		next = next->link;
	}
	return start;
}
void middle_item(struct node* start){
	if(start == NULL){
		printf("empty\n");
		return;
	}
	struct node*p = start,*q=start->link;
	while(q!=NULL){
		p = p->link;
		if(q->link == NULL)
			break;
		q=q->link->link;
		
	}
	printf("%d is middle element\n",p->info);
}
void palindrome(struct node*start){
	struct node *p = start,*copy = NULL;
	if(start == NULL){
		printf("empty\n");
		return;
	}
	while(p !=NULL){
		copy = ins_end(copy,p->info);
		p = p->link;
	}	
	p = start;
	while(copy != NULL){
		if(p->info != copy->info){
			printf("not palindrome\n");
			return;
		}
		p = p->link;
		copy = copy->link;
	}
	printf("palindrome\n");
} 

int main(){
	int choice, data, i,n,pos,max = -1,min = -1;
	struct node *start = NULL;
	printf("1. Create\n");
		printf("2. Display\n3. Add at beg / Add to empty list.\n");
		printf("4. Add at end.\n");
		printf("5. Count.\n");
		printf("6. Search.\n");
		printf("7. Add after node.\n");
		printf("8. Add before node.\n");
		printf("9. Add at pos.\n");
		printf("10. Delete.\n");
		printf("11.del_beg\n");
		printf("12. del_end\n13.addafter\n14.insert_sort\n15.selectsort_data\n16.bubblesort_data\n17.insertionsort_data\n18.selectsort_address\n19.bubblesort_address\n20.insertionsort_address\n21.reverse\n22.rev_k\n23.kth element\n24.max_min\n25.del_dup_end\n26.exit\n");
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
			case 5 : count(start);
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
			case 14 : printf("Enter the element to be inserted : ");
					 scanf("%d", &data);
					 start=insert_s(start,data);
					  break;
			case 15 : start=select_s_data(start);
					  break;
			case 16 : start=bubble_s_data(start);
					  break;
			case 17 : start = insertion_s_data(start);
					  break;
			case 18 : start=select_s_addr(start);
					  break;
			case 19 : start=bubble_s_addr(start);
					  break;
			case 20 : start = insertion_s_addr(start);
					  break;
			case 21 : start = reverse(start);
					  break;
			case 22 : scanf("%d", &data);
					  start = rev_k(start,data);
					  break;
			case 23 : scanf("%d", &data);
					 kth_element(start,data);
					  break;
			case 24 : max_min(start);
					  break;
			case 25 : start = del_dup_end(start);
					  break;
			case 26 : start = del_alt_node(start);
					  break;
			case 27 : start = right_grt(start);
					  break;
			case 28 : middle_item(start);
					  break;
			case 29 : palindrome(start);
					  break;
		//	case 30 : freq(start);
					//  break;
			default : printf("Wrong choice\n");
			exit(0);
		}
	}
	return 0;
}

