#include <stdio.h>
#include <stdlib.h>
void row(int arr[][100], int n);
void column(int arr[][100], int n);
void display(int arr[][100],int n);

int main() {
	int n,i,choice,j;
	scanf("%d",&n);
	int arr[100][100];
	printf("enter elements\n");
	for( i = 0; i<n; i++){
		for( j =0; j<n; j++)
			scanf("%d",&arr[i][j]);
	}
	printf("1.print unique elements of rows\t2.print unique elements of columns\t3.print unique elements of matrix\t4.exit\nenter ur choice\n");
while(1){	
	scanf("%d",&choice);
	switch(choice){
		case 1:
			row(arr,n);
			break;
		case 2:
			column(arr,n);
			break;
		case 3:
			display(arr,n);
			break;
		default :
			exit(0);
	}
}
	return 0;
}



void row(int arr[][100], int n){
	int index[n][n]={0},i,j,k;
	for( i = 0; i<n; i++){
		
	        for( j =0; j<n; j++){
			for( k = j+1; k<n; k++){
				if(arr[i][j] == arr[i][k]){
					if(index[i][j] != 1) index[i][j] = 1;
					if(index[i][k] != 1)  index[i][k] = 1;
				}
			}
		}
	}
	for( i = 0; i< n; i++){
		printf("ROW %d UNIQUE ELEMENTS ARE : ",i);
		for( j =0; j < n; j++){
			if(index[i][j] == 0)	
				printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void column(int arr[][100], int n){
	int index[100][100]={0},i,j,k,l=0;
	for( i = 0; i<n; i++){
		
	        for( j =0; j<n; j++){
			
			for( k = j+1; k<n; k++){
				if(arr[j][i] == arr[k][i]){
					if(index[j][i] != 1) index[j][i] = 1;
					if(index[k][i] != 1)  index[k][i] = 1;
				}
			}
		}
	}
	for( i = 0; i< n; i++){
		printf("COLUMN %d UNIQUE ELEMENTS ARE : ",i);
		for( j =0; j<n; j++){
			if(index[j][i] == 0)		
				printf("%d ",arr[j][i]);
		}
		printf("\n");
	}
}
void display(int arr[][100],int n){
	int index[n][n]={0},i,j,k;
	for( i = 0; i<n; i++){
	        for( j =0; j<n; j++){
			for( k = j+1; k<n; k++){
				if(arr[i][j] == arr[i][k]){
					if(index[i][j] == 0) index[i][j] = 1;
					if(index[i][k] == 0)  index[i][k] = 1;
				}
				if(arr[j][i] == arr[k][i]){
					if(index[j][i] == 0) index[j][i] = 1;
					if(index[k][i] == 0)  index[k][i] = 1;
				}
			}
		}
	}
	for( i = 0; i< n; i++){
		for( j =0; j<n; j++){
			if(index[i][j] != 1)	
				printf("%d ",arr[i][j]);
			else
				printf("  ");
		}
		printf("\n");
	}
}

