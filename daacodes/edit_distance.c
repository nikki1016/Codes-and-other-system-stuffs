#include<stdio.h>
#include<string.h>
int min(int a,int b,int c){
	if(a < b && a<c )
		return a;
	else if(b < a && b < c )
		return b;
	else  return c;
}
int edit_distance(char *a,char *b){
	int n = strlen(a);
	int m = strlen(b);
	printf("%d %d\n",n,m);
	int arr[n+1][m+1];
	int dir[n+1][m+1];
	int i,j;
	for(i = 1; i<n+1; i++){
		for(j=1; j<m+1; j++){
			arr[i][j]=0;
			dir[i][j] = 0;
		}
	}
	for(i =0; i<n+1; i++)
		arr[i][0] = i;
	for( i = 0; i<m+1; i++)
		arr[0][i] = i;
	for(i =1;i<n+1; i++){
		for(j =1;j<m+1; j++){
			int aa=99999,bb=99999,cc=99999;
			if(a[i-1] == b[j-1]){
				arr[i][j] = arr[i-1][j-1];
			}
			else {
				aa = arr[i][j-1] + 1;
				bb= arr[i-1][j]+1;
				cc = arr[i-1][j-1]+ 1;
				arr[i][j] = min(aa,bb,cc);
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

	return arr[n][m];
}
	



int main(){
	int i;
	char a[100],b[100];
	scanf("%s",a);
	scanf("%s",b);
	i = edit_distance(a,b);
	printf("%d\n",i);
	return 0;
}
