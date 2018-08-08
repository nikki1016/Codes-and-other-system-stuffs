#include<stdio.h>
void minheapify(int a[], int j, int n){
	int temp, i;
	int largest = j;
	while(j < n){
		
		for(i=0;i<2;i++){
			if ( (2*j + i +1) < n && a[2*j + i+1] < a[largest]) {
				largest = 2*j + i + 1;
			}
			else if ( (2*j + i +1) >= n) break;
		} 

		if (largest != j) {
		    	temp = a[j];
		   	a[j] = a[largest];
		    	a[largest] = temp;
		    	j = largest;
		}
		else return;
	}

}
void build_MIN_heap( int arr[], int n){
	//printf("-k = %d  n = %d",k,n);
	int j = (n/2)-1;
	for( ; j>=0; j--){
		minheapify(arr,j,n);
	}
} 

int extractmin(int arr[],int n)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
	if(n==0) return -1;
	int temp = arr[0];
	arr[0] = arr[n-1];
	minheapify(arr,0,n-1);
	return temp;
}
int mincost(int arr[],int n){
	build_MIN_heap(arr,n);
	int i,a,b,sum=0;
	while(n){
		a = extractmin(arr,n);
		n--;
		b = arr[0];
		arr[0] = a+b;
		sum+=a+b;
		//printf("%d %d %d %d %d\n",a,b,arr[0],sum,n);
		minheapify(arr,0,n);
	}
	return sum;
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n],i;
	for(i = 0; i<n;i++)
		scanf("%d",&arr[i]);
	i = mincost(arr,n);
	printf("%d\n",i);
	return 0;
}
