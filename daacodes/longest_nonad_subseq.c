#include<stdio.h>
#include<string.h>
void printans(int brr[][100],char *a,int i,int j,int k){
	if(i <=0 || j <= 0)
		return;
	//printf("%d %d %d \n",i,j,brr[i][j]);
	if(brr[i][j] == 0){
		printans(brr,a,i-k,j-k,k);
		printf("%c",a[i-1]);
	}
	else if(brr[i][j] == 1){
		//printf("%c",a[i-1]);
		printans(brr,a,i-1,j,k);
	}
	else if(brr[i][j] == 2){
		//printf("%c",a[i-1]);
		printans(brr,a,i,j-1,k);
	}

}
int lcs_rec(char *a,char*b,int x,int y){
	if(x== -1  || y==-1)
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
int long_subseq(char *a,char *b,int k){
	int n = strlen(a);
	int m = strlen(b);
	printf("%d %d\n",n,m);
	int arr[n+1][m+1];
	int dir[n+1][100];
	int i,j;
	for(i = 0; i<n+1; i++){
		for(j=0; j<m+1; j++){
			arr[i][j]=0;
			dir[i][j] = 0;
		}
	}
	for(i =1;i<n+1; i++){
		for(j =1;j<m+1; j++){
			if(a[i-1] == b[j-1]){
				if( i-k >=0 && j-k >=0)
					arr[i][j] = arr[i-k][j-k]+1;
				else
					arr[i][j] = 1;
				dir[i][j] = 0;      //diagonal
			}
			else if(arr[i-1][j] > arr[i][j-1]){
				arr[i][j] = arr[i-1][j];
				dir[i][j] = 1;        // up
			}
			else {
				arr[i][j] = arr[i][j-1];
				dir[i][j] = 2;   // left
			}

		}
	}
	for(i =1; i< n+1; i++){
		for(j =1 ;j< m+1; j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("direction\n");
	for(i =1; i< n+1; i++){
	        for(j =1 ;j< m+1; j++){
	                printf("%d ",dir[i][j]);
	        }
	        printf("\n");
	}
	printans(dir,a,n,m,k);
	return arr[n][m];
}
	


int main(){
	int i,k;
	char a[100],b[100];
	scanf("%s",a);
	scanf("%s",b);
	printf("enter k for nonadjacent subseq (for ad k=0)\n");
	scanf("%d",&k);
	i = long_subseq(a,b,k+1);
	int j = lcs_rec(a,b,strlen(a)-1,strlen(b)-1);
	printf("%d  %d\n",i,j);
	return 0;
}
