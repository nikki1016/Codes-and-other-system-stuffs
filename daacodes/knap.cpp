#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
struct Item
{
   float weight;
   int value;
};

struct Node
{
   int level, profit, bound;
   float weight;
};
bool cmp(Item a, Item b)
{
   double r1 = (double)a.value / a.weight;
   double r2 = (double)b.value / b.weight;
   return r1 > r2;
}
int bound(Node u, int n, int W, Item arr[], int cnt, int p)
{
   if (u.weight >= W || cnt>p)
      return 0;

   int profit_bound = u.profit;

   int j = u.level + 1;
   int totweight = u.weight;

   while ((j < n) && (totweight + arr[j].weight <= W) && cnt<p)
   {
      totweight    += arr[j].weight;
      profit_bound += arr[j].value;
      j++;
      cnt++;
   }

   if (j < n && cnt<p)
      profit_bound += (W - totweight) * arr[j].value /
	 arr[j].weight;

   return profit_bound;
}
int bound(Node u, int n, int W, Item arr[])
{
   if (u.weight >= W)
      return 0;

   int profit_bound = u.profit;

   int j = u.level + 1;
   int totweight = u.weight;

   while ((j < n) && (totweight + arr[j].weight <= W))
   {
      totweight    += arr[j].weight;
      profit_bound += arr[j].value;
      j++;
   }

   if (j < n)
      profit_bound += (W - totweight) * arr[j].value /
	 arr[j].weight;

   return profit_bound;
}
int knapsack_basic(int,int,int *,float *);
int knapsack_constrained(int,int,int *,float *,int);
int knapsack_multiple(int,int *,int,int *,float *);
int main()
{
   int i,W,n,m,*c,p,*mW;
   float *w;
   scanf("%d",&n);
   scanf("%d",&W);
   c=(int *)malloc(n*sizeof(int));
   w=(float *)malloc(n*sizeof(float));
   for(i=0;i<n;i++)
      scanf("%d",&c[i]);
   for(i=0;i<n;i++)
      scanf("%f",&w[i]);
   printf("Knapsack Basic : %d\n",knapsack_basic(W,n,c,w));
   scanf("%d",&n);
   scanf("%d",&W);
   c=(int *)malloc(n*sizeof(int));
   w=(float *)malloc(n*sizeof(float));
   for(i=0;i<n;i++)
      scanf("%d",&c[i]);
   for(i=0;i<n;i++)
      scanf("%f",&w[i]);
   scanf("%d",&p);
   printf("Knapsack Constrained : %d\n",knapsack_constrained(W,n,c,w,p));
   scanf("%d",&n);
   scanf("%d",&m);
   mW=(int *)malloc(m*sizeof(int));
   c=(int *)malloc(n*sizeof(int));
   w=(float *)malloc(n*sizeof(float));
   for(i=0;i<m;i++)
      scanf("%d",&mW[i]);
   for(i=0;i<n;i++)
      scanf("%d",&c[i]);
   for(i=0;i<n;i++)
      scanf("%f",&w[i]);
    printf("Knapsack Multiple : \n"),knapsack_multiple(m,mW,n,c,w);
   return 0;
}

int knapsack_basic(int W,int n,int *c,float *w)
{
   Item arr[100];
   int i;
   for(i=0;i<n;i++){
      arr[i].value = c[i];
      arr[i].weight = w[i];
   }

   sort(arr, arr + n, cmp);
   queue<Node> Q;
   Node u, v;
   u.level = -1;
   u.profit = u.weight = 0;
   Q.push(u);
   int maxProfit = 0;
   while (!Q.empty())
   {
      u = Q.front();
      Q.pop();
      if (u.level == -1)
	 v.level = 0;
      if (u.level == n-1)
	 continue;
      v.level = u.level + 1;
      v.weight = u.weight + arr[v.level].weight;
      v.profit = u.profit + arr[v.level].value;
      if (v.weight <= W && v.profit > maxProfit)
		 maxProfit = v.profit;
      v.bound = bound(v, n, W, arr);
      int tmp = v.bound;
      if (v.bound > maxProfit )
	 Q.push(v);
      v.weight = u.weight;
      v.profit = u.profit;
      v.bound = bound(v, n, W, arr);
      if (v.bound > maxProfit)
	 Q.push(v);
   }

   return maxProfit;

}
int knapsack_constrained(int W,int n,int *c,float *w,int p)
{
	 Item arr[100];
   int i;
   for(i=0;i<n;i++){
      arr[i].value = c[i];
      arr[i].weight = w[i];
   }
	int cnt = 0;
   sort(arr, arr + n, cmp);
   queue<Node> Q;
   Node u, v;
   u.level = -1;
   u.profit = u.weight = 0;
   Q.push(u);
   int maxProfit = 0;
   while (!Q.empty())
   {
      u = Q.front();
      Q.pop();
      if (u.level == -1)
	 v.level = 0;
      if (u.level == n-1)
	 continue;
      v.level = u.level + 1;
      v.weight = u.weight + arr[v.level].weight;
      v.profit = u.profit + arr[v.level].value;
      if (v.weight <= W && v.profit > maxProfit && cnt<p)
	 maxProfit = v.profit;
      v.bound = bound(v, n, W, arr, cnt,p);
      int tmp = v.bound;

      if (v.bound > maxProfit && cnt<p)
	 Q.push(v);
      v.weight = u.weight;
      v.profit = u.profit;
      v.bound = bound(v, n, W, arr, cnt, p);
      if (v.bound > maxProfit && cnt<=p)
	 Q.push(v);
      if(v.bound < tmp)
	 cnt++;
   }

   return maxProfit;

   
}

int knapsack_multiple(int m,int *mW,int n,int *c,float *w)
{

   Item arr[100];
   int i, l, ans = 0;
   bool chk[100];
   for(l=0;l<m;l++)
   {
   	int W = mW[l];

   for(i=0;i<n;i++){
      arr[i].value = c[i];
      arr[i].weight = w[i];
   }
   sort(arr, arr + n, cmp);
   queue<Node> Q;
   Node u, v;
   u.level = -1;
   u.profit = u.weight = 0;
   Q.push(u);
   int maxProfit = 0;
   while (!Q.empty())
   {
      u = Q.front();
      Q.pop();
      if (u.level == -1)
	 v.level = 0;
      if (u.level == n-1)
	 continue;
      v.level = u.level + 1;
      v.weight = u.weight + arr[v.level].weight;
      v.profit = u.profit + arr[v.level].value;
      if (v.weight <= W && v.profit > maxProfit)
			 maxProfit = v.profit;
      v.bound = bound(v, n, W, arr);
      int tmp = v.bound;

      if (v.bound > maxProfit)
		 Q.push(v);
      v.weight = u.weight;
      v.profit = u.profit;
      v.bound = bound(v, n, W, arr);
      if (v.bound > maxProfit)
	 	Q.push(v);
   }

   cout<< maxProfit  << " ";
}
}

