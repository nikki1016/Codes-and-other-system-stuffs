#include<stdio.h>

int partition(double *arr, int low, int high) {
   	int j;
	double temp;
	int i = (low - 1); 
      	double pivot = (arr[high]);
	for ( j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i ];
			arr[i ] =  arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] =  arr[high];
	arr[high] = temp;
	return (i + 1);
}


void quickSort(double * arr,int left, int right) {
	if(right <= left) return;
	int point = partition(arr, left, right);
  	quickSort(arr, left,point-1);
	quickSort(arr, point+1,right);
}
int main(){
	int i,n;
	scanf("%d",&n);
	double arr[n];
	for(i = 0; i< n;i++){
		scanf("%lf",&arr[i]);
	}
	quickSort(arr,0,n-1);
	for(i = 0; i< n;i++){
		printf("%.2lf ",arr[i]);
	}
	return 0;
}
