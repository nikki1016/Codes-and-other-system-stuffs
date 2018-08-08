#include <pthread.h>
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>
void *Sum(void *thid) {
	long tid;
	tid=(long)thid;
	double i;
	double sum=0.0;
	for(i=1;i<=10000;i++) {
		sum=sum+sin((double)i);
	}
	printf("%lf is sum\n",sum);
	pthread_exit(NULL);
}

int main() {
	pthread_t threads[32];
	long t;
	double rc;
	for(t=0;t<32;t++) {
		printf("In main: creating thread %ld\n", t);
		rc=pthread_create(&threads[t],NULL,Sum,(void *)t);
		//sleep(4);
	}
	for(t=0;t<32;t++) {
		printf("In main: joining thread %ld\n", t);
		pthread_join(threads[t],NULL);
	//	sleep(4);
	}
	
pthread_exit(NULL);
}
