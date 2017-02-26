#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void push1(int stack[100],int *top1,int *top2,int data);
int pop1(int stack[100],int *top);
void display1(int stack[100],int *top);
int length1 (int stack[100],int *top);
void push2(int stack[100],int *top1,int *top2,int data);
int pop2(int stack[100],int *top);
void display2(int stack[100],int *top);
int length2 (int stack[100],int *top);

int main() {
	int top1= -1,stack[MAX],top2 =MAX;
	int i,n,data,item,choice;
	printf("enter choice:\t1.push in stk1\t2.push in stk2\t3.pop out stk1\t4.pop out stk2\t5.display stk1\t6.display stk2\t7.length of stk1\t8.length of stk2\t9.exit\n");
	while(1) {
		scanf("%d",&choice);
		switch(choice){
			case 1:
				scanf("%d",&data);
				push1(stack,&top1,&top2,data);
				break;
			case 2:
				scanf("%d",&data);
				push2(stack,&top1,&top2,data);
				break;
			case 3:
				item = pop1( stack,&top1);
				printf("top element of stk1 is : %d\n",item);
				break;
			case 4:
				item = pop2(stack,&top2 );
				printf("top element of stk2 is : %d\n",item);
				break;
			case 5:
				 display1(stack,&top1);
				break;
			case 6:
				 display2(stack,&top2);
				break;
			case 7:
				item=length1(stack,&top1);
				printf("length of stk1 is : %d\n",item);
				break;
			case 8:
				item=length2(stack,&top2);
				printf("length of stk2 is : %d\n",item);
				break;
			default :
				exit(0);
		}
	}
	return 0;
}

void push1(int stack[100],int *top1,int *top2, int data) {
	if((*top1) +1 == (*top2)){
		printf("overflow\n");
		return ;
	}
	(*top1)++;
	stack[*top1] = data;
}
	

int pop1(int stack[100],int *top ) {
	if(*top == -1) {
		printf("underflow\n");
		return -1;
	}
	int data ;
	data = stack[*top];
	(*top)--;
	return data;
}

void display1(int stack[100],int *top) {
	int i;
	if(*top == -1) {
		printf("no element\n");
		return;
	}
	for(i = *top;i >= 0; i--) {
		printf("%d ",stack[i]);
	}
	printf("\n");
}
int length1 (int stack[100],int *top){
	int i,c=0;
	if(*top == -1) {
		printf("no element\n");
		return;
	}
	for( i= 0; i<= *top; i++)
		c++;
	return c;
}
void push2(int stack[100],int *top1,int *top2, int data) {
	if((*top1) +1 == *top2){
		printf("overflow\n");
		return ;
	}
	(*top2)--;
	stack[*top2] = data;
}
	

int pop2(int stack[100],int *top ) {
	if(*top == MAX) {
		printf("underflow\n");
		return -1;
	}
	int data ;
	data = stack[*top];
	(*top)++;
	return data;
}

void display2(int stack[100],int *top) {
	int i;
	if(*top == MAX) {
		printf("no element\n");
		return;
	}
	for( i=*top; i < MAX ; i++) {
		printf("%d ",stack[i]);
	}
	printf("\n");
}
int length2(int stack[100],int *top){
	int i,c=0;
	if(*top == MAX) {
		printf("no element\n");
		return;
	}
	for( i=*top; i<MAX; i++)
		c++;
	return c;
}



