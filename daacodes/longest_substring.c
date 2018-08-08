#include<stdio.h>
#include<string.h>
int lcs_rec(char *a,char*b,int x,int y){
	if(x== -1 || y==-1)
		return 0;
	if(a[x] == b[y]){
		int i = lcs_rec(a,b,x-1,y-1)+1;
		return i;
	}
	else return 0;
	
}
int long_substr(char *a,char *b){
	int n = strlen(a);
	int m = strlen(b);
	printf("%d %d\n",n,m);
	int arr[n+1][m+1];
	int dir[n+1][m+1];
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
				arr[i][j] = arr[i-1][j-1]+1;
				dir[i][j] = 1;      //diagonal
			}
			/*else if(arr[i-1][j] >= arr[i][j-1]){
				arr[i][j] = arr[i-1][j];
				dir[i][j] = 1;        // up
			}
			else {
				arr[i][j] = arr[i][j-1];
				dir[i][j] = 2;   // left
			}*/
		}
	}	
	int max=-999;
	for(i =1; i< n+1; i++){
		for(j =1 ;j< m+1; j++){
			printf("%d ",arr[i][j]);
			if(max < arr[i][j])
				max = arr[i][j];
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

	return max;
}
	
int main(){
	int i;
	char a[100],b[100];
	scanf("%s",a);
	scanf("%s",b);
	i = long_substr(a,b);
	int j = lcs_rec(a,b,strlen(a)-1,strlen(b)-1);
	printf("%d  %d\n",i,j);
	return 0;
}
