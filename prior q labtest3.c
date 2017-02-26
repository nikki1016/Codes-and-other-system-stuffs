#include <stdio.h>
struct node {
	int roll;
	int marks;
	int fr;
};
void display(struct node arr[],int n){
	int i;
	for(i =n; i>0; i--)
		printf("%d  ",arr[i].roll);
	printf("\n");
}
void restoreup(struct node arr[],int n){
	int i,j,t;
	struct node data;
	data.roll = arr[n].roll;
	data.fr = arr[n].fr;
	data.marks = arr[n].marks;
	while( i>0){
		if(arr[i].marks < arr[i/2].marks ){
			arr[i/2].marks = arr[i].marks;
			arr[i/2].roll = arr[i].roll;
			arr[i/2].fr = arr[i].fr;
			i = i/2;
		}
		else break;
	}
}

void restoredown(struct node arr[],int i,int n){
	int l  = 2*i, r = 2 * i +1, min = i, data,mrk,rol,frnd;
	mrk = arr[i].marks;
	rol = arr[i].roll;
	frnd = arr[i].fr;
	while( l<= n){
		if(mrk >= arr[l].marks && l <= n){
			min = l;
//			mrk = arr[i].marks;
		}
		if(arr[min].marks >= arr[r].marks && r <= n){
			min = r;
		}
		if(min == i)
			break;
		else{
			arr[i].marks = arr[min].marks;
			arr[i].roll = arr[min].roll;
			arr[i].fr = arr[min].fr;
			i = min;
			l = 2*i;
			r = l+1;
		}
	}
	arr[i].marks = mrk;
	arr[i].fr = frnd;
	arr[i].roll = rol;
}

void buildheap(struct node arr[],int n){
	int i= n/2;
	for(i = n/2; i>0; i--){
		restoredown(arr,i,n);
//		display(arr,n);
	}
}

int find(int rl,struct node arr[],int n,int *mrk){
	int i;
	for(i =n; i > 0; i--){
		if(arr[i].roll == rl){
			*mrk = arr[i].marks/2;
			return i;
		}
	}
	return -1;
}
void extractmin(struct node arr[],int *n){
	int i,rl,mrk;
	struct node data;
	data.roll = arr[1].roll;
	data.marks = arr[1].marks;
	data.fr = arr[1].fr;
	if(arr[1].fr != -1){
		rl = arr[1].fr;
		i = find(rl,arr,*n,&mrk);
		if(i != -1)
			arr[i].marks = mrk;
	}
	arr[1].roll = arr[*n].roll;
	arr[1].marks = arr[*n].marks;
	arr[1].fr = arr[*n].fr;

	arr[*n].roll = data.roll;
	arr[*n].marks = data.marks;
	arr[*n].fr = data.fr ;
	
	
	(*n)--;
	restoredown(arr,1,*n);
	//display(arr,*n);
}

int main() {
	int i,j,n;
	struct node arr[100];
	scanf("%d",&n);
	for(i = 1; i<= n; i++){
		scanf("%d%d%d", &arr[i].roll,&arr[i].marks, &arr[i].fr);
	}
	buildheap(arr,n);
	j = n;
	display(arr,n);
	for(i = 1; i<n; i++)
		extractmin(arr,&j);
	display(arr,n);
	return 0;
}

