#include<stdio.h>
#include<stdlib.h>
#define white 0
#define grey 1
#define black 2
void ins_ver(int arr[][100],int *v);
void ins_edge(int arr[][100],int v,int i,int j,int d_un);
void del_ver(int arr[][100],int *v,int n,int d_un);
void del_edge(int arr[][100],int u,int v,int d_un);
void creategraph(int arr[][100],int v,int d_un);
void display(int arr[][100],int v);
void dfs(int arr[][100],int v,int s,int state[]);
void arti_p(int arr[][100],int v,int state[]);
int main(){
	int graph[100][100] = {0},v,i,j,e,d_un,state[100];
	scanf("%d%d",&v,&d_un);
	creategraph(graph,v,d_un);
	display(graph,v);
	for(i = 1; i <= v;i++)
		state[i] = white;
	scanf("%d",&e);
//	dfs(graph,v,e,state);
	printf("\n");
	arti_p(graph,v,state);
	//del_ver(graph,&v,2,d_un);
	//display(graph,v);
	return 0;
}
void dfs(int arr[][100],int v,int s,int state[]){
	int i;
//	printf("%d_",s);
	state[s] = black;
	for(i = 1; i <= v;i++){
		if(state[i] == white && arr[s][i] != 0 )
			dfs(arr,v,i,state);
	}
}
void arti_p(int arr[][100],int v,int state[]){
	int i,j,k,c=0,count=0;
	int adj[100][100];
	for(i=1; i<=v; i++){
		for(j=1;j<=v; j++){
			adj[i][j] = arr[i][j];
		}
	}
	for(i =1; i<=v;i++){
		if(state[i] == white){
			dfs(arr,v,i,state);printf("\n");
			c++;
		}
	}
	printf("%d\n",c);
	for(i = 1; i <= v;i++)
		state[i] = white;
	for(j=1;j<=v;j++){
		count = 0;
		for(k=1;k<=v;k++){
			adj[j][k] = 0;
			adj[k][j] = 0;
		}
				//	display(adj,v);
		for(k =1; k<=v;k++){
			if(state[k] == white && k != j){
				dfs(adj,v,k,state);//printf("\n");
				count++;
			}
		}
	//	printf("%d+    %d\n",j,count);
		if(count != c){
			printf("%d is ap\n",j);
		}		
		count = 0;
		for(k=1;k<=v;k++){
			adj[j][k] = arr[j][k];
			adj[k][j] = arr[k][j];
		}
		for(i = 1; i <= v;i++)
			state[i] = white;		
	}		
}
void ins_ver(int arr[][100],int *v){
	(*v)++;
}
void ins_edge(int arr[][100],int v,int i,int j,int d_un){
	if(i<=v && j<=v && i>0 && j>0){
		arr[i][j] = 1;
		if(d_un == 0)
			arr[j][i] = 1;
	}
	else printf("cant exist\n");
}
void del_ver(int arr[][100],int *v,int n,int d_un){
	int i,j;
	for(i = 1; i<=*v; i++){
		if(arr[i][n] == 1)
			arr[i][n] =0;
		if(arr[n][i] == 1)
			arr[n][i] =0;
	}
	
}
void del_edge(int arr[][100],int u,int v,int d_un){
	arr[u][v] =0;
	if(d_un == 0)
		arr[v][u] = 0;
	
}
void creategraph(int arr[][100],int v,int d_un){
	int i,j;
	while(1){
		scanf("%d%d",&i,&j);
		if(i<=v && j<=v && i>0 && j>0){
			arr[i][j] = 1;
			if(d_un == 0)
				arr[j][i] = 1;
		}
		else   break;
	}
}

void display(int arr[][100],int v){
	int i,j;
	for(i=1;i<=v; i++){
		for(j =1; j<=v; j++)
			printf("%d  ",arr[i][j]);
		printf("\n");
	}
}

