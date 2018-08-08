#include<stdio.h>
#include<stdlib.h>
#define infinity 99999
#define white 1
#define grey 2
#define black 3
#define nil -1
#define MAX 100
#define dir 1
#define undir 0
void enqueue(int arr[],int item,int *front,int *rear);
int dequeue(int arr[],int *front,int *rear);
void creategraph(int arr[][MAX],int v,int d_un);
void display(int arr[][MAX],int v);
void bfs(int arr[][MAX],int v,int s,int q[],int *front,int *rear,int state[],int path_l[],int pred[]);
int main(){
	int q[MAX],front = -1,rear = -1;
	int graph[MAX][MAX] = {0}, pathlength[MAX], pred[MAX], state[MAX];
	int v,s,des,d_un,i,c =0;
	scanf("%d%d",&v,&d_un);
	for(i = 0; i<v; i++){
		pathlength[i] = 0;
		pred[i] = nil;
		state[i] = white;
	}
	creategraph(graph,v,d_un);
	display(graph,v);
	for(i = 0; i<v; i++){
		if(state[i] == white){
			bfs(graph,v,i,q,&front,&rear,state,pathlength,pred);
			c++;
			printf("\n");	
		}
	}
	printf("%d connected components in this graph\n",c);
	return 0;
}
void bfs(int arr[][MAX],int v,int s,int q[],int *front,int *rear,int state[],int path_l[],int pred[]){	
	int i;
	enqueue(q,s,front,rear);
	state[s] = grey;
	while(*front != -1){
		s = dequeue(q,front,rear);
		printf("%d ->",s);
		state[s] = black;	
	 	for(i = 0; i< v; i++){
			if(arr[s][i] != 0 && state[i] == white){
				enqueue(q,i,front,rear);
				state[i] = grey;
				path_l[i] = path_l[s] + 1 ;
				pred[i] = s;
			}
		}
	}
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
void enqueue(int arr[],int item,int *front,int *rear){
	if(*rear == MAX-1){
		printf("overflow\n");
		return;
	}
	if(*front == -1){
		*front =0;
	}
	(*rear)++;
	arr[*rear] = item;//printf("enq\n");
}

int dequeue(int arr[],int *front,int *rear){
	if(*front == -1){
		printf("underflow\n");
		return -1;
	}
	int item;
	if(*front == *rear){
		item = arr[*front];
		*front = -1;
		*rear = -1;
		//printf("%d is dequeued\n",item);
	}
	else{
		item = arr[*front];
		(*front)++;
		//printf("%d is dequeued\n",item);
	}
	//printf("deq\n");
	return item;
}
