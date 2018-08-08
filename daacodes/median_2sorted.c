#include<stdio.h>
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
int min(int a,int b){
	if(a<b) return a;
	else return b;
}
int median(int arr[],int l1,int r1,int brr[],int l2,int r2){
	if(r2-l2+1 == 0 && r1-l1+1 == 0 ) return -1;
	if(r2-l2+1 == 1 && r1-l1+1 == 1) return (arr[r1] + brr[r2])/2;
	if(r2-l2+1 == 2 && r1-l1+1 == 2) {
		return (max(arr[l1],brr[l2]) + min(arr[r1],brr[r2]))/2;
	}	
	int m1,m2;
	if( (r1-l1+1 )%2 == 0)
		m1 = (arr[(r1-l1+1)/2 +l1 -1] + arr[(r1-l1+1)/2 +l1]) /2;
	else  m1 = arr[(r1-l1+1)/2 +l1 ];
	if( (r2-l2+1 )%2 == 0)
		m2 = (brr[(r2-l2+1)/2 +l2 -1] + brr[(r2-l2+1)/2 +l2]) /2;
	else  m2 = brr[(r2-l2+1)/2 +l2 ];
	if(m1 > m2){
		printf("aarr>\n");
		return median(arr,l1,(r1-l1+1)/2 +l1 -1,brr,(r2-l2+1)/2 +l2,r2);
	}
	else if(m1 < m2){
printf("arr<\n");
		return median(arr,(r1-l1+1)/2 +l1 ,r1,brr,l2,(r2-l2+1)/2 +l2-1);
	}
	else return (m1+m2)/2;
}

int main(){
	int n,i;
	scanf("%d",&n);
	int arr[n],brr[n];
	for(i=0;i<n; i++)
		scanf("%d",&arr[i]);
	for(i = 0; i<n ; i++)
		scanf("%d",&brr[i]);
	i = median(arr,0,n-1,brr,0,n-1);

	printf("%d\n",i);
	return 0;
}

