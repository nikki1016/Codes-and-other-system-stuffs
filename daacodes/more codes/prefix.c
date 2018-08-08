#include<stdio.h>
int main(){
	int a =5, b=7;
	//int a=5;

	int c = ++a + (a++);
	int cnt = 10;
	int ct = -cnt++;
	printf("%d %d \n",ct,cnt);

	printf("%d\n",c);
	printf("%d\n",a);
	return 0;
}

