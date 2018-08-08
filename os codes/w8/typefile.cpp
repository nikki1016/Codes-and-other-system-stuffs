#include "time.h"
#include "sys\stat.h"
#include "stdio.h"
int main(){
    struct stat status;
    FILE *fp;
    stat("c:\\tc\\bin",&status);
    if (status.st_mode & S_IFDIR)
         printf("It is directory.\n");
    if (status.st_mode & S_IFCHR)
         printf("It is chracter file.");
    if (status.st_mode & S_IFREG)
         printf("It is reggular file.");

}
