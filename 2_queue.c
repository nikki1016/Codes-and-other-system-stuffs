#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void enqueue1(int arr[],int item,int *front1,int *rear1,int *front2,int *rear2);
void dequeue1(int arr[],int *front1,int *rear1,int *front2,int *rear2);
void display1(int arr[],int *front1,int *rear1,int *front2,int *rear2);
int size1(int arr[],int *front1,int *rear1,int *front2,int *rear2);

void enqueue2(int arr[],int item,int *front1,int *rear1,int *front2,int *rear2);
void dequeue2(int arr[],int *front1,int *rear1,int *front2,int *rear2);
void display2(int arr[],int *front1,int *rear1,int *front2,int *rear2);
int size2(int arr[],int *front1,int *rear1,int *front2,int *rear2);

int main(){
	int arr[MAX],front1 = -1, rear1= -1,front2= MAX, rear2= MAX,ch,k;
	printf("1.enqueue_q1\t2.enqueue_q2\t3.dequeue_q1\t4.dequeue_q2\t5.size_q1\t6.size_q2\t7.display_q1\t8.display_q2\n");
	while(1){
		scanf("%d",&ch);
		switch(ch){
			case 1:
				scanf("%d",&k);
				enqueue1(arr,k,&front1,&rear1,&front2,&rear2);
				break;
			case 2:
				scanf("%d",&k);
				enqueue2(arr,k,&front1,&rear1,&front2,&rear2);
				break;
			case 3:
				dequeue1(arr,&front1,&rear1,&front2,&rear2);
				break;
			case 4:
				dequeue2(arr,&front1,&rear1,&front2,&rear2);
				break;
			case 5:
				k = size1(arr,&front1,&rear1,&front2,&rear2);
				printf("%d size of q1\n",k);
				break;
			case 6:
				k = size2(arr,&front1,&rear1,&front2,&rear2);
				printf("%d size of q2\n",k);
				break;
			case 7:
				display1(arr,&front1,&rear1,&front2,&rear2);
				break;
			case 8:
				display2(arr,&front1,&rear1,&front2,&rear2);
				break;
			default:
				exit(0);
		}
	}
	return 0;
}

void enqueue1(int arr[],int item,int *front1,int *rear1,int *front2,int *rear2){
	 if(*front1 == -1){
		*front1 =0;
		(*rear1)++;
	}
	else if(*rear1 + 1 == *rear2 && *front1 == 0){
		printf("2 queues overflow\n");
		return;
	}
	else if(*rear1 + 1 == *rear2 && *front1 != 0){
		*rear1 = 0;
	}
	else (*rear1)++;
	arr[*rear1] = item;
}
void dequeue1(int arr[],int *front1,int *rear1,int *front2,int *rear2){
	if(*front1 == -1 ){
		printf("queue 1 underflow\n");
		return;
	}
	int item;
	if(*front1 == *rear1){
		item = arr[*front1];
		*front1 = -1;
		*rear1 = -1;
		printf("%d is dequeued from 1q\n",item);
	}
	else if(*front1 == *rear2 - 1){
		item = arr[*front1];
		*front1 = 0;
		printf("%d is dequeued from 1q\n",item);
	}
	else{
		item = arr[*front1];
		(*front1)++;
		printf("%d is dequeued from 1q\n",item);
	}
}
void display1(int arr[],int *front1,int *rear1,int *front2,int *rear2){
	int i;
	if(*front1 == -1){
		printf("queue 1 underflow\n");
		return;
	}
	if(*front1 <= *rear1){
		for(i = *front1; i<=*rear1; i++)
			printf("%d ",arr[i]);
	}
	else{
		for(i = *front1; i < *rear2; i++)
			printf("%d ",arr[i]);
		for( i =0; i<=*rear1; i++)
			printf("%d ",arr[i]);
	}
}
int size1(int arr[],int *front1,int *rear1,int *front2,int *rear2){
	int length=0,i;
	if(*front1 == -1){
		length = 0;
	}
	if(*front1 <= *rear1){
		for(i = *front1; i<=*rear1; i++)
			length++;
	}
	else{
		for(i = *front1; i < *rear2; i++)
			length++;
		for( i =0; i<=*rear1; i++)
			length++;
	}
	return length;
}

void enqueue2(int arr[],int item,int *front1,int *rear1,int *front2,int *rear2){
	 if(*front2 == MAX){
		*front2 = MAX-1;
		(*rear2) = MAX-1 ;
	}
	else if(*rear1 + 1 == *rear2 && *front2 == MAX-1){
		printf("2 queues overflow\n");
		return;
	}
	else if(*rear1 + 1 == *rear2 && *front2 != MAX-1){
		*rear2 = MAX -1;
	}
	else (*rear2)--;
	arr[*rear2] = item;
}

void dequeue2(int arr[],int *front1,int *rear1,int *front2,int *rear2){
	if(*front2 == MAX ){
		printf("queue 2 underflow\n");
		return;
	}
	int item;
	if(*front2 == *rear2){
		item = arr[*front2];
		*front2 = MAX;
		*rear2 = MAX;
		printf("%d is dequeued from 2q\n",item);
	}
	else if(*front2 == *rear1 + 1){
		item = arr[*front2];
		*front2 = MAX-1;
		printf("%d is dequeued from 2q\n",item);
	}
	else{
		item = arr[*front2];
		(*front2)--;
		printf("%d is dequeued from 2q\n",item);
	}
}

void display2(int arr[],int *front1,int *rear1,int *front2,int *rear2){
	int i;
	if(*front2 == MAX){
		printf("queue 2 underflow\n");
		return;
	}
	if(*front2 == *rear2)
		printf("%d ",arr[*front2]);
	else if(*front2 < *rear2){
		for(i = *front2; i > *rear1 ; i--)
			printf("%d ",arr[i]);
		for(i = MAX-1; i >=*rear2; i--)
			printf("%d ",arr[i]);
	}
	else{
		for(i = *front2; i >= *rear2; i--)
			printf("%d ",arr[i]);
	}
}

int size2(int arr[],int *front1,int *rear1,int *front2,int *rear2){
	int length=0,i;
	if(*front2 == MAX){
		length = 0;
	}
	if(*front2 <= *rear2){
		for(i = *front2; i >=*rear1 + 1; i--)
			length++;
		for(i = MAX-1; i >= *rear2; i--)
			length++;
	}
	else{
		for(i = *front2; i >= *rear2; i--)
			length++;
	}
	return length;
}

