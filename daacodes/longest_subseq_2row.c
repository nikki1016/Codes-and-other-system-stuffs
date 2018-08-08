#include<stdio.h>
#include<string.h>
int lcs_rec(char *a,char*b,int x,int y){
	if(x== 0  || y==0)
		return 0;
	if(a[x] == b[y]){
		int i = lcs_rec(a,b,x-1,y-1)+1;
		return i;
	}
	else {
		int j = lcs_rec(a,b,x-1,y);
		int k = lcs_rec(a,b,x,y-1);
		if(j <  k )return k;
		else return j;
	}
}
int long_subseq(char *a,char *b){
	int n = strlen(a);
	int m = strlen(b);
	printf("%d %d\n",n,m);
	int arr[2][m+1];
	int dir[n+1][m+1];
	int i,j;
	for(i = 0; i<2; i++){
		for(j=0; j<m+1; j++){
			arr[i][j]=0;
		}
	}
	for(i = 0; i<n+1; i++){
		for(j=0; j<m+1; j++){
			//arr[i][j]=0;
			dir[i][j] = 0;
		}
	}
	for(i =1;i<n+1; i++){
		for(j =1;j<m+1; j++){
			
			if(a[i] == b[j]){
				arr[i%2][j] = arr[(i+1)%2][j-1]+1;
				dir[i][j] = 0;      //diagonal
			}
			else if(arr[(i+1)%2][j] >= arr[i%2][j-1]){
				arr[i%2][j] = arr[(i+1)%2][j];
				dir[i][j] = 1;        // up
			}
			else {
				arr[i%2][j] = arr[i%2][j-1];
				dir[i][j] = 2;   // left
			}
		}
	}
	printf("direction\n");
	for(i =1; i< n+1; i++){
	        for(j =1 ;j< m+1; j++){
	                printf("%d ",dir[i][j]);
	        }
	        printf("\n");
	}

	return arr[n%2][m];
}
	



int main(){
	int i;
	char a[100],b[100];
	scanf("%s",a);
	scanf("%s",b);
	i = long_subseq(a,b);
	int j = lcs_rec(a,b,strlen(a),strlen(b));
	printf("%d  %d\n",i,j);
	return 0;
}
