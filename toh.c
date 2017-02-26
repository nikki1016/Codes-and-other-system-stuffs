#include <stdio.h>
void toh(int n, char from, char to, char aux);
int main(){
	char from='A',to='B',aux='C';
	int n;
	scanf("%d",&n);
	toh( n, from, to, aux);
	return 0;
}
void toh(int n, char a, char b, char c){
	if (n == 1)
		printf("move %d from %c to %c\n",n,a,b);
	else{
		toh(n-1,a,c,b);
		printf("move %d from %c to %c\n",n,a,b);
		toh(n-1,c,b,a);
	}
}
