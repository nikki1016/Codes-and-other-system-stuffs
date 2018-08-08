#include<stdio.h>
#include<string.h>
void sort(int arr[],int brr[],int n);
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
int long_subseq(char *a,char *b){
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
				dir[i][j] = 0;      //diagonal
			}
			else if(arr[i-1][j] >= arr[i][j-1]){
				arr[i][j] = arr[i-1][j];
				dir[i][j] = 1;        // up
			}
			else {
				arr[i][j] = arr[i][j-1];
				dir[i][j] = 2;   // left
			}

		}
	}
	return arr[n][m];
}
	



int main(){
	int i;
	FILE *fp = fopen("dict.txt","r");
	int ch,flag=0 ;
	char str[100][100];
	while( fscanf(fp,"%s",str[i]) ==1){
		str[i][strlen(str[i])] = '\0';
		printf("in  %s\n",str[i]);			
		i++;
	}
	int n = i;
	FILE *ip = fopen("inputt.txt","r");
	FILE *op = fopen("output.txt","w+");
	char string[100];
	while( fscanf(ip,"%s",string) == 1){
		string[strlen(string)] = '\0';
		printf("i %s\n",string);
		int arr[n],brr[n];
		flag=0;
		for(i =0; i<n;i ++){
			if(strcmp (string , str[i])==0){
				flag = 1;	
				strcat(string,"\n");		
				fputs(string,op);
				printf("%s\n",string);	
				break;
			}
		}
		if(flag ==0){
			for(i =0; i<n;i++){
				arr[i] = long_subseq(string,str[i]);
				brr[i] = i;
			}
			char cc[100];
			sort(arr,brr,n);
			strcpy(cc,str[brr[0]]);
			strcat(cc," ");
			fputs(cc,op);
			strcpy(cc,str[brr[1]]);
			strcat(cc," ");
			fputs(cc,op);
			strcpy(cc,str[brr[2]]);
			strcat(cc,"\n");
			fputs(cc,op);
		}			
		
	}
	
	
	//int j = lcs_rec(a,b,strlen(a)-1,strlen(b)-1);
	printf("%d  \n",i);
	return 0;
}

void sort(int arr[],int brr[],int n){
	int i,j;
	for(i =0; i< n-1; i++){
		for(j = i +1; j<n; j++){
			if(arr[i] < arr[j] ){
				int temp = arr[i];		
				arr[i] = arr[j];
				arr[j] = temp;
				temp = brr[i];	
				brr[i] = brr[j] ;
				brr[j] = temp;
			}
		}
	}
}
