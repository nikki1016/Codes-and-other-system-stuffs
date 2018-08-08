#include <time.h>
#include <sys\stat.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct stat status;
    FILE *fp;
    fp=fopen("F1.txt","r");
    fstat(fileno(fp),&status);
    printf("Size of file : %d",status.st_size);
    printf("Drive name   : %c",65+status.st_dev);
    //getch();
}
