#include<stdio.h>
int arr[30];
int n,p;

void fcfs()
{
	int i,seek_time = 0;
	seek_time = p - arr[0];
	if(seek_time < 0)
	{
		seek_time = -seek_time;
	}
	for(i = 1; i<n;i++)
	{
		if(arr[i] > arr[i-1])
		{
			seek_time += arr[i] - arr[i-1];
		}
		else seek_time += arr[i-1] - arr[i];
	}
	printf("%d is fcfs seek time\n",seek_time);
}

int sort(int val,int bit[])
{
	int brr[30],i,j, temp;
	for(i = 0; i<n;i++)
	{
		if(arr[i] != val && bit[i]!=1)
		{
			if(val > arr[i])
				brr[i] = val - arr[i];
			else brr[i] = arr[i] - val;
			
		}
		else brr[i] = 999;
	}
	int small =9999, index = n;
	for(i = 0; i<n ; i++)
	{
		if(brr[i] < small )
		{
			small = brr[i];
			index = i;
		}
	}
	return index;
}
void sstf()
{
	int brr[30]={0},crr[30] ,i,seek_time = 0,j=p, k=p;
	for(i = 0; i<n;i++)
	{
		k = sort(j,brr);
		if(arr[k] > j)
		{
			seek_time += arr[k] - j;
		}
		
		else seek_time += j - arr[k];
		brr[k]=1;
		j=arr[k];
		crr[i] = k;
		printf("%d ",crr[i]);
	}
	printf("\n%d is sstf seek time\n",seek_time);
}

void scan()
{
	int brr[30]={0},crr[30] ,i,seek_time = 0,j=p,temp, cnt=0;
	for(i = 0; i<n ; i++)
	{
		crr[i] = arr[i];
	}
	for(i = 0; i<n-1; i++)
	{
		for(j = i+1; j<n; j++)
		{
			if(crr[i] >crr[j])
			{
				temp = crr[i];
				crr[i] = crr[j];
				crr[j] = temp;
			}
		}
	}
	for(i = 0; i<n;i++)
	{
		if(crr[i] < p && i==0)
		{
			seek_time += crr[i];
		}
		else if( crr[i] < p)
		{
			seek_time += crr[i] - crr[i-1];
		}
		else if(crr[i] > p && cnt ==0  && i ==0)
		{
			
			seek_time += crr[i];
			cnt =1;
		}
		else if(crr[i] > p && cnt ==0 )
		{
			seek_time += p - crr[i-1];
			seek_time += crr[i];
			cnt =1;
		}
		else 
		{
			seek_time += crr[i] - crr[i-1];
		}
		//brr[i] = crr[i];
		printf("%d ",crr[i]);
	}
	printf("\n%d is scan seek time\n",seek_time);
	
}
void scan_proper()
{
	int brr[30]={0},crr[30] ,i,seek_time = 0,j=p,k,temp;
	for(i = 0; i<n ; i++)
	{
		crr[i] = arr[i];
	}
	
	for(i = 0; i<n-1; i++)
	{
		for(j = i+1; j<n; j++)
		{
			if(crr[i] >crr[j])
			{
				temp = crr[i];
				crr[i] = crr[j];
				crr[j] = temp;
			}
		}
	}
	for(i = 0; i<n ; i++)
	{
		if(crr[i] > p)
			break;			
	}
	if(i)	
		k=i-1;
	else k = 0;
	j=k;
//	printf("%d k \n",k);
	for(i = 0; i<n;i++)
	{
		if( crr[k] < p && k == j)
		{
			seek_time += p - crr[k];
			k--;
		}
		else if(crr[k] > p && k==0)
		{
			k = n-2;
			seek_time +=  crr[k+1]- crr[k];
			k--;
		}
		else  if( crr[k] < p)
		{
			seek_time += crr[k+1] - crr[k];
			k--;
			if(k == -1){
				seek_time += crr[0] ;
				k = j+1;
				seek_time += crr[k] ;
			}
				
		}
		else  if( crr[k] > p)
		{
			seek_time += crr[k+1] - crr[k];
			k++;
			if(k == n-1)
				break;
		}
	
		//brr[i] = crr[i];
		//printf("%d ",crr[i]);
	}
	printf("\n%d is scanproper seek time\n",seek_time);
	
}



