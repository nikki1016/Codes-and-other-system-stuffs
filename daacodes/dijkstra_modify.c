// to a count of the number of different minimal length paths from s to v for every node v.
/* 	if(distance[q] > distance[j] + arr[j][q]) 
		N[q] = N[j];
	else if(distance[q] == distance[j] + arr[j][q]) 
		N[q] = N[j] + 1;
 */


/* to modify Dijkstra's algorithm so that if there is more than one minimum path from v to w, a path with the fewest number of edges is chosen.

	Use an array numEdges such that for any vertex u, numEdges[u] is the shortest number of edges on a path of distance du from s to u known so far. Thus numEdges is used as a tiebreaker when selecting the vertex to mark. As before, v is the vertex marked known, and w is adjacent to v.
	If dv + cv,w = dw, then change pw to v and numEdges[w] to numEdges[v] + 1 if numEdges[v] + 1 < numEdges[w].
	If dv + cv,w < dw, then update pw and dw, and set numEdges[w] to numEdges[v] + 1.
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
int dij_three(int **arr,int parent[],int N[]int s,int t,int n){
	int distance[n];
	int visited[n],q;
	int i;
	int j;
	for(i =0; i<n; i++){
		visited[i]=0;
		distance[i] = INF;
		parent[i] = NIL;
		N[i] = 0;
	}
	int hs = n,k;
	distance[s] =0;
	while(hs){
		j = find_MIN(distance,visited,n);
		hs--;
		if(j == -1) break;
		visited[j]=1;
		for(q=0; q<n; q++){
			if(q == j || arr[j][q]==0 )  
				continue;
		  //      printf("               q %d dis %d\n",q,distance[q]);
			if(arr[j][q] != 0 && visited[q]==0 && distance[q] > distance[j] + arr[j][q]){        
				distance[q] = distance[j] + arr[j][q];
				parent[q] = j;
				N[q] = N[j];
			}
			else if(arr[j][q] != 0 && visited[q]==0 && distance[q] == distance[j] + arr[j][q]){        
				distance[q] = distance[j] + arr[j][q];
				parent[q] = j;
				N[q] = N[j]+1;
			}
			
		}
		
	}
	return distance[t];
}
