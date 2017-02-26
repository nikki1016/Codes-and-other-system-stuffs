#include <stdio.h>
#include <stdlib.h>
void push(int stack[100],int *top,int data);
int pop(int stack[100],int *top);
void display(int stack[100],int *top);
int primee(int i);
int main() {
	int stack[100],top = -1;
	int i = 2, n;
	scanf("%d",&n);
	while(n > 0){
		while(primee(i)){
			while(n%i == 0){
				push(stack,&top,i);
				n = n/i;
			}
			i++;
		}
		i++;
	}
	display(stack,&top);
	while(top != -1){
		i = pop(stack,&top);
		printf("%d",i);
	}
	printf("\n");
	return 0;
}
int primee(int i){
	int p,flag = 0;
	for(p = 2; p <= i/2; p++){
		if(i % p == 0 ){
			flag = 1;
			return 0;
		}
	}
	return 1;
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

