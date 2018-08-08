#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	int i;
	int y = fork();
	if(y == 0){
		for(i =0; i<20;i++){
			printf("child i = %d\n",i);
		}
	}
	else{
		wait(NULL);
		for(i =0;i<10; i++)
			printf("parent i = %d\n",i);
	}
	printf("bye\n");
	return 0;
}
