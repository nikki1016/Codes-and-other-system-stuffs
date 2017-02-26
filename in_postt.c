#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 15
void in_post();
int isfull();
int isempty() ;
void push(int item);
char pop();
int eva_post() ;
int prior(char sym);
int incm_prior(char sym);
int top=-1;
char arr[MAX];
char infix[100], postfix[100];
int main()
{
	
	scanf("%[^\n]s",infix);
	in_post();
	int i=eva_post();
	printf("%d\n",i);
	return 0;
}
void in_post(){
	int i,p=0,l;
	char sym,itm;
	for(i = 0; i< strlen(infix); i++){
		sym = infix[i];
		if(sym == '(') 
			push (sym);
		else if( sym == '^' ||sym == '*' || sym== '/' || sym == '+' || sym== '-' || sym == '%') {
			if(isempty())
				push (sym);
			else{
				while (prior(arr[top]) >= incm_prior(sym) && !isempty()) {
					itm= pop();
					postfix[p++] = itm;
				}
				push (sym);	
			}			
		}
		else if (sym == ')'){
			while ((itm = pop()) != '('){
				postfix[p++] = itm;
			}
		}
		else 
			postfix[p++] = sym;
	}
	while(!isempty()) {
		itm = pop();
		postfix[p++] = itm;
	}
	postfix[p]='\0';
}
void push(int item){
	if(isfull())
		printf("stack overflow\n");
	else
	{
		top=top+1;
		arr[top]=item;
	}
}
int isempty() {
	if(top==-1 )
		return 1;
	return 0;
}
int isfull() {
	if(top==( MAX-1) )
		return 1;
	return 0;
}
char pop()
{
	if(isempty() )
		return -1;
	else{
		char in= arr[top];
                top=top-1;
		return in;
	}
		
}
void view()
{
	int i;
	if(top==-1)
		printf("stack underflow\n");
	for(i=0;i<top;i++)
 		printf("%d ",arr[i]);
}
int prior(char sym){
	if(sym == '^')  return 3;
	else if(sym == '*' || sym== '/'|| sym == '%')  return 2;
	else if(sym == '+' || sym== '-')  return 1;
	else 
	 return 0;
}
int incm_prior(char sym){
	if(sym == '^')  return 4;
	else if(sym == '*' || sym== '/'|| sym == '%')  return 2;
	else if(sym == '+' || sym== '-')  return 1;
	else 
	 return 0;
}
int eva_post() {
	int i,result;
	int sym,itm,a,b;
	for(i = 0; i< strlen(postfix); i++){
		if(postfix[i] >= '0' && postfix[i] <='9')
			push(postfix[i]-'0');
		else if( postfix[i] == '^' ||postfix[i] == '*' || postfix[i]== '/' || postfix[i] == '+' || postfix[i]== '-' || postfix[i] == '%') {
			if(isempty())
				printf("no\n");
			else {
				a=pop();
				b=pop();
				switch(postfix[i]) {
					case '+':
						sym = a+b;
						break;
					case '-':
						sym =b-a;
						break;
					case '*':
						sym = a*b;
						break;
					case '/':
						sym = b/a;
						break;
					case '%':
						sym = b%a;
						break;
					case '^':
						sym = pow(b,a);
						break;
				}
				push (sym);	
			}			
		}
	}
	result=pop();
	return result;
}
