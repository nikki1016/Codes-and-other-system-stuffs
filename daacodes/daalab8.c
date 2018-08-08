/*

1. Write a code for finding out the closest pair of points among a list of given points on a plane. Note that you have to return the points and not the distance between them.
	void closestpair2d(struct point2d *close2d, struct point2d *points, int n)


2. Extend the idea of finding closest pair of points on a plane to finding the closest pair of points in a three-dimensional space and write a function for it. Note that finding an efficient bound for the strip in 3-d case, analogous to the 2-d case is hard. In case of 3-d points you can compare every point with every other point within the strip.
	void closestpair3d(struct point3d *close3d, struct point3d *plane,int m)

3. Remember that in Kruskal’s algorithm, at each step, we were trying to find out the minimum weight edge and checking whether it is safe or not. Consider the case of “Euclidean MST” where the edge weight between any two point is the distance between them. Use a modified version of the function defined in 1. to find the Euclidean MST of a given set of points in a plane. (Note that this is not the most efficient way of finding an Euclidean MST).
			func euclideanMST(struct point2d **mst,struct point2d *points,int n)

*/

#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define INF 99999

struct point2d {
  int x,y;
};

struct point3d {
  int x,y,z;
};

struct set{
	int x;
	int y;
	int root;
};

void makeset(struct set  set[],int n,struct point2d *points){
	int i;
	for(i =0; i<n; i++){
		set[i].x = points[i].x;
		set[i].y = points[i].y;
		set[i].root = i ; //hash(x,y);
	}
}
void union_set(struct set  set[],int n,int u1,int v1,int u2,int v2){
	int i ,j = -1,k=-1;
	for(i =0; i<n; i++){
		if(set[i].x == u2 && set[i].y == v2)
			j = i; 
		if(set[i].x == u1 && set[i].y == v1)
			k = i; 
	}
	i = j;
	while( i != set[i].root && i < n){
		//printf("union i %d parent %d\n",i,set[i].root);
		i = set[i].root;
	}
	set[i].root = set[k].root;
}
int find( struct set  set[],int n,int u,int v){
	int i ;
	for(i =0; i<n; i++){
		if(set[i].x == u && set[i].y == v)
			break ; 
	}
		//printf("i %d parent %d\n",i,set[i].root);
	while( i != set[i].root && i <n){
		//printf("i %d parent %d\n",i,set[i].root);
		i = set[i].root;
	}
	return i;
}

