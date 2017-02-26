#include <stdio.h>
void quick_rand(int arr[],int low,int up);
void quick_up(int arr[],int low,int up);
void quick_low(int arr[],int low,int up);
int partition(int arr[],int mid,int up);
void quick_median(int arr[],int low,int up);
void quick_mean(int arr[],int low,int up);
void swap(int *a,int *b);
//int inv_cnt(int arr[],int n);
//void copy(int arr[],int temp[], int low,int high);
int main(){
	int arr[100],n,i,j,temp;
	scanf("%d",&n);
	for(i = 0; i< n; i++){
		scanf("%d",&arr[i]);
	}
	
	//j = inv_cnt(arr,n);
	quick_mean(arr,0,n-1);
	for(i = 0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
void quick_rand(int arr[],int low,int up){
	int i,temp,pivot;
	i = low + rand() % (up+1) ;
	printf("%d is pivot\n",i);
	swap(&arr[i],&arr[0]);
	pivot = partition(arr,low,up);
	quick_rand(arr,low,pivot-1);
	quick_rand(arr,pivot+1,up);
}
void quick_low(int arr[],int low,int up){
	int pivot ;
	if(low <up){
		pivot = partition(arr,low,up);
		printf("%d is pivot\n",pivot);
		quick_low(arr,low,pivot-1);
		quick_low(arr,pivot+1,up);
	}
}
void quick_up(int arr[],int low,int up){
	int pivot,temp;
	swap(&arr[low],&arr[up]);
	if(low <up){
		pivot = partition(arr,low,up);
		quick_up(arr,low,pivot-1);
		quick_up(arr,pivot+1,up);
	}
}
void quick_median(int arr[],int low,int up){
	int pivot,mid ;
	mid = (low + up )/2;
	if(arr[low] > arr[mid])
		swap(&arr[low],&arr[mid]);
	if(arr[mid] > arr[up])
		swap(&arr[up],&arr[mid]);
	if(arr[low] > arr[mid])
		swap(&arr[low],&arr[mid]);
	swap(&arr[low],&arr[mid]);
			printf("%d is median\n",arr[low]);
	if(low <up){
		pivot = partition(arr,low,up);
		printf("%d is pivot\n",pivot);
		quick_median(arr,low,pivot-1);
		quick_median(arr,pivot+1,up);
	}
}
void quick_mean(int arr[],int low,int up){
	int pivot,mid ,i,sum=0;
	int temp[100]={0},min = 100000;
	for(i =0; i<= up; i++)
		sum += arr[i];
	sum = (int)( sum/(up+1));
	printf("%d is mean\n",sum);
	for(i = low; i<= up; i++){
		temp[i] = abs(arr[i] - sum);
		if(temp[i] < min)
			min = temp[i];
	}
	for(i = low; i<= up; i++)
		if(min == temp[i])
			break;		
	swap(&arr[low],&arr[i]);
	printf("%d is pivot\n",arr[low]);
	if(low <up){
		pivot = partition(arr,low,up);
		printf("%d is pivot\n",pivot);
		quick_mean(arr,low,pivot-1);
		quick_mean(arr,pivot+1,up);
	}
}
int partition(int arr[],int low,int up){
	int i=low + 1,j=up,temp;
	int pivot =arr[low];
	while(i<=up && i <= j){
		while( arr[i] <= pivot)
			i++;
		while( arr[j] > pivot)
			j--;
		if(i <j ){
			swap(&arr[i],&arr[j]);
		}
		else i++;
	}
	arr[low] =arr[j];
	arr[j] = pivot;
	return j;
}
void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;	
	*b = temp;
}
