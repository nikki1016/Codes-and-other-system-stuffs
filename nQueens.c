#include<stdio.h>
#include<stdlib.h>
void display (int** a, int n)
{
	int i=0, j=0, k=0;
	printf("\n");
	for (;i<n;i++)
	{
		for(j=0;j<n;j++)
			{if(a[i][j]==-1) printf("Q ");
			else printf ("_ ");}
		printf("\t");
		for(j=0;j<n;j++) 
			{k=a[i][j];
			if(k==-1) printf("%d ",a[i][j]);
			else printf(" %d ",a[i][j]);}
		printf("\n");
	}
}
int look (int i, int j, int** a, int n)
{
	for(;i<n; i++) {
		if(a[i][j]==0){ /*printf("look gave a[%d][%d]=%d\tk ",i,j,a[i][j],i);*/ break;} }
	return i;
}
void set (int i, int j, int **a, int n)
{
	a[i][j]=-1;
//printf("a[%d][%d]=%d",i,j,a[i][j]);
	int k=0, l=0;
	for(k=j+1; k<n; k++) a[i][k]++;
//display(a,n);
	for(k=j+1,l=i-1; ((k<n)&&(l>-1)); k++, l--) {/*printf("%d\t",((k<n)&&(l<n))); printf("before adding a[%d][%d=%d]",l,k,a[l][k]);*/ a[l][k]=a[l][k]+1; /*printf("after adding a[%d][%d=%d]",l,k,a[l][k]); display(a,n);*/}
//display(a,n);
	for(k=j+1,l=i+1; (k<n)&&(l<n); k++, l++) a[l][k]++;
//display(a,n);
}
void unset (int i, int j, int **a, int n)
{
	a[i][j]=0;
	int k=0, l=0;
	for(k=j+1; k<n; k++) a[i][k]--;
	for(k=j+1,l=i-1; (k<n)&&(l>-1); k++, l--) a[l][k]--;
	for(k=j+1,l=i+1; (k<n)&&(l<n); k++, l++) a[l][k]--;
}
int UNDO (int j, int **a, int n)
{
	int i=0;
	for(; i<n; i++) if(a[i][j]==-1) break;
	unset(i,j,a,n);
	int k=look (i+1,j,a,n);
	if (k!=n) set(k,j,a,n);
	else return UNDO(j-1,a,n);
	return j;
}
int main()
{
	int n;
	scanf("%d",&n);
	int* arr= (int*)malloc(n*n*sizeof(int));
	int**a =(int**)malloc(n*sizeof(int*));
	a[0]=arr;
//printf("arr %p a %p\n",arr,a);
	int j=0, k=0;
	for(j=1; j<n; j++) {a[j]= a[j-1]+n;
//printf("a[%d]=%p",j,a[j]);
	}
	for(j=0; j<n; j++) for(k=0; k<n; k++) {
//printf("into init  ");
	a[j][k]=0;
//printf("a[%d][%d]=%d",j,k,a[j][k]);
	}
//printf("\nbefore disp\n");
//	display(a,n);
//printf("after disp\n");
	for(j=0; j<n; j++)
	{
		if((k=look(0,j,a,n))!=n)
		{
//printf("k %d\n",k);
			set(k,j,a,n);
		}
		else 
		{
//			printf("j before undo %d\t",j); 
			j=UNDO(j-1,a,n);
//			printf ("j after undo %d\n",j);
		}
//		display(a,n);
	}
	display(a,n);
	return 0;
}
