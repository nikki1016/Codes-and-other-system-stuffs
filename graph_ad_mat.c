#include<stdio.h>
#include<stdlib.h>
void ins_ver(int arr[][100],int *v);
void ins_edge(int arr[][100],int v,int i,int j,int d_un);
void del_ver(int arr[][100],int *v,int n,int d_un);
void del_edge(int arr[][100],int u,int v,int d_un);
void creategraph(int arr[][100],int v,int d_un);
void display(int arr[][100],int v);

int main(){
	int graph[100][100] = {0},v,i,j,e,d_un;
	scanf("%d%d",&v,&d_un);
	creategraph(graph,v,d_un);
	display(graph,v);
	del_ver(graph,&v,2,d_un);
	display(graph,v);
	return 0;
}
void ins_ver(int arr[][100],int *v){
	(*v)++;
}
void ins_edge(int arr[][100],int v,int i,int j,int d_un){
	if(i<v && j<v && i>=0 && j>=0){
		arr[i][j] = 1;
		if(d_un == 0)
			arr[j][i] = 1;
	}
	else printf("cant exist\n");
}
void del_ver(int arr[][100],int *v,int n,int d_un){
	int i,j;
	for(i = 0; i<*v; i++){
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
		if(i<v && j<v && i>=0 && j>=0){
			arr[i][j] = 1;
			if(d_un == 0)
				arr[j][i] = 1;
		}
		else   break;
	}
}

void display(int arr[][100],int v){
	int i,j;
	for(i=0;i<v; i++){
		for(j =0; j<v; j++)
			printf("%d  ",arr[i][j]);
		printf("\n");
	}
}

