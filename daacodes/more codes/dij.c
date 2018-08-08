#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

int mindist(int dist[], bool setfinal[],int v)
{
	int min=INT_MAX,min_index,m;
	for(m=0;m<v;m++)
	{
	if(setfinal[m]==false && dist[m]<=min)
	{
		min=dist[m];
		min_index=m;
	}
}
	return min_index;
}
int print(int dist[],int v)
{
	int i;
	printf("vertex          distance from source\n");
	for(i=0;i<v;i++)
	{
		printf("%d \t\t %d\n",i,dist[i]);
	}
}
void dij(int graph[100][100],int src,int v)
{
	int dist[v];
	int count,i,a,u;
	bool setfinal[v];
	for(i=0;i<v;i++)
	{
		dist[i]=INT_MAX;
		setfinal[i]=false;
	}
	dist[src]=0;
	for(count=0;count<v;count++)
	{
		u=mindist(dist,setfinal,v);
		setfinal[u]=true;
		for(a=0;a<v;a++)
		{
			if(a != u && setfinal[a]==false && graph[u][a] && dist[u]!=INT_MAX && dist[u]+graph[u][a]<dist[a])
			{
				dist[a]=dist[u]+graph[u][a];
			}
		}
	}
	print(dist,v);
	
}
int main()
{
	int v;
	int graph[100][100],i,j,s;
	printf("enter no of vertices\n");
	scanf("%d",&v);
	printf("enter the matrix\n");
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("enter the source\n");
	scanf("%d",&s);
	dij(graph,s,v);
	return 0;
}
