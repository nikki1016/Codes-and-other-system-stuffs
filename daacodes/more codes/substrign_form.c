#include<stdio.h>
int main(){
	char str[100],ch;
	int i;
	scanf("%s",str);
	while(1){
		int l,r,q,x,m;
		scanf("%d",&q);
		if(q==1){
			scanf("%d",&l);
			ch = getchar();
			str[l-1] = ch;
	//		printf("%s\n",str);
		}
		else if(q==2){
			r=0;
			scanf("%d%d",&l,&r);
			for(i = l-1; i<r; i++){
	//			putchar(str[i]);
				m = m ^ (int)(str[i]);
				//printf("%c",str[i]);
			}
			if(m==0 && (r-l+1 ) %2==0){
				printf("YES\n");
			}
			else if(m >=97 && m <= 120 && (r-l+1)%2)
				printf("YES\n");
			else printf("NO\n");
		}
		else return 0;
	}
	return 0;
}


