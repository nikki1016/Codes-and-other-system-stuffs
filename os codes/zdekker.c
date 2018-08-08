#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int flag[10];
int turn;
int a;
void lock(int self)
{
	int i;
        flag[self]=1;
	for(i=0;i<10;i++)
	{
		if(i!=self)
		{
			turn =i;
       			while((flag[i]==1) && (turn == i));
		}
	}
}
void unlock(int self)
{
        flag[self]=0;
}
void* fnc(void  *s)
{
        int i=0;
        int self=(int *)s;
        printf("Thread %d\n",self);
        lock(self);
        printf("Critical Section %d\n",self);
        //for(i=0;i<10;i++)
        a+=10;
        unlock(self);
}
int main()
{
	int n;
	int i;
    pthread_t p[10];	
	for(i=0;i<10;i++)
		flag[i]=0;
    turn = 0;
	for(i=0;i<10;i++)
		pthread_create(&p[i],NULL,fnc,(void *)i);
	for(i=0;i<10;i++)
       		pthread_join(p[i],NULL);
        printf("%d\n",a);
        return 0;
}

