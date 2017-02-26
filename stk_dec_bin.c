#include <stdio.h>
#include <stdlib.h>
void push(int stack[100],int *top,int data);
int pop(int stack[100],int *top);
void display(int stack[100],int *top);

int main() {
	int stack[100],top= -1;
	int i,n,data,item,choice;
	scanf("%d",&n);
	while(n > 0){
		i = n%2;
		push(stack,&top,i);
		n/=2;
	}
	display(stack,&top);
	while(top != -1){
		i = pop(stack,&top);
		printf("%d",i);
	}
	printf("\n");
	return 0;
}

void push(int stack[100],int *top,int data) {
	if(*top == 99){
		printf("overflow\n");
		return ;
	}
	(*top)++;
	stack[*top] = data;
}
	

int pop( int stack[100],int *top) {
	if(*top == -1) {
		printf("underflow\n");
		return -1;
	}
	int data ;
	data = stack[*top];
	(*top)--;
	return data;
}

void display(int stack[100],int *top) {
	int i;
	if(*top == -1) {
		printf("no element\n");
		return;
	}
	for(i=*top;i>= 0; i--) {
		printf("%d",stack[i]);
	}
	printf("\n");
}

