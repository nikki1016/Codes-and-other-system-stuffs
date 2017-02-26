#include<stdio.h>
void minarr(int arr[],int n,int k,int temp[]);
void sort(int temp[],int k);
int min(int arr[],int low,int up);
int main(){
	int arr[100],i,n,temp[100],k;
	scanf("%d",&n);
	for(i = 0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	scanf("%d",&k);
	minarr(arr,n,k,temp);
	for(i =0; i< n-k+1; i++){
		printf("%d ",temp[i]);
	}
	printf("\n");
	sort(temp,n-k+1);
	for(i =0; i< n-k+1; i++){
		printf("%d ",temp[i]);
	}
	printf("\n");
	return 0;
}
void minarr(int arr[],int n,int k,int temp[]){
	int i;
	for(i =0; i< n-k+1; i++){
		temp[i] = min(arr,i,i+k-1);
	}
}
void sort(int temp[],int k){
	int i,j,tmp;
	for(i = 0; i<k-1; i++){
		for(j = 0; j < k-i-1; j++){
			if(temp[j] > temp[j+1]){
				tmp = temp[j];  
				temp[j] = temp[j+1]; 
				temp[j+1] = tmp;
			}
		}
	}
}
int min(int arr[],int low,int up){
	int i,minim;
	minim = arr[low];
	for(i = low+1; i<= up; i++){
		if(minim > arr[i])   minim = arr[i];
	}
	return minim;
}
