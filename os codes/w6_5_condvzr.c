#include<pthread.h>
#include<stdio.h>

pthread_mutex_t mutex ;
pthread_cond_t cond1 ;
pthread_cond_t cond2;
int count = 4;
void *inc_count(void * no)
{
	int i=0;
	
	while(i<10)
	{
		pthread_mutex_lock(&mutex);
		
		if(count != 0)
		{
			pthread_cond_wait(&cond1,&mutex);
			printf("thread %d count %d\n",(int) no,count);
			pthread_cond_signal(&cond2);
			pthread_mutex_unlock(&mutex);
			
		}
		else
			count++;
		i++;
	}
		pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}
void *dec_count(void * no)
{
	int i;
	for(i= 0; i<10; i++)
	{
		pthread_mutex_lock(&mutex);
	
		
		if(count== 1)
		{	
			pthread_cond_wait(&cond2,&mutex);
			printf("thread %d count %d\n",(int) no,count);
			
			break;
			pthread_exit(0);
		}
		else if(count == 0)
		{
			pthread_cond_signal(&cond1);
			pthread_mutex_unlock(&mutex);
		}
		else
			count--;
		pthread_mutex_unlock(&mutex);
		
	}
	pthread_exit(NULL);
}
int main()
{
	pthread_mutex_init(&mutex,NULL) ;
	pthread_cond_init(&cond1,NULL) ;
	pthread_cond_init(&cond2,NULL);
	pthread_t pid[2];
	int id[2], i = 1,j = 2;
	id[0] =	pthread_create(&pid[0],NULL,inc_count,(void *)i);
	id[1] =	pthread_create(&pid[1],NULL,dec_count,(void *)j);
	pthread_join(pid[0],NULL);
	pthread_join(pid[1],NULL);
	pthread_mutex_destroy(&mutex) ;
	pthread_cond_destroy(&cond1) ;
	pthread_cond_destroy(&cond2);
	return 0;

}
