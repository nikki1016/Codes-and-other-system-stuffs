#include<stdio.h>
struct node{
	int arr[20];
	int value[20];
} array, frame;

int n, frame_size;
void sort(struct node *p)
{
	int i,j,temp;
	for(i = 0; i< frame_size-1; i++)
	{
		for(j = i+1; j<frame_size;j++)	
		{
			if(p->arr[i] < p->arr[j] && p->arr[j] != 999)
			{
				temp = p->arr[i];
				p->arr[i] = p->arr[j];
				p->arr[j] = temp;

				temp = p->value[i];
				p->value[i] = p->value[j];
				p->value[j] = temp;
			}
		}
	}
}

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
int search_array (int p,int index)
{
	int i;
	for(i = index+1 ; i< n; i++)
	{
		if(p == array.value[i])
			return i;
	}
	printf("not found\n");
	return 999;
}


void replace(int a,int b, int index)
{
	int i,j= -1,k = 0;
	struct node pp;
	for(i = 0; i<frame_size; i++)
	{
		pp.arr[i] = search_array(frame.value[i],index);
		pp.value[i] = frame.value[i];
		if(pp.arr[i] == 999)
		{
			j = i;
			printf("repalce %d by %d\n",frame.value[i],a);
			frame.value[i] = a;
			frame.arr[i] = b;
			return;
		}
	}
	sort(&pp);
	k = search(pp.value[0]);	
	printf("repalce %d by %d\n",frame.value[k],a);
	frame.value[k] = a;
	frame.arr[k] = b;
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
		frame.value[i] = frame.arr[i] = 0;
	}
	printf("enter frame size : ");
	scanf("%d",&frame_size);
	for(i = 0; i < n; i++)
	{
		if( j < frame_size && search(array.value[i]) == -1)
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
			replace(array.value[i], array.arr[i],i);
			//print();
		}
		
	}
	printf("%d are page_miss\n",p_miss);
	return 0;
}
	

