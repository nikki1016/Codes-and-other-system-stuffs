	#include<stdio.h>
	#include<process.h>
	int a[20],p[20],n,m;
	void first()
	{
		int i,j;
		int copy[20];
		for(i=0;i<n;i++)
		{
		    copy[i] = a[i];
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
	   	    {
	           	if(p[i]<=copy[j])
	            {
	            	copy[j] = copy[j] - p[i];
	               	printf("The Process %d allocated to %dth block occupying %d space n hole of %d\n",i,j,p[i],copy[j]);
	                p[i]=10000;
	                break;
	            }
	        }
		}
		for(j=0;j<m;j++)
		{
			if(p[j]!=10000)
	        {
				printf("The Process %d is not allocated\n",j);
	        }
		}
	}
	void worst()
	{
		int i,k;
			int copy[20];
		for(i=0;i<n;i++)
		{
		    copy[i] = a[i];
		}
		for(i=0;i<m;i++)
		{
	   	    int small = -1;
	   	    int index =n-1;
	   	    for(k = 0; k<n; k++)
	   	    {
	   	    	if(copy[k] > small && p[i] <= copy[k])
				{
					small = copy[k];
					index = k;   	
				}	
			}
	        if(p[i]<=copy[index])
	        {
	           	copy[index] = copy[index] - p[i];
	           	printf("The Process %d allocated to %dth block occupying %d space n hole of %d\n",i,index,p[i],copy[index]);
	            p[i]=10000;
	            break;
	        }
	        }
		for(k=0;k<m;k++)
		{
			if(p[k]!=10000)
	        {
				printf("The Process %d is not allocated\n",k);
	        }
		}
	}
	void best()
	{
		int i,k;
		int copy[20];
		for(i=0;i<n;i++)
		{
		    copy[i] = a[i];
		}
		for(i=0;i<m;i++)
		{
	   	    int small = 999;
	   	    int index =n-1;
	   	    for(k = 0; k<n; k++)
	   	    {
	   	    	if(copy[k] < small && p[i] <= copy[k])
				{
					small = copy[k];
					index = k;   	
				}	
			}
	        if(p[i]<=copy[index])
	        {
	           	copy[index] = copy[index] - p[i];
	           	printf("The Process %d allocated to %dth block occupying %d space n hole of %d\n",i,index,p[i],copy[index]);
	            p[i]=10000;
	            break;
	        }
	    }
	
		int j;
		for(j=0;j<m;j++)
		{
			if(p[j]!=10000)
	        {
				printf("The Process %d is not allocated\n",j);
	        }
		}
	}
	int main()
	{
		int i,j,ch;
		printf("Enter no of Blocks.\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		    printf("Enter the %dst Block size:",i);
	        scanf("%d",&a[i]);
		}
		printf("Enter no of Process.\n");
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
	        printf("Enter the size of %dst Process:",i);
	        scanf("%d",&p[i]);
		}	
		printf("want to implement 1) First-Fit 2)Worst-Fit 3) Best-Fit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				first();
				break;
			case 2:
				worst();
				break;
			case 3:
				best();
				break;	
			
		}
	    return 0;
	}
	
