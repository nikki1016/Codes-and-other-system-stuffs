#include <stdio.h>
#include <stdlib.h>
struct set ;
struct node {
	int data;
	struct node *next;
	struct set *rep;
};
struct set {
	int rep;
	struct node *first;
	struct set *next;
};
struct set *getset(struct set *p,int data){
	p =(struct set *) malloc(sizeof(struct set));
	p->rep = data;
	p->next =NULL;
	p->first = NULL;
	return p;
}
struct node *getnode(struct node *p,int data,struct set *repp){
	p = (struct node *)malloc(sizeof(struct node));
	p->data = data;
	p->next = NULL;
	p->rep = repp;
	return p;
}
struct set *makeset(struct set *start,int data){
	struct set *tmp,*p= start;
	tmp = getset(tmp,data);
	struct node *q;
	q = getnode(q,data,tmp);
	tmp->first = q;
	if(start == NULL){
		start = tmp;
		return start;
	}
	while(p->next != NULL)
		p = p->next;
	p->next = tmp;
	return start;
}
struct set *find (struct set *start,int i){
	struct set *p = start ;
	struct node *q = p->first;
	while(p != NULL){
		q = p->first;
		while(q!= NULL){
			if(q->data == i)
				return p;
			q= q->next;
		}
		p = p->next;
	}
	return NULL;
}
int length(struct node *start){
	int c = 0;
	while(start != NULL){
		c++;
		start = start->next;
	}
	return c;
}
struct set *unionn(struct set *start,int i,int j){
	struct set *p , *q , *tmp = start,*ppp;
	p = find(start,i);
	q = find(start,j);
	if(p == NULL || q == NULL)
		return start;
	int a,b;
	a = length(p->first);
	b = length(q->first);
	if(a < b ){
		ppp = q;
		q = p;
		p =ppp;
	}
	struct node *qq = q->first, *pp = p->first ;
	while(qq != NULL){
		qq->rep = p;
		qq = qq->next;
	}
	while(pp ->next != NULL)
		pp = pp->next;
	pp->next = q->first;
	if(start == q){
		start = start->next;
	}
	else {
		while(tmp->next != NULL){
			if(tmp->next == q){
				tmp->next = q->next;
				free(q);
				break;
			}
			tmp = tmp->next;
		}
	}
	return start;
}

void display(struct set *start){
	struct set *p = start;
	struct node *q = start->first;
	while(p!= NULL){
		q= p->first;
		while(q != NULL){
			printf("%d - ",q->data);
			q = q->next;
		}
		printf("\n");
		p = p->next;
	}
	printf("\n");
}
int main(){
	struct set *start = NULL;
	int data,n,i,j;
	scanf("%d",&n);
	for(i =0; i<n; i++){
		scanf("%d",&data);
		start = makeset(start,data);
	}
	while(1){
		scanf("%d%d",&i,&j);
		if(i == -1 || j == -1)
			break;
		start = unionn(start,i,j);
		display(start);

	}
	return 0;
}

