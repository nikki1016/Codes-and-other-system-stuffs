#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
	if(a > b) return a;
	else return b;
}
int incs_subseq(int * p,int n){
	int i,arr[n],j;
	for(i = 0; i<n; i++){
		arr[i] = 1;
	}
	for( i = 0; i<n; i++){
		for(j = 0; j<i ; j++){
			if(p[i] > p[j]){
				arr[i] = max( arr[j] + 1,arr[i]);
			}
		}
	}
	return arr[n-1];	
}
int main(){
	int i,j;
	int *p,n;
	scanf("%d",&n);  
  	p = (int *)malloc(n*sizeof(int));
  	for(i=0;i<n;i++) {
    		scanf("%d",&p[i]); /* weight*/
  	}
  	printf("%d\n",incs_subseq(p,n));
  	return 0;
}


