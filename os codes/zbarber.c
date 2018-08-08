#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define seats 6
void *customerMaker();
void *barberShop();
void *waitingRoom();
void checkQueue();
pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;
int returnTime=5,current=0;
int main()
{ 
	pthread_t barber,customerM;
	pthread_create(&customerM,0,customerMaker,NULL);
	pthread_create(&barber,0,barberShop,NULL);
	while(1);
} 
void *customerMaker()
{ 
	int i=0;
	pthread_t customer[seats];
	while(i<(seats))
	{ 
		i++;
		sleep(1);
		pthread_create(&customer[seats],0,waitingRoom,NULL);
	} 
} 
void *waitingRoom()
{ 
	pthread_mutex_lock(&queue_mutex);
	checkQueue();
	sleep(returnTime);
	waitingRoom();
} 
void *barberShop()
{
	while(1)
	{ 
		if(current==0)
		{ 
			printf("The shop is empty, barber is sleeping.\n");
			printf("Customer has arrived, customer wakes him.\n");
			printf("Barber wakes up.\n");
			current++;
		} 
		else
		{ 
			printf("Barber begins cutting hair.\n");
			sleep(1);
			current--; 
			printf("Hair cut complete, customer leavingstore.\n");
		} 

	} 

} 
void checkQueue()
{     
	current++;
	printf("\tCustomer has arrived in the waiting room.\t\t%d Customers in store.\n",current);
	printf("\t\tCustomer checking chairs.\n");
	if(current<seats)
	{
		printf("\t\tCustomer takes a seat.\n");
		pthread_mutex_unlock(&queue_mutex);
		return;
	} 
	if(current>=seats)
	{ 
		printf("\t\tAll chairs full, leaving store.\n");
		current--; 
		pthread_mutex_unlock(&queue_mutex);
		return;
	} 
}
