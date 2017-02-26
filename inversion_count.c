#include <stdio.h>
int mergesort(int arr[],int low,int up);
int merge(int arr[],int temp[],int low,int mid,int up);
int inv_cnt(int arr[],int n);
void copy(int arr[],int temp[], int low,int high);
int main(){
	int arr[100],n,i,j;
	scanf("%d",&n);
	for(i = 0; i< n; i++){
		scanf("%d",&arr[i]);
	}
	j = inv_cnt(arr,n);
	i = mergesort(arr,0,n-1);
	
	printf("inversion_count is %d n %d\n",i,j);
	for(i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
int inv_cnt(int arr[],int n){
	int i,j,sum =0;
	for(i =0; i<n-1; i++){
		for(j=i+1;j <n; j++){
			if(arr[i] > arr[j])
				sum++;
		}
	}
	return sum;
}
int mergesort(int arr[],int low,int up){
	int mid,temp[100],inv=0;
	if(low<up){	
		mid = (low+up)/2;
		inv = mergesort(arr,low,mid);
		inv += mergesort(arr,mid+1,up);
		inv  +=  merge(arr,temp,low,mid,up);
		copy(arr,temp,low,up);
		return inv;
	}
   return 0;
}
int merge(int arr[],int temp[],int low,int mid,int up){
	int i=low,j=mid+1,k=low,inv=0;
	while(i<=mid && j <=up){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			inv = inv +(mid-i+1);
	printf("inv++\n");
		}
	}
	while(i<=mid)
		temp[k++] = arr[i++];
	while(j<=up)
		temp[k++] = arr[j++];
	printf("yo2\n");
	return inv;
}
void copy(int arr[],int temp[], int low,int high){
	int i;
	for(i=low; i<=high;i++)
		arr[i] = temp[i];
	//printf("yo3\n");
}
