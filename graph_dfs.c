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
void push(int stack[100],int data,int *top);
int pop(int stack[100],int *top);
void creategraph(int arr[][MAX],int v,int d_un);
void display(int arr[][MAX],int v);
void dfs(int arr[][MAX],int v,int s,int stack[],int *top,int state[],int path_l[],int pred[]);
int main(){
	int q[MAX],front = -1;
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
			dfs(graph,v,i,q,&front,state,pathlength,pred);
			c++;
			printf("\n");	
		}
	}
	printf("%d connected components in this graph\n",c);
	return 0;
}
void dfs(int arr[][MAX],int v,int s,int stack[],int *top,int state[],int path_l[],int pred[]){
	int i;	
	push(stack,s,top);
	while(*top != -1){
		s = pop(stack,top );
		if(state[s] == white)
			printf("%d->",s);
		state[s] = black;
		for(i = v-1; i>=0; i--){
			if(arr[s][i] != 0 && state[i] == white)
				push(stack,i,top);
		}
	}
	printf("\n");
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
void push(int stack[100],int data,int *top) {
	if(*top == 99){
		printf("overflow\n");
		return ;
	}
	(*top)++;
	stack[*top] = data;
}
	

int pop(int stack[100],int *top) {
	if(*top == -1) {
		printf("underflow\n");
		return -1;
	}
	int data ;
	data = stack[*top];
	(*top)--;
	return data;
}

