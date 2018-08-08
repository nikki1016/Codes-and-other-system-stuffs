#include<stdio.h>
struct node{
//	int arr[20];
	int value[20];
	int ref[20];
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

int sort()
{
	int i=0;
	while(1)
	{
		if(frame.ref[i] == 1)
		{
			frame.ref[i] = 0;
			i = (i+1)%frame_size;
		}
		else if(frame.ref[i] == 0)
		{
			return i;
		}
	}
}

void replace(int a)
{
	int i,j=0;
	i =sort();
	printf("repalce %d by %d\n",frame.value[i],a);
	frame.value[i] = a;
	frame.ref[i]= 1;
}
 
void print()
{
	int i;
	for( i = 0; i<frame_size; i++)
	{
		printf("%d ",frame.value[i]);
	}
	printf("\n");
	for( i = 0; i<frame_size; i++)
	{
		printf("%d ",frame.ref[i]);
	}
	printf("\n");
}

int main()
{
	int i, p_miss = 0, j = 0,k = 0;
	printf("enter total pages : ");
	scanf("%d",&n);
	for( i =0; i<n; i++)
	{
		scanf("%d",&array.value[i]);
	//	array.arr[i] = i;
		frame.ref[i] = 0;
		frame.value[i] =  -1;
		
	}
	printf("enter frame size : ");
	scanf("%d",&frame_size);
	for(i = 0; i < n; i++)
	{
		if((k=search(array.value[i])) != -1)
		{
			(frame.ref[k]) = 1;
		//	printf("%d ref %d  %d\n",array.value[i],frame.ref[k],frame.value[k]);
			print();
		}
		else if( j < frame_size && search(array.value[i]) == -1)
		{
			frame.value[j] = array.value[i];
		//	frame.arr[j] = array.arr[i];
			frame.ref[j] = 1;
			j++;
			p_miss++;
			print();
		}
		else if(search(array.value[i]) == -1)
		{
			p_miss++;
			replace(array.value[i]);
			print();
		}
	}
	printf("%d are page_miss\n",p_miss);
	return 0;
}
	