void cscan()
{
	int brr[30]={0},crr[30] ,i,seek_time = 0,j=p,k,temp;
	for(i = 0; i<n ; i++)
	{
		crr[i] = arr[i];
	}
	crr[n]=199;
	for(i = 0; i<n-1; i++)
	{
		for(j = i+1; j<n; j++)
		{
			if(crr[i] >crr[j])
			{
				temp = crr[i];
				crr[i] = crr[j];
				crr[j] = temp;
			}
		}
	}
	for(i = 0; i<n ; i++)
	{
		if(crr[i] > p)
			break;			
	}
	k=i-1;
	j=k;
//	printf("%d k \n",k);
	for(i = 0; i<n+1;i++)
	{
		if(k==-1)
		{
			seek_time += crr[0];
			k=n-1;
		}
		else if( crr[k] < p && k == j)
		{
			seek_time += p - crr[k];
			k--;
		}
		else if(crr[k] > p && k==0)
		{
			k = n-1;
			seek_time +=  crr[k+1]- crr[k];
			k--;
		}
		else // if( crr[k] < p)
		{
			seek_time += crr[k+1] - crr[k];
			k--;
		}
	
		//brr[i] = crr[i];
		//printf("%d ",crr[i]);
	}
	printf("\n%d is cscan seek time\n",seek_time);
	
}
void look()
{
	int brr[30]={0},crr[30] ,i,seek_time = 0,j=p,temp, cnt=0;
	for(i = 0; i<n ; i++)
	{
		crr[i] = arr[i];
	}
	for(i = 0; i<n-1; i++)
	{
		for(j = i+1; j<n; j++)
		{
			if(crr[i] >crr[j])
			{
				temp = crr[i];
				crr[i] = crr[j];
				crr[j] = temp;
			}
		}
	}
	for(i = 0; i<n;i++)
	{
		if(crr[i] < p && i==0)
		{
			//seek_time += crr[i];
		}
		else if( crr[i] < p)
		{
			seek_time += crr[i] - crr[i-1];
		}
		else if(crr[i] > p && cnt ==0  && i ==0)
		{
			
			seek_time += crr[i];
			cnt =1;
		}
		else if(crr[i] > p && cnt ==0 )
		{
			seek_time += p - crr[i-1] ;
			seek_time += crr[i] - crr[0];
			cnt =1;
		}
		else 
		{
			seek_time += crr[i] - crr[i-1];
		}
		//brr[i] = crr[i];
	//	printf("%d ",crr[i]);
	}
	printf("\n%d is look seek time\n",seek_time);
	
}
void look_proper()
{
	int brr[30]={0},crr[30] ,i,seek_time = 0,j=p,k,temp;
	for(i = 0; i<n ; i++)
	{
		crr[i] = arr[i];
	}
	
	for(i = 0; i<n-1; i++)
	{
		for(j = i+1; j<n; j++)
		{
			if(crr[i] >crr[j])
			{
				temp = crr[i];
				crr[i] = crr[j];
				crr[j] = temp;
			}
		}
	}
	for(i = 0; i<n ; i++)
	{
		if(crr[i] > p)
			break;			
	}
	if(i)	
		k=i-1;
	else k = 0;
	j=k;
//	printf("%d k \n",k);
	for(i = 0; i<n;i++)
	{
		if( crr[k] < p && k == j)
		{
			seek_time += p - crr[k];
			k--;
		}
		else if(crr[k] > p && k==0)
		{
			k = n-2;
			seek_time +=  crr[k+1]- crr[k];
			k--;
		}
		else  if( crr[k] < p)
		{
			seek_time += crr[k+1] - crr[k];
			k--;
			if(k == -1){
				k = j+1;
				seek_time += crr[k] -crr[0];
			}
				
		}
		else  if( crr[k] > p)
		{
			seek_time += crr[k+1] - crr[k];
			k++;
			if(k == n-1)
				break;
		}
	
		//brr[i] = crr[i];
		//printf("%d ",crr[i]);
	}
	printf("\n%d is lookproper seek time\n",seek_time);
	
}


void clook()
{
	int brr[30]={0},crr[30] ,i,seek_time = 0,j=p,k,temp;
	for(i = 0; i<n ; i++)
	{
		crr[i] = arr[i];
	}
	
	for(i = 0; i<n-1; i++)
	{
		for(j = i+1; j<n; j++)
		{
			if(crr[i] >crr[j])
			{
				temp = crr[i];
				crr[i] = crr[j];
				crr[j] = temp;
			}
		}
	}
	for(i = 0; i<n ; i++)
	{
		if(crr[i] > p)
			break;			
	}
	if(i)	
		k=i-1;
	else k = 0;
	j=k;
//	printf("%d k \n",k);
	for(i = 0; i<n-1;i++)
	{
		if( crr[k] < p && k == j)
		{
			seek_time += p - crr[k];
			k--;
		}
		else if(crr[k] > p && k==0)
		{
			k = n-2;
			seek_time +=  crr[k+1]- crr[k];
			k--;
		}
		else // if( crr[k] < p)
		{
			seek_time += crr[k+1] - crr[k];
			k--;
			if(k == -1)
				k = n-2;
		}
	
		//brr[i] = crr[i];
		//printf("%d ",crr[i]);
	}
	printf("\n%d is clook seek time\n",seek_time);
	
}


int main()
{
	int i;
	scanf("%d",&n);
	for(i = 0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&p);
	fcfs();
	sstf();
	scan();
	scan_proper();
	cscan();
	look();
	look_proper();
	clook();
	return 0;
}
