#include <stdio.h>
#include <stdlib.h>
 
int main()
{
   FILE *fp1 = fopen("F1.txt", "r");
   FILE *fp2 = fopen("F_2.txt", "w");
   char c;
   while ((c = fgetc(fp1)) != EOF)
      fputc(c, fp2);
   fclose(fp1);
   fclose(fp2);
   return 0;
}
