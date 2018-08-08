//#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
pthread_mutex_t x, wsem;
pthread_t tid[100];
int readcount = 0;


void * reader (void * param)
{
    int waittime;
    int i = (int)param;
    waittime = rand() % 5;
    printf("\n%d Reader is trying to enter",i);
    pthread_mutex_lock(&x);
    readcount++;
    if(readcount==1)
        pthread_mutex_lock(&wsem);
    printf("\n%d Reader is inside ",readcount);
    pthread_mutex_unlock(&x);
    sleep(waittime);
    pthread_mutex_lock(&x);
    readcount--;
    if(readcount==0)
        pthread_mutex_unlock(&wsem);
    pthread_mutex_unlock(&x);
    printf("\n%d Reader is Leaving",i);
}   

void * writer (void * param)
{
	 int i = (int)param;
    int waittime;
    waittime=rand() % 3;
    printf("\n%d Writer is trying to enter",i);
    pthread_mutex_lock(&wsem);
    printf("\nWrite has entered");
    sleep(waittime);
    pthread_mutex_unlock(&wsem);    
    printf("\n%d Writer is leaving",i);
    sleep(30);
    exit(0);
}

int main()
{
	pthread_mutex_init(&x,NULL);
pthread_mutex_init(&wsem,NULL);

    int n1,n2,i;    
    printf("\nEnter the no of readers: ");
    scanf("%d",&n1);
    printf("\nEnter the no of writers: ");
    scanf("%d",&n2);
    for(i=0;i<n1;i++)
        pthread_create(&tid[i],NULL,reader,(void *)i);  
        sleep(2);
    for(i=0;i<n2;i++)
        pthread_create(&tid[i],NULL,writer,(void *)i);
    sleep(30);
    exit(0);
}
