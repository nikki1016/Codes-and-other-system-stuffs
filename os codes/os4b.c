#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
typedef struct
{
	double *a;
	double *b;
	double sum;
	
}dot;
#define NUMTHRDS 4
#define VECLEN 1000
dot d;
pthread_t callThd[NUMTHRDS];
pthread_mutex_t mutexsum; 

void *dotprod(void *arg) {
	int i,start,end,len;
	long offset;
	double mysum,*x,*y;
offset=(long)arg;
len=250;
start=offset*len;
end=start+len;
x=d.a;
y=d.b;
mysum = 0;
for (i=start; i<end ; i++)
{
mysum += (x[i] * y[i]);
}
pthread_mutex_lock(&mutexsum);
d.sum+=mysum;
pthread_mutex_unlock(&mutexsum);
pthread_exit((void*) 0);
}

int main (int argc, char *argv[])
{
long i;
double *a, *b;
void *status;
pthread_attr_t attr;
/* Assign storage and initialize values */
a = (double*) malloc (NUMTHRDS*VECLEN*sizeof(double));
b = (double*) malloc (NUMTHRDS*VECLEN*sizeof(double));
for (i=0; i<VECLEN*NUMTHRDS; i++)
{
a[i]=1.0;
b[i]=a[i];
}

	d.a = a;
	d.b = b; 
	d.sum=0;
	pthread_mutex_init(&mutexsum, NULL);

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	for(i=0; i<NUMTHRDS; i++)
	{

	pthread_create(&callThd[i], &attr, dotprod, (void *)i);
	}
	pthread_attr_destroy(&attr);
	/* Wait on the other threads */
	for(i=0; i<NUMTHRDS; i++)
	{
	pthread_join(callThd[i], &status);
	}
	/* After joining, print out the results and cleanup */
	printf ("Sum = %f \n", d.sum);
	free (a);
	free (b);
	pthread_mutex_destroy(&mutexsum);
	pthread_exit(NULL);
}
