#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int i,t,j;
	unsigned int n[10],arr[255];
	clock_t start[10],end[10];
	for(i = 0; i < 10; i++)	
		scanf("%d",&n[i]);
	for(i = 0; i<10; i++){
		start[i] = clock();
		for(j=0; j<n[i]; j++)
			arr[j] = rand() % 256;
		end[i] = clock();
		t[i] = (double)(end[i] - start[i]) / CLOCKS_PER_SEC;
	}
	for(i = 0; i < n; i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
