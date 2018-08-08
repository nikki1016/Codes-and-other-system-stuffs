#include "time.h"
#include "sys\stat.h"
#include "stdio.h"
int main(){
    struct stat status;
    FILE *fp;
    fp=fopen("F1.txt","r");
    fstat(fileno(fp),&status);
    printf("Last date of modification : %s",ctime(&status.st_ctime));
    return 0;
}

