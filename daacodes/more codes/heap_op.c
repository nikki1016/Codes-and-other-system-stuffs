/*The structure of the class is
class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

public:
MinHeap(int cap=100) {heap_size = 0; capacity = cap; harr = new int[cap];}

    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
};*/

/* Removes min element from min heap and returns it */
#include<stdio.h>
void maxheapify(int a[], int i, int heapsize)
{
    if(heapsize == 0) return;
    int temp, largest, left, right, k;
    left = (2*i);
    right = ((2*i)+1);
    if (left >= heapsize)
        return;
    else {
        if (left <= (heapsize) && a[left] < a[i]) 
            largest = left;
        else
            largest = i;
        if (right <= (heapsize) && a[right] < a[largest])  
            largest = right;
        if (largest != i) {
            temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            maxheapify(a, largest, heapsize);
        }
    }
}

int  extractMin(int heap_size, int harr[])
{
   	if(heap_size==0) return -1;
   	if(heap_size == 1){
   	    heap_size--;
   	    return  harr[1];
   	} 
	int temp = harr[1];
	harr[1] = harr[heap_size];
	heap_size--;
	maxheapify(harr,1,heap_size);
	
	return temp;
}

/* Removes element from position x in the min heap  */
void  deleteKey(int x,int heap_size, int harr [])
{
    if(heap_size == 0 || x > heap_size) return;
    x++;
    int pos = x;
    int temp = harr[x];
	harr[x] = harr[heap_size];
	 heap_size--;
	if(temp < harr[x]){
	    maxheapify(harr,x,heap_size);
	}
	else if(temp > harr[x]){
	    while(pos > 0 && harr[(pos-1)/2] < harr[pos]){
		    int y = harr[pos];
		    harr[pos]= harr[(pos-1)/2];
		    harr[(pos-1)/2] = y;
	    	pos = (pos-1)/2;
	    }
	}
   
}

/* Inserts an element at position x into the min heap*/
void insertKey(int x,int heap_size ,int harr [])
{
    heap_size++;
    harr[heap_size] = x;
    int pos = heap_size;
	while(pos > 1 && harr[(pos)/2] > harr[pos]){
		int y = harr[pos];
		harr[pos]= harr[(pos)/2];
		harr[(pos)/2] = y;
		pos = (pos)/2;
	}

}


int main() {
	int t,n,i,q,a,heap_size=0;
	int arr[100];
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&a);
		while(a--){
		    	scanf("%d",&q);
		    	if(q==1){
//for(i = 0; i< 5;i++){
			    	scanf("%d",&n);
		    	    	insertKey(n, heap_size , arr);
				heap_size++; 
//}
			}
			else if(q==2){
			    	scanf("%d",&n);
				deleteKey(n,heap_size, arr);
				if(heap_size !=0) 
				heap_size--;
			}
			else if(q==3){
//for(i = 0; i< 5;i++){
				printf("%d ",extractMin(heap_size,arr));
				if(heap_size !=0) 
					heap_size--;
//}
			}
		}
	}
	return 0;
}
