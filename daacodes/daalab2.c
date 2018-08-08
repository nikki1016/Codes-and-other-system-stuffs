/*
	k-ary Max-Heap
In the last classes we learnt about Max/Min - Heaps, its properties and the following operations on them.
• build MAX heap(A)
• insert(m)
• Extract max(A)
The max-heap implementation we dealt with, in the class, was a binary heap (each node had at most 2 children). Similarly, a MAX-Heap can be implemented using a k-ary heap (each node can have at most k children). Remember that a k-ary heap is a complete k-ary tree.
In this assignment, you take an array (of length n) as input and you are required to
1. Check that the array is already a k-ary MAX-heap.
2. If not, implement a k-ary max-Heap. You should allow the above mentioned operations on the k-ary max-Heap (with array representation).
	Please implement all the operations without recursion/recursive methods.
3. write an algorithm (change(A,i,m)) for changing an element in the middle of max-heap (A[i] ← m) and restore the max-heap property.

*/


# include <stdio.h>
# include <stdlib.h>

int check_MAX_heap(int *,int,int);
int extract_MAX(int *,int, int);
void insert(int *,int,int,int);
void change(int *,int,int,int,int);
void maxheapify(int a[], int j, int heapsize,int k);
void bubbleup(int arr[],int n,int k);
void build_MAX_heap( int arr[], int n, int k);
int main()
{
	  char ch=' ';
	  int *arr,n,k,i,new;
	  scanf("%d",&k);
	  scanf("%d",&n); /* To have anything non-trivial, n should be >2*n*k*/
	  arr = (int *)malloc(2*n*sizeof(int));
	  for(i=0;i<n;i++)
	  {
	      scanf("%d",&arr[i]);
	  }
	  i = check_MAX_heap (arr,n,k);
	
	if(i == 0){
printf("hii\n");
		build_MAX_heap(arr,n,k);
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}

	  do
	    {
	      while(getchar()!='\n'); /* To clear the buffer of any leftover characters*/
	      ch=getchar();
	      switch(ch)
		{
		case 'i':
		  	scanf("%d",&new);
		 	 insert(arr,n,k,new);
		  	n+=1;
			for(i=0;i<n;i++)
			{
	      			printf("%d ",arr[i]);
	    		}
		  	break;
		case 'd':
			if(n>=1){
			  	printf("%d\n",extract_MAX(arr,n,k));
			  	n--;
			}
			for(i=0;i<n;i++)
			{
	      			printf("%d ",arr[i]);
	    		}
		  	break;
		case 'c':
		  scanf("%d",&i);
		  scanf("%d",&new);
		  change(arr,n,k,i,new);
		  break;
		}
	    }while(ch!='q');
	  return 0;
}
void build_MAX_heap( int arr[], int n, int k){
	//printf("-k = %d  n = %d",k,n);
	int j = (n/k)-1,i;
	for( ; j>=0; j--){
		maxheapify(arr,j,n,k);
	}
} 

int check_MAX_heap(int a[],int n,int k)
{
  /* The function returns 0 if arr is NOT a k-ary MAX-heap.*/
	int j  = (n-1)/k, i,largest,f=0 ;
	while(j >= 0){
		largest = j;
		for(i=0;i<k;i++){
			if ( (k*j + i +1) <= n-1 && a[k*j + i +1] > a[j]) 
				largest = k*j + i +1;
		} 

		if (largest != j) {
			f=1;
		    	return 0;
		}
		j--;
	}
	if(f==0)
		return 1;
	else return 0;			
}


void maxheapify(int a[], int j, int n,int k){
	int temp, i;
	int largest = j;
	while(j < n){
		
		for(i=0;i<k;i++){
			if ( (k*j + i +1) < n && a[k*j + i+1] > a[largest]) {
				largest = k*j + i + 1;
			}
			else if ( (k*j + i +1) >= n) break;
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
void insert(int arr[],int n,int k,int new)
{
  /* This function inserts a new element into the k-ary MAX-heap arr*/
	arr[n] = new;
	bubbleup(arr,n,k);	
}
void bubbleup(int arr[],int n,int k){
	int pos = n;
	while(pos > 0 && arr[(pos-1)/k] < arr[pos]){
		int y = arr[pos];
		arr[pos]= arr[(pos-1)/k];
		arr[(pos-1)/k] = y;
		pos = (pos-1)/k;
	}
}
int extract_MAX(int arr[],int n,int k)
{
  /* This function extracts the maximum element of a k-ary MAX-heap and returns it*/
	if(n==0) return -1;
	int temp = arr[0];
	arr[0] = arr[n-1];
	maxheapify(arr,0,n-1,k);
	return temp;
}

void change(int arr[],int n,int k,int i,int new)
{
  /* This function changes the value of arr[i]= new and makes arr a k-ary max-heap*/
	if(i >= n ) {
		printf("cnt change\n");
		return;
	}
	int temp = arr[i];
	arr[i] = new;
	if(new > temp)
		bubbleup(arr,i,k);
	else if(new < temp)
		maxheapify(arr,i,n,k);
	//printf("%d arr[i]",arr[i]);
}

