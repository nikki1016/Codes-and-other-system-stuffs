#include<stdio.h>
#define MAX 100
#define infinity 9999
#define nil -1
#define white 0
#define grey 1
#define black 2
void push(int stack[],int *top,int i);
int pop(int stack[], int *top);
void enqueue(int q[],int *front,int *rear,int i);
int dequeue(int q[],int *front,int *rear);

void bfs(int arr[][MAX], int v,int s,int state[],int path[],int pred[],int q[],int *front,int *rear);
void dfs(int arr[][MAX], int v,int s,int state[],int path[],int pred[],int stack[],int *front);
void dfs_rec(int arr[][MAX],int v,int i,int state[],int dis[],int fin[],int *time);
void short_bfs(int arr[][MAX], int v,int s,int des,int state[],int path[],int pred[],int stack[],int *front,int *rear);
void ins_edge(int arr[][MAX], int v,int i,int j);
void del_edge(int arr[][MAX], int v,int i,int j);
void display(int arr[][MAX],int v);
void create_graph(int arr[][MAX], int v);
void warshall(int arr[][MAX], int v);
int main(){
	int arr[MAX][MAX]=  {0}, state[MAX], pred[MAX], path[MAX],q[MAX],stack[MAX],dis[MAX],fin[MAX];
	int i,j,v,front = -1,rear =-1, top = -1,time= 0;
	scanf("%d",&v);
	for(i = 1; i<=v; i++){
		state[i] = white;
		pred[i] = nil;
		path[i] = infinity;
	}
	for(i = 1; i<=v; i++){
		for(j = 1; j<=v; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	//create_graph(arr,v);
	display(arr,v);
	//warshall(arr,v);
	scanf("%d%d",&i,&j);
	short_bfs(arr,v,i,j,state,path,pred,q,&front,&rear);	
	
	dfs(arr,v,j,state,path,pred,stack,&top);
for(i = 0; i<v; i++){
		state[i] = white;
		pred[i] = nil;
		path[i] = infinity;
	}
	dfs_rec(arr,v,j,state,dis,fin,&time);
	for(i = 1; i<=v; i++){
		printf("%d id dis & %d is fin of %d\n",dis[i],fin[i],i);
	}
	return 0;
}

void push(int stack[],int *top,int i){
	if(*top == 99){
		printf("overflow\n");
		return;
	}
	(*top)++;
	stack[*top] = i;
}
int pop(int stack[], int *top){
	if(*top == -1){
		printf("underflow\n");
		return;
	}
	int i = stack[(*top)--];
	return i;
}
void enqueue(int q[],int *front,int *rear,int i){
	if(*front == (*rear+1) % MAX ){
		printf("overflow\n");
		return;
	}
	if(*front == -1)
		(*front)++;
	*rear = (*rear +1) %MAX;
	q[*rear] = i;
}
int dequeue(int q[],int *front,int *rear){
	if(*front == -1){
		printf("underflow\n");
		return;
	}
	int i = q[*front];
	if(*front == *rear)
		*front = *rear = -1;
	else *front = (*front +1) %MAX;
	return i;
}

void bfs(int arr[][MAX], int v,int s,int state[],int path[],int pred[],int q[],int *front,int *rear){
	int cur,i;
	enqueue(q,front,rear,s);
	state[s] = grey;
	path[s] = 1;
	pred[s] = nil;
	while(*front != -1){
		cur = dequeue(q,front,rear);
		state[cur] = black;
		printf("%d_",cur);
		for(i =1; i<= v; i++){
			if(arr[cur][i] != 0 && state[i] == white){
				enqueue(q,front,rear,i);
				state[i] = grey;
				path[i] = path[cur] + 1;
				pred[i] = cur;
			}
		}
	}
	printf("\n");
}

void dfs(int arr[][MAX], int v,int s,int state[],int path[],int pred[],int stack[],int *front){
	int cur,i;
	for(i = 1; i<= v; i++){
		state[i] = white;
		pred[i] = nil;
		path[i] = infinity;
	}
	push(stack,front,s);
	path[s] = 1;
	pred[s] = nil;
	while(*front != -1){
		cur = pop(stack,front);
		if(state[cur] == white)
			printf("%d_",cur);
		state[cur] = black;
		for(i =v; i>0; i--){
			if(arr[cur][i] != 0 && state[i] == white){
				push(stack,front,i);
				path[i] = path[cur] + 1;
				pred[i] = cur;
			}
		}
	}
	printf("\n");
}
void dfs_rec(int arr[][MAX],int v,int s,int state[],int dis[],int fin[],int *time){
	state[s] = grey;
	(*time)++;
	dis[s] = *time;
	printf("%d + ",s);
	int i;
	for(i =1;i <=v; i++){
		if(arr[s][i] != 0 && state[i] == white){
			dfs_rec(arr,v,i,state,dis,fin,time);
		}
	}
	state[s] = black;
	fin[s] = (*time)++;
}
	
void short_bfs(int arr[][MAX], int v,int s,int des,int state[],int path[],int pred[],int q[],int *front,int *rear){
	bfs(arr,v,s,state,path,pred,q,front,rear);
	if(pred[des] == nil){
		//printf("no pred\n");
		return;
	}
	int pat[MAX] ,i = 0,j,u;
	while(pred[des] != nil){
		pat[i++] = pred[des];
		u = pred[des];
		des = u;
	}
	for(j = 0; j<i; j++){
		printf("%d   ",pat[j]);
	}
}
void warshall(int arr[][MAX], int v){
	int path[MAX][MAX],i,j,k;
	for(k =1; k<=v; k++){
		for(i = 1; i<=v; i++)
			path[k][i] = arr[k][i];
	}
	for(k =1; k<=v; k++){
		for(i = 1; i<=v; i++){
			for(j =1; j<=v; j++){
				if(path[i][j] == 1 || (path[i][k] && path[k][j]))
					path[i][j] = 1;
				else path[i][j] = 0;
			}
		}
	}
	for(i = 1; i<=v; i++){
		for(j =1; j<=v; j++)
			printf("%d ",path[i][j]);
		printf("\n");
	}
}
void dijkshtra(int arr[][MAX], int v,int s,int path[]){

}
void ins_edge(int arr[][MAX], int v,int i,int j){
	if(i >v || j> v){
		printf("vertices not exist\n");
		return;
	}
        arr[i][j] = 1;
}


void del_edge(int arr[][MAX], int v,int i,int j){
	if(i >v || j> v){
		printf("vertices not exist\n");
		return;
	}
	arr[i][j] = 0;
}

void display(int arr[][MAX],int v){
	int i,j;
	for(i =1; i<=v; i++){
		for(j =1; j<=v; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void create_graph(int arr[][MAX], int v){
	int i,s,d;
	for(i = 1; i<v *(v-1); i++){
		scanf("%d%d",&s,&d);
		if(s <= -1 || d <= -1)
			return;
		if(s > v || d > v){
			i--;
			continue;
		}
		arr[s][d] = 1;
	}
}

