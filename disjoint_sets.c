#include <stdio.h>
#include <stdlib.h>
struct node {
		int info;
		struct node *next;
		struct set *rep;
	    };

struct set{				
		struct node *rep;
	 	struct set *next;
	   };

struct node *getnode (struct node *p,int data)
	{
		p = (struct node *)malloc(sizeof(struct node));
		p->info = data;
		p->next = NULL;
		p->rep = NULL;
		return p;
	}	
i
struct set *getset (struct set *p,struct node *repres)	
	{
		p = (struct set *)malloc(sizeof(struct set));
		p->rep = repres;
		p->next = NULL;
		return p;
	}
	
struct set *ins_set(struct set *start,struct set *p)
	{
		struct set *pp = start;
		if(start == NULL){
		start = p;
		return p;
	}
	while(pp->next != NULL)
		pp = pp->next;
	pp->next = p;
	return start;
	}

struct node *ins_node(struct node *start,struct node *p)
	{
		struct node *pp = start;
		if(start == NULL)
		{
		start = p;
		return start;
		}
	while(pp->next != NULL)
		pp = pp->next;
	pp->next = p;
	return start;
	}

struct set *makeset(struct set *start,int data)
	{
		struct set *p =start, *tmp;
		struct node *q;
		q = getnode(q,data);
		tmp = getset(tmp,q);
		q->rep = tmp;
		start = ins_set(start,tmp);
		return start;
	}

struct set *find(struct set *start,int data)
	{
		struct set *p = start;
		struct node *q = start->rep;
		while(p != NULL)
		{
			q= p->rep;
			while(q!= NULL)
			{
				if(q->info == data)
				return p;
				q = q->next;
			}
		p = p->next;
		}
	return NULL;
	}


int length (struct set *p)
	{
		struct node *q = p->rep;
		int c = 0;
		while(q != NULL){
		c++;
		q = q->next;
	}
	return c;
	}

struct set *unionv (struct set *start,int i,int j)
	{
		struct set *p,*q,*pp =start;
		struct node *tmp;
		int a,b;
		p = find(start,i);
		if(p == NULL)   return start;
		printf("%d  \n",p->rep->info);
		q = find(start,j);
		if(q == NULL)
		return start;
		printf("%d \n",q->rep->info);
		a = length(p);
		b = length(q);
		if(p == q)
		return start;
		if(a < b){
		pp = p;
		p = q;
		q = pp;
	}
	else 
	{
		if(q == start)
			start = start->next;
		else {
			pp = start;
			while(pp->next != NULL){
				if(pp->next == q)
					break;
				pp =pp->next;
			}
		}
		tmp = q->rep;
		while(tmp != NULL){
			tmp->rep = p;
			tmp = tmp->next;
		}
		p->rep = ins_node(p->rep,q->rep);
		pp->next = q->next;
		free(q);
	}
	return start;
}

void display(struct set *start){
	struct set *p = start;
	struct node *q = start->rep;
	while(p != NULL){
		q = p->rep;
		while( q!= NULL){
			printf("%d ->",q->info);
			q = q->next;
		}
		printf("\n");
		p = p->next;
	}
}

int main()
	{
		struct set *start = NULL;
		int data,n,i;
		scanf("%d",&n);
		for(i =0; i<n; i++)
		{
			scanf("%d",&data);
			start = makeset(start,data);
		}
			display(start);
			for(i =0; i<n-1;i++)
		{
			start = unionv(start,i+1, i+2);
			display(start);
		}
		return 0;
}

