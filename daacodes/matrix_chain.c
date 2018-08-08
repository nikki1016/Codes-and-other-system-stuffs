#include <stdio.h>
#include <stdlib.h>

void solve(int *,int);
void printans(int arr[][100],int n,int i,int j);
int main(){
  	int i,n,m;
	int *p;
  	scanf("%d",&n);  /* Enter how many numbers are there in the expression */
  	p = (int *)malloc((n+1)*sizeof(int)); /* n numbers and n-1 operators */
  	for(i=0;i<n+1 ;i++) {
    		scanf("%d",&p[i]); /* operator */
//		arr[i] = i+1;

  	}
  	solve(p,n+1);
  	return 0;
}

void solve(int *p,int n){
	int arr[n][100],brac[n][100];
	int i,j,k,len,q;
	for(i =0; i< n; i++){	
		for(j =0; j<=n; j++){
			arr[i][j] = 0;
			brac[i][j] =-1;
			if(i ==j)
				brac[i][j] = i;
		}
	}
	for(len = 2; len < n; len++){
		for(i =1; i< n-len+1; i++){
			j = i+len-1;
			arr[i][j] = 999999;
			for(k = i; k <= j-1 ; k++){
				q = arr[i][k] + arr[k+1][j] + p[i-1]*p[k]*p[j];
				//printf("%d q %d i %d j %d k %darr[i][k] %d arr[k+1][j] %d p[i-1] %d p[k] %d p[j]\n",q,i,j,k,arr[i][k],arr[k+1][j],p[i-1],p[k],p[j]);
				if(q < arr[i][j]){
					//printf("q %d and arr[i][j] %d\n",q,arr[i][j]);
					arr[i][j] = q;
					brac[i][j] = k;
				}
			}
		}
	}
	for(i =0; i< n; i++){
		for(j =0; j<n; j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	for(i =0; i< n; i++){
		for(j =0; j<n; j++)
			printf("%d  ",brac[i][j]);
		printf("\n");
	}
	printf("min multiplication required are : %d\n",arr[1][n-1]);
	printans(brac,n,1,n-1);
	printf("\n");
}

void printans(int arr[][100],int n,int i,int j){
	if(i==j){
		printf("A%d ",i);
		return;
	}
	printf(" ( ");
	printans(arr,n,i,arr[i][j]);
	printans(arr,n,arr[i][j]+1, j);
	printf(" ) ");
	return ;
}
