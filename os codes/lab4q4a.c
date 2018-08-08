#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define ll long long int
#define VECLEN 100
int size_of_array;

typedef struct
{
    double *a;
   // double *b;
    double sum;
    int veclen;
}DATA;

pthread_t callThd[5];
pthread_mutex_t mutexsum;

DATA dstr;
void *func(void *arg)
{
    int start,end,len;
    double mysum,*x;
    x=dstr.a;
    mysum=0;
    long offset=(long)arg;
    long i;
    len=dstr.veclen;
    start=offset*len;
    end=start+len;
   // printf("%d %d\n",start,end);
    for(i=start;i<end;i++)
    {
        mysum+=x[i];
    }
    pthread_mutex_lock(&mutexsum);
    dstr.sum+=mysum;
    pthread_mutex_unlock(&mutexsum);
    pthread_exit((void *) 0);
}

int main()
{
    long i;
    double *a;
    void *status;
    pthread_attr_t attr;
    a=(double*)malloc(5*VECLEN*sizeof(double));
    for(i=0;i<5;i++)
    {
    	 a[i]=(double)(1.0+(10.0*i));
    	 printf("%lf a[%d]\n ",a[i],i);
	}
       
    dstr.veclen=VECLEN;
    dstr.a=a;
    dstr.sum=0;
    pthread_mutex_init(&mutexsum, NULL);  
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    for(i=0;i<5;i++)
    {
        pthread_create(&callThd[i], &attr, func, (void *)i);
    }
    pthread_attr_destroy(&attr);
    for(i=0; i<5; i++)
    {
        pthread_join(callThd[i], &status);
    }
    printf ("Sum = %f \n", dstr.sum);
    free (a);
    //free (b);
    pthread_mutex_destroy(&mutexsum);
    pthread_exit(NULL);
}