double dist(struct point2d * arr,struct point2d * brr){
	double t = sqrt(  (arr->x -brr->x)*(arr->x - brr->x) + (arr->y - brr->y) * (arr->y - brr->y)); 
	return t;
}
int  find_edge(struct point2d **mst,int m, struct point2d a,struct point2d b){
	int i;
	for(i =0; i<m; i++){
		if(mst[i][0].x == a.x && mst[i][0].y == a.y && mst[i][1].x == b.x && mst[i][1].y == b.y){
			//printf("find_edge 0\n");
			return 0;
		}
		else if(mst[i][0].x == b.x && mst[i][0].y == b.y && mst[i][1].x == a.x && mst[i][1].y == a.y){
			//printf("find_edge 0\n");
			return 0;
		}	
	}
	//printf("find_edge 1\n");
	return 1;
}
double bruteforce(struct point2d *close, struct point2d *points, int low,int high,struct point2d **mst,int m){
	int i,j;
	double min=INF;
	for(i = low; i< high; i++){
		for(j =i+1; j<=high; j++){
			if(min > dist( &points[i], &points[j] ) && find_edge(mst,m,points[i],points[j])){
				min = dist(&points[i],&points[j]);
				close[0] = points[i];
				close[1]= points[j];
			}
		}
	}
	return min;
}
double  merge(struct point2d *points,int n,struct point2d *close,double d,struct point2d **mst,int m){
	int i,j;
	double min=INF;
	for(i =0; i<n-1; i++){
		for(j=i+1;j<n;j++){
			if(points[i].y > points[j].y){
				struct point2d temp  = points[i];
				points[i] = points[j];
				points[j] = temp;
			}
		}
	}
	for(i=0;i<n; i++){
		for(j = i+1; j <n && abs(points[i].y - points[j].y) <= d; j++){
			if( dist( &points[i],&points[j]) < min && find_edge(mst,m,points[i],points[j])){
				min = dist(&points[i],&points[j]);
				close[0] = points[i];
				close[1]= points[j];
			}
		}
	}
	return min;
}
double closest(struct point2d *close2d, struct point2d *points, int low,int high,struct point2d **mst,int m){
	if(high - low + 1 <2 ) 
		return INF;
	if(high - low + 1 <= 3){
		//printf("closest  brute inside\n");
		return bruteforce(close2d,points,low,high,mst,m);
	}
	int mid = (high+low )/2;
	struct point2d c[2], d[2];
	double dl = closest(c,points,low,mid,mst,m);
	//printf("closest left inside    %lf dl\n",dl);
	double dr = closest(d,points,mid+1,high,mst,m);
	//printf("closest right inside    %lf dr \n",dr);
	double dd=0.0,g; 
	if(dl > dr){
		dd = dr;
		close2d[0] = d[0];
		close2d[1] = d[1];
	}
	else {
		dd = dl;
		close2d[0] = c[0];
		close2d[1] = c[1];
	}
	struct point2d split[20];
	int i,j,k=0;
	//printf("\nsplit %lf dd\n",dd);
	for(i=low; i<=high; i++){
		if(abs(points[i].x - points[mid].x) <= dd ){//  && find_edge(mst,m,points[i],points[j]) ){
			split[k] = points[i];
			k++;
		}
	}
	//printf("merge inside\n");
	g = merge(split,k,d,dd,mst,m);
	//printf("merge outside\n");
	if(g < dd){
		dd = g;
		close2d[0] = d[0];
		close2d[1] = d[1];
	}
	//printf("\nmerge %lf dd\n",dd);
	return dd;
}	

double closestpair(struct point2d *close, struct point2d *points, int n,struct point2d **mst,int m)
{
	int i,j;
	for(i =0; i<n-1; i++){
		for(j=i+1;j<n;j++){
			if(points[i].x > points[j].x){
				struct point2d temp  = points[i];
				points[i] = points[j];
				points[j] = temp;
			}
		}
	}
	//printf("closestpair inside\n");
	double d = closest(close,points,0,n-1,mst,m);
	//sprintf("%lf   : %d %d && %d %d\n",d,close[0].x,close[0].y,close[1].x,close[1].y);
  /* find out the closest pair of points among the points in "points" and store them in the pointsay close */
	return d;
}			


void euclideanMST(struct point2d **mst,struct point2d *points,int n)
{
  /* find out the Euclidean MST and store the MST in -pointsay mst.
     Each of the n-1 edges are store by storing it's two endpoints.
  */
	struct point2d close2d[2];
	struct set set[n];
	makeset(set,n,points);
	int i = 0,k=0,w,hs = n-1;
	struct point2d **temp;
	temp = (struct point2d **)malloc((n+1)*(n/2)*sizeof(struct point2d *));
	for(i=0;i<(n+1)*n/2;i++)
	    	temp[i]=(struct point2d *)malloc(2*sizeof(struct point2d));
	i =0;
	while(k < n){
		double d = closestpair(close2d,points,n,temp,i);
		if(d == INF) break;
		int a = find(set,n,close2d[0].x,close2d[0].y);
		//printf("a %d\n",a);
		int b = find(set,n,close2d[1].x,close2d[1].y);
		//printf("bb        %d\n",i);
		temp[i][0] = close2d[0];
		temp[i][1] = close2d[1];
		i++;
		if( a != b){
			mst[k][0] = close2d[0];
			mst[k][1] = close2d[1];
			union_set(set,n,close2d[0].x,close2d[0].y,close2d[1].x,close2d[1].y) ;
			a = find(set,n,close2d[0].x,close2d[0].y);
			//printf("union   a %d\n",a);
			b = find(set,n,close2d[1].x,close2d[1].y);
			//printf("      dd  k        %lf  %d : %d %d && %d %d\n",d,k,mst[k][0].x,mst[k][0].y,mst[k][1].x,mst[k][1].y);
			k++;
			//printf("union   b %d\n",b);
		}
	}
	for(i=0;i<n-1;i++)
	    	printf("mst   %d %d && %d %d\n",mst[i][0].x,mst[i][0].y,mst[i][1].x,mst[i][1].y);

}

