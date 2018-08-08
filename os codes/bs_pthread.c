#include<stdio.h>
#include<pthread.h>
#define NO_THREAD 5
struct node{
	int arr[100][100];
	int brr[100][100];
	int crr[100][100];
	int n;
};
int off = 0;
void *matrix_mult(void * arg)
{
	struct node * p = (struct node *)arg;
	int i, j,k,m = (p -> n )/NO_THREAD ,strt,end;
	strt = off*m;
	end = strt +m;
	for(i = strt; i< end; i++)
	{
		for(j = 0; j<p->n; j++)
		{
			for(k = 0; k< p->n; k++)
			{
				p->crr[i][k] += p->arr[i][j] * p->brr[j][k];
			}
		}
	}
	off += 1;
	pthread_exit(0);
}
int main()
{
	struct node nn;
	int i ,j, n;
	scanf("%d",&nn.n);
	for(i =0; i<nn.n; i++)
	{
		for(j= 0; j<nn.n; j++)
		{
			nn.arr[i][j]= 1;
			nn.brr[i][j] = 1;
		}
		
		
	}
	pthread_t pth[NO_THREAD];
	
	for(i = 0; i< NO_THREAD; i++)
	{
		j = pthread_create(&pth[i], NULL, (void * )matrix_mult, (void *) &nn);
	}
	for(i = 0; i< NO_THREAD; i++)
	{
		pthread_join(pth[i], NULL);
	}
	for(i =0; i<nn.n; i++)
	{
		for(j= 0; j<nn.n; j++)
		{
			printf("%d  ",nn.crr[i][j]);
		}
		printf("\n");
		
		
	}
	pthread_exit(0);
	return 0;
}
