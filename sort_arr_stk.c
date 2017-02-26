#include<stdio.h>
#include<stdlib.h>
struct stack{
	int srt[100];
	int top;
};
int is_empty(struct stack *stk){
	if((stk->top) == -1 )
		return 1;
	return 0;
}
int is_full(struct stack *stk,int n){
	if((stk->top) == n-1)
		return 1;
	return 0;
}
struct stack* push(int item,struct stack **stk,int n){
	if(is_full((*stk),n)){
		printf("overflow\n");
		return *stk;
	}
	((*stk)->top)++;
	((*stk)->srt[(*stk)->top]) = item;
	return (*stk);
}
int pop(struct stack* stk){
	if(is_empty(stk)){
		printf("underflow\n");
		return -1;
	}
	int item;
	item = (stk->srt[stk->top]);
	(stk->top)--;
	return item;
}

int peek(struct stack *stk){
	if(is_empty(stk)){
	       printf("underflow\n");
	       return -1;
	}
        int item;
	item = (stk->srt[stk->top]);
	return item;
}
void copy(int *arr,struct stack *stk1,int n){
	int j,i;
	for(i = stk1->top,j=0; i>=0; i--,j++)
		*(arr+j) = pop(stk1);
	for(i=0; i<j; i++)
		printf("%d ",arr[i]);
}

struct stack *sort_arr(int arr[100],struct stack **stk1,struct stack **stk2,int n){
	int i,item;
	*stk1 = push(arr[0],stk1,n);
	for(i=1; i<n; i++){
		if(arr[i] <= peek(*stk1)){
			*stk1 = push(arr[i], stk1,n);
		}
		else{
			while((arr[i] > peek(*stk1)) && ((*stk1)->top != -1)){
				item = pop(*stk1);
				push(item , stk2,n);
			}
			*stk1 = push(arr[i], stk1,n);
			while((*stk2)->top != -1){
				item =pop(*stk2);
				*stk1 = push(item,stk1,n);
			}
		}
	}
	return *stk1;
}

int main(){
	struct stack *stk1,*stk2;
	stk1 = (struct stack *)malloc (sizeof (struct stack));
	stk2 = (struct stack *)malloc (sizeof (struct stack));
	stk1->top = -1;
	stk2->top = -1;
	int n;
	scanf("%d",&n);
	int arr[n],i;
	for(i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	stk1 = sort_arr(arr,&stk1,&stk2,n);
	copy(arr,stk1,n);
	return 0;
}
