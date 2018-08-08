#include<stdio.h>
struct node {
	int pid;
	int at;
	int bt;
	int bf;
	int wait;
	int turn;
	int rt;
}arr[20];

int n;
void sort()
{
	int i,j;
	struct node temp;
	for(i = 0; i<n-1;i++)
	{
		for(j =i+1; j<n; j++)
		{
			if(arr[i].at > arr[j].at)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j]= temp;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	int i,remain = n, time = 0,small;
	double  awt = 0.0, att = 0.0 ;
	for(i = 0 ;i<n; i++)
	{
		scanf("%d%d%d%d", &arr[i].pid, &arr[i].at, &arr[i].bt, &arr[i].bf);
		arr[i].wait = arr[i].turn = 0;
		arr[i].rt = arr[i].bt ;
	}
	sort();

	for(time = 0; remain != 0; )
	{
		small = 33333;
		int index=99999;
		for(i = 0; i<n; i++)
		{
			if( arr[i].at <= time && arr[i].rt >0)
			{
				index = arr[i].at;
				small =i;
				if( arr[i].bf == 1)
				{
					break;
				}
			}
		}
		if(arr[small].bf == 1)
		{
			time += arr[small].bt;
		//	arr[small].bt = 0;
			arr[small].rt = 0;
			remain--;
			arr[small].wait = time - arr[small].at- arr[small].bt;
			arr[small].turn = time - arr[small].at;
			awt += arr[small].wait ;
			att += arr[small].turn ;
			printf("%d is process with wait %d n turn is %d is completed \n",arr[small].pid, arr[small].wait,arr[small].turn);
		//	printf("awt %lf, att %lf\n", awt,att);
		}
		else 
		{
			small = j;
			time++;
			arr[small].rt--;
			j = small;
			if(arr[small].rt == 0)
			{
				remain--;
				arr[small].wait = time - arr[small].at - arr[small].bt;
				arr[small].turn = time - arr[small].at;
				awt += arr[small].wait *1.0;
				att += arr[small].turn*1.0;
				printf("%d is process with wait %d n turn is %d is completed \n",arr[small].pid,arr[small].wait,arr[small].turn);
			//	printf("awt %lf, att %lf\n", awt,att);
			}
		}
		
	}
	awt = awt/n;
	att = att/n;
	printf("%.2lf is awt n %.2lf is att\n",awt,att);
}
