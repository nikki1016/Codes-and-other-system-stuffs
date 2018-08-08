#include <stdio.h>
#include <string.h>

int main ()
{
  char str[100] ;
  char * pch;
int t;
scanf("%d",&t);
getchar();
  scanf("%[^\n]s",str);
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ");
  }
  return 0;
}
