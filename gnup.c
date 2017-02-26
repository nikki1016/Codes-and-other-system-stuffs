#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	FILE *pipe_gp = popen("gnuplot", "w");
	fputs("set terminal png\n", pipe_gp);
	fputs("plot '-' u 1:2\n", pipe_gp);

	int i,j;
	unsigned int n[10],arr[255];
	clock_t start[10],end[10];
	double t[10];
	for(i = 0; i < 10; i++)	
		scanf("%u",&n[i]);
	for(i = 0; i<10; i++){
		start[i] = clock();
		for(j=0; j<n[i]; j++)
			arr[j] = rand() % 256;
		end[i] = clock();
		t[i] = (double)(end[i] - start[i]) / CLOCKS_PER_SEC;
		fprintf(pipe_gp, "%u %f\n", n[i], t[i]);
	}
	fputs("e\n", pipe_gp);
 	pclose(pipe_gp);
	return 0;
}
