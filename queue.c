#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front = -1, rear = -1;
int queue[MAX];
void insert(int a);
int del();
int firstel();
void display();
int isempty();
int isfull();

int main(){
	int i,a;
	while(1){
		printf("enter ur choice\n");
		printf("1.insert element in queue\t2.delete 1st element\t3.display first element\t4.display d queue\t5.exit\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				printf("insert element\n");
				scanf("%d",&a);
				insert(a);
				break;
			case 2:
				a = del();
				printf("deleted element is %d\n",a);
				break;
			case 3:
				a = firstel();
				printf("first element of queue is %d\n",a);
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
		}
	}
	return 0;
}

int isempty(){
	if(front == -1){
		printf("queue underflow\n");
		return 1;
	}
	return 0;
}

int isfull() {
	if ((front ==0 && rear ==MAX-1) || front == rear+1)
		return 1;
	return 0;
}

void insert(int a) {
	if(isfull()){
		printf("overflow\n");
		return ;
	}
	if(front == -1)
		front =0;
	if(rear == MAX-1)
		rear=0;
	else 
		rear++;
	queue[rear]=a;
}

int del(){
	if(isempty()){
		printf("overflow \n");
		return -1;
	}
	int a = queue[front];
	if(front == MAX-1)
		front = 0;
	else if(front == rear){
		front =-1;
		rear = -1;
	}
	else
		front ++;
	return a;
}

int firstel() {
	if(isempty()){ 
		printf("overflow \n");          
		return -1;
	}
	return queue[front];
}

void display() {
	if(isempty()){ 
		printf("overflow \n");  
		return ;
	}
	int i=front;
	if(front <= rear){
		while(i<=rear)
			printf("%d ",queue[i++]);
		printf("\n");
	}
	else{
		while(i<MAX)
			printf("%d ",queue[i++]);
		i=0;
		while(i<=rear)
			printf("%d ",queue[i++]);
		printf("\n");
	}
}
