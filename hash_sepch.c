#include <stdio.h>
#include<stdlib.h>
struct node {
	int info;
	struct node *next;
};
struct link {
	int indx;
	struct link *next;
	struct node *index;
};

int count(struct link *tmp){
	int c = 0;
	struct node *p = tmp->index;
	while(p != NULL){
		c++;
		p = p->next;
	}
	return c;
}
int hash(int a);
void display (struct link *start){
	int i;
	struct link *p = start;
	struct node *tmp ;
	while(p != NULL){
		tmp = p->index;
		if(tmp != NULL){
			printf("%d   :  ",p->indx);
			while(tmp != NULL){
				printf("%d ->",tmp->info);
				tmp= tmp->next;
		//		printf("%d\n",count(tmp));
			}
			printf("\n");
		}
		p = p->next;
	}
}
struct  node *search_data(struct link *start,int data){
	struct link *ptr = start;
	struct node *p ;
	while(ptr!= NULL){
		p = ptr->index;		
		while(p != NULL){
			if(p->info == (data))
				return p;
			p = p->next;
		}
		ptr= ptr->next;
	}
	p = NULL;
	return p;
}
struct  link *search_index(struct link *start,int data){
	struct link *ptr = start;
	while(ptr!= NULL){
		if(ptr->indx == hash(data))
			return ptr;
		ptr= ptr->next;
	}
	return ptr;
}
struct link *insert (int letter, struct link *start){
	struct link *tmp,*ptr = start;
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p->info = letter;
	p->next = NULL;
	if(search_index(start,letter) == NULL){
		tmp = (struct link *)malloc(sizeof(struct link));
		tmp->indx = hash(letter);
		tmp->index = p;
		tmp->next = NULL;
		if(start == NULL){
			tmp->next = start;
			start = tmp;
		}
		else if(start->indx > hash(letter)){
			tmp->next = start;
			start = tmp;
		}
		else{
			while(ptr->next != NULL ){
				if(ptr->next->indx > hash(letter))
					break;
				ptr = ptr->next;
			}
			tmp->next = ptr->next;
			ptr->next = tmp;
		}
	}
	else{
		/*while(ptr != NULL ){
				if(ptr->index->info == letter)
					break;
				ptr = ptr->next;
			}*/
		ptr = search_index(start,letter);
		p->next = ptr->index;
		ptr->index = p;
	}
//	printf("hi\n");
	return start;
}

int hash(int  a){
	int i;
	i = a % 11;
	return i;
}
int main(){
	struct link *start = NULL;
	int  letter;
	int i,n,j,k;
	scanf("%d",&n);
	for(i =0; i<n; i++){
		scanf("%d",&letter);	
		//j = hash(letter);
		if(search_index(start,letter) == NULL)
			printf("hi\n");
		if(search_data(start,letter) == NULL )
			start = insert(letter, start);
	}
	display(start);
	return 0;
}
