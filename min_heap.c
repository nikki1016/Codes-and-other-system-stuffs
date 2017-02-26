#include<stdio.h>
#define MAX 100
void build_heap(int arr[],int hs);
void insert(int arr[],int data,int *hs);
void delete_root(int arr[],int *hs);
void maxheapify(int arr[],int i,int hs);
int search(int arr[],int data,int hs);
void display(int arr[],int hs);
int ismin_heap(int arr[],int i,int hs);
int min_cost(int arr[],int *hs);
int main(){
	int heap[MAX],hs = 0,n,i,data;
	scanf("%d",&n);
	hs = n;
	for(i=1; i <= n;i++){
		scanf("%d",&data);
		heap[i] = data;
	}
	if( ismin_heap(heap,1,n)){
		printf("yes\n");	
	}
	else printf("no");
//	build_heap(heap,n);
		 display(heap,n);

	i = min_cost(heap,&hs);
	printf("%d is min cost\n",i);
	 display(heap,n);
//	insert(heap,70,&hs);
//	delete_root(heap,&hs);
	display(heap,hs);
	return 0;
}
int min_cost(int arr[],int *hs){
	build_heap(arr,*hs);
	int i = *hs,min = 0;
	while(i >1 ){
		delete_root(arr,hs);
		delete_root(arr,hs);
		min = min +arr[i] +arr[i-1];
		insert(arr,arr[i]+arr[i-1],hs);
		i = *hs;
	}
	return min;
}
int ismin_heap(int arr[],int i,int hs){
	if(i >hs)
	return 1;
	int j = 2*i;
	if(arr[i] > arr[j] && j<=hs)
		return 0;
	else if(arr[i] > arr[j+1] && j+1<=hs)
		return 0;
	else 
		return ismin_heap(arr,2*i+1,hs) && ismin_heap(arr,2*i+2,hs);
}
void build_heap(int arr[],int hs){
	int i;
	for(i = hs/2; i>0; i--)
		maxheapify(arr,i,hs);
}
int search(int arr[],int data,int hs){
	int i;
	for(i = 1; i <= hs; i++){
		if(arr[i] == data)
			return 1;
	}
	return 0;
}
void insert(int arr[],int data,int *hs){
	int i;
	if(search(arr,data,*hs)){
		printf("already there\n");
		return;
	}
	(*hs)++;
	arr[*hs] = data;
	for(i = *hs/2; i>0; i = i/2)
           maxheapify(arr,i,*hs);

}
void delete_root(int arr[],int *hs){
	if(hs == 0){
		printf("empty heap\n");
		return;
	}
//	printf("%d is min\n", arr[1]);
	int t,i;
	t = arr[1];
	arr[1] = arr[*hs];
	arr[*hs] = t;
	(*hs)--;
	maxheapify(arr,1,*hs);
	
}

void max(int arr[],int hs){
	if(hs == 0){
		printf("empty heap\n");
		return;
	}
	printf("%d is max\n", arr[1]);
}
void maxheapify(int arr[],int i,int hs){
	int l,r,largest,t;
	l = 2*i;
	r = l+1;
	largest = i;
	while(l <= hs || r <= hs){
		if(arr[i] > arr[l] && l <= hs)
			largest = l;
		if(arr[largest] > arr[r] && r <= hs)
			largest = r;
		if(largest != i){
			t = arr[i];
			arr[i] = arr[largest];
			arr[largest] = t;
		}
		else if(largest == i){
			break;
		}
		i = largest;
		l = 2*i;
		r = l+1;
	}
} 
void display(int arr[],int hs){
	int i;
	for(i =1;i <= hs; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
