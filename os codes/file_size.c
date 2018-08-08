#include <time.h>
#include <sys\stat.h>
#include <stdio.h>
void main()
{
    struct stat status;
    FILE *fp;
    fp=fopen("test.txt","r");
    fstat(fileno(fp),&status);
   // clrscr();
    printf("Size of file : %d",status.st_size);
    printf("Size of file : %d",status.st_mode);
    printf("Size of file : %s",ctime(&status.st_ctime));
    printf("Drive name   : %c",65+status.st_dev);
    //getch();
}
