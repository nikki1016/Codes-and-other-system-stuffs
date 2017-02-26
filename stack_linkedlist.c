#include <stdio.h>
#include<stdlib.h>
struct stack{
	int ptr;
	struct stack *top;
};

int is_empty(struct stack *arr) {
	if(arr == NULL)
		return 1;
	return 0;
}
void create(int *ptr){
	ptr = (int * )malloc(sizeof(int));
	if(ptr == NULL){
		printf("no memory\n");
	}
}

struct stack* push(struct stack* arr,int data){
	struct stack* temp;
	temp = (struct stack *)malloc(sizeof(struct stack));
	if(temp == NULL)
		printf("no memory available\n");
	else {
		temp->ptr = data;
		temp->top = arr;
		return temp;
	}
}

struct stack* pop(struct stack* arr){
	struct stack* temp;
	if(is_empty(arr)){
		printf("no element\n");
	}
	else {
		printf("deleted top element is : %d\n",(arr->ptr));
		if(arr->top == NULL) 
			return NULL;
		arr=arr->top;
		return arr;
	}
}

void peek(struct stack* arr){
	struct stack* temp=arr;
	if(is_empty(arr)){
		printf("no element\n");
	}
	else{
		temp = arr;
		printf("top element is : %d\n",(temp->ptr));	
	}
}

void length(struct stack *arr){
	int c=0;
	struct stack* pttr=arr;
	if(is_empty(arr)){
		printf("no element\n");
	}
	
	while(pttr->top != NULL){
		c++;
		pttr = pttr->top;
	}	
	printf("length is : %d\n",c+1);
	
}

void display(struct stack *arr){
	struct stack* pttr=arr;
	if(is_empty(arr)){
		printf("no element\n");
	}
	while(pttr != NULL){
		printf("%d ",(pttr->ptr));
		pttr = pttr->top;
	}	
	printf("\n");
}

int main(){
	struct stack *array;
	array = NULL;
//	array = (struct stack *)malloc(sizeof(struct stack));
	int i,data,item,choice;
	printf("enter choice:\t1.push\t2.pop\t3.display\t4.length of stack\t5.top element\t6.exit\n");
	while(1) {
		printf("enter choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				scanf("%d",&data);
				array = push(array,data);
				break;
			case 2:
				array = pop(array);
				break;
			case 3:
				display(array);
				break;
			case 4:
				length(array);
				
				break;
			case 5:
				peek(array);
				break;
			default :
				exit(0);
		}
	}
	return 0;
}
