#include<stdio.h>

void sort(int p[],int at[],int bt[],int pr[],int n)
{
	int i, j,temp;
	for(i = 0; i<n-1; i++)
	{
		for(j = i+1; j<n; j++)
		{
			if(at[i] > at[j] ){
				temp = at[j];
				at[j] = at[i] ;
				at[i] = temp;
				
				temp = bt[j];
				bt[j] = bt[i] ;
				bt[i] = temp;
				
				temp = p[j];
				p[j] = p[i] ;	
				p[i] = temp;
			
				
			}
		}
	}
}

int main()
{
	int n, i,time =0, count =0, small = 0;
	scanf("%d",&n);
	int at[n],bt[n], rt[n+1],p[n], pr[n+1], wait[n],turn[n], avgwait=0, avgturn=0, remain = n;
	for(i= 0; i<n; i++)
	{
		scanf("%d%d%d",&at[i], &bt[i],&pr[i]);
		rt[i] = bt[i];
		p[i] = i;
	}
	sort(p,at,bt,pr,n);
	for(i= 0; i<n; i++)
	{
		rt[i] = bt[i];
	}
	rt[n]= 9999;
	pr[n] = 999;
	
	for( time = at[0]; remain!=0; time++)
	{
		small = n;
		for(i=0; i<n; i++)
		{
			if(at[i] >=0 && at[i] <= time && pr[small] > pr[i] && rt[i] > 0)
			{
				small = i;
			}
		}
		rt[small]--;
		if(rt[small] == 0)
		{
			remain--;
			turn[small] = time + 1 - at[small];
			wait[small] = time + 1 - at[small] - bt[small];
			avgwait += wait[small];
			avgturn += turn[small];
			printf("\n\nProcess\t|Turnaround Time|Waiting Time|Priority\n\n"); 
      		printf("P[%d]\t|\t%d\t|\t%d|\t%d\n",p[small],turn[small],wait[small],pr[small]); 
		}
		
		
	}
	printf("\nAverage Waiting Time= %f\n",avgwait*1.0/n); 
  	printf("Avg Turnaround Time = %f",avgturn*1.0/n); 
 	return 0;
}
