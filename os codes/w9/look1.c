#include<stdio.h>
#include<math.h>
int main() {
	int i,j,s,n,a[100],t;
	scanf("%d%d",&n,&s);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++) {
		for(j=0;j<n-i-1;j++) {
			if(a[j]>a[j+1]) {
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	} 
	int l,sum=0;
	for(i=0;a[i]<s;i++) ;
	l=i;
	for(i=l;i<n;i++) {
		printf("%d ",a[i]);
		sum+=abs(s-a[i]);
		s=a[i];
	}
	sum+=a[n-1]-a[0];
	for(i=l-1;i>=0;i--) {
		printf("%d ",a[i]);
		//sum+=abs(s-a[i]);
		//s=a[i];
	}
		printf("movement %d",sum);
	
	return 0;
}
	
