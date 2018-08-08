#include <stdio.h>
#include <stdlib.h>

void knapsack01(int *p,int *q,int w,int n);
void knapsack01_rec(int *p,int *q,int w,int n);
int knapsack01_rec_util(int *weight,int *cost,int w,int i);
//void printans(int arr[][100],int n,int i,int j);
int main(){
  	int i,n,w;
	int *p,*q;
  	scanf("%d",&n);  /* Enter how many numbers are there in the expression */
  	p = (int *)malloc(n*sizeof(int));
	q = (int *)malloc(n*sizeof(int));
  	for(i=0;i<n;i++) {
    		scanf("%d",&p[i]); /* weight*/
  	}
	for(i=0;i<n ;i++) {
    		scanf("%d",&q[i]); /* cost*/
  	}
	//printf("gg");
	scanf("%d",&w);
  	knapsack01_rec(p,q,w,n);
  	return 0;
}

void knapsack01(int *weight,int *cost,int w,int n){
	int arr[n+1][w+1],brr[n+1][w+1];
	int i,j;
	for (i =0; i<n+1; i++){
		for(j= 0; j<w+1; j++){
			arr[i][j] =0;
		}
	}
	for(i =0; i<n+1; i++){
		arr[i][0] = 0;
		brr[i][0] = 0;
	}
	for(i =0; i<w+1; i++){
		arr[0][i] = 0;
		brr[0][i] = 0;
	}
	int a,b=0;
	for( i = 1; i<n+1; i++){
		for(j = 1; j <w+1; j++){
			a = arr[i-1][j];          //without that value
			if(j - weight[i-1] >=0 ){
				b = arr[i-1][j-weight[i-1]] + cost[i-1] ; 
			}
			else b=0;
			if(a > b){
				arr[i][j] = a;
				brr[i][j] = 1;           //up
			}
			else{
			 	arr[i][j] = b;
				if(b == cost[i-1])
					brr[i][j] = 0;                //self
				else brr[i][j] = 2;     // cross
			}
			//printf("%d %d %d %d %d\n",arr[i][j],i,j,a,b);
		}
	}
	printf("%d\n",arr[n][w]);
	for(i =0; i<n+1; i++){
		for(j =0; j<w+1; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");	
	}
	for(i =0; i<n+1; i++){
		for(j =0; j<w+1; j++){
			printf("%d ",brr[i][j]);
		}
		printf("\n");	
	}
}
void knapsack01_rec(int *weight,int *cost,int w,int n){
	if(n == 0 || w==0){
		printf("0\n");
		return ;
	}
	int a = knapsack01_rec_util(weight,cost,w,n);
	printf("%d\n",a);
}
int knapsack01_rec_util(int *weight,int *cost,int w,int i){
	if(i == -1 || w<=0){
		return 0;
	}
	int  a,b;
	a = knapsack01_rec_util(weight,cost,w,i-1);
	if(w-weight[i] >=0)
		b = knapsack01_rec_util(weight,cost,w-weight[i],i-1) + cost[i];
	else b=0;
	//printf("%d %d %d %d\n",i,w,a,b);
	if(a > b) return a;
	else return b;
}

/*
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
*/
