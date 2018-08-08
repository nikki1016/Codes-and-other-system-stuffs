#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int factorial(int n,int k){
    if(n==1 || n==0) return 1;
    int t = factorial(n-1,k);
    int ans = ((n%k)*(t%k))%k;
    return ans;
}
int expp(int n,int k){
    if(k == 0) return 1;
    if(k == 1) return n;
	int t;
    if(k %2 == 0){
        t = expp(n,k/2) * expp(n,k/2);
    }
    else t =expp(n,k/2) *expp(n,k/2) * n;
	return t;
}
int main() {

    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int j=n+m-1, k=1000000007;
        int num =factorial(j,k)%k;
        int den1 =factorial(m-1,k);
        int den2 =factorial(n,k);
        den1 = (den1 *den2);
        int kk = expp(den1,k) % k;
        num = (num * kk)%k;
        printf("%d\n",num);
    }
    return 0;
}

