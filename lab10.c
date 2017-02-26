#include<stdio.h>
#include<stdlib.h>
#define infinity 99999
#define initial 1
#define waited 2
#define visited 3
#define nil -1
#define MAX 100
#define dir 1
#define undir 0
void enqueue(int arr[],int item,int *front,int *rear);
int dequeue(int arr[],int *front,int *rear);
void push(int stack[100],int data,int *top);
int pop(int stack[100],int *top);
void ins_edge(int arr[][MAX],int v,int i,int j,int d_un);
void del_ver(int arr[][MAX],int *v,int n,int d_un);
void del_edge(int arr[][MAX],int u,int v,int d_un);
void creategraph(int arr[][MAX],int v,int d_un);
void display(int arr[][MAX],int v);
void bfs(int arr[][MAX], int v,int s,int q[],int *front ,int *rear,int state[],int path[],int pred[]);
void dfs(int arr[][MAX], int v,int s,int st[],int *top,int state[],int path[],int pred[]);
int main(){
	int graph[MAX][MAX] = {0}, q[MAX], stack[MAX], state[MAX],pathl[MAX],pred[MAX];
	int v,s,des,d_un,i,ch,j,c = 0;
	int front = -1, rear = -1,top = -1;
	while(1){
		scanf("%d",&ch);
		switch(ch){
			case 1:
				scanf("%d%d",&v,&s);
				for(i = 0; i<v; i++){	
					for(j =0; j<v; j++){
						scanf("%d",&graph[i][j]);
					}
				}
				for(i =0; i<v; i++)
					state[i] = initial;
				bfs(graph,v,s-1,q,&front,&rear,state,pathl,pred);
				//break;
			case 2:
				for(i =0; i<v; i++)
					state[i] = initial;
				for(i =0; i<v; i++){
					if(state[i] == initial){
						dfs(graph,v,i,stack,&top,state,pathl,pred);
						c++;
					}
				}
				printf("%d\n",c);
				//break;
			case 3:
				scanf("%d%d",&i,&j);
				if(graph[i-1][j-1] != 0)
					printf("yes\n");
				else printf("no\n");	
				//break;
			case 4:scanf("%d%d",&v,&s);
				for(i = 0; i<v; i++){	
					for(j =0; j<v; j++){
						scanf("%d",&graph[i][j]);
					}
				}
				for(i =0; i<v; i++){
					for(j =i+1; j<v; j++){
						if(graph[i][j] != 0){
							printf("%d %d\n",i+1,j+1);
						}
					}
				}
				break;
			default : exit(0);
		}
	}	

/*creategraph(graph,v,d_un);
	display(graph,v);
	scanf("%d%d",&s,&des);
	
*/	display(graph,v);
	return 0;
}
void bfs(int arr[][MAX], int v,int sr,int q[],int *front ,int *rear,int state[],int path[],int pred[]){
	int cur,i;
	for(i =0; i<v; i++)
		state[i] = initial;
	enqueue(q,sr,front,rear);
	state[sr] = waited;
	while(*front != -1){
		cur = dequeue(q,front,rear);
		state[cur] = visited;
		printf("%d_",cur+1);
		for(i =0; i<v; i++){
			if(arr[cur][i] != 0 && state[i] == initial){
				enqueue(q,i,front,rear);
				state[i] = waited;
				path[i] = path[cur] +1;
				pred[i] = cur;
			}
		}
	}
	printf("\n");
}

void dfs(int arr[][MAX], int v,int sr,int stack[],int *top,int state[],int path[],int pred[]){
	int cur,i;
	
	push(stack,sr,top);
	while(*top != -1){
		cur = pop(stack,top);
		if(state[cur] == initial)
			printf("%d +",cur+1);
		state[cur] = visited;
		for(i = v-1; i>=0; i--){
		//for(i = 0; i<v; i++){
			if(arr[cur][i] != 0 && state[i] == initial){
				push(stack,i,top);
				pred[i] = cur;
				path[i] = path[cur] +1;
			}
		}
	}
	printf("\n");
}
int height(int arr[][MAX],int v){
	if(
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

