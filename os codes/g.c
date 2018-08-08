#include <stdio.h>
int main()
{
	int q, arr[100000] = {0}, n , l,r,k, i=1, count=0,j;
	scanf("%d",&n);
	while(n--)
	{
		count = 0;
		scanf("%d",&q);
		if(q!=1){
			scanf("%d%d%d",&l,&r,&k);
		}
		else{
			scanf("%d",&k);
			arr[i++]= k;
			continue;
		} 
		if(q ==2){
			for(j = l; j< r && j <= i; j++)
			{
				if(arr[j] < k)
					count++;
			}
		}
		else if(q == 3){
			for(j = l; j< r && j <= i; j++)
			{
				if(arr[j] == k)
					count++;
			}
		}
		else if(q == 4){
			for(j = l; j< r && j <= i; j++)
			{
				if(arr[j] > k)
					count++;
			}
		}
		printf("%d\n",count);
	}
}
