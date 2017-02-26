#include<stdio.h>
#include<stdlib.h>
#define undir 0
#define dir 1
struct edge;
struct vertex{
	int n;
	struct edge *sr;
	struct vertex *next;
};
struct edge{
	struct vertex *des;
	struct edge *next;
};
struct vertex * ins_ver(struct vertex *start,int *v,int i);
struct vertex * ins_edge(struct vertex *start,int v,int i,int j);
struct vertex * del_ver(struct vertex *start,int *v,int n,int d_un);
struct vertex * del_edge(struct vertex *start,int u,int v,int d_un);
struct vertex * creategraph(struct vertex *start,int v,int d_un);
struct vertex *search(struct vertex *start,int i);
void display(struct vertex *start);

int main(){
	struct vertex *graph = NULL;
	int v,i,j,e,d_un;
	scanf("%d%d",&v,&d_un);
	graph = creategraph(graph,v,d_un);
	display(graph);//printf("hi\n");
	graph = del_edge(graph,1,3,d_un);
	display(graph);
	graph = del_ver(graph,&v,2,d_un);
	display(graph);
	return 0;
}
struct vertex * creategraph(struct vertex *start,int v,int d_un){
	int i,j;
	struct vertex *tmp,*p,*ptr;
	struct edge *pp;
	for(i =0; i<v; i++){
		scanf("%d",&j);
		start = ins_ver(start,&v,j);
	}
		display(start);				//printf("hi ver\n");
	ptr = p;
	while(1){
		scanf("%d%d",&i,&j);
		if( search(start,i) != NULL && search(start,j) != NULL){
			start = ins_edge(start,v, i, j);						//printf("hi edge\n");
			if(d_un == 0)
				start = ins_edge(start,v,j,i);
		}
		else break;
	}
	return start;
}
struct vertex * ins_ver(struct vertex *start,int *v,int i){
	struct vertex *tmp,*p = start,*ptr = start;
	tmp = (struct vertex *)malloc(sizeof(struct vertex ));
	tmp->next = NULL;
	tmp->sr = NULL;
	tmp->n = i;
	if(start == NULL){
		tmp->next = start;
		start = tmp;
	}
	else if(start->n > i){
		tmp->next = start;
		start = tmp;
	}
	else{
		while(ptr->next != NULL ){
			if(ptr->next->n > i)
				break;
			ptr = ptr->next;
		}
		tmp->next = ptr->next;
		ptr->next = tmp;
	}
	return start;
}
struct vertex * ins_edge(struct vertex *start,int v,int i,int j){
	struct vertex *tmp,*ptr = start;
	struct edge *pp;
	if( search(start,i) != NULL && search(start,j) != NULL){
		pp = (struct edge *)malloc(sizeof(struct edge ));
		pp->next = NULL;
		while(ptr != NULL && ptr->n != i)
			ptr = ptr->next;
		pp->next = ptr->sr;
		ptr->sr = pp;
		ptr = start;
		while(ptr != NULL && ptr->n != j)
			ptr = ptr->next;
		pp->des = ptr;
	}
	return start;
}
struct vertex *search(struct vertex *start,int i){
	struct vertex *p = start;
	while(p != NULL){
		if(p->n == i){
			//printf("found %d",p->n);
			return p;
		}
		p = p->next;
	}
	return p;
}
struct vertex * del_ver(struct vertex *start,int *v,int i,int d_un){
	struct vertex *p ,*ptr = start;
	struct edge *pp,*tmp;
	p = search(start,i);
	if(p == NULL){
		printf("not exist %d vertex\n",i);
		return start;
	}
	p = start;
	while(p != NULL){
		start = del_edge(start,p->n,i,d_un);
		p = p->next;
	}
    p = search(start,i);
	if(p == start){
		start = p->next;	
	}
	else{
		while(ptr->next != p )
			ptr = ptr->next;
		ptr->next = p->next;
		free(p);
	}
	tmp = p->sr;
	while(tmp != NULL){
		//start = del_edge(start,n,tmp->des->n,d_un);
		//p = search(start,n);
		//tmp = p->sr;
		pp = tmp;
		tmp = tmp->next;
		free(pp);
	}
	(*v)--;
	return start;	
}
struct vertex * del_edge(struct vertex *start,int i,int j,int d_un){
	struct vertex *p1,*p2,*ptr = start;
	struct edge *pp,*tmp;
	p1 = search(start,i);
	p2 = search(start,j); 
	if(  p1 != NULL && p2 != NULL){
		pp = p1->sr;
if(pp != NULL){
		if(pp->des->n == j){
			p1->sr = pp->next;
			free(pp);
			return start;
		}
		while( pp->next != NULL){
			if(pp->next->des->n == j){
				tmp = pp->next;
				pp->next = tmp->next;
				free(tmp);
				break;
			}
			pp = pp->next;
		}
		if(pp->next == NULL){
			printf("not found %d to %d edge\n",i,j);
			return start;
		}
	}
		if(d_un == 0){
			pp = p2->sr;
	if(pp != NULL){		if(pp->des->n == j){
				p2->sr = pp->next;
				free(pp);
			}
			while( pp->next != NULL){
				if(pp->next->des->n == j)
					break;
				pp = pp->next;
			}
			if(pp->next == NULL){
				printf("not found %d to %d edge\n",i,j);
				return start;
			}
			tmp = pp->next;
			pp->next = tmp->next;
			free(tmp);
		}
	}
	}
	else 			printf("not exist %d to %d edge\n",i,j);
	return start;
}

void display (struct vertex *start){
	int i;
	struct vertex *p = start;
	struct edge *tmp ;
	while(p != NULL){
		printf("sr %d -- ",p->n);
		tmp = p->sr;
		while(tmp != NULL){
			printf("%d -> ",tmp->des->n);
			tmp= tmp->next;
		//		printf("hi\n",count(tmp));
		}
		printf("NULL\n");
		p = p->next;
	}
}
