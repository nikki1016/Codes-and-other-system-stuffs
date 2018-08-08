#include <stdio.h>
int partition(int arr[],int low,int high){
    int j,temp;
	int i = (low - 1); 
      	int pivot = (arr[high]);
	for ( j = low; j <= high- 1; j++)
	{
		if (arr[j] < pivot)
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
int find(int arr[],int low,int high){
    int i=low;
    while(i <= high ){
	        printf("ffn\n");
        if(arr[i] == 2){
            return i;
        }
	i++;
    }
    return -1;
}
void quicksort(int arr[],int low,int high){
    if(low >= high){
        return;
    }	        printf("gii  ");
    int i= partition(arr,low,high);
	        printf("%d i  ",i);
    int j =find(arr,i,high);
	        printf("%d j  ",j);
    if(j == -1) return;
    arr[j] = arr[high];
    arr[high] =2;
    j = partition(arr,i,high);
}

int main() {
	int t,ind;
	scanf("%d",&t);
	while(t--){
	    	int n,i,f=0;
	    	scanf("%d",&n);
	    	int arr[n];
		ind=-1;
	    	for(i = 0; i<n ; i++){
	        	scanf("%d",&arr[i]);
	        	if(arr[i] == 1 && f==0){
	            		f=1;
	            		ind = i;
	        	}
	    	}
	     	printf("%d-ind\n",ind);
	    	if(ind != -1){
	        	arr[ind]= arr[n-1];
	        	arr[n-1] = 1;
	    	}
		for(i = 0; i<n ; i++){
	        	printf("%d ",arr[i]);
	    	}
	        printf("\n");
	    	i= partition(arr,0,n-1);
	        printf("%d i\n",i);
    		int j = find(arr,i,n-1);
	        printf("%d j\n",j);
   		if(j != -1){
    			arr[j] = arr[n-1];
   	 		arr[n-1] =2;
    			j = partition(arr,i,n-1);
		}
	    	for(i = 0; i<n ; i++){
	        	printf("%d ",arr[i]);
	    	}
	        printf("\n");
	}
	return 0;
}
