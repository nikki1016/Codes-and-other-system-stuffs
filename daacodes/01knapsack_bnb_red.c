#include <stdio.h>
#include <stdlib.h>
struct node{
	int level;
	int weight;
	int bound;
	int profit;
	int count;
};
int knapsack_basic(int,int,int *,int *);
int knapsack_constrained(int,int,int *,int *,int);
int knapsack_multiple(int,int *,int,int *,int *);
int main()
{
	int i,W,n,m,*c,*w,p,*mW;
	scanf("%d",&n);
	scanf("%d",&W);
	c=(int *)malloc(n*sizeof(int));
	w=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("Knapsack Basic : %d\n",knapsack_basic(W,n,c,w));
	scanf("%d",&n);
	scanf("%d",&W);
	c=(int *)malloc(n*sizeof(int));
	w=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	scanf("%d",&p);
	printf("Knapsack Constrained : %d\n",knapsack_constrained(W,n,c,w,p));
	/*scanf("%d",&n);
	scanf("%d",&m);
	mW=(int *)malloc(m*sizeof(int));
	c=(int *)malloc(n*sizeof(int));
	w=(int *)malloc(n*sizeof(int));
	for(i=0;i<m;i++)
		scanf("%d",&mW[i]);
	for(i=0;i<n;i++)
		scanf("%d",&c[i]);
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("Knapsack Multiple : %d\n",knapsack_multiple(m,mW,n,c,w));*/
	return 0;
}
void swap(int *a,int x,int y){
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
	
}
void sort(int *c,int *w,int n){
	int i,j;
	float a,b;
	for(i=1;i<n;i++)
		for(j=i;j>0;j--){
			a = (float)c[j]/w[j];
			b = (float)c[j-1]/w[j-1];
			if(a>b){
				swap(c,j,j-1);
				swap(w,j,j-1);
			}
		}
}
void push(struct node * queue,struct node dummy,int *f,int *r,int n){
	int rear = *r;
	int front = *f;
	if(rear - front ==  n-1||(front >0&&rear == front -1))
		return ;
	if(rear==n-1){
		rear = -1;
		*r = -1;
	}
	(*r)++;
	rear++;
	queue[rear] = dummy;
}
struct node pop(struct node * queue,int *r,int *f,int n){
	int rear = *r;
	int front = *f;
	struct node temp;
	temp.level = -1;
	temp.weight = -1;
	if(rear == -1)
		return temp;
	if(front == rear){
		(*f) = 0;
		(*r) = -1;
		return queue[front];
	}
	if(front == n-1){
		(*f) = 0;
		return queue[front];
	}
	(*f)++;
	return queue[front]; 
}
int isEmpty(int r){
	if(r==-1)
		return 1;
	else 
		return 0;
}
int bound(struct node u,int n,int W,int *c,int *w,int p){
	if(u.weight>=W&&u.count>=p)
		return 0;
	int profit_bound = u.profit;
	int j = u.level +1;
	int totweight = u.weight;
	int count = u.count;
	while((j<n)&&(totweight+w[j]<=W)&&count<p){
		profit_bound += c[j];
		totweight += w[j];
		j++;
		count++;
	}
	if(j<n&&count<p){
		profit_bound += (W-totweight)*((float)c[j])/w[j] ;
	}
	return profit_bound;
}
int knapsack_basic(int W,int n,int *c,int *w)
{
	/* Implement basic 0/1 knapsack problem */
	
	sort(c,w,n);
	struct node queue[10000];
	int rear = -1;
	int front = 0;
	struct node dummy ;
	dummy.level = -1;
	dummy.weight = 0;
	dummy.profit = 0;
	dummy.bound = 0;
	dummy.count = 0;
	int maxprofit=0;
	int profit_bound;
	push(queue,dummy,&front,&rear,10000);
	struct node u;
	int x;
	while(!isEmpty(rear)){
		u = pop(queue,&rear,&front,10000);
//		printf("%d %d %d %d\n",u.level,u.profit,u.weight,u.bound);
		if(u.level == n-1)
			continue;
		struct node v;
		v.level = u.level+1;
		v.weight = u.weight + w[v.level];
		v.profit = u.profit + c[v.level];
//		printf("%d %d %d %d\n",v.level,v.profit,v.weight,v.bound);
		v.count = u.count+1;
		if(v.weight<=W&&v.profit>maxprofit){
			maxprofit = v.profit;
			x = v.count;
		}
		v.bound = bound(v,n,W,c,w,n);
		if(v.bound>maxprofit){
			push(queue,v,&front,&rear,10000);
		}
		v.weight = u.weight;
		v.profit = u.profit;
		v.count = u.count;
		v.bound = bound(v,n,W,c,w,n);
		if(v.bound>maxprofit){
			push(queue,v,&front,&rear,10000);
		}
	}
	printf("count := %d \n",x);
	return maxprofit;
}

int knapsack_constrained(int W,int n,int *c,int *w,int p)
{
	/* implement the constrained knapsack with the maximum number of elements*/
	 sort(c,w,n);
        struct node queue[10000];
        int rear = -1;
        int front = 0;
        struct node dummy ;
        dummy.level = -1;
        dummy.weight = 0;
        dummy.profit = 0;
        dummy.bound = 0;
        dummy.count = 0;
        int maxprofit=0;
        int profit_bound;
        push(queue,dummy,&front,&rear,10000);
        while(!isEmpty(rear)){
                struct node u = pop(queue,&rear,&front,10000);
//              printf("%d %d %d %d\n",u.level,u.profit,u.weight,u.bound);
                if(u.level == n-1)
                        continue;
                struct node v;
                v.level = u.level+1;
                v.weight = u.weight + w[v.level];
                v.profit = u.profit + c[v.level];
		v.count = u.count +1;
//              printf("%d %d %d %d\n",v.level,v.profit,v.weight,v.bound);
                if(v.weight<=W&&v.profit>maxprofit)
                        maxprofit = v.profit;
                v.bound = bound(v,n,W,c,w,p);
                if(v.bound>maxprofit){
                        push(queue,v,&front,&rear,10000);
                }
                v.weight = u.weight;
                v.profit = u.profit;
		v.count = u.count;
                v.bound = bound(v,n,W,c,w,p);
                if(v.bound>maxprofit){
                        push(queue,v,&front,&rear,10000);
                }
        }
        return maxprofit;
}

int knapsack_multiple(int m,int *mW,int n,int *c,int *w)
{
	/* implement the multiple knapsack problem */ 
}
