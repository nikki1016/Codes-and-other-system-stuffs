#include<stdio.h>
#include<stdlib.h>
struct edge {
	int x,y,w;
	struct edge *next;
};

struct edge* sort(struct edge *head) {

   int i, j, k, tempx, tempData;
   struct edge *current = head;
   struct edge *nxt;
	
   while(current){
      	nxt = current->next;	
	while(nxt){	
        	if ( current->w > nxt->w ) {
		    	tempx = current->x;
		    	current->x = nxt->x;
		    	nxt->x = tempx;
		   	tempx = current->y;
		    	current->y = nxt->y;
		    	nxt->y = tempx;
			tempx = current->w;
		    	current->w = nxt->w;
		    	nxt->w = tempx;
         	}
         	nxt = nxt->next;
      	}
      	current = current->next;
   } 
   return head;  
}
void makeset(int  set[],int n){
	int i;
	for(i =0; i<n; i++){
		set[i]= i;
	}
}
void union_set(int  set[],int n,int u,int v){
	int i = v;
	while( i != set[i] && i < n){
		//printf("union i %d parent %d\n",i,set[i]);
		i = set[i];
	}
	set[i] = u;
}
int find( int  set[],int n,int u){
	int i = u;
	while( i != set[i] && i <n){
		//printf("i %d parent %d\n",i,set[i]);
		i = set[i];
	}
	return i;
}
		
struct edge *del(struct edge *root,int x,int y){
	struct edge * q = root,*p;
	if(root == NULL)
		return root;
	if((root->x == x && root->y == y)){
		p = root;
		root = root->next;
		free(p);
		return root;
	}
	while(q->next && q->next->x != x && q->next->y != y){
		q = q->next;
	}
	if(q->next && q->next->x == x && q->next->y == y){
		p = q->next;
		q->next = p->next;
		free(p);
	}
	return root;
}
struct edge *insertend(struct edge *root,int u,int v,int w){
	struct edge *q = root;
	struct edge * p = (struct edge *)malloc(sizeof(struct edge));
	p->x =u;
	p->y =v;
	p->w = w;
	p->next = NULL;
	if(root == NULL){
		root = p;
		return root;
	}
	while(q->next)
		q = q->next;
	q->next = p;
	return root;
}


struct edge * krushkal_mst(struct edge * root,int n){
	if(root == NULL) return root;
	root = sort(root);
	int  disjoint_set[n];
	int i,u,v,w;
	makeset(disjoint_set,n);
	struct edge * tree = NULL,*q= root;
	int d=0;
	while(q->next){
		//printf("x %d, y %d, w %d\n",q->x,q->y,q->w);
		q = q->next;
		d++;
	}
	//printf("x %d, y %d, w %d\n",q->x,q->y,q->w);
	d++;
	q = root;
	while(d--){
		u = q->x;
		v = q->y;
		w = q->w;
		int a = find( disjoint_set,n,u);
		int b = find( disjoint_set,n,v);
		//printf("find %d - %d  %d - %d\n",u,a,v,b);
		if(a != b ){
			struct edge * p = (struct edge *)malloc(sizeof(struct edge));
			p->x = u;
			p->y = v;
			p->w = w;
			p->next = tree;
			tree = p;
			union_set(disjoint_set,n,u,v);
			//printf("union %d - %d  %d - %d\n",u,a,v,b);
		}
		q= q->next;
		//free(q);
	}
	return tree;
}

struct edge * krushkal_mst2(struct edge * root,int n){
	int i,u,v,w,min = 99999;
	struct edge * tree = krushkal_mst(root,n),*q,*t,*p;
	p = tree;
	int d = 0;
	while(tree ){
		//root = del(root,tree->x,tree->y);
		//printf("delete   %d -> %d : %d\n",tree->x,tree->y,tree->w);
		struct edge * pp=NULL,*qq = root,*tt;
		while(qq ){
			struct edge * rr = (struct edge *)malloc(sizeof(struct edge));
			if(qq->x == tree->x && qq->y == tree->y && qq->w == tree->w)    {
			       qq =qq->next;
				continue;
			}
			rr->x = qq->x;
			rr->y = qq->y;
			rr->w = qq->w;
			rr->next = pp;
			pp = rr;
			qq= qq->next;
		}
		tt = pp  ;
		/*while(tt ){
			printf("rootdel  %d -> %d : %d\n",tt->x,tt->y,tt->w);
			tt= tt->next;
		}*/
			
		q = krushkal_mst(pp,n);
		p = q;
		int d = 0;
		while(p ){
			d += p->w;
			//printf("%d -> %d : %d\n",p->x,p->y,p->w);
			p= p->next;
		}
		//printf("d  %d \n",d);
		if(min > d){
			min = d;
			t = q;
		}
		tree = tree->next;
	}
		
	return t;
}

int main(){
	int **adj;
	
	int n,k,i,j,w,s,t,temp;
	scanf("%d",&n);
	adj = (int **)calloc(n,sizeof(int *));
	for(i=0;i<n;i++)
    	{
      		adj[i] = (int *)calloc(n,sizeof(int));
    	}
	struct edge * root = NULL,*p,*tree1,*tree2 ;
	scanf("%d%d%d",&i,&j,&k);
	while(i!=-1)
	{
	      	adj[i][j]=k;
		adj[j][i] = k;
		struct edge *q = (struct edge *)malloc(sizeof(struct edge));
		q->x = i;
		q->y = j;
		q->w = k;
		q->next= root;
		root = q;
	      	scanf("%d%d%d",&i,&j,&k);
		//printf("i\n");
	}

	tree1 = krushkal_mst(root,n);
	p = tree1;
	int d = 0;
	while(p ){
		d += p->w;
		printf("mst 1   %d -> %d : %d\n",p->x,p->y,p->w);
		p= p->next;
	}
	printf("%d\n",d);
	/*p = root;
	d = 0;
	while(p ){
		d += p->w;
		printf("root  %d -> %d : %d\n",p->x,p->y,p->w);
		p= p->next;
	}*/
	tree2 = krushkal_mst2(root,n);
	p = tree2;
	d = 0;
	while(p ){
		d += p->w;
		printf("mst 2  %d -> %d : %d\n",p->x,p->y,p->w);
		p= p->next;
	}
	printf("%d\n",d);
	
	return 0;
}
