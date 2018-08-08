#include<stdio.h>

void DFS(int,int,int *,int [],int a[][100],int *);
int G[100][100],visited[100],n;    //n is no of vertices and graph is sorted in array G[10][10]

int main()
{
	int i,j,u,v,w1;
	printf("Enter number of vertices:");

	scanf("%d",&n);

	//read the adjecency matrix
	printf("\nEnter adjacency matrix of the graph:");
	scanf("%d%d%d",&u,&v,&w1);
	while(u!=-1)
	{
		G[u][v]=w1;
		scanf("%d%d%d",&u,&v,&w1);
	}

	//visited is initialized to zero
	for(i=0;i<n;i++)
		visited[i]=0;

	printf("Enter source and destination :");
	scanf("%d%d",&u,&v);
	int k=0;
	int path[100];
	int a[100][100];
	int m = 0;
	DFS(u,v,&k,path,a,&m);
	//int m = *m1;
	
	if(m==0)
	{
		printf("NULL\nNULL\nNULL\n");
		return 0;
	}
	int w[m];
	for(i=0;i<m;i++)
		w[i]=i;
	if(m>=3)
		k = 3;
	else
		k = m;
	for(i=0;i<=k-1;i++) {
		for(j=i+1;j<m;j++) {
			if(a[w[i]][0]>a[w[j]][0])
			{
				int temp=w[i];
				w[i]=w[j];
				w[j]=temp;
			}
		}
	}
	for(i=0;i<=k-1;i++) {
		for(j=2;j<a[w[i]][1];j++)
			printf("%d ",a[w[i]][j]);
		printf("\n");
	}
	for(i=k;i<=2;i++) 
		printf("NULL\n");
	//for(i=0;i<m;i++) {
	//	w[m]+=
}

void DFS(int i,int v,int *k,int path[],int a[][100],int *l)
{
	//printf("DFS %d \n",i);
	int j;
	path[(*k)]=i;
	(*k)+=1;
	visited[i]=1;
	if(i==v) 
	{
		a[*l][1]=*k+2;
		for(j=0;j<(*k);j++)
		{
			if(j<(*k)-1)
				a[*l][0]+=G[path[j]][path[j+1]];
			a[*l][j+2]=path[j];
			//printf("%d->",path[j]);
		}
		//printf(" %d",a[*l][0]);
		//printf("\n");
		(*l)+=1;
		//return;
	}
	for(j=0;j<n;j++) 
		if(!visited[j]&&G[i][j]!=0)
			DFS(j,v,k,path,a,l);
	(*k)--;
	visited[i]=0;	
}
