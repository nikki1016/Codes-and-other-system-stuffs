#include<stdio.h>
struct node{
	int arr[20];
	int value[20];
	int count[20];
} array, frame;

int n, frame_size;
int search (int p)
{
	int i;
	for(i = 0; i< frame_size; i++)
	{
		if(p == frame.value[i])
			return i;
	}
//	printf("not found\n");
	return -1;
}

void sort()
{
	int i,j,temp;
	for(i = 0; i< frame_size-1; i++)
	{
		for(j = i+1; j<frame_size;j++)	
		{
			if(frame.count[i] < frame.count[j])
			{
				temp = frame.arr[i];
				frame.arr[i] = frame.arr[j];
				frame.arr[j] = temp;

				temp = frame.value[i];
				frame.value[i] = frame.value[j];
				frame.value[j] = temp;

				temp = frame.count[i];
				frame.count[i] = frame.count[j];
				frame.count[j] = temp;
			}
			else if(frame.count[i] == frame.count[j] && frame.arr[i] > frame.arr[j])
			{
				temp = frame.arr[i];
				frame.arr[i] = frame.arr[j];
				frame.arr[j] = temp;

				temp = frame.value[i];
				frame.value[i] = frame.value[j];
				frame.value[j] = temp;

				temp = frame.count[i];
				frame.count[i] = frame.count[j];
				frame.count[j] = temp;
			}
		}
	}
	
	
}

void replace(int a,int b)
{
	int i,j=0,small = frame.arr[0];
	sort();
	printf("repalce %d by %d\n",frame.value[0],a);
	frame.value[0] = a;
	frame.arr[0] = b;
}
 
void print()
{
	int i;
	for( i = 0; i<frame_size; i++)
	{
		printf("%d ",frame.value[i]);
	}
	printf("\n");
}

int main()
{
	int i, p_miss = 0, j = 0,k=0;
	printf("enter total pages : ");
	scanf("%d",&n);
	for( i =0; i<n; i++)
	{
		scanf("%d",&array.value[i]);
		array.arr[i] = i;
		frame.value[i] = frame.arr[i]  = frame.count[i] = 0;
	}
	printf("enter frame size : ");
	scanf("%d",&frame_size);
	for(i = 0; i < n; i++)
	{
		if(search(array.value[i]) != -1)
		{
			k = search(array.value[i]);
			frame.count[k]++;	
		}
		else if( j < frame_size)
		{
			frame.value[j] = array.value[i];
			frame.arr[j] = array.arr[i];
			j++;
			p_miss++;
			//print();
		}
		else if(search(array.value[i]) == -1)
		{
			p_miss++;
			replace(array.value[i], array.arr[i]);
			//print();
		}
	
	}
	printf("%d are page_miss\n",p_miss);
	return 0;
}
	

