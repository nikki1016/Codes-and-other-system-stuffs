#include<stdio.h>
#include<stdlib.h>
#define INF 99999

int find_min(int distance[],int visited[],int n){
	int i,min= INF, ind=-1;
	for(i =0; i<n; i++){
		if(min > distance[i] && visited[i] ==0){
			min = distance[i];
			ind = i;
		}
	}
	return ind;
}
int prim(int **arr,int n,int *parent){
	int k,j;
	int distance[n],visited[n],i;
	for(i =0; i<n ; i++){
		distance[i] = INF;
		visited[i] = 0;
		parent[i]  = -1;
	}
	distance[0] = 0;
	int hs = n,u=0,d=0;
	while(hs--){
		i = find_min(distance,visited,n);
		d += distance[i];
		visited[i] =1;
		if(i == -1 || i>=n)
			break;
		for(u = 0; u<n ;u++){
			if(i != u && arr[i][u] != 0 && distance[u] > arr[i][u] && visited[u] == 0){
				distance[u] = arr[i][u];
				parent[u] = i;
				//printf("find   %d -> %d :%d   && arr is %d\n",i,u,distance[u],arr[i][u] );
			}
		}
		//u = i;
	}
	return d;
}

int main(){
	int **arr, *parent;
	
	int n,k,i,j,w,s,t,temp=0;
	scanf("%d",&n);
	arr = (int **)calloc(n,sizeof(int *));
	for(i=0;i<n;i++){
      		arr[i] = (int *)calloc(n,sizeof(int));
    	}
	parent = (int *)calloc(n,sizeof(int));
	scanf("%d%d%d",&i,&j,&k);
	while(i!=-1)
	{
	      	arr[i][j]=k;
	      	scanf("%d%d%d",&i,&j,&k);
	}
	int d = prim (arr,n,parent);
	/*printf("\npath2: \n");
	while(parent[temp] != temp)
	{
	      printf("->%d",parent[temp]);
	      temp=parent[temp];
	}*/
	printf("%d\n",d);
	return 0;
}
