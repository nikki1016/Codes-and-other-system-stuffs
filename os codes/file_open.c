	#include<stdio.h>
	int main(){
		FILE *fp;
		char ch;
		char str[100];
		fp=fopen("file.txt","w");
		printf("\nEnter data to be stored in to the file:");
		while((ch=getchar())!= EOF)
			fputc(ch,fp);
		fclose(fp);
		fp=fopen("file.txt","r");
		ch=fgetc(fp);
		while(!feof(fp)){         ///returns 0 if not at end else non-zero value at end of file
			printf("%c",ch);
			ch=fgetc(fp);
		}
		
			putchar(ch);
		fclose(fp);
		fp = fopen("myfile.txt" , "w" );
fputs ( "This is an apple." , fp );
printf("%d is current loc\n",ftell(fp));
fseek ( fp , 10, SEEK_SET );
printf("%d is current loc\n",ftell(fp));
fputs ( " sam" , fp );
printf("%d is current loc\n",ftell(fp));
rewind(fp);
fgets(str,10,fp);
printf("%s is str\n",str);

fclose ( fp );

		return 0;
	}

