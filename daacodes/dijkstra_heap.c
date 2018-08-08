# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
#define INF 999999
#define NIL -1

int find_MIN(int arr[],int p[],int n){
	int i,min=99999,ind = -1;
	for(i =0;i<n;i++){
		if(arr[i] < min && p[i] == 0){
			min = arr[i];
			ind = i;
		}
		//printf("%d distance %d i\n",arr[i],i);
	}
	return ind;
}
int dij_three(int **arr,int parent[],int s,int t,int n){
	int distance[n];
	int visited[n],q;
	int i;
	int j;
	for(i =0; i<n; i++){
		visited[i]=0;
		distance[i] = INF;
		parent[i] = NIL;
	}
	int hs = n,k;
	distance[s] =0;
	while(hs){
		j = find_MIN(distance,visited,n);
		hs--;
		if(j == -1) break;
		visited[j]=1;
		for(q=0; q<n; q++){
			if(q == j || arr[j][q]==0 )  
				continue;
		  //      printf("               q %d dis %d\n",q,distance[q]);
			if(arr[j][q] != 0 && visited[q]==0 && distance[q] > distance[j] + arr[j][q]){
				distance[q] = distance[j] + arr[j][q];
				//change(distance,hs, k, j.dis + arr[j.ind][q]);
				parent[q] = j;
				//for(i =0;i<n;i++)          printf("change    ind %d dis %d\n",i,distance[i]);
			}
		}
		
	}
	//for(i =0;i<n;i++)          printf("final   ind %d   dis %d\n",i,distance[i]);
	return distance[t];
}

int main()
{	
	int n=1,k,i,j,s,t,m=1;
	scanf("%d%d",&n,&m);
	while(n!= 0 && m != 0){
		int **adj;
		adj = (int **)calloc(n,sizeof(int *));
		for(i=0;i<n;i++){
      			adj[i] = (int *)calloc(n,sizeof(int));
    		}
		int parent[n];
		for(i=0;i<n;i++)
	    	{
			for(j=0;j<n;j++)
	  			adj[i][j] = 0;
			parent[i]= 0;
	    	}
		  scanf("%d%d",&s,&t);
		while(m--){
			 scanf("%d%d%d",&i,&j,&k);
			 adj[i][j]=k;
		}	
		printf("%d\n",disjkstra(adj,n,parent,s,t));
		scanf("%d%d",&n,&m);
	}
  	return 0;
}


