#include <stdio.h>
void mergesort(int arr[],int low,int up);
void merge(int arr[],int temp[],int low,int mid,int up);
void copy(int arr[],int temp[], int low,int high);
int main(){
	int arr[100],n,i;
	scanf("%d",&n);
	for(i = 0; i< n; i++){
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,n-1);
	for(i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
void mergesort(int arr[],int low,int up){
	int mid,temp[100];
	if(low<up){	
		mid = (low+up)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,up);
		merge(arr,temp,low,mid,up);
		copy(arr,temp,low,up);
	}
}
void merge(int arr[],int temp[],int low,int mid,int up){
	int i=low,j=mid+1,k=low;
	while(i<=mid && j <=up){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else
			temp[k++] = arr[j++];
	}
	while(i<=mid)
		temp[k++] = arr[i++];
	while(j<=up)
		temp[k++] = arr[j++];
//printf("yo2\n");
}
void copy(int arr[],int temp[], int low,int high){
	int i;
	for(i=low; i<=high;i++)
		arr[i] = temp[i];
	//printf("yo3\n");
}
