#include<stdio.h>
int main()
{
	int n, i,time =0, count =0, small = 0;
	scanf("%d",&n);
	int at[n],bt[n], rt[n+1], wait[n],turn[n], avgwait=0, avgturn=0, remain = n;
	for(i= 0; i<n; i++)
	{
		scanf("%d%d",&at[i], &bt[i]);
		rt[i] = bt[i];
	}
	rt[n] = 99999;
	for( time = 0; remain != 0; )
	{
		small = n;
		for(i = 0; i<n; i++){			
			if(at[i] >=0 && at[i] <= time && rt[small] > rt[i]  && rt[i] > 0)
			{
				small = i;
				
			}
		}
	//	printf("small %d\n ",small);
		time += rt[small];
		rt[small] = 0;
		
		remain--;
		turn[small] = time-at[small];
		wait[small] = time-at[small]-bt[small];
		avgwait += wait[small];
		avgturn += turn[small];
		printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
    	printf("P[%d]\t|\t%d\t|\t%d\n",small+1,turn[small],wait[small]); 
	}
	printf("\nAverage Waiting Time= %f\n",avgwait*1.0/n); 
  	printf("Avg Turnaround Time = %f",avgturn*1.0/n); 
 	return 0;
}
