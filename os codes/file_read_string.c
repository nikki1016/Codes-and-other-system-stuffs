#include<stdio.h>
int main(){
char str[70];
FILE *p;
if((p=fopen("n.c","w"))==NULL){
printf("\nUnable t open file string.txt");
exit(1);
}


while(fgets(str,70,p)!=NULL)
puts(str);
fclose(p);
return 0;
}

