#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ll long long int

int main()
{
	FILE *fptr;
	char ch;
	int i,n;
	printf("enter no of elements u want in the array\n");
	scanf("%d",&n);
	int arr[n];
	fptr=fopen("filepro8.txt","w");
	printf("Enter the array u want to write in the file\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		fprintf(fptr,"arr[%d] = %d\n",i,arr[i]);
	}
	//fwrite(arr,sizeof(arr),1,fptr);
	fclose(fptr);
	return 0;
}

