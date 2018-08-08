#include <bits/stdc++.h>
#define rep(i,n) for(__typeof(n) i=0;i<n;++i)
#define reu(i,s,e) for(__typeof(e) i=s;i<e;++i)
#define si(x) x = scanInt();
#define sll(x) x = scanLong();
using namespace std;

typedef long long ll;
inline int scanInt(){
	 int n = 0;
	 char ch = getchar_unlocked();
	 int sign = 1;
	 while(ch < '0' || ch > '9') {
		  if(ch == '-') sign = -1;
		  ch = getchar_unlocked();
	 }
	 while(ch >= '0' && ch <= '9') {
		  n = (n<<1)+(n<<3)+(int)(ch-'0');
		  ch = getchar_unlocked();
	 }
	 return n*sign;
}
inline ll scanLong(){
	 ll n = 0;
	 char ch = getchar_unlocked();
	 ll sign = 1;
	 while(ch < '0' || ch > '9') {
		  if(ch == '-') sign = -1;
		  ch = getchar_unlocked();
	 }
	 while(ch >= '0' && ch <= '9') {
		  n = (n<<1)+(n<<3)+(ll)(ch-'0');
		  ch = getchar_unlocked();
	 }
	 return n*sign;
}
int m,n;
int steps[255][255];
struct move{
	int R,D;
};
void initialise(void){
	rep(i,255)
		rep(j,255) steps[i][j]=1000;
}
int main(){
    si(m);si(n);
    struct move jumps[m][n];
    rep(i,m)
		rep(j,n){
			si(jumps[i][j].R);
		}
	rep(i,m)
		rep(j,n){
			si(jumps[i][j].D);
		}
    initialise();
    steps[0][0]=0;
    rep(i,m)
		rep(j,n){
			reu(k,j+1,j+jumps[i][j].R+1){
				if(k>=n) break;
				if(steps[i][k]>1+steps[i][j]) steps[i][k]=steps[i][j]+1;
			}
			reu(k,i+1,i+jumps[i][j].D+1){
				if(k>=m) break;
				if(steps[k][j]>1+steps[i][j]) steps[k][j]=steps[i][j]+1;
			}
		}
	printf("%d",steps[m-1][n-1]);
    return 0;
}

