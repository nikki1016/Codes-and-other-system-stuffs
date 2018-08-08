#include<stdio.h>
 
void printSolution(int board[3][3])
{
    int i, j;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
	printf("\n");
}
int isSafe(int board[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++){
		for(j =0; j<3; j++){
			if(board[i][j] != i*3 + j )
					return 0;
		}
	}
	return 1;
}
int same(int board[3][3],int arr[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++){
		for(j =0; j<3; j++){
			if(board[i][j] != arr[i][j])
					return 0;
		}
	}
	return 1;
}
int findblank(int board[3][3],int *a,int *b){
	int i, j;
	for (i = 0; i < 3; i++){
		for(j =0; j<3; j++){
			if(board[i][j] == 0){
				*a = i;
				*b = j;
				//printf("hii blank\n");
				return 1;			
			}
		}
	}
	return 0;
}
void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
int solve3QUtil(int board[3][3],int arr[3][3],int visited[9])
{
    
    if (isSafe(board)){
		printf("safe found\n");
		printSolution(board);
        return 1;
	}
	
	int i,j;
    int a=-1,b=-1;
	findblank( board, &a,&b);
	//printf("%d %d\n",a,b);
	//if(a < 0 || a > 2 || b < 0 || b > 2)
		//return 0; 
	for ( i = 0; i < 4; i++){
			//printf("hii solve\n");
		switch(i){
				case 0:
						if(a-1 >=0 && visited[(a-1)*3+b] == 0){
								swap(&board[a-1][b],&board[a][b]);
								printSolution(board);
								 visited[(a-1)*3+b] =1 ;
								if ( solve3QUtil(board,arr,visited) )
		            				return 1;
								 visited[(a-1)*3+b] = 0;
								swap(&board[a-1][b],&board[a][b]);
						}

						break;
				case 1:
						if(b-1 >=0 && visited[(a)*3+b-1] == 0 ){
								swap(&board[a][b-1],&board[a][b]);
								printSolution(board);
								visited[(a)*3+b-1] =1;
								if ( solve3QUtil(board,arr,visited) )
		            				return 1;
								visited[(a)*3+b-1] =0;
								swap(&board[a][b-1],&board[a][b]);
						}

						break;
				case 2:
						if( a+1 < 3 && visited[(a+1)*3+b] == 0){
								swap(&board[a+1][b],&board[a][b]);
								printSolution(board);
								visited[(a+1)*3+b] = 1;
								if ( solve3QUtil(board,arr,visited) )
		            				return 1;
								visited[(a+1)*3+b] = 0;
								swap(&board[a+1][b],&board[a][b]);
						}
						
						break;
				case 3:
						if(b+1 < 3 && visited[(a)*3+b+1] == 0){
								swap(&board[a][b+1],&board[a][b]);
								printSolution(board);
								visited[(a)*3+b+1] = 1;
								if ( solve3QUtil(board,arr,visited) )
		            				return 1;
								visited[(a)*3+b+1] = 0;
								swap(&board[a][b+1],&board[a][b]);
						}
						break;
		}
	}
    return 0;
}
int solve(int board[3][3]){
	int arr[3][3] = {0},visited[9]={0};
	int i,j;
	for(i =0; i<3; i++){
		for(j =0; j <3; j++){
			arr[i][j] = board[i][j];
		}
	}
	if(solve3QUtil(board,arr,visited) == 1)
		return 1;
	return 0;
}
int main(){
  	int board[3][3] = {0};
 	int i,j;
	for(i =0;i<3; i++){
		for(j =0; j<3; j++){
			scanf("%d",&board[i][j]);
		}
	}
    if ( solve(board) == 0 ){
   		//printf("Solution does not exist");
      	return 0;
	}
	//printSolution(board);
    return 0;
}

