#include <stdio.h>
#include<string.h>
int expp( int a,int b,int m){
    if(b==0) return 1;
    if(b==1) return a%m;
    int t=expp(a,b/2,m)%m;
    
    if(b%2 == 0){
        t = (t*t)%m;
    }
    else t = (t*t*(a%m))%m;
    return t;
}

int main() {
	int t,b,m;
	
	scanf("%d",&t);
	while(t--){
	    char *a;
	    scanf("%s",a);
	    scanf("%d%d",&b,&m);
	    int k=0,i;
	    for(i=0;i<strlen(a);i++){
	        k = k*10 +(a[i]-'0');
	        k= k%m;
	    }
	     int t = expp(k,b,m);
	    printf("%d\n",t);
	}
	return 0;
}
