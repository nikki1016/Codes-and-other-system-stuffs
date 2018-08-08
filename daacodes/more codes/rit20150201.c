#include<stdio.h>
# include <stdlib.h>
#define INF 999999
#define NIL -1

int find_MIN(int arr[],int p[],int n){
	int i,min=INF,ind = -1;
	for(i =0;i<n;i++){
		if(arr[i] < min && p[i] == 0){
			min = arr[i];
			ind = i;
		}

	}
	return ind;
}
void dijkstra(int **arr,int parent[],int s,int **dist,int n){
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
			if(arr[j][q] != 0 && visited[q]==0 && distance[q] > distance[j] + arr[j][q]){        
				distance[q] = distance[j] + arr[j][q];
				parent[q] = j;
			}
			
		}	
	}
	for(i =0; i<n; i++){
		dist[s][i] = distance[i];
	}
}

int findcycle(int n,int **adj,int s){
	int **distance;
	int i,j;
	distance = (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
    	{
      		distance[i] = (int *)calloc(n,sizeof(int));
    	}
	for(i =0; i<n; i++){
		for(j =0; j<n; j++){
			distance[i][j] = INF;
		}
	}
	int parent[n];
	for(i = 0; i<n; i++){
		dijkstra(adj,parent,i,distance, n);
	}
	int d = 0,min = INF,t = s,ind = -1;
	for(i =0; i<n; i++){
		if(t <n && distance[t][i] < min && distance[t][i] > 0){
			min = distance[t][i];
			ind =i;
		}
	}
	int flag = 0;
	if(ind == -1){
		d = 0;
		flag = 1;
	}
	else {
		d += adj[t][ind];
		t = ind;
	}
	int k = 0;
	while(s != t && flag == 0 && k < n){
		ind =-1;
		min = INF;	
		for(i =0; i<n; i++){
			if(t <n && distance[t][i] < min && distance[t][i] > 0 && distance[t][i] != INF){
				min = distance[t][i];
				ind =i;
			}
		}
		if(ind == -1){
			d= 0;
			flag = 1;
		}
		else {
			d += adj[t][ind];
			t = ind;
		}
		k++;
	}
	return d;	
}
