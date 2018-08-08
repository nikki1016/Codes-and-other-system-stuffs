#include<stdio.h>
#include<math.h>
double dist(int arr[],int brr[]){
	return sqrt(  (arr[0]-brr[0])*(arr[0]-brr[0]) + (arr[1]-brr[1]) * (arr[1]-brr[1])  );
}
double bruteforce(int arr[][2],int low,int high,int a[],int b[]){
	int i,j;
	double min=99999;
	for(i = low; i< high; i++){
		for(j =i+1; j<=high; j++){
			if(min > dist(arr[i],arr[j])){
				min = dist(arr[i],arr[j]);
				a[0] = arr[i][0];
				a[1]= arr[i][1];
				b[0] = arr[j][0];
				b[1]= arr[j][1];
			}
		}
	}
	return min;
}
double  merge(int arr[][2],int n,int a[],int b[],double d){
	int i,j;
	double min=9999;
	for(i =0; i<n-1; i++){
		for(j=i+1;j<n;j++){
			if(arr[i][1] > arr[j][1]){
				int temp  = arr[i][0];
				arr[i][0] = arr[j][0];
				arr[j][0] = temp;
				temp  = arr[i][1];
				arr[i][1] = arr[j][1];
				arr[j][1] = temp;
			}
		}
	}
	for(i=0;i<n; i++){
		for(j = i+1; j <n && abs(arr[i][1] - arr[j][1]) <= d;j++){
			if( dist(arr[i],arr[j]) < min){
				min = dist(arr[i],arr[j]);
				a[0] = arr[i][0];
				a[1]= arr[i][1];
				b[0] = arr[j][0];
				b[1]= arr[j][1];
			}
		}
	}
	return min;
}				

double closest(int arr[][2],int low,int high,int a[],int b[]){
	if(high - low + 1 <2 ) 
		return 999999;
	if(high - low + 1 <= 3){
		return bruteforce(arr,low,high,a,b);
	}
	int mid = (high+low )/2;
	int  c[2], d[2], e[2], f[2];
	double dl = closest(arr,low,mid,c,d);
	double dr = closest(arr,mid+1,high,e,f),dd=0.0,g; 
	if(dl > dr){
		dd = dr;
		a[0] = e[0];
		a[1] = e[1];
		b[0] = f[0];
		b[1] = f[1];
	}
	else {
		dd = dl;
		a[0] = c[0];
		a[1] = c[1];
		b[0] = d[0];
		b[1] = d[1];
	}
	int split[20][2],i,j,k=0;
	for(i=low; i<=high; i++){
		if(abs(arr[i][0] - arr[mid][0]) <= dd){
			split[k][0] = arr[i][0];
			split[k++][1] = arr[i][1];
		}
		
	}

	g = merge(split,k,e,f,dd);
	if(g < dd){
		dd = g;
		a[0] = e[0];
		a[1] = e[1];
		b[0] = f[0];
		b[1] = f[1];
	}
	return dd;
}


//a & b store the closest points 
double closestpoints(int arr[][2],int n,int a[],int b[]){
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
			}
		}
	}
	return closest(arr,0,n-1,a,b);
}
void find(int arr[][2],int t,int a[],int b[],int *n,int *m){
	int i,flag = 0, gg = 1;
	for(i = 0; i<t ; i++){
		if(flag == 0 && a[0] == arr[i][0] && a[1] == arr[i][1]){
			*n = i;
			flag = 1;
		}
		else if(gg == 1 && b[0] == arr[i][0] && b[1] == arr[i][1]){
			*m = i;
			gg = 0;
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n][2],brr[n][2];
	int i,a[2], b[2],j;
	double d=0;
	for(i =0; i<n;i++){
		scanf("%d%d",&arr[i][0],&arr[i][1]);
		brr[i][0] =arr[i][0];
		brr[i][1] = arr[i][1];
	}
	double minDist = 9999;
	for( i = 0; i<n-1; i++){
 		for( j = i + 1; j<n ; j++){
  			if (dist(arr[i],arr[j]) < minDist){
		   		minDist = dist(arr[i],arr[j]);
				a[0] = arr[i][0];
				a[1] = arr[i][1];
				b[0] = arr[j][0];
				b[1] = arr[j][1];
			}
		}
	}
	printf("%d %d && %d %d : %lf\n",a[0],a[1],b[0],b[1],minDist);
	d = closestpoints(arr,n,a,b);
	find(brr,n,a,b,&i,&j);
	printf("%d %d  : %lf\n",i,j,d);
	return 0;
}
