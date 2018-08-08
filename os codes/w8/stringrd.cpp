#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int

int main()
{
	char str[70];
	FILE *p;
	if((p=fopen("file1.cpp","r"))==NULL)
	{
		printf("\nUnable t open file string.txt");
		exit(1);
	}
	while(fgets(str,70,p)!=NULL)
	puts(str);
	fclose(p);
	return 0;
}
