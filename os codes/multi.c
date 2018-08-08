#include<stdio.h>
int main()
{
	int n;
	printf("no. ofprocesses: ");
	scanf("%d",&n);
	int p[n], wait[n], turn[n], su[n], bt[n], i, j, temp, avgwait = 0, avgturn = 0;
	for(i = 0; i<n; i++)
	{
		printf("burst time and System/ User process(0/1) of process %d : ",i);
		scanf("%d%d",&bt[i],&su[i]);
		p[i] = i;
	}
	for(i = 0; i<n; i++)
	{
		for(j = i+1; j<n; j++)
		{
			if(su[i] > su[j] || (su[i] == su[j] && bt[i] < bt[j] ))
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				
				temp = bt[i];
				bt[i] = bt[j];
				bt[j] = temp;
				
				temp =  su[i];
				su[i] = su[j];
				su[j] = temp;
				
			}
		}
	}
	wait[0]  = 0;
	avgturn = turn[0] = bt[0];
	printf("\nPROCESS\t\t SYSTEM/USER PROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
	for(i = 0; i<n; i++)
	{
		if(i != 0)
		{
			wait[i] = wait[i-1] +bt[i-1];
			turn[i] = wait[i] + bt[i];
			avgwait += wait[i];
			avgturn += turn[i];
		}
		
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",p[i],su[i],bt[i],wait[i],turn[i]);
	}
	printf("\nAverage Waiting Time is---%f",avgwait*1.0/n);
	printf("\nAverage Turnaround Time is---%f",avgturn*1.0/n);
	return 0;
	
}
