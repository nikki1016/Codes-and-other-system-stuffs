n# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <time.h>
struct node {
	struct node *next;
	double str;
};
struct table{
	struct node *next;
	int count;
};
void bucketsort(double input[],int n)
{
	struct table arr[10];
	int i, j;
	float  sum, std = 0;
	for(i = 0; i< 10; i++){
		arr[i].next = NULL;
		arr[i].count = 0;
	}
	for(i = 0; i < n; i++){
		j = (int)(input[i]*10);
		struct node * p = (struct node *)malloc(sizeof(struct node)),*kk = arr[j].next;
		p->str = input[i];
			//printf("j %d p %lf--  ",j,p->str);
		p->next = NULL;
		if(kk == NULL || kk->str > input[i]){
			p->next = arr[j].next;
			arr[j].next = p;
			arr[j].count++;		
			continue;
		}
		while(kk->next && kk->next->str < input[i]){
			//printf("kk %lf  ",kk->str);
			kk = kk->next;
		}
		p->next = kk->next;
		kk->next = p;
		arr[j].count++;
		//printf("count j %d arr %lf--  ",arr[j].count,arr[j].next->str);
	}
	j=0;
 	for(i = 0; i< 10; i++){
		struct node *p = arr[i].next;
		while(p != NULL && arr[i].count != 0){
			input[j++] = p->str;
			p = p->next;
			arr[i].count--;
		}
	}
	
}

int main()
{
	int n,i;
	scanf("%d",&n);
	double arr[n];
	for(i = 0; i<n ; i++)
		scanf("%lf",&arr[i]);
	
	bucketsort(arr,n);
      	for(i = 0; i<n ; i++)
		printf("%lf ",arr[i]);
	printf("\n");
	return 0;
}


