#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int

int main()
{
	FILE *fptr;
	char ch;
	fptr=fopen("file1.cpp","r");
	while( (ch=getc(fptr)) !=EOF)
	{
		putchar(ch);
	}
	fclose(fptr);
	return 0;
}
