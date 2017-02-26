#include<stdio.h>
#include<stdlib.h>
struct node {
	int src;
	int des;
	int weight;
};
struct list {
	struct list *next;
	int i;
	int j;
	int w;
};
void swap(int *i,int *j){
	int tmp;
	tmp = *i;
	*i = *j;
	*j = tmp;
}
struct list *insert(struct list *start,int i,int j,int w)
{
	struct list *p;
	p = (struct list *)malloc(sizeof(struct list));
	p->i = i;
	p->j = j;
	p->w= w;
	p->next = start;
	start = p;
	return start;	
}

void enque(struct node arr[],int i,int j,int w, int *top, int *rear)
{
	if(*top==-1)
		*top=0;
	(*rear)++;
	arr[*rear].src = i;
	arr[*rear].des = j;
	arr[*rear].weight = w;
}

void  deque(struct node arr[],int *i,int *j,int *w, int *top)
{
	(*i)=arr[*top].src;
	(*j) = arr[*top].des;
	(*w) = arr[*top].weight;
	(*top)++;
}

int find(struct node arr[],int n,int i){
	if(arr[i].src == i)
		return i;
	return find(arr,n,arr[i].src);
}
void unionn(struct node arr[],int n,int i,int j){
	int a,b;
	a = find(arr,n,i);
	b = find(arr,n,j);
	if(a != b){
		arr[a].src = b;
	}
}
void sort_inc(struct node arr[],int n)
{
	int i,j;
	for(i = 0; i<=n; i++){
		for(j = i+1; j<=n; j++){
			if(arr[i].weight > arr[j].weight){
				swap( &arr[i].weight , &arr[j].weight);
				swap( &arr[i].src , &arr[j].src);
				swap( &arr[i].des , &arr[j].des);
			} 
		}
	}
}
void sort_dec(struct node arr[],int n)
{
	int i,j;
	for(i = 0; i<=n; i++){
		for(j = i+1; j<=n; j++){
			if(arr[i].weight < arr[j].weight){
				swap( &arr[i].weight , &arr[j].weight);
				swap( &arr[i].src , &arr[j].src);
				swap( &arr[i].des , &arr[j].des);
			} 
		}
	}
}

void krushal(int adj[][100],int n)
{
	struct list *start = NULL,*p;
	int i,j,top = -1,rear = -1,w;
	struct node q[100],arr[100];
	for(i =1;i<=n;i++){
		arr[i].src = i;
		arr[i].des = 0;
		arr[i].weight = 0;
	}
	for(i =1; i<=n; i++){
		for(j = 1; j<=n; j++){
			if(adj[i][j] != 0)
				enque(q,i,j,adj[i][j],&top,&rear);
		}
	}
	printf("max or min mst ???? 1 or 0\n");
	scanf("%d",&j);
	if(j == 1)
		sort_dec(q,rear);
	else 
		sort_inc(q,rear);
//	printf("hiii\n");
	while(top != -1 && top != rear+1)
	{
		deque(q, &i, &j, &w, &top);
		if(find (arr,n,i) != find(arr,n,j)){
			unionn(arr,n,i,j);
			start = insert(start,i,j,w);
		}
	}
	p = start;
	while(p!= NULL){
		printf("%d--%d   ->  %d\n",p->i,p->j,p->w);
		p = p->next;
	}
}

void krushal_graph(int adj[][100],int n)
{
	struct list *start = NULL,*p;
	int i,j,top = -1,rear = -1,w;
	struct node q[100],arr[100];
	for(i =1;i<=n;i++){
		arr[i].src = i;
		arr[i].des = 0;
		arr[i].weight = 0;
	}
	for(i =1; i<=n; i++){
		for(j = 1; j<=n; j++){
			if(adj[i][j] != 0)
				enque(q,i,j,adj[i][j],&top,&rear);
		}
	}
	sort(q,rear);
//	printf("hiii\n");
	while(top != -1 && top != rear+1)
	{
		deque(q, &i, &j, &w, &top);
		if(find (arr,n,i) != find(arr,n,j)){
			unionn(arr,n,i,j);
			start = insert(start,i,j,w);
		}
	}
	for(i =1; i<=n; i++)
		for(j = 1; j<=n; j++)
			adj[i][j] = 0;
	p = start;
	while(p!= NULL){
		//printf("%d--%d   ->  %d\n",p->i,p->j,p->w);
		adj[p->i][p->j] = p->w;
		p = p->next;
	}
}


int main()
{
	int adj[100][100],i,j,n;
	scanf("%d",&n);
	for(i=1; i<=n; i++){
		for(j =1; j<=i; j++){
			scanf("%d",&adj[i][j]);
			adj[j][i] = adj[i][j];
		}
	}
	krushal_graph(adj,n);
	printf("\n");
	for(i =1; i<=n; i++)
	{
		for(j = 1; j<=n; j++)
			printf("%d ",adj[i][j]);
		printf("\n");
	}	
	return 0;
}
