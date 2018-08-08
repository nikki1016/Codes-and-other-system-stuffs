#include<stdio.h>
void update(int bit[],int ind,int value,int max);
int query(int bit[],int ind,int max);
int main(){
	int t,n,arr[100],i,j;
	scanf("%d",&t);
	for(i = 1; i<=t; i++){
		scanf("%d",&n);
		int bit[105] = {0};
		for(j =1; j<=n; j++){
			scanf("%d",&arr[j]);
			update(bit,j,arr[j],n);
			
		}
		printf("query of 4 is %d",query(bit,4,n));
			
	}
	
}
void update(int bit[],int ind,int value,int max){
	while(ind < max){
		bit[ind] += value;
		ind += ind & -ind;
	}
}
int query(int bit[],int ind,int max){
	int sum = 0;
	while(ind > 0){
		sum += bit[ind];
		ind -= ind & -ind;
	}
	return sum;
}
