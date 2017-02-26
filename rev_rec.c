#include<stdio.h>
#include<string.h>
#define N 100
void reverse(char *string,int l){
	if(l<=1) return;
	char tmp;
	tmp = *(string+l-1);
	*(string+l-1)=*string;
	*string = tmp;
	reverse(string+1,l-2);
}
int main(){
	char expp[N];
	int arr[N],top=-1,f,i;
	scanf("%s",expp);
	reverse(expp,strlen(expp));
	printf("%s\n",expp);
	return 0;
}

