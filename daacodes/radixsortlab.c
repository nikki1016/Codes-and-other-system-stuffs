# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

void radix_sort(char **,int,int);
void radsort(char **,int,int,int);
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
	}
	radix_sort(input,n,k);
	for(i=0;i<n;i++)
	{
		printf("%s\n",input[i]);
	}

	return 0;
}
void radsort(char **input,int n,int num,int k)
{
	char ans[n][n]; 
	int m;
	int i,count[101]={0};
	for(i=0;i<n;i++)
	{
		//printf("%s\n",a[i]);
		//printf("%d\n",(int)(strlen(a[i])-1));
		m=input[i][strlen(input[i])-num-1]-32;
		//printf("co%d %d\n",m,i);
		count[m]++;
	}
	for (i=1;i<101;i++)
	{
		count[i]=count[i]+count[i-1];
		//	printf("ii%d %d\n",i,count[i]);
	}
	int j,xo=n;
	for(i=n-1;i>=0;i--)
	{
		//printf("%d %d\n",i,count[input[i][(int)(strlen(input[i])-num-1)]-1]);
		m=count[input[i][(int)(strlen(input[i])-num-1)]-32]-1;
		//printf("mm%d %d %d %d\n",m,i,(int)strlen(input[i]),num);
		//input[m+xo]=(char *)malloc((k+1)*sizeof(char));
		for(j=0;j<strlen(input[i]);j++)
		{
			//printf("%s\n",input[i]);
			ans[m][j]=input[i][j];
		}
		count[input[i][(int)(strlen(input[i])-num-1)]-32]--;
		xo++;
	}
	for(i=0;i<n;i++)
	 {
	 for(j=0;j<strlen(input[i]);j++)
	 {
	  input[i][j]=ans[i][j];
	  }
	  }

}
void radix_sort(char **input,int n,int k)
{
	/* The function sorts the array input using radix sort
	   Write the two versions of the radix sort here, one after another.
	   To execute one of the version just comment out the other version.
	 */
	int num;
	for(num=0;num<k;num++)
	{
		radsort(input,n,num,k);
	}
}

