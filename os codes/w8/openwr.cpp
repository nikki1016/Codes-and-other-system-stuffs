#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int

int main()
{
	FILE *fptr;
	char ch;
	fptr=fopen("filepro1.txt","w");
	printf("Enter what you want to store in the .txt file \n");
	while( (ch=getchar())!=EOF )
		putc(ch,fptr);
	fclose(fptr);
	return 0;
}
