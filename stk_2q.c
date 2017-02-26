#include<stdio.h>
#include<stdlib.h>
#define MAX 10
void enqueue(int arr[],int *front,int *rear,int item){
	if(*rear == MAX-1){
		printf("overflow\n");
		return;
	}
	else if(*front == -1){
		(*front) = 0;
	}
	(*rear)++;
	arr[*rear] = item;
}
void push(int arr[],int *front,int *rear,int item){
	enqueue(arr,front,rear,item);
}
int dequeue(int arr[],int *front , int *rear){
	if(*front == -1){
		printf("underflow\n");
		return;
	}
	int i;
	if(*front == *rear){
		i = arr[*front];
		(*front) = -1;
		(*rear) = -1;
		return i;
	}
	else{
		i = arr[*front];
		(*front)++;
		return i;
	}
}
void pop(int q1[],int q2[],int *front1,int *rear1,int *front2,int *rear2){
	int i,k;
	while( *front1 != *rear1 || *front2 != *rear2){
		for(i = *front1; i< *rear1; i++) {
			k = dequeue(q1,front1,rear1);
			enqueue(q2,front2,rear2,k);
		}
		k = dequeue(q1,front1,rear1);
		printf("%d ",k);
		for(i = *front2; i<*rear2; i++) {
			k = dequeue(q2,front2,rear2);
			enqueue(q1,front1,rear1,k);
		}
		k = dequeue(q2,front2,rear2);
		printf("%d ",k);
		if(*front1 == *rear1 && *front1 != -1){
			k = dequeue(q1,front1,rear1);
			printf("%d ", k);
		}
		else if(*front2 == *rear2 && *front2 != -1){
			k = dequeue(q2,front2,rear2);
			printf("%d ",k);
		}
	}
	printf("\n");
}
void display(int arr[],int *front,int *rear){
	if(*front == -1){
		printf("underflow\n");
		return;
	}
	int i;
	for( i = *front; i <= *rear; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

int main(){
	int q1[MAX],q2[MAX],n,i,j,k,stk[MAX],top =-1;
	int front1= -1,rear1 = -1,front2 = -1,rear2 = -1,ch;
	while(1){
		scanf("%d",&ch);
		switch(ch){
			case 1:
				scanf("%d",&k);
				push(q1,&front1,&rear1,k);
				break;
			case 2:
				k = pop(q1,q2,&front1,&rear1,&front2,&rear2);
				if(k != -1)
				printf("first is at element %d\n",k);
				break;
			case 3:
				display(q1,&front1,&rear1);
				break;
			case 4:
				display(q2,&front2,&rear2);
				break;
			default:
				exit(0);
		}
	}
	return 0;
}
	