double dist2d(struct point2d * arr,struct point2d * brr){
	double t = sqrt(  (arr->x -brr->x)*(arr->x - brr->x) + (arr->y - brr->y) * (arr->y - brr->y)); 
	return t;
}
double bruteforce2d(struct point2d *close2d, struct point2d *points, int low,int high){
	int i,j;
	double min=99999;
	for(i = low; i< high; i++){
		for(j =i+1; j<=high; j++){
			if(min > dist2d( &points[i], &points[j] )){
				min = dist2d(&points[i],&points[j]);
				close2d[0] = points[i];
				close2d[1]= points[j];
			}
		}
	}
	return min;
}
double  merge2d(struct point2d *points,int n,struct point2d *close2d,double d){
	int i,j;
	double min=9999;
	for(i =0; i<n-1; i++){
		for(j=i+1;j<n;j++){
			if(points[i].y > points[j].y){
				struct point2d temp  = points[i];
				points[i] = points[j];
				points[j] = temp;
			}
		}
	}
	for(i=0;i<n; i++){
		for(j = i+1; j <n && abs(points[i].y - points[j].y) <= d; j++){
			if( dist2d( &points[i],&points[j]) < min){
				min = dist2d(&points[i],&points[j]);
				close2d[0] = points[i];
				close2d[1]= points[j];
			}
		}
	}
	return min;
}				

double closest2d(struct point2d *close2d, struct point2d *points, int low,int high){
	if(high - low + 1 <2 ) 
		return 999999;
	if(high - low + 1 <= 3){
		return bruteforce2d(close2d,points,low,high);
	}
	int mid = (high+low )/2;
	struct point2d c[2], d[2];
	double dl = closest2d(c,points,low,mid);
	double dr = closest2d(d,points,mid+1,high);
	double dd=0.0,g; 
	if(dl > dr){
		dd = dr;
		close2d[0] = d[0];
		close2d[1] = d[1];
	}
	else {
		dd = dl;
		close2d[0] = c[0];
		close2d[1] = c[1];
	}
	struct point2d split[20];
	int i,j,k=0;
	for(i=low; i<=high; i++){
		if(abs(points[i].x - points[mid].x) <= dd){
			split[k] = points[i];
			k++;
		}
	}
	g = merge2d(split,k,d,dd);
	if(g < dd){
		dd = g;
		close2d[0] = d[0];
		close2d[1] = d[1];
	}
	return dd;
}

double dist3d(struct point3d * arr,struct point3d * brr){
	double t = sqrt(  (arr->x -brr->x)*(arr->x - brr->x) + (arr->y - brr->y) * (arr->y - brr->y) + (arr->z -brr->z)*(arr->z - brr->z) ); 
	return t;
}
double bruteforce3d(struct point3d *close3d, struct point3d *points, int low,int high){
	int i,j;
	double min=99999;
	for(i = low; i< high; i++){
		for(j =i+1; j<=high; j++){
			if(min > dist3d( &points[i], &points[j] )){
				min = dist3d(&points[i],&points[j]);
				close3d[0] = points[i];
				close3d[1]= points[j];
			}
		}
	}
	return min;
}
double  merge3d(struct point3d *points,int n,struct point3d *close3d,double d){
	int i,j;
	double min=9999;
	for(i =0; i<n-1; i++){
		for(j=i+1;j<n;j++){
			if(points[i].y > points[j].y){
				struct point3d temp  = points[i];
				points[i] = points[j];
				points[j] = temp;
			}
		}
	}
	for(i=0;i<n; i++){
		for(j = i+1; j <n ; j++){
			if( dist3d( &points[i],&points[j]) < min){
				min = dist3d(&points[i],&points[j]);
				close3d[0] = points[i];
				close3d[1]= points[j];
			}
		}
	}
	return min;
}				
	

