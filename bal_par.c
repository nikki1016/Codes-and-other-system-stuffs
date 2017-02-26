#include<stdio.h>
#include<string.h>
#define N 100
int is_empty(int *stk){
	if(*stk == -1 )
		return 1;
	return 0;
}
int is_full(int *stk){
	if(*stk ==N-1)
		return 1;
	return 0;
}
void push(int item,int *stk,int arr[100]){
	if(is_full(stk)){
		printf("overflow\n");
		return;
	}
	(*stk)++;
	arr[*stk] = item;
}
int pop(int *stk,int arr[100]){
	if(is_empty(stk)){
		printf("underflow\n");
		return -1;
	}
	int item;
	item = arr[*stk];
	(*stk)--;
	return item;
}

int peek(int *stk,int arr[100]){
	if(is_empty(stk)){
		printf("underflow\n");
		return -1;
	}
	int item;
	item = arr[*stk];
	return item;
}

int main(){
	char expp[N];
	int arr[N],top=-1,f,i;
	scanf("%s",expp);
	for(i=0; i<strlen(expp); i++){
		if(expp[i] == '(' || expp[i] == '{' ||expp[i] == '[')
			push(expp[i],&top,arr);
		else if(expp[i] == ')' || expp[i] == '}' ||expp[i] == ']'){
			f= check(arr,expp[i],&top);
			if(f==0){
				printf("not balance\n");
				return 0;
			}
		}
	}
	if(top != -1)
		printf("not closing par balance\n");
	else
		printf("par balance\n");
	return 0;
}
int  check(int arr[100],int ex,int *top){
	int p;
	if(*top == -1) return 0;
	p = peek(top,arr);
	if(p == '(' && ex == ')'){
		p =pop(top,arr);
		return 1;
	}	
	else if(p == '[' && ex == ']'){
		p =pop(top,arr);
		return 1;
	}	
	else if(p == '{' && ex == '}'){
		p =pop(top,arr);
		return 1;
	}	
	else return 0;
}
