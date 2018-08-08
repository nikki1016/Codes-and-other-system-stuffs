# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
#define INF 99999
struct node {
	struct node *next;
	int str;
	int w;
};
struct table{
	struct node *next;
	int count;
};
void addedge(struct table arr[],int k,int w,int n)
{
	int i, j;
	struct node * p = (struct node *)malloc(sizeof(struct node)),*kk = arr[k].next;
	p->str = n;
	p->w = w;
	p->next = NULL;
	//while(kk->next)
	//	kk = kk->next;
	
	p->next = arr[k].next;
	arr[k].next = p;
	arr[k].count++;
		//printf("count j %d arr %lf--  ",arr[j].count,arr[j].next->str);	
}
void enqueue(int q[],int a,int* front,int *rear){
	if(*front == -1){
		*front = 0;
	}
	(*rear)++;
	q[*rear] = a;
}
int dequeue(int q[],int *f,int *r){
	if(*f == -1){
		return -1;
	}
	int t = q[*f];
	if(*f == *r){
		*f = *r = -1;
		return t;	
	}
	(*f)++;
	return t;
}
int findmin(int arr[],int visited[],int n){
	int i,min=0;
	for(i =0;i<=n;i++){
		if(arr[min] > arr[i] && visited[i] == 0)
			min = i;
		//printf("%d distance %d i\n",arr[i],i);
	}
	return min;
}
int dijkshtras(struct table arr[],int n,int a,int b){
	int distance[n],visited[n];
	int i,j;
	for(i =0; i<=n; i++){
		visited[i]=0;
		distance[i] = INF;
	}
	distance[a]=0;
	//printf("%d a %d\n",distance[a],a);
	for(i=0;i<=n;i++){
		j = findmin(distance,visited,n);
		//printf("min %d\n",j);
		if(visited[j]==1)  {
			//i--;
			continue;
		}
		if(visited[j] == 0){
			visited[j]=1;
			struct node *p = arr[j].next;
			while(p){
					//printf("%d p->str %d\n",distance[p->str],p->str);
				if(visited[p->str]==0 && distance[p->str] > distance[j] + p->w){
					distance[p->str] = distance[j] + p->w;
					//printf("%d min %d\n",distance[p->str],p->str);
				}
				p = p->next;
			}
		}
	}
	return distance[b];
}
			
	

int main()
{
	int n,m,i,k,j,a,b,x,y,z,max=-999;
	scanf("%d%d%d",&m,&a,&b);
	struct table arr[2000];
	for(i = 0; i<2000; i++){
		arr[i].next = NULL;
		arr[i].count=0;
	}
	for(i = 0; i< m ; i++){
		scanf("%d%d%d",&x,&y,&z);
		if(x>z){
			n=x;
			x=z;
			z=n;
		}
		addedge(arr,x,y,z);
		addedge(arr,z,y,x);
		if(max < x)	max = x;
		if(max < z)     max=z;
	}
	/*for(i =0; i<=max;i++){
		struct node *p = arr[i].next;
		printf("\n%d ---   ",i);	
		while(p){
			printf("%d %d --",p->str,p->w);
			p = p->next;
		}
	}*/
	i=dijkshtras(arr,max,a,b);
	if(i == INF) printf("NO\n");
	else
	printf("YES\n%d\n",i);
	
	return 0;
}


