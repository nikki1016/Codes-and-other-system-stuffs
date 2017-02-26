#include<stdio.h>
int n_queen(int board[][100],int i,int n);
void print(int board[][100],int n);
int constraints(int board[][100],int i,int j,int n);

int main(){
	int i=0,n,res;
	scanf("%d",&n);
	int board[100][100]={0};
	res = n_queen(board,i,n);
//	print(board,n);
	if(!res)
		printf("no solution\n");
	return 0;
}

int n_queen(int board[][100],int i,int n){
	if(i >= n){
		print(board,n);
		printf("\n");
		return 1;
	}
	int j;
	for( j=0; j<n; j++){
		board[i][j] = 1;
		int good = constraints(board, i, j, n);
		if(good){
			int found;
			found = n_queen(board,i+1,n);
		}
		board[i][j] = 0;
	}
//print(board,n);	
	return 0;
}
int constraints(int board[][100],int i,int j,int n){
	int k;
        for(k = 0; k<n && k != j; k++) {
                if(board[i][k] == 1)
                        return 0;
	}
	for(k = 0; k<n && k!= i ; k++){
                if(board[k][j] == 1)
                        return 0;
        }	
	if(board[i+1][j] == 1 || board[i][j+1] == 1)
		return 0;
	if(board[i-1][j+1] == 1 || board[i+1][j-1] == 1)
		return 0;
	if(board[i+1][j+1] == 1|| board[i-1][j-1] == 1)
		return 0;
	if(board[i-1][j] == 1  || board[i][j-1] == 1)
		return 0;
	return 1;
}

void print(int board[][100],int n){
	int i,j;
	for(i = 0; i<n; i++){
		for(j=0; j<n; j++){
			if(board[i][j] ==1)
				printf("Q ");
			else
				printf("- ");
		}
		printf("\n");
	}
}

