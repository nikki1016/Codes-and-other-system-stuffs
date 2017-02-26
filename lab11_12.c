#include<stdio.h>
void pathmul(int adj[][100],int tmp[][100],int n);
int main(){
	int adj[100][100],n,i,j,tmp[100][100];
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		for(j = 1; j<= n; j++){
			scanf("%d",&adj[i][j]);
			tmp[i][j] = adj[i][j];
		}
	}
	for(i = 2; i<=n; i++)
		pathmul(adj,tmp,n);
	scanf("%d",&j);
	for(i =1; i<=n; i++){
		if(tmp[j][i] != 1 && i != j)
			break;
	}
	if(i != n)
		printf("not arborescence\n");
	return 0;
}
void pathmul(int adj[][100],int tmp[][100],int n){
	int arr[100][100],i,j,k;
	for(i = 1; i<=n; i++){
		for(j = 1; j<=n; j++){
			arr[i][j] = 0;
			for(k = 1; k<=n; k++)
				arr[i][j] = arr[i][j] + adj[i][k] * tmp[k][j];
		}
	}
	for(i =1;i<=n; i++)
		for(j  =1; j<=n; j++)
			tmp[i][j] = arr[i][j];
}