double closest3d(struct point3d *close3d, struct point3d *points, int low,int high){
	if(high - low + 1 <2 ) 
		return 999999;
	if(high - low + 1 <= 3){
		return bruteforce3d(close3d,points,low,high);
	}
	int mid = (high+low )/2;
	struct point3d c[2], d[2];
	double dl = closest3d(c,points,low,mid);
	double dr = closest3d(d,points,mid+1,high);
	double dd=0.0,g; 
	if(dl > dr){
		dd = dr;
		close3d[0] = d[0];
		close3d[1] = d[1];
	}
	else {
		dd = dl;
		close3d[0] = c[0];
		close3d[1] = c[1];
	}
	struct point3d split[20];
	int i,j,k=0;
	for(i=low; i<=high; i++){
		if(abs(points[i].x - points[mid].x) <= dd){
			split[k] = points[i];
			k++;
		}
	}
	g = merge3d(split,k,d,dd);
	if(g < dd){
		dd = g;
		close3d[0] = d[0];
		close3d[1] = d[1];
	}
	return dd;
}


void closestpair2d(struct point2d *close2d, struct point2d *points, int n)
{
	int i,j;
	for(i =0; i<n-1; i++){
		for(j=i+1;j<n;j++){
			if(points[i].x > points[j].x){
				struct point2d temp  = points[i];
				points[i] = points[j];
				points[j] = temp;
			}
		}
	}
	double d = closest2d(close2d,points,0,n-1);
	printf("%lf   : %d %d && %d %d\n",d,close2d[0].x,close2d[0].y,close2d[1].x,close2d[1].y);
  /* find out the closest pair of points among the points in "points" and store them in the pointsay close2d */
}

void closestpair3d(struct point3d *close3d, struct point3d *plane,int m)
{
	int i,j;
	for(i =0; i<m-1; i++){
		for(j=i+1;j<m;j++){
			if(plane[i].x > plane[j].x){
				struct point3d temp  = plane[i];
				plane[i] = plane[j];
				plane[j] = temp;
			}
		}
	}
	double d = closest3d(close3d,plane,0,m-1);
	printf("%lf   : %d %d %d && %d %d %d\n",d,close3d[0].x,close3d[0].y,close3d[0].z,close3d[1].x,close3d[1].y,close3d[1].z);

  /* find out the closest pair of points among the points in "plane" and store them in the pointsay close3d */
}

int main()
{
	  struct point2d *points,close2d[2],**mst;
	  struct point3d *plane,close3d[2];
	  int i,n,m;
	  scanf("%d",&n);
	  points = (struct point2d *)malloc(n*sizeof(struct point2d));
	  for(i=0;i<n;i++)
	    	scanf("%d%d",&(points[i].x),&(points[i].y));

	  scanf("%d",&m);
	  plane = (struct point3d *)malloc(m*sizeof(struct point3d));
	  for(i=0;i<m;i++)
	    	scanf("%d%d%d",&(plane[i].x),&(plane[i].y),&(plane[i].z));

	  closestpair2d(close2d,points,n);
	  closestpair3d(close3d,plane,m);

	  mst = (struct point2d **)malloc((n-1)*sizeof(struct point2d *));
	  for(i=0;i<n;i++)
	    	mst[i]=(struct point2d *)malloc(2*sizeof(struct point2d));
	  euclideanMST(mst,points,n);
	  return 0;
}

