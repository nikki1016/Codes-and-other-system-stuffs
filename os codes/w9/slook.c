#include<stdio.h>
int main()
{
	int n;
	printf("\nenter the no of element in queue:");
	scanf("%d",&n);
	int i, a[n];
	printf("\nenter the  element in queue:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nenter the head start:");
	int start;
	scanf("%d",&start);
	int sum=0,j,diff,max=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(a[i]<a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
			if(max<a[i])
				max=a[i];

		}
	for(i=0;i<n;i++)
		printf("%d ",a[i]); 
	for(i=0;i<n;i++)
		if(a[i]>start)
			break;
	int ind=i-1;
	for(i=ind;i>=0;i--)
	{	
		if(i==ind)
		{	diff=start-a[i]; 
			printf("\n%d ---->> %d",start , a[i]);
			sum+=start-a[i];
		}		
		else
		{	diff=a[i+1]-a[i];
			printf("\n%d ---->> %d",a[i+1] , a[i]);
			sum+=a[i+1]-a[i];
		}
		
	}
	printf("\n%d  --->> 0",a[0]);
	

//	a[ind]=0;
	for(i=n-1;i>ind+1;i--)
	{ 
		if(i==n-1)
		{       diff=199-a[i];
			printf("\n199 ---->> %d",  a[i]);
		}
		else
		{       diff=a[i]-a[i-1];
			printf("\n%d ---->> %d",a[i] , a[i-1]);
		}
		sum+=diff;
	}

	printf("\n Total Head MOments :%d",start-a[0]+a[n-1]-a[ind+1]);
	return 0;
}

