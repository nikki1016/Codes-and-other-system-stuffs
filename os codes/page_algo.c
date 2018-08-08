#include<stdio.h>
struct node{
	int val;
	int at;
	int bit;
} arr[20], frame[20];
int n, fr_sz;

int search(int a)
{
	int i;
	for(i = 0; i<fr_sz; i++)
	{
		if(frame[i].val == a)
			return i;
	}
	return -1;
}
int search_frame(int a,int index)
{
	int i;
	for(i = index; i<n; i++)
	{
		if(arr[i].val == a)
			return i;
	}
	return -1;
}
void init()
{
	int i;
	for(i=0;i<fr_sz;i++)
	{
		frame[i].at = frame[i].bit = frame[i].val = -1;
	}
	
}
void print()
{
	int i;
	for( i = 0; i<fr_sz; i++)
	{
		printf("-%d ",frame[i].val);
	}
	printf("\n");
}

void fifo()
{
	init();
	int i ,j = 0,k= 0, small = 999, pfault=0,t=0;
	for(i = 0; i<n; i++)
	{
		if(search(arr[i].val ) != -1){
			t++;
		//	continue;
		}
		else	if(j < fr_sz)
		{
			frame[j].val = arr[i].val;
			frame[j++].at= arr[i].at;
			pfault++;
		}
		else 
		{
			small = fr_sz;
			for(k = 0; k< fr_sz; k++)
			{
				if(frame[small].at > frame[k].at)
				{
					small = k;
				}
			}
			frame[small].val = arr[i].val;
			frame[small].at = arr[i].at;
			pfault++;
		}
	}
	printf("%d hits %d  page_fault in fifo\n",t,pfault);
}


void lru()
{
	init();
	int i ,j = 0,k= 0, small = 999, pfault=0;
	for(i = 0; i<n; i++)
	{
		if(k = search(arr[i].val ) != -1)
		{
			frame[k].at = arr[i].at;	
		//	continue;
		}
		else if(j < fr_sz)
		{
			frame[j].val = arr[i].val;
			frame[j++].at= arr[i].at;
			pfault++;
			print();
		}
		else 
		{
			small = fr_sz;
			for(k = 0; k< fr_sz; k++)
			{
				if(frame[small].at > frame[k].at)
				{
					small = k;
				}
			}
			printf("%d ",frame[small].val);
			frame[small].val = arr[i].val;
			frame[small].at = arr[i].at;
			pfault++;
			print();
		}
	}
	printf("%d page_fault in lru\n",pfault);
}
void optimal()
{
	init();
	int i ,j = 0,k= 0, p, cnt=0, pfault=0;
	for(i = 0; i<n; i++)
	{
		if(search(arr[i].val ) != -1){
			//continue;
		}
		else if(j < fr_sz)
		{
			frame[j].val = arr[i].val;
			frame[j++].at= arr[i].at;
			pfault++;
		}
		else 
		{
			for(k = i+1; k< n; k++)
			{
				p = search_frame(arr[k].val,i+1);
				if(p != -1 )
				{
					cnt++;
					if(cnt == fr_sz)
						break;
				}
			}
			frame[p].val = arr[i].val;
			frame[p].at = arr[i].at;
			pfault++;
		}
	}
	printf("%d page_fault in optimal\n",pfault);
}
void lfu()
{
	init();
	int i ,j = 0,k= 0, small = 999, pfault=0;
	for(i = 0; i<n; i++)
	{
		if(k = search(arr[i].val ) != -1)
		{
			frame[k].bit++;	
		//	continue;
		}
		else if(j < fr_sz)
		{
			frame[j].val = arr[i].val;
			frame[j].at= arr[i].at;
			frame[j++].bit = 1;
			pfault++;
		}
		else 
		{
			small = fr_sz;
			for(k = 0; k< fr_sz; k++)
			{
				if(frame[small].bit > frame[k].bit || ( frame[small].bit == frame[k].bit && frame[small].at >= frame[k].at))
				{
					small = k;
				}
			}
			frame[small].val = arr[i].val;
			frame[small].at = arr[i].at;
			frame[small].bit =1;
			pfault++;
		}
	}
	printf("%d page_fault in lfu\n",pfault);
}
void mfu()
{
	init();
	int i ,j = 0,k= 0, small = 999, pfault=0;
	for(i = 0; i<n; i++)
	{
		if(k = search(arr[i].val ) != -1)
		{
			frame[k].bit++;	
		//	continue;
		}
		else if(j < fr_sz)
		{
			frame[j].val = arr[i].val;
			frame[j].at= arr[i].at;
			frame[j++].bit = 1;
			pfault++;
		}
		else 
		{
			frame[fr_sz].bit = -1;
			small = fr_sz;
			for(k = 0; k< fr_sz; k++)
			{
				if(frame[small].bit < frame[k].bit || ( frame[small].bit == frame[k].bit && frame[small].at >= frame[k].at))
				{
					small = k;
				}
			}
			frame[small].val = arr[i].val;
			frame[small].at = arr[i].at;
			frame[small].bit =1;
			pfault++;
		}
	}
	printf("%d page_fault in mfu\n",pfault);
}
void second()
{
	init();
	int i ,j = 0,k= 0, small = 999, pfault=0;
	for(i = 0; i<n; i++)
	{
		if(k = search(arr[i].val ) != -1)
		{
			frame[k].bit =1;
			continue;
		}
		if(j < fr_sz)
		{
			frame[j].val = arr[i].val;
			frame[j].at= arr[i].at;
			frame[j++].bit = 0;
			pfault++;
		}
		else 
		{
			small = n;
			for(k = 0; k< fr_sz; k++)
			{
				if(frame[k].bit == 1)
				{
					frame[k].bit =0;
					continue;
				}
				if(frame[small].at > frame[i].at)
				{
					small = i;
				}
			}
			frame[small].val = arr[i].val;
			frame[small].at = arr[i].at;
			frame[small].bit =0;
			pfault++;
		}
	}
	printf("%d page_fault in second\n",pfault);
}
void clock()
{
	init();
	int i ,j = 0,k= 0, small = 999, pfault=0, p =0;
	for(i = 0; i<n; i++)
	{
		if(k = search(arr[i].val ) != -1)
		{
			frame[k].bit =1;
			continue;
		}
		else if(j < fr_sz)
		{
			frame[j].val = arr[i].val;
			frame[j].at= arr[i].at;
			frame[j++].bit = 0;
			p = j % fr_sz;
			pfault++;
		}
		else 
		{
			small = n;
			for(k = 0; k< fr_sz; k++)
			{
				if(frame[p].bit == 1)
				{
					frame[p].bit =0;
					p= (p++)%fr_sz;
				//	continue;
				}
				else
				{		
					frame[p].val = arr[i].val;
					frame[p].at = arr[i].at;
					frame[p].bit =0;
					p= (p++)%fr_sz;
					pfault++;
					break;
				}
			}
		}
	}
	printf("%d page_fault in clock\n",pfault);
}


int main()
{
	scanf("%d",&n);
	int i;
	for(i = 0; i <n; i++)
	{
		scanf("%d",&arr[i].val);
		arr[i].at = i;
		
	}
//	arr[i].at = arr[i].val = 999;
	scanf("%d",&fr_sz);
	frame[fr_sz].at = frame[fr_sz].val =frame[fr_sz].bit = 999;
	fifo();
	lru();
	optimal();
	lfu();
	mfu();
	second();
	clock();
	return 0;
}
