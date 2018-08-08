#include<stdio.h>
int search_root(int arr[],int brr[],int n){
	int i,j;
	for(i = 0 ; i < n ; i++){
		for(j = 0; j<n; j++){
			if(arr[i] == brr[j] && i!=j){
				break;
			}
		}
		if(j==n) return arr[i];
	}
	return -1;
}
void findchild(int arr[],int brr[],int n,int root,int *a,int *b){
	int i,cnt = 1;
	for(i = 0 ; i<n;i++){
		if(arr[i] == root && cnt == 1){
			*a = brr[i];
			cnt++;
		}
		else if(arr[i] == root && cnt == 2){
			*b = brr[i];
			cnt++;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n],brr[n],i,j,root;
	for(i=0;i<n; i++)
		scanf("%d%d",&arr[i],&brr[i]);
	root = search_root(arr,brr,n);
printf("root  %d ",root);
	int crr[n*2+1];
	for(i = 0 ; i< n*2+1;i++)
		crr[i]=-1;
	crr[0]=root;
	int k = 0;
	for(i =0; i<n ;i++){
		int a=-1,b=-1;
		root = crr[k++];
		while(root==-1 && k<n*2+1){
			root = crr[k++];
		}
		findchild(arr,brr,n,root,&a,&b);
		j = k-1;
		//printf("j %d a %d b %d\n",j,a,b); 
		if(a != -1){
			if(crr[2*j+1] == -1){
				crr[2*j+1] = a;
			}
		}
		if(b != -1){
			if( crr[2*j+2] == -1 ){
				crr[2*j+2] = b;
			}
		}
		//else if(a==-1 && b==-1){
			
		//root = crr[k++];
	}
	for(i = 0 ; i<k ; i++){
		printf("%d ",crr[i]);
	}	
	return 0;
}
