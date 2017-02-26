#include<stdio.h>
struct node{
	int parent;
	int rank;
};
void makeset(struct node arr[],int n){
	int i,j;
	for(i =1; i<=n; i++){
		arr[i].parent = i;
		arr[i].rank = 0;
	}
}
int find(struct node arr[],int n,int a){
	int i;
	if(arr[a].parent == a)
		return a;
	arr[a].parent =  find(arr,n,arr[a].parent);
	return arr[a].parent;
}

void unionn(struct node arr[],int n,int i,int j){
	int a,b;
	a = find(arr,n,i); 
	b = find(arr,n,j);
	if( a != b){
		if(arr[a].rank < arr[b].rank)
			arr[a].parent = b;
		else if(arr[b].rank < arr[a].rank)
			arr[b].parent = a;
		else {
			arr[b].parent = a;
			(arr[a].rank) ++;
		}
	}
}

void display(struct node arr[],int n){
	int i;
	for(i = 1; i<= n; i++){
		printf("%d  %d  %d \n",i,arr[i].parent,arr[i].rank);
	}
}
int main(){
	struct node set[100];
	int n,i,j;
	scanf("%d",&n);
	makeset(set,n);
	while(1){	
		scanf("%d%d",&i,&j);
		if(i == -1 || j == -1)
			break;
		unionn(set,n,i,j);
	}
	display(set,n);
	return 0;
}
