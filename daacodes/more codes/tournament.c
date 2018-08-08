#include<stdio.h>
int findsecondmin(int arr[],int low,int high){
	if(low == high) return arr[low];
	if(high-low+1 == 2) {
		if(arr[low] < arr[high]) return arr[high];
		else return arr[low];
	}
	int brr[high-low+1];
	int i,k;
	for(i =low,k =0; i<=high; i= i+2){
		if(arr[i] > arr[i+1] && i+1<=high)
			brr[k++]=arr[i+1];
		else if(arr[i] < arr[i+1] && i+1 <= high)
			brr[k++] = arr[i];
		else if(i == high)
			brr[k++] = arr[i];
	}
	return findsecondmin(brr,0,k-1);
}

int main(){
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i =0;i<n; i++)
		scanf("%d",&arr[i]);
	i = findsecondmin(arr,0,n-1);
	printf("%d\n",i);
	return 0;
}
