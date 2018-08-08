#include <stdio.h>
#include <stdlib.h>
struct node{
	int level;
	int weight;
	int bound1;
	int profit;
	int count;
};

void swap(int *a,int x,int y){
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
	
}
void sort(int c[],int w[],int n){
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
int bound1(struct node u,int n,int W,int c[],int w[],int p){
	if(u.weight>=W)
		return 0;
	int profit_bound1 = u.profit;
	int j = u.level +1;
	int totweight = u.weight;
	int count = u.count;
	while((j<n)&&(totweight+w[j]<=W)&&count<p){
		profit_bound1 += c[j];
		totweight += w[j];
		j++;
		count++;
	}
	if(j<n&&count<p){
		profit_bound1 += (W-totweight)*((float)c[j])/w[j] ;
	}
	return profit_bound1;
}
int bound2(struct node u,int n,int W,int c[],int w[],int p){
	if(u.weight>=W&&u.count>=p)
		return 0;
	int profit_bound1 = u.profit;
	int j = u.level +1;
	int totweight = u.weight;
	int count = u.count;
	while((j<n)&&(totweight+w[j]<=W)&&count<p){
		profit_bound1 += c[j];
		totweight += w[j];
		count++;
	}
	if(j<n&&count<p){
		profit_bound1 += (W-totweight)*((float)c[j])/w[j] ;
	}
	return profit_bound1;
}
int knapsack_basic(int W,int n,int c[],int w[],int flag)
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
	dummy.bound1 = 0;
	dummy.count = 0;
	int maxprofit=0;
	int profit_bound1;
	push(queue,dummy,&front,&rear,10000);
	struct node u;
	int x;
	int cnt=0;
	while(!isEmpty(rear)){
		u = pop(queue,&rear,&front,10000);
//		printf("%d %d %d %d\n",u.level,u.profit,u.weight,u.bound1);
		if(u.level == n-1){
			continue;
		}
		
		struct node v;
		v.level = u.level+1;
		v.weight = u.weight + w[v.level];
		v.profit = u.profit + c[v.level];

		v.count = u.count+1;
		if(v.weight<=W&&v.profit>maxprofit){
			maxprofit = v.profit;
			x = v.count;
			cnt++;
		}
		if(flag == 0 ){
			v.bound1 = bound1(v,n,W,c,w,n);
		}
		else if(flag == 1 ){
			v.bound1 = bound2(v,n,W,c,w,n);
		}
		if(v.bound1>maxprofit){
			push(queue,v,&front,&rear,10000);
			cnt++;
		}
		//printf("have %d %d %d %d        %d %d\n",v.level,v.profit,v.weight,v.bound1,cnt,maxprofit);
		v.weight = u.weight;
		v.profit = u.profit;
		v.count = u.count;
		if(flag == 0 ){
			v.bound1 = bound1(v,n,W,c,w,n);
		}
		else if(flag == 1 ){
			v.bound1 = bound2(v,n,W,c,w,n);
		}
		if(v.bound1>maxprofit){
			push(queue,v,&front,&rear,10000);
			//cnt++;
		}
	//	printf("not %d %d %d %d        %d %d\n",v.level,v.profit,v.weight,v.bound1,cnt,maxprofit);
	}
	printf("count := %d pr %d \n",cnt,maxprofit);
	if(flag == 0) cnt--;
	return cnt;
}

void knapsack(int W,int n,int c[],int w[],int nodes[]){
	int i,j;
	nodes[0] = knapsack_basic(W,n,c,w,0);
	nodes[1] = knapsack_basic(W,n,c,w,1);
	printf("%d %d\n",nodes[0],nodes[1]);
}

