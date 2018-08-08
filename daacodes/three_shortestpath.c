/*

Essentially, for any given vertex in a graph, you are going to find the three shortest paths to it from the source.
Following are the specifications for input and output to your program.
	1. The first line contains the number of vertices in the graph.
	2. Each subsequent line of input contains 3 natural numbers u, v, w (seperated by space) where (u,v) is an edge and w is the weight of 		the edge. 
	3. For your convinience, the vertices are numbered as consecutive natural numbers starting from 0. 
	4. Number of edges in the input is not specified apriori. You have to continue reading the input till you encounter a line of the form 		−1 − 10.
	5. The line after the end of the graph (after the line containing −1, −1, 0) contains two natural numbers s, t the source and target 		vertices.
	6. The output should have three lines where each line, representing a path between s and t, contains a sequence of natural numbers
		• The first number represent the cost of the path.
		• All subsequent numbers represent the sequence of vertices in the path.
	7. The ouput should have the three shortest paths between s and t.

*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
#define INF 999999
#define NIL -1

int find_MIN(int arr[],int p[],int n){
	int i,min=99999,ind = -1;
	for(i =0;i<n;i++){
		if(arr[i] < min && p[i] == 0){
			min = arr[i];
			ind = i;
		}
		//printf("%d distance %d i\n",arr[i],i);
	}
	return ind;
}
int dij_three(int **arr,int parent[],int s,int t,int n){
	int distance[n];
	int visited[n],q;
	int i;
	int j;
	for(i =0; i<n; i++){
		visited[i]=0;
		distance[i] = INF;
		parent[i] = NIL;
	}
	int hs = n,k;
	distance[s] =0;
	while(hs){
		j = find_MIN(distance,visited,n);
		hs--;
		//printf("%d j \n",j);
		if(j == -1) break;
		visited[j]=1;
		for(q=0; q<n; q++){
			if(q == j || arr[j][q]==0 )  
				continue;
		      //  printf("               q %d dis %d\n",q,distance[q]);
			if(arr[j][q] != 0 && visited[q]==0 && distance[q] > distance[j] + arr[j][q]){        
				distance[q] = distance[j] + arr[j][q];
				parent[q] = j;
			}
			// to a count of the number of different minimal length paths from s to v for every node v.
		/* 	if(distance[q] > distance[j] + arr[j][q]) 
				N[q] = N[j];
			else if(distance[q] == distance[j] + arr[j][q]) 
				N[q] = N[j] + 1;
 		 */
		}
		
	}
	//for(i =0;i<n;i++)          printf("final   ind %d   dis %d\n",i,distance[i]);
	return distance[t];
}
void disjkstra(int **arr,int n,int parent1[],int parent2[],int parent3[],int s,int t){
	if(dij_three(arr,parent1,s,t,n) == INF){
		parent1[t] = -1;
		parent2[t] = -1;
		parent3[t] = -1;
		return;
	}
	printf("smallest distance is %d\n",dij_three(arr,parent1,s,t,n));
	int temp=t,par,min=99,k=0;
	int mm[n*n], a[n*n], b[n*n], c[n*n], d[n*n], i=0;
	while(temp != s){
		par = parent1[temp];
		k = arr[par][temp];
		arr[par][temp] = 0;
		a[i] = par;
		b[i] = temp;
		mm[i] = dij_three(arr,parent2,s,t,n);
		//printf(" %d  on removing %d -> %d edge :  %d\n",i,a[i],b[i],mm[i]);
		i++;
		arr[par][temp] = k;
		temp=par;

	}
	min = mm[0];
	temp=0;	
	for(par = 1; par < i; par++) {
		if(mm[par] < min){
			min = mm[par];
			temp = par;
		}
	}
	k = arr[a[temp]][b[temp]];
	arr[a[temp]][b[temp]] = 0;
	if(dij_three(arr,parent2,s,t,n) == INF){
		parent2[t] = -1;
		parent3[t] = -1;
		return;
	}
	printf("smallest distance is %d\n",dij_three(arr,parent2,s,t,n));
	arr[a[temp]][b[temp]] = k;

	int par2, temp2 = t, k2;
	i = 0;
	temp = t;
	while(temp != s){
		par = parent1[temp];
		k = arr[par][temp];
		arr[par][temp] = 0;
		temp2 = t;
		while(temp2 != s){
			par2 = parent2[temp2];
			k2 = arr[par2][temp2];
			arr[par2][temp2] = 0;
			a[i] = par;
			b[i] = temp;
			c[i] = par2;
			d[i] = temp2;
			if(a[i] == c[i] && b[i] == d[i]){
				arr[par2][temp2] = k2;
				temp2 = par2;
				continue;
			}
			mm[i] = dij_three(arr,parent3,s,t,n);
			//printf(" %d  on removing %d -> %d && %d -> %d  edge :  %d\n",i,a[i],b[i],c[i],d[i],mm[i]);
			i++;
			arr[par2][temp2] = k2;
	      		temp2 = par2;
		}
		arr[par][temp] = k;
		temp=par;
	}
	min = mm[0];
	temp=0;
	for(par = 1; par < i; par++) {
		if(mm[par] < min){
			min = mm[par];
			temp = par;
		}
	}
	k = arr[a[temp]][b[temp]];
	k2 = arr[c[temp]][d[temp]];
	arr[a[temp]][b[temp]] = 0;
	arr[c[temp]][d[temp]] = 0;
	if(dij_three(arr,parent3,s,t,n) == INF){
		parent3[t] = -1;
		return;
	}
	printf("smallest distance is %d\n",dij_three(arr,parent3,s,t,n));
	arr[a[temp]][b[temp]] = k;
	arr[c[temp]][d[temp]] = k2;

	
}


int main()
{
	int **adj, *parent1,*parent2,*parent3;
	
	int n,k,i,j,w,s,t,temp;
	scanf("%d",&n);
	adj = (int **)calloc(n,sizeof(int *));
	for(i=0;i<n;i++)
    	{
      		adj[i] = (int *)calloc(n,sizeof(int));
    	}
	  parent1 = (int *)calloc(n,sizeof(int));
	  parent2 = (int *)calloc(n,sizeof(int));
	  parent3 = (int *)calloc(n,sizeof(int));
	  
	  scanf("%d%d%d",&i,&j,&k);
	  while(i!=-1)
	    {
	      adj[i][j]=k;
	      scanf("%d%d%d",&i,&j,&k);
	    }
	
	  scanf("%d%d",&s,&t);
	  disjkstra(adj,n,parent1,parent2,parent3,s,t);
	  temp=t;
	  printf("\npath1: %d",t);
	  if(parent1[temp] == -1)
	   	printf("\nNo path");
	  else {
		while(temp!=s)
		    {
		      printf("->%d",parent1[temp]);
		      temp=parent1[temp];
		    }
	  }
	  temp=t;
	  if(parent2[temp] == -1)
	   	printf("\nNo path");
	  else {
	  	printf("\npath2: %d",t);
		while(temp!=s)
		    {
		      printf("->%d",parent2[temp]);
		      temp=parent2[temp];
		    }
	  }
	  temp=t;
	  if(parent3[temp] == -1)
	   	printf("\nNo path\n");
	  else {
		  printf("\npath3: %d",t);
		while(temp!=s)
		    {
		      printf("->%d",parent3[temp]);
		      temp=parent3[temp];
		    }
	  }
	  return 0;
}


