#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct thread_data
{
int tid;
int priority_value;
char msg[5];
};
struct thread_data th[4];
void * Print(void *ts) {
	struct thread_data * data=(struct thread_data *)ts;
	printf("thread id#%d priority %d msg is %s\n",data->tid,data->priority_value,data->msg);
	pthread_exit(NULL);
}

int main (int argc, char *argv[])
{
	pthread_t threads[5];

	int  rc;
	 int t,p;

	for(t=0;t<4;t++) {
	th[t].tid=t;
	scanf("%d",&p);

	scanf("%s",th[t].msg);
	th[t].priority_value=p;
	

	}

for(t=0; t<4; t++){

	printf("In main: creating thread %d\n", t);
	rc = pthread_create(&threads[t], NULL, Print,(void *)&th[t]);
	if (rc){
	printf("ERROR; return code from pthread_create() is %d\n", rc);
	exit(-1);
	}
}
/* Last thing that main() should do */
pthread_exit(NULL);
}
