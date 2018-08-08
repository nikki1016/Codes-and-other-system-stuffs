#include<stdio.h>
#include<math.h>
double dist(int arr[],int brr[]){
	return sqrt(  (arr[0]-brr[0])*(arr[0]-brr[0]) + (arr[1]-brr[1]) * (arr[1]-brr[1]) + (arr[2]-brr[2])*(arr[2]-brr[2]) );
}
double bruteforce(int arr[][3],int low,int high,int a[],int b[]){
	int i,j;
	double min=99999;
	for(i = low; i< high; i++){
		for(j =i+1; j<=high; j++){
			if(min > dist(arr[i],arr[j])){
				min = dist(arr[i],arr[j]);
				a[0] = arr[i][0];
				a[1]= arr[i][1];
				a[2]= arr[i][2];
				b[2] = arr[j][2];
				b[0] = arr[j][0];
				b[1]= arr[j][1];
			}
		}
	}
	return min;
}
double  merge(int arr[][3],int n,int a[],int b[],double d){
	int i,j;
	double min=9999;
	for(i=0;i<n-1; i++){
		for(j = i+1; j <n ; j++){
			if( dist(arr[i],arr[j]) < min){
				min = dist(arr[i],arr[j]);
				a[0] = arr[i][0];
				a[1]= arr[i][1];
				a[2]= arr[i][2];
				b[2] = arr[j][2];
				b[0] = arr[j][0];
				b[1]= arr[j][1];
			}
		}
	}
	return min;
}				

double closest(int arr[][3],int low,int high,int a[],int b[]){
	if(high - low + 1 < 2 ) 
		return 9999;
	if(high - low + 1 <= 3){
		return bruteforce(arr,low,high,a,b);
	}
	int mid = (high+low )/2;
	int  c[3], d[3], e[3], f[3];
	double dl = closest(arr,low,mid,c,d);
	double dr = closest(arr,mid+1,high,e,f),dd=0.0,g;
	if(dl > dr){
		dd = dr;
		a[0] = e[0];
		a[1] = e[1];
		a[2] = e[2];
		b[0] = f[0];
		b[2] = f[2];
		b[1] = f[1];
	}
	else {
		dd = dl;
		a[0] = c[0];
		a[1] = c[1];
		a[2] = c[2];
		b[2] = d[2];
		b[0] = d[0];
		b[1] = d[1];
	}
	int split[30][3],i,j,k=0;
	for(i=low; i <= high; i++){
		if(abs(arr[i][0] - arr[mid][0]) <= dd){
			split[k][0] = arr[i][0];
			split[k][1] = arr[i][1];
			split[k++][2] = arr[i][2];
		}
		
	}
	g = merge(split,k,e,f,dd);
	if(g < dd){
		dd = g;
		a[0] = e[0];
		a[1] = e[1];
		a[2] = e[2];
		b[0] = f[0];
		b[2] = f[2];
		b[1] = f[1];
	}
	return dd;
}


//a & b store the closest points 
double closestpoints(int arr[][3],int n,int a[],int b[]){
	int i,j;
	for(i =0; i<n-1; i++){
		for(j=i+1;j<n;j++){
			if(arr[i][0] > arr[j][0]){
				int temp  = arr[i][0];
				arr[i][0] = arr[j][0];
				arr[j][0] = temp;
				temp  = arr[i][1];
				arr[i][1] = arr[j][1];
				arr[j][1] = temp;
				temp  = arr[i][2];
				arr[i][2] = arr[j][2];
				arr[j][2] = temp;
			}
		}
	}
	return closest(arr,0,n-1,a,b);
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n][3];
	int i,a[3], b[3],j;
	double d=0;
	for(i =0; i<n;i++)
		scanf("%d%d%d",&arr[i][0],&arr[i][1],&arr[i][2]);
	double minDist = 9999;
	for( i = 0; i<n-1; i++){
 		for( j = i + 1; j<n ; j++){
  			if (dist(arr[i],arr[j]) < minDist){
		   		minDist = dist(arr[i],arr[j]);
				a[0] = arr[i][0];
				a[1] = arr[i][1];
				a[2] = arr[i][2];
				b[0] = arr[j][0];
				b[1] = arr[j][1];
				b[2] = arr[j][2];
			}
		}
	}
	printf("%d %d %d && %d %d %d : %lf\n",a[0],a[1],a[2],b[0],b[1],b[2],minDist);
	d = closestpoints(arr,n,a,b);
	printf("%d %d %d && %d %d %d : %lf\n",a[0],a[1],a[2],b[0],b[1],b[2],d);
	
	return 0;
}
