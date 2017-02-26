#include<stdio.h>
#define infinity 99999
struct que{
	int value;
	int index;
};
void restoredown(struct  que q[],int hs,int v){
	int data,l,h,i,min = v;
	data = q[v].value;
	i = q[1].index;
	l = 2*v;
	h = l+1;
	while(l <= hs ){
		if(q[l].value < q[v].value && l<=hs)
			min = l;
		if(q[h].value < q[min].value && h <=hs)
			min = h;
		if(min != v){
			q[v].value = q[min].value;
			q[v].index = q[min].index;
			v= min;
			l = v*2;
			h = l+1;
		}
		else break;
	}
	q[min].value = data;
	q[min].index = i;
}
void buildheap(int dis[],struct que q[100],int n){
	int i;
	for(i =1; i<= n; i++){
		q[i].value = dis[i];
		q[i].index = i;
	}
//printf("hi\n");
	for(i = n/2; i>0; i--)
		restoredown(q,n,i);
}

int delete(struct que q[],int *hs){
	int data = q[1].value,i;
	i = q[1].index;
	q[1].value = q[*hs].value;
	q[1].index = q[*hs].index;
	q[*hs].value = data;
	q[*hs].index = i;
	(*hs)--;
	restoredown(q,*hs,i);
	return i;
}
void decreasekey(struct que q[],int v,int value,int hs){
	int i;
	i = find(q,hs,v);
	q[i].value = value;
	for(i = hs/2; i>0; i--)
		restoredown(q,hs,i);
}
int find(struct que q[],int hs,int v){
	int i;
	for(i = 1; i<= hs; i++){
		if(q[i].index == v)
			return i;
	}
	return 0;
}
void printpath(int par[],int v){
	if(par[v] == -1)
		printf("%d ",v);
	else {
		printpath(par,par[v]);
		printf("%d ",v);
	}
}
void dijkstra(int adj[][100],int n,int v){
	int d[100],par[100],i,j,hs = 0;
	struct que q[100];
	for(i = 1; i<= n; i++){
		d[i] = infinity;
		par[i] = -1;
	}
	d[v] = 0;
	hs = n;
	buildheap(d,q,hs);
	while(hs != 0){
		i = delete(q,&hs);
		for(j = 1; j<=n; j++){
			if(adj[i][j] != 0 && find(q,hs,j)){
				if(d[j] > d[i] + adj[i][j]){
					d[j] = d[i] +adj[i][j];
					par[j] = i;
					decreasekey(q,j,d[j],hs);
				}
			}
		}
	}
	for(i = 1; i<= n; i++){
		if( i != v){
			printpath(par,i);
			printf(" --> %d \n",d[i]);
		}
	}
}

int main(){
	int adj[100][100],n,i,j;
	scanf("%d",&n);
	for(i =1; i<=n; i++)
		for(j = 1; j<=n; j++)
			scanf("%d",&adj[i][j]);
	scanf("%d",&i);
	dijkstra(adj,n,i);
	return 0;
}

