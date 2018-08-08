#include <stdio.h>
int main()
{
	int q, arr[100000] = {0}, n , l,r, i=1, count=0,j,k;
	scanf("%d",&n);
	while(n--)
	{
		count = 0;
		scanf("%d",&q);
		if(q!=1){
			scanf("%d%d%d",&l,&r,&k);
			for(j = l; j<= r && j <= i; j++)
			{
				if(arr[j] < k && q == 2)
					count++;
				else if(arr[j] == k && q ==3)
					count++;
				else if(arr[j] > k && q== 4)
					count++;
	
			}
			printf("%d\n",count);
		}
		else{
			scanf("%d",&arr[i++]);
		} 
		
	}
	return 0;
}

