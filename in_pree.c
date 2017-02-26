#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 15
void in_pre();
int isfull();
int isempty() ;
void push(int item);
char pop();
int eva_pre() ;
int prior(char sym);
int top=-1;
char arr[MAX];
char infix[100],infx[100], prefix[100];
int main()
{
	int i=0,j;
	scanf("%[^\n]s",infx);
	for(i=0, j=strlen(infx); infx[i] != '\0';i++,j--){
		infix[i] = infx[j-1];
	}
	in_pre();
	for(i=strlen(infix)-1; i >= 0; i--){
		printf("%c",prefix[i]);
	}
	printf("\n");
	i=eva_pre();
	printf("%d\n",i);
	return 0;
}
void in_pre(){
	int i,p=0,l;
	char sym,itm;
	for(i = 0; i < strlen(infix); i++){
		sym = infix[i];
		if(sym == ')') 
			push (sym);
		else if( sym == '^' ||sym == '*' || sym== '/' || sym == '+' || sym== '-' || sym == '%') {
			if(isempty())
				push (sym);
			else{
				while (prior(arr[top]) >= prior(sym) && !isempty()) {
					itm= pop();
					prefix[p++] = itm;
				}
				push (sym);	
			}			
		}
		else if (sym == '('){
			while ((itm = pop()) != ')'){
				prefix[p++] = itm;
			}
		}
		else 
			prefix[p++] = sym;
	}
	while(!isempty()) {
		itm = pop();
		prefix[p++] = itm;
	}
	prefix[p]='\0';
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
int eva_pre() {
	int i,result;
	int sym,itm,a,b;
	for(i = 0; i< strlen(prefix); i++){
		if(prefix[i] >= '0' && prefix[i] <='9') 
			push(prefix[i]-'0');
		else if( prefix[i] == '^' ||prefix[i] == '*' ||prefix[i]== '/' || prefix[i] == '+' || prefix[i]== '-' || prefix[i] == '%') {
			if(isempty())
				printf("no\n");
			else {
				a=pop();
				b=pop();
				switch(prefix[i]) {
					case '+':
						sym = a+b;
						break;
					case '-':
						sym =a-b;
						break;
					case '*':
						sym = a*b;
						break;
					case '/':
						sym = a/b;
						break;
					case '%':
						sym = a%b;
						break;
					case '^':
						sym = pow(a,b);
						break;
				}
				push (sym);	
			}			
		}
	}
	result=pop();
	return result;
}

