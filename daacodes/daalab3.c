# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
void countsort1(char **,int n,int k,int i);
void radix_sort1(char **,int,int);
void bubblesort2(char **arr,int n,int k,int ind);
void swap(char **a, char **b);
int main()
{
	char **input;
	char ch=' ';
	int n,k,i,j;
	srand(time(NULL));
	scanf("%d",&n);
	scanf("%d",&k);
	input = (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		input[i]=(char *)malloc((k+1)*sizeof(char));
		for(j=0;j<k;j++)
			input[i][j]=(rand()%95)+32;
		input[i][k]='\0';
	//printf("%s\n",input[i]);
	}
	printf("\n\n");
	radix_sort1(input,n,k);
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}
	/*bubblesort2(input,n,k,0);
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}*/
	return 0;
}

void radix_sort1(char **input,int n,int k)
{
	int i;
	for(i = k-1; i >=0 ; i--){
		countsort1(input,n,k,i);
	}
}

void countsort1(char **arr,int n,int k,int ind){
        int brr[100] , i, j;
	char crr[n][k];
        for(i = 0; i<100; i++){
	        brr[i] = 0;
	}
	for(i = 0; i < n; i++){	
	        brr[ arr[i][ind] - 32]++;
	}
	
	for(i = 1; i < 100; i++){
	        brr[i] = brr[i] + brr[i-1];
	}
	for(i = n-1; i >= 0; i--){
		for(j = 0; j < k; j++){
	        	crr[brr[arr[i][ind] - 32] -1][j] = arr[i][j];
		}
		brr[ arr[i][ind] - 32 ]--;
	}
	for(i = 0; i<n ;i++){
		for(j = 0; j < k; j++) 
	        	arr[i][j]  = crr[i][j];
	}
}

void bubblesort2(char **arr,int n,int k,int ind){
	int i,j,f=0,t;
	for(i = 0 ; i<n-1; i++){
		for(j = 0 ; j<n-i-1; j++){
			char *str;
			if(strcmp(arr[j],arr[j+1]) > 0){
	        		str = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = str;
			}
			f=1;
		}
		if(f==0)
			break;
	}
}
				
void swap(char **a, char **b){
	char *temp,*mp;
	temp = *a;
	*a= *b;
	mp = *b;
	*b= temp;
}

