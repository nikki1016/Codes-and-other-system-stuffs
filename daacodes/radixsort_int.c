#include<stdio.h>

void countsort(int arr[],int n,int k){
        int brr[10] , i, crr[n];
        for(i = 0; i<10; i++){
	        brr[i] = 0;
	}
	for(i = 0;i<n; i++){
	        brr[ (arr[i]/k)%10 ]++;
	}
	
	for(i = 1; i < 10; i++){
	        brr[i] = brr[i] + brr[i-1];
	}
/*	for(i = 0; i<10;i++)
		printf("%d ",brr[i]);
	printf("\n");*/
	for(i = n-1; i >= 0; i--){
	        crr[brr[(arr[i]/k)%10]-1] = arr[i];
	        brr[ (arr[i]/k)%10]--;
	}
/*	for(i = 0; i<n; i++)
		printf("%d ",crr[i]);
	printf("\n");*/
	for(i = 0; i<n ;i++){
	        arr[i] = crr[i];
	}
}
void radixsort(int arr[],int n,int d){
	int i;
	for(i = 1; d > 0; i = i*10,d--){
		countsort(arr,n,i);
	}
}

int main(){
	int n, i, max=-9999;
	scanf("%d",&n);
	int arr[n];
	for(i = 0; i<n; i++){
		scanf("%d",&arr[i]);
		if(max < arr[i])
			max = arr[i];
	}
	int d = 0;
	while(max > 0){
		max/= 10;
		d++;
	}
	printf("%d digits\n",d);
	int j;
	radixsort(arr,n,d);
	for(j = 0; j < n; j++	)
			printf("%d ",arr[j]);
		printf("\n");
	return 0;
}
