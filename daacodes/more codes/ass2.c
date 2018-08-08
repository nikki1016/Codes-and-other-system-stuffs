# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>
struct node {
	struct node *next;
	int str;
};
struct table{
	struct node *next;
	int count;
};
void addedge(struct table arr[],int k,int n)
{
	int i, j;
	struct node * p = (struct node *)malloc(sizeof(struct node)),*kk = arr[k].next;
	p->str = n;
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

void bfs(struct table arr[],int n){
	int q[n],front=-1,rear=-1,k;
	int visited[n],i;
	for(i = 0 ; i < n; i++)
		visited[i] = -1;
	visited[0] = 0;
	enqueue(q,0,&front,&rear);
	while( front != -1){
		i = dequeue(q,&front,&rear);
		//printf("%d i ",i);
		struct node *p = arr[i].next;
		while(p){
			k = p->str;
			p = p->next;
			if(visited[k] == -1){
				visited[k] = 1+visited[i];
				enqueue(q,k,&front,&rear);
				//printf("%d k--  ",k);
			}
		}
	}
	//for(i =0;i<n;i++)
	printf("%d\n",visited[n-1]);
}

int main()
{
	int n,m,i,k,j;
	scanf("%d%d",&m,&n);
	int r[m][n],d[m][n];
	struct table arr[n*m];
	for(i = 0; i<m*n; i++){
		arr[i].next = NULL;
		arr[i].count=0;
	}
	for(i = 0; i< m ; i++){
		for(j =0;j<n; j++){
			scanf("%d",&r[i][j]);
			k = r[i][j];
			while(k ){
				if(i == m-1 && j == n-1)
					break;
				if(i*n+j+k <= i*n+m){
					addedge(arr,i*n+j,i*n+j+k);
				//	printf("%d %d\n",i*n+j,i*n+j+k);
				}
				k--;
			}
		}
	}
	for(i = 0; i< m ; i++){
		for(j =0;j<n; j++){
			scanf("%d",&d[i][j]);
			k = d[i][j];
			while(k){
				if(i*n+j+n*k < n*m){
					//printf("%d %d\n",i*n+j,i*n+j+k);
					addedge(arr,i*n+j,i*n+j+n*k);
				}
				k--;
			}
		}
	}
	/*for(i =0; i<n*m;i++){
		struct node *p = arr[i].next;
		printf("\n%d ---   ",i);	
		while(p){
			printf("%d ",p->str);
			p = p->next;
		}
	}*/
	bfs(arr,m*n);
	
		//printf("%d\n",);

	return 0;
}


