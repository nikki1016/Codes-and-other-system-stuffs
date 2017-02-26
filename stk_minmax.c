#include <stdio.h>
#include <stdlib.h>
void push(int stack[100],int *top,int data);
int pop(int stack[100],int *top);
void display(int stack[100],int *top);
int length (int stack[100],int *top);
int minn(int stack[100],int *top,int *min);
int maxx(int stack[100],int *top,int *max);
int main() {
	int stack[100],top= -1,max = -1,min=10000;
	int i,n,data,item,choice;
	while(1) {
		printf("enter choice:\t1.push\t2.pop\t3.display\t4.length of stack\t5.maximum is\t6.minimum\t7.exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				scanf("%d",&data);
				if(max< data)
					max = data;
				else if(min > data)
					min = data;
				push(stack,&top,data);
				break;
			case 2:
				data= pop(stack,&top);
				if(max == data)
					max = maxx(stack,&top,&max);
				else if(min == data)
					min = minn(stack,&top,&min);
				printf("top element is : %d\n",data);
				break;
			case 3:
				 display(stack,&top);
				break;
			case 4:
				item=length(stack,&top);
				printf("length is : %d\n",item);
				break;
			case 5:
				printf("max is : %d\n",max);
				break;
			case 6:
				printf("min is : %d\n",min);
				break;
			default :
				exit(0);
		}
	}
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
		printf("%d ",stack[i]);
	}
	printf("\n");
}
int length (int stack[100],int *top){
	int i,c=0;
	if(*top == -1) {
		printf("no element\n");
		return;
	}
	for( i= 0; i<=*top; i++)
		c++;
	return c;
}
int minn (int stack[100],int *top,int *min){
	int i;
	for( i= 0; i<=*top; i++){
		if(*min > stack[i])
			*min= stack[i];
	}
	return *min;
}
int maxx (int stack[100],int *top,int *max){
	int i;
	for( i= 0; i<=*top; i++){
		if(*max < stack[i])
			*max= stack[i];
	}
	return *max;
}
