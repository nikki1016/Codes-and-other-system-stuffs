#include<stdio.h>
int a =10;
int fun(){
	a = 17;
	return 3;
}
int main(){
	int b = fun()+a;
	printf("%d %d\n",a,b);
	return 0;
}
