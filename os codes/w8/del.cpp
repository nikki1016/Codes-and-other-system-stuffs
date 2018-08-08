#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	FILE *fptr;
	int status;
	char file_name[1001];
	gets(file_name);
	status=remove(file_name);
	if(status!=0)
	{
			printf("Cant delete\n");
	}
	else
		printf("Deleted %s",file_name);
	return 0;
}
