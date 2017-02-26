#include<stdio.h>
#include<stdlib.h>
#define infinity 99999
#define initial 1
#define visited 2
#define nil -1
#define MAX 100
#define dir 1
#define undir 0
void ins_edge(int arr[][MAX],int v,int i,int j,int d_un);
void del_ver(int arr[][MAX],int *v,int n,int d_un);
void del_edge(int arr[][MAX],int u,int v,int d_un);
void creategraph(int arr[][MAX],int v,int d_un);
void display(int arr[][MAX],int v);
void dijkshtra(int arr[][MAX],int v,int s,int pathlength[MAX],int predecessor[MAX],int state[MAX]);
void warshall(int arr[][MAX],int v);
void findpath(int arr[][MAX],int v,int s,int des,int pathlength[MAX],int predecessor[MAX],int state[MAX]);
void floyd(int arr[][MAX],int v,int pathlength[][MAX],int predecessor[][MAX]);
int min_l(int length[MAX],int state[MAX],int v);
int diameter(int length[MAX][MAX],int v);
int main(){
	int graph[MAX][MAX] = {0}, pathlength[MAX], pred[MAX], state[MAX],pathl_f[MAX][MAX],pred_f[MAX][MAX];
	int v,s,des,d_un,i;
	scanf("%d%d",&v,&d_un);
	for(i = 0; i<v; i++){
		pathlength[i] = infinity;
		pred[i] = nil;
		state[i] = initial;
		for(j = 0; j<v; j++){
			graph[i][j] = 0;
			pathl_f[i][j] = infinity;
			pred_f[i][j] = nil;
		}
	}
	creategraph(graph,v,d_un);
	display(graph,v);
	scanf("%d%d",&s,&des);
	dijkshtra(graph,v,s,pathlength,pred,state);
	for(i = 0; i< v; i++)
		findpath(graph,v,s,i,pathlength,pred,state);
	floyd(graph,v,pathl_f,pred_f);
	i = diameter(pathlength,v);
	printf("%d\n",i);
	//display(graph,v);
	return 0;
}

void ins_edge(int arr[][MAX],int v,int i,int j,int d_un){
	if(i<v && j<v && i>=0 && j>=0){
		arr[i][j] = 1;
		if(d_un == undir)
			arr[j][i] = 1;
	}
	else printf("cant exist\n");
}
void del_ver(int arr[][MAX],int *v,int n,int d_un){
	int i,j;
	for(i = 0; i<*v; i++){
		if(arr[i][n] == 1)
			arr[i][n] =0;
		if(arr[n][i] == 1)
			arr[n][i] =0;
	}
	
}
void del_edge(int arr[][MAX],int u,int v,int d_un){
	arr[u][v] =0;
	if(d_un == undir)
		arr[v][u] = 0;
	
}
void creategraph(int arr[][MAX],int v,int d_un){
	int i,j;
	while(1){
		scanf("%d%d",&i,&j);
		if(i<v && j<v && i>=0 && j>=0){
			arr[i][j] = 1;
			if(d_un == undir)
				arr[j][i] = 1;
		}
		else   break;
	}
}

void display(int arr[][MAX],int v){
	int i,j;
	for(i=0;i<v; i++){
		for(j =0; j<v; j++)
			printf("%d  ",arr[i][j]);
		printf("\n\n");
	}
}
void dijkshtra(int arr[][MAX],int v,int s,int pathlength[MAX],int predecessor[MAX],int state[MAX]){
	int i,j,k;
	if(s >= v || s < 0){
		printf("not exist %d s\n",s);
		return;
	}
	pathlength[s] = 0;
	while(1){
		k = min_l(pathlength,state,v);
		if(k == -1)  return;
		state[k] = visited;
		for(i = 0; i<v; i++){
			if(arr[k][i] != 0 && state[i] == initial){
				if(pathlength[k] + arr[k][i] < pathlength[i]){
					pathlength[i] = pathlength[k] + arr[k][i];
					predecessor[i] = k;
				}
			}
			printf("%d->pre",predecessor[i]);
		}
	}
}
int min_l(int length[MAX],int state[MAX],int v){
	int min = infinity, k = nil,i;
	for(i = 0; i<v; i++){
		if(length[i] < min && state[i] == initial){
			min = length[i];
			k = i;
		}
	}
	return k;
}
int diameter(int length[MAX][MAX],int v){
	int min = infinity,i,j;
	for(i = 0; i<v; i++){
		for(j =0; j<v; j++){
			if(length[i][j] > min){
				min = length[i][j];
			}
		}
	}
	return min;
}
void warshall(int arr[][MAX],int v){
	int path[MAX][MAX],i,j,k;
	for(i =0; i<v; i++){
		for(j = 0; j<v; j++)
			path[i][j] = arr[i][j];
	}
	for(k = 0; k<v; k++){
		for(i =0; i<v; i++){
			for(j = 0; j<v; j++){
				path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
				printf("%d  ",path[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
		

void findpath(int arr[][MAX],int v,int s,int des,int pathlength[MAX],int predecessor[MAX],int state[MAX]){
	if(s >= v || s < 0){
		printf("not exist %d s\n",s);
		return;
	}
	if(des >= v || des < 0){
		printf("not exist %d des\n",s);
		return;
	}	
	int path[MAX],i= des,u,p = 0;
	if(pathlength[des] == infinity){
		printf("no path\n");
		return;
	}
	printf("%d is pathlength of   ->", pathlength[des]);
	while(des != s){
		path[p++] = des;
		u = predecessor[des];
		des = u;		
	}
	path[p] = s;
	for(i = p; i>0; i--){
		printf("%d->", path[i]);
	}
	printf("%d\n",path[0]);

}
void floyd(int arr[][MAX],int v,int pathlength[][MAX],int predecessor[][MAX]){
	int dis[MAX][MAX],i,j,k;
	for(i =0; i<v; i++){
		for(j = 0; j<v; j++){
			if(arr[i][j] != 0){
				dis[i][j] = arr[i][j];
				predecessor[i][j] = i;
			}
			else dis[i][j] = infinity;
		}
	}
	for(k = 0; k<v; k++){
		printf("distance matrix is \n");
		for(i =0; i<v; i++){
			for(j = 0; j<v; j++){
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
					predecessor[i][j] = predecessor[k][j];
				}
				printf("%d ",dis[i][j]);
			}
			printf("\n");
		}
		printf("predecessor matrix is \n");
		for(i =0; i<v; i++){
			for(j = 0; j<v; j++){
				printf("%d ",predecessor[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

