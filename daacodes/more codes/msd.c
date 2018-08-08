#include<stdio.h>
#include<stdlib.h>
#include<string.h>	
void radsort(char a[][20],int n,int num)
{
	char ans[n][20];
	int m;
	int i,count[27]={0};
	for(i=0;i<n;i++)
	{
		if( (int)(strlen(a[i])) - num- 1 >= 0)
			m=a[i][(int)(strlen(a[i]))-num-1]-'a';
		else{
			m = a[i][0]-'a';
		}		
		count[m]++;
	}
	for (i=1;i<26;i++)
	{
        	count[i]=count[i]+count[i-1];
	}
	int j;
	for(i=n-1;i>=0;i--)
	{
		if((int)(strlen(a[i])-num-1) >= 0){
			m=count[ a[i][(int)(strlen(a[i])-num-1)]-'a']-1;
			count[ a[i][(int)(strlen(a[i])-num-1)] -'a']--;
		}
		else {
			m = count[a[i][0]-'a']-1;
			count[a[i][0]-'a']--;
		}		
		strcpy(ans[m],a[i]);
	}
	/*printf("ans\n");
	for(i=0;i<n;i++)
	{
		printf("%s %d  ",ans[i],(int)strlen(ans[i]));
		//printf("\n");
	}
	printf("en\n");*/
	for(i=0;i<n;i++)
	{
		strcpy(a[i],ans[i]);
	}
}
void sort(char a[][20],int n,int k)
{
	int num=0,i,j;
	for(num=0;num<k;num++)
	{
    printf("       sort %d\n",k-num);
		radsort(a,n,num);
		for(i=0;i<n;i++)
		{
			printf("%s\n",a[i]);
		}
		printf("\n");
	}
}
int main()
{
    int n,k,i,max = -99,j;
    scanf("%d",&n);
    char a[n][20];
    for(i=0;i<n;i++)
    {
    	//scanf("%s",a[i]);
	k = rand()%20;
	for(j = 0; j< k; j++)
		a[i][j]=(char)((rand()%26)+97);
	a[i][j] = '\0';
	if(max < (int)(strlen(a[i])))
		max = strlen(a[i]);
	printf("%d %s\n",k,a[i]);
    }
    sort(a,n,max);
    printf("ans\n");
    for(i=0;i<n;i++)
        printf("%s\n",a[i]);
    return 0;
}
